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
/**
 * A macro that invokes the logIntersection:with: method if the LOGGING_ENABLED
 * compiler build setting is defined and set to 1.
 *
 * If the compiler build setting is not defined, or is set to 0, this macro is an
 * empty string, and effectively does not invoke the logIntersection:with: method.
 *
 * This macro allows code that is not conditionally compiled with the LOGGING_ENABLED
 * to include invoke the logIntersection:with: method when the conditionally compiled
 * code is available.
 */
#if LOGGING_ENABLED
#	define CC3LogBVIntersection(BV, I) logIntersection( (I), (BV) )
#else
#	define CC3LogBVIntersection(BV, I)
#endif

CC3BoundingVolume::CC3BoundingVolume()
{
	_isDirty = false;
}

CC3BoundingVolume::~CC3BoundingVolume()
{

}

CC3Plane* CC3BoundingVolume::getPlanes()
{ 
	return NULL; 
}

GLuint CC3BoundingVolume::getPlaneCount()
{ 
	return 0; 
}

CC3Vector* CC3BoundingVolume::getVertices()
{ 
	return NULL;
}

GLuint CC3BoundingVolume::getVertexCount()
{ 
	return 0; 
}

bool CC3BoundingVolume::init()
{
	GLuint pCnt = getPlaneCount();
	CC3Plane* pArray = getPlanes();
	for (GLuint i = 0; i < pCnt; i++) 
		pArray[i] = kCC3PlaneZero;

	GLuint vCnt = getVertexCount();
	CC3Vector* vArray = getVertices();
	for (GLuint i = 0; i < vCnt; i++) 
		vArray[i] = CC3Vector::kCC3VectorZero;

	_isDirty = true;
	_shouldIgnoreRayIntersection = false;
	setShouldLogIntersections( false );			// Use setter
	setShouldLogIntersectionMisses( false );	// Use setter

	return true;
}

CC3BoundingVolume* CC3BoundingVolume::boundingVolume()
{ 
	CC3BoundingVolume* pVolume = new CC3BoundingVolume;
	pVolume->init();
	pVolume->autorelease();
	return pVolume;
}

void CC3BoundingVolume::populateFrom( CC3BoundingVolume* another )
{
	_isDirty = another->isDirty();
	_shouldIgnoreRayIntersection = another->shouldIgnoreRayIntersection();
	setShouldLogIntersections( another->shouldLogIntersections() );			// Use setter
	setShouldLogIntersectionMisses( another->shouldLogIntersectionMisses() );	// Use setter

	GLuint pCnt = getPlaneCount();
	CC3Plane* pArray = getPlanes();
	CC3Plane* otherPlanes = another->getPlanes();
	for (GLuint i = 0; i < pCnt; i++) 
		pArray[i] = otherPlanes[i];
	
	GLuint vCnt = getVertexCount();
	CC3Vector* vArray = getVertices();
	CC3Vector* otherVertices = another->getVertices();
	for (GLuint i = 0; i < vCnt; i++) 
		vArray[i] = otherVertices[i];
}

 CCObject* CC3BoundingVolume::copyWithZone( CCZone* pZone )
 {
	CC3BoundingVolume* aCopy = new CC3BoundingVolume;
	aCopy->init();
	aCopy->populateFrom( this );
	return aCopy;
}

std::string CC3BoundingVolume::fullDescription()
{
	std::string description = "CC3BoundingVolume";
	appendPlanesTo( description );
	appendVerticesTo( description );

	return description;
}

void CC3BoundingVolume::appendPlanesTo( std::string& desc )
{
	GLuint pCnt = getPlaneCount();
	CC3Plane* pArray = getPlanes();
	for (GLuint pIdx = 0; pIdx < pCnt; pIdx++)
	{
		std::string sThis = CC3String::stringWithFormat( (char*)"\n\tplane: %s", stringFromCC3Plane( pArray[pIdx] ).c_str() );
		desc += sThis;
	}
}

void CC3BoundingVolume::appendVerticesTo( std::string& desc )
{
	GLuint vCnt = getVertexCount();
	CC3Vector* vArray = getVertices();
	for (GLuint vIdx = 0; vIdx < vCnt; vIdx++)
	{
		std::string sThis = CC3String::stringWithFormat( (char*)"\n\tvertex: %s", vArray[vIdx].stringfy().c_str() );
		desc += sThis;
	}
}


bool CC3BoundingVolume::isDirty()
{
	return _isDirty; 
}

void CC3BoundingVolume::markDirty()
{ 
	_isDirty = true;
}

void CC3BoundingVolume::updateIfNeeded()
{
	if (_isDirty) 
	{
		buildVolume();
		buildPlanes();
		_isDirty = false;
	}
}

/**
 * Builds the bounding volume.
 *
 * This default template method implementation does nothing. Subclasses will override.
 * 
 * This method is invoked automatically when this bounding volume requires rebuilding.
 */
void CC3BoundingVolume::buildVolume() {}

/** 
 * If this bounding volume is described in terms of a hull of planes,
 * builds those planes.
 *
 * This default template method implementation does nothing. Subclasses will override.
 * 
 * This method is invoked automatically when this bounding volume is rebuilt.
 */
void CC3BoundingVolume::buildPlanes() {}

/**
 * Double-dispatches to the other bounding volume as a convex hull using
 * using the planes of this bounding volume.
 */
bool CC3BoundingVolume::doesIntersect( CC3BoundingVolume* aBoundingVolume )
{
	CCAssert(getPlanes() != NULL, "%CC3BoundingVolume does not use planes. You must add planes or override method doesIntersect:");
	bool intersects = aBoundingVolume->doesIntersectConvexHullOf( getPlaneCount(), getPlanes(), this );
	CC3LogBVIntersection(aBoundingVolume, intersects);
	return intersects;
}

bool CC3BoundingVolume::doesIntersectLocation( const CC3Vector& aLocation )
{
	CCAssert(getPlanes() != NULL, "CC3BoundingVolume does not use planes. You must add planes or override method doesIntersectLocation:");
	GLuint pCnt = getPlaneCount();
	CC3Plane* pArray = getPlanes();
	for (GLuint pIdx = 0; pIdx < pCnt; pIdx++) 
	{
		if ( CC3VectorIsInFrontOfPlane(aLocation, pArray[pIdx]) ) 
			return false;
	}

	return true;
}

/**
 * Returns whether the location where the specified ray punctures the plane at the
 * specified index, is behind all the other planes. This indicates that the puncture
 * location is behind all of the planes, and hence is inside this bounding volume.
 */
bool CC3BoundingVolume::isRayBehindAllOtherPlanesAtPunctureOfPlane( const CC3Ray& aRay, GLuint planeIndex )
{
	CC3Plane* pArray = getPlanes();
	CC3Vector4 pLoc4 = CC3RayIntersectionWithPlane(aRay, pArray[planeIndex]);

	// If ray is pointed away from, or is parallel to the plane, it won't puncture it.
	if ( pLoc4.w < 0.0f || pLoc4.isNull() ) 
		return false;

	CC3Vector punctureLoc = pLoc4.cc3Vector();
	GLuint pCnt = getPlaneCount();
	for (GLuint pIdx = 0; pIdx < pCnt; pIdx++) 
	{
		if ( (pIdx != planeIndex) &&
			CC3VectorIsInFrontOfPlane(punctureLoc, pArray[pIdx]) ) 
			return false;
	}

	return true;
}

/**
 * Find puncture location of ray on each plane in turn. If any of those puncture locations
 * is behind all of the other planes, then the ray intersects this bounding volume.
 */
bool CC3BoundingVolume::doesIntersectRay( const CC3Ray& aRay )
{
	if (_shouldIgnoreRayIntersection) 
		return false;
	// MARK_TRACE_HERE
	//CCAssert(getPlanes()!=NULL, "CC3BoundingVolume does not use planes. You must add planes or override method doesIntersectRay:");
	GLuint pCnt = getPlaneCount();
	for (GLuint pIdx = 0; pIdx < pCnt; pIdx++) 
	{
		if ( isRayBehindAllOtherPlanesAtPunctureOfPlane( aRay, pIdx ) ) 
		{
			// MARK_TRACE_HERE
			//CCLOG( "Ray %s intersects %s", stringFromCC3Ray(aRay).c_str(), fullDescription().c_str());
			return true;
		}
	}

	return false;
}

