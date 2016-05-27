/*
 * Cocos3D-X 1.0.0
 * Author: Bill Hollings
 * Copyright (c) 2010-2014 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Copyright (c) 2014-2015 Jason Wong
 * http://www.cocos3dx.org/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * http://en.wikipedia.org/wiki/MIT_License
 */
#include "cocos3d.h"

NS_COCOS3D_BEGIN


	// Extra action for making a CCSequence or CCSpawn when only adding one action to it.
class ExtraAction3D : public CC3ActionInterval
{
public:
	static ExtraAction3D* create();
	virtual CCObject* copyWithZone(CCZone* pZone);
	virtual ExtraAction3D* reverse(void);
	virtual void update(float time);
	virtual void step(float dt);
};

ExtraAction3D* ExtraAction3D::create()
{
	ExtraAction3D* pRet = new ExtraAction3D();
	if (pRet)
	{
		pRet->autorelease();
	}
	return pRet;
}

CCObject* ExtraAction3D::copyWithZone(CCZone* pZone)
{
	CC_UNUSED_PARAM(pZone);
	ExtraAction3D* pRet = new ExtraAction3D();
	return pRet;
}

ExtraAction3D* ExtraAction3D::reverse(void)
{
	return ExtraAction3D::create();
}

void ExtraAction3D::update(float time)
{
	CC_UNUSED_PARAM(time);
}

void ExtraAction3D::step(float dt)
{
	CC_UNUSED_PARAM(dt);
}



CCAction* CC3ActionInterval::repeatForever()
{ 
	return CC3RepeatForever::create( this );
}

CC3Node* CC3ActionInterval::getTargetNode()
{
	return (CC3Node*)m_pTargetCC3Node; 
}

void CC3ActionInterval::startWithTarget( CC3Node* pNode )
{
	m_pTargetCC3Node = pNode;
	m_elapsed = 0.0f;
	m_bFirstTick = true;
}

CC3ActionInterval* CC3ActionInterval::reverse()
{
	return NULL;
}

void CC3ActionInterval::initWithDuration( float d )
{
	CCActionInterval::initWithDuration( d );
}

void CC3ActionTransformVector::initWithDuration( float t, const CC3Vector& aVector )    /// differeneceVector
{
	super::initWithDuration( t ); 
	m_diffVector = aVector;
}

CC3ActionTransformVector* CC3ActionTransformVector::actionWithDuration( float t, const CC3Vector& aVector )
{
	CC3ActionTransformVector* pAction = new CC3ActionTransformVector;
	pAction->initWithDuration( t, aVector );
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionTransformVector::copyWithZone( CCZone* pZone ) 
{
	CC3ActionTransformVector* pAction = new CC3ActionTransformVector;
	pAction->initWithDuration( getDuration(), m_diffVector );

	return pAction;
}

CC3ActionInterval* CC3ActionTransformVector::reverse()
{
	return CC3ActionTransformVector::actionWithDuration( getDuration(), m_diffVector.negate() );
}

void CC3ActionTransformVector::startWithTarget( CC3Node* aTarget )
{
	CC3ActionInterval::startWithTarget( aTarget );
	m_startVector = getTargetVector();
}

void CC3ActionTransformVector::update( float t )
{	
	setTargetVector( m_startVector.add( m_diffVector.scaleUniform( t )) );
}

CC3Vector CC3ActionTransformVector::getTargetVector()
{ 
	return CC3Vector::kCC3VectorZero; 
}

void CC3ActionTransformVector::setTargetVector( const CC3Vector& aVector )
{

}

void CC3ActionMoveBy::initWithDuration( float t, const CC3Vector& aTranslation )   /// moveBy
{
	CC3ActionTransformVector::initWithDuration( t, aTranslation );
}

CC3ActionMoveBy* CC3ActionMoveBy::actionWithDuration( float t, const CC3Vector& aTranslation )
{
	CC3ActionMoveBy* pVal = new CC3ActionMoveBy;
	pVal->initWithDuration( t, aTranslation );
	pVal->autorelease();

	return pVal;
}

CC3Vector CC3ActionMoveBy::getTargetVector()
{
	return getTargetNode()->getLocation(); 
}

void CC3ActionMoveBy::setTargetVector( const CC3Vector& aLocation )
{
	getTargetNode()->setLocation( aLocation );
}

void CC3ActionRotateBy::initWithDuration( float t, const CC3Vector& aRotation )  /// rotateBy
{
	CC3ActionTransformVector::initWithDuration( t, aRotation );
}

CC3ActionRotateBy* CC3ActionRotateBy::actionWithDuration( float t, const CC3Vector& aRotation )
{
	CC3ActionRotateBy* pAction = new CC3ActionRotateBy;
	pAction->initWithDuration( t, aRotation );
	pAction->autorelease();

	return pAction;
}

CC3Vector CC3ActionRotateBy::getTargetVector()
{ 
	return getTargetNode()->getRotation(); 
}

void CC3ActionRotateBy::setTargetVector( const CC3Vector& aRotation )
{ 
	getTargetNode()->setRotation( aRotation ); 
}

void CC3ActionRotateForever::initWithRotationRate( const CC3Vector& rotationPerSecond )
{
	initWithAction( CC3ActionRotateBy::actionWithDuration( 1.0, rotationPerSecond ));
}

CC3ActionRotateForever* CC3ActionRotateForever::actionWithRotationRate( const CC3Vector& rotationPerSecond )
{
	CC3ActionRotateForever* pAction = new CC3ActionRotateForever;
	pAction->initWithRotationRate( rotationPerSecond );
	pAction->autorelease();

	return pAction;
}

CC3ActionInterval* CC3ActionRotateForever::reverse()
{ 
	// return [self.class actionWithAction: [self.innerAction reverse]]; }

	CCAssert( false, "CC3ActionRotateForever::reverse() not implemented for now" );
	return NULL;
}

/**
 * Scale is multiplicative. Scaling BY 5 means take whatever the current scale is
 * and multiply it by 5. If the previous scale was 3, then the future scale
 * will be 15, not 8 if the numbers were simply added as in the superclass.
 */
void CC3ActionScaleBy::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	CC3Vector endVector = m_startVector.scale( m_diffVector );
	m_scaleDiffVector = endVector - m_startVector;
}

void CC3ActionScaleBy::initWithDuration( float t, const CC3Vector& aScale )  /// scaleBy
{
	super::initWithDuration( t, aScale );
}

