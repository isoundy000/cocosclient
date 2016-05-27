#pragma once
#include "cocoa/CCArray.h"
#include "cocoa/CCObject.h"
#include "cocoa/CCSet.h"
#include "cocos2d.h"

USING_NS_CC;
namespace cocos3d
{
class C3DAction;
    class C3DNode;
struct _hashElement3D
{
	struct _ccArray             *actions;
	CCObject                    *target;
	unsigned int                actionIndex;
	C3DAction                    *currentAction;
	bool                        currentActionSalvaged;
	bool                        paused;
	UT_hash_handle                hh;
} ;

class C3DActionManager : public CCObject
{
public:
	C3DActionManager(void);
	~C3DActionManager(void);

	
    // actions
    
    /** Adds an action with a target. 
     If the target is already present, then the action will be added to the existing target.
     If the target is not present, a new instance of this target will be created either paused or not, and the action will be added to the newly created target.
     When the target is paused, the queued actions won't be 'ticked'.
     */
    void addAction(C3DAction *pAction, C3DNode *pTarget, bool paused);

    /** Removes all actions from all the targets.
    */
    void removeAllActions(void);

    /** Removes all actions from a certain target.
     All the actions that belongs to the target will be removed.
     */
    void removeAllActionsFromTarget(CCObject *pTarget);

    /** Removes an action given an action reference.
    */
    void removeAction(C3DAction *pAction);

    /** Removes an action given its tag and the target */
    void removeActionByTag(unsigned int tag, CCObject *pTarget);

    /** Gets an action given its tag an a target
     @return the Action the with the given tag
     */
    C3DAction* getActionByTag(unsigned int tag, CCObject *pTarget);

    /** Returns the numbers of actions that are running in a certain target. 
     * Composable actions are counted as 1 action. Example:
     * - If you are running 1 Sequence of 7 actions, it will return 1.
     * - If you are running 7 Sequences of 2 actions, it will return 7.
     */
    unsigned int numberOfRunningActionsInTarget(CCObject *pTarget);

    /** Pauses the target: all running actions and newly added actions will be paused.
    */
    void pauseTarget(CCObject *pTarget);

    /** Resumes the target. All queued actions will be resumed.
    */
    void resumeTarget(CCObject *pTarget);
    
    /** Pauses all running actions, returning a list of targets whose actions were paused.
     */
    cocos2d::CCSet* pauseAllRunningActions();
    
    /** Resume a set of targets (convenience function to reverse a pauseAllRunningActions call)
     */
    void resumeTargets(cocos2d::CCSet *targetsToResume);

	static C3DActionManager *getInstance();
	static void destroyInstance();

public:

    void removeActionAtIndex(unsigned int uIndex, struct _hashElement3D *pElement);
    void deleteHashElement(struct _hashElement3D *pElement);
    void actionAllocWithHashElement(struct _hashElement3D *pElement);
    void update(float dt);

protected:
    struct _hashElement3D    *m_pTargets;
    struct _hashElement3D    *m_pCurrentTarget;
    bool            m_bCurrentTargetSalvaged;
};

}