bool CC3BoundingVolume::shouldIgnoreRayIntersection()
{
	return _shouldIgnoreRayIntersection;
}

void CC3BoundingVolume::setShouldIgnoreRayIntersection( bool should )
{
	_shouldIgnoreRayIntersection = should;
}

bool CC3BoundingVolume::isInFrontOfPlane( const CC3Plane& aPlane )
{
	return areAllVerticesInFrontOf( aPlane );
}

bool CC3BoundingVolume::doesIntersectSphere( const CC3Sphere& aSphere )
{
	return doesIntersectSphere( aSphere, NULL );
}

bool CC3BoundingVolume::doesIntersectSphere( const CC3Sphere& aSphere, CC3BoundingVolume* otherBoundingVolume )
{
	CCAssert(getPlanes(), "CC3BoundingVolume does not use planes. You must add planes or override method doesIntersectSphere:from:");
	GLuint pCnt = getPlaneCount();
	CC3Plane* pArray = getPlanes();
	for (GLuint pIdx = 0; pIdx < pCnt; pIdx++) {
		GLfloat dist = CC3DistanceFromPlane(aSphere.center, pArray[pIdx]);
		if (dist > aSphere.radius) {
			/*CCLOG("Sphere %s from %s is in front of plane %s and does not intersect %s",
						  stringFromCC3Spere(aSphere).c_str(), otherBoundingVolume->fullDescription().c_str(),
						  stringFromCC3Plane(pArray[pIdx]).c_str(), fullDescription().c_str());*/
			return false;
		}
	}
	/*CCLOG("Sphere %@ from %@ intersects %@", NSStringFromCC3Spere(aSphere), otherBoundingVolume, self);*/
	return true;
}

bool CC3BoundingVolume::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes )
{
	return doesIntersectConvexHullOf( numOtherPlanes, otherPlanes, NULL );
}

bool CC3BoundingVolume::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes, CC3BoundingVolume* otherBoundingVolume )
{
	// This test attempts to reject the intersection in stages, first by testing
	// the vertices of this BV against the specified planes of the other BV, then,
	// if the other BV has been specified, it is tested against the planes of this
	// BV. If neither test rejects the intersection, then we assume that the
	// intersection has occurred.
	
	// Reject if all vertices of this are in front of one of the other BV's planes
	if ( areAllVerticesInFrontOfOneOf( numOtherPlanes, otherPlanes ) ) 
		return false;
	
	// If not, then if the other BV exists, reject if it is outside this BV's planes.
	if (otherBoundingVolume) 
		return otherBoundingVolume->doesIntersectConvexHullOf( getPlaneCount(), getPlanes() );
	
	return true;		// Neither test rejected the intersection, so pass it.
}

bool CC3BoundingVolume::areAllVerticesInFrontOfOneOf( GLuint numPlanes, CC3Plane* planes )
{
	for (GLuint pIdx = 0; pIdx < numPlanes; pIdx++) 
	{
		if( areAllVerticesInFrontOf( planes[pIdx] ) ) 
			return true;
	}

	return false;
}

bool CC3BoundingVolume::areAllVerticesInFrontOf( const CC3Plane& plane )
{
	GLuint vCnt = getVertexCount();
	if (vCnt == 0) return false;

	CC3Vector* vArray = getVertices();
	for (GLuint vIdx = 0; vIdx < vCnt; vIdx++) 
	{
		/*LogTrace(@"Location %@ from %@ is %@ plane %@",
					  NSStringFromCC3Vector(vArray[vIdx]), self,
					  ((CC3VectorIsInFrontOfPlane(vArray[vIdx], plane)) ? @"in front of" : @"behind"),
					  NSStringFromCC3Plane(plane));*/
		if ( !CC3VectorIsInFrontOfPlane(vArray[vIdx], plane) ) 
			return false;
	}
	/*LogTrace(@"%@ all %i vertices are in front of plane %@",
	self, vCnt, NSStringFromCC3Plane(plane));*/
	return true;
}


CC3Plane CC3BoundingVolume::buildPlaneFromNormal( const CC3Vector& normal, const CC3Face& face, const CC3Vector& orientationAxis )
{
	CC3Plane p;
	
	// First, assume the mesh is a box. Try making plane from the normal and one location.
	// Will fail if normal is zero.
	p = CC3PlaneFromNormalAndLocation(normal, face.vertices[0]);
	if ( !CC3PlaneIsZero(p) ) return p;
	
	// The mesh is no more than a plane.
	// Next, try making plane from the three locations of the face.
	// Will fail if two are co-linear,
	p = CC3FacePlane(face);
	if ( !CC3PlaneIsZero(p) ) return p;
	
	// The mesh is no more than a line.
	// Next, try making the plane from the line, using the orientationAxis to provide a
	// third vertex by adding the orientation axis to one of the vertices on the line.
	CC3Vector v3 = face.vertices[0].add( orientationAxis );
	p = CC3PlaneFromLocations(face.vertices[1], face.vertices[0], v3);
	if ( !CC3PlaneIsZero(p) ) return p;
	
	// Try the other possible line.
	p = CC3PlaneFromLocations(face.vertices[2], face.vertices[0], v3);
	if ( !CC3PlaneIsZero(p) ) return p;
	
	// The mesh is just a single location.
	// Finally, use the orienationAxis as the plane's normal.
	return CC3PlaneFromNormalAndLocation(orientationAxis, face.vertices[0]);
}

CC3Vector CC3BoundingVolume::getGlobalLocationOfGlobalRayIntesection( const CC3Ray& aRay )
{
	CCAssert(false, "% CC3BoundingVolume does not yet implement globalLocationOfGlobalRayIntesection:. An implementation needs to be added.");
	return CC3Vector::kCC3VectorNull;
}

bool CC3BoundingVolume::shouldLogIntersections()
{ 
	return _shouldLogIntersections; 
}

void CC3BoundingVolume::setShouldLogIntersections( bool shouldLog )
{ 
	_shouldLogIntersections = shouldLog; 
}

bool CC3BoundingVolume::shouldLogIntersectionMisses()
{ 
	return _shouldLogIntersectionMisses; 
}

void CC3BoundingVolume::setShouldLogIntersectionMisses( bool shouldLog )
{ 
	_shouldLogIntersectionMisses = shouldLog; 
}

/**
 * If the shouldLogIntersections or shouldLogIntersectionMisses property is set to YES
 * in both this bounding volume and the specified bounding volume, a message is logged.
 *
 * You can use the CC3LogBVIntersection macro function to invoke this method in a way that
 * will be removed from the code when logging is disabled.
 */
void CC3BoundingVolume::logIntersection( bool intersects, CC3BoundingVolume* aBoundingVolume )
{
	/*LogInfoIf(intersects && self.shouldLogIntersections && aBoundingVolume.shouldLogIntersections
			  , @"%@ intersects %@", self.fullDescription, aBoundingVolume.fullDescription);

	LogInfoIf(!intersects && self.shouldLogIntersectionMisses && aBoundingVolume.shouldLogIntersectionMisses,
			  @"%@ does not intersect %@", self.fullDescription, aBoundingVolume.fullDescription);*/
}

CC3NodeBoundingVolume::CC3NodeBoundingVolume()
{
	_node = NULL;
}

CC3NodeBoundingVolume::~CC3NodeBoundingVolume()
{
	_node = NULL;
}

CC3Node* CC3NodeBoundingVolume::getNode()
{ 
	return _node; 
}