CC3ActionScaleBy* CC3ActionScaleBy::actionWithDuration( float t, const CC3Vector& aScale )
{
	CC3ActionScaleBy* pAction = new CC3ActionScaleBy;
	pAction->initWithDuration( t, aScale );
	pAction->autorelease();

	return pAction;
}

void CC3ActionScaleBy::initWithDuration( float t, GLfloat aScale )
{
	return initWithDuration( t, cc3v(aScale, aScale, aScale) );
}

CC3ActionScaleBy* CC3ActionScaleBy::actionWithDuration( float t, GLfloat aScale )
{
	return actionWithDuration( t, cc3v(aScale, aScale, aScale) );
}

void CC3ActionScaleBy::update( float t )
{	
	setTargetVector( m_startVector.add( m_scaleDiffVector.scaleUniform( t ) ) );
}

CC3Vector CC3ActionScaleBy::getTargetVector()
{
	return getTargetNode()->getScale(); 
}

void CC3ActionScaleBy::setTargetVector( const CC3Vector& aScale )
{
	getTargetNode()->setScale( aScale );  
}
 
void CC3ActionRotateByAngle::initWithDuration( float t, GLfloat anAngle )
{
	return initWithDuration( t, anAngle, CC3Vector::kCC3VectorNull );
}

CC3ActionRotateByAngle* CC3ActionRotateByAngle::actionWithDuration( float t, GLfloat anAngle )
{
	CC3ActionRotateByAngle* pAction = new CC3ActionRotateByAngle;
	pAction->initWithDuration( t, anAngle );
	pAction->autorelease();

	return pAction;
}

void CC3ActionRotateByAngle::initWithDuration( float t, GLfloat anAngle, const CC3Vector& anAxis )
{
	super::initWithDuration( t );
	m_diffAngle = anAngle;
	m_rotationAxis = anAxis;
}

CC3ActionRotateByAngle* CC3ActionRotateByAngle::actionWithDuration( float t, GLfloat anAngle, const CC3Vector& anAxis )
{
	CC3ActionRotateByAngle* pAction = new CC3ActionRotateByAngle;
	pAction->initWithDuration( t, anAngle, anAxis );
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionRotateByAngle::copyWithZone( CCZone* zone )
{
	CC3ActionRotateByAngle* pAction = new CC3ActionRotateByAngle;
	pAction->initWithDuration( getDuration(), m_diffAngle, m_rotationAxis );
	
	return pAction;
}

CC3ActionInterval* CC3ActionRotateByAngle::reverse() 
{
	return actionWithDuration( getDuration(), -m_diffAngle, m_rotationAxis );
}

/** If no explicit rotation axis was set, retrieve it from the target node. */
void CC3ActionRotateByAngle::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_activeRotationAxis = m_rotationAxis.isNull() ? aTarget->getRotationAxis() : m_rotationAxis;
	m_fPrevTime = 0;
}

void CC3ActionRotateByAngle::update( float t )
{
	GLfloat deltaTime = t - m_fPrevTime;
	GLfloat deltaAngle = m_diffAngle * deltaTime;
	getTargetNode()->rotateByAngle( deltaAngle, m_activeRotationAxis );
	m_fPrevTime = t;
}

std::string CC3ActionRotateByAngle::description()
{
	return CC3String::stringWithFormat( (char*)"CC3ActionRotateByAngle angle: %.3f, axis: %s", m_diffAngle, m_rotationAxis.stringfy().c_str() );
}

void CC3ActionRotateOnAxisForever::initWithRotationRate( GLfloat degreesPerSecond, const CC3Vector& anAxis )
{
	initWithAction( CC3ActionRotateByAngle::actionWithDuration( 1.0f, degreesPerSecond, anAxis ) );
}

CC3ActionRotateOnAxisForever* CC3ActionRotateOnAxisForever::actionWithRotationRate( GLfloat degreesPerSecond, const CC3Vector& anAxis )
{
	CC3ActionRotateOnAxisForever* pAction = new CC3ActionRotateOnAxisForever;
	pAction->initWithRotationRate( degreesPerSecond, anAxis );
	pAction->autorelease();

	return pAction;
}

CC3ActionInterval* CC3ActionRotateOnAxisForever::reverse()
{
	return create( (CC3ActionInterval*)getInnerAction()->reverse() ); 
}


void CC3ActionTransformTo::initWithDuration( float t, const CC3Vector& aVector ) /// endVector
{
	CC3ActionInterval::initWithDuration( t );
	m_endVector = aVector;
}

CC3ActionTransformTo* CC3ActionTransformTo::actionWithDuration( float t, const CC3Vector& aVector )
{
	CC3ActionTransformTo* pAction = new CC3ActionTransformTo;
	pAction->initWithDuration( t, aVector );
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionTransformTo::copyWithZone( CCZone* zone )
{
	CC3ActionTransformTo* pAction = new CC3ActionTransformTo;
	pAction->initWithDuration( getDuration(), m_endVector );
	return pAction;
}

CC3ActionInterval* CC3ActionTransformTo::reverse()
{
	return actionWithDuration( getDuration(), m_startVector );
}

void CC3ActionTransformTo::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_diffVector = m_endVector - m_startVector;
}

std::string CC3ActionTransformTo::description()
{
	return CC3String::stringWithFormat( (char*)"%CC3ActionTransformTo start: %s, end: %s, diff: %s", 
		m_startVector.stringfy().c_str(), m_endVector.stringfy().c_str(),
			m_diffVector.stringfy().c_str() );
}

void CC3ActionMoveTo::initWithDuration( float t, const CC3Vector& aLocation ) /// moveTo
{
	return super::initWithDuration( t, aLocation );
}

CC3ActionMoveTo* CC3ActionMoveTo::actionWithDuration( float t, const CC3Vector& aLocation )
{
	CC3ActionMoveTo* pAction = new CC3ActionMoveTo;
	pAction->initWithDuration( t, aLocation );
	pAction->autorelease();

	return pAction;
}

CC3Vector CC3ActionMoveTo::getTargetVector()
{
	return getTargetNode()->getLocation(); 
}

void CC3ActionMoveTo::setTargetVector( const CC3Vector& aLocation ) 
{
	getTargetNode()->setLocation( aLocation );   
}


void CC3ActionRotateTo::initWithDuration( float t, const CC3Vector& aRotation ) /// rotateTo
{
	return super::initWithDuration( t, aRotation );
}

