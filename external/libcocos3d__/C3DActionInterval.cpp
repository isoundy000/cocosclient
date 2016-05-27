#include "C3DActionInterval.h"

namespace cocos3d
{
	// Extra action for making a CCSequence or C3DSpawn when only adding one action to it.
	class ExtraAction : public C3DAction
	{
	public:
		static ExtraAction* create();
		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual ExtraAction* reverse(void);
		virtual void update(float time);
		virtual void step(float dt);
	};

	ExtraAction* ExtraAction::create()
	{
		ExtraAction* pRet = new ExtraAction();
		if (pRet)
		{
			pRet->autorelease();
		}
		return pRet;
	}

	CCObject* ExtraAction::copyWithZone(CCZone* pZone)
	{
		CC_UNUSED_PARAM(pZone);
		ExtraAction* pRet = new ExtraAction();
		return pRet;
	}

	ExtraAction* ExtraAction::reverse(void)
	{
		return ExtraAction::create();
	}

	void ExtraAction::update(float time)
	{
		CC_UNUSED_PARAM(time);
	}

	void ExtraAction::step(float dt)
	{
		CC_UNUSED_PARAM(dt);
	}

	//C3DActionInterval
	//////////////////////////////////////////////////////////////////////////
	C3DActionInterval* C3DActionInterval::create(float d)
	{
		C3DActionInterval *pAction = new C3DActionInterval();
		pAction->initWithDuration(d);
		pAction->autorelease();

		return pAction;
	}

	bool C3DActionInterval::initWithDuration(float d)
	{
		m_fDuration = d;

		// prevent division by 0
		// This comparison could be in step:, but it might decrease the performance
		// by 3% in heavy based action games.
		if (m_fDuration == 0)
		{
			m_fDuration = FLT_EPSILON;
		}

		m_elapsed = 0;
		m_bFirstTick = true;

		return true;
	}
	CCObject* C3DActionInterval::copyWithZone(CCZone *pZone)
	{
		CCZone* pNewZone = NULL;
		C3DActionInterval* pCopy = NULL;
		if(pZone && pZone->m_pCopyObject) 
		{
			//in case of being called at sub class
			pCopy = (C3DActionInterval*)(pZone->m_pCopyObject);
		}
		else
		{
			pCopy = new C3DActionInterval();
			pZone = pNewZone = new CCZone(pCopy);
		}


		C3DAction::copyWithZone(pZone);

		CC_SAFE_DELETE(pNewZone);

		pCopy->initWithDuration(m_fDuration);

		return pCopy;
	}

	bool C3DActionInterval::isDone(void)
	{
		return m_elapsed >= m_fDuration;
	}

	void C3DActionInterval::step(float dt)
	{
		if (m_bFirstTick)
		{
			m_bFirstTick = false;
			m_elapsed = 0;
		}
		else
		{
			m_elapsed += dt;
		}

		this->update(MAX (0,                                  // needed for rewind. elapsed could be negative
			MIN(1, m_elapsed /
			MAX(m_fDuration, FLT_EPSILON)   // division by 0
			)
			)
			);
	}

	void C3DActionInterval::setAmplitudeRate(float amp)
	{
		CC_UNUSED_PARAM(amp);
		// Abstract class needs implementation
		CCAssert(0, "");
	}

	float C3DActionInterval::getAmplitudeRate(void)
	{
		// Abstract class needs implementation
		CCAssert(0, "");

		return 0;
	}

	void C3DActionInterval::startWithTarget(C3DNode *pTarget)
	{
		C3DAction::startWithTarget(pTarget);
		m_elapsed = 0.0f;
		m_bFirstTick = true;
	}

	C3DActionInterval* C3DActionInterval::reverse(void)
	{
		CCAssert(false, "CCIntervalAction: reverse not implemented.");
		return NULL;
	}


	// 3DSequence
	//////////////////////////////////////////////////////////////////////////

	C3DSequence* C3DSequence::createWithTwoActions(C3DAction *pActionOne, C3DAction *pActionTwo)
	{
		C3DSequence *pSequence = new C3DSequence();
		pSequence->initWithTwoActions(pActionOne, pActionTwo);
		pSequence->autorelease();

		return pSequence;
	}