void CC3NodeBoundingVolume::setNode( CC3Node* node )
{
	CCAssert( !_node || !node, "%CC3NodeBoundingVolume may have only one primary node. If you want to change the"
			  " primary node, first set this property to nil, then set the new node.");
	_node = node;			// weak reference

	// Update whether the BV should be built from the mesh
	setShouldBuildFromMesh( shouldBuildFromMesh() );
}

bool CC3NodeBoundingVolume::shouldBuildFromMesh()
{ 
	return _shouldBuildFromMesh; 
}

void CC3NodeBoundingVolume::setShouldBuildFromMesh( bool build )
{
#pragma _NOTE_TODO( "Bad behavior here!!!" )
	_shouldBuildFromMesh = build && ( (_node == NULL) || dynamic_cast<CC3MeshNode*>(_node) != NULL );
	if (_shouldBuildFromMesh)
		markDirty();
}

CC3Vector* CC3NodeBoundingVolume::getVertices()
{
	updateIfNeeded();
	return &_globalCenterOfGeometry;
}

GLuint CC3NodeBoundingVolume::getVertexCount() 
{ 
	return 1; 
}

CC3Vector CC3NodeBoundingVolume::getCenterOfGeometry()
{
	updateIfNeeded();
	return _centerOfGeometry;
}

CC3Vector CC3NodeBoundingVolume::getGlobalCenterOfGeometry()
{
	updateIfNeeded();
	return _globalCenterOfGeometry;
}

void CC3NodeBoundingVolume::setCenterOfGeometry( const CC3Vector& aLocation )
{
	_centerOfGeometry = aLocation;
	_isDirty = false;
	_shouldBuildFromMesh = false;
	markTransformDirty();
}

/**
 * Returns the vertex locations of the CC3MeshNode holding this bounding volume.
 * If the node is not a CC3MeshNode, an assertion error is raised.
 */
CC3VertexLocations* CC3NodeBoundingVolume::getVertexLocations()
{
#pragma _NOTE_TODO( "class RTTI mesh node" )
	/*CCAssert(_node->getNodeType() == KCC3MeshNode, "%CC3NodeBoundingVolume can only be assigned to a CC3MeshNode instance.");*/

	CC3Mesh* pMesh = ((CC3MeshNode*)_node)->getMesh();
	if ( pMesh )
		return pMesh->getVertexLocations();

	return NULL;
}

bool CC3NodeBoundingVolume::init()
{
	if ( CC3BoundingVolume::init() )
	{
		_node = NULL;
		_shouldBuildFromMesh = true;
		_centerOfGeometry = CC3Vector::kCC3VectorZero;
		_globalCenterOfGeometry = CC3Vector::kCC3VectorZero;
		_shouldMaximize = false;
		_isTransformDirty = true;
		_shouldDraw = false;
	}
	return true;
}

void CC3NodeBoundingVolume::populateFrom( CC3NodeBoundingVolume* another )
{
	super::populateFrom( another );

	// Node property is not copied and must be set externally,
	// because a node can only have one bounding volume.

	_shouldBuildFromMesh = another->shouldBuildFromMesh();
	_centerOfGeometry = another->getCenterOfGeometry();
	_globalCenterOfGeometry = another->getGlobalCenterOfGeometry();
	_shouldMaximize = another->shouldMaximize();
	_isTransformDirty = another->isTransformDirty();
	_shouldDraw = another->shouldDraw();
}

CCObject* CC3NodeBoundingVolume::copyWithZone( CCZone* pZone )
{
	CC3NodeBoundingVolume* pVal = new CC3NodeBoundingVolume;
	pVal->init();
	pVal->populateFrom( this );

	return pVal;
}

void CC3NodeBoundingVolume::scaleBy( GLfloat scale )
{

}

bool CC3NodeBoundingVolume::isTransformDirty()
{ 
	return _isTransformDirty; 
}

void CC3NodeBoundingVolume::markTransformDirty()
{ 
	_isTransformDirty = true; 
}

/**
 * Builds the volume if needed, then transforms it with the node's globalTransformMatrix.
 * The transformation will occur if either the transform is marked as dirty, or the
 * bounding volume is being rebuilt.
 */
void CC3NodeBoundingVolume::updateIfNeeded()
{
	if (_isDirty) 
	{
		buildVolume();
		_isDirty = false;
		updateDisplayNode();
		markTransformDirty();
	}

	if (_node && _isTransformDirty) 
	{
		transformVolume();
		buildPlanes();
		_isTransformDirty = false;
	}
}

void CC3NodeBoundingVolume::transformVolume()
{
	_globalCenterOfGeometry = _centerOfGeometry.equals( CC3Vector::kCC3VectorZero )
								? _node->getGlobalLocation()
								: _node->getGlobalTransformMatrix()->transformLocation( _centerOfGeometry );
}

CC3Vector CC3NodeBoundingVolume::getLocationOfRayIntesection( const CC3Ray& localRay )
{
	CCAssert(false, "%CC3NodeBoundingVolume does not yet implement locationOfRayIntesection:. An implementation needs to be added.");
	return CC3Vector::kCC3VectorNull;
}

CC3Vector CC3NodeBoundingVolume::getGlobalLocationOfGlobalRayIntesection( const CC3Ray& aRay )
{
	if ( !_node || _shouldIgnoreRayIntersection ) 
		return CC3Vector::kCC3VectorNull;

	CC3Ray localRay = _node->getGlobalTransformMatrixInverted()->transformRay( aRay );
	CC3Vector puncture = getLocationOfRayIntesection( localRay );
	return puncture.isNull() ? puncture : _node->getGlobalTransformMatrix()->transformLocation( puncture );
}

/**
 * Template method that returns the suffix used to name the node used to display
 * this bounding volume. Different bounding volume types will use different suffixes.
 */
std::string CC3NodeBoundingVolume::displayNodeNameSuffix()
{
	CCAssert(false, "CC3NodeBoundingVolume has no unique display node suffix. You must override method displayNodeNameSuffix:");
	return "BV";
}

/** The name to use when creating or retrieving the wireframe child node of this node. */
std::string CC3NodeBoundingVolume::displayNodeName()
{
	return CC3String::stringWithFormat ( (char*)"%s-%s", _node->getName().c_str(), displayNodeNameSuffix().c_str() );
}

/**
 * Retrieves the display node that is displaying this bounding volume from this
 * bounding volume's node, and returns it, or returns nil if this bounding volume
 * is not currently being displayed.
 */
CC3BoundingVolumeDisplayNode* CC3NodeBoundingVolume::displayNode()
{
	return (CC3BoundingVolumeDisplayNode*)_node->getNodeNamed( displayNodeName().c_str() );
}

/** The color used to display the bounding volume. */
CCColorRef CC3NodeBoundingVolume::getDisplayNodeColor()
{ 
	return CCColorRefFromCCC4F(kCCC4FWhite); 
}

/** The opacity at which to display the bounding volume. */
CCOpacity CC3NodeBoundingVolume::getDisplayNodeOpacity()
{ 
	return (CCOpacity)(kCCOpacityFull * 0.25f); 
}	// 25% opacity

/**
 * Populates the display node to create the appropriate shape.
 * This abstract implementation does nothing. Subclasses will customize.
 */
void CC3NodeBoundingVolume::populateDisplayNode()
{

}

/**
 * If this bounding volume is being displayed, update the display mesh node.
 *
 * This default implementation repopulates the mesh node from scratch, which
 * may be expensive. Subclasses may override to something more efficient.
 */
void CC3NodeBoundingVolume::updateDisplayNode()
{ 
	if (_shouldDraw) 
		populateDisplayNode(); 
}

bool CC3NodeBoundingVolume::shouldDraw()
{ 
	return _shouldDraw; 
}