CC3ActionRotateTo* CC3ActionRotateTo::actionWithDuration( float t, const CC3Vector& aRotation )
{
	CC3ActionRotateTo* pAction = new CC3ActionRotateTo;
	pAction->initWithDuration( t, aRotation );
	pAction->autorelease();

	return pAction;
}

// We want to rotate the minimal angles to get from the startVector to the endVector,
// taking into consideration the cyclical nature of rotation. Therefore, a rotation
// from 10 degrees to 350 degrees should travel -20 degrees, not the +340 degrees
// that would result from simple subtraction.
void CC3ActionRotateTo::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_diffVector = m_endVector.rotationalDifference( m_startVector );
}

CC3Vector CC3ActionRotateTo::getTargetVector()
{
	return getTargetNode()->getRotation(); 
}

void CC3ActionRotateTo::setTargetVector( const CC3Vector& aRotation )
{
	getTargetNode()->setRotation( aRotation );
}

void CC3ActionScaleTo::initWithDuration( float t, const CC3Vector& aScale )  /// scaleTo
{
	super::initWithDuration(t, aScale);
}

CC3ActionScaleTo* CC3ActionScaleTo::actionWithDuration( float t, const CC3Vector& aScale )
{
	CC3ActionScaleTo* pAction = new CC3ActionScaleTo;
	pAction->initWithDuration( t, aScale );
	pAction->autorelease();

	return pAction;
}

void CC3ActionScaleTo::initWithDuration( float t, GLfloat aScale )
{
	return initWithDuration( t, cc3v(aScale, aScale, aScale) );
}

CC3ActionScaleTo* CC3ActionScaleTo::actionWithDuration( float t, GLfloat aScale )
{
	CC3ActionScaleTo* pAction = new CC3ActionScaleTo;
	pAction->initWithDuration( t, aScale );
	pAction->autorelease();

	return pAction;
}

CC3Vector CC3ActionScaleTo::getTargetVector()
{
	return getTargetNode()->getScale(); 
}

void CC3ActionScaleTo::setTargetVector( const CC3Vector& aScale )
{
	getTargetNode()->setScale( aScale );  
}

void CC3ActionRotateToAngle::initWithDuration( float t, GLfloat anAngle )
{
	super::initWithDuration( t );
	m_endAngle = anAngle;
}

CC3ActionRotateToAngle* CC3ActionRotateToAngle::actionWithDuration( float t, GLfloat anAngle )
{
	CC3ActionRotateToAngle* pAction = new CC3ActionRotateToAngle;
	pAction->initWithDuration( t, anAngle );
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionRotateToAngle::copyWithZone( CCZone* zone )
{
	CC3ActionRotateToAngle* pAction = new CC3ActionRotateToAngle;
	pAction->initWithDuration( getDuration(), m_endAngle );
	return pAction;
}

CC3ActionInterval* CC3ActionRotateToAngle::reverse()
{
	return actionWithDuration( getDuration(), m_startAngle );
}

void CC3ActionRotateToAngle::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_startAngle = aTarget->getRotationAngle();
	m_diffAngle = CC3SemiCyclicAngle(m_endAngle - m_startAngle);
}

void CC3ActionRotateToAngle::update( float t )
{	
	getTargetNode()->setRotationAngle( m_startAngle + (m_diffAngle * t) );
}

std::string CC3ActionRotateToAngle::description()
{
	return CC3String::stringWithFormat( (char*)"CC3ActionRotateToAngle start: %.3f, end: %.3f, diff: %.3f",
			m_startAngle, m_endAngle, m_diffAngle );
}

void CC3ActionRotateToLookTowards::initWithDuration( float t, const CC3Vector& aDirection )	/// forwardDirection
{
	return super::initWithDuration( t, aDirection.normalize() );
}

CC3ActionRotateToLookTowards* CC3ActionRotateToLookTowards::actionWithDuration( float t, const CC3Vector& aDirection )
{
	CC3ActionRotateToLookTowards* pAction = new CC3ActionRotateToLookTowards;
	pAction->initWithDuration( t, aDirection );
	pAction->autorelease();

	return pAction;
}

CC3Vector CC3ActionRotateToLookTowards::getTargetVector()
{
	return getTargetNode()->getForwardDirection();
}

void CC3ActionRotateToLookTowards::setTargetVector( const CC3Vector& aDirection )
{
	getTargetNode()->setForwardDirection( aDirection );   
}

void CC3ActionRotateToLookAt::initWithDuration( float t, const CC3Vector& aLocation )
{
	return CC3ActionTransformTo::initWithDuration( t, aLocation );
}

CC3ActionRotateToLookAt* CC3ActionRotateToLookAt::actionWithDuration( float t, const CC3Vector& aLocation )
{
	CC3ActionRotateToLookAt* pAction = new CC3ActionRotateToLookAt;
	pAction->initWithDuration( t, aLocation );
	pAction->autorelease();

	return pAction;
}

void CC3ActionRotateToLookAt::startWithTarget( CC3Node* aTarget )
{
    m_endVector = m_endVector - aTarget->getGlobalLocation();
    m_endVector = m_endVector.normalize();
	super::startWithTarget( aTarget );
}

void CC3ActionMoveDirectionallyBy::initWithDuration( float t, GLfloat aDistance )
{
	super::initWithDuration( t );
	m_distance = aDistance;
}

CC3ActionMoveDirectionallyBy* CC3ActionMoveDirectionallyBy::actionWithDuration( float t, GLfloat aDistance )
{
	CC3ActionMoveDirectionallyBy* pAction = new CC3ActionMoveDirectionallyBy;
	pAction->initWithDuration( t, aDistance );
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionMoveDirectionallyBy::copyWithZone( CCZone* zone )
{
	CC3ActionMoveDirectionallyBy* pAction = new CC3ActionMoveDirectionallyBy;
	pAction->initWithDuration( getDuration(), m_distance );
	
	return pAction;
}

CC3ActionInterval* CC3ActionMoveDirectionallyBy::reverse()
{
	CC3ActionMoveDirectionallyBy* pAction = new CC3ActionMoveDirectionallyBy;
	pAction->initWithDuration( getDuration(), -m_distance );
	pAction->autorelease();

	return pAction;
}

void CC3ActionMoveDirectionallyBy::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_prevTime = 0;
}