	C3DSequence* C3DSequence::create(C3DAction *pAction1, ...)
	{
		va_list params;
		va_start(params, pAction1);

		C3DSequence *pRet = C3DSequence::createWithVariableList(pAction1, params);

		va_end(params);

		return pRet;
	}

	C3DSequence* C3DSequence::createWithVariableList(C3DAction *pAction1, va_list args)
	{
		C3DAction *pNow;
		C3DAction *pPrev = pAction1;
		bool bOneAction = true;

		while (pAction1)
		{
			pNow = va_arg(args, C3DAction*);
			if (pNow)
			{
				pPrev = createWithTwoActions(pPrev, pNow);
				bOneAction = false;
			}
			else
			{
				// If only one action is added to C3DSequence, make up a C3DSequence by adding a simplest finite time action.
				if (bOneAction)
				{
					pPrev = createWithTwoActions(pPrev, ExtraAction::create());
				}
				break;
			}
		}

		return ((C3DSequence*)pPrev);
	}

	C3DSequence* C3DSequence::create(CCArray* arrayOfActions)
	{
		C3DSequence* pRet = NULL;
		do 
		{
			unsigned  int count = arrayOfActions->count();
			CC_BREAK_IF(count == 0);

			C3DAction* prev = (C3DAction*)arrayOfActions->objectAtIndex(0);

			if (count > 1)
			{
				for (unsigned int i = 1; i < count; ++i)
				{
					prev = createWithTwoActions(prev, (C3DAction*)arrayOfActions->objectAtIndex(i));
				}
			}
			else
			{
				// If only one action is added to C3DSequence, make up a C3DSequence by adding a simplest finite time action.
				prev = createWithTwoActions(prev, ExtraAction::create());
			}
			pRet = (C3DSequence*)prev;
		}while (0);
		return pRet;
	}

	bool C3DSequence::initWithTwoActions(C3DAction *pActionOne, C3DAction *pActionTwo)
	{
		CCAssert(pActionOne != NULL, "");
		CCAssert(pActionTwo != NULL, "");

		float d = pActionOne->getDuration() + pActionTwo->getDuration();
		C3DActionInterval::initWithDuration(d);

		m_pActions[0] = pActionOne;
		pActionOne->retain();

		m_pActions[1] = pActionTwo;
		pActionTwo->retain();

		return true;
	}

	CCObject* C3DSequence::copyWithZone(CCZone *pZone)
	{
		CCZone* pNewZone = NULL;
		C3DSequence* pCopy = NULL;
		if(pZone && pZone->m_pCopyObject) 
		{
			//in case of being called at sub class
			pCopy = (C3DSequence*)(pZone->m_pCopyObject);
		}
		else
		{
			pCopy = new C3DSequence();
			pZone = pNewZone = new CCZone(pCopy);
		}

		C3DActionInterval::copyWithZone(pZone);

		pCopy->initWithTwoActions((C3DAction*)(m_pActions[0]->copy()->autorelease()), 
			(C3DAction*)(m_pActions[1]->copy()->autorelease()));

		CC_SAFE_DELETE(pNewZone);
		return pCopy;
	}

	C3DSequence::~C3DSequence(void)
	{
		CC_SAFE_RELEASE(m_pActions[0]);
		CC_SAFE_RELEASE(m_pActions[1]);
	}

	void C3DSequence::startWithTarget(C3DNode *pTarget)
	{
		C3DActionInterval::startWithTarget(pTarget);
		m_split = m_pActions[0]->getDuration() / m_fDuration;
		m_last = -1;
	}

	void C3DSequence::stop(void)
	{
		// Issue #1305
		if( m_last != - 1)
		{
			m_pActions[m_last]->stop();
		}

		C3DActionInterval::stop();
	}

