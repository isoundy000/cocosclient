#include "C3DActionManager.h"
#include "cocos2d.h"
#include "CCScheduler.h"
#include "ccMacros.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "support/data_support/ccCArray.cpp"
#else
#include "support/data_support/ccCArray.h"
#endif
#include "support/data_support/uthash.h"
#include "cocoa/CCSet.h"
#include "C3DAction.h"

namespace cocos3d
{
	static C3DActionManager *instance = NULL;
C3DActionManager::C3DActionManager(void)
	: m_pTargets(NULL), 
	m_pCurrentTarget(NULL),
	m_bCurrentTargetSalvaged(false)
{


}

C3DActionManager *C3DActionManager::getInstance()
{
	if (instance == NULL)
	{
		instance = new C3DActionManager();
	}
	return instance;
}

void C3DActionManager::destroyInstance()
{
	CC_SAFE_DELETE(instance);
}


C3DActionManager::~C3DActionManager(void)
{
	CCLOGINFO("cocos3d: deallocing %p", this);

	removeAllActions();
}

void C3DActionManager::deleteHashElement(_hashElement3D *pElement)
{
	ccArrayFree(pElement->actions);
	HASH_DEL(m_pTargets, pElement);
	pElement->target->release();
	free(pElement);
}

void C3DActionManager::actionAllocWithHashElement(_hashElement3D *pElement)
{
	// 4 actions per Node by default
	if (pElement->actions == NULL)
	{
		pElement->actions = ccArrayNew(4);
	}else 
		if (pElement->actions->num == pElement->actions->max)
		{
			cocos2d::ccArrayDoubleCapacity(pElement->actions);
		}

}

void C3DActionManager::removeActionAtIndex(unsigned int uIndex, _hashElement3D *pElement)
{
	C3DAction *pAction = (C3DAction*)pElement->actions->arr[uIndex];

	if (pAction == pElement->currentAction && (! pElement->currentActionSalvaged))
	{
		pElement->currentAction->retain();
		pElement->currentActionSalvaged = true;
	}

	ccArrayRemoveObjectAtIndex(pElement->actions, uIndex, true);

	// update actionIndex in case we are in tick. looping over the actions
	if (pElement->actionIndex >= uIndex)
	{
		pElement->actionIndex--;
	}

	if (pElement->actions->num == 0)
	{
		if (m_pCurrentTarget == pElement)
		{
			m_bCurrentTargetSalvaged = true;
		}
		else
		{
			deleteHashElement(pElement);
		}
	}
}

// pause / resume

void C3DActionManager::pauseTarget(CCObject *pTarget)
{
	_hashElement3D *pElement = NULL;
	HASH_FIND_INT(m_pTargets, &pTarget, pElement);
	if (pElement)
	{
		pElement->paused = true;
	}
}

void C3DActionManager::resumeTarget(CCObject *pTarget)
{
	_hashElement3D *pElement = NULL;
	HASH_FIND_INT(m_pTargets, &pTarget, pElement);
	if (pElement)
	{
		pElement->paused = false;
	}
}

cocos2d::CCSet* C3DActionManager::pauseAllRunningActions()
{
	cocos2d::CCSet *idsWithActions = new cocos2d::CCSet();
	idsWithActions->autorelease();

	for (_hashElement3D *element=m_pTargets; element != NULL; element = (_hashElement3D *)element->hh.next) 
	{
		if (! element->paused) 
		{
			element->paused = true;
			idsWithActions->addObject(element->target);
		}
	}    

	return idsWithActions;
}

void C3DActionManager::resumeTargets(cocos2d::CCSet *targetsToResume)
{    
	CCSetIterator iter;
	for (iter = targetsToResume->begin(); iter != targetsToResume->end(); ++iter)
	{
		resumeTarget(*iter);
	}
}

// run

void C3DActionManager::addAction(C3DAction *pAction, C3DNode *pTarget, bool paused)
{
	CCAssert(pAction != NULL, "");
	CCAssert(pTarget != NULL, "");

	_hashElement3D *pElement = NULL;
	// we should convert it to CCObject*, because we save it as CCObject*
	CCObject *tmp = (CCObject *)pTarget;
	HASH_FIND_INT(m_pTargets, &tmp, pElement);
	if (! pElement)
	{
		pElement = (_hashElement3D*)calloc(sizeof(*pElement), 1);
		pElement->paused = paused;
		tmp->retain();
		pElement->target = (CCObject *)pTarget;
		HASH_ADD_INT(m_pTargets, target, pElement);
	}

	actionAllocWithHashElement(pElement);

	CCAssert(! ccArrayContainsObject(pElement->actions, pAction), "");
	cocos2d::ccArrayAppendObject(pElement->actions, pAction);

	pAction->startWithTarget(pTarget);
}

// remove

void C3DActionManager::removeAllActions(void)
{
	for (_hashElement3D *pElement = m_pTargets; pElement != NULL; )
	{
		CCObject *pTarget = pElement->target;
		pElement = (_hashElement3D*)pElement->hh.next;
		removeAllActionsFromTarget(pTarget);
	}
}

void C3DActionManager::removeAllActionsFromTarget(CCObject *pTarget)
{
	// explicit null handling
	if (pTarget == NULL)
	{
		return;
	}

	_hashElement3D *pElement = NULL;
	HASH_FIND_INT(m_pTargets, &pTarget, pElement);
	if (pElement)
	{
		if (ccArrayContainsObject(pElement->actions, pElement->currentAction) && (! pElement->currentActionSalvaged))
		{
			pElement->currentAction->retain();
			pElement->currentActionSalvaged = true;
		}

		ccArrayRemoveAllObjects(pElement->actions);
		if (m_pCurrentTarget == pElement)
		{
			m_bCurrentTargetSalvaged = true;
		}
		else
		{
			deleteHashElement(pElement);
		}
	}
	else
	{
		//        CCLOG("cocos2d: removeAllActionsFromTarget: Target not found");
	}
}

void C3DActionManager::removeAction(C3DAction *pAction)
{
	// explicit null handling
	if (pAction == NULL)
	{
		return;
	}

	_hashElement3D *pElement = NULL;
	CCObject *pTarget = pAction->getTarget();
	HASH_FIND_INT(m_pTargets, &pTarget, pElement);
	if (pElement)
	{
		unsigned int i = ccArrayGetIndexOfObject(pElement->actions, pAction);
		if (UINT_MAX != i)
		{
			removeActionAtIndex(i, pElement);
		}
	}
	else
	{
		CCLOG("cocos2d: removeAction: Target not found");
	}
}

void C3DActionManager::removeActionByTag(unsigned int tag, CCObject *pTarget)
{
	CCAssert((int)tag != kCCActionTagInvalid, "");
	CCAssert(pTarget != NULL, "");

	_hashElement3D *pElement = NULL;
	HASH_FIND_INT(m_pTargets, &pTarget, pElement);

	if (pElement)
	{
		unsigned int limit = pElement->actions->num;
		for (unsigned int i = 0; i < limit; ++i)
		{
			CCAction *pAction = (CCAction*)pElement->actions->arr[i];

			if (pAction->getTag() == (int)tag && pAction->getOriginalTarget() == pTarget)
			{
				removeActionAtIndex(i, pElement);
				break;
			}
		}
	}
}

// get

C3DAction* C3DActionManager::getActionByTag(unsigned int tag, CCObject *pTarget)
{
	CCAssert((int)tag != kCCActionTagInvalid, "");

	_hashElement3D *pElement = NULL;
	HASH_FIND_INT(m_pTargets, &pTarget, pElement);

	if (pElement)
	{
		if (pElement->actions != NULL)
		{
			unsigned int limit = pElement->actions->num;
			for (unsigned int i = 0; i < limit; ++i)
			{
				C3DAction *pAction = (C3DAction*)pElement->actions->arr[i];

				if (pAction->getTag() == (int)tag)
				{
					return pAction;
				}
			}
		}
		CCLOG("cocos2d : getActionByTag(tag = %d): Action not found", tag);
	}
	else
	{
		// CCLOG("cocos2d : getActionByTag: Target not found");
	}

	return NULL;
}

unsigned int C3DActionManager::numberOfRunningActionsInTarget(CCObject *pTarget)
{
	_hashElement3D *pElement = NULL;
	HASH_FIND_INT(m_pTargets, &pTarget, pElement);
	if (pElement)
	{
		return pElement->actions ? pElement->actions->num : 0;
	}

	return 0;
}

// main loop
void C3DActionManager::update(float dt)
{
	for (_hashElement3D *elt = m_pTargets; elt != NULL; )
	{
		m_pCurrentTarget = elt;
		m_bCurrentTargetSalvaged = false;

		if (! m_pCurrentTarget->paused)
		{
			// The 'actions' CCMutableArray may change while inside this loop.
			for (m_pCurrentTarget->actionIndex = 0; m_pCurrentTarget->actionIndex < m_pCurrentTarget->actions->num;
				m_pCurrentTarget->actionIndex++)
			{
				m_pCurrentTarget->currentAction = (C3DAction*)m_pCurrentTarget->actions->arr[m_pCurrentTarget->actionIndex];
				if (m_pCurrentTarget->currentAction == NULL)
				{
					continue;
				}

				m_pCurrentTarget->currentActionSalvaged = false;

				m_pCurrentTarget->currentAction->step(dt);

				if (m_pCurrentTarget->currentActionSalvaged)
				{
					// The currentAction told the node to remove it. To prevent the action from
					// accidentally deallocating itself before finishing its step, we retained
					// it. Now that step is done, it's safe to release it.
					m_pCurrentTarget->currentAction->release();
				} else
					if (m_pCurrentTarget->currentAction->isDone())
					{
						m_pCurrentTarget->currentAction->stop();

						C3DAction *pAction = m_pCurrentTarget->currentAction;
						// Make currentAction nil to prevent removeAction from salvaging it.
						m_pCurrentTarget->currentAction = NULL;
						removeAction(pAction);
					}

					m_pCurrentTarget->currentAction = NULL;
			}
		}

		// elt, at this moment, is still valid
		// so it is safe to ask this here (issue #490)
		elt = (_hashElement3D*)(elt->hh.next);

		// only delete currentTarget if no actions were scheduled during the cycle (issue #481)
		if (m_bCurrentTargetSalvaged && m_pCurrentTarget->actions->num == 0)
		{
			deleteHashElement(m_pCurrentTarget);
		}
	}

	// issue #635
	m_pCurrentTarget = NULL;
}

}