void CC3NodeBoundingVolume::setShouldDraw( bool shdDraw )
{
	_shouldDraw = shdDraw;
	
	// Fetch the display node.
	CC3BoundingVolumeDisplayNode* dn = displayNode();
	
	// If the display node exists, but should not, remove it
	if (dn && !_shouldDraw) 
		dn->remove();
	
	// If there is no display node, but there should be, add it by creating a
	// CC3BoundingVolumeDisplayNode of the correct shape from the properties of
	// this bounding volume, and add it as a child of this bounding volume's node.
	if(!dn && _shouldDraw) 
	{
		dn = CC3BoundingVolumeDisplayNode::nodeWithName( displayNodeName().c_str() );
		dn->setMaterial( CC3Material::shiny() );
		dn->setColor( getDisplayNodeColor() );
		dn->setOpacity( getDisplayNodeOpacity() );

		// Set drawing order and decal properties to minimize Z-fighting between the
		// bounding volume display and the node which the bounding volume surrounds.
		dn->setZOrder( _node->getZOrder() - 1 );
		dn->setDecalOffsetFactor( -5.0f );
		dn->setDecalOffsetUnits( -5.0f );

		dn->setShouldDisableDepthMask( true );	// Don't update depth mask, to allow later...
											// ..overlapping transparencies to all be drawn
		_node->addChild( dn );
		populateDisplayNode();			// Populate with the right shape
	}
}

void CC3NodeBoundingVolume::setShouldMaximize( bool should )
{
	_shouldMaximize = should;
}

bool CC3NodeBoundingVolume::shouldMaximize()
{
	return _shouldMaximize;
}

void CC3NodeCenterOfGeometryBoundingVolume::buildVolume()
{
	if ( !(_node && _shouldBuildFromMesh) ) 
		return;
	
	_centerOfGeometry = getVertexLocations()->getCenterOfGeometry();
}

/** Double-dispatches to the other bounding volume as a single point location. */
bool CC3NodeCenterOfGeometryBoundingVolume::doesIntersect( CC3BoundingVolume* aBoundingVolume )
{
	bool intersects = aBoundingVolume->doesIntersectLocation( getGlobalCenterOfGeometry() );
	CC3LogBVIntersection(aBoundingVolume, intersects);
	return intersects;
}

bool CC3NodeCenterOfGeometryBoundingVolume::doesIntersectLocation( const CC3Vector& aLocation )
{
	return getGlobalCenterOfGeometry().equals( aLocation );
}

bool CC3NodeCenterOfGeometryBoundingVolume::doesIntersectRay( const CC3Ray& aRay )
{
	if (_shouldIgnoreRayIntersection) 
		return false;

	return CC3IsLocationOnRay(getGlobalCenterOfGeometry(), aRay);
}

// Included to satisfy compiler because selector appears in interface for documentation purposes
bool CC3NodeCenterOfGeometryBoundingVolume::isInFrontOfPlane( const CC3Plane& aPlane )
{ 
	return CC3NodeBoundingVolume::isInFrontOfPlane( aPlane ); 
}

bool CC3NodeCenterOfGeometryBoundingVolume::doesIntersectSphere( const CC3Sphere& aSphere, CC3BoundingVolume* otherBoundingVolume )
{
	return CC3IsLocationWithinSphere(getGlobalCenterOfGeometry(), aSphere);
}

/**
 * Determines whether the globalCenterOfGeometry is outside any of the planes,
 * returns NO if that is the case.
 */
bool CC3NodeCenterOfGeometryBoundingVolume::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes, CC3BoundingVolume* otherBoundingVolume )
{
	CC3Vector gcog = getGlobalCenterOfGeometry();	// Retrieve as property to force update
	for (GLuint pIdx = 0; pIdx < numOtherPlanes; pIdx++) 
	{
		if ( CC3VectorIsInFrontOfPlane(gcog, otherPlanes[pIdx]) ) 
			return false;
	}

	return true;
}

CC3Vector CC3NodeCenterOfGeometryBoundingVolume::getLocationOfRayIntesection( const CC3Ray& localRay )
{
	if (_shouldIgnoreRayIntersection) 
		return CC3Vector::kCC3VectorNull;

	CC3Vector cog = getCenterOfGeometry();

	return ( CC3IsLocationOnRay(cog, localRay) ) ? cog : CC3Vector::kCC3VectorNull;
}

std::string CC3NodeCenterOfGeometryBoundingVolume::displayNodeNameSuffix()
{ 
	return "BV-CoG"; 
}

bool CC3NodeCenterOfGeometryBoundingVolume::shouldDraw()
{ 
	// No shape to draw
	return false; 
}			

// No shape to draw
void CC3NodeCenterOfGeometryBoundingVolume::setShouldDraw( bool shdDraw )
{

}	

CC3NodeSphericalBoundingVolume::CC3NodeSphericalBoundingVolume()
{
	_radius = 0.f;
	_globalRadius = 0.f;
}

CC3NodeSphericalBoundingVolume::~CC3NodeSphericalBoundingVolume()
{

}
/**
 * If building from the mesh, finds the sphere that currently encompasses all the vertices.
 * Then, if the boundary should be maximized, finds the sphere that is the union of that sphere,
 * and the sphere that previously encompassed all the vertices, otherwise, uses the new sphere.
 */
void CC3NodeSphericalBoundingVolume::buildVolume()
{
	if ( !(_node && _shouldBuildFromMesh) ) 
		return;
	
	CC3VertexLocations* vtxLocs = getVertexLocations();
	if ( vtxLocs )
	{
		CC3Vector newCOG = vtxLocs->getCenterOfGeometry();
		GLfloat newRadius = vtxLocs->getRadius() + _node->getBoundingVolumePadding();

		if (_shouldMaximize) 
		{
			CC3Sphere unionSphere = CC3SphereUnion(CC3SphereMake(newCOG, newRadius),
				CC3SphereMake(_centerOfGeometry, _radius));
			_centerOfGeometry = unionSphere.center;
			_radius = unionSphere.radius;
		} 
		else
		{
			_centerOfGeometry = newCOG;
			_radius = newRadius;
		}
	}
}

GLfloat CC3NodeSphericalBoundingVolume::getRadius()
{
	updateIfNeeded();
	return _radius;
}

void CC3NodeSphericalBoundingVolume::setRadius( GLfloat aRadius )
{
	_radius = aRadius;
	_isDirty = false;
	_shouldBuildFromMesh = false;
	markTransformDirty();
}

GLfloat CC3NodeSphericalBoundingVolume::getGlobalRadius()
{
	updateIfNeeded();
	return _globalRadius;
}

void CC3NodeSphericalBoundingVolume::scaleBy( GLfloat scale )
{
	CC3NodeBoundingVolume::scaleBy( scale );
	setRadius( getRadius() * scale );
}

CC3Sphere CC3NodeSphericalBoundingVolume::getSphere()
{ 
	return CC3SphereMake(getCenterOfGeometry(), getRadius());
}

CC3Sphere CC3NodeSphericalBoundingVolume::getGlobalSphere()
{ 
	return CC3SphereMake(getGlobalCenterOfGeometry(), getGlobalRadius()); 
}

void CC3NodeSphericalBoundingVolume::populateFrom( CC3NodeSphericalBoundingVolume* another )
{
	super::populateFrom( another );

	_radius = another->getRadius();
	_globalRadius = another->getGlobalRadius();
}

CCObject* CC3NodeSphericalBoundingVolume::copyWithZone( CCZone* pZone )
{
	CC3NodeSphericalBoundingVolume* pVal = new CC3NodeSphericalBoundingVolume;
	pVal->init();
	pVal->populateFrom( this );

	return pVal;
}

std::string CC3NodeSphericalBoundingVolume::fullDescription()
{
	return CC3String::stringWithFormat( (char*)"%CC3NodeSphericalBoundingVolume centered at: %s (globally: %s) with radius: %.3f (globally: %.3f)",
			getCenterOfGeometry().stringfy().c_str(),
			getGlobalCenterOfGeometry().stringfy().c_str(), getRadius(), getGlobalRadius() );
}

void CC3NodeSphericalBoundingVolume::transformVolume()
{
	super::transformVolume();

//	CC3_PUSH_NOSHADOW
	// Expand the radius by the global scale of the node. In case the node's global scale is not
	// uniform, use the largest of the three scale axes to ensure the scaled object is contained
	// within the sphere, and ensure that the radius is positive even if scale is negative.
	CC3Vector ngs = _node->getGlobalScale();
	_globalRadius = _radius * fabs(MAX(MAX(ngs.x, ngs.y), ngs.z));
//	CC3_POP_NOSHADOW
}