	void C3DSequence::update(float t)
	{
		int found = 0;
		float new_t = 0.0f;

		if( t < m_split ) {
			// action[0]
			found = 0;
			if( m_split != 0 )
				new_t = t / m_split;
			else
				new_t = 1;

		} else {
			// action[1]
			found = 1;
			if ( m_split == 1 )
				new_t = 1;
			else
				new_t = (t-m_split) / (1 - m_split );
		}

		if ( found==1 ) {

			if( m_last == -1 ) {
				// action[0] was skipped, execute it.
				m_pActions[0]->startWithTarget(m3d_pTarget);
				m_pActions[0]->update(1.0f);
				m_pActions[0]->stop();
			}
			else if( m_last == 0 )
			{
				// switching to action 1. stop action 0.
				m_pActions[0]->update(1.0f);
				m_pActions[0]->stop();
			}
		}
		else if(found==0 && m_last==1 )
		{
			// Reverse mode ?
			// XXX: Bug. this case doesn't contemplate when _last==-1, found=0 and in "reverse mode"
			// since it will require a hack to know if an action is on reverse mode or not.
			// "step" should be overriden, and the "reverseMode" value propagated to inner Sequences.
			m_pActions[1]->update(0);
			m_pActions[1]->stop();
		}
		// Last action found and it is done.
		if( found == m_last && m_pActions[found]->isDone() )
		{
			return;
		}

		// Last action found and it is done
		if( found != m_last )
		{
			m_pActions[found]->startWithTarget(m3d_pTarget);
		}

		m_pActions[found]->update(new_t);
		m_last = found;
	}

	C3DActionInterval* C3DSequence::reverse(void)
	{
		return C3DSequence::createWithTwoActions(m_pActions[1]->reverse(), m_pActions[0]->reverse());
	}

	//////////////////////////////////////////////////////////////////////////
	//  Reqpeat3D
	//////////////////////////////////////////////////////////////////////////
	

	C3DRepeat* C3DRepeat::create(C3DAction *pAction, unsigned int times)
	{
		C3DRepeat* pRepeat = new C3DRepeat();
		pRepeat->initWithAction(pAction, times);
		pRepeat->autorelease();

		return pRepeat;
	}

	bool C3DRepeat::initWithAction(C3DAction *pAction, unsigned int times)
	{
		float d = pAction->getDuration() * times;

		if (C3DActionInterval::initWithDuration(d))
		{
			m_uTimes = times;
			m_pInnerAction = pAction;
			pAction->retain();

			m_bActionInstant = dynamic_cast<CCActionInstant*>(pAction) ? true : false;
			//an instant action needs to be executed one time less in the update method since it uses startWithTarget to execute the action
			if (m_bActionInstant) 
			{
				m_uTimes -=1;
			}
			m_uTotal = 0;

			return true;
		}

		return false;
	}

	CCObject* C3DRepeat::copyWithZone(CCZone *pZone)
	{

		CCZone* pNewZone = NULL;
		C3DRepeat* pCopy = NULL;
		if(pZone && pZone->m_pCopyObject) 
		{
			//in case of being called at sub class
			pCopy = (C3DRepeat*)(pZone->m_pCopyObject);
		}
		else
		{
			pCopy = new C3DRepeat();
			pZone = pNewZone = new CCZone(pCopy);
		}

		C3DActionInterval::copyWithZone(pZone);

		pCopy->initWithAction((C3DAction*)(m_pInnerAction->copy()->autorelease()), m_uTimes);

		CC_SAFE_DELETE(pNewZone);
		return pCopy;
	}

	C3DRepeat::~C3DRepeat(void)
	{
		CC_SAFE_RELEASE(m_pInnerAction);
	}

	void C3DRepeat::startWithTarget(C3DNode *pTarget)
	{
		m_uTotal = 0;
		m_fNextDt = m_pInnerAction->getDuration()/m_fDuration;
		C3DActionInterval::startWithTarget(pTarget);
		m_pInnerAction->startWithTarget(pTarget);
	}

	void C3DRepeat::stop(void)
	{
		m_pInnerAction->stop();
		C3DActionInterval::stop();
	}

