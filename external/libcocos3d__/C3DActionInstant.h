#pragma once
#include "C3DAction.h"
namespace cocos3d{
class C3DActionInstant : public C3DAction
{
public:
	C3DActionInstant(void);
	~C3DActionInstant(void){};

	virtual void step(float dt);
	virtual void update(float dt);
	virtual bool isDone();
};


class C3DShow : public C3DActionInstant
{
public:
	C3DShow();
	~C3DShow(){};

	static C3DShow* create();
	virtual void update(float dt);
};

class C3DHide : public C3DActionInstant
{
public:
	C3DHide();
	~C3DHide(){};

	static C3DHide* create();
	virtual void update(float dt);
};

class C3DRemoveSelf : public C3DActionInstant
{
public:
	C3DRemoveSelf();
	~C3DRemoveSelf(){};

	static C3DRemoveSelf* create();
	virtual void update(float dt);
};

class C3DPlace : public C3DActionInstant
{
public:
	C3DPlace(){};
	~C3DPlace(){};

	static C3DPlace* create(C3DVector3 position);
	virtual void update(float dt);

	C3DVector3 pos;
};


typedef void (*SEL_3DCallFunc)(C3DNode *pSender,void *data);
class  C3DCallFunc : public C3DActionInstant //<NSCopying>
{
public:
    /**
     *  @js ctor
     */
    C3DCallFunc();
	~C3DCallFunc(){};
    static C3DCallFunc * create(SEL_3DCallFunc selector,void *data);

    virtual void update(float time);
protected:
	SEL_3DCallFunc m_pCallFunc;
	void *m_pData;
};

}