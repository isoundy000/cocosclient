#include "C3DEaseAction.h"

namespace cocos3d{
C3DEaseAction::C3DEaseAction(void)
{
}


C3DEaseAction::~C3DEaseAction(void)
{
	CC_SAFE_RELEASE(m_pInner);
}

C3DEaseAction *C3DEaseAction::create(C3DActionInterval *action)
{
	C3DEaseAction * pRet = new C3DEaseAction();
	pRet->initWithAction(action);

	pRet->autorelease();
	return pRet;
}

bool C3DEaseAction::initWithAction(C3DActionInterval *pAction)
{
	CCAssert(pAction != NULL, "");

	if (C3DActionInterval::initWithDuration(pAction->getDuration()))
	{
		m_pInner = pAction;
		pAction->retain();

		return true;
	}

	return false;
}

void C3DEaseAction::startWithTarget(C3DNode *pTarget)
{
	C3DActionInterval::startWithTarget(pTarget);
	m_pInner->startWithTarget(m3d_pTarget);
}

void C3DEaseAction::stop(void)
{
	m_pInner->stop();
	C3DActionInterval::stop();
}

void C3DEaseAction::update(float time)
{
	m_pInner->update(time);
}

C3DActionInterval* C3DEaseAction::getInnerAction()
{
	return m_pInner;
}


bool C3DEaseRateAction::initWithAction(C3DActionInterval *pAction,float mRate)
{
	if (C3DEaseAction::initWithAction(pAction))
	{
		m_pRate = mRate;
		return true;
	}
	return false;
}

C3DEaseRateAction *C3DEaseRateAction::create(C3DActionInterval *action,float mRate)
{
	C3DEaseRateAction *pRet = new C3DEaseRateAction();
	pRet->initWithAction(action,mRate);
	pRet->autorelease();

	return pRet;
}

//////////////////////////////////////////////////////////////////////////

C3DEaseExponentialIn *C3DEaseExponentialIn::create(C3DActionInterval* pAction)
{
	C3DEaseExponentialIn *pRet = new C3DEaseExponentialIn();
	pRet->initWithAction(pAction);
	pRet->autorelease();

	return pRet;
}

void C3DEaseExponentialIn::update(float time)
{
	m_pInner->update(time == 0 ? 0 : powf(2, 10 * (time/1 - 1)) - 1 * 0.001f);
}

C3DEaseExponentialOut *C3DEaseExponentialOut::create(C3DActionInterval* pAction)
{
	C3DEaseExponentialOut *pRet = new C3DEaseExponentialOut();
	pRet->initWithAction(pAction);
	pRet->autorelease();

	return pRet;
}

void C3DEaseExponentialOut::update(float time)
{
	m_pInner->update(time == 1 ? 1 : (-powf(2, -10 * time / 1) + 1));
}

C3DEaseExponentialInOut *C3DEaseExponentialInOut::create(C3DActionInterval* pAction)
{
	C3DEaseExponentialInOut *pRet = new C3DEaseExponentialInOut();
	pRet->initWithAction(pAction);
	pRet->autorelease();

	return pRet;
}

void C3DEaseExponentialInOut::update(float time)
{
	time /= 0.5f;
	if (time < 1)
	{
		time = 0.5f * powf(2, 10 * (time - 1));
	}
	else
	{
		time = 0.5f * (-powf(2, -10 * (time - 1)) + 2);
	}

	m_pInner->update(time);
}


}