/** Double-dispatches to the other bounding volume as a sphere. */
bool CC3NodeSphericalBoundingVolume::doesIntersect( CC3BoundingVolume* aBoundingVolume )
{
	bool intersects = aBoundingVolume->doesIntersectSphere( getGlobalSphere(), this );
	CC3LogBVIntersection(aBoundingVolume, intersects);
	return intersects;
}

bool CC3NodeSphericalBoundingVolume::doesIntersectLocation( const CC3Vector& aLocation )
{
	return CC3IsLocationWithinSphere(aLocation, getGlobalSphere());
}

bool CC3NodeSphericalBoundingVolume::doesIntersectRay( const CC3Ray& aRay )
{
	if (_shouldIgnoreRayIntersection) 
		return false;

	return CC3DoesRayIntersectSphere(aRay, getGlobalSphere());
}

/**
 * Determines the distance from the globalCenterOfGeometry to the plane
 * (in terms of the normal of the plane), and return YES if that distance
 * is greater than the globalRadius, indicating the sphere is in front
 * of that plane.
 */
bool CC3NodeSphericalBoundingVolume::isInFrontOfPlane( const CC3Plane& aPlane )
{
	GLfloat dist = CC3DistanceFromPlane(getGlobalCenterOfGeometry(), aPlane);
	return (dist > getGlobalRadius());
}

bool CC3NodeSphericalBoundingVolume::doesIntersectSphere( const CC3Sphere& aSphere, CC3BoundingVolume* otherBoundingVolume )
{
	return CC3DoesSphereIntersectSphere(aSphere, getGlobalSphere());
}

/**
 * Determines whether the globalCenterOfGeometry is in front of any of the
 * specified planes, and if so, returns NO.
 */
bool CC3NodeSphericalBoundingVolume::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes, CC3BoundingVolume* otherBoundingVolume )
{
	for (GLuint pIdx = 0; pIdx < numOtherPlanes; pIdx++) 
	{
		if ( isInFrontOfPlane( otherPlanes[pIdx] ) ) 
			return false;
	}

	return true;
}

CC3Vector CC3NodeSphericalBoundingVolume::getLocationOfRayIntesection( const CC3Ray& localRay )
{
	if (_shouldIgnoreRayIntersection) 
		return CC3Vector::kCC3VectorNull;

	return CC3RayIntersectionWithSphere(localRay, getSphere());
}

std::string CC3NodeSphericalBoundingVolume::displayNodeNameSuffix()
{ 
	return "BV-Sphere"; 
}

CCColorRef CC3NodeSphericalBoundingVolume::getDisplayNodeColor() { return CCColorRefFromCCC4F(kCCC4FMagenta); }		// Magenta

// Magenta is faint...increase to 33% opacity
CCOpacity CC3NodeSphericalBoundingVolume::getDisplayNodeOpacity() { return (CCOpacity)(kCCOpacityFull * kCC3OneThird); }

void CC3NodeSphericalBoundingVolume::populateDisplayNode()
{
	CC3BoundingVolumeDisplayNode* dn = displayNode();
	if ( dn )
	{
		dn->populateAsSphereWithRadius( getRadius(), CC3TessellationMake(24, 24) );
		dn->doNotBufferVertexContent();
		dn->setLocation( getCenterOfGeometry() );
	}
}

// Don't delegate to initFromSphere: because this intializer must leave _shouldBuildFromMesh alone
bool CC3NodeSphericalBoundingVolume::init()
{
	if ( super::init() ) 
	{
		_radius = 0.0f;
		return true;
	}

	return false;
}

bool CC3NodeSphericalBoundingVolume::initFromSphere( const CC3Sphere& sphere )
{
	if ( super::init() ) 
	{
		_centerOfGeometry = sphere.center;
		_radius = sphere.radius;
		_shouldBuildFromMesh = false;		// We want a fixed volume

		return true;
	}

	return false;
}

CC3NodeSphericalBoundingVolume* CC3NodeSphericalBoundingVolume::boundingVolumeFromSphere( const CC3Sphere& sphere )
{
	CC3NodeSphericalBoundingVolume* pVolume = new CC3NodeSphericalBoundingVolume;
	pVolume->initFromSphere( sphere );
	pVolume->autorelease();

	return pVolume;
}

CC3NodeSphericalBoundingVolume* CC3NodeSphericalBoundingVolume::boundingVolume()
{
	CC3NodeSphericalBoundingVolume* pVolume = new CC3NodeSphericalBoundingVolume;
	pVolume->init();
	pVolume->autorelease();

	return pVolume;
}

CC3NodeBoxBoundingVolume::CC3NodeBoxBoundingVolume()
{

}

CC3NodeBoxBoundingVolume::~CC3NodeBoxBoundingVolume()
{

}

void CC3NodeBoxBoundingVolume::buildVolume()
{
	if ( !(_node && _shouldBuildFromMesh) ) 
		return;

	CC3Box newBB = ((CC3MeshNode*)getNode())->getLocalContentBoundingBox();	// Includes possible padding
	_boundingBox = _shouldMaximize ? CC3BoxUnion(newBB, _boundingBox) : newBB;
	_centerOfGeometry = CC3BoxCenter(_boundingBox);
}

CC3Box CC3NodeBoxBoundingVolume::getBoundingBox()
{
	updateIfNeeded();
	return _boundingBox;
}

void CC3NodeBoxBoundingVolume::setBoundingBox( const CC3Box& aBoundingBox )
{
	_boundingBox = aBoundingBox;
	_isDirty = false;
	_shouldBuildFromMesh = false;
	
	markTransformDirty();
}

void CC3NodeBoxBoundingVolume::scaleBy( GLfloat scale )
{
	super::scaleBy( scale );
	setBoundingBox( CC3BoxScaleUniform( getBoundingBox(), scale) );
}

CC3Plane* CC3NodeBoxBoundingVolume::getPlanes()
{
	updateIfNeeded();
	return _planes;
}

GLuint CC3NodeBoxBoundingVolume::getPlaneCount()
{ 
	return 6; 
}

CC3Vector* CC3NodeBoxBoundingVolume::getVertices()
{
	updateIfNeeded();
	return _vertices;
}

GLuint CC3NodeBoxBoundingVolume::getVertexCount()
{
	return 8; 
}

void CC3NodeBoxBoundingVolume::populateFrom( CC3NodeBoxBoundingVolume* another )
{
	super::populateFrom( another );

	_boundingBox = another->getBoundingBox();
}

CCObject* CC3NodeBoxBoundingVolume::copyWithZone( CCZone* pZone )
{
	CC3NodeBoxBoundingVolume* pVal = new CC3NodeBoxBoundingVolume;
	pVal->init();
	pVal->populateFrom( this );

	return pVal;
}

void CC3NodeBoxBoundingVolume::transformVolume()
{
	super::transformVolume();

	CC3Matrix* tMtx = _node->getGlobalTransformMatrix();

	// Get the corners of the local bounding box
	CC3Vector bbMin = _boundingBox.minimum;
	CC3Vector bbMax = _boundingBox.maximum;
	
	// Construct all 8 corner vertices of the local bounding box and transform each to global coordinates
	_vertices[0] = tMtx->transformLocation( cc3v(bbMin.x, bbMin.y, bbMin.z) );
	_vertices[1] = tMtx->transformLocation( cc3v(bbMin.x, bbMin.y, bbMax.z) );
	_vertices[2] = tMtx->transformLocation( cc3v(bbMin.x, bbMax.y, bbMin.z) );
	_vertices[3] = tMtx->transformLocation( cc3v(bbMin.x, bbMax.y, bbMax.z) );
	_vertices[4] = tMtx->transformLocation( cc3v(bbMax.x, bbMin.y, bbMin.z) );
	_vertices[5] = tMtx->transformLocation( cc3v(bbMax.x, bbMin.y, bbMax.z) );
	_vertices[6] = tMtx->transformLocation( cc3v(bbMax.x, bbMax.y, bbMin.z) );
	_vertices[7] = tMtx->transformLocation( cc3v(bbMax.x, bbMax.y, bbMax.z) );
}