	// issue #80. Instead of hooking step:, hook update: since it can be called by any 
	// container action like C3DRepeat, CCSequence, CCEase, etc..
	void C3DRepeat::update(float dt)
	{
		if (dt >= m_fNextDt)
		{
			while (dt > m_fNextDt && m_uTotal < m_uTimes)
			{

				m_pInnerAction->update(1.0f);
				m_uTotal++;

				m_pInnerAction->stop();
				m_pInnerAction->startWithTarget(m3d_pTarget);
				m_fNextDt += m_pInnerAction->getDuration()/m_fDuration;
			}

			// fix for issue #1288, incorrect end value of repeat
			if(dt >= 1.0f && m_uTotal < m_uTimes) 
			{
				m_uTotal++;
			}

			// don't set an instant action back or update it, it has no use because it has no duration
			if (!m_bActionInstant)
			{
				if (m_uTotal == m_uTimes)
				{
					m_pInnerAction->update(1);
					m_pInnerAction->stop();
				}
				else
				{
					// issue #390 prevent jerk, use right update
					m_pInnerAction->update(dt - (m_fNextDt - m_pInnerAction->getDuration()/m_fDuration));
				}
			}
		}
		else
		{
			m_pInnerAction->update(fmodf(dt * m_uTimes,1.0f));
		}
	}

	bool C3DRepeat::isDone(void)
	{
		return m_uTotal == m_uTimes;
	}

	C3DActionInterval* C3DRepeat::reverse(void)
	{
		return C3DRepeat::create(m_pInnerAction->reverse(), m_uTimes);
	}

	//
	// RepeatForever
	//
	C3DRepeatForever::~C3DRepeatForever()
	{
		CC_SAFE_RELEASE(m_pInnerAction);
	}

	C3DRepeatForever *C3DRepeatForever::create(C3DActionInterval *pAction)
	{
		C3DRepeatForever *pRet = new C3DRepeatForever();
		if (pRet && pRet->initWithAction(pAction))
		{
			pRet->autorelease();
			return pRet;
		}
		CC_SAFE_DELETE(pRet);
		return NULL;
	}

	bool C3DRepeatForever::initWithAction(C3DActionInterval *pAction)
	{
		CCAssert(pAction != NULL, "");
		pAction->retain();
		m_pInnerAction = pAction;
		return true;
	}
	CCObject* C3DRepeatForever::copyWithZone(CCZone *pZone)
	{
		CCZone* pNewZone = NULL;
		C3DRepeatForever* pRet = NULL;
		if(pZone && pZone->m_pCopyObject) //in case of being called at sub class
		{
			pRet = (C3DRepeatForever*)(pZone->m_pCopyObject);
		}
		else
		{
			pRet = new C3DRepeatForever();
			pZone = pNewZone = new CCZone(pRet);
		}
		C3DActionInterval::copyWithZone(pZone);
		// win32 : use the m_pOther's copy object.
		pRet->initWithAction((C3DActionInterval*)(m_pInnerAction->copy()->autorelease())); 
		CC_SAFE_DELETE(pNewZone);
		return pRet;
	}

	void C3DRepeatForever::startWithTarget(C3DNode* pTarget)
	{
		C3DActionInterval::startWithTarget(pTarget);
		m_pInnerAction->startWithTarget(pTarget);
	}

	void C3DRepeatForever::step(float dt)
	{
		m_pInnerAction->step(dt);
		if (m_pInnerAction->isDone())
		{
			float diff = m_pInnerAction->getElapsed() - m_pInnerAction->getDuration();
			m_pInnerAction->startWithTarget(m3d_pTarget);
			// to prevent jerk. issue #390, 1247
			m_pInnerAction->step(0.0f);
			m_pInnerAction->step(diff);
		}
	}

	bool C3DRepeatForever::isDone()
	{
		return false;
	}

	C3DActionInterval *C3DRepeatForever::reverse()
	{
		return (C3DActionInterval*)(C3DRepeatForever::create(m_pInnerAction->reverse()));
	}

	//
	// Spawn
	//