void CC3ActionMoveDirectionallyBy::update( float t )
{
	GLfloat deltaTime = t - m_prevTime;
	GLfloat deltaDist = m_distance * deltaTime;
	CC3Vector moveDir = getTargetDirection().normalize();
	CC3Vector prevLoc = getTargetNode()->getLocation();
	getTargetNode()->setLocation( prevLoc.add( moveDir.scaleUniform(deltaDist) ) );
	m_prevTime = t;
	
	/*LogTrace(@"%@: time: %.3f, delta time: %.3f, delta dist: %.3f, was at: %@, now at: %@",
				  self, t, deltaTime, deltaDist,
				  NSStringFromCC3Vector(prevLoc),
				  NSStringFromCC3Vector(self.targetCC3Node.location));*/
}

/** The direction in which to move. Subclasses will override. */
CC3Vector CC3ActionMoveDirectionallyBy::getTargetDirection()
{
	return CC3Vector::kCC3VectorZero; 
}

std::string CC3ActionMoveDirectionallyBy::description()
{
	return CC3String::stringWithFormat( (char*)"CC3ActionMoveDirectionallyBy distance: %.3f", m_distance );
}

CC3Vector CC3ActionMoveForwardBy::getTargetDirection()
{
	return getTargetNode()->getForwardDirection(); 
}

CC3Vector CC3ActionMoveRightBy::getTargetDirection()
{
	return getTargetNode()->getRightDirection(); 
}


CC3Vector CC3ActionMoveUpBy::getTargetDirection()
{
	return getTargetNode()->getUpDirection(); 
}

ccColor4F CC3ActionTintTo::getTargetColor()
{
	return getTargetNode()->getDiffuseColor(); 
}

void CC3ActionTintTo::setTargetColor( const ccColor4F& aColor )
{
	getTargetNode()->setAmbientColor( aColor );
	getTargetNode()->setDiffuseColor( aColor );
}

void CC3ActionTintTo::initWithDuration( float t, const ccColor4F& aColor )
{
	super::initWithDuration( t );
	m_endColor = aColor;
}

CC3ActionTintTo* CC3ActionTintTo::actionWithDuration( float t, const ccColor4F& aColor )
{
	CC3ActionTintTo* pAction = new CC3ActionTintTo;
	pAction->initWithDuration( t, aColor );
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionTintTo::copyWithZone( CCZone* zone )
{
	CC3ActionTintTo* pAction = new CC3ActionTintTo;
	pAction->initWithDuration( getDuration(), m_endColor );
	return pAction;
}

void CC3ActionTintTo::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_startColor = getTargetColor();
}

void CC3ActionTintTo::update( float t )
{
	setTargetColor( CCC4FBlend(m_startColor, m_endColor, t) );
}

ccColor4F CC3ActionTintAmbientTo::getTargetColor()
{
	return getTargetNode()->getAmbientColor(); 
}

void CC3ActionTintAmbientTo::setTargetColor( const ccColor4F& aColor )
{
	getTargetNode()->setAmbientColor( aColor );  
}

ccColor4F CC3ActionTintDiffuseTo::getTargetColor()
{
	return getTargetNode()->getDiffuseColor(); 
}

void CC3ActionTintDiffuseTo::setTargetColor( const ccColor4F& aColor )
{
	getTargetNode()->setDiffuseColor( aColor );  
}

ccColor4F CC3ActionTintSpecularTo::getTargetColor()
{
	return getTargetNode()->getSpecularColor(); 
}

void CC3ActionTintSpecularTo::setTargetColor( const ccColor4F& aColor )
{
	getTargetNode()->setSpecularColor( aColor ); 
}

ccColor4F CC3ActionTintEmissionTo::getTargetColor()
{
	return getTargetNode()->getEmissionColor(); 
}

void CC3ActionTintEmissionTo::setTargetColor( const ccColor4F& aColor )
{
	getTargetNode()->setEmissionColor( aColor ); 
}

bool CC3ActionAnimate::isReversed()
{
	return m_isReversed;
}

void CC3ActionAnimate::setIsReversed( bool reversed )
{
	m_isReversed = reversed;
}

void CC3ActionAnimate::initWithDuration( float t )
{
	return initWithDuration( t, 0 ); 
}

CC3ActionAnimate* CC3ActionAnimate::actionWithDuration( float t )
{
	return actionWithDuration( t, 0 ); 
}

void CC3ActionAnimate::initWithDuration( float t, GLuint trackID )
{
	super::initWithDuration( t );
	m_trackID = trackID;
	m_isReversed = false;
}

CC3ActionAnimate* CC3ActionAnimate::actionWithDuration( float t, GLuint trackID )
{
	CC3ActionAnimate* pAction = new CC3ActionAnimate;
	pAction->initWithDuration( t, trackID );
	pAction->autorelease();

	return pAction;
}

CC3ActionAnimate* CC3ActionAnimate::actionWithDuration( float t, GLfloat startOfRange, GLfloat endOfRange )
{
	return actionWithDuration( t, 0, startOfRange, endOfRange );
}

CC3ActionAnimate* CC3ActionAnimate::actionWithDuration( float t, GLuint trackID, GLfloat startOfRange, GLfloat endOfRange )
{
#pragma _NOTE_TODO( "CC3ActionAnimate* CC3ActionAnimate::actionWithDuration( float t, GLuint trackID, GLfloat startOfRange, GLfloat endOfRange )" )
	// return actionWithDuration( t, trackID )->asActionLimitedFrom( startOfRange, endOfRange );
	return NULL;
}

CC3ActionInterval* CC3ActionAnimate::asActionLimitedFrom( GLfloat startOfRange, GLfloat endOfRange )
{
#pragma _NOTE_TODO( "CC3ActionInterval* CC3ActionAnimate::asActionLimitedFrom( GLfloat startOfRange, GLfloat endOfRange )" )
	// return CC3ActionRangeLimit::actionWithAction( this, startOfRange, endOfRange );
	return NULL;
}

void CC3ActionAnimate::update( float t )
{
	getTargetNode()->establishAnimationFrameAt( m_isReversed ? (1.0f - t) : t, m_trackID );
}

CC3ActionInterval* CC3ActionAnimate::reverse()
{
	CC3ActionAnimate* newAnim = actionWithDuration( getDuration() );
	newAnim->setIsReversed( !isReversed() );
	return newAnim;
}

CCObject* CC3ActionAnimate::copyWithZone( CCZone* zone )
{
	CC3ActionAnimate* newAnim = new CC3ActionAnimate;
	newAnim->initWithDuration( getDuration() );
	newAnim->setIsReversed( isReversed() );
	return newAnim;
}