/**
 * Constructs the six box face planes from normals and vertices.
 * The plane normals are the transformed face normals of the original box.
 * The vertices are the transformed min-max corners of the box.
 */
void CC3NodeBoxBoundingVolume::buildPlanes()
{
	CC3Vector normal;
	CC3Matrix* tMtx = _node->getGlobalTransformMatrix();
	CC3Vector bbMin = _vertices[0];
	CC3Vector bbMax = _vertices[7];
	
	// Front plane
	normal = tMtx->transformDirection( CC3Vector::kCC3VectorUnitZPositive ).normalize();
	_planes[0] = CC3PlaneFromNormalAndLocation(normal, bbMax);
	
	// Back plane
	normal = tMtx->transformDirection( CC3Vector::kCC3VectorUnitZNegative ).normalize();
	_planes[1] = CC3PlaneFromNormalAndLocation(normal, bbMin);
	
	// Right plane
	normal = tMtx->transformDirection( CC3Vector::kCC3VectorUnitXPositive ).normalize();
	_planes[2] = CC3PlaneFromNormalAndLocation(normal, bbMax);
	
	// Left plane
	normal = tMtx->transformDirection( CC3Vector::kCC3VectorUnitXNegative ).normalize();
	_planes[3] = CC3PlaneFromNormalAndLocation(normal, bbMin);
	
	// Top plane
	normal = tMtx->transformDirection( CC3Vector::kCC3VectorUnitYPositive ).normalize();
	_planes[4] = CC3PlaneFromNormalAndLocation(normal, bbMax);
	
	// Bottom plane
	normal = tMtx->transformDirection( CC3Vector::kCC3VectorUnitYNegative ).normalize();
	_planes[5] = CC3PlaneFromNormalAndLocation(normal, bbMin);
}

std::string CC3NodeBoxBoundingVolume::fullDescription()
{
	return "CC3NodeBoxBoundingVolume";
}

CC3Vector CC3NodeBoxBoundingVolume::getLocationOfRayIntesection( const CC3Ray& localRay )
{
	if (_shouldIgnoreRayIntersection) 
		return CC3Vector::kCC3VectorNull;

	return CC3RayIntersectionWithBox(localRay, getBoundingBox());
}

CCColorRef CC3NodeBoxBoundingVolume::getDisplayNodeColor()
{ 
	return CCColorRefFromCCC4F(kCCC4FCyan); 
}	// Cyan

// Cyan is heavy...reduce to 25% opacity
CCOpacity CC3NodeBoxBoundingVolume::getDisplayNodeOpacity()
{ 
	return (CCOpacity)(kCCOpacityFull * 0.25f); 
}

void CC3NodeBoxBoundingVolume::populateDisplayNode()
{
	CC3BoundingVolumeDisplayNode* dn = displayNode();
	if ( dn )
	{
		dn->populateAsSolidBox( getBoundingBox() );
		dn->doNotBufferVertexContent();
	}	
}

// Don't delegate to initFromBox: because this intializer must leave _shouldBuildFromMesh alone
bool  CC3NodeBoxBoundingVolume::init()
{
	if ( super::init() ) {
		_boundingBox = kCC3BoxZero;
		return true;
	}

	return false;
}

bool CC3NodeBoxBoundingVolume::initFromBox( const CC3Box& box )
{
	if ( super::init() )
	{
		_centerOfGeometry = CC3BoxCenter(box);
		_boundingBox = box;
		_shouldBuildFromMesh = false;		// We want a fixed volume
		return true;
	}

	return false;
}

CC3NodeBoxBoundingVolume* CC3NodeBoxBoundingVolume::boundingVolumeFromBox( const CC3Box& box )
{
	CC3NodeBoxBoundingVolume* pVolume = new CC3NodeBoxBoundingVolume;
	pVolume->initFromBox( box );
	pVolume->autorelease();

	return pVolume;
}

CC3NodeBoxBoundingVolume* CC3NodeBoxBoundingVolume::boundingVolume()
{
	CC3NodeBoxBoundingVolume* pVolume = new CC3NodeBoxBoundingVolume;
	pVolume->init();
	pVolume->autorelease();

	return pVolume;
}

CC3NodeTighteningBoundingVolumeSequence::CC3NodeTighteningBoundingVolumeSequence()
{

}

CC3NodeTighteningBoundingVolumeSequence::~CC3NodeTighteningBoundingVolumeSequence() 
{
	CC_SAFE_RELEASE( _boundingVolumes );
}

void CC3NodeTighteningBoundingVolumeSequence::setShouldMaximize( bool shouldMax )
{
	_shouldMaximize = shouldMax;

	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
			pVolume->setShouldMaximize( shouldMax );
	}
}

void CC3NodeTighteningBoundingVolumeSequence::setNode( CC3Node* aNode )
{
	super::setNode( aNode );
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
			pVolume->setNode( aNode );
	}
}

/** Overridden to keep the COG consistent for all BV's.  */
void CC3NodeTighteningBoundingVolumeSequence::setCenterOfGeometry( const CC3Vector& aLocation )
{
	super::setCenterOfGeometry( aLocation );

	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
			pVolume->setCenterOfGeometry( aLocation );
	}
}

void CC3NodeTighteningBoundingVolumeSequence::scaleBy( GLfloat scale )
{
	super::scaleBy( scale );

	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
			pVolume->scaleBy( scale );
	}
}

bool CC3NodeTighteningBoundingVolumeSequence::init()
{
	if ( super::init() ) 
	{
		_boundingVolumes = CCArray::create();	// retained
		_boundingVolumes->retain();
		return true;
	}
	return false;
}

void CC3NodeTighteningBoundingVolumeSequence::populateFrom( CC3NodeTighteningBoundingVolumeSequence* another )
{
	super::populateFrom( another );
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CCObject* pCopy = pObj->copy();
		pCopy->autorelease(); // retained through collection
		_boundingVolumes->addObject( pCopy );
	}
}

CCObject* CC3NodeTighteningBoundingVolumeSequence::copyWithZone( CCZone* pZone )
{
	CC3NodeTighteningBoundingVolumeSequence* pVal = new CC3NodeTighteningBoundingVolumeSequence;
	pVal->init();
	pVal->populateFrom( this );

	return pVal;
}

void CC3NodeTighteningBoundingVolumeSequence::addBoundingVolume( CC3NodeBoundingVolume* aBoundingVolume )
{
	_boundingVolumes->addObject( aBoundingVolume );
	aBoundingVolume->setNode( _node );
}

void CC3NodeTighteningBoundingVolumeSequence::markDirty()
{
	super::markDirty();

	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
			pVolume->markDirty();
	}
}

void CC3NodeTighteningBoundingVolumeSequence::markTransformDirty()
{
	super::markTransformDirty();

	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
			pVolume->markTransformDirty();
	}
}

/** Builds each contained bounding volume, if needed, and sets the local centerOfGeometry from the last one. */
void CC3NodeTighteningBoundingVolumeSequence::buildVolume()
{
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			pVolume->updateIfNeeded();
			_centerOfGeometry = pVolume->getCenterOfGeometry();
		}
	}
}

void CC3NodeTighteningBoundingVolumeSequence::transformVolume()
{
	super::transformVolume();
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			pVolume->transformVolume();
		}
	}
}

std::string CC3NodeTighteningBoundingVolumeSequence::fullDescription()
{
	return "CC3NodeTighteningBoundingVolumeSequence";
}

bool CC3NodeTighteningBoundingVolumeSequence::doesIntersect( CC3BoundingVolume* aBoundingVolume )
{
	bool intersects = true;
	
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			intersects = intersects && pVolume->doesIntersect( aBoundingVolume );
		}
	}

	CC3LogBVIntersection(aBoundingVolume, intersects);
	return intersects;
}