	C3DSpawn* C3DSpawn::create(C3DAction *pAction1, ...)
	{
		va_list params;
		va_start(params, pAction1);

		C3DSpawn *pRet = C3DSpawn::createWithVariableList(pAction1, params);

		va_end(params);

		return pRet;
	}

	C3DSpawn* C3DSpawn::createWithVariableList(C3DAction *pAction1, va_list args)
	{
		C3DAction *pNow;
		C3DAction *pPrev = pAction1;
		bool bOneAction = true;

		while (pAction1)
		{
			pNow = va_arg(args, C3DAction*);
			if (pNow)
			{
				pPrev = createWithTwoActions(pPrev, pNow);
				bOneAction = false;
			}
			else
			{
				// If only one action is added to C3DSpawn, make up a C3DSpawn by adding a simplest finite time action.
				if (bOneAction)
				{
					pPrev = createWithTwoActions(pPrev, ExtraAction::create());
				}
				break;
			}
		}

		return ((C3DSpawn*)pPrev);
	}

	C3DSpawn* C3DSpawn::create(CCArray *arrayOfActions)
	{
		C3DSpawn* pRet = NULL;
		do 
		{
			unsigned  int count = arrayOfActions->count();
			CC_BREAK_IF(count == 0);
			C3DAction* prev = (C3DAction*)arrayOfActions->objectAtIndex(0);
			if (count > 1)
			{
				for (unsigned int i = 1; i < arrayOfActions->count(); ++i)
				{
					prev = createWithTwoActions(prev, (C3DAction*)arrayOfActions->objectAtIndex(i));
				}
			}
			else
			{
				// If only one action is added to C3DSpawn, make up a C3DSpawn by adding a simplest finite time action.
				prev = createWithTwoActions(prev, ExtraAction::create());
			}
			pRet = (C3DSpawn*)prev;
		}while (0);

		return pRet;
	}

	C3DSpawn* C3DSpawn::createWithTwoActions(C3DAction *pAction1, C3DAction *pAction2)
	{
		C3DSpawn *pSpawn = new C3DSpawn();
		pSpawn->initWithTwoActions(pAction1, pAction2);
		pSpawn->autorelease();

		return pSpawn;
	}

	bool C3DSpawn:: initWithTwoActions(C3DAction *pAction1, C3DAction *pAction2)
	{
		CCAssert(pAction1 != NULL, "");
		CCAssert(pAction2 != NULL, "");

		bool bRet = false;

		float d1 = pAction1->getDuration();
		float d2 = pAction2->getDuration();

		if (C3DActionInterval::initWithDuration(MAX(d1, d2)))
		{
			m_pOne = pAction1;
			m_pTwo = pAction2;

			if (d1 > d2)
			{
				m_pTwo = C3DSequence::createWithTwoActions(pAction2, C3DDelayTime::create(d1 - d2));
			} 
			else if (d1 < d2)
			{
				m_pOne = C3DSequence::createWithTwoActions(pAction1, C3DDelayTime::create(d2 - d1));
			}

			m_pOne->retain();
			m_pTwo->retain();

			bRet = true;
		}


		return bRet;
	}

	CCObject* C3DSpawn::copyWithZone(CCZone *pZone)
	{
		CCZone* pNewZone = NULL;
		C3DSpawn* pCopy = NULL;

		if(pZone && pZone->m_pCopyObject) 
		{
			//in case of being called at sub class
			pCopy = (C3DSpawn*)(pZone->m_pCopyObject);
		}
		else
		{
			pCopy = new C3DSpawn();
			pZone = pNewZone = new CCZone(pCopy);
		}

		C3DActionInterval::copyWithZone(pZone);

		pCopy->initWithTwoActions((C3DAction*)(m_pOne->copy()->autorelease()), 
			(C3DAction*)(m_pTwo->copy()->autorelease()));

		CC_SAFE_DELETE(pNewZone);
		return pCopy;
	}

	C3DSpawn::~C3DSpawn(void)
	{
		CC_SAFE_RELEASE(m_pOne);
		CC_SAFE_RELEASE(m_pTwo);
	}

