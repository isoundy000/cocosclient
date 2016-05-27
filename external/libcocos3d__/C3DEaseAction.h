#pragma once
#include "C3DActionInterval.h"

namespace cocos3d{
class C3DEaseAction : public C3DActionInterval
{
public:
	C3DEaseAction(void);
	~C3DEaseAction(void);

	static C3DEaseAction *create(C3DActionInterval *action);

	    /** initializes the action */
    bool initWithAction(C3DActionInterval *pAction);
    virtual void startWithTarget(C3DNode *pTarget);
    virtual void stop(void);
    virtual void update(float time);
    virtual C3DActionInterval* getInnerAction();

protected:
	C3DActionInterval *m_pInner;
};

class C3DEaseRateAction : public C3DEaseAction
{
public:
	CC_SYNTHESIZE(float,m_pRate,Rate);
public:
	static C3DEaseRateAction *create(C3DActionInterval *action,float mRate);

	bool initWithAction(C3DActionInterval *pAction,float mRate);
};


class C3DEaseExponentialIn : public C3DEaseAction
{
public:
    virtual void update(float time);
public:
    /** creates the action */
    static C3DEaseExponentialIn* create(C3DActionInterval* pAction);
};

/** 
 @brief Ease Exponential Out
 @ingroup Actions
 */
class C3DEaseExponentialOut : public C3DEaseAction
{
public:
    virtual void update(float time);
 

public:
    /** creates the action */
    static C3DEaseExponentialOut* create(C3DActionInterval* pAction);
};

/** 
 @brief Ease Exponential InOut
 @ingroup Actions
 */
class C3DEaseExponentialInOut : public C3DEaseAction
{
public:
    virtual void update(float time);
public:

    /** creates the action */
    static C3DEaseExponentialInOut* create(C3DActionInterval* pAction);
};


}