void CC3ActionAnimationBlendingFadeTrackTo::initWithDuration( float t, GLuint trackID, GLfloat blendingWeight )
{
	super::initWithDuration( t );
	m_trackID = trackID;
	m_endWeight = blendingWeight;
}

CC3ActionAnimationBlendingFadeTrackTo* CC3ActionAnimationBlendingFadeTrackTo::actionWithDuration( float t, GLuint trackID, GLfloat blendingWeight )
{
	CC3ActionAnimationBlendingFadeTrackTo* pAction = new CC3ActionAnimationBlendingFadeTrackTo;
	pAction->initWithDuration( t, trackID, blendingWeight );
	pAction->autorelease();
	
	return pAction;
}

void CC3ActionAnimationBlendingFadeTrackTo::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_startWeight = aTarget->animationBlendingWeightOnTrack( m_trackID );
}

void CC3ActionAnimationBlendingFadeTrackTo::update( float t )
{
	getTargetNode()->setAnimationBlendingWeight( m_startWeight + (t * (m_endWeight - m_startWeight)), m_trackID );
}

CC3ActionInterval* CC3ActionAnimationBlendingFadeTrackTo::reverse()
{
	return actionWithDuration( getDuration(), m_trackID, m_startWeight );
}
	
CCObject* CC3ActionAnimationBlendingFadeTrackTo::copyWithZone( CCZone* zone )
{
	CC3ActionAnimationBlendingFadeTrackTo* pAction = new CC3ActionAnimationBlendingFadeTrackTo;
	pAction->initWithDuration( getDuration(), m_trackID, m_endWeight );
	
	return pAction;
}

void CC3ActionAnimationCrossFade::initWithDuration( float t, GLuint fromTrackID, GLuint toTrackID )
{
	return initWithDuration( t, fromTrackID, toTrackID, 1.0f );
}

void CC3ActionAnimationCrossFade::initWithDuration( float t, GLuint fromTrackID, GLuint toTrackID, GLfloat toBlendingWeight )
{
	super::initWithDuration( t );
	m_fromTrackID = fromTrackID;
	m_toTrackID = toTrackID;
	m_endWeight = toBlendingWeight;
}

CC3ActionAnimationCrossFade* CC3ActionAnimationCrossFade::actionWithDuration( float t, GLuint fromTrackID, GLuint toTrackID )
{
	return actionWithDuration( t, fromTrackID, toTrackID, 1.0f );
}

CC3ActionAnimationCrossFade* CC3ActionAnimationCrossFade::actionWithDuration( float t, GLuint fromTrackID, GLuint toTrackID, GLfloat toBlendingWeight )
{
	CC3ActionAnimationCrossFade* pAction = new CC3ActionAnimationCrossFade;
	pAction->initWithDuration( t, fromTrackID, toTrackID, toBlendingWeight );
	pAction->autorelease();

	return pAction;
}

void CC3ActionAnimationCrossFade::startWithTarget( CC3Node* aTarget )
{
	super::startWithTarget( aTarget );
	m_startWeight = aTarget->animationBlendingWeightOnTrack( m_fromTrackID );
}

void CC3ActionAnimationCrossFade::update( float t )
{
	CC3Node* node = getTargetNode();
	node->setAnimationBlendingWeight( ((1.f - t) * m_startWeight), m_fromTrackID );
	node->setAnimationBlendingWeight( (t * m_endWeight), m_toTrackID );
}

CC3ActionInterval* CC3ActionAnimationCrossFade::reverse()
{
	return actionWithDuration( getDuration(), getToTrackID(), getFromTrackID(), m_startWeight );
}

GLuint CC3ActionAnimationCrossFade::getFromTrackID()
{
	return m_fromTrackID;
}

GLuint CC3ActionAnimationCrossFade::getToTrackID()
{
	return m_toTrackID;
}

CCObject* CC3ActionAnimationCrossFade::copyWithZone( CCZone* zone )
{
	CC3ActionAnimationCrossFade* pAction = new CC3ActionAnimationCrossFade;
	pAction->initWithDuration( getDuration(), getFromTrackID(), getToTrackID(), m_endWeight );
	
	return pAction;
}

void CC3ActionAnimationBlendingSetTrackTo::initOnTrack( GLuint trackID, GLfloat blendingWeight )
{
	//super::init();
	m_trackID = trackID;
	m_endWeight = blendingWeight;
}

CC3ActionAnimationBlendingSetTrackTo* CC3ActionAnimationBlendingSetTrackTo::actionOnTrack( GLuint trackID, GLfloat blendingWeight )
{
	CC3ActionAnimationBlendingSetTrackTo* pAction = new CC3ActionAnimationBlendingSetTrackTo;
	pAction->initOnTrack( trackID, blendingWeight );
	pAction->autorelease();

	return pAction;
}

void CC3ActionAnimationBlendingSetTrackTo::update( float t )
{
	//getTargetNode()->setAnimationBlendingWeight( m_endWeight, _trackID );
}

void CC3ActionEnableAnimationTrack::initOnTrack( GLuint trackID )
{
	//super::init();
	m_trackID = trackID;
}

CC3ActionEnableAnimationTrack* CC3ActionEnableAnimationTrack::actionOnTrack( GLuint trackID )
{
	CC3ActionEnableAnimationTrack* pAction = new CC3ActionEnableAnimationTrack;
	pAction->initOnTrack( trackID );
	pAction->autorelease();

	return pAction;
}

void CC3ActionEnableAnimationTrack::update( float t )
{
	//getTargetNode()->enableAllAnimationOnTrack( _trackID ); 
}


void CC3ActionDisableAnimationTrack::initOnTrack( GLuint trackID )
{
	//super::init();
	m_trackID = trackID;
}

CC3ActionDisableAnimationTrack* CC3ActionDisableAnimationTrack::actionOnTrack( GLuint trackID )
{
	CC3ActionDisableAnimationTrack* pAction = new CC3ActionDisableAnimationTrack;
	pAction->initOnTrack( trackID );
	pAction->autorelease();

	return pAction;
}

void CC3ActionDisableAnimationTrack::update( float t )
{
	//getTargetNode()->disableAllAnimationOnTrack( _trackID ); 
}

void CC3ActionRangeLimit::initWithAction( CCActionInterval* action, GLfloat startOfRange, GLfloat endOfRange )
{
	super::initWithAction( action );
	m_rangeStart = startOfRange;
	m_rangeSpan = endOfRange - startOfRange;
}

