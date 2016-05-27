#ifndef _C3DAction_H_
#define _C3DAction_H_
#include "cocos2d.h"
#include "C3DNode.h"

USING_NS_CC;
namespace cocos3d
{
class C3DAction : public CCFiniteTimeAction
{
public:
	C3DAction() : CCFiniteTimeAction()
	{

	}
	virtual ~C3DAction();

	CC_SYNTHESIZE(C3DNode *,m3d_pTarget,Target);
public:
	virtual void startWithTarget(C3DNode *_3dTarget);
	/** returns a reversed action */
	virtual C3DAction* reverse(void);
    
    virtual void update(float dt);
};

}

#endif