bool CC3NodeTighteningBoundingVolumeSequence::doesIntersectLocation( const CC3Vector& aLocation )
{
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			if ( !pVolume->doesIntersectLocation( aLocation ) )
				return false;
		}
	}

	return true;
}

bool CC3NodeTighteningBoundingVolumeSequence::doesIntersectRay( const CC3Ray& aRay )
{
	if (_shouldIgnoreRayIntersection) 
		return false;

	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			if ( !pVolume->doesIntersectRay( aRay ) )
				return false;
		}
	}

	return true;
}

bool CC3NodeTighteningBoundingVolumeSequence::isInFrontOfPlane( const CC3Plane& aPlane )
{
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			if ( pVolume->isInFrontOfPlane( aPlane ) )
				return true;
		}
	}

	return false;
}

bool CC3NodeTighteningBoundingVolumeSequence::doesIntersectSphere( const CC3Sphere& aSphere, CC3BoundingVolume* otherBoundingVolume )
{
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			if ( pVolume->doesIntersectSphere( aSphere, otherBoundingVolume ) )
				return false;
		}
	}

	return true;
}

bool CC3NodeTighteningBoundingVolumeSequence::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes, CC3BoundingVolume* otherBoundingVolume )
{
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			if ( pVolume->doesIntersectConvexHullOf( numOtherPlanes, otherPlanes, otherBoundingVolume ) )
				return false;
		}
	}

	return true;
}

/** Returns the location of the intersection on the tightest child BV. */
CC3Vector CC3NodeTighteningBoundingVolumeSequence::getLocationOfRayIntesection( const CC3Ray& localRay )
{
	if (_shouldIgnoreRayIntersection) 
		return CC3Vector::kCC3VectorNull;

	CC3NodeBoundingVolume* bv = (CC3NodeBoundingVolume*)_boundingVolumes->lastObject();
	return bv ? bv->getLocationOfRayIntesection( localRay ) : CC3Vector::kCC3VectorNull;
}

void CC3NodeTighteningBoundingVolumeSequence::setShouldDraw( bool shouldDraw )
{
	CCObject* pObj;
	CCARRAY_FOREACH( _boundingVolumes, pObj )
	{
		CC3NodeBoundingVolume* pVolume = (CC3NodeBoundingVolume*)pObj;
		if ( pVolume )
		{
			pVolume->setShouldDraw( shouldDraw );
		}
	}
}

CC3NodeSphereThenBoxBoundingVolume::CC3NodeSphereThenBoxBoundingVolume()
{

}

CC3NodeSphereThenBoxBoundingVolume::~CC3NodeSphereThenBoxBoundingVolume()
{
	_sphericalBoundingVolume->release();
	_boxBoundingVolume->release();
}

CC3NodeSphericalBoundingVolume* CC3NodeSphereThenBoxBoundingVolume::getSphericalBoundingVolume()
{
	return _sphericalBoundingVolume;
}

CC3NodeBoxBoundingVolume* CC3NodeSphereThenBoxBoundingVolume::getBoxBoundingVolume()
{
	return _boxBoundingVolume;
}

void CC3NodeSphereThenBoxBoundingVolume::setShouldMaximize( bool shouldMax )
{
	super::setShouldMaximize( shouldMax );
	_sphericalBoundingVolume->setShouldMaximize( shouldMax );
	_boxBoundingVolume->setShouldMaximize( shouldMax );
}

void CC3NodeSphereThenBoxBoundingVolume::setNode( CC3Node* aNode )
{
	super::setNode( aNode );
	_sphericalBoundingVolume->setNode( aNode );
	_boxBoundingVolume->setNode( aNode );
}

/** Overridden to keep the COG consistent for all BV's.  */
void CC3NodeSphereThenBoxBoundingVolume::setCenterOfGeometry( const CC3Vector& aLocation )
{
	super::setCenterOfGeometry( aLocation );
	_sphericalBoundingVolume->setCenterOfGeometry( aLocation );
	_boxBoundingVolume->setCenterOfGeometry( aLocation );
}

void CC3NodeSphereThenBoxBoundingVolume::scaleBy( GLfloat scale )
{
	super::scaleBy( scale );
	_sphericalBoundingVolume->scaleBy( scale );
	_boxBoundingVolume->scaleBy( scale );
}

void CC3NodeSphereThenBoxBoundingVolume::populateFrom( CC3NodeSphereThenBoxBoundingVolume* another )
{
	super::populateFrom( another );
	
	CC_SAFE_RELEASE(_sphericalBoundingVolume);
	_sphericalBoundingVolume = (CC3NodeSphericalBoundingVolume*)another->getSphericalBoundingVolume()->copy();	// retained

	CC_SAFE_RELEASE(_boxBoundingVolume);
	_boxBoundingVolume = (CC3NodeBoxBoundingVolume*)another->getBoxBoundingVolume()->copy();				// retained
}

CCObject* CC3NodeSphereThenBoxBoundingVolume::copyWithZone( CCZone* pZone )
{
	CC3NodeSphereThenBoxBoundingVolume* pVal = new CC3NodeSphereThenBoxBoundingVolume;
	pVal->init();
	pVal->populateFrom( this );

	return pVal;
}

void CC3NodeSphereThenBoxBoundingVolume::markDirty()
{
	super::markDirty();
	_sphericalBoundingVolume->markDirty();
	_boxBoundingVolume->markDirty();
}

void CC3NodeSphereThenBoxBoundingVolume::markTransformDirty()
{
	super::markTransformDirty();
	_sphericalBoundingVolume->markTransformDirty();
	_boxBoundingVolume->markTransformDirty();
}

/** Builds each contained bounding volume, if needed, and sets the local centerOfGeometry from the box. */
void CC3NodeSphereThenBoxBoundingVolume::buildVolume()
{
	super::buildVolume();
	_sphericalBoundingVolume->updateIfNeeded();
	_boxBoundingVolume->updateIfNeeded();
	_centerOfGeometry = (_boxBoundingVolume
						 ? _boxBoundingVolume->getCenterOfGeometry()
						 : _sphericalBoundingVolume->getCenterOfGeometry());
}

void CC3NodeSphereThenBoxBoundingVolume::transformVolume()
{
	super::transformVolume();
	_sphericalBoundingVolume->transformVolume();
	_boxBoundingVolume->transformVolume();
}

bool CC3NodeSphereThenBoxBoundingVolume::doesIntersect( CC3BoundingVolume* aBoundingVolume )
{
	bool intersects = true;

	if (_sphericalBoundingVolume)
		intersects = intersects && _sphericalBoundingVolume->doesIntersect( aBoundingVolume );

	if (_boxBoundingVolume)
		intersects = intersects && _boxBoundingVolume->doesIntersect( aBoundingVolume );
	
	CC3LogBVIntersection(aBoundingVolume, intersects);
	return intersects;
}

bool CC3NodeSphereThenBoxBoundingVolume::doesIntersectLocation( const CC3Vector& aLocation )
{
	return (_sphericalBoundingVolume->doesIntersectLocation( aLocation ) &&
			_boxBoundingVolume->doesIntersectLocation( aLocation ));
}

bool CC3NodeSphereThenBoxBoundingVolume::doesIntersectRay( const CC3Ray& aRay )
{
	if (_shouldIgnoreRayIntersection) 
		return false;

	return (_sphericalBoundingVolume->doesIntersectRay( aRay ) &&
			_boxBoundingVolume->doesIntersectRay( aRay ));
}

bool CC3NodeSphereThenBoxBoundingVolume::isInFrontOfPlane( const CC3Plane& aPlane )
{
	return (_sphericalBoundingVolume->isInFrontOfPlane( aPlane ) ||
			_boxBoundingVolume->isInFrontOfPlane( aPlane ));
}

