#pragma once
#include "C3DAction.h"


namespace cocos3d
{
class C3DActionInterval : public C3DAction
{
public:

    /** how many seconds had elapsed since the actions started to run. */
    inline float getElapsed(void) { return m_elapsed; }

    /** initializes the action */
    bool initWithDuration(float d);

    /** returns true if the action has finished */
    virtual bool isDone(void);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual void step(float dt);
    virtual void startWithTarget(C3DNode *pTarget);
    /** returns a reversed action */
    virtual C3DActionInterval* reverse(void);

public:

    /** creates the action */
    static C3DActionInterval* create(float d);

public:
    //extension in CCGridAction 
    void setAmplitudeRate(float amp);
    float getAmplitudeRate(void);

protected:
    float m_elapsed;
    bool   m_bFirstTick;
};


/** @brief Runs actions sequentially, one after another
 */
class  C3DSequence : public C3DActionInterval
{
public:
    /**
     * @js NA
     * @lua NA
     */
    ~C3DSequence(void);

    /** initializes the action 
     * @lua NA
     */
    bool initWithTwoActions(C3DAction *pActionOne, C3DAction *pActionTwo);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    /**
     * @lua NA
     */
    virtual void startWithTarget(C3DNode *pTarget);
    /**
     * @lua NA
     */
    virtual void stop(void);
    /**
     * @lua NA
     */
    virtual void update(float t);
    virtual C3DActionInterval* reverse(void);

public:

    /** helper constructor to create an array of sequenceable actions 
     * @lua NA
     */
    static C3DSequence* create(C3DAction *pAction1, ...);
    /** helper constructor to create an array of sequenceable actions given an array 
     * @js NA
     */
    static C3DSequence* create(CCArray *arrayOfActions);
    /** helper constructor to create an array of sequence-able actions 
     * @js NA
     * @lua NA
     */
    static C3DSequence* createWithVariableList(C3DAction *pAction1, va_list args);
    /** creates the action 
     * @js NA
     */
    static C3DSequence* createWithTwoActions(C3DAction *pActionOne, C3DAction *pActionTwo);

protected:
    C3DAction *m_pActions[2];
    float m_split;
    int m_last;
};

/** @brief Repeats an action a number of times.
 * To repeat an action forever use the CCRepeatForever action.
 */
class C3DRepeat : public C3DActionInterval
{
public:
    /**
     *  @js NA
     *  @lua NA
     */
    ~C3DRepeat(void);

    /** initializes a CCRepeat action. Times is an unsigned integer between 1 and pow(2,30) */
    bool initWithAction(C3DAction *pAction, unsigned int times);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual void startWithTarget(C3DNode *pTarget);
    virtual void stop(void);
    virtual void update(float dt);
    virtual bool isDone(void);
    virtual C3DActionInterval* reverse(void);

    inline void setInnerAction(C3DAction *pAction)
    {
        if (m_pInnerAction != pAction)
        {
            CC_SAFE_RETAIN(pAction);
            CC_SAFE_RELEASE(m_pInnerAction);
            m_pInnerAction = pAction;
        }
    }

    inline C3DAction* getInnerAction()
    {
        return m_pInnerAction;
    }

public:

    /** creates a CCRepeat action. Times is an unsigned integer between 1 and pow(2,30) */
    static C3DRepeat* create(C3DAction *pAction, unsigned int times);
protected:
    unsigned int m_uTimes;
    unsigned int m_uTotal;
    float m_fNextDt;
    bool m_bActionInstant;
    /** Inner action */
    C3DAction *m_pInnerAction;
};

/** @brief Repeats an action for ever.
To repeat the an action for a limited number of times use the Repeat action.
@warning This action can't be Sequenceable because it is not an IntervalAction
*/
class C3DRepeatForever : public C3DActionInterval
{
public:
    /**
     *  @js ctor
     */
    C3DRepeatForever()
        : m_pInnerAction(NULL)
    {}
    /**
     *  @js NA
     *  @lua NA
     */
    virtual ~C3DRepeatForever();

    /** initializes the action */
    bool initWithAction(C3DActionInterval *pAction);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone *pZone);
    virtual void startWithTarget(C3DNode* pTarget);
    virtual void step(float dt);
    virtual bool isDone(void);
    virtual C3DActionInterval* reverse(void);

    inline void setInnerAction(C3DActionInterval *pAction)
    {
        if (m_pInnerAction != pAction)
        {
            CC_SAFE_RELEASE(m_pInnerAction);
            m_pInnerAction = pAction;
            CC_SAFE_RETAIN(m_pInnerAction);
        }
    }