CC3ActionRangeLimit* CC3ActionRangeLimit::actionWithAction( CCActionInterval* action, GLfloat startOfRange, GLfloat endOfRange )
{
	CC3ActionRangeLimit* pAction = new CC3ActionRangeLimit;
	pAction->initWithAction( action, startOfRange, endOfRange );
	pAction->autorelease();

	return pAction;
}

void CC3ActionRangeLimit::update( float t )
{
	getInnerAction()->update( m_rangeStart + (m_rangeSpan * t) ); 
}

CCActionInterval* CC3ActionRangeLimit::reverse()
{
	return actionWithAction( getInnerAction(), m_rangeStart + m_rangeSpan, m_rangeStart );
}

CCObject* CC3ActionRangeLimit::copyWithZone( CCZone* zone )
{
	CC3ActionRangeLimit* pAction = new CC3ActionRangeLimit;
	pAction->initWithAction( getInnerAction(), m_rangeStart, (m_rangeStart + m_rangeSpan) );
	
	return pAction;
}

CC3ActionRemove* CC3ActionRemove::create()
{
	CC3ActionRemove* pAction = new CC3ActionRemove;
	pAction->autorelease();

	return pAction;
}

void CC3ActionRemove::update( float t )
{
	// getTargetNode()->remove(); 
}


void CC3ActionCCNodeSizeTo::initWithDuration( float dur, const CCSize& endSize )
{
	super::initWithDuration( dur );
	endSize_ = endSize;
}

CC3ActionCCNodeSizeTo* CC3ActionCCNodeSizeTo::actionWithDuration( float dur, const CCSize& endSize )
{
	CC3ActionCCNodeSizeTo* pAction = new CC3ActionCCNodeSizeTo;
	pAction->initWithDuration( dur, endSize );
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionCCNodeSizeTo::copyWithZone( CCZone* zone )
{
	CC3ActionCCNodeSizeTo* pAction = new CC3ActionCCNodeSizeTo;
	pAction->initWithDuration( getDuration(), endSize_);

	return pAction;
}

CC3ActionInterval* CC3ActionCCNodeSizeTo::reverse()
{ 
	return CC3ActionCCNodeSizeTo::actionWithDuration( getDuration(), endSize_); 
}

void CC3ActionCCNodeSizeTo::startWithTarget( CCNode* aTarget )
{
	//super::startWithTarget( aTarget );
	startSize_ = aTarget->getContentSize();
	sizeChange_ = CCSizeMake(endSize_.width - startSize_.width, endSize_.height - startSize_.height);
}

void CC3ActionCCNodeSizeTo::update( float t )
{
	CCNode* tNode = (CCNode*)getTarget();
	tNode->setContentSize( CCSizeMake(startSize_.width + (sizeChange_.width * t),
								   startSize_.height + (sizeChange_.height * t)) );
}


//
// RepeatForever
//
CC3RepeatForever::~CC3RepeatForever()
{
	CC_SAFE_RELEASE(m_pInnerAction);
}

CC3RepeatForever *CC3RepeatForever::create(CC3ActionInterval *pAction)
{
	CC3RepeatForever *pRet = new CC3RepeatForever();
	if (pRet && pRet->initWithAction(pAction))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool CC3RepeatForever::initWithAction(CC3ActionInterval *pAction)
{
	CCAssert(pAction != NULL, "");
	pAction->retain();
	m_pInnerAction = pAction;
	return true;
}
CCObject* CC3RepeatForever::copyWithZone(CCZone *pZone)
{
	CCZone* pNewZone = NULL;
	CC3RepeatForever* pRet = NULL;
	if(pZone && pZone->m_pCopyObject) //in case of being called at sub class
	{
		pRet = (CC3RepeatForever*)(pZone->m_pCopyObject);
	}
	else
	{
		pRet = new CC3RepeatForever();
		pZone = pNewZone = new CCZone(pRet);
	}
	CC3ActionInterval::copyWithZone(pZone);
	// win32 : use the m_pOther's copy object.
	pRet->initWithAction((CC3ActionInterval*)(m_pInnerAction->copy()->autorelease())); 
	CC_SAFE_DELETE(pNewZone);
	return pRet;
}

void CC3RepeatForever::startWithTarget(CC3Node* pTarget)
{
	CC3ActionInterval::startWithTarget(pTarget);
	m_pInnerAction->startWithTarget(pTarget);
}

void CC3RepeatForever::step(float dt)
{
	m_pInnerAction->step(dt);
	if (m_pInnerAction->isDone())
	{
		float diff = m_pInnerAction->getElapsed() - m_pInnerAction->getDuration();
		m_pInnerAction->startWithTarget(m_pTargetCC3Node);
		// to prevent jerk. issue #390, 1247
		m_pInnerAction->step(0.0f);
		m_pInnerAction->step(diff);
	}
}

bool CC3RepeatForever::isDone()
{
	return false;
}

CC3ActionInterval *CC3RepeatForever::reverse()
{
	return NULL;
//	return (CC3ActionInterval*)(CC3RepeatForever::create(m_pInnerAction->reverse()));
}

CC3ActionSequence::~CC3ActionSequence()
{
	CC_SAFE_RELEASE(m_pActions[0]);
	CC_SAFE_RELEASE(m_pActions[1]);
}

bool CC3ActionSequence::initWithTwoActions(CC3ActionInterval *pActionOne, CC3ActionInterval *pActionTwo)
{
	CCAssert(pActionOne != NULL, "");
	CCAssert(pActionTwo != NULL, "");

	float d = pActionOne->getDuration() + pActionTwo->getDuration();
	CC3ActionInterval::initWithDuration(d);

	m_pActions[0] = pActionOne;
	pActionOne->retain();

	m_pActions[1] = pActionTwo;
	pActionTwo->retain();

	return true;
}

CCObject* CC3ActionSequence::copyWithZone( CCZone* pZone )
{
	CCZone* pNewZone = NULL;
	CC3ActionSequence* pRet = NULL;
	if(pZone && pZone->m_pCopyObject) //in case of being called at sub class
	{
		pRet = (CC3ActionSequence*)(pZone->m_pCopyObject);
	}
	else
	{
		pRet = new CC3ActionSequence();
		pZone = pNewZone = new CCZone(pRet);
	}
	CC3ActionInterval::copyWithZone(pZone);
	// win32 : use the m_pOther's copy object.
	pRet->initWithTwoActions( m_pActions[0], m_pActions[1] );

	CC_SAFE_DELETE(pNewZone);
	return pRet;
}

void CC3ActionSequence::startWithTarget(CC3Node *pTarget)
{
	CC3ActionInterval::startWithTarget(pTarget);
	m_elapsed = 0.0f;
	m_bFirstTick = true;
}


void CC3ActionSequence::stop(void)
{
	// Issue #1305
	if( m_last != - 1)
	{
		m_pActions[m_last]->stop();
	}

	CC3ActionInterval::stop();
}

void CC3ActionSequence::update(float t)
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
			m_pActions[0]->startWithTarget(m_pTargetCC3Node);
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
		m_pActions[found]->startWithTarget(m_pTargetCC3Node);
	}

	m_pActions[found]->update(new_t);
	m_last = found;
}