	void C3DSpawn::startWithTarget(C3DNode *pTarget)
	{
		C3DActionInterval::startWithTarget(pTarget);
		m_pOne->startWithTarget(pTarget);
		m_pTwo->startWithTarget(pTarget);
	}

	void C3DSpawn::stop(void)
	{
		m_pOne->stop();
		m_pTwo->stop();
		C3DActionInterval::stop();
	}

	void C3DSpawn::update(float time)
	{
		if (m_pOne)
		{
			m_pOne->update(time);
		}
		if (m_pTwo)
		{
			m_pTwo->update(time);
		}
	}

	C3DActionInterval* C3DSpawn::reverse(void)
	{
		return C3DSpawn::createWithTwoActions(m_pOne->reverse(), m_pTwo->reverse());
	}


	//////////////////////////////////////////////////////////////////////////
	//		C3DRotateBy3D
	//////////////////////////////////////////////////////////////////////////

	C3DRotateBy* C3DRotateBy::create(float fDuration, const C3DVector3 &deltaAngle)
	{
		C3DRotateBy *pRet = new C3DRotateBy();
		pRet->initWithDuration(fDuration,deltaAngle);
		pRet->autorelease();

		return pRet;
	}

	bool C3DRotateBy::initWithDuration(float fDuration, const C3DVector3 &deltaAngle)
	{
		if (C3DActionInterval::initWithDuration(fDuration))
		{
			this->deltaAngle = deltaAngle;
			return true;
		}
		return false;
	}

	void C3DRotateBy::startWithTarget(C3DNode *pTarget)
	{
		C3DActionInterval::startWithTarget(pTarget);
		C3DQuaternion rot = pTarget->getRotation();
        rotStart = rot;
		C3DVector3 unitX(1,0,0),unitY(0,1,0),unitZ(0,0,1);
		startAngle.x = rot.toAxisAngle(&unitX);
		startAngle.y = rot.toAxisAngle(&unitY);
		startAngle.z = rot.toAxisAngle(&unitZ);

	}

	void C3DRotateBy::update(float time)
	{
		C3DVector3 angle = deltaAngle * time;
		C3DQuaternion qX;C3DQuaternion::createFromAxisAngle(C3DVector3::unitX(),angle.x,&qX);
		C3DQuaternion qY;C3DQuaternion::createFromAxisAngle(C3DVector3::unitY(),angle.y,&qY);
		C3DQuaternion qZ;C3DQuaternion::createFromAxisAngle(C3DVector3::unitZ(),angle.z,&qZ);

		qX.multiply(qY);
		qX.multiply(qZ);
        
        C3DQuaternion ret = rotStart;
        ret.multiply(qX);

		m3d_pTarget->setRotation(ret);
	}

	//////////////////////////////////////////////////////////////////////////
	//  C3DMoveBy
	//////////////////////////////////////////////////////////////////////////


	C3DMoveBy *C3DMoveBy::create(float fDuration, const C3DVector3 &delta)
	{
		C3DMoveBy *pRet = new C3DMoveBy();
		pRet->initWithDuration(fDuration,delta);
		pRet->autorelease();

		return pRet;
	}

	bool C3DMoveBy::initWithDuration(float fDuration, const C3DVector3 &delta)
	{
		if (C3DActionInterval::initWithDuration(fDuration))
		{
			this->deltaPosition = delta;
			return true;
		}
		return false;
	}

	void C3DMoveBy::startWithTarget(C3DNode *pTarget)
	{
		C3DActionInterval::startWithTarget(pTarget);
		startPosition = pTarget->getPosition();
	}

	void C3DMoveBy::update(float time)
	{
		C3DVector3 pos = startPosition + deltaPosition * time;
		m3d_pTarget->setPosition(pos);
	}

	// C3DMoveTo
	C3DMoveTo *C3DMoveTo::create(float fDuration, const C3DVector3 &dstPosition)
	{
		C3DMoveTo *pRet = new C3DMoveTo();
		pRet->initWithDuration(fDuration,dstPosition);
		pRet->autorelease();

		return pRet;
	}

