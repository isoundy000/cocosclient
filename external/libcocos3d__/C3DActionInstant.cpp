#include "C3DActionInstant.h"

namespace cocos3d{
C3DActionInstant::C3DActionInstant(void)
{
}

bool C3DActionInstant::isDone()
{
	return true;
}

void C3DActionInstant::step(float dt)
{
	CC_UNUSED_PARAM(dt);
	update(1);
}

void C3DActionInstant::update(float dt)
{
	CC_UNUSED_PARAM(dt);
}

C3DShow::C3DShow()
{

}
C3DShow *C3DShow::create()
{
	C3DShow *pRet = new C3DShow();
	pRet->autorelease();

	return pRet;
}

void C3DShow::update(float dt)
{
	CC_UNUSED_PARAM(dt);
	m3d_pTarget->active(true);
}

C3DHide::C3DHide()
{

}

C3DHide *C3DHide::create()
{
	C3DHide *pRet = new C3DHide();
	pRet->autorelease();

	return pRet;
}

void C3DHide::update(float dt)
{
	CC_UNUSED_PARAM(dt);
	m3d_pTarget->active(false);
}

C3DRemoveSelf::C3DRemoveSelf()
{

}
C3DRemoveSelf *C3DRemoveSelf::create()
{
	C3DRemoveSelf *pRet = new C3DRemoveSelf();
	pRet->autorelease();

	return pRet;
}

void C3DRemoveSelf::update(float dt)
{
	CC_UNUSED_PARAM(dt);
	m3d_pTarget->removeFromParent();
}

C3DPlace* C3DPlace::create(C3DVector3 position)
{
	C3DPlace *pRet = new C3DPlace();
	pRet->autorelease();
	pRet->pos = position;
	return pRet;
}

void C3DPlace::update(float dt)
{
	CC_UNUSED_PARAM(dt);
	m3d_pTarget->setPosition(pos);

}

C3DCallFunc::C3DCallFunc()
{
	m_pCallFunc = NULL;
}

C3DCallFunc *C3DCallFunc::create(SEL_3DCallFunc selector,void *data)
{
	C3DCallFunc *pRet = new C3DCallFunc();
	pRet->m_pCallFunc = selector;
	pRet->m_pData = data;
	pRet->autorelease();
	return pRet;
}

void C3DCallFunc::update(float time)
{
	CC_UNUSED_PARAM(time);
	m_pCallFunc(m3d_pTarget,m_pData);
}

}