CC3ActionInterval* CC3ActionSequence::reverse(void)
{
	return CC3ActionSequence::createWithTwoActions(m_pActions[1]->reverse(), m_pActions[0]->reverse());
}

CC3ActionSequence* CC3ActionSequence::createWithTwoActions(CC3ActionInterval *pActionOne, CC3ActionInterval *pActionTwo)
{
	CC3ActionSequence *pSequence = new CC3ActionSequence();
	pSequence->initWithTwoActions(pActionOne, pActionTwo);
	pSequence->autorelease();

	return pSequence;
}


CC3ActionSpawn* CC3ActionSpawn::create(CC3ActionInterval *pAction1, ...)
{
	va_list params;
	va_start(params, pAction1);

	CC3ActionSpawn *pRet = CC3ActionSpawn::createWithVariableList(pAction1, params);

	va_end(params);

	return pRet;
}

CC3ActionSpawn* CC3ActionSpawn::createWithVariableList(CC3ActionInterval *pAction1, va_list args)
{
	CC3ActionInterval *pNow;
	CC3ActionInterval *pPrev = pAction1;
	bool bOneAction = true;

	while (pAction1)
	{
		pNow = va_arg(args, CC3ActionInterval*);
		if (pNow)
		{
			pPrev = createWithTwoActions(pPrev, pNow);
			bOneAction = false;
		}
		else
		{
			// If only one action is added to CC3ActionSpawn, make up a CC3ActionSpawn by adding a simplest finite time action.
			if (bOneAction)
			{
				pPrev = createWithTwoActions(pPrev, ExtraAction3D::create());
			}
			break;
		}
	}

	return ((CC3ActionSpawn*)pPrev);
}

CC3ActionSpawn* CC3ActionSpawn::create(CCArray *arrayOfActions)
{
	CC3ActionSpawn* pRet = NULL;
	do 
	{
		unsigned  int count = arrayOfActions->count();
		CC_BREAK_IF(count == 0);
		CC3ActionInterval* prev = (CC3ActionInterval*)arrayOfActions->objectAtIndex(0);
		if (count > 1)
		{
			for (unsigned int i = 1; i < arrayOfActions->count(); ++i)
			{
				prev = createWithTwoActions(prev, (CC3ActionInterval*)arrayOfActions->objectAtIndex(i));
			}
		}
		else
		{
			// If only one action is added to CC3ActionSpawn, make up a CC3ActionSpawn by adding a simplest finite time action.
			prev = createWithTwoActions(prev, ExtraAction3D::create());
		}
		pRet = (CC3ActionSpawn*)prev;
	}while (0);

	return pRet;
}

CC3ActionSpawn* CC3ActionSpawn::createWithTwoActions(CC3ActionInterval *pAction1, CC3ActionInterval *pAction2)
{
	CC3ActionSpawn *pSpawn = new CC3ActionSpawn();
	pSpawn->initWithTwoActions(pAction1, pAction2);
	pSpawn->autorelease();

	return pSpawn;
}

bool CC3ActionSpawn:: initWithTwoActions(CC3ActionInterval *pAction1, CC3ActionInterval *pAction2)
{
	CCAssert(pAction1 != NULL, "");
	CCAssert(pAction2 != NULL, "");

	bool bRet = false;

	float d1 = pAction1->getDuration();
	float d2 = pAction2->getDuration();

	if (true)
	{
		CC3ActionInterval::initWithDuration(MAX(d1, d2));
		m_pOne = pAction1;
		m_pTwo = pAction2;

		if (d1 > d2)
		{
			m_pTwo = CC3ActionSequence::createWithTwoActions(pAction2, CC3ActionDelayTime::create(d1 - d2));
		} 
		else if (d1 < d2)
		{
			m_pOne = CC3ActionSequence::createWithTwoActions(pAction1, CC3ActionDelayTime::create(d2 - d1));
		}

		m_pOne->retain();
		m_pTwo->retain();

		bRet = true;
	}


	return bRet;
}

CCObject* CC3ActionSpawn::copyWithZone(CCZone *pZone)
{
	CCZone* pNewZone = NULL;
	CC3ActionSpawn* pCopy = NULL;

	if(pZone && pZone->m_pCopyObject) 
	{
		//in case of being called at sub class
		pCopy = (CC3ActionSpawn*)(pZone->m_pCopyObject);
	}
	else
	{
		pCopy = new CC3ActionSpawn();
		pZone = pNewZone = new CCZone(pCopy);
	}

	CC3ActionInterval::copyWithZone(pZone);

	pCopy->initWithTwoActions((CC3ActionInterval*)(m_pOne->copy()->autorelease()), 
		(CC3ActionInterval*)(m_pTwo->copy()->autorelease()));

	CC_SAFE_DELETE(pNewZone);
	return pCopy;
}

CC3ActionSpawn::~CC3ActionSpawn(void)
{
	CC_SAFE_RELEASE(m_pOne);
	CC_SAFE_RELEASE(m_pTwo);
}

void CC3ActionSpawn::startWithTarget(CC3Node *pTarget)
{
	CC3ActionInterval::startWithTarget(pTarget);
	m_pOne->startWithTarget(pTarget);
	m_pTwo->startWithTarget(pTarget);
}

void CC3ActionSpawn::stop(void)
{
	m_pOne->stop();
	m_pTwo->stop();
	CCActionInterval::stop();
}

void CC3ActionSpawn::update(float time)
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

CC3ActionInterval* CC3ActionSpawn::reverse(void)
{
	return CC3ActionSpawn::createWithTwoActions(m_pOne->reverse(), m_pTwo->reverse());
}

// delaytime

CC3ActionDelayTime* CC3ActionDelayTime::create(float d)
{
	CC3ActionDelayTime* pAction = new CC3ActionDelayTime();

	pAction->initWithDuration(d);
	pAction->autorelease();

	return pAction;
}