	bool C3DMoveTo::initWithDuration(float fDuration, const C3DVector3 &dstPosition)
	{
		if (C3DActionInterval::initWithDuration(fDuration))
		{
			deltaPosition = dstPosition;
			return true;
		}
		return false;
	}

	void C3DMoveTo::startWithTarget(C3DNode *pTarget)
	{
		C3DActionInterval::startWithTarget(pTarget);
		startPosition = pTarget->getPosition();
        deltaPosition = deltaPosition - startPosition;
	}

	void C3DMoveTo::update(float time)
	{
		C3DVector3 pos = startPosition + deltaPosition * time;
		m3d_pTarget->setPosition(pos);
	}

	//////////////////////////////////////////////////////////////////////////
	//  C3DBezierBy
	//////////////////////////////////////////////////////////////////////////

	C3DBezierBy *C3DBezierBy::create(float fDuration,c3dBezierConfig &bezierConfig)
	{
		C3DBezierBy *pRet = new C3DBezierBy();
		pRet->initWithDuration(fDuration,bezierConfig);
		pRet->autorelease();

		return pRet;
	}

	bool C3DBezierBy::initWithDuration(float duration,c3dBezierConfig &beCf)
	{
		if (C3DActionInterval::initWithDuration(duration))
		{
			m_bezierConfig = beCf;
			return true;
		}
		return false;
	}
	void C3DBezierBy::startWithTarget(C3DNode *pTarget)
	{
		C3DActionInterval::startWithTarget(pTarget);
		m_PreviousPos = m_StartPos = pTarget->getPosition();
	}
	static inline float bezierat( float a, float b, float c, float d, float t )
	{
		return (powf(1-t,3) * a + 
			3*t*(powf(1-t,2))*b + 
			3*powf(t,2)*(1-t)*c +
			powf(t,3)*d );
	}
	void C3DBezierBy::update(float time)
	{
		if (m3d_pTarget)
		{
			float xa = 0;
			float xb = m_bezierConfig.controlPoint_1.x;
			float xc = m_bezierConfig.controlPoint_2.x;
			float xd = m_bezierConfig.endPosition.x;

			float ya = 0;
			float yb = m_bezierConfig.controlPoint_1.y;
			float yc = m_bezierConfig.controlPoint_2.y;
			float yd = m_bezierConfig.endPosition.y;

			float za = 0;
			float zb = m_bezierConfig.controlPoint_1.z;
			float zc = m_bezierConfig.controlPoint_2.z;
			float zd = m_bezierConfig.endPosition.z;

			float x = bezierat(xa, xb, xc, xd, time);
			float y = bezierat(ya, yb, yc, yd, time);
			float z = bezierat(za, zb, zc, zd, time);

			C3DVector3 currentPos = m3d_pTarget->getPosition();
			C3DVector3 diff = currentPos - m_PreviousPos;
			m_StartPos -= diff;

			m_PreviousPos = m_StartPos + C3DVector3(x,y,z);
			m3d_pTarget->setPosition(m_PreviousPos);
		}
	}


	//////////////////////////////////////////////////////////////////////////
	//  C3DBezierTo

	C3DBezierTo *C3DBezierTo::create(float fDuration,c3dBezierConfig &bezierConfig)
	{
		C3DBezierTo *pRet = new C3DBezierTo();
		pRet->initWithDuration(fDuration,bezierConfig);
		pRet->autorelease();

		return pRet;
	}

	void C3DBezierTo::startWithTarget(C3DNode *pTarget)
	{
		C3DBezierBy::startWithTarget(pTarget);
		m_bezierConfig.controlPoint_1 -= m_StartPos;
		m_bezierConfig.controlPoint_2 -= m_StartPos;
		m_bezierConfig.endPosition -= m_StartPos;
	}

	//////////////////////////////////////////////////////////////////////////
	// DelayTime

	C3DDelayTime* C3DDelayTime::create(float time)
	{
		C3DDelayTime *pRet = new C3DDelayTime();
		pRet->initWithDuration(time);
		pRet->autorelease();

		return pRet;
	}
}