    inline C3DActionInterval* getInnerAction()
    {
        return m_pInnerAction;
    }

public:

    /** creates the action */
    static C3DRepeatForever* create(C3DActionInterval *pAction);
protected:
    /** Inner action */
    C3DActionInterval *m_pInnerAction;
};

/** @brief Spawn a new action immediately
 */
class C3DSpawn : public C3DActionInterval
{
public:
    /**
     * @js NA
     * @lua NA
     */
    ~C3DSpawn(void);

    /** initializes the Spawn action with the 2 actions to spawn 
     * @lua NA
     */
    bool initWithTwoActions(C3DAction *pAction1, C3DAction *pAction2);
    /**
     *  @js NA
     *  @lua NA
     */
    virtual CCObject* copyWithZone(CCZone* pZone);
    /**
     * @lua NA
     */
    virtual void startWithTarget(C3DNode *pTarget);
    /**
     * @lua NA
     */
    virtual void stop(void);
    /**
     * @lua NA
     */
    virtual void update(float time);
    virtual C3DActionInterval* reverse(void);

public:

    /** helper constructor to create an array of spawned actions 
     * @lua NA
     */
    static C3DSpawn* create(C3DAction *pAction1, ...);
    
    /** helper constructor to create an array of spawned actions 
     * @js  NA
     * @lua NA
     */
    static C3DSpawn* createWithVariableList(C3DAction *pAction1, va_list args);

    /** helper constructor to create an array of spawned actions given an array 
     * @js NA
     */
    static C3DSpawn* create(CCArray *arrayOfActions);

    /** creates the Spawn action 
     * @js NA
     */
    static C3DSpawn* createWithTwoActions(C3DAction *pAction1, C3DAction *pAction2);

protected:
    C3DAction *m_pOne;
    C3DAction *m_pTwo;
};

class C3DRotateBy : public C3DActionInterval
{
public: 
    /** creates the action with separate rotation angles */
	static C3DRotateBy* create(float fDuration, const C3DVector3 &deltaAngle);

    virtual bool initWithDuration(float fDuration, const C3DVector3 &deltaAngle);

    virtual void startWithTarget(C3DNode *pTarget);
    virtual void update(float time);
    
protected:
    C3DVector3 startAngle;
    C3DQuaternion rotStart;
	C3DVector3 deltaAngle;
};


class C3DRotateTo : public CCRotateBy
{
public:
	static C3DRotateTo* create(float fDuration, const C3DVector3 &destAngle);
	virtual bool initWithDuration(float fDuration, const C3DVector3 &deltaAngle);

	virtual void startWithTarget(C3DNode *pTarget);
	virtual void update(float time);
};

class C3DMoveBy : public C3DActionInterval
{
public:
	static C3DMoveBy* create(float fDuration, const C3DVector3 &delta);
	virtual bool initWithDuration(float fDuration, const C3DVector3 &delta);

	virtual void startWithTarget(C3DNode *pTarget);
	virtual void update(float time);
protected:
	C3DVector3 startPosition;
	C3DVector3 deltaPosition;
};

class C3DMoveTo : public C3DMoveBy
{
public:
	static C3DMoveTo* create(float fDuration, const C3DVector3 &dstPosition);
	virtual bool initWithDuration(float fDuration, const C3DVector3 &delta);

	virtual void startWithTarget(C3DNode *pTarget);
	virtual void update(float time);
};

typedef struct _c3dBezierConfig {
	//! end position of the bezier
	C3DVector3 endPosition;
	//! Bezier control point 1
	C3DVector3 controlPoint_1;
	//! Bezier control point 2
	C3DVector3 controlPoint_2;
} c3dBezierConfig;

class C3DBezierBy : public C3DActionInterval
{
public:
	static C3DBezierBy *create(float fDuration,c3dBezierConfig &bezierConfig);
	virtual bool initWithDuration(float duration,c3dBezierConfig &beCf);
	virtual void startWithTarget(C3DNode *pTarget);
	virtual void update(float time); 

protected:
	c3dBezierConfig m_bezierConfig;
	C3DVector3 m_StartPos;
	C3DVector3 m_PreviousPos;
};

class C3DBezierTo : public C3DBezierBy
{
public:
	static C3DBezierTo *create(float fDuration,c3dBezierConfig &bezierConfig);
	virtual void startWithTarget(C3DNode *pTarget);
};

/** @brief Delays the action a certain amount of seconds
*/
class C3DDelayTime : public C3DActionInterval
{
public:
    /** creates the action */
    static C3DDelayTime* create(float d);
};


}