CCObject* CC3ActionDelayTime::copyWithZone(CCZone *pZone)
{
	CCZone* pNewZone = NULL;
	CC3ActionDelayTime* pCopy = NULL;
	if(pZone && pZone->m_pCopyObject) 
	{
		//in case of being called at sub class
		pCopy = (CC3ActionDelayTime*)(pZone->m_pCopyObject);
	}
	else
	{
		pCopy = new CC3ActionDelayTime();
		pZone = pNewZone = new CCZone(pCopy);
	}


	CC3ActionInterval::copyWithZone(pZone);

	CC_SAFE_DELETE(pNewZone);

	return pCopy;
}

void CC3ActionDelayTime::update(float time)
{
	CC_UNUSED_PARAM(time);
	return;
}

CC3ActionInterval* CC3ActionDelayTime::reverse(void)
{
	return CC3ActionDelayTime::create(m_fDuration);
}


//
// BezierBy
//


static inline float bezierat( float a, float b, float c, float d, float t )
{
	return (powf(1-t,3) * a + 
		3*t*(powf(1-t,2))*b + 
		3*powf(t,2)*(1-t)*c +
		powf(t,3)*d );
}

CC3ActionBezierBy* CC3ActionBezierBy::create(float t, const ccBezier3DConfig& c)
{
	CC3ActionBezierBy *pBezierBy = new CC3ActionBezierBy();
	pBezierBy->initWithDuration(t, c);
	pBezierBy->autorelease();

	return pBezierBy;
}

bool CC3ActionBezierBy::initWithDuration(float t, const ccBezier3DConfig& c)
{
	if (CCActionInterval::initWithDuration(t))
	{
		m_sConfig = c;
		return true;
	}

	return false;
}

void CC3ActionBezierBy::startWithTarget(CC3Node *pTarget)
{
	CC3ActionInterval::startWithTarget(pTarget);
	m_previousPosition = m_startPosition = pTarget->getLocation();
}

CCObject* CC3ActionBezierBy::copyWithZone(CCZone *pZone)
{
	CCZone* pNewZone = NULL;
	CC3ActionBezierBy* pCopy = NULL;
	if(pZone && pZone->m_pCopyObject) 
	{
		//in case of being called at sub class
		pCopy = (CC3ActionBezierBy*)(pZone->m_pCopyObject);
	}
	else
	{
		pCopy = new CC3ActionBezierBy();
		pZone = pNewZone = new CCZone(pCopy);
	}

	CCActionInterval::copyWithZone(pZone);

	pCopy->initWithDuration(m_fDuration, m_sConfig);

	CC_SAFE_DELETE(pNewZone);
	return pCopy;
}

void CC3ActionBezierBy::update(float time)
{
	if (m_pTarget)
	{
		float xa = 0;
		float xb = m_sConfig.controlPoint_1.x;
		float xc = m_sConfig.controlPoint_2.x;
		float xd = m_sConfig.endPosition.x;

		float ya = 0;
		float yb = m_sConfig.controlPoint_1.y;
		float yc = m_sConfig.controlPoint_2.y;
		float yd = m_sConfig.endPosition.y;

		float za = 0;
		float zb = m_sConfig.controlPoint_1.z;
		float zc = m_sConfig.controlPoint_2.z;
		float zd = m_sConfig.endPosition.z;

		float x = bezierat(xa, xb, xc, xd, time);
		float y = bezierat(ya, yb, yc, yd, time);
		float z = bezierat(za, zb, zc, zd, time);


#if CC_ENABLE_STACKABLE_ACTIONS
		CC3Vector currentPos = m_pTargetCC3Node->getLocation();
		CC3Vector diff = currentPos - m_previousPosition;
		m_startPosition = m_startPosition +  diff;

		CC3Vector newPos = m_startPosition +  cc3v(x,y,z);
		m_pTargetCC3Node->setLocation(newPos);

		m_previousPosition = newPos;
#else
		m_pTarget->setPosition(ccpAdd( m_startPosition, ccp(x,y)));
#endif // !CC_ENABLE_STACKABLE_ACTIONS
	}
}

CC3ActionInterval* CC3ActionBezierBy::reverse(void)
{
	ccBezier3DConfig r;

	r.endPosition = -m_sConfig.endPosition;
	r.controlPoint_1 = m_sConfig.controlPoint_2 - m_sConfig.endPosition;
	r.controlPoint_2 = m_sConfig.controlPoint_1 -  m_sConfig.endPosition;

	CC3ActionBezierBy *pAction = CC3ActionBezierBy::create(m_fDuration, r);
	return pAction;
}

//
// BezierTo
//

CC3ActionBezierTo* CC3ActionBezierTo::create(float t, const ccBezier3DConfig& c)
{
	CC3ActionBezierTo *pBezierTo = new CC3ActionBezierTo();
	pBezierTo->initWithDuration(t, c);
	pBezierTo->autorelease();

	return pBezierTo;
}

bool CC3ActionBezierTo::initWithDuration(float t, const ccBezier3DConfig &c)
{
	bool bRet = false;

	if (CCActionInterval::initWithDuration(t))
	{
		m_sToConfig = c;
	}

	return bRet;
}

CCObject* CC3ActionBezierTo::copyWithZone(CCZone *pZone)
{
	CCZone* pNewZone = NULL;
	CC3ActionBezierBy* pCopy = NULL;
	if(pZone && pZone->m_pCopyObject) 
	{
		//in case of being called at sub class
		pCopy = (CC3ActionBezierTo*)(pZone->m_pCopyObject);
	}
	else
	{
		pCopy = new CC3ActionBezierTo();
		pZone = pNewZone = new CCZone(pCopy);
	}

	CC3ActionBezierBy::copyWithZone(pZone);

	pCopy->initWithDuration(m_fDuration, m_sConfig);

	CC_SAFE_DELETE(pNewZone);
	return pCopy;
}

void CC3ActionBezierTo::startWithTarget(CC3Node *pTarget)
{
	CC3ActionBezierBy::startWithTarget(pTarget);
	m_sConfig.controlPoint_1 = m_sToConfig.controlPoint_1 - m_startPosition;
	m_sConfig.controlPoint_2 = m_sToConfig.controlPoint_2 - m_startPosition;
	m_sConfig.endPosition = m_sToConfig.endPosition-  m_startPosition;
}


NS_COCOS3D_END