bool CC3NodeSphereThenBoxBoundingVolume::doesIntersectSphere( const CC3Sphere& aSphere, CC3BoundingVolume* otherBoundingVolume )
{
	return (_sphericalBoundingVolume->doesIntersectSphere( aSphere, otherBoundingVolume ) &&
			_boxBoundingVolume->doesIntersectSphere( aSphere, otherBoundingVolume) );
}

bool CC3NodeSphereThenBoxBoundingVolume::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes, CC3BoundingVolume* otherBoundingVolume )
{
	return (_sphericalBoundingVolume->doesIntersectConvexHullOf( numOtherPlanes, otherPlanes, otherBoundingVolume ) &&
			_boxBoundingVolume->doesIntersectConvexHullOf( numOtherPlanes, otherPlanes, otherBoundingVolume ));
}

/** Returns the location of the intersection on the tightest BV. */
CC3Vector CC3NodeSphereThenBoxBoundingVolume::getLocationOfRayIntesection( const CC3Ray& localRay )
{
	if (_shouldIgnoreRayIntersection) 
		return CC3Vector::kCC3VectorNull;

	CC3NodeBoundingVolume* bv = _boxBoundingVolume;
	if ( !_boxBoundingVolume ) 
		bv = _sphericalBoundingVolume;

	return bv ? bv->getLocationOfRayIntesection( localRay ) : CC3Vector::kCC3VectorNull;
}

void CC3NodeSphereThenBoxBoundingVolume::setShouldDraw( bool shouldDraw )
{
	_sphericalBoundingVolume->setShouldDraw( shouldDraw );
	_boxBoundingVolume->setShouldDraw( shouldDraw );
}

bool CC3NodeSphereThenBoxBoundingVolume::init()
{
	initWithSphereVolume( CC3NodeSphericalBoundingVolume::boundingVolume(), CC3NodeBoxBoundingVolume::boundingVolume() );
	return true;
}

CC3NodeSphereThenBoxBoundingVolume* CC3NodeSphereThenBoxBoundingVolume::boundingVolume()
{
	CC3NodeSphereThenBoxBoundingVolume* pVolume = new CC3NodeSphereThenBoxBoundingVolume;
	pVolume->init();
	pVolume->autorelease();

	return pVolume;
}

void CC3NodeSphereThenBoxBoundingVolume::initWithSphereVolume( CC3NodeSphericalBoundingVolume* sphereBV, CC3NodeBoxBoundingVolume* boxBV )
{
	if ( super::init() ) 
	{
		_sphericalBoundingVolume = sphereBV;
		_sphericalBoundingVolume->retain();
		_boxBoundingVolume = boxBV;
		_boxBoundingVolume->retain();
	}
}

CC3NodeSphereThenBoxBoundingVolume* CC3NodeSphereThenBoxBoundingVolume::boundingVolumeWithSphereVolume( CC3NodeSphericalBoundingVolume* sphereBV, CC3NodeBoxBoundingVolume* boxBV )
{
	CC3NodeSphereThenBoxBoundingVolume* pVolume = new CC3NodeSphereThenBoxBoundingVolume;
	pVolume->initWithSphereVolume( sphereBV, boxBV );
	pVolume->autorelease();

	return pVolume;
}

void CC3NodeSphereThenBoxBoundingVolume::initFromSphere( const CC3Sphere& sphere, const CC3Box& box )
{
	return initWithSphereVolume( CC3NodeSphericalBoundingVolume::boundingVolumeFromSphere( sphere ), 
		CC3NodeBoxBoundingVolume::boundingVolumeFromBox( box ) );
}

CC3NodeSphereThenBoxBoundingVolume* CC3NodeSphereThenBoxBoundingVolume::boundingVolumeFromSphere( const CC3Sphere& sphere, const CC3Box& box )
{
	CC3NodeSphereThenBoxBoundingVolume* pVolume = new CC3NodeSphereThenBoxBoundingVolume;
	pVolume->initFromSphere( sphere, box );
	pVolume->autorelease();

	return pVolume;
}

void CC3NodeSphereThenBoxBoundingVolume::initByCircumscribingBox( const CC3Box& box )
{
	return initFromSphere( CC3SphereFromCircumscribingBox(box), box );
}

CC3NodeSphereThenBoxBoundingVolume* CC3NodeSphereThenBoxBoundingVolume::boundingVolumeCircumscribingBox( const CC3Box& box )
{
	CC3NodeSphereThenBoxBoundingVolume* pVolume = new CC3NodeSphereThenBoxBoundingVolume;
	pVolume->initByCircumscribingBox( box );
	pVolume->autorelease();

	return pVolume;
}

std::string CC3NodeSphereThenBoxBoundingVolume::fullDescription()
{
	return "CC3NodeSphereThenBoxBoundingVolume";
}

bool CC3NodeSphereThenBoxBoundingVolume::doesIntersectBounds( const CCRect& bounds )
{ 
	return true; 
}

bool CC3NodeBoundingArea::doesIntersectBounds( const CCRect& bounds )
{
	return true;
}

/** Intersects everything except nil. */
bool CC3NodeInfiniteBoundingVolume::doesIntersect( CC3BoundingVolume* aBoundingVolume )
{
	bool intersects = (aBoundingVolume != NULL);
	CC3LogBVIntersection(aBoundingVolume, intersects);
	return intersects;
}

bool CC3NodeInfiniteBoundingVolume::doesIntersectLocation( const CC3Vector& aLocation )
{ 
	return true; 
}

bool CC3NodeInfiniteBoundingVolume::doesIntersectRay( const CC3Ray& aRay )
{
	if (_shouldIgnoreRayIntersection) 
		return false;

	return true;
}

bool CC3NodeInfiniteBoundingVolume::isInFrontOfPlane( const CC3Plane& aPlane )
{ 
	return false; 
}

bool CC3NodeInfiniteBoundingVolume::doesIntersectSphere( const CC3Sphere& aSphere, CC3BoundingVolume* otherBoundingVolume )
{ 
	return true; 
}

bool CC3NodeInfiniteBoundingVolume::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes, CC3BoundingVolume* otherBoundingVolume )
{ 
	return true; 
}

CC3Vector CC3NodeInfiniteBoundingVolume::getLocationOfRayIntesection( const CC3Ray& localRay )
{
	if (_shouldIgnoreRayIntersection) 
		return CC3Vector::kCC3VectorNull;

	return localRay.startLocation;
}

bool CC3NodeInfiniteBoundingVolume::shouldDraw()
{ 
	return _shouldDraw;
}

void CC3NodeInfiniteBoundingVolume::setShouldDraw( bool shdDraw )
{

}

bool CC3NodeNullBoundingVolume::doesIntersect( CC3BoundingVolume* aBoundingVolume )
{
	CC3LogBVIntersection(aBoundingVolume, false);
	return false;
}

bool CC3NodeNullBoundingVolume::doesIntersectLocation( const CC3Vector& aLocation )
{ 
	return false; 
}

bool CC3NodeNullBoundingVolume::doesIntersectRay( const CC3Ray& aRay )
{ 
	return false; 
}

bool CC3NodeNullBoundingVolume::isInFrontOfPlane( const CC3Plane& aPlane )
{ 
	return true; 
}

bool CC3NodeNullBoundingVolume::doesIntersectSphere( const CC3Sphere& aSphere, CC3BoundingVolume* otherBoundingVolume )
{ 
	return false; 
}

bool CC3NodeNullBoundingVolume::doesIntersectConvexHullOf( GLuint numOtherPlanes, CC3Plane* otherPlanes, CC3BoundingVolume* otherBoundingVolume )
{ 
	return false; 
}

CC3Vector CC3NodeNullBoundingVolume::getLocationOfRayIntesection( const CC3Ray& localRay )
{ 
	return CC3Vector::kCC3VectorNull; 
}

bool CC3NodeNullBoundingVolume::shouldDraw()
{
	return _shouldDraw; 
}

void CC3NodeNullBoundingVolume::setShouldDraw( bool shdDraw )
{
}

NS_COCOS3D_END
