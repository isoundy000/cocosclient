#include "C3DAction.h"

namespace cocos3d
{
void C3DAction::startWithTarget(C3DNode *_3dTarget)
{
	m3d_pTarget = _3dTarget;
}

C3DAction *C3DAction::reverse()
{

	return NULL;
}
    
void C3DAction::update(float dt)
    {
        
    }
    
C3DAction::~C3DAction()
{
	//CCLOG("ACtion 3D deleted !!");
}

}