/**
 * @module cocos3dx
 */
var cc3 = cc3 || {};

/**
 * @class CC3Matrix
 */
cc3.CC3Matrix = {

/**
 * @method extractQuaternion
 * @return A value converted from C/C++ "CC3Quaternion"
 */
extractQuaternion : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Matrix*}
 */
populateFrom : function () {},

/**
 * @method multiplyIntoCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
multiplyIntoCC3Matrix4x4 : function () {},

/**
 * @method leftMultiplyIntoCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
leftMultiplyIntoCC3Matrix3x3 : function () {},

/**
 * @method populateToLookAt
 * @param {cocos3d::CC3Vector}
 * @param {cocos3d::CC3Vector}
 * @param {cocos3d::CC3Vector}
 */
populateToLookAt : function () {},

/**
 * @method extractRotation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractRotation : function () {},

/**
 * @method multiplyIntoCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
multiplyIntoCC3Matrix4x3 : function () {},

/**
 * @method transformHomogeneousVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 * @param {cocos3d::CC3Vector4}
 */
transformHomogeneousVector : function () {},

/**
 * @method scaleBy
 * @param {cocos3d::CC3Vector}
 */
scaleBy : function () {},

/**
 * @method extractRightDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractRightDirection : function () {},

/**
 * @method populateToPointTowards
 * @param {cocos3d::CC3Vector}
 * @param {cocos3d::CC3Vector}
 */
populateToPointTowards : function () {},

/**
 * @method rotateByQuaternion
 * @param {cocos3d::CC3Quaternion}
 */
rotateByQuaternion : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method translateBy
 * @param {cocos3d::CC3Vector}
 */
translateBy : function () {},

/**
 * @method orthonormalizeRotationStartingWith
 * @param {unsigned int}
 */
orthonormalizeRotationStartingWith : function () {},

/**
 * @method leftMultiplyByCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
leftMultiplyByCC3Matrix3x3 : function () {},

/**
 * @method invert
 * @return A value converted from C/C++ "bool"
 */
invert : function () {},

/**
 * @method populateCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
populateCC3Matrix3x3 : function () {},

/**
 * @method extractTranslation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractTranslation : function () {},

/**
 * @method multiplyIntoCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
multiplyIntoCC3Matrix3x3 : function () {},

/**
 * @method init
 */
init : function () {},

/**
 * @method populateCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
populateCC3Matrix4x3 : function () {},

/**
 * @method populateCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
populateCC3Matrix4x4 : function () {},

/**
 * @method populateFromScale
 * @param {cocos3d::CC3Vector}
 */
populateFromScale : function () {},

/**
 * @method rotateBy
 * @param {cocos3d::CC3Vector}
 */
rotateBy : function () {},

/**
 * @method leftMultiplyIntoCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
leftMultiplyIntoCC3Matrix4x3 : function () {},

/**
 * @method invertRigid
 */
invertRigid : function () {},

/**
 * @method leftMultiplyIntoCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
leftMultiplyIntoCC3Matrix4x4 : function () {},

/**
 * @method multiplyByCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
multiplyByCC3Matrix4x3 : function () {},

/**
 * @method populateFromCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
populateFromCC3Matrix4x3 : function () {},

/**
 * @method populateFromCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
populateFromCC3Matrix4x4 : function () {},

/**
 * @method transformDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Vector}
 */
transformDirection : function () {},

/**
 * @method leftMultiplyBy
 * @param {cocos3d::CC3Matrix*}
 */
leftMultiplyBy : function () {},

/**
 * @method multiplyByCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
multiplyByCC3Matrix4x4 : function () {},

/**
 * @method transpose
 */
transpose : function () {},

/**
 * @method isDirty
 * @return A value converted from C/C++ "bool"
 */
isDirty : function () {},

/**
 * @method populateIdentity
 */
populateIdentity : function () {},

/**
 * @method populateFromQuaternion
 * @param {cocos3d::CC3Quaternion}
 */
populateFromQuaternion : function () {},

/**
 * @method extractUpDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractUpDirection : function () {},

/**
 * @method extractForwardDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractForwardDirection : function () {},

/**
 * @method transformRay
 * @return A value converted from C/C++ "CC3Ray"
 * @param {cocos3d::CC3Ray}
 */
transformRay : function () {},

/**
 * @method populateFromTranslation
 * @param {cocos3d::CC3Vector}
 */
populateFromTranslation : function () {},

/**
 * @method multiplyByCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
multiplyByCC3Matrix3x3 : function () {},

/**
 * @method leftMultiplyByCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
leftMultiplyByCC3Matrix4x4 : function () {},

/**
 * @method setIsDirty
 * @param {bool}
 */
setIsDirty : function () {},

/**
 * @method populateZero
 */
populateZero : function () {},

/**
 * @method multiplyBy
 * @param {cocos3d::CC3Matrix*}
 */
multiplyBy : function () {},

/**
 * @method leftMultiplyByCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
leftMultiplyByCC3Matrix4x3 : function () {},

/**
 * @method populateFromRotation
 * @param {cocos3d::CC3Vector}
 */
populateFromRotation : function () {},

/**
 * @method populateFromCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
populateFromCC3Matrix3x3 : function () {},

/**
 * @method isRigid
 * @return A value converted from C/C++ "bool"
 */
isRigid : function () {},

/**
 * @method isIdentity
 * @return A value converted from C/C++ "bool"
 */
isIdentity : function () {},

/**
 * @method transformLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Vector}
 */
transformLocation : function () {},

/**
 * @method invertAdjoint
 * @return A value converted from C/C++ "bool"
 */
invertAdjoint : function () {},

/**
 * @method matrixByMultiplying
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 * @param {cocos3d::CC3Matrix*}
 * @param {cocos3d::CC3Matrix*}
 */
matrixByMultiplying : function () {},

/**
 * @method matrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
matrix : function () {},

/**
 * @method CC3Matrix
 * @constructor
 */
CC3Matrix : function () {},

};

/**
 * @class CC3AffineMatrix
 */
cc3.CC3AffineMatrix = {

/**
 * @method extractQuaternion
 * @return A value converted from C/C++ "CC3Quaternion"
 */
extractQuaternion : function () {},

/**
 * @method multiplyIntoCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
multiplyIntoCC3Matrix4x4 : function () {},

/**
 * @method leftMultiplyIntoCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
leftMultiplyIntoCC3Matrix3x3 : function () {},

/**
 * @method extractRotation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractRotation : function () {},

/**
 * @method multiplyIntoCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
multiplyIntoCC3Matrix4x3 : function () {},

/**
 * @method transformHomogeneousVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 * @param {cocos3d::CC3Vector4}
 */
transformHomogeneousVector : function () {},

/**
 * @method extractRightDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractRightDirection : function () {},

/**
 * @method orthonormalizeRotationStartingWith
 * @param {unsigned int}
 */
orthonormalizeRotationStartingWith : function () {},

/**
 * @method leftMultiplyByCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
leftMultiplyByCC3Matrix3x3 : function () {},

/**
 * @method populateCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
populateCC3Matrix3x3 : function () {},

/**
 * @method transformDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Vector}
 */
transformDirection : function () {},

/**
 * @method multiplyIntoCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
multiplyIntoCC3Matrix3x3 : function () {},

/**
 * @method extractTranslation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractTranslation : function () {},

/**
 * @method populateCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
populateCC3Matrix4x3 : function () {},

/**
 * @method populateCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
populateCC3Matrix4x4 : function () {},

/**
 * @method leftMultiplyIntoCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
leftMultiplyIntoCC3Matrix4x3 : function () {},

/**
 * @method invertRigid
 */
invertRigid : function () {},

/**
 * @method leftMultiplyIntoCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
leftMultiplyIntoCC3Matrix4x4 : function () {},

/**
 * @method multiplyByCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
multiplyByCC3Matrix4x3 : function () {},

/**
 * @method multiplyByCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
multiplyByCC3Matrix4x4 : function () {},

/**
 * @method transpose
 */
transpose : function () {},

/**
 * @method extractUpDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractUpDirection : function () {},

/**
 * @method extractForwardDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
extractForwardDirection : function () {},

/**
 * @method multiplyByCC3Matrix3x3
 * @param {CC3Matrix3x3*}
 */
multiplyByCC3Matrix3x3 : function () {},

/**
 * @method leftMultiplyByCC3Matrix4x4
 * @param {CC3Matrix4x4*}
 */
leftMultiplyByCC3Matrix4x4 : function () {},

/**
 * @method leftMultiplyByCC3Matrix4x3
 * @param {CC3Matrix4x3*}
 */
leftMultiplyByCC3Matrix4x3 : function () {},

/**
 * @method invertAdjoint
 * @return A value converted from C/C++ "bool"
 */
invertAdjoint : function () {},

/**
 * @method transformLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Vector}
 */
transformLocation : function () {},

/**
 * @method matrix
 * @return A value converted from C/C++ "cocos3d::CC3AffineMatrix*"
 */
matrix : function () {},

/**
 * @method CC3AffineMatrix
 * @constructor
 */
CC3AffineMatrix : function () {},

};

/**
 * @class CC3Cacheable
 */
cc3.CC3Cacheable = {

/**
 * @method getName
 * @return A value converted from C/C++ "std::string"
 */
getName : function () {},

};

/**
 * @class CC3Identifiable
 */
cc3.CC3Identifiable = {

/**
 * @method populateFrom
 * @param {cocos3d::CC3Identifiable*}
 */
populateFrom : function () {},

/**
 * @method resetTagAllocation
 */
resetTagAllocation : function () {},

/**
 * @method initWithName
 * @param {std::string}
 */
initWithName : function () {},

/**
 * @method getPodIndex
 * @return A value converted from C/C++ "int"
 */
getPodIndex : function () {},

/**
 * @method getUserData
 * @return A value converted from C/C++ "void*"
 */
getUserData : function () {},

/**
 * @method getName
 * @return A value converted from C/C++ "std::string"
 */
getName : function () {},

/**
 * @method initUserData
 */
initUserData : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method nextTag
 * @return A value converted from C/C++ "unsigned int"
 */
nextTag : function () {},

/**
 * @method setPodIndex
 * @param {int}
 */
setPodIndex : function () {},

/**
 * @method setName
 * @param {std::string}
 */
setName : function () {},

/**
 * @method copyWithName
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {std::string}
 */
copyWithName : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method getTag
 * @return A value converted from C/C++ "unsigned int"
 */
getTag : function () {},

/**
 * @method copy
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 */
copy : function () {},

/**
 * @method shouldIncludeInDeepCopy
 * @return A value converted from C/C++ "bool"
 */
shouldIncludeInDeepCopy : function () {},

/**
 * @method setUserData
 * @param {void*}
 */
setUserData : function () {},

/**
 * @method fullDescription
 * @return A value converted from C/C++ "std::string"
 */
fullDescription : function () {},

/**
 * @method setTag
 * @param {unsigned int}
 */
setTag : function () {},

/**
 * @method copyUserDataFrom
 * @param {cocos3d::CC3Identifiable*}
 */
copyUserDataFrom : function () {},

/**
 * @method getNameSuffix
 * @return A value converted from C/C++ "std::string"
 */
getNameSuffix : function () {},

/**
 * @method getInstanceCount
 * @return A value converted from C/C++ "int"
 */
getInstanceCount : function () {},

/**
 * @method CC3Identifiable
 * @constructor
 */
CC3Identifiable : function () {},

};

/**
 * @class CC3Node
 */
cc3.CC3Node = {

/**
 * @method defaultBoundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3NodeBoundingVolume*"
 */
defaultBoundingVolume : function () {},

/**
 * @method doNotBufferVertexLocations
 */
doNotBufferVertexLocations : function () {},

/**
 * @method retainVertexIndices
 */
retainVertexIndices : function () {},

/**
 * @method setPodContentIndex
 * @param {int}
 */
setPodContentIndex : function () {},

/**
 * @method getSkeletalScale
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getSkeletalScale : function () {},

/**
 * @method getStructureDescription
 * @return A value converted from C/C++ "std::string"
 */
getStructureDescription : function () {},

/**
 * @method isLight
 * @return A value converted from C/C++ "bool"
 */
isLight : function () {},

/**
 * @method disableAnimation
 */
disableAnimation : function () {},

/**
 * @method addChildFromBackgroundThread
 * @param {cocos3d::CC3Node*}
 */
addChildFromBackgroundThread : function () {},

/**
 * @method doNotBufferVertexIndices
 */
doNotBufferVertexIndices : function () {},

/**
 * @method getNodeNamed
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 * @param {const char*}
 */
getNodeNamed : function () {},

/**
 * @method getPerformanceStatistics
 * @return A value converted from C/C++ "cocos3d::CC3PerformanceStatistics*"
 */
getPerformanceStatistics : function () {},

/**
 * @method setShouldShadowBackFaces
 * @param {bool}
 */
setShouldShadowBackFaces : function () {},

/**
 * @method getRootAncestor
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
getRootAncestor : function () {},

/**
 * @method removeAllDirectionMarkers
 */
removeAllDirectionMarkers : function () {},

/**
 * @method setZOrder
 * @param {int}
 */
setZOrder : function () {},

/**
 * @method shouldDisableDepthTest
 * @return A value converted from C/C++ "bool"
 */
shouldDisableDepthTest : function () {},

/**
 * @method shouldBlendAtFullOpacity
 * @return A value converted from C/C++ "bool"
 */
shouldBlendAtFullOpacity : function () {},

/**
 * @method setPodUserDataSize
 * @param {unsigned int}
 */
setPodUserDataSize : function () {},

/**
 * @method getRotationAxis
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getRotationAxis : function () {},

/**
 * @method setShouldAddShadowVolumeEndCapsOnlyWhenNeeded
 * @param {bool}
 */
setShouldAddShadowVolumeEndCapsOnlyWhenNeeded : function () {},

/**
 * @method getAnimation
 * @return A value converted from C/C++ "cocos3d::CC3NodeAnimation*"
 */
getAnimation : function () {},

/**
 * @method removeTransformListener
 * @param {cocos3d::CC3NodeTransformListenerProtocol*}
 */
removeTransformListener : function () {},

/**
 * @method isLightProbe
 * @return A value converted from C/C++ "bool"
 */
isLightProbe : function () {},

/**
 * @method createBoundingVolume
 */
createBoundingVolume : function () {},

/**
 * @method touchableNode
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
touchableNode : function () {},

/**
 * @method getAnimationOnTrack
 * @return A value converted from C/C++ "cocos3d::CC3NodeAnimation*"
 * @param {unsigned int}
 */
getAnimationOnTrack : function () {},

/**
 * @method setShouldAllowTouchableWhenInvisible
 * @param {bool}
 */
setShouldAllowTouchableWhenInvisible : function () {},

/**
 * @method shouldDrawDescriptor
 * @return A value converted from C/C++ "bool"
 */
shouldDrawDescriptor : function () {},

/**
 * @method removeAllTransformListeners
 */
removeAllTransformListeners : function () {},

/**
 * @method applyTargetLocation
 */
applyTargetLocation : function () {},

/**
 * @method setEmissionColor
 * @param {cocos2d::ccColor4F}
 */
setEmissionColor : function () {},

/**
 * @method applyEffectNamedFromFile
 * @param {std::string}
 * @param {std::string}
 */
applyEffectNamedFromFile : function () {},

/**
 * @method isMeshNode
 * @return A value converted from C/C++ "bool"
 */
isMeshNode : function () {},

/**
 * @method retainVertexBitangents
 */
retainVertexBitangents : function () {},

/**
 * @method markAddEnd
 */
markAddEnd : function () {},

/**
 * @method isDescendantOf
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Node*}
 */
isDescendantOf : function () {},

/**
 * @method getProjectedLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getProjectedLocation : function () {},

/**
 * @method hide
 */
hide : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method setParent
 * @param {cocos3d::CC3Node*}
 */
setParent : function () {},

/**
 * @method drawWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawWithVisitor : function () {},

/**
 * @method removeAnimationState
 * @param {cocos3d::CC3NodeAnimationState*}
 */
removeAnimationState : function () {},

/**
 * @method removeShadowVolumes
 */
removeShadowVolumes : function () {},

/**
 * @method getLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLocation : function () {},

/**
 * @method isTransformRigid
 * @return A value converted from C/C++ "bool"
 */
isTransformRigid : function () {},

/**
 * @method disableAnimationOnTrack
 * @param {unsigned int}
 */
disableAnimationOnTrack : function () {},

/**
 * @method enableScaleAnimation
 */
enableScaleAnimation : function () {},

/**
 * @method getRotationAngle
 * @return A value converted from C/C++ "float"
 */
getRotationAngle : function () {},

/**
 * @method hasShadowVolumesForLight
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Light*}
 */
hasShadowVolumesForLight : function () {},

/**
 * @method applyTargetLocationAsGlobal
 */
applyTargetLocationAsGlobal : function () {},

/**
 * @method setColor
 * @param {cocos2d::ccColor3B}
 */
setColor : function () {},

/**
 * @method hasShadowVolumes
 * @return A value converted from C/C++ "bool"
 */
hasShadowVolumes : function () {},

/**
 * @method disableAllLocationAnimation
 */
disableAllLocationAnimation : function () {},

/**
 * @method buildGlobalRotationMatrix
 */
buildGlobalRotationMatrix : function () {},

/**
 * @method addShadowVolumes
 */
addShadowVolumes : function () {},

/**
 * @method setDiffuseColor
 * @param {cocos2d::ccColor4F}
 */
setDiffuseColor : function () {},

/**
 * @method doesIntersectNode
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Node*}
 */
doesIntersectNode : function () {},

/**
 * @method getAnimationStateOnTrack
 * @return A value converted from C/C++ "cocos3d::CC3NodeAnimationState*"
 * @param {unsigned int}
 */
getAnimationStateOnTrack : function () {},

/**
 * @method markAnimationDirty
 */
markAnimationDirty : function () {},

/**
 * @method retainVertexBoneIndices
 */
retainVertexBoneIndices : function () {},

/**
 * @method addCopiesOfChildrenFrom
 * @param {cocos3d::CC3Node*}
 */
addCopiesOfChildrenFrom : function () {},

/**
 * @method setShouldAutotargetCamera
 * @param {bool}
 */
setShouldAutotargetCamera : function () {},

/**
 * @method setShouldBlendAtFullOpacity
 * @param {bool}
 */
setShouldBlendAtFullOpacity : function () {},

/**
 * @method disableAllScaleAnimation
 */
disableAllScaleAnimation : function () {},

/**
 * @method shouldAutotargetCamera
 * @return A value converted from C/C++ "bool"
 */
shouldAutotargetCamera : function () {},

/**
 * @method setShadowLagFactor
 * @param {unsigned short}
 */
setShadowLagFactor : function () {},

/**
 * @method setShouldDrawWireframeBox
 * @param {bool}
 */
setShouldDrawWireframeBox : function () {},

/**
 * @method getRotator
 * @return A value converted from C/C++ "cocos3d::CC3Rotator*"
 */
getRotator : function () {},

/**
 * @method doNotBufferVertexBitangents
 */
doNotBufferVertexBitangents : function () {},

/**
 * @method getDisplayedOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getDisplayedOpacity : function () {},

/**
 * @method getTargettingRotator
 * @return A value converted from C/C++ "cocos3d::CC3TargettingRotator*"
 */
getTargettingRotator : function () {},

/**
 * @method doNotBufferVertexBoneWeights
 */
doNotBufferVertexBoneWeights : function () {},

/**
 * @method setPerformanceStatistics
 * @param {cocos3d::CC3PerformanceStatistics*}
 */
setPerformanceStatistics : function () {},

/**
 * @method isCamera
 * @return A value converted from C/C++ "bool"
 */
isCamera : function () {},

/**
 * @method freezeIfInanimateOnTrack
 * @param {unsigned int}
 */
freezeIfInanimateOnTrack : function () {},

/**
 * @method shouldUseLightProbes
 * @return A value converted from C/C++ "bool"
 */
shouldUseLightProbes : function () {},

/**
 * @method closestNodeIntersectedByGlobalRay
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 * @param {cocos3d::CC3Ray}
 */
closestNodeIntersectedByGlobalRay : function () {},

/**
 * @method getPodContentIndex
 * @return A value converted from C/C++ "int"
 */
getPodContentIndex : function () {},

/**
 * @method getLineWidth
 * @return A value converted from C/C++ "float"
 */
getLineWidth : function () {},

/**
 * @method setIsRunning
 * @param {bool}
 */
setIsRunning : function () {},

/**
 * @method setDepthFunction
 * @param {unsigned int}
 */
setDepthFunction : function () {},

/**
 * @method getGlobalTransformMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getGlobalTransformMatrix : function () {},

/**
 * @method getShaderContext
 * @return A value converted from C/C++ "cocos3d::CC3ShaderContext*"
 */
getShaderContext : function () {},

/**
 * @method getDirectionMarkers
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getDirectionMarkers : function () {},

/**
 * @method addChild
 * @param {cocos3d::CC3Node*}
 */
addChild : function () {},

/**
 * @method setLineWidth
 * @param {float}
 */
setLineWidth : function () {},

/**
 * @method setShouldDisableDepthMask
 * @param {bool}
 */
setShouldDisableDepthMask : function () {},

/**
 * @method markBoundingVolumeDirty
 */
markBoundingVolumeDirty : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method getShadowLagFactor
 * @return A value converted from C/C++ "unsigned short"
 */
getShadowLagFactor : function () {},

/**
 * @method getLineSmoothingHint
 * @return A value converted from C/C++ "unsigned int"
 */
getLineSmoothingHint : function () {},

/**
 * @method disableAllQuaternionAnimation
 */
disableAllQuaternionAnimation : function () {},

/**
 * @method addDirectionMarkerColored
 * @param {cocos2d::ccColor4F}
 * @param {cocos3d::CC3Vector}
 */
addDirectionMarkerColored : function () {},

/**
 * @method setDecalOffsetUnits
 * @param {float}
 */
setDecalOffsetUnits : function () {},

/**
 * @method enableAnimationOnTrack
 * @param {unsigned int}
 */
enableAnimationOnTrack : function () {},

/**
 * @method deleteGLBuffers
 */
deleteGLBuffers : function () {},

/**
 * @method applyRotationTo
 * @param {cocos3d::CC3Matrix*}
 */
applyRotationTo : function () {},

/**
 * @method getBlendFunc
 * @return A value converted from C/C++ "ccBlendFunc"
 */
getBlendFunc : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method selectShaders
 */
selectShaders : function () {},

/**
 * @method shouldContributeToParentBoundingBox
 * @return A value converted from C/C++ "bool"
 */
shouldContributeToParentBoundingBox : function () {},

/**
 * @method getNodeTagged
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 * @param {unsigned int}
 */
getNodeTagged : function () {},

/**
 * @method getScale
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getScale : function () {},

/**
 * @method resumeAllActions
 */
resumeAllActions : function () {},

/**
 * @method notifyTransformListeners
 */
notifyTransformListeners : function () {},

/**
 * @method shouldAllowTouchableWhenInvisible
 * @return A value converted from C/C++ "bool"
 */
shouldAllowTouchableWhenInvisible : function () {},

/**
 * @method shouldUpdateToTarget
 * @return A value converted from C/C++ "bool"
 */
shouldUpdateToTarget : function () {},

/**
 * @method rotationallyRestrictTargetLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Vector}
 */
rotationallyRestrictTargetLocation : function () {},

/**
 * @method getProjectedPosition
 * @return A value converted from C/C++ "cocos2d::CCPoint"
 */
getProjectedPosition : function () {},

/**
 * @method nodeWasDestroyed
 * @param {cocos3d::CC3Node*}
 */
nodeWasDestroyed : function () {},

/**
 * @method setCascadeColorEnabled
 * @param {bool}
 */
setCascadeColorEnabled : function () {},

/**
 * @method wasRemoved
 */
wasRemoved : function () {},

/**
 * @method setNormalScalingMethod
 * @param {cocos3d::CC3NormalScaling}
 */
setNormalScalingMethod : function () {},

/**
 * @method setShouldLogIntersectionMisses
 * @param {bool}
 */
setShouldLogIntersectionMisses : function () {},

/**
 * @method getTargettingConstraint
 * @return A value converted from C/C++ "cocos3d::CC3TargettingConstraint"
 */
getTargettingConstraint : function () {},

/**
 * @method getPodParentIndex
 * @return A value converted from C/C++ "int"
 */
getPodParentIndex : function () {},

/**
 * @method getGlobalCenterOfGeometry
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalCenterOfGeometry : function () {},

/**
 * @method updateAfterTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
updateAfterTransform : function () {},

/**
 * @method doNotBufferVertexNormals
 */
doNotBufferVertexNormals : function () {},

/**
 * @method setExpectsVerticallyFlippedTextures
 * @param {bool}
 */
setExpectsVerticallyFlippedTextures : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {unsigned char}
 */
updateDisplayedOpacity : function () {},

/**
 * @method setIsAnimationEnabled
 * @param {bool}
 */
setIsAnimationEnabled : function () {},

/**
 * @method doNotBufferVertexTangents
 */
doNotBufferVertexTangents : function () {},

/**
 * @method getWireframeBoxNode
 * @return A value converted from C/C++ "cocos3d::CC3WireframeBoundingBoxNode*"
 */
getWireframeBoxNode : function () {},

/**
 * @method setPodTargetIndex
 * @param {int}
 */
setPodTargetIndex : function () {},

/**
 * @method flipTexturesHorizontally
 */
flipTexturesHorizontally : function () {},

/**
 * @method setReflectivity
 * @param {float}
 */
setReflectivity : function () {},

/**
 * @method asOrientingWrapper
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
asOrientingWrapper : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method setShouldDrawAllDescriptors
 * @param {bool}
 */
setShouldDrawAllDescriptors : function () {},

/**
 * @method setShouldUseFixedBoundingVolume
 * @param {bool}
 */
setShouldUseFixedBoundingVolume : function () {},

/**
 * @method shouldStopActionsWhenRemoved
 * @return A value converted from C/C++ "bool"
 */
shouldStopActionsWhenRemoved : function () {},

/**
 * @method shouldReverseForwardDirection
 * @return A value converted from C/C++ "bool"
 */
shouldReverseForwardDirection : function () {},

/**
 * @method shouldCastShadowsWhenInvisible
 * @return A value converted from C/C++ "bool"
 */
shouldCastShadowsWhenInvisible : function () {},

/**
 * @method freezeAllInanimatesOnTrack
 * @param {unsigned int}
 */
freezeAllInanimatesOnTrack : function () {},

/**
 * @method disableLocationAnimation
 */
disableLocationAnimation : function () {},

/**
 * @method enableAllAnimationOnTrack
 * @param {unsigned int}
 */
enableAllAnimationOnTrack : function () {},

/**
 * @method isTransformDirty
 * @return A value converted from C/C++ "bool"
 */
isTransformDirty : function () {},

/**
 * @method getShadowVolumeForLight
 * @return A value converted from C/C++ "cocos3d::CC3ShadowVolumeMeshNode*"
 * @param {cocos3d::CC3Light*}
 */
getShadowVolumeForLight : function () {},

/**
 * @method setShouldDrawAllLocalContentWireframeBoxes
 * @param {bool}
 */
setShouldDrawAllLocalContentWireframeBoxes : function () {},

/**
 * @method shouldTrackTarget
 * @return A value converted from C/C++ "bool"
 */
shouldTrackTarget : function () {},

/**
 * @method setDecalOffsetFactor
 * @param {float}
 */
setDecalOffsetFactor : function () {},

/**
 * @method shouldAutoremoveWhenEmpty
 * @return A value converted from C/C++ "bool"
 */
shouldAutoremoveWhenEmpty : function () {},

/**
 * @method getShadowOffsetUnits
 * @return A value converted from C/C++ "float"
 */
getShadowOffsetUnits : function () {},

/**
 * @method shouldInheritTouchability
 * @return A value converted from C/C++ "bool"
 */
shouldInheritTouchability : function () {},

/**
 * @method setShadowVolumeVertexOffsetFactor
 * @param {float}
 */
setShadowVolumeVertexOffsetFactor : function () {},

/**
 * @method enableQuaternionAnimation
 */
enableQuaternionAnimation : function () {},

/**
 * @method applyScalingTo
 * @param {cocos3d::CC3Matrix*}
 */
applyScalingTo : function () {},

/**
 * @method isTouchEnabled
 * @return A value converted from C/C++ "bool"
 */
isTouchEnabled : function () {},

/**
 * @method isTargettingConstraintLocal
 * @return A value converted from C/C++ "bool"
 */
isTargettingConstraintLocal : function () {},

/**
 * @method setTouchEnabled
 * @param {bool}
 */
setTouchEnabled : function () {},

/**
 * @method touchDisableAll
 */
touchDisableAll : function () {},

/**
 * @method getGlobalHomogeneousPosition
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 */
getGlobalHomogeneousPosition : function () {},

/**
 * @method expectsVerticallyFlippedTextures
 * @return A value converted from C/C++ "bool"
 */
expectsVerticallyFlippedTextures : function () {},

/**
 * @method stopActionByTag
 * @param {unsigned int}
 */
stopActionByTag : function () {},

/**
 * @method setSpecularColor
 * @param {cocos2d::ccColor4F}
 */
setSpecularColor : function () {},

/**
 * @method setShouldTrackTarget
 * @param {bool}
 */
setShouldTrackTarget : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method markAddBegin
 */
markAddBegin : function () {},

/**
 * @method bindRestPose
 */
bindRestPose : function () {},

/**
 * @method disableQuaternionAnimation
 */
disableQuaternionAnimation : function () {},

/**
 * @method notifyDestructionListeners
 */
notifyDestructionListeners : function () {},

/**
 * @method getTouchableNode
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
getTouchableNode : function () {},

/**
 * @method updateBeforeTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
updateBeforeTransform : function () {},

/**
 * @method setShouldUseLightProbes
 * @param {bool}
 */
setShouldUseLightProbes : function () {},

/**
 * @method getTarget
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
getTarget : function () {},

/**
 * @method cleanupActions
 */
cleanupActions : function () {},

/**
 * @method shouldDrawWireframeBox
 * @return A value converted from C/C++ "bool"
 */
shouldDrawWireframeBox : function () {},

/**
 * @method setShouldUseClockwiseFrontFaceWinding
 * @param {bool}
 */
setShouldUseClockwiseFrontFaceWinding : function () {},

/**
 * @method setLocation
 * @param {cocos3d::CC3Vector}
 */
setLocation : function () {},

/**
 * @method setShaderContext
 * @param {cocos3d::CC3ShaderContext*}
 */
setShaderContext : function () {},

/**
 * @method shouldDrawAllDescriptors
 * @return A value converted from C/C++ "bool"
 */
shouldDrawAllDescriptors : function () {},

/**
 * @method setUniformScale
 * @param {float}
 */
setUniformScale : function () {},

/**
 * @method rotateByQuaternion
 * @param {cocos3d::CC3Quaternion}
 */
rotateByQuaternion : function () {},

/**
 * @method removeShadowVolumesForLight
 * @param {cocos3d::CC3Light*}
 */
removeShadowVolumesForLight : function () {},

/**
 * @method getCenterOfGeometry
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getCenterOfGeometry : function () {},

/**
 * @method getReferenceUpDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getReferenceUpDirection : function () {},

/**
 * @method getDescriptorNode
 * @return A value converted from C/C++ "cocos3d::CC3NodeDescriptor*"
 */
getDescriptorNode : function () {},

/**
 * @method doesIntersectFrustum
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Frustum*}
 */
doesIntersectFrustum : function () {},

/**
 * @method shouldDrawInClipSpace
 * @return A value converted from C/C++ "bool"
 */
shouldDrawInClipSpace : function () {},

/**
 * @method setTarget
 * @param {cocos3d::CC3Node*}
 */
setTarget : function () {},

/**
 * @method removeAllChildren
 */
removeAllChildren : function () {},

/**
 * @method setShouldUseLighting
 * @param {bool}
 */
setShouldUseLighting : function () {},

/**
 * @method isAnimationEnabled
 * @return A value converted from C/C++ "bool"
 */
isAnimationEnabled : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method isRunning
 * @return A value converted from C/C++ "bool"
 */
isRunning : function () {},

/**
 * @method getParent
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
getParent : function () {},

/**
 * @method setShouldCacheFaces
 * @param {bool}
 */
setShouldCacheFaces : function () {},

/**
 * @method setTargetLocation
 * @param {cocos3d::CC3Vector}
 */
setTargetLocation : function () {},

/**
 * @method asCameraTrackingWrapper
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
asCameraTrackingWrapper : function () {},

/**
 * @method transformAndDrawWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
transformAndDrawWithVisitor : function () {},

/**
 * @method setVisible
 * @param {bool}
 */
setVisible : function () {},

/**
 * @method animationBlendingWeightOnTrack
 * @return A value converted from C/C++ "float"
 * @param {unsigned int}
 */
animationBlendingWeightOnTrack : function () {},

/**
 * @method setSkeletalBoundingVolume
 * @param {cocos3d::CC3NodeBoundingVolume*}
 */
setSkeletalBoundingVolume : function () {},

/**
 * @method shouldShadowBackFaces
 * @return A value converted from C/C++ "bool"
 */
shouldShadowBackFaces : function () {},

/**
 * @method getGlobalForwardDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalForwardDirection : function () {},

/**
 * @method getBoundingBoxRelativeTo
 * @return A value converted from C/C++ "CC3Box"
 * @param {cocos3d::CC3Node*}
 */
getBoundingBoxRelativeTo : function () {},

/**
 * @method updateFromAnimationState
 */
updateFromAnimationState : function () {},

/**
 * @method setAnimationBlendingWeight
 * @param {float}
 * @param {unsigned int}
 */
setAnimationBlendingWeight : function () {},

/**
 * @method getShadowLagCount
 * @return A value converted from C/C++ "unsigned short"
 */
getShadowLagCount : function () {},

/**
 * @method setRotationAngle
 * @param {float}
 */
setRotationAngle : function () {},

/**
 * @method reattachBonesFrom
 * @param {cocos3d::CC3Node*}
 */
reattachBonesFrom : function () {},

/**
 * @method enableAllLocationAnimation
 */
enableAllLocationAnimation : function () {},

/**
 * @method isShadowVisible
 * @return A value converted from C/C++ "bool"
 */
isShadowVisible : function () {},

/**
 * @method isTrackingForBumpMapping
 * @return A value converted from C/C++ "bool"
 */
isTrackingForBumpMapping : function () {},

/**
 * @method flattenInto
 * @param {cocos2d::CCArray*}
 */
flattenInto : function () {},

/**
 * @method appendStructureDescriptionTo
 * @return A value converted from C/C++ "std::string"
 * @param {std::string}
 * @param {unsigned int}
 */
appendStructureDescriptionTo : function () {},

/**
 * @method shouldDrawBoundingVolume
 * @return A value converted from C/C++ "bool"
 */
shouldDrawBoundingVolume : function () {},

/**
 * @method setShouldIgnoreRayIntersection
 * @param {bool}
 */
setShouldIgnoreRayIntersection : function () {},

/**
 * @method setReferenceUpDirection
 * @param {cocos3d::CC3Vector}
 */
setReferenceUpDirection : function () {},

/**
 * @method retainVertexTextureCoordinates
 */
retainVertexTextureCoordinates : function () {},

/**
 * @method getGlobalRotation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalRotation : function () {},

/**
 * @method enableLocationAnimation
 */
enableLocationAnimation : function () {},

/**
 * @method isAnimationEnabledOnTrack
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 */
isAnimationEnabledOnTrack : function () {},

/**
 * @method setShouldCullBackFaces
 * @param {bool}
 */
setShouldCullBackFaces : function () {},

/**
 * @method pauseAllActions
 */
pauseAllActions : function () {},

/**
 * @method getSpecularColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getSpecularColor : function () {},

/**
 * @method getShadowVolumes
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getShadowVolumes : function () {},

/**
 * @method shouldDrawAllLocalContentWireframeBoxes
 * @return A value converted from C/C++ "bool"
 */
shouldDrawAllLocalContentWireframeBoxes : function () {},

/**
 * @method retainVertexPointSizes
 */
retainVertexPointSizes : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method setShadowExpansionLimitFactor
 * @param {float}
 */
setShadowExpansionLimitFactor : function () {},

/**
 * @method setShouldCullFrontFaces
 * @param {bool}
 */
setShouldCullFrontFaces : function () {},

/**
 * @method show
 */
show : function () {},

/**
 * @method disableAllAnimationOnTrack
 * @param {unsigned int}
 */
disableAllAnimationOnTrack : function () {},

/**
 * @method resetTagAllocation
 */
resetTagAllocation : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method getChildren
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getChildren : function () {},

/**
 * @method getSoftBodyNode
 * @return A value converted from C/C++ "cocos3d::CC3SoftBodyNode*"
 */
getSoftBodyNode : function () {},

/**
 * @method getNormalScalingMethod
 * @return A value converted from C/C++ "cocos3d::CC3NormalScaling"
 */
getNormalScalingMethod : function () {},

/**
 * @method applyTargetLocationAsLocal
 */
applyTargetLocationAsLocal : function () {},

/**
 * @method setPodParentIndex
 * @param {int}
 */
setPodParentIndex : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method addTexture
 * @param {cocos3d::CC3Texture*}
 */
addTexture : function () {},

/**
 * @method getDiffuseColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getDiffuseColor : function () {},

/**
 * @method setIsOpaque
 * @param {bool}
 */
setIsOpaque : function () {},

/**
 * @method setRotation
 * @param {cocos3d::CC3Vector}
 */
setRotation : function () {},

/**
 * @method shouldAddShadowVolumeEndCapsOnlyWhenNeeded
 * @return A value converted from C/C++ "bool"
 */
shouldAddShadowVolumeEndCapsOnlyWhenNeeded : function () {},

/**
 * @method applyLocalTransformsTo
 * @param {cocos3d::CC3Matrix*}
 */
applyLocalTransformsTo : function () {},

/**
 * @method addAnimationState
 * @param {cocos3d::CC3NodeAnimationState*}
 */
addAnimationState : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "ccColor3B"
 */
getColor : function () {},

/**
 * @method setLineSmoothingHint
 * @param {unsigned int}
 */
setLineSmoothingHint : function () {},

/**
 * @method setShouldLogIntersections
 * @param {bool}
 */
setShouldLogIntersections : function () {},

/**
 * @method getRenderStreamGroupMarker
 * @return A value converted from C/C++ "std::string"
 */
getRenderStreamGroupMarker : function () {},

/**
 * @method getRightDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getRightDirection : function () {},

/**
 * @method enableAllAnimation
 */
enableAllAnimation : function () {},

/**
 * @method shouldCullFrontFaces
 * @return A value converted from C/C++ "bool"
 */
shouldCullFrontFaces : function () {},

/**
 * @method hasLocalContent
 * @return A value converted from C/C++ "bool"
 */
hasLocalContent : function () {},

/**
 * @method addAnimation
 * @param {cocos3d::CC3NodeAnimation*}
 * @param {unsigned int}
 */
addAnimation : function () {},

/**
 * @method applyEffectNamedFromRez
 * @param {std::string}
 * @param {std::string}
 */
applyEffectNamedFromRez : function () {},

/**
 * @method remove
 */
remove : function () {},

/**
 * @method didRemoveDescendant
 * @param {cocos3d::CC3Node*}
 */
didRemoveDescendant : function () {},

/**
 * @method setShouldCastShadowsWhenInvisible
 * @param {bool}
 */
setShouldCastShadowsWhenInvisible : function () {},

/**
 * @method descendantDidModifySequencingCriteria
 * @param {cocos3d::CC3Node*}
 */
descendantDidModifySequencingCriteria : function () {},

/**
 * @method flipNormals
 */
flipNormals : function () {},

/**
 * @method shouldDrawAllBoundingVolumes
 * @return A value converted from C/C++ "bool"
 */
shouldDrawAllBoundingVolumes : function () {},

/**
 * @method isTouchable
 * @return A value converted from C/C++ "bool"
 */
isTouchable : function () {},

/**
 * @method isOpaque
 * @return A value converted from C/C++ "bool"
 */
isOpaque : function () {},

/**
 * @method getDepthFunction
 * @return A value converted from C/C++ "unsigned int"
 */
getDepthFunction : function () {},

/**
 * @method setShouldShadowFrontFaces
 * @param {bool}
 */
setShouldShadowFrontFaces : function () {},

/**
 * @method isUniformlyScaledGlobally
 * @return A value converted from C/C++ "bool"
 */
isUniformlyScaledGlobally : function () {},

/**
 * @method getGlobalLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalLocation : function () {},

/**
 * @method isBillboard
 * @return A value converted from C/C++ "bool"
 */
isBillboard : function () {},

/**
 * @method setForwardDirection
 * @param {cocos3d::CC3Vector}
 */
setForwardDirection : function () {},

/**
 * @method setShadowLagCount
 * @param {unsigned short}
 */
setShadowLagCount : function () {},

/**
 * @method getForwardDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getForwardDirection : function () {},

/**
 * @method shouldUseClockwiseFrontFaceWinding
 * @return A value converted from C/C++ "bool"
 */
shouldUseClockwiseFrontFaceWinding : function () {},

/**
 * @method getLocationOfGlobalRayIntesection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Ray}
 */
getLocationOfGlobalRayIntesection : function () {},

/**
 * @method nextTag
 * @return A value converted from C/C++ "unsigned int"
 */
nextTag : function () {},

/**
 * @method setTargettingConstraint
 * @param {cocos3d::CC3TargettingConstraint}
 */
setTargettingConstraint : function () {},

/**
 * @method shouldCullBackFaces
 * @return A value converted from C/C++ "bool"
 */
shouldCullBackFaces : function () {},

/**
 * @method setGlobalLightPosition
 * @param {cocos3d::CC3Vector4}
 */
setGlobalLightPosition : function () {},

/**
 * @method setShouldStopActionsWhenRemoved
 * @param {bool}
 */
setShouldStopActionsWhenRemoved : function () {},

/**
 * @method addAnimationFromFrameWithBaseTrackID
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {unsigned int}
 */
addAnimationFromFrameWithBaseTrackID : function () {},

/**
 * @method numberOfRunningActions
 * @return A value converted from C/C++ "int"
 */
numberOfRunningActions : function () {},

/**
 * @method releaseRedundantContent
 */
releaseRedundantContent : function () {},

/**
 * @method convertRotatorGlobalToLocal
 */
convertRotatorGlobalToLocal : function () {},

/**
 * @method getDisplayedColor
 * @return A value converted from C/C++ "ccColor3B"
 */
getDisplayedColor : function () {},

/**
 * @method getGlobalBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getGlobalBoundingBox : function () {},

/**
 * @method getShaderProgram
 * @return A value converted from C/C++ "cocos3d::CC3ShaderProgram*"
 */
getShaderProgram : function () {},

/**
 * @method doNotBufferVertexBoneIndices
 */
doNotBufferVertexBoneIndices : function () {},

/**
 * @method setShouldSmoothLines
 * @param {bool}
 */
setShouldSmoothLines : function () {},

/**
 * @method updateBoundingVolume
 */
updateBoundingVolume : function () {},

/**
 * @method doNotBufferVertexColors
 */
doNotBufferVertexColors : function () {},

/**
 * @method describeCurrentAnimationState
 * @return A value converted from C/C++ "std::string"
 */
describeCurrentAnimationState : function () {},

/**
 * @method getRotation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getRotation : function () {},

/**
 * @method isBasePODNode
 * @return A value converted from C/C++ "bool"
 */
isBasePODNode : function () {},

/**
 * @method touchEnableAll
 */
touchEnableAll : function () {},

/**
 * @method getInitialDescriptorColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getInitialDescriptorColor : function () {},

/**
 * @method getZOrder
 * @return A value converted from C/C++ "int"
 */
getZOrder : function () {},

/**
 * @method retainVertexColors
 */
retainVertexColors : function () {},

/**
 * @method addAnimationFromFrameWithTrackID
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {unsigned int}
 */
addAnimationFromFrameWithTrackID : function () {},

/**
 * @method addAndLocalizeChild
 * @param {cocos3d::CC3Node*}
 */
addAndLocalizeChild : function () {},

/**
 * @method getAmbientColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getAmbientColor : function () {},

/**
 * @method getGlobalRightDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalRightDirection : function () {},

/**
 * @method getGlobalLocationOfGlobalRayIntesection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Ray}
 */
getGlobalLocationOfGlobalRayIntesection : function () {},

/**
 * @method translateBy
 * @param {cocos3d::CC3Vector}
 */
translateBy : function () {},

/**
 * @method getDecalOffsetFactor
 * @return A value converted from C/C++ "float"
 */
getDecalOffsetFactor : function () {},

/**
 * @method doNotBufferVertexPointSizes
 */
doNotBufferVertexPointSizes : function () {},

/**
 * @method doesIntersectBoundingVolume
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3BoundingVolume*}
 */
doesIntersectBoundingVolume : function () {},

/**
 * @method animationTimeOnTrack
 * @return A value converted from C/C++ "float"
 * @param {unsigned int}
 */
animationTimeOnTrack : function () {},

/**
 * @method setCameraDistanceProduct
 * @param {float}
 */
setCameraDistanceProduct : function () {},

/**
 * @method nodeWasTransformed
 * @param {cocos3d::CC3Node*}
 */
nodeWasTransformed : function () {},

/**
 * @method updateDisplayedColor
 * @param {CCColorRef}
 */
updateDisplayedColor : function () {},

/**
 * @method applyTranslationTo
 * @param {cocos3d::CC3Matrix*}
 */
applyTranslationTo : function () {},

/**
 * @method shouldDisableDepthMask
 * @return A value converted from C/C++ "bool"
 */
shouldDisableDepthMask : function () {},

/**
 * @method getQuaternion
 * @return A value converted from C/C++ "CC3Quaternion"
 */
getQuaternion : function () {},

/**
 * @method enableAnimation
 */
enableAnimation : function () {},

/**
 * @method setProjectedLocation
 * @param {cocos3d::CC3Vector}
 */
setProjectedLocation : function () {},

/**
 * @method doNotBufferVertexTextureCoordinates
 */
doNotBufferVertexTextureCoordinates : function () {},

/**
 * @method setIsTrackingForBumpMapping
 * @param {bool}
 */
setIsTrackingForBumpMapping : function () {},

/**
 * @method updateTargetLocation
 */
updateTargetLocation : function () {},

/**
 * @method addTransformListener
 * @param {cocos3d::CC3NodeTransformListenerProtocol*}
 */
addTransformListener : function () {},

/**
 * @method flipTexturesVertically
 */
flipTexturesVertically : function () {},

/**
 * @method createBoundingVolumes
 */
createBoundingVolumes : function () {},

/**
 * @method getCameraDistanceProduct
 * @return A value converted from C/C++ "float"
 */
getCameraDistanceProduct : function () {},

/**
 * @method buildLocalTransformMatrix
 */
buildLocalTransformMatrix : function () {},

/**
 * @method ensureRigidSkeleton
 */
ensureRigidSkeleton : function () {},

/**
 * @method getActiveCamera
 * @return A value converted from C/C++ "cocos3d::CC3Camera*"
 */
getActiveCamera : function () {},

/**
 * @method setBlendFunc
 * @param {ccBlendFunc}
 */
setBlendFunc : function () {},

/**
 * @method enableAllQuaternionAnimation
 */
enableAllQuaternionAnimation : function () {},

/**
 * @method setShouldDrawBoundingVolume
 * @param {bool}
 */
setShouldDrawBoundingVolume : function () {},

/**
 * @method setShadowOffsetFactor
 * @param {float}
 */
setShadowOffsetFactor : function () {},

/**
 * @method isScene
 * @return A value converted from C/C++ "bool"
 */
isScene : function () {},

/**
 * @method stopAction
 * @param {cocos3d::CC3Action*}
 */
stopAction : function () {},

/**
 * @method getBoundingVolumePadding
 * @return A value converted from C/C++ "float"
 */
getBoundingVolumePadding : function () {},

/**
 * @method isUniformlyScaledLocally
 * @return A value converted from C/C++ "bool"
 */
isUniformlyScaledLocally : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 */
getTexture : function () {},

/**
 * @method getDescriptorName
 * @return A value converted from C/C++ "std::string"
 */
getDescriptorName : function () {},

/**
 * @method getGlobalUpDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalUpDirection : function () {},

/**
 * @method shouldCastShadows
 * @return A value converted from C/C++ "bool"
 */
shouldCastShadows : function () {},

/**
 * @method isTrackingTargetDirection
 * @return A value converted from C/C++ "bool"
 */
isTrackingTargetDirection : function () {},

/**
 * @method getEmissionColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getEmissionColor : function () {},

/**
 * @method getAnimationStateForAnimation
 * @return A value converted from C/C++ "cocos3d::CC3NodeAnimationState*"
 * @param {cocos3d::CC3NodeAnimation*}
 */
getAnimationStateForAnimation : function () {},

/**
 * @method retainVertexTangents
 */
retainVertexTangents : function () {},

/**
 * @method wasAdded
 */
wasAdded : function () {},

/**
 * @method setShouldAutoremoveWhenEmpty
 * @param {bool}
 */
setShouldAutoremoveWhenEmpty : function () {},

/**
 * @method setShouldApplyOpacityAndColorToMeshContent
 * @param {bool}
 */
setShouldApplyOpacityAndColorToMeshContent : function () {},

/**
 * @method getDirectionalRotator
 * @return A value converted from C/C++ "cocos3d::CC3DirectionalRotator*"
 */
getDirectionalRotator : function () {},

/**
 * @method shouldLogIntersections
 * @return A value converted from C/C++ "bool"
 */
shouldLogIntersections : function () {},

/**
 * @method getAnimationState
 * @return A value converted from C/C++ "cocos3d::CC3NodeAnimationState*"
 */
getAnimationState : function () {},

/**
 * @method addShadowVolumesForLight
 * @param {cocos3d::CC3Light*}
 */
addShadowVolumesForLight : function () {},

/**
 * @method establishAnimationFrameAt
 * @param {float}
 * @param {unsigned int}
 */
establishAnimationFrameAt : function () {},

/**
 * @method setBoundingVolumePadding
 * @param {float}
 */
setBoundingVolumePadding : function () {},

/**
 * @method updateBeforeChildren
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
updateBeforeChildren : function () {},

/**
 * @method setShininess
 * @param {float}
 */
setShininess : function () {},

/**
 * @method setLocalTransformMatrix
 * @param {cocos3d::CC3Matrix*}
 */
setLocalTransformMatrix : function () {},

/**
 * @method getAnimationStates
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getAnimationStates : function () {},

/**
 * @method setShouldDrawAllWireframeBoxes
 * @param {bool}
 */
setShouldDrawAllWireframeBoxes : function () {},

/**
 * @method removeChild
 * @param {cocos3d::CC3Node*}
 */
removeChild : function () {},

/**
 * @method getTargetLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetLocation : function () {},

/**
 * @method getScene
 * @return A value converted from C/C++ "cocos3d::CC3Scene*"
 */
getScene : function () {},

/**
 * @method shouldShadowFrontFaces
 * @return A value converted from C/C++ "bool"
 */
shouldShadowFrontFaces : function () {},

/**
 * @method setBoundingVolume
 * @param {cocos3d::CC3NodeBoundingVolume*}
 */
setBoundingVolume : function () {},

/**
 * @method buildGlobalTransformMatrix
 */
buildGlobalTransformMatrix : function () {},

/**
 * @method setTexture
 * @param {cocos3d::CC3Texture*}
 */
setTexture : function () {},

/**
 * @method shouldCacheFaces
 * @return A value converted from C/C++ "bool"
 */
shouldCacheFaces : function () {},

/**
 * @method shouldDrawAllWireframeBoxes
 * @return A value converted from C/C++ "bool"
 */
shouldDrawAllWireframeBoxes : function () {},

/**
 * @method processUpdateAfterTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
processUpdateAfterTransform : function () {},

/**
 * @method flatten
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
flatten : function () {},

/**
 * @method removeShaders
 */
removeShaders : function () {},

/**
 * @method shouldRotateToTargetLocation
 * @return A value converted from C/C++ "bool"
 */
shouldRotateToTargetLocation : function () {},

/**
 * @method getReflectivity
 * @return A value converted from C/C++ "float"
 */
getReflectivity : function () {},

/**
 * @method getShadowVolumeVertexOffsetFactor
 * @return A value converted from C/C++ "float"
 */
getShadowVolumeVertexOffsetFactor : function () {},

/**
 * @method applyRotatorTo
 * @param {cocos3d::CC3Matrix*}
 */
applyRotatorTo : function () {},

/**
 * @method retainVertexLocations
 */
retainVertexLocations : function () {},

/**
 * @method shouldIgnoreRayIntersection
 * @return A value converted from C/C++ "bool"
 */
shouldIgnoreRayIntersection : function () {},

/**
 * @method getPodTargetIndex
 * @return A value converted from C/C++ "int"
 */
getPodTargetIndex : function () {},

/**
 * @method getMutableRotator
 * @return A value converted from C/C++ "cocos3d::CC3MutableRotator*"
 */
getMutableRotator : function () {},

/**
 * @method asTrackingWrapper
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
asTrackingWrapper : function () {},

/**
 * @method getBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getBoundingBox : function () {},

/**
 * @method getGlobalScale
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalScale : function () {},

/**
 * @method setShouldCastShadows
 * @param {bool}
 */
setShouldCastShadows : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getShadowOffsetFactor
 * @return A value converted from C/C++ "float"
 */
getShadowOffsetFactor : function () {},

/**
 * @method retainVertexBoneWeights
 */
retainVertexBoneWeights : function () {},

/**
 * @method getDecalOffsetUnits
 * @return A value converted from C/C++ "float"
 */
getDecalOffsetUnits : function () {},

/**
 * @method getPodUserDataSize
 * @return A value converted from C/C++ "unsigned int"
 */
getPodUserDataSize : function () {},

/**
 * @method updateAfterChildren
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
updateAfterChildren : function () {},

/**
 * @method isVisible
 * @return A value converted from C/C++ "bool"
 */
isVisible : function () {},

/**
 * @method shouldUseSmoothShading
 * @return A value converted from C/C++ "bool"
 */
shouldUseSmoothShading : function () {},

/**
 * @method setShaderProgram
 * @param {cocos3d::CC3ShaderProgram*}
 */
setShaderProgram : function () {},

/**
 * @method setAmbientColor
 * @param {cocos2d::ccColor4F}
 */
setAmbientColor : function () {},

/**
 * @method setShouldUseSmoothShading
 * @param {bool}
 */
setShouldUseSmoothShading : function () {},

/**
 * @method getShininess
 * @return A value converted from C/C++ "float"
 */
getShininess : function () {},

/**
 * @method buildGlobalTransformMatrixInverted
 */
buildGlobalTransformMatrixInverted : function () {},

/**
 * @method getInitialDirectionMarkerColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getInitialDirectionMarkerColor : function () {},

/**
 * @method deleteBoundingVolumes
 */
deleteBoundingVolumes : function () {},

/**
 * @method stopAllActions
 */
stopAllActions : function () {},

/**
 * @method disableScaleAnimation
 */
disableScaleAnimation : function () {},

/**
 * @method setShadowOffsetUnits
 * @param {float}
 */
setShadowOffsetUnits : function () {},

/**
 * @method getUpDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getUpDirection : function () {},

/**
 * @method markTransformDirty
 */
markTransformDirty : function () {},

/**
 * @method setQuaternion
 * @param {cocos3d::CC3Quaternion}
 */
setQuaternion : function () {},

/**
 * @method getActionByTag
 * @return A value converted from C/C++ "cocos2d::CCAction*"
 * @param {unsigned int}
 */
getActionByTag : function () {},

/**
 * @method checkDrawingOrder
 */
checkDrawingOrder : function () {},

/**
 * @method addChildNow
 * @param {cocos3d::CC3Node*}
 */
addChildNow : function () {},

/**
 * @method disableAllAnimation
 */
disableAllAnimation : function () {},

/**
 * @method doesIntersectGlobalRay
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Ray}
 */
doesIntersectGlobalRay : function () {},

/**
 * @method getBoundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3NodeBoundingVolume*"
 */
getBoundingVolume : function () {},

/**
 * @method processUpdateBeforeTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
processUpdateBeforeTransform : function () {},

/**
 * @method getGlobalRotationMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getGlobalRotationMatrix : function () {},

/**
 * @method setShouldDisableDepthTest
 * @param {bool}
 */
setShouldDisableDepthTest : function () {},

/**
 * @method shouldLogIntersectionMisses
 * @return A value converted from C/C++ "bool"
 */
shouldLogIntersectionMisses : function () {},

/**
 * @method addAxesDirectionMarkers
 */
addAxesDirectionMarkers : function () {},

/**
 * @method retainVertexContent
 */
retainVertexContent : function () {},

/**
 * @method getShadowExpansionLimitFactor
 * @return A value converted from C/C++ "float"
 */
getShadowExpansionLimitFactor : function () {},

/**
 * @method setShouldDrawDescriptor
 * @param {bool}
 */
setShouldDrawDescriptor : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Node*}
 */
populateFrom : function () {},

/**
 * @method getWireframeBoxName
 * @return A value converted from C/C++ "std::string"
 */
getWireframeBoxName : function () {},

/**
 * @method prewarmForShadowVolumes
 */
prewarmForShadowVolumes : function () {},

/**
 * @method setScale
 * @param {cocos3d::CC3Vector}
 */
setScale : function () {},

/**
 * @method hasTarget
 * @return A value converted from C/C++ "bool"
 */
hasTarget : function () {},

/**
 * @method getUniformScale
 * @return A value converted from C/C++ "float"
 */
getUniformScale : function () {},

/**
 * @method setAnimation
 * @param {cocos3d::CC3NodeAnimation*}
 */
setAnimation : function () {},

/**
 * @method containsAnimationOnTrack
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 */
containsAnimationOnTrack : function () {},

/**
 * @method removeAnimation
 * @param {cocos3d::CC3NodeAnimation*}
 */
removeAnimation : function () {},

/**
 * @method shouldSmoothLines
 * @return A value converted from C/C++ "bool"
 */
shouldSmoothLines : function () {},

/**
 * @method removeAnimationTrack
 * @param {unsigned int}
 */
removeAnimationTrack : function () {},

/**
 * @method createSkinnedBoundingVolumes
 */
createSkinnedBoundingVolumes : function () {},

/**
 * @method setRotationAxis
 * @param {cocos3d::CC3Vector}
 */
setRotationAxis : function () {},

/**
 * @method getLocalTransformMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getLocalTransformMatrix : function () {},

/**
 * @method retainVertexNormals
 */
retainVertexNormals : function () {},

/**
 * @method createGLBuffers
 */
createGLBuffers : function () {},

/**
 * @method enableAllScaleAnimation
 */
enableAllScaleAnimation : function () {},

/**
 * @method setShouldDrawInClipSpace
 * @param {bool}
 */
setShouldDrawInClipSpace : function () {},

/**
 * @method rotateBy
 * @param {cocos3d::CC3Vector}
 */
rotateBy : function () {},

/**
 * @method getGlobalTransformMatrixInverted
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getGlobalTransformMatrixInverted : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method shouldUseLighting
 * @return A value converted from C/C++ "bool"
 */
shouldUseLighting : function () {},

/**
 * @method didAddDescendant
 * @param {cocos3d::CC3Node*}
 */
didAddDescendant : function () {},

/**
 * @method checkCameraTarget
 */
checkCameraTarget : function () {},

/**
 * @method getGlobalLightPosition
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 */
getGlobalLightPosition : function () {},

/**
 * @method shouldApplyOpacityAndColorToMeshContent
 * @return A value converted from C/C++ "bool"
 */
shouldApplyOpacityAndColorToMeshContent : function () {},

/**
 * @method setRotator
 * @param {cocos3d::CC3Rotator*}
 */
setRotator : function () {},

/**
 * @method linkToPODNodes
 * @param {cocos2d::CCArray*}
 */
linkToPODNodes : function () {},

/**
 * @method setShouldDrawAllBoundingVolumes
 * @param {bool}
 */
setShouldDrawAllBoundingVolumes : function () {},

/**
 * @method addDirectionMarker
 */
addDirectionMarker : function () {},

/**
 * @method isShadowVolume
 * @return A value converted from C/C++ "bool"
 */
isShadowVolume : function () {},

/**
 * @method doNotBufferVertexContent
 */
doNotBufferVertexContent : function () {},

/**
 * @method containsAnimation
 * @return A value converted from C/C++ "bool"
 */
containsAnimation : function () {},

/**
 * @method asBumpMapLightTrackingWrapper
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
asBumpMapLightTrackingWrapper : function () {},

/**
 * @method hasSoftBodyContent
 * @return A value converted from C/C++ "bool"
 */
hasSoftBodyContent : function () {},

/**
 * @method shouldUseFixedBoundingVolume
 * @return A value converted from C/C++ "bool"
 */
shouldUseFixedBoundingVolume : function () {},

/**
 * @method getInitialWireframeBoxColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getInitialWireframeBoxColor : function () {},

/**
 * @method nodesIntersectedByGlobalRay
 * @return A value converted from C/C++ "cocos3d::CC3NodePuncturingVisitor*"
 * @param {cocos3d::CC3Ray}
 */
nodesIntersectedByGlobalRay : function () {},

/**
 * @method setShouldInheritTouchability
 * @param {bool}
 */
setShouldInheritTouchability : function () {},

/**
 * @method node
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
node : function () {},

/**
 * @method setDirectionMarkerColor
 * @param {cocos2d::ccColor4F}
 */
setDirectionMarkerColor : function () {},

/**
 * @method setDescriptorFontSize
 * @param {float}
 */
setDescriptorFontSize : function () {},

/**
 * @method descriptorFontSize
 * @return A value converted from C/C++ "float"
 */
descriptorFontSize : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 * @param {std::string}
 */
nodeWithName : function () {},

/**
 * @method getWireframeBoxColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getWireframeBoxColor : function () {},

/**
 * @method setWireframeBoxColor
 * @param {cocos2d::ccColor4F}
 */
setWireframeBoxColor : function () {},

/**
 * @method nodeAtIndex
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
nodeAtIndex : function () {},

/**
 * @method getDirectionMarkerColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getDirectionMarkerColor : function () {},

/**
 * @method CC3Node
 * @constructor
 */
CC3Node : function () {},

};

/**
 * @class CC3BoundingVolume
 */
cc3.CC3BoundingVolume = {

/**
 * @method populateFrom
 * @param {cocos3d::CC3BoundingVolume*}
 */
populateFrom : function () {},

/**
 * @method isInFrontOfPlane
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Plane}
 */
isInFrontOfPlane : function () {},

/**
 * @method getPlanes
 * @return A value converted from C/C++ "CC3Plane*"
 */
getPlanes : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method markDirty
 */
markDirty : function () {},

/**
 * @method doesIntersectRay
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Ray}
 */
doesIntersectRay : function () {},

/**
 * @method shouldIgnoreRayIntersection
 * @return A value converted from C/C++ "bool"
 */
shouldIgnoreRayIntersection : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method doesIntersectLocation
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Vector}
 */
doesIntersectLocation : function () {},

/**
 * @method doesIntersect
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3BoundingVolume*}
 */
doesIntersect : function () {},

/**
 * @method getGlobalLocationOfGlobalRayIntesection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Ray}
 */
getGlobalLocationOfGlobalRayIntesection : function () {},

/**
 * @method setShouldLogIntersections
 * @param {bool}
 */
setShouldLogIntersections : function () {},

/**
 * @method getPlaneCount
 * @return A value converted from C/C++ "unsigned int"
 */
getPlaneCount : function () {},

/**
 * @method isDirty
 * @return A value converted from C/C++ "bool"
 */
isDirty : function () {},

/**
 * @method setShouldIgnoreRayIntersection
 * @param {bool}
 */
setShouldIgnoreRayIntersection : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method logIntersection
 * @param {bool}
 * @param {cocos3d::CC3BoundingVolume*}
 */
logIntersection : function () {},

/**
 * @method shouldLogIntersections
 * @return A value converted from C/C++ "bool"
 */
shouldLogIntersections : function () {},

/**
 * @method updateIfNeeded
 */
updateIfNeeded : function () {},

/**
 * @method fullDescription
 * @return A value converted from C/C++ "std::string"
 */
fullDescription : function () {},

/**
 * @method shouldLogIntersectionMisses
 * @return A value converted from C/C++ "bool"
 */
shouldLogIntersectionMisses : function () {},

/**
 * @method setShouldLogIntersectionMisses
 * @param {bool}
 */
setShouldLogIntersectionMisses : function () {},

/**
 * @method boundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3BoundingVolume*"
 */
boundingVolume : function () {},

/**
 * @method CC3BoundingVolume
 * @constructor
 */
CC3BoundingVolume : function () {},

};

/**
 * @class CC3Camera
 */
cc3.CC3Camera = {

/**
 * @method setIsUsingParallelProjection
 * @param {bool}
 */
setIsUsingParallelProjection : function () {},

/**
 * @method setScale
 * @param {cocos3d::CC3Vector}
 */
setScale : function () {},

/**
 * @method shouldReverseForwardDirection
 * @return A value converted from C/C++ "bool"
 */
shouldReverseForwardDirection : function () {},

/**
 * @method getFovRatios
 * @return A value converted from C/C++ "cocos2d::CCSize"
 */
getFovRatios : function () {},

/**
 * @method getFieldOfView
 * @return A value converted from C/C++ "float"
 */
getFieldOfView : function () {},

/**
 * @method getOrientedFieldOfViewAspect
 * @return A value converted from C/C++ "cocos2d::CCPoint"
 */
getOrientedFieldOfViewAspect : function () {},

/**
 * @method closeViewWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
closeViewWithVisitor : function () {},

/**
 * @method ensureAtRootAncestor
 */
ensureAtRootAncestor : function () {},

/**
 * @method getFarClippingDistance
 * @return A value converted from C/C++ "float"
 */
getFarClippingDistance : function () {},

/**
 * @method setFrustum
 * @param {cocos3d::CC3Frustum*}
 */
setFrustum : function () {},

/**
 * @method closeProjectionWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
closeProjectionWithVisitor : function () {},

/**
 * @method getProjectionMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getProjectionMatrix : function () {},

/**
 * @method setFieldOfView
 * @param {float}
 */
setFieldOfView : function () {},

/**
 * @method shouldClipToViewport
 * @return A value converted from C/C++ "bool"
 */
shouldClipToViewport : function () {},

/**
 * @method loadViewMatrixWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
loadViewMatrixWithVisitor : function () {},

/**
 * @method setViewport
 * @param {cocos3d::CC3Viewport}
 */
setViewport : function () {},

/**
 * @method getNearClippingDistance
 * @return A value converted from C/C++ "float"
 */
getNearClippingDistance : function () {},

/**
 * @method getGlobalScale
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalScale : function () {},

/**
 * @method loadProjectionMatrixWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
loadProjectionMatrixWithVisitor : function () {},

/**
 * @method setFarClippingDistance
 * @param {float}
 */
setFarClippingDistance : function () {},

/**
 * @method setShouldClipToViewport
 * @param {bool}
 */
setShouldClipToViewport : function () {},

/**
 * @method isOpen
 * @return A value converted from C/C++ "bool"
 */
isOpen : function () {},

/**
 * @method getFieldOfViewOrientation
 * @return A value converted from C/C++ "cocos3d::CC3FieldOfViewOrientation"
 */
getFieldOfViewOrientation : function () {},

/**
 * @method setHasInfiniteDepthOfField
 * @param {bool}
 */
setHasInfiniteDepthOfField : function () {},

/**
 * @method applyScalingTo
 * @param {cocos3d::CC3Matrix*}
 */
applyScalingTo : function () {},

/**
 * @method openViewWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
openViewWithVisitor : function () {},

/**
 * @method openWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
openWithVisitor : function () {},

/**
 * @method closeWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
closeWithVisitor : function () {},

/**
 * @method isUsingParallelProjection
 * @return A value converted from C/C++ "bool"
 */
isUsingParallelProjection : function () {},

/**
 * @method markTransformDirty
 */
markTransformDirty : function () {},

/**
 * @method setFieldOfViewOrientation
 * @param {cocos3d::CC3FieldOfViewOrientation}
 */
setFieldOfViewOrientation : function () {},

/**
 * @method projectNode
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {cocos3d::CC3Node*}
 */
projectNode : function () {},

/**
 * @method getFieldOfViewAspectOrientation
 * @return A value converted from C/C++ "cocos3d::CC3UIInterfaceOrientation"
 */
getFieldOfViewAspectOrientation : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method setFieldOfViewAspectOrientation
 * @param {cocos3d::CC3UIInterfaceOrientation}
 */
setFieldOfViewAspectOrientation : function () {},

/**
 * @method hasInfiniteDepthOfField
 * @return A value converted from C/C++ "bool"
 */
hasInfiniteDepthOfField : function () {},

/**
 * @method isCamera
 * @return A value converted from C/C++ "bool"
 */
isCamera : function () {},

/**
 * @method markProjectionDirty
 */
markProjectionDirty : function () {},

/**
 * @method getViewMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getViewMatrix : function () {},

/**
 * @method setNearClippingDistance
 * @param {float}
 */
setNearClippingDistance : function () {},

/**
 * @method fullDescription
 * @return A value converted from C/C++ "std::string"
 */
fullDescription : function () {},

/**
 * @method buildProjection
 */
buildProjection : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Camera*}
 */
populateFrom : function () {},

/**
 * @method getViewport
 * @return A value converted from C/C++ "CC3Viewport"
 */
getViewport : function () {},

/**
 * @method openProjectionWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
openProjectionWithVisitor : function () {},

/**
 * @method ensureSceneUpdated
 * @param {bool}
 */
ensureSceneUpdated : function () {},

/**
 * @method getEffectiveFieldOfView
 * @return A value converted from C/C++ "float"
 */
getEffectiveFieldOfView : function () {},

/**
 * @method getFrustum
 * @return A value converted from C/C++ "cocos3d::CC3Frustum*"
 */
getFrustum : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3Camera*"
 * @param {std::string}
 */
nodeWithName : function () {},

/**
 * @method CC3Camera
 * @constructor
 */
CC3Camera : function () {},

};

/**
 * @class CC3Frustum
 */
cc3.CC3Frustum = {

/**
 * @method getTopPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getTopPlane : function () {},

/**
 * @method setBottom
 * @param {float}
 */
setBottom : function () {},

/**
 * @method fullDescription
 * @return A value converted from C/C++ "std::string"
 */
fullDescription : function () {},

/**
 * @method getRight
 * @return A value converted from C/C++ "float"
 */
getRight : function () {},

/**
 * @method setTop
 * @param {float}
 */
setTop : function () {},

/**
 * @method getPlanes
 * @return A value converted from C/C++ "CC3Plane*"
 */
getPlanes : function () {},

/**
 * @method setCamera
 * @param {cocos3d::CC3Camera*}
 */
setCamera : function () {},

/**
 * @method setIsUsingParallelProjection
 * @param {bool}
 */
setIsUsingParallelProjection : function () {},

/**
 * @method getFarBottomRight
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getFarBottomRight : function () {},

/**
 * @method getPlaneCount
 * @return A value converted from C/C++ "unsigned int"
 */
getPlaneCount : function () {},

/**
 * @method getFarTopRight
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getFarTopRight : function () {},

/**
 * @method getRightPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getRightPlane : function () {},

/**
 * @method getLeft
 * @return A value converted from C/C++ "float"
 */
getLeft : function () {},

/**
 * @method setFar
 * @param {float}
 */
setFar : function () {},

/**
 * @method getNearBottomLeft
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getNearBottomLeft : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getLeftPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getLeftPlane : function () {},

/**
 * @method populateRight
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 */
populateRight : function () {},

/**
 * @method getFarTopLeft
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getFarTopLeft : function () {},

/**
 * @method getTop
 * @return A value converted from C/C++ "float"
 */
getTop : function () {},

/**
 * @method getBottom
 * @return A value converted from C/C++ "float"
 */
getBottom : function () {},

/**
 * @method getFarBottomLeft
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getFarBottomLeft : function () {},

/**
 * @method getFar
 * @return A value converted from C/C++ "float"
 */
getFar : function () {},

/**
 * @method setNear
 * @param {float}
 */
setNear : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method getInfiniteProjectionMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getInfiniteProjectionMatrix : function () {},

/**
 * @method setLeft
 * @param {float}
 */
setLeft : function () {},

/**
 * @method getNearBottomRight
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getNearBottomRight : function () {},

/**
 * @method isUsingParallelProjection
 * @return A value converted from C/C++ "bool"
 */
isUsingParallelProjection : function () {},

/**
 * @method getBottomPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getBottomPlane : function () {},

/**
 * @method getNearPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getNearPlane : function () {},

/**
 * @method getNear
 * @return A value converted from C/C++ "float"
 */
getNear : function () {},

/**
 * @method setRight
 * @param {float}
 */
setRight : function () {},

/**
 * @method getCamera
 * @return A value converted from C/C++ "cocos3d::CC3Camera*"
 */
getCamera : function () {},

/**
 * @method getFiniteProjectionMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getFiniteProjectionMatrix : function () {},

/**
 * @method getNearTopLeft
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getNearTopLeft : function () {},

/**
 * @method getNearTopRight
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getNearTopRight : function () {},

/**
 * @method getFarPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getFarPlane : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method frustum
 * @return A value converted from C/C++ "cocos3d::CC3Frustum*"
 */
frustum : function () {},

/**
 * @method CC3Frustum
 * @constructor
 */
CC3Frustum : function () {},

};

/**
 * @class CC3EnvironmentNode
 */
cc3.CC3EnvironmentNode = {

/**
 * @method setTexture
 * @param {cocos3d::CC3Texture*}
 */
setTexture : function () {},

/**
 * @method initWithTexture
 * @param {cocos3d::CC3Texture*}
 */
initWithTexture : function () {},

/**
 * @method isLightProbe
 * @return A value converted from C/C++ "bool"
 */
isLightProbe : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 */
getTexture : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3EnvironmentNode*"
 * @param {std::string}
 * @param {cocos3d::CC3Texture*}
 */
nodeWithName : function () {},

/**
 * @method nodeWithTexture
 * @return A value converted from C/C++ "cocos3d::CC3EnvironmentNode*"
 * @param {cocos3d::CC3Texture*}
 */
nodeWithTexture : function () {},

/**
 * @method CC3EnvironmentNode
 * @constructor
 */
CC3EnvironmentNode : function () {},

};

/**
 * @class CC3LightProbe
 */
cc3.CC3LightProbe = {

/**
 * @method getDiffuseColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getDiffuseColor : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method setDiffuseColor
 * @param {cocos2d::ccColor4F}
 */
setDiffuseColor : function () {},

/**
 * @method isLightProbe
 * @return A value converted from C/C++ "bool"
 */
isLightProbe : function () {},

/**
 * @method nodeWithTexture
 * @return A value converted from C/C++ "cocos3d::CC3LightProbe*"
 * @param {cocos3d::CC3Texture*}
 */
nodeWithTexture : function () {},

};

/**
 * @class CC3Light
 */
cc3.CC3Light = {

/**
 * @method setDiffuseColor
 * @param {cocos2d::ccColor4F}
 */
setDiffuseColor : function () {},

/**
 * @method hasShadows
 * @return A value converted from C/C++ "bool"
 */
hasShadows : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method removeShadow
 * @param {cocos3d::CC3ShadowVolumeMeshNode*}
 */
removeShadow : function () {},

/**
 * @method shouldReverseForwardDirection
 * @return A value converted from C/C++ "bool"
 */
shouldReverseForwardDirection : function () {},

/**
 * @method updateShadows
 */
updateShadows : function () {},

/**
 * @method applyPositionWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyPositionWithVisitor : function () {},

/**
 * @method configureStencilParameters
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureStencilParameters : function () {},

/**
 * @method getShadowCastingVolume
 * @return A value converted from C/C++ "cocos3d::CC3ShadowCastingVolume*"
 */
getShadowCastingVolume : function () {},

/**
 * @method setAmbientColor
 * @param {cocos2d::ccColor4F}
 */
setAmbientColor : function () {},

/**
 * @method isLight
 * @return A value converted from C/C++ "bool"
 */
isLight : function () {},

/**
 * @method setCameraShadowVolume
 * @param {cocos3d::CC3CameraShadowVolume*}
 */
setCameraShadowVolume : function () {},

/**
 * @method addShadow
 * @param {cocos3d::CC3ShadowVolumeMeshNode*}
 */
addShadow : function () {},

/**
 * @method applyColorWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyColorWithVisitor : function () {},

/**
 * @method getAttenuation
 * @return A value converted from C/C++ "CC3AttenuationCoefficients"
 */
getAttenuation : function () {},

/**
 * @method setShadowIntensityFactor
 * @param {float}
 */
setShadowIntensityFactor : function () {},

/**
 * @method getStencilledShadowPainter
 * @return A value converted from C/C++ "cocos3d::CC3StencilledShadowPainterNode*"
 */
getStencilledShadowPainter : function () {},

/**
 * @method getGlobalHomogeneousPosition
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 */
getGlobalHomogeneousPosition : function () {},

/**
 * @method getCameraShadowVolume
 * @return A value converted from C/C++ "cocos3d::CC3CameraShadowVolume*"
 */
getCameraShadowVolume : function () {},

/**
 * @method checkShadowCastingVolume
 */
checkShadowCastingVolume : function () {},

/**
 * @method paintStenciledShadowsWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
paintStenciledShadowsWithVisitor : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Light*}
 */
populateFrom : function () {},

/**
 * @method getSpotExponent
 * @return A value converted from C/C++ "float"
 */
getSpotExponent : function () {},

/**
 * @method setShouldCastShadowsWhenInvisible
 * @param {bool}
 */
setShouldCastShadowsWhenInvisible : function () {},

/**
 * @method applyAttenuationWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyAttenuationWithVisitor : function () {},

/**
 * @method turnOnWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
turnOnWithVisitor : function () {},

/**
 * @method getShadowIntensityFactor
 * @return A value converted from C/C++ "float"
 */
getShadowIntensityFactor : function () {},

/**
 * @method getDiffuseColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getDiffuseColor : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method addShadowNow
 * @param {cocos3d::CC3ShadowVolumeMeshNode*}
 */
addShadowNow : function () {},

/**
 * @method cleanupShadows
 */
cleanupShadows : function () {},

/**
 * @method setIsDirectionalOnly
 * @param {bool}
 */
setIsDirectionalOnly : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getColor : function () {},

/**
 * @method turnOffWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
turnOffWithVisitor : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method shouldCopyLightIndex
 * @return A value converted from C/C++ "bool"
 */
shouldCopyLightIndex : function () {},

/**
 * @method markTransformDirty
 */
markTransformDirty : function () {},

/**
 * @method setShadowCastingVolume
 * @param {cocos3d::CC3ShadowCastingVolume*}
 */
setShadowCastingVolume : function () {},

/**
 * @method getAmbientColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getAmbientColor : function () {},

/**
 * @method getGlobalScale
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalScale : function () {},

/**
 * @method getLightIndex
 * @return A value converted from C/C++ "unsigned int"
 */
getLightIndex : function () {},

/**
 * @method drawShadowsWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawShadowsWithVisitor : function () {},

/**
 * @method nextLightIndex
 * @return A value converted from C/C++ "unsigned int"
 */
nextLightIndex : function () {},

/**
 * @method isDirectionalOnly
 * @return A value converted from C/C++ "bool"
 */
isDirectionalOnly : function () {},

/**
 * @method addShadowFromBackgroundThread
 * @param {cocos3d::CC3ShadowVolumeMeshNode*}
 */
addShadowFromBackgroundThread : function () {},

/**
 * @method returnLightIndex
 * @param {unsigned int}
 */
returnLightIndex : function () {},

/**
 * @method applyScalingTo
 * @param {cocos3d::CC3Matrix*}
 */
applyScalingTo : function () {},

/**
 * @method setShouldCopyLightIndex
 * @param {bool}
 */
setShouldCopyLightIndex : function () {},

/**
 * @method setSpotExponent
 * @param {float}
 */
setSpotExponent : function () {},

/**
 * @method getSpotCutoffAngle
 * @return A value converted from C/C++ "float"
 */
getSpotCutoffAngle : function () {},

/**
 * @method setColor
 * @param {cocos3d::CCColorRef}
 */
setColor : function () {},

/**
 * @method initWithLightIndex
 * @param {unsigned int}
 */
initWithLightIndex : function () {},

/**
 * @method checkCameraShadowVolume
 */
checkCameraShadowVolume : function () {},

/**
 * @method setAttenuation
 * @param {cocos3d::CC3AttenuationCoefficients}
 */
setAttenuation : function () {},

/**
 * @method getSpecularColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getSpecularColor : function () {},

/**
 * @method setSpecularColor
 * @param {cocos2d::ccColor4F}
 */
setSpecularColor : function () {},

/**
 * @method updateRelativeIntensityFrom
 * @param {cocos2d::ccColor4F}
 */
updateRelativeIntensityFrom : function () {},

/**
 * @method shouldCastShadowsWhenInvisible
 * @return A value converted from C/C++ "bool"
 */
shouldCastShadowsWhenInvisible : function () {},

/**
 * @method setSpotCutoffAngle
 * @param {float}
 */
setSpotCutoffAngle : function () {},

/**
 * @method cleanupStencilParameters
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
cleanupStencilParameters : function () {},

/**
 * @method checkStencilledShadowPainter
 */
checkStencilledShadowPainter : function () {},

/**
 * @method setStencilledShadowPainter
 * @param {cocos3d::CC3StencilledShadowPainterNode*}
 */
setStencilledShadowPainter : function () {},

/**
 * @method setVisible
 * @param {bool}
 */
setVisible : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method applyDirectionWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyDirectionWithVisitor : function () {},

/**
 * @method lightWithName
 * @return A value converted from C/C++ "cocos3d::CC3Light*"
 * @param {std::string}
 * @param {unsigned int}
 */
lightWithName : function () {},

/**
 * @method getLightPoolStartIndex
 * @return A value converted from C/C++ "unsigned int"
 */
getLightPoolStartIndex : function () {},

/**
 * @method setLightPoolStartIndex
 * @param {unsigned int}
 */
setLightPoolStartIndex : function () {},

/**
 * @method getLightCount
 * @return A value converted from C/C++ "unsigned int"
 */
getLightCount : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3Light*"
 * @param {std::string}
 */
nodeWithName : function () {},

/**
 * @method nodeWithLightIndex
 * @return A value converted from C/C++ "cocos3d::CC3Light*"
 * @param {unsigned int}
 */
nodeWithLightIndex : function () {},

/**
 * @method lightWithLightIndex
 * @return A value converted from C/C++ "cocos3d::CC3Light*"
 * @param {unsigned int}
 */
lightWithLightIndex : function () {},

/**
 * @method disableReservedLightsWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
disableReservedLightsWithVisitor : function () {},

/**
 * @method CC3Light
 * @constructor
 */
CC3Light : function () {},

};

/**
 * @class CC3LightCameraBridgeVolume
 */
cc3.CC3LightCameraBridgeVolume = {

/**
 * @method getLightPosition
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLightPosition : function () {},

/**
 * @method setLight
 * @param {cocos3d::CC3Light*}
 */
setLight : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3LightCameraBridgeVolume*}
 */
populateFrom : function () {},

/**
 * @method getLight
 * @return A value converted from C/C++ "cocos3d::CC3Light*"
 */
getLight : function () {},

/**
 * @method isLightInFrontOfPlane
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Plane}
 */
isLightInFrontOfPlane : function () {},

/**
 * @method nodeWasDestroyed
 * @param {cocos3d::CC3Node*}
 */
nodeWasDestroyed : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method nodeWasTransformed
 * @param {cocos3d::CC3Node*}
 */
nodeWasTransformed : function () {},

/**
 * @method areAllVerticesInFrontOf
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Plane}
 */
areAllVerticesInFrontOf : function () {},

/**
 * @method CC3LightCameraBridgeVolume
 * @constructor
 */
CC3LightCameraBridgeVolume : function () {},

};

/**
 * @class CC3ShadowCastingVolume
 */
cc3.CC3ShadowCastingVolume = {

/**
 * @method addPlane
 * @param {cocos3d::CC3Plane}
 */
addPlane : function () {},

/**
 * @method buildPlanes
 */
buildPlanes : function () {},

/**
 * @method getPlaneCount
 * @return A value converted from C/C++ "unsigned int"
 */
getPlaneCount : function () {},

/**
 * @method checkPlaneEdge
 * @param {cocos3d::CC3Plane}
 * @param {cocos3d::CC3Vector}
 * @param {cocos3d::CC3Vector}
 */
checkPlaneEdge : function () {},

/**
 * @method checkPlane
 * @param {cocos3d::CC3Plane}
 * @param {cocos3d::CC3Plane}
 * @param {cocos3d::CC3Vector}
 * @param {cocos3d::CC3Plane}
 * @param {cocos3d::CC3Vector}
 * @param {cocos3d::CC3Plane}
 * @param {cocos3d::CC3Vector}
 * @param {cocos3d::CC3Plane}
 * @param {cocos3d::CC3Vector}
 */
checkPlane : function () {},

/**
 * @method addUniqueVertex
 * @param {cocos3d::CC3Vector}
 */
addUniqueVertex : function () {},

/**
 * @method getPlanes
 * @return A value converted from C/C++ "CC3Plane*"
 */
getPlanes : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method boundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3ShadowCastingVolume*"
 */
boundingVolume : function () {},

/**
 * @method CC3ShadowCastingVolume
 * @constructor
 */
CC3ShadowCastingVolume : function () {},

};

/**
 * @class CC3CameraShadowVolume
 */
cc3.CC3CameraShadowVolume = {

/**
 * @method getTopRight
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTopRight : function () {},

/**
 * @method getRightPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getRightPlane : function () {},

/**
 * @method getTopPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getTopPlane : function () {},

/**
 * @method getBottomLeft
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getBottomLeft : function () {},

/**
 * @method buildPlanes
 */
buildPlanes : function () {},

/**
 * @method getBottomPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getBottomPlane : function () {},

/**
 * @method getNearPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getNearPlane : function () {},

/**
 * @method buildVolume
 */
buildVolume : function () {},

/**
 * @method getBottomRight
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getBottomRight : function () {},

/**
 * @method getLeftPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getLeftPlane : function () {},

/**
 * @method getFarPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getFarPlane : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method getPlaneCount
 * @return A value converted from C/C++ "unsigned int"
 */
getPlaneCount : function () {},

/**
 * @method getTopLeft
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTopLeft : function () {},

/**
 * @method getPlanes
 * @return A value converted from C/C++ "CC3Plane*"
 */
getPlanes : function () {},

/**
 * @method boundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3CameraShadowVolume*"
 * @param {cocos3d::CC3Light*}
 */
boundingVolume : function () {},

};

/**
 * @class CC3LocalContentNode
 */
cc3.CC3LocalContentNode = {

/**
 * @method populateFrom
 * @param {cocos3d::CC3LocalContentNode*}
 */
populateFrom : function () {},

/**
 * @method setShouldDrawAllLocalContentWireframeBoxes
 * @param {bool}
 */
setShouldDrawAllLocalContentWireframeBoxes : function () {},

/**
 * @method checkDrawingOrder
 */
checkDrawingOrder : function () {},

/**
 * @method getBoundingBoxRelativeTo
 * @return A value converted from C/C++ "CC3Box"
 * @param {cocos3d::CC3Node*}
 */
getBoundingBoxRelativeTo : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method getZOrder
 * @return A value converted from C/C++ "int"
 */
getZOrder : function () {},

/**
 * @method getLocalContentBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getLocalContentBoundingBox : function () {},

/**
 * @method getLocalContentCenterOfGeometry
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLocalContentCenterOfGeometry : function () {},

/**
 * @method getLocalContentWireframeBoxName
 * @return A value converted from C/C++ "std::string"
 */
getLocalContentWireframeBoxName : function () {},

/**
 * @method getBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getBoundingBox : function () {},

/**
 * @method setZOrder
 * @param {int}
 */
setZOrder : function () {},

/**
 * @method markTransformDirty
 */
markTransformDirty : function () {},

/**
 * @method shouldDrawLocalContentWireframeBox
 * @return A value converted from C/C++ "bool"
 */
shouldDrawLocalContentWireframeBox : function () {},

/**
 * @method getLocalContentBoundingBoxRelativeTo
 * @return A value converted from C/C++ "CC3Box"
 * @param {cocos3d::CC3Node*}
 */
getLocalContentBoundingBoxRelativeTo : function () {},

/**
 * @method shouldContributeToParentBoundingBox
 * @return A value converted from C/C++ "bool"
 */
shouldContributeToParentBoundingBox : function () {},

/**
 * @method getGlobalLocalContentBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getGlobalLocalContentBoundingBox : function () {},

/**
 * @method getGlobalLocalContentCenterOfGeometry
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalLocalContentCenterOfGeometry : function () {},

/**
 * @method getInitialDescriptorColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getInitialDescriptorColor : function () {},

/**
 * @method hasLocalContent
 * @return A value converted from C/C++ "bool"
 */
hasLocalContent : function () {},

/**
 * @method shouldDrawAllLocalContentWireframeBoxes
 * @return A value converted from C/C++ "bool"
 */
shouldDrawAllLocalContentWireframeBoxes : function () {},

/**
 * @method setShouldDrawLocalContentWireframeBox
 * @param {bool}
 */
setShouldDrawLocalContentWireframeBox : function () {},

/**
 * @method getInitialLocalContentWireframeBoxColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getInitialLocalContentWireframeBoxColor : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method getLocalContentWireframeBoxNode
 * @return A value converted from C/C++ "cocos3d::CC3WireframeBoundingBoxNode*"
 */
getLocalContentWireframeBoxNode : function () {},

/**
 * @method setLocalContentWireframeBoxColor
 * @param {cocos2d::ccColor4F}
 */
setLocalContentWireframeBoxColor : function () {},

/**
 * @method getLocalContentWireframeBoxColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getLocalContentWireframeBoxColor : function () {},

/**
 * @method CC3LocalContentNode
 * @constructor
 */
CC3LocalContentNode : function () {},

};

/**
 * @class CC3MeshNode
 */
cc3.CC3MeshNode = {

/**
 * @method populateAsTriangle
 * @param {cocos3d::CC3Face}
 * @param {ccTex2F*}
 * @param {unsigned int}
 */
populateAsTriangle : function () {},

/**
 * @method defaultBoundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3NodeBoundingVolume*"
 */
defaultBoundingVolume : function () {},

/**
 * @method setShouldCullFrontFaces
 * @param {bool}
 */
setShouldCullFrontFaces : function () {},

/**
 * @method doNotBufferVertexLocations
 */
doNotBufferVertexLocations : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 */
getTexture : function () {},

/**
 * @method setNormalScalingMethod
 * @param {cocos3d::CC3NormalScaling}
 */
setNormalScalingMethod : function () {},

/**
 * @method populateAsHollowConeWithRadius
 * @param {float}
 * @param {float}
 * @param {cocos3d::CC3Tessellation}
 */
populateAsHollowConeWithRadius : function () {},

/**
 * @method getNormalScalingMethod
 * @return A value converted from C/C++ "cocos3d::CC3NormalScaling"
 */
getNormalScalingMethod : function () {},

/**
 * @method setVertexBitangent
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexBitangent : function () {},

/**
 * @method addShadowVolumesForLight
 * @param {cocos3d::CC3Light*}
 */
addShadowVolumesForLight : function () {},

/**
 * @method setDiffuseColor
 * @param {cocos2d::ccColor4F}
 */
setDiffuseColor : function () {},

/**
 * @method getPodMaterialIndex
 * @return A value converted from C/C++ "int"
 */
getPodMaterialIndex : function () {},

/**
 * @method getEmissionColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getEmissionColor : function () {},

/**
 * @method shouldApplyOpacityToColor
 * @return A value converted from C/C++ "bool"
 */
shouldApplyOpacityToColor : function () {},

/**
 * @method doNotBufferVertexIndices
 */
doNotBufferVertexIndices : function () {},

/**
 * @method retainVertexTangents
 */
retainVertexTangents : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method shouldUseSmoothShading
 * @return A value converted from C/C++ "bool"
 */
shouldUseSmoothShading : function () {},

/**
 * @method retainVertexIndices
 */
retainVertexIndices : function () {},

/**
 * @method addTexture
 * @param {cocos3d::CC3Texture*}
 */
addTexture : function () {},

/**
 * @method doNotBufferVertexNormals
 */
doNotBufferVertexNormals : function () {},

/**
 * @method ensureMesh
 * @return A value converted from C/C++ "cocos3d::CC3Mesh*"
 */
ensureMesh : function () {},

/**
 * @method getDiffuseColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getDiffuseColor : function () {},

/**
 * @method setIsOpaque
 * @param {bool}
 */
setIsOpaque : function () {},

/**
 * @method getVertexBoneCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexBoneCount : function () {},

/**
 * @method populateAsCubeMappedSolidBox
 * @param {cocos3d::CC3Box}
 */
populateAsCubeMappedSolidBox : function () {},

/**
 * @method getDrawingMode
 * @return A value converted from C/C++ "unsigned int"
 */
getDrawingMode : function () {},

/**
 * @method getVertexBoneIndicesAt
 * @return A value converted from C/C++ "void*"
 * @param {unsigned int}
 */
getVertexBoneIndicesAt : function () {},

/**
 * @method applyShaderProgramWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyShaderProgramWithVisitor : function () {},

/**
 * @method setShouldApplyOpacityAndColorToMeshContent
 * @param {bool}
 */
setShouldApplyOpacityAndColorToMeshContent : function () {},

/**
 * @method shouldDisableDepthTest
 * @return A value converted from C/C++ "bool"
 */
shouldDisableDepthTest : function () {},

/**
 * @method shouldBlendAtFullOpacity
 * @return A value converted from C/C++ "bool"
 */
shouldBlendAtFullOpacity : function () {},

/**
 * @method alignTextureUnit
 * @param {unsigned int}
 */
alignTextureUnit : function () {},

/**
 * @method makeMesh
 * @return A value converted from C/C++ "cocos3d::CC3Mesh*"
 */
makeMesh : function () {},

/**
 * @method getLineSmoothingHint
 * @return A value converted from C/C++ "unsigned int"
 */
getLineSmoothingHint : function () {},

/**
 * @method flipTexturesHorizontally
 */
flipTexturesHorizontally : function () {},

/**
 * @method setShaderProgram
 * @param {cocos3d::CC3ShaderProgram*}
 */
setShaderProgram : function () {},

/**
 * @method getVertexColorType
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexColorType : function () {},

/**
 * @method setVertexColor4F
 * @param {cocos2d::ccColor4F}
 * @param {unsigned int}
 */
setVertexColor4F : function () {},

/**
 * @method updateLightPosition
 */
updateLightPosition : function () {},

/**
 * @method setVertexColor4B
 * @param {cocos2d::ccColor4B}
 * @param {unsigned int}
 */
setVertexColor4B : function () {},

/**
 * @method prepareParametricMesh
 * @return A value converted from C/C++ "cocos3d::CC3Mesh*"
 */
prepareParametricMesh : function () {},

/**
 * @method shouldCullFrontFaces
 * @return A value converted from C/C++ "bool"
 */
shouldCullFrontFaces : function () {},

/**
 * @method shouldSmoothLines
 * @return A value converted from C/C++ "bool"
 */
shouldSmoothLines : function () {},

/**
 * @method getLocalContentBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getLocalContentBoundingBox : function () {},

/**
 * @method findFirstGlobal
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 * @param {CC3MeshIntersection*}
 * @param {CC3Ray}
 * @param {bool}
 * @param {bool}
 */
findFirstGlobal : function () {},

/**
 * @method retainVertexBoneIndices
 */
retainVertexBoneIndices : function () {},

/**
 * @method setShininess
 * @param {float}
 */
setShininess : function () {},

/**
 * @method setDrawingMode
 * @param {unsigned int}
 */
setDrawingMode : function () {},

/**
 * @method getDeformedFaceNormalAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getDeformedFaceNormalAt : function () {},

/**
 * @method shouldDrawLowAlpha
 * @return A value converted from C/C++ "bool"
 */
shouldDrawLowAlpha : function () {},

/**
 * @method shouldCastShadowsWhenInvisible
 * @return A value converted from C/C++ "bool"
 */
shouldCastShadowsWhenInvisible : function () {},

/**
 * @method removeLocalShaders
 */
removeLocalShaders : function () {},

/**
 * @method flipVerticallyTextureUnit
 * @param {unsigned int}
 */
flipVerticallyTextureUnit : function () {},

/**
 * @method setShouldCastShadowsWhenInvisible
 * @param {bool}
 */
setShouldCastShadowsWhenInvisible : function () {},

/**
 * @method getDeformedFaceCenterAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getDeformedFaceCenterAt : function () {},

/**
 * @method flipNormals
 */
flipNormals : function () {},

/**
 * @method getVertexTexCoord2FForTextureUnit
 * @return A value converted from C/C++ "ccTex2F"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getVertexTexCoord2FForTextureUnit : function () {},

/**
 * @method configureColoring
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureColoring : function () {},

/**
 * @method drawMeshWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawMeshWithVisitor : function () {},

/**
 * @method shouldCacheFaces
 * @return A value converted from C/C++ "bool"
 */
shouldCacheFaces : function () {},

/**
 * @method setDecalOffsetFactor
 * @param {float}
 */
setDecalOffsetFactor : function () {},

/**
 * @method getMaterial
 * @return A value converted from C/C++ "cocos3d::CC3Material*"
 */
getMaterial : function () {},

/**
 * @method configureNormalization
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureNormalization : function () {},

/**
 * @method isOpaque
 * @return A value converted from C/C++ "bool"
 */
isOpaque : function () {},

/**
 * @method applyEffectNamedFromRez
 * @param {std::string}
 * @param {std::string}
 */
applyEffectNamedFromRez : function () {},

/**
 * @method getDeformedFaceAt
 * @return A value converted from C/C++ "CC3Face"
 * @param {unsigned int}
 */
getDeformedFaceAt : function () {},

/**
 * @method setEmissionColor
 * @param {cocos2d::ccColor4F}
 */
setEmissionColor : function () {},

/**
 * @method applyEffectNamedFromFile
 * @param {std::string}
 * @param {std::string}
 */
applyEffectNamedFromFile : function () {},

/**
 * @method isMeshNode
 * @return A value converted from C/C++ "bool"
 */
isMeshNode : function () {},

/**
 * @method retainVertexBitangents
 */
retainVertexBitangents : function () {},

/**
 * @method setVertexContentTypes
 * @param {cocos3d::CC3VertexContent}
 */
setVertexContentTypes : function () {},

/**
 * @method setLineSmoothingHint
 * @param {unsigned int}
 */
setLineSmoothingHint : function () {},

/**
 * @method shouldUseLightProbes
 * @return A value converted from C/C++ "bool"
 */
shouldUseLightProbes : function () {},

/**
 * @method getEffectiveNormalScalingMethod
 * @return A value converted from C/C++ "cocos3d::CC3NormalScaling"
 */
getEffectiveNormalScalingMethod : function () {},

/**
 * @method getFaceCenterAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getFaceCenterAt : function () {},

/**
 * @method getFaceCountFromVertexIndexCount
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 */
getFaceCountFromVertexIndexCount : function () {},

/**
 * @method setMaterial
 * @param {cocos3d::CC3Material*}
 */
setMaterial : function () {},

/**
 * @method drawWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawWithVisitor : function () {},

/**
 * @method retainVertexLocations
 */
retainVertexLocations : function () {},

/**
 * @method getVertexLocationAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexLocationAt : function () {},

/**
 * @method shouldUseClockwiseFrontFaceWinding
 * @return A value converted from C/C++ "bool"
 */
shouldUseClockwiseFrontFaceWinding : function () {},

/**
 * @method getVertexBoneWeightsAt
 * @return A value converted from C/C++ "float*"
 * @param {unsigned int}
 */
getVertexBoneWeightsAt : function () {},

/**
 * @method setExpectsVerticallyFlippedTextures
 * @param {bool}
 */
setExpectsVerticallyFlippedTextures : function () {},

/**
 * @method getFaceFromIndices
 * @return A value converted from C/C++ "CC3Face"
 * @param {cocos3d::CC3FaceIndices}
 */
getFaceFromIndices : function () {},

/**
 * @method populateAsLineStripWith
 * @param {unsigned int}
 * @param {cocos3d::CC3Vector*}
 * @param {bool}
 */
populateAsLineStripWith : function () {},

/**
 * @method selectShaders
 */
selectShaders : function () {},

/**
 * @method shouldCullBackFaces
 * @return A value converted from C/C++ "bool"
 */
shouldCullBackFaces : function () {},

/**
 * @method getFaceNormalAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getFaceNormalAt : function () {},

/**
 * @method setGlobalLightPosition
 * @param {cocos3d::CC3Vector4}
 */
setGlobalLightPosition : function () {},

/**
 * @method selectShaderProgram
 * @return A value converted from C/C++ "cocos3d::CC3ShaderProgram*"
 */
selectShaderProgram : function () {},

/**
 * @method getLocalContentCenterOfGeometry
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLocalContentCenterOfGeometry : function () {},

/**
 * @method expectsVerticallyFlippedTextures
 * @return A value converted from C/C++ "bool"
 */
expectsVerticallyFlippedTextures : function () {},

/**
 * @method getVertexColor4FAt
 * @return A value converted from C/C++ "ccColor4F"
 * @param {unsigned int}
 */
getVertexColor4FAt : function () {},

/**
 * @method retainVertexBoneWeights
 */
retainVertexBoneWeights : function () {},

/**
 * @method releaseRedundantContent
 */
releaseRedundantContent : function () {},

/**
 * @method getVertexBitangentAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexBitangentAt : function () {},

/**
 * @method expectsVerticallyFlippedTextureInTextureUnit
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 */
expectsVerticallyFlippedTextureInTextureUnit : function () {},

/**
 * @method setColor
 * @param {cocos2d::ccColor3B}
 */
setColor : function () {},

/**
 * @method setPodMaterialIndex
 * @param {int}
 */
setPodMaterialIndex : function () {},

/**
 * @method getDecalOffsetUnits
 * @return A value converted from C/C++ "float"
 */
getDecalOffsetUnits : function () {},

/**
 * @method setSpecularColor
 * @param {cocos2d::ccColor4F}
 */
setSpecularColor : function () {},

/**
 * @method getVertexContentTypes
 * @return A value converted from C/C++ "cocos3d::CC3VertexContent"
 */
getVertexContentTypes : function () {},

/**
 * @method hasSkeleton
 * @return A value converted from C/C++ "bool"
 */
hasSkeleton : function () {},

/**
 * @method setVertexHomogeneousLocation
 * @param {cocos3d::CC3Vector4}
 * @param {unsigned int}
 */
setVertexHomogeneousLocation : function () {},

/**
 * @method setVertexCount
 * @param {unsigned int}
 */
setVertexCount : function () {},

/**
 * @method getTextureCount
 * @return A value converted from C/C++ "unsigned int"
 */
getTextureCount : function () {},

/**
 * @method alignMaterialAndMesh
 */
alignMaterialAndMesh : function () {},

/**
 * @method updateVertexTextureCoordinatesGLBuffer
 */
updateVertexTextureCoordinatesGLBuffer : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method getShaderProgram
 * @return A value converted from C/C++ "cocos3d::CC3ShaderProgram*"
 */
getShaderProgram : function () {},

/**
 * @method doNotBufferVertexBoneIndices
 */
doNotBufferVertexBoneIndices : function () {},

/**
 * @method setShouldUseLightProbes
 * @param {bool}
 */
setShouldUseLightProbes : function () {},

/**
 * @method setVertexIndex
 * @param {unsigned int}
 * @param {unsigned int}
 */
setVertexIndex : function () {},

/**
 * @method getMesh
 * @return A value converted from C/C++ "cocos3d::CC3Mesh*"
 */
getMesh : function () {},

/**
 * @method updateVertexNormalsGLBuffer
 */
updateVertexNormalsGLBuffer : function () {},

/**
 * @method setShouldDrawLowAlpha
 * @param {bool}
 */
setShouldDrawLowAlpha : function () {},

/**
 * @method setReflectivity
 * @param {float}
 */
setReflectivity : function () {},

/**
 * @method setVertexBoneIndex
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {unsigned int}
 */
setVertexBoneIndex : function () {},

/**
 * @method setVertexBoneWeights
 * @param {float*}
 * @param {unsigned int}
 */
setVertexBoneWeights : function () {},

/**
 * @method alignTextureUnits
 */
alignTextureUnits : function () {},

/**
 * @method updateVertexBitangentsGLBuffer
 */
updateVertexBitangentsGLBuffer : function () {},

/**
 * @method setAmbientColor
 * @param {cocos2d::ccColor4F}
 */
setAmbientColor : function () {},

/**
 * @method setVertexBoneIndices
 * @param {void*}
 * @param {unsigned int}
 */
setVertexBoneIndices : function () {},

/**
 * @method updateVertexColorsGLBuffer
 */
updateVertexColorsGLBuffer : function () {},

/**
 * @method setShouldUseClockwiseFrontFaceWinding
 * @param {bool}
 */
setShouldUseClockwiseFrontFaceWinding : function () {},

/**
 * @method setShaderContext
 * @param {cocos3d::CC3ShaderContext*}
 */
setShaderContext : function () {},

/**
 * @method configureDepthTesting
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureDepthTesting : function () {},

/**
 * @method isUsingGLBuffers
 * @return A value converted from C/C++ "bool"
 */
isUsingGLBuffers : function () {},

/**
 * @method getVertexHomogeneousLocationAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 * @param {unsigned int}
 */
getVertexHomogeneousLocationAt : function () {},

/**
 * @method setShouldBlendAtFullOpacity
 * @param {bool}
 */
setShouldBlendAtFullOpacity : function () {},

/**
 * @method setShouldUseSmoothShading
 * @param {bool}
 */
setShouldUseSmoothShading : function () {},

/**
 * @method getShininess
 * @return A value converted from C/C++ "float"
 */
getShininess : function () {},

/**
 * @method getTextureForTextureUnit
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {unsigned int}
 */
getTextureForTextureUnit : function () {},

/**
 * @method populateAsSphereWithRadius
 * @param {float}
 * @param {cocos3d::CC3Tessellation}
 */
populateAsSphereWithRadius : function () {},

/**
 * @method getCenterOfGeometry
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getCenterOfGeometry : function () {},

/**
 * @method getVertexIndexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexIndexCount : function () {},

/**
 * @method doNotBufferVertexTangents
 */
doNotBufferVertexTangents : function () {},

/**
 * @method retainVertexColors
 */
retainVertexColors : function () {},

/**
 * @method setMesh
 * @param {cocos3d::CC3Mesh*}
 */
setMesh : function () {},

/**
 * @method shouldDisableDepthMask
 * @return A value converted from C/C++ "bool"
 */
shouldDisableDepthMask : function () {},

/**
 * @method doNotBufferVertexColors
 */
doNotBufferVertexColors : function () {},

/**
 * @method getAmbientColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getAmbientColor : function () {},

/**
 * @method prewarmForShadowVolumes
 */
prewarmForShadowVolumes : function () {},

/**
 * @method configureDrawingParameters
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureDrawingParameters : function () {},

/**
 * @method getDeformedVertexLocationAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getDeformedVertexLocationAt : function () {},

/**
 * @method setVertexNormal
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexNormal : function () {},

/**
 * @method shouldDrawInClipSpace
 * @return A value converted from C/C++ "bool"
 */
shouldDrawInClipSpace : function () {},

/**
 * @method setName
 * @param {std::string}
 */
setName : function () {},

/**
 * @method getVertexTangentAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexTangentAt : function () {},

/**
 * @method findFirst
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 * @param {CC3MeshIntersection*}
 * @param {CC3Ray}
 * @param {bool}
 * @param {bool}
 */
findFirst : function () {},

/**
 * @method applyMaterialWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyMaterialWithVisitor : function () {},

/**
 * @method setVertexWeight
 * @param {float}
 * @param {unsigned int}
 * @param {unsigned int}
 */
setVertexWeight : function () {},

/**
 * @method getTextureRectangle
 * @return A value converted from C/C++ "cocos2d::CCRect"
 */
getTextureRectangle : function () {},

/**
 * @method setShouldUseLighting
 * @param {bool}
 */
setShouldUseLighting : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method getDecalOffsetFactor
 * @return A value converted from C/C++ "float"
 */
getDecalOffsetFactor : function () {},

/**
 * @method getVertexIndexAt
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 */
getVertexIndexAt : function () {},

/**
 * @method setDecalOffsetUnits
 * @param {float}
 */
setDecalOffsetUnits : function () {},

/**
 * @method getVertexNormalAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexNormalAt : function () {},

/**
 * @method getDeformedFacePlaneAt
 * @return A value converted from C/C++ "CC3Plane"
 * @param {unsigned int}
 */
getDeformedFacePlaneAt : function () {},

/**
 * @method doNotBufferVertexContent
 */
doNotBufferVertexContent : function () {},

/**
 * @method getFaceIndicesAt
 * @return A value converted from C/C++ "CC3FaceIndices"
 * @param {unsigned int}
 */
getFaceIndicesAt : function () {},

/**
 * @method setShouldCacheFaces
 * @param {bool}
 */
setShouldCacheFaces : function () {},

/**
 * @method getVertexWeightForBoneInfluence
 * @return A value converted from C/C++ "float"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getVertexWeightForBoneInfluence : function () {},

/**
 * @method updateVertexBoneWeightsGLBuffer
 */
updateVertexBoneWeightsGLBuffer : function () {},

/**
 * @method removeShaders
 */
removeShaders : function () {},

/**
 * @method populateAsWireBox
 * @param {cocos3d::CC3Box}
 */
populateAsWireBox : function () {},

/**
 * @method cleanupDrawingParameters
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
cleanupDrawingParameters : function () {},

/**
 * @method setShouldDisableDepthTest
 * @param {bool}
 */
setShouldDisableDepthTest : function () {},

/**
 * @method updateGLBuffers
 */
updateGLBuffers : function () {},

/**
 * @method getLineWidth
 * @return A value converted from C/C++ "float"
 */
getLineWidth : function () {},

/**
 * @method configureLineProperties
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureLineProperties : function () {},

/**
 * @method getVertexColor4BAt
 * @return A value converted from C/C++ "ccColor4B"
 * @param {unsigned int}
 */
getVertexColor4BAt : function () {},

/**
 * @method makeMaterial
 * @return A value converted from C/C++ "cocos3d::CC3Material*"
 */
makeMaterial : function () {},

/**
 * @method retainVertexContent
 */
retainVertexContent : function () {},

/**
 * @method setVertexTangent
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexTangent : function () {},

/**
 * @method getFacePlaneAt
 * @return A value converted from C/C++ "CC3Plane"
 * @param {unsigned int}
 */
getFacePlaneAt : function () {},

/**
 * @method setVertexIndexCount
 * @param {unsigned int}
 */
setVertexIndexCount : function () {},

/**
 * @method setDepthFunction
 * @param {unsigned int}
 */
setDepthFunction : function () {},

/**
 * @method hasTexturePremultipliedAlpha
 * @return A value converted from C/C++ "bool"
 */
hasTexturePremultipliedAlpha : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3MeshNode*}
 */
populateFrom : function () {},

/**
 * @method removeAllTextures
 */
removeAllTextures : function () {},

/**
 * @method getFaceAt
 * @return A value converted from C/C++ "CC3Face"
 * @param {unsigned int}
 */
getFaceAt : function () {},

/**
 * @method getDepthFunction
 * @return A value converted from C/C++ "unsigned int"
 */
getDepthFunction : function () {},

/**
 * @method getShaderContext
 * @return A value converted from C/C++ "cocos3d::CC3ShaderContext*"
 */
getShaderContext : function () {},

/**
 * @method setShouldSmoothLines
 * @param {bool}
 */
setShouldSmoothLines : function () {},

/**
 * @method doNotBufferVertexBoneWeights
 */
doNotBufferVertexBoneWeights : function () {},

/**
 * @method getVertexBoneIndexType
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexBoneIndexType : function () {},

/**
 * @method updateVertexTangentsGLBuffer
 */
updateVertexTangentsGLBuffer : function () {},

/**
 * @method hasPremultipliedAlpha
 * @return A value converted from C/C++ "bool"
 */
hasPremultipliedAlpha : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method setLineWidth
 * @param {float}
 */
setLineWidth : function () {},

/**
 * @method expectsVerticallyFlippedTexture
 * @param {bool}
 * @param {unsigned int}
 */
expectsVerticallyFlippedTexture : function () {},

/**
 * @method updateVertexLocationsGLBuffer
 */
updateVertexLocationsGLBuffer : function () {},

/**
 * @method setVertexLocation
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexLocation : function () {},

/**
 * @method setShouldDisableDepthMask
 * @param {bool}
 */
setShouldDisableDepthMask : function () {},

/**
 * @method getFaceCount
 * @return A value converted from C/C++ "unsigned int"
 */
getFaceCount : function () {},

/**
 * @method createGLBuffers
 */
createGLBuffers : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method setShouldDrawInClipSpace
 * @param {bool}
 */
setShouldDrawInClipSpace : function () {},

/**
 * @method hasTextureAlpha
 * @return A value converted from C/C++ "bool"
 */
hasTextureAlpha : function () {},

/**
 * @method updateVertexBoneIndicesGLBuffer
 */
updateVertexBoneIndicesGLBuffer : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "ccColor3B"
 */
getColor : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method populateAsDiskWithRadius
 * @param {float}
 * @param {cocos3d::CC3Tessellation}
 */
populateAsDiskWithRadius : function () {},

/**
 * @method flipTexturesVertically
 */
flipTexturesVertically : function () {},

/**
 * @method deleteGLBuffers
 */
deleteGLBuffers : function () {},

/**
 * @method getVertexBoneIndexForBoneInfluence
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getVertexBoneIndexForBoneInfluence : function () {},

/**
 * @method getBlendFunc
 * @return A value converted from C/C++ "ccBlendFunc"
 */
getBlendFunc : function () {},

/**
 * @method updateVertexTextureCoordinatesGLBufferForTextureUnit
 * @param {unsigned int}
 */
updateVertexTextureCoordinatesGLBufferForTextureUnit : function () {},

/**
 * @method getReflectivity
 * @return A value converted from C/C++ "float"
 */
getReflectivity : function () {},

/**
 * @method hasRigidSkeleton
 * @return A value converted from C/C++ "bool"
 */
hasRigidSkeleton : function () {},

/**
 * @method getGlobalLightPosition
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 */
getGlobalLightPosition : function () {},

/**
 * @method moveMeshOriginTo
 * @param {cocos3d::CC3Vector}
 */
moveMeshOriginTo : function () {},

/**
 * @method shouldApplyOpacityAndColorToMeshContent
 * @return A value converted from C/C++ "bool"
 */
shouldApplyOpacityAndColorToMeshContent : function () {},

/**
 * @method doNotBufferVertexTextureCoordinates
 */
doNotBufferVertexTextureCoordinates : function () {},

/**
 * @method moveMeshOriginToCenterOfGeometry
 */
moveMeshOriginToCenterOfGeometry : function () {},

/**
 * @method getVertexTexCoord2FAt
 * @return A value converted from C/C++ "ccTex2F"
 * @param {unsigned int}
 */
getVertexTexCoord2FAt : function () {},

/**
 * @method isDrawingPointSprites
 * @return A value converted from C/C++ "bool"
 */
isDrawingPointSprites : function () {},

/**
 * @method getVertexIndexCountFromFaceCount
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 */
getVertexIndexCountFromFaceCount : function () {},

/**
 * @method retainVertexTextureCoordinates
 */
retainVertexTextureCoordinates : function () {},

/**
 * @method setShouldCullBackFaces
 * @param {bool}
 */
setShouldCullBackFaces : function () {},

/**
 * @method getTextureRectangleForTextureUnit
 * @return A value converted from C/C++ "cocos2d::CCRect"
 * @param {unsigned int}
 */
getTextureRectangleForTextureUnit : function () {},

/**
 * @method setBlendFunc
 * @param {ccBlendFunc}
 */
setBlendFunc : function () {},

/**
 * @method getSpecularColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getSpecularColor : function () {},

/**
 * @method updateVertexIndicesGLBuffer
 */
updateVertexIndicesGLBuffer : function () {},

/**
 * @method configureDecalParameters
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureDecalParameters : function () {},

/**
 * @method configureFaceCulling
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureFaceCulling : function () {},

/**
 * @method getFaceNeighboursAt
 * @return A value converted from C/C++ "CC3FaceNeighbours"
 * @param {unsigned int}
 */
getFaceNeighboursAt : function () {},

/**
 * @method retainVertexNormals
 */
retainVertexNormals : function () {},

/**
 * @method shouldUseLighting
 * @return A value converted from C/C++ "bool"
 */
shouldUseLighting : function () {},

/**
 * @method doNotBufferVertexBitangents
 */
doNotBufferVertexBitangents : function () {},

/**
 * @method flipHorizontallyTextureUnit
 * @param {unsigned int}
 */
flipHorizontallyTextureUnit : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3MeshNode*"
 * @param {std::string}
 */
nodeWithName : function () {},

/**
 * @method CC3MeshNode
 * @constructor
 */
CC3MeshNode : function () {},

};

/**
 * @class CC3BitmapFontConfiguration
 */
cc3.CC3BitmapFontConfiguration = {

/**
 * @method getFontSize
 * @return A value converted from C/C++ "float"
 */
getFontSize : function () {},

/**
 * @method getTextureSize
 * @return A value converted from C/C++ "cocos2d::CCSize"
 */
getTextureSize : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method getKerningBetween
 * @return A value converted from C/C++ "int"
 * @param {unsigned char}
 * @param {unsigned char}
 */
getKerningBetween : function () {},

/**
 * @method getPadding
 * @return A value converted from C/C++ "CC3BitmapFontPadding"
 */
getPadding : function () {},

/**
 * @method getBaseline
 * @return A value converted from C/C++ "unsigned int"
 */
getBaseline : function () {},

/**
 * @method getAtlasName
 * @return A value converted from C/C++ "std::string"
 */
getAtlasName : function () {},

/**
 * @method getCommonHeight
 * @return A value converted from C/C++ "int"
 */
getCommonHeight : function () {},

/**
 * @method initFromFontFile
 * @return A value converted from C/C++ "bool"
 * @param {std::string}
 */
initFromFontFile : function () {},

/**
 * @method getCharacterSpecFor
 * @return A value converted from C/C++ "CC3BitmapCharDef*"
 * @param {unsigned char}
 */
getCharacterSpecFor : function () {},

/**
 * @method configurationFromFontFile
 * @return A value converted from C/C++ "cocos3d::CC3BitmapFontConfiguration*"
 * @param {std::string}
 */
configurationFromFontFile : function () {},

/**
 * @method clearFontConfigurations
 */
clearFontConfigurations : function () {},

/**
 * @method CC3BitmapFontConfiguration
 * @constructor
 */
CC3BitmapFontConfiguration : function () {},

};

/**
 * @class CC3BitmapLabelNode
 */
cc3.CC3BitmapLabelNode = {

/**
 * @method setTextAlignment
 * @param {cocos2d::CCTextAlignment}
 */
setTextAlignment : function () {},

/**
 * @method getFontFileName
 * @return A value converted from C/C++ "std::string"
 */
getFontFileName : function () {},

/**
 * @method setTessellation
 * @param {cocos3d::CC3Tessellation}
 */
setTessellation : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3BitmapLabelNode*}
 */
populateFrom : function () {},

/**
 * @method getFontSize
 * @return A value converted from C/C++ "float"
 */
getFontSize : function () {},

/**
 * @method getBaseline
 * @return A value converted from C/C++ "float"
 */
getBaseline : function () {},

/**
 * @method setLabelString
 * @param {std::string}
 */
setLabelString : function () {},

/**
 * @method getTextAlignment
 * @return A value converted from C/C++ "cocos2d::CCTextAlignment"
 */
getTextAlignment : function () {},

/**
 * @method setFontFileName
 * @param {std::string}
 */
setFontFileName : function () {},

/**
 * @method getTessellation
 * @return A value converted from C/C++ "CC3Tessellation"
 */
getTessellation : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method getRelativeOrigin
 * @return A value converted from C/C++ "cocos2d::CCPoint"
 */
getRelativeOrigin : function () {},

/**
 * @method populateLabelMesh
 */
populateLabelMesh : function () {},

/**
 * @method populateAsBitmapFontLabelFromString
 * @param {std::string}
 * @param {std::string}
 * @param {float}
 * @param {cocos2d::CCTextAlignment}
 * @param {cocos2d::CCPoint}
 * @param {cocos3d::CC3Tessellation}
 */
populateAsBitmapFontLabelFromString : function () {},

/**
 * @method setRelativeOrigin
 * @param {cocos2d::CCPoint}
 */
setRelativeOrigin : function () {},

/**
 * @method getLineHeight
 * @return A value converted from C/C++ "float"
 */
getLineHeight : function () {},

/**
 * @method setLineHeight
 * @param {float}
 */
setLineHeight : function () {},

/**
 * @method getLabelString
 * @return A value converted from C/C++ "std::string"
 */
getLabelString : function () {},

/**
 * @method CC3BitmapLabelNode
 * @constructor
 */
CC3BitmapLabelNode : function () {},

};

/**
 * @class CC3PlaneNode
 */
cc3.CC3PlaneNode = {

/**
 * @method getPlane
 * @return A value converted from C/C++ "CC3Plane"
 */
getPlane : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3PlaneNode*"
 * @param {std::string}
 */
nodeWithName : function () {},

};

/**
 * @class CC3LineNode
 */
cc3.CC3LineNode = {

};

/**
 * @class CC3SimpleLineNode
 */
cc3.CC3SimpleLineNode = {

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method setLineStart
 * @param {cocos3d::CC3Vector}
 */
setLineStart : function () {},

/**
 * @method getLineEnd
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLineEnd : function () {},

/**
 * @method getLineStart
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLineStart : function () {},

/**
 * @method setLineEnd
 * @param {cocos3d::CC3Vector}
 */
setLineEnd : function () {},

};

/**
 * @class CC3BoxNode
 */
cc3.CC3BoxNode = {

/**
 * @method node
 * @return A value converted from C/C++ "cocos3d::CC3BoxNode*"
 */
node : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3BoxNode*"
 * @param {std::string}
 */
nodeWithName : function () {},

};

/**
 * @class CC3TouchBox
 */
cc3.CC3TouchBox = {

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method getNameSuffix
 * @return A value converted from C/C++ "std::string"
 */
getNameSuffix : function () {},

/**
 * @method setBox
 * @param {cocos3d::CC3Box}
 */
setBox : function () {},

/**
 * @method setParent
 * @param {cocos3d::CC3Node*}
 */
setParent : function () {},

/**
 * @method shouldContributeToParentBoundingBox
 * @return A value converted from C/C++ "bool"
 */
shouldContributeToParentBoundingBox : function () {},

/**
 * @method updateAfterTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
updateAfterTransform : function () {},

/**
 * @method getBox
 * @return A value converted from C/C++ "CC3Box"
 */
getBox : function () {},

/**
 * @method populateBox
 * @param {cocos3d::CC3Box}
 */
populateBox : function () {},

/**
 * @method getParentBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getParentBoundingBox : function () {},

/**
 * @method prepareParametricMesh
 * @return A value converted from C/C++ "cocos3d::CC3Mesh*"
 */
prepareParametricMesh : function () {},

};

/**
 * @class CC3SphereNode
 */
cc3.CC3SphereNode = {

/**
 * @method defaultBoundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3NodeBoundingVolume*"
 */
defaultBoundingVolume : function () {},

/**
 * @method node
 * @return A value converted from C/C++ "cocos3d::CC3SphereNode*"
 */
node : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3SphereNode*"
 * @param {std::string}
 */
nodeWithName : function () {},

};

/**
 * @class CC3ClipSpaceNode
 */
cc3.CC3ClipSpaceNode = {

/**
 * @method defaultBoundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3NodeBoundingVolume*"
 */
defaultBoundingVolume : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method nodeWithTexture
 * @return A value converted from C/C++ "cocos3d::CC3ClipSpaceNode*"
 * @param {cocos3d::CC3Texture*}
 */
nodeWithTexture : function () {},

/**
 * @method nodeWithColor
 * @return A value converted from C/C++ "cocos3d::CC3ClipSpaceNode*"
 * @param {cocos2d::ccColor4F}
 */
nodeWithColor : function () {},

};

/**
 * @class CC3Backdrop
 */
cc3.CC3Backdrop = {

/**
 * @method node
 * @return A value converted from C/C++ "cocos3d::CC3Backdrop*"
 */
node : function () {},

/**
 * @method nodeWithTexture
 * @return A value converted from C/C++ "cocos3d::CC3Backdrop*"
 * @param {cocos3d::CC3Texture*}
 */
nodeWithTexture : function () {},

/**
 * @method nodeWithColor
 * @return A value converted from C/C++ "cocos3d::CC3Backdrop*"
 * @param {cocos2d::ccColor4F}
 */
nodeWithColor : function () {},

};

/**
 * @class CC3Fog
 */
cc3.CC3Fog = {

/**
 * @method setPerformanceHint
 * @param {unsigned int}
 */
setPerformanceHint : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Fog*}
 */
populateFrom : function () {},

/**
 * @method getAttenuationMode
 * @return A value converted from C/C++ "unsigned int"
 */
getAttenuationMode : function () {},

/**
 * @method setEndDistance
 * @param {float}
 */
setEndDistance : function () {},

/**
 * @method setDensity
 * @param {float}
 */
setDensity : function () {},

/**
 * @method setAttenuationMode
 * @param {unsigned int}
 */
setAttenuationMode : function () {},

/**
 * @method getPerformanceHint
 * @return A value converted from C/C++ "unsigned int"
 */
getPerformanceHint : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getEndDistance
 * @return A value converted from C/C++ "float"
 */
getEndDistance : function () {},

/**
 * @method getDensity
 * @return A value converted from C/C++ "float"
 */
getDensity : function () {},

/**
 * @method getStartDistance
 * @return A value converted from C/C++ "float"
 */
getStartDistance : function () {},

/**
 * @method setStartDistance
 * @param {float}
 */
setStartDistance : function () {},

/**
 * @method fog
 * @return A value converted from C/C++ "cocos3d::CC3Fog*"
 */
fog : function () {},

};

/**
 * @class CC3VertexArray
 */
cc3.CC3VertexArray = {

/**
 * @method getBufferTarget
 * @return A value converted from C/C++ "unsigned int"
 */
getBufferTarget : function () {},

/**
 * @method setShouldNormalizeContent
 * @param {bool}
 */
setShouldNormalizeContent : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3VertexArray*}
 */
populateFrom : function () {},

/**
 * @method createGLBuffer
 */
createGLBuffer : function () {},

/**
 * @method bindContentToAttributeAt
 * @param {int}
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
bindContentToAttributeAt : function () {},

/**
 * @method getSemantic
 * @return A value converted from C/C++ "unsigned int"
 */
getSemantic : function () {},

/**
 * @method resetTagAllocation
 */
resetTagAllocation : function () {},

/**
 * @method getElementSize
 * @return A value converted from C/C++ "int"
 */
getElementSize : function () {},

/**
 * @method shouldAllowVertexBuffering
 * @return A value converted from C/C++ "bool"
 */
shouldAllowVertexBuffering : function () {},

/**
 * @method deleteGLBuffer
 */
deleteGLBuffer : function () {},

/**
 * @method setElementOffset
 * @param {unsigned int}
 */
setElementOffset : function () {},

/**
 * @method setElementsFromCPODData
 * @param {CPODData*}
 * @param {SPODMesh*}
 */
setElementsFromCPODData : function () {},

/**
 * @method updateGLBufferStartingAt
 * @param {unsigned int}
 * @param {unsigned int}
 */
updateGLBufferStartingAt : function () {},

/**
 * @method getVertices
 * @return A value converted from C/C++ "void*"
 */
getVertices : function () {},

/**
 * @method getAllocatedVertexCapacity
 * @return A value converted from C/C++ "unsigned int"
 */
getAllocatedVertexCapacity : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method releaseRedundantContent
 */
releaseRedundantContent : function () {},

/**
 * @method getElementType
 * @return A value converted from C/C++ "unsigned int"
 */
getElementType : function () {},

/**
 * @method shouldNormalizeContent
 * @return A value converted from C/C++ "bool"
 */
shouldNormalizeContent : function () {},

/**
 * @method setShouldReleaseRedundantContent
 * @param {bool}
 */
setShouldReleaseRedundantContent : function () {},

/**
 * @method isUsingGLBuffer
 * @return A value converted from C/C++ "bool"
 */
isUsingGLBuffer : function () {},

/**
 * @method setShouldAllowVertexBuffering
 * @param {bool}
 */
setShouldAllowVertexBuffering : function () {},

/**
 * @method getBufferID
 * @return A value converted from C/C++ "unsigned int"
 */
getBufferID : function () {},

/**
 * @method getElementOffset
 * @return A value converted from C/C++ "unsigned int"
 */
getElementOffset : function () {},

/**
 * @method nextTag
 * @return A value converted from C/C++ "unsigned int"
 */
nextTag : function () {},

/**
 * @method getAvailableVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getAvailableVertexCount : function () {},

/**
 * @method setVertexStride
 * @param {unsigned int}
 */
setVertexStride : function () {},

/**
 * @method setAllocatedVertexCapacity
 * @param {unsigned int}
 */
setAllocatedVertexCapacity : function () {},

/**
 * @method setBufferID
 * @param {unsigned int}
 */
setBufferID : function () {},

/**
 * @method setElementSize
 * @param {int}
 */
setElementSize : function () {},

/**
 * @method setVertices
 * @param {void*}
 */
setVertices : function () {},

/**
 * @method updateGLBuffer
 */
updateGLBuffer : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method setBufferUsage
 * @param {unsigned int}
 */
setBufferUsage : function () {},

/**
 * @method setElementType
 * @param {unsigned int}
 */
setElementType : function () {},

/**
 * @method getVertexStride
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexStride : function () {},

/**
 * @method getAddressOfElement
 * @return A value converted from C/C++ "void*"
 * @param {unsigned int}
 */
getAddressOfElement : function () {},

/**
 * @method setSemantic
 * @param {unsigned int}
 */
setSemantic : function () {},

/**
 * @method getElementLength
 * @return A value converted from C/C++ "unsigned int"
 */
getElementLength : function () {},

/**
 * @method defaultSemantic
 * @return A value converted from C/C++ "unsigned int"
 */
defaultSemantic : function () {},

/**
 * @method setVertexCount
 * @param {unsigned int}
 */
setVertexCount : function () {},

/**
 * @method shouldReleaseRedundantContent
 * @return A value converted from C/C++ "bool"
 */
shouldReleaseRedundantContent : function () {},

/**
 * @method getBufferUsage
 * @return A value converted from C/C++ "unsigned int"
 */
getBufferUsage : function () {},

/**
 * @method vertexArray
 * @return A value converted from C/C++ "cocos3d::CC3VertexArray*"
 */
vertexArray : function () {},

/**
 * @method vertexArrayWithName
 * @return A value converted from C/C++ "cocos3d::CC3VertexArray*"
 * @param {std::string}
 */
vertexArrayWithName : function () {},

/**
 * @method CC3VertexArray
 * @constructor
 */
CC3VertexArray : function () {},

};

/**
 * @class CC3Mesh
 */
cc3.CC3Mesh = {

/**
 * @method populateAsTriangle
 * @param {cocos3d::CC3Face}
 * @param {ccTex2F*}
 * @param {unsigned int}
 */
populateAsTriangle : function () {},

/**
 * @method drawVerticesWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawVerticesWithVisitor : function () {},

/**
 * @method copyVertexAt
 * @param {unsigned int}
 * @param {cocos3d::CC3Mesh*}
 * @param {unsigned int}
 */
copyVertexAt : function () {},

/**
 * @method doNotBufferVertexLocations
 */
doNotBufferVertexLocations : function () {},

/**
 * @method retainVertexIndices
 */
retainVertexIndices : function () {},

/**
 * @method setVertexColors
 * @param {cocos3d::CC3VertexColors*}
 */
setVertexColors : function () {},

/**
 * @method resetTagAllocation
 */
resetTagAllocation : function () {},

/**
 * @method ensureCapacity
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 */
ensureCapacity : function () {},

/**
 * @method populateAsHollowConeWithRadius
 * @param {float}
 * @param {float}
 * @param {cocos3d::CC3Tessellation}
 */
populateAsHollowConeWithRadius : function () {},

/**
 * @method retainVertexLocations
 */
retainVertexLocations : function () {},

/**
 * @method setVertexBitangent
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexBitangent : function () {},

/**
 * @method getVertexTangents
 * @return A value converted from C/C++ "cocos3d::CC3VertexTangents*"
 */
getVertexTangents : function () {},

/**
 * @method setTextureCoordinates
 * @param {cocos3d::CC3VertexTextureCoordinates*}
 * @param {unsigned int}
 */
setTextureCoordinates : function () {},

/**
 * @method doNotBufferVertexIndices
 */
doNotBufferVertexIndices : function () {},

/**
 * @method getAllocatedVertexCapacity
 * @return A value converted from C/C++ "unsigned int"
 */
getAllocatedVertexCapacity : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateAsSphereWithRadius
 * @param {float}
 * @param {cocos3d::CC3Tessellation}
 */
populateAsSphereWithRadius : function () {},

/**
 * @method doNotBufferVertexNormals
 */
doNotBufferVertexNormals : function () {},

/**
 * @method getDrawingMode
 * @return A value converted from C/C++ "unsigned int"
 */
getDrawingMode : function () {},

/**
 * @method setExpectsVerticallyFlippedTextures
 * @param {bool}
 */
setExpectsVerticallyFlippedTextures : function () {},

/**
 * @method getVertexBoneCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexBoneCount : function () {},

/**
 * @method populateAsCubeMappedSolidBox
 * @param {cocos3d::CC3Box}
 */
populateAsCubeMappedSolidBox : function () {},

/**
 * @method getVertexBoneIndicesAt
 * @return A value converted from C/C++ "void*"
 * @param {unsigned int}
 */
getVertexBoneIndicesAt : function () {},

/**
 * @method getTextureCoordinatesForTextureUnit
 * @return A value converted from C/C++ "cocos3d::CC3VertexTextureCoordinates*"
 * @param {unsigned int}
 */
getTextureCoordinatesForTextureUnit : function () {},

/**
 * @method hasVertexBitangents
 * @return A value converted from C/C++ "bool"
 */
hasVertexBitangents : function () {},

/**
 * @method doNotBufferVertexTangents
 */
doNotBufferVertexTangents : function () {},

/**
 * @method hasVertexBoneWeights
 * @return A value converted from C/C++ "bool"
 */
hasVertexBoneWeights : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getColor : function () {},

/**
 * @method getVertexNormals
 * @return A value converted from C/C++ "cocos3d::CC3VertexNormals*"
 */
getVertexNormals : function () {},

/**
 * @method getVertexBoneWeights
 * @return A value converted from C/C++ "cocos3d::CC3VertexBoneWeights*"
 */
getVertexBoneWeights : function () {},

/**
 * @method flipTexturesHorizontally
 */
flipTexturesHorizontally : function () {},

/**
 * @method doNotBufferVertexColors
 */
doNotBufferVertexColors : function () {},

/**
 * @method getVertexColorType
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexColorType : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method setVertexColor4F
 * @param {cocos2d::ccColor4F}
 * @param {unsigned int}
 */
setVertexColor4F : function () {},

/**
 * @method shouldInterleaveVertices
 * @return A value converted from C/C++ "bool"
 */
shouldInterleaveVertices : function () {},

/**
 * @method setVertexColor4B
 * @param {cocos2d::ccColor4B}
 * @param {unsigned int}
 */
setVertexColor4B : function () {},

/**
 * @method setColor
 * @param {cocos3d::CCColorRef}
 */
setColor : function () {},

/**
 * @method vertexTexCoord2FAt
 * @return A value converted from C/C++ "ccTex2F"
 * @param {unsigned int}
 */
vertexTexCoord2FAt : function () {},

/**
 * @method updateVertexBitangentsGLBuffer
 */
updateVertexBitangentsGLBuffer : function () {},

/**
 * @method setDrawingMode
 * @param {unsigned int}
 */
setDrawingMode : function () {},

/**
 * @method alignTextureUnit
 * @param {unsigned int}
 * @param {cocos3d::CC3Texture*}
 */
alignTextureUnit : function () {},

/**
 * @method updateVertexIndicesGLBuffer
 */
updateVertexIndicesGLBuffer : function () {},

/**
 * @method getVertexArrayForSemantic
 * @return A value converted from C/C++ "cocos3d::CC3VertexArray*"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getVertexArrayForSemantic : function () {},

/**
 * @method deleteGLBuffers
 */
deleteGLBuffers : function () {},

/**
 * @method setVertexPointSize
 * @param {float}
 * @param {unsigned int}
 */
setVertexPointSize : function () {},

/**
 * @method getNameSuffix
 * @return A value converted from C/C++ "std::string"
 */
getNameSuffix : function () {},

/**
 * @method flipNormals
 */
flipNormals : function () {},

/**
 * @method getVertexTexCoord2FForTextureUnit
 * @return A value converted from C/C++ "ccTex2F"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getVertexTexCoord2FForTextureUnit : function () {},

/**
 * @method updatePointSizesGLBuffer
 */
updatePointSizesGLBuffer : function () {},

/**
 * @method setVertexLocations
 * @param {cocos3d::CC3VertexLocations*}
 */
setVertexLocations : function () {},

/**
 * @method shouldCacheFaces
 * @return A value converted from C/C++ "bool"
 */
shouldCacheFaces : function () {},

/**
 * @method setVertexBitangents
 * @param {cocos3d::CC3VertexTangents*}
 */
setVertexBitangents : function () {},

/**
 * @method getCapacityExpansionFactor
 * @return A value converted from C/C++ "float"
 */
getCapacityExpansionFactor : function () {},

/**
 * @method retainVertexBitangents
 */
retainVertexBitangents : function () {},

/**
 * @method updateVertexTextureCoordinatesGLBufferForTextureUnit
 * @param {unsigned int}
 */
updateVertexTextureCoordinatesGLBufferForTextureUnit : function () {},

/**
 * @method removeTextureCoordinates
 * @param {cocos3d::CC3VertexTextureCoordinates*}
 */
removeTextureCoordinates : function () {},

/**
 * @method getRadius
 * @return A value converted from C/C++ "float"
 */
getRadius : function () {},

/**
 * @method setVertexContentTypes
 * @param {cocos3d::CC3VertexContent}
 */
setVertexContentTypes : function () {},

/**
 * @method getFaceCountFromVertexIndexCount
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 */
getFaceCountFromVertexIndexCount : function () {},

/**
 * @method drawWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawWithVisitor : function () {},

/**
 * @method getVertexLocationAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexLocationAt : function () {},

/**
 * @method getVertexBoneWeightsAt
 * @return A value converted from C/C++ "float*"
 * @param {unsigned int}
 */
getVertexBoneWeightsAt : function () {},

/**
 * @method nextTag
 * @return A value converted from C/C++ "unsigned int"
 */
nextTag : function () {},

/**
 * @method moveMeshOriginToCenterOfGeometry
 */
moveMeshOriginToCenterOfGeometry : function () {},

/**
 * @method getFaceFromIndices
 * @return A value converted from C/C++ "CC3Face"
 * @param {cocos3d::CC3FaceIndices}
 */
getFaceFromIndices : function () {},

/**
 * @method populateAsLineStripWith
 * @param {unsigned int}
 * @param {cocos3d::CC3Vector*}
 * @param {bool}
 */
populateAsLineStripWith : function () {},

/**
 * @method getFaceNormalAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getFaceNormalAt : function () {},

/**
 * @method getFaces
 * @return A value converted from C/C++ "cocos3d::CC3FaceArray*"
 */
getFaces : function () {},

/**
 * @method hasVertexBoneIndices
 * @return A value converted from C/C++ "bool"
 */
hasVertexBoneIndices : function () {},

/**
 * @method updateVertexStride
 * @return A value converted from C/C++ "unsigned int"
 */
updateVertexStride : function () {},

/**
 * @method retainVertexTangents
 */
retainVertexTangents : function () {},

/**
 * @method setCapacityExpansionFactor
 * @param {float}
 */
setCapacityExpansionFactor : function () {},

/**
 * @method flipVerticallyTextureUnit
 * @param {unsigned int}
 */
flipVerticallyTextureUnit : function () {},

/**
 * @method doNotBufferVertexContent
 */
doNotBufferVertexContent : function () {},

/**
 * @method getAllocatedVertexIndexCapacity
 * @return A value converted from C/C++ "unsigned int"
 */
getAllocatedVertexIndexCapacity : function () {},

/**
 * @method retainVertexBoneWeights
 */
retainVertexBoneWeights : function () {},

/**
 * @method releaseRedundantContent
 */
releaseRedundantContent : function () {},

/**
 * @method getVertexBitangents
 * @return A value converted from C/C++ "cocos3d::CC3VertexTangents*"
 */
getVertexBitangents : function () {},

/**
 * @method getVertexStride
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexStride : function () {},

/**
 * @method getVertexBitangentAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexBitangentAt : function () {},

/**
 * @method getUncachedFaceIndicesAt
 * @return A value converted from C/C++ "CC3FaceIndices"
 * @param {unsigned int}
 */
getUncachedFaceIndicesAt : function () {},

/**
 * @method hasVertexIndices
 * @return A value converted from C/C++ "bool"
 */
hasVertexIndices : function () {},

/**
 * @method getVertexContentTypes
 * @return A value converted from C/C++ "cocos3d::CC3VertexContent"
 */
getVertexContentTypes : function () {},

/**
 * @method setVertexHomogeneousLocation
 * @param {cocos3d::CC3Vector4}
 * @param {unsigned int}
 */
setVertexHomogeneousLocation : function () {},

/**
 * @method setVertexCount
 * @param {unsigned int}
 */
setVertexCount : function () {},

/**
 * @method expectsVerticallyFlippedTextures
 * @return A value converted from C/C++ "bool"
 */
expectsVerticallyFlippedTextures : function () {},

/**
 * @method getTextureRectangleForTextureUnit
 * @return A value converted from C/C++ "cocos2d::CCRect"
 * @param {unsigned int}
 */
getTextureRectangleForTextureUnit : function () {},

/**
 * @method updateVertexTextureCoordinatesGLBuffer
 */
updateVertexTextureCoordinatesGLBuffer : function () {},

/**
 * @method hasVertexColors
 * @return A value converted from C/C++ "bool"
 */
hasVertexColors : function () {},

/**
 * @method doNotBufferVertexBoneIndices
 */
doNotBufferVertexBoneIndices : function () {},

/**
 * @method setVertexIndex
 * @param {unsigned int}
 * @param {unsigned int}
 */
setVertexIndex : function () {},

/**
 * @method updateVertexNormalsGLBuffer
 */
updateVertexNormalsGLBuffer : function () {},

/**
 * @method getFaceCenterAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getFaceCenterAt : function () {},

/**
 * @method hasVertexTangents
 * @return A value converted from C/C++ "bool"
 */
hasVertexTangents : function () {},

/**
 * @method setVertexBoneIndex
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {unsigned int}
 */
setVertexBoneIndex : function () {},

/**
 * @method setAllocatedVertexIndexCapacity
 * @param {unsigned int}
 */
setAllocatedVertexIndexCapacity : function () {},

/**
 * @method retainVertexBoneIndices
 */
retainVertexBoneIndices : function () {},

/**
 * @method updateVertexColorsGLBuffer
 */
updateVertexColorsGLBuffer : function () {},

/**
 * @method getVertexIndices
 * @return A value converted from C/C++ "cocos3d::CC3VertexIndices*"
 */
getVertexIndices : function () {},

/**
 * @method isUsingGLBuffers
 * @return A value converted from C/C++ "bool"
 */
isUsingGLBuffers : function () {},

/**
 * @method getVertexHomogeneousLocationAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 * @param {unsigned int}
 */
getVertexHomogeneousLocationAt : function () {},

/**
 * @method interleavedVertices
 * @return A value converted from C/C++ "void*"
 */
interleavedVertices : function () {},

/**
 * @method getVertexColor4FAt
 * @return A value converted from C/C++ "ccColor4F"
 * @param {unsigned int}
 */
getVertexColor4FAt : function () {},

/**
 * @method hasVertexPointSizes
 * @return A value converted from C/C++ "bool"
 */
hasVertexPointSizes : function () {},

/**
 * @method getCenterOfGeometry
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getCenterOfGeometry : function () {},

/**
 * @method getVertexIndexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexIndexCount : function () {},

/**
 * @method retainVertexColors
 */
retainVertexColors : function () {},

/**
 * @method setExpectsVerticallyFlippedTexture
 * @param {bool}
 * @param {unsigned int}
 */
setExpectsVerticallyFlippedTexture : function () {},

/**
 * @method updateGLBuffersStartingAt
 * @param {unsigned int}
 * @param {unsigned int}
 */
updateGLBuffersStartingAt : function () {},

/**
 * @method setVertexNormal
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexNormal : function () {},

/**
 * @method setName
 * @param {std::string}
 */
setName : function () {},

/**
 * @method getVertexTangentAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexTangentAt : function () {},

/**
 * @method doNotBufferVertexBitangents
 */
doNotBufferVertexBitangents : function () {},

/**
 * @method setVertexWeight
 * @param {float}
 * @param {unsigned int}
 * @param {unsigned int}
 */
setVertexWeight : function () {},

/**
 * @method getTextureRectangle
 * @return A value converted from C/C++ "cocos2d::CCRect"
 */
getTextureRectangle : function () {},

/**
 * @method setVertexPointSizes
 * @param {cocos3d::CC3VertexPointSizes*}
 */
setVertexPointSizes : function () {},

/**
 * @method getVertexBoneIndices
 * @return A value converted from C/C++ "cocos3d::CC3VertexBoneIndices*"
 */
getVertexBoneIndices : function () {},

/**
 * @method ensureVertexContent
 */
ensureVertexContent : function () {},

/**
 * @method getVertexIndexAt
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 */
getVertexIndexAt : function () {},

/**
 * @method setFaces
 * @param {cocos3d::CC3FaceArray*}
 */
setFaces : function () {},

/**
 * @method getVertexNormalAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getVertexNormalAt : function () {},

/**
 * @method getTextureCoordinatesArrayCount
 * @return A value converted from C/C++ "unsigned int"
 */
getTextureCoordinatesArrayCount : function () {},

/**
 * @method doNotBufferVertexPointSizes
 */
doNotBufferVertexPointSizes : function () {},

/**
 * @method getTextureCoordinatesNamed
 * @return A value converted from C/C++ "cocos3d::CC3VertexTextureCoordinates*"
 * @param {std::string}
 */
getTextureCoordinatesNamed : function () {},

/**
 * @method getFaceIndicesAt
 * @return A value converted from C/C++ "CC3FaceIndices"
 * @param {unsigned int}
 */
getFaceIndicesAt : function () {},

/**
 * @method setShouldCacheFaces
 * @param {bool}
 */
setShouldCacheFaces : function () {},

/**
 * @method hasVertexTextureCoordinates
 * @return A value converted from C/C++ "bool"
 */
hasVertexTextureCoordinates : function () {},

/**
 * @method getVertexWeightForBoneInfluence
 * @return A value converted from C/C++ "float"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getVertexWeightForBoneInfluence : function () {},

/**
 * @method updateVertexBoneWeightsGLBuffer
 */
updateVertexBoneWeightsGLBuffer : function () {},

/**
 * @method setShouldInterleaveVertices
 * @param {bool}
 */
setShouldInterleaveVertices : function () {},

/**
 * @method populateAsWireBox
 * @param {cocos3d::CC3Box}
 */
populateAsWireBox : function () {},

/**
 * @method getVertexColor4BAt
 * @return A value converted from C/C++ "ccColor4B"
 * @param {unsigned int}
 */
getVertexColor4BAt : function () {},

/**
 * @method retainVertexContent
 */
retainVertexContent : function () {},

/**
 * @method setVertexTangent
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexTangent : function () {},

/**
 * @method getFacePlaneAt
 * @return A value converted from C/C++ "CC3Plane"
 * @param {unsigned int}
 */
getFacePlaneAt : function () {},

/**
 * @method setVertexIndexCount
 * @param {unsigned int}
 */
setVertexIndexCount : function () {},

/**
 * @method getVertexColors
 * @return A value converted from C/C++ "cocos3d::CC3VertexColors*"
 */
getVertexColors : function () {},

/**
 * @method removeAllTextureCoordinates
 */
removeAllTextureCoordinates : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Mesh*}
 */
populateFrom : function () {},

/**
 * @method getFaceAt
 * @return A value converted from C/C++ "CC3Face"
 * @param {unsigned int}
 */
getFaceAt : function () {},

/**
 * @method bindWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
bindWithVisitor : function () {},

/**
 * @method findFirst
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 * @param {CC3MeshIntersection*}
 * @param {cocos3d::CC3Ray}
 * @param {bool}
 * @param {bool}
 */
findFirst : function () {},

/**
 * @method doNotBufferVertexBoneWeights
 */
doNotBufferVertexBoneWeights : function () {},

/**
 * @method addTextureCoordinates
 * @param {cocos3d::CC3VertexTextureCoordinates*}
 */
addTextureCoordinates : function () {},

/**
 * @method getVertexBoneIndexType
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexBoneIndexType : function () {},

/**
 * @method updateVertexTangentsGLBuffer
 */
updateVertexTangentsGLBuffer : function () {},

/**
 * @method doNotBufferVertexTextureCoordinates
 */
doNotBufferVertexTextureCoordinates : function () {},

/**
 * @method setVertexIndices
 * @param {cocos3d::CC3VertexIndices*}
 */
setVertexIndices : function () {},

/**
 * @method updateVertexLocationsGLBuffer
 */
updateVertexLocationsGLBuffer : function () {},

/**
 * @method setVertexLocation
 * @param {cocos3d::CC3Vector}
 * @param {unsigned int}
 */
setVertexLocation : function () {},

/**
 * @method getFaceCount
 * @return A value converted from C/C++ "unsigned int"
 */
getFaceCount : function () {},

/**
 * @method createGLBuffers
 */
createGLBuffers : function () {},

/**
 * @method drawFrom
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawFrom : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method expectsVerticallyFlippedTextureInTextureUnit
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 */
expectsVerticallyFlippedTextureInTextureUnit : function () {},

/**
 * @method drawVerticesFrom
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawVerticesFrom : function () {},

/**
 * @method getVertexPointSizes
 * @return A value converted from C/C++ "cocos3d::CC3VertexPointSizes*"
 */
getVertexPointSizes : function () {},

/**
 * @method updateVertexBoneIndicesGLBuffer
 */
updateVertexBoneIndicesGLBuffer : function () {},

/**
 * @method getVertexLocations
 * @return A value converted from C/C++ "cocos3d::CC3VertexLocations*"
 */
getVertexLocations : function () {},

/**
 * @method getBoundingBox
 * @return A value converted from C/C++ "CC3Box"
 */
getBoundingBox : function () {},

/**
 * @method populateAsDiskWithRadius
 * @param {float}
 * @param {cocos3d::CC3Tessellation}
 */
populateAsDiskWithRadius : function () {},

/**
 * @method flipTexturesVertically
 */
flipTexturesVertically : function () {},

/**
 * @method setVertexStride
 * @param {unsigned int}
 */
setVertexStride : function () {},

/**
 * @method setAllocatedVertexCapacity
 * @param {unsigned int}
 */
setAllocatedVertexCapacity : function () {},

/**
 * @method getVertexBoneIndexForBoneInfluence
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getVertexBoneIndexForBoneInfluence : function () {},

/**
 * @method ensureVertexCapacity
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 */
ensureVertexCapacity : function () {},

/**
 * @method hasVertexLocations
 * @return A value converted from C/C++ "bool"
 */
hasVertexLocations : function () {},

/**
 * @method setVertexNormals
 * @param {cocos3d::CC3VertexNormals*}
 */
setVertexNormals : function () {},

/**
 * @method moveMeshOriginTo
 * @param {cocos3d::CC3Vector}
 */
moveMeshOriginTo : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "unsigned int"
 */
getVertexCount : function () {},

/**
 * @method getVertexTexCoord2FAt
 * @return A value converted from C/C++ "ccTex2F"
 * @param {unsigned int}
 */
getVertexTexCoord2FAt : function () {},

/**
 * @method getVertexIndexCountFromFaceCount
 * @return A value converted from C/C++ "unsigned int"
 * @param {unsigned int}
 */
getVertexIndexCountFromFaceCount : function () {},

/**
 * @method createVertexContent
 * @param {cocos3d::CC3VertexContent}
 */
createVertexContent : function () {},

/**
 * @method getVertexTextureCoordinates
 * @return A value converted from C/C++ "cocos3d::CC3VertexTextureCoordinates*"
 */
getVertexTextureCoordinates : function () {},

/**
 * @method getVertexPointSizeAt
 * @return A value converted from C/C++ "float"
 * @param {unsigned int}
 */
getVertexPointSizeAt : function () {},

/**
 * @method retainVertexTextureCoordinates
 */
retainVertexTextureCoordinates : function () {},

/**
 * @method setVertexTangents
 * @param {cocos3d::CC3VertexTangents*}
 */
setVertexTangents : function () {},

/**
 * @method hasVertexNormals
 * @return A value converted from C/C++ "bool"
 */
hasVertexNormals : function () {},

/**
 * @method updateGLBuffers
 */
updateGLBuffers : function () {},

/**
 * @method retainVertexPointSizes
 */
retainVertexPointSizes : function () {},

/**
 * @method getFaceNeighboursAt
 * @return A value converted from C/C++ "CC3FaceNeighbours"
 * @param {unsigned int}
 */
getFaceNeighboursAt : function () {},

/**
 * @method retainVertexNormals
 */
retainVertexNormals : function () {},

/**
 * @method flipHorizontallyTextureUnit
 * @param {unsigned int}
 */
flipHorizontallyTextureUnit : function () {},

/**
 * @method setVertexTextureCoordinates
 * @param {cocos3d::CC3VertexTextureCoordinates*}
 */
setVertexTextureCoordinates : function () {},

/**
 * @method meshWithName
 * @return A value converted from C/C++ "cocos3d::CC3Mesh*"
 * @param {std::string}
 */
meshWithName : function () {},

/**
 * @method mesh
 * @return A value converted from C/C++ "cocos3d::CC3Mesh*"
 */
mesh : function () {},

/**
 * @method CC3Mesh
 * @constructor
 */
CC3Mesh : function () {},

};

/**
 * @class CC3SoftBodyNode
 */
cc3.CC3SoftBodyNode = {

/**
 * @method getSoftBodyNode
 * @return A value converted from C/C++ "cocos3d::CC3SoftBodyNode*"
 */
getSoftBodyNode : function () {},

/**
 * @method addCopiesOfChildrenFrom
 * @param {cocos3d::CC3Node*}
 */
addCopiesOfChildrenFrom : function () {},

/**
 * @method getSkeletalScale
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getSkeletalScale : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3SoftBodyNode*"
 * @param {std::string}
 */
nodeWithName : function () {},

};

/**
 * @class CC3SkinMeshNode
 */
cc3.CC3SkinMeshNode = {

/**
 * @method defaultBoundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3NodeBoundingVolume*"
 */
defaultBoundingVolume : function () {},

/**
 * @method setDeformedFaces
 * @param {cocos3d::CC3DeformedFaceArray*}
 */
setDeformedFaces : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3SkinMeshNode*}
 */
populateFrom : function () {},

/**
 * @method getSkinSectionForVertexIndexAt
 * @return A value converted from C/C++ "cocos3d::CC3SkinSection*"
 * @param {int}
 */
getSkinSectionForVertexIndexAt : function () {},

/**
 * @method setSkeletalBoundingVolume
 * @param {cocos3d::CC3NodeBoundingVolume*}
 */
setSkeletalBoundingVolume : function () {},

/**
 * @method drawMeshWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawMeshWithVisitor : function () {},

/**
 * @method getDeformedFaceAt
 * @return A value converted from C/C++ "CC3Face"
 * @param {unsigned int}
 */
getDeformedFaceAt : function () {},

/**
 * @method boneWasTransformed
 * @param {cocos3d::CC3Bone*}
 */
boneWasTransformed : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method getSkinSections
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getSkinSections : function () {},

/**
 * @method getDeformedFaceCenterAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getDeformedFaceCenterAt : function () {},

/**
 * @method reattachBonesFrom
 * @param {cocos3d::CC3Node*}
 */
reattachBonesFrom : function () {},

/**
 * @method getSkeletalTransformMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getSkeletalTransformMatrix : function () {},

/**
 * @method markTransformDirty
 */
markTransformDirty : function () {},

/**
 * @method getDeformedVertexLocationAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 * @param {unsigned int}
 */
getDeformedVertexLocationAt : function () {},

/**
 * @method createBoundingVolumes
 */
createBoundingVolumes : function () {},

/**
 * @method hasSoftBodyContent
 * @return A value converted from C/C++ "bool"
 */
hasSoftBodyContent : function () {},

/**
 * @method hasRigidSkeleton
 * @return A value converted from C/C++ "bool"
 */
hasRigidSkeleton : function () {},

/**
 * @method getSkinSectionForFaceIndex
 * @return A value converted from C/C++ "cocos3d::CC3SkinSection*"
 * @param {int}
 */
getSkinSectionForFaceIndex : function () {},

/**
 * @method addShadowVolumesForLight
 * @param {cocos3d::CC3Light*}
 */
addShadowVolumesForLight : function () {},

/**
 * @method getDeformedFacePlaneAt
 * @return A value converted from C/C++ "CC3Plane"
 * @param {unsigned int}
 */
getDeformedFacePlaneAt : function () {},

/**
 * @method createSkinnedBoundingVolumes
 */
createSkinnedBoundingVolumes : function () {},

/**
 * @method getSkeletalTransformMatrixInverted
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getSkeletalTransformMatrixInverted : function () {},

/**
 * @method setShouldCacheFaces
 * @param {bool}
 */
setShouldCacheFaces : function () {},

/**
 * @method getDeformedFaceNormalAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getDeformedFaceNormalAt : function () {},

/**
 * @method hasSkeleton
 * @return A value converted from C/C++ "bool"
 */
hasSkeleton : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method getDeformedFaces
 * @return A value converted from C/C++ "cocos3d::CC3DeformedFaceArray*"
 */
getDeformedFaces : function () {},

/**
 * @method ensureRigidSkeleton
 */
ensureRigidSkeleton : function () {},

/**
 * @method CC3SkinMeshNode
 * @constructor
 */
CC3SkinMeshNode : function () {},

};

/**
 * @class CC3SkinSection
 */
cc3.CC3SkinSection = {

/**
 * @method populateFrom
 * @param {cocos3d::CC3SkinSection*}
 */
populateFrom : function () {},

/**
 * @method getVertexStart
 * @return A value converted from C/C++ "int"
 */
getVertexStart : function () {},

/**
 * @method containsVertexIndex
 * @return A value converted from C/C++ "bool"
 * @param {int}
 */
containsVertexIndex : function () {},

/**
 * @method getBoneCount
 * @return A value converted from C/C++ "unsigned int"
 */
getBoneCount : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method getTransformMatrixForBoneAt
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 * @param {unsigned int}
 */
getTransformMatrixForBoneAt : function () {},

/**
 * @method reattachBonesFrom
 * @param {cocos3d::CC3Node*}
 */
reattachBonesFrom : function () {},

/**
 * @method init
 */
init : function () {},

/**
 * @method getDeformedVertexLocationAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getDeformedVertexLocationAt : function () {},

/**
 * @method drawVerticesOfMesh
 * @param {cocos3d::CC3Mesh*}
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawVerticesOfMesh : function () {},

/**
 * @method getBoneAt
 * @return A value converted from C/C++ "cocos3d::CC3Bone*"
 * @param {unsigned int}
 */
getBoneAt : function () {},

/**
 * @method hasRigidSkeleton
 * @return A value converted from C/C++ "bool"
 */
hasRigidSkeleton : function () {},

/**
 * @method addBone
 * @param {cocos3d::CC3Bone*}
 */
addBone : function () {},

/**
 * @method getVertexCount
 * @return A value converted from C/C++ "int"
 */
getVertexCount : function () {},

/**
 * @method initForNode
 * @param {cocos3d::CC3SkinMeshNode*}
 */
initForNode : function () {},

/**
 * @method getBones
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getBones : function () {},

/**
 * @method fullDescription
 * @return A value converted from C/C++ "std::string"
 */
fullDescription : function () {},

/**
 * @method hasSkeleton
 * @return A value converted from C/C++ "bool"
 */
hasSkeleton : function () {},

/**
 * @method setVertexCount
 * @param {int}
 */
setVertexCount : function () {},

/**
 * @method setVertexStart
 * @param {int}
 */
setVertexStart : function () {},

/**
 * @method skinSectionForNode
 * @return A value converted from C/C++ "cocos3d::CC3SkinSection*"
 * @param {cocos3d::CC3SkinMeshNode*}
 */
skinSectionForNode : function () {},

/**
 * @method CC3SkinSection
 * @constructor
 */
CC3SkinSection : function () {},

};

/**
 * @class CC3Bone
 */
cc3.CC3Bone = {

/**
 * @method hasSoftBodyContent
 * @return A value converted from C/C++ "bool"
 */
hasSoftBodyContent : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Bone*}
 */
populateFrom : function () {},

/**
 * @method cacheRestPoseMatrix
 */
cacheRestPoseMatrix : function () {},

/**
 * @method markTransformDirty
 */
markTransformDirty : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method bindRestPose
 */
bindRestPose : function () {},

/**
 * @method ensureRigidSkeleton
 */
ensureRigidSkeleton : function () {},

/**
 * @method getSkeletalTransformMatrix
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getSkeletalTransformMatrix : function () {},

/**
 * @method getRestPoseSkeletalTransformMatrixInverted
 * @return A value converted from C/C++ "cocos3d::CC3Matrix*"
 */
getRestPoseSkeletalTransformMatrixInverted : function () {},

/**
 * @method CC3Bone
 * @constructor
 */
CC3Bone : function () {},

};

/**
 * @class CC3Action
 */
cc3.CC3Action = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method getTargetNode
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
getTargetNode : function () {},

/**
 * @method CC3Action
 * @constructor
 */
CC3Action : function () {},

};

/**
 * @class CC3ActionInterval
 */
cc3.CC3ActionInterval = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method getTargetNode
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
getTargetNode : function () {},

/**
 * @method repeatForever
 * @return A value converted from C/C++ "cocos2d::CCAction*"
 */
repeatForever : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method initWithDuration
 * @param {float}
 */
initWithDuration : function () {},

};

/**
 * @class CC3ActionTransformVector
 */
cc3.CC3ActionTransformVector = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionTransformVector*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionTransformBy
 */
cc3.CC3ActionTransformBy = {

};

/**
 * @class CC3ActionMoveBy
 */
cc3.CC3ActionMoveBy = {

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionMoveBy*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionRotateBy
 */
cc3.CC3ActionRotateBy = {

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionRotateBy*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3RepeatForever
 */
cc3.CC3RepeatForever = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method setInnerAction
 * @param {cocos3d::CC3ActionInterval*}
 */
setInnerAction : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method step
 * @param {float}
 */
step : function () {},

/**
 * @method initWithAction
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3ActionInterval*}
 */
initWithAction : function () {},

/**
 * @method getInnerAction
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
getInnerAction : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos3d::CC3RepeatForever*"
 * @param {cocos3d::CC3ActionInterval*}
 */
create : function () {},

/**
 * @method CC3RepeatForever
 * @constructor
 */
CC3RepeatForever : function () {},

};

/**
 * @class CC3ActionRotateForever
 */
cc3.CC3ActionRotateForever = {

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method initWithRotationRate
 * @param {cocos3d::CC3Vector}
 */
initWithRotationRate : function () {},

/**
 * @method actionWithRotationRate
 * @return A value converted from C/C++ "cocos3d::CC3ActionRotateForever*"
 * @param {cocos3d::CC3Vector}
 */
actionWithRotationRate : function () {},

};

/**
 * @class CC3ActionScaleBy
 */
cc3.CC3ActionScaleBy = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

};

/**
 * @class CC3ActionRotateByAngle
 */
cc3.CC3ActionRotateByAngle = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

};

/**
 * @class CC3ActionRotateOnAxisForever
 */
cc3.CC3ActionRotateOnAxisForever = {

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method initWithRotationRate
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithRotationRate : function () {},

/**
 * @method actionWithRotationRate
 * @return A value converted from C/C++ "cocos3d::CC3ActionRotateOnAxisForever*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithRotationRate : function () {},

};

/**
 * @class CC3ActionTransformTo
 */
cc3.CC3ActionTransformTo = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionTransformTo*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionMoveTo
 */
cc3.CC3ActionMoveTo = {

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionMoveTo*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionRotateTo
 */
cc3.CC3ActionRotateTo = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionRotateTo*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionScaleTo
 */
cc3.CC3ActionScaleTo = {

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

};

/**
 * @class CC3ActionRotateToAngle
 */
cc3.CC3ActionRotateToAngle = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {float}
 */
initWithDuration : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionRotateToAngle*"
 * @param {float}
 * @param {float}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionRotateToLookTowards
 */
cc3.CC3ActionRotateToLookTowards = {

/**
 * @method getTargetVector
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetVector : function () {},

/**
 * @method setTargetVector
 * @param {cocos3d::CC3Vector}
 */
setTargetVector : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionRotateToLookTowards*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionRotateToLookAt
 */
cc3.CC3ActionRotateToLookAt = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
initWithDuration : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionRotateToLookAt*"
 * @param {float}
 * @param {cocos3d::CC3Vector}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionMoveDirectionallyBy
 */
cc3.CC3ActionMoveDirectionallyBy = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {float}
 */
initWithDuration : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getTargetDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetDirection : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionMoveDirectionallyBy*"
 * @param {float}
 * @param {float}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionMoveForwardBy
 */
cc3.CC3ActionMoveForwardBy = {

/**
 * @method getTargetDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetDirection : function () {},

};

/**
 * @class CC3ActionMoveRightBy
 */
cc3.CC3ActionMoveRightBy = {

/**
 * @method getTargetDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetDirection : function () {},

};

/**
 * @class CC3ActionMoveUpBy
 */
cc3.CC3ActionMoveUpBy = {

/**
 * @method getTargetDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getTargetDirection : function () {},

};

/**
 * @class CC3ActionTintTo
 */
cc3.CC3ActionTintTo = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos2d::ccColor4F}
 */
initWithDuration : function () {},

/**
 * @method setTargetColor
 * @param {cocos2d::ccColor4F}
 */
setTargetColor : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getTargetColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getTargetColor : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionTintTo*"
 * @param {float}
 * @param {cocos2d::ccColor4F}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionTintAmbientTo
 */
cc3.CC3ActionTintAmbientTo = {

/**
 * @method setTargetColor
 * @param {cocos2d::ccColor4F}
 */
setTargetColor : function () {},

/**
 * @method getTargetColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getTargetColor : function () {},

};

/**
 * @class CC3ActionTintDiffuseTo
 */
cc3.CC3ActionTintDiffuseTo = {

/**
 * @method setTargetColor
 * @param {cocos2d::ccColor4F}
 */
setTargetColor : function () {},

/**
 * @method getTargetColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getTargetColor : function () {},

};

/**
 * @class CC3ActionTintSpecularTo
 */
cc3.CC3ActionTintSpecularTo = {

/**
 * @method setTargetColor
 * @param {cocos2d::ccColor4F}
 */
setTargetColor : function () {},

/**
 * @method getTargetColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getTargetColor : function () {},

};

/**
 * @class CC3ActionTintEmissionTo
 */
cc3.CC3ActionTintEmissionTo = {

/**
 * @method setTargetColor
 * @param {cocos2d::ccColor4F}
 */
setTargetColor : function () {},

/**
 * @method getTargetColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getTargetColor : function () {},

};

/**
 * @class CC3ActionAnimate
 */
cc3.CC3ActionAnimate = {

/**
 * @method isReversed
 * @return A value converted from C/C++ "bool"
 */
isReversed : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method setIsReversed
 * @param {bool}
 */
setIsReversed : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getTrackID
 * @return A value converted from C/C++ "unsigned int"
 */
getTrackID : function () {},

/**
 * @method asActionLimitedFrom
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 * @param {float}
 * @param {float}
 */
asActionLimitedFrom : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

};

/**
 * @class CC3ActionAnimationBlendingFadeTrackTo
 */
cc3.CC3ActionAnimationBlendingFadeTrackTo = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {unsigned int}
 * @param {float}
 */
initWithDuration : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getTrackID
 * @return A value converted from C/C++ "unsigned int"
 */
getTrackID : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionAnimationBlendingFadeTrackTo*"
 * @param {float}
 * @param {unsigned int}
 * @param {float}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionAnimationCrossFade
 */
cc3.CC3ActionAnimationCrossFade = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getToTrackID
 * @return A value converted from C/C++ "unsigned int"
 */
getToTrackID : function () {},

/**
 * @method getFromTrackID
 * @return A value converted from C/C++ "unsigned int"
 */
getFromTrackID : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

};

/**
 * @class CC3ActionAnimationBlendingSetTrackTo
 */
cc3.CC3ActionAnimationBlendingSetTrackTo = {

/**
 * @method getTrackID
 * @return A value converted from C/C++ "unsigned int"
 */
getTrackID : function () {},

/**
 * @method initOnTrack
 * @param {unsigned int}
 * @param {float}
 */
initOnTrack : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method actionOnTrack
 * @return A value converted from C/C++ "cocos3d::CC3ActionAnimationBlendingSetTrackTo*"
 * @param {unsigned int}
 * @param {float}
 */
actionOnTrack : function () {},

};

/**
 * @class CC3ActionEnableAnimationTrack
 */
cc3.CC3ActionEnableAnimationTrack = {

/**
 * @method getTrackID
 * @return A value converted from C/C++ "unsigned int"
 */
getTrackID : function () {},

/**
 * @method initOnTrack
 * @param {unsigned int}
 */
initOnTrack : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method actionOnTrack
 * @return A value converted from C/C++ "cocos3d::CC3ActionEnableAnimationTrack*"
 * @param {unsigned int}
 */
actionOnTrack : function () {},

};

/**
 * @class CC3ActionDisableAnimationTrack
 */
cc3.CC3ActionDisableAnimationTrack = {

/**
 * @method getTrackID
 * @return A value converted from C/C++ "unsigned int"
 */
getTrackID : function () {},

/**
 * @method initOnTrack
 * @param {unsigned int}
 */
initOnTrack : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method actionOnTrack
 * @return A value converted from C/C++ "cocos3d::CC3ActionDisableAnimationTrack*"
 * @param {unsigned int}
 */
actionOnTrack : function () {},

};

/**
 * @class CC3ActionRangeLimit
 */
cc3.CC3ActionRangeLimit = {

/**
 * @method initWithAction
 * @param {cocos2d::CCActionInterval*}
 * @param {float}
 * @param {float}
 */
initWithAction : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::CCActionInterval*"
 */
reverse : function () {},

/**
 * @method actionWithAction
 * @return A value converted from C/C++ "cocos3d::CC3ActionRangeLimit*"
 * @param {cocos2d::CCActionInterval*}
 * @param {float}
 * @param {float}
 */
actionWithAction : function () {},

};

/**
 * @class CC3ActionRemove
 */
cc3.CC3ActionRemove = {

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos3d::CC3ActionRemove*"
 */
create : function () {},

};

/**
 * @class CC3ActionCCNodeSizeTo
 */
cc3.CC3ActionCCNodeSizeTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::CCNode*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method initWithDuration
 * @param {float}
 * @param {cocos2d::CCSize}
 */
initWithDuration : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method actionWithDuration
 * @return A value converted from C/C++ "cocos3d::CC3ActionCCNodeSizeTo*"
 * @param {float}
 * @param {cocos2d::CCSize}
 */
actionWithDuration : function () {},

};

/**
 * @class CC3ActionSequence
 */
cc3.CC3ActionSequence = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method initWithTwoActions
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3ActionInterval*}
 * @param {cocos3d::CC3ActionInterval*}
 */
initWithTwoActions : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method createWithTwoActions
 * @return A value converted from C/C++ "cocos3d::CC3ActionSequence*"
 * @param {cocos3d::CC3ActionInterval*}
 * @param {cocos3d::CC3ActionInterval*}
 */
createWithTwoActions : function () {},

};

/**
 * @class CC3ActionSpawn
 */
cc3.CC3ActionSpawn = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method initWithTwoActions
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3ActionInterval*}
 * @param {cocos3d::CC3ActionInterval*}
 */
initWithTwoActions : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos3d::CC3ActionSpawn*"
 * @param {cocos2d::CCArray*}
 */
create : function () {},

/**
 * @method createWithTwoActions
 * @return A value converted from C/C++ "cocos3d::CC3ActionSpawn*"
 * @param {cocos3d::CC3ActionInterval*}
 * @param {cocos3d::CC3ActionInterval*}
 */
createWithTwoActions : function () {},

};

/**
 * @class CC3ActionDelayTime
 */
cc3.CC3ActionDelayTime = {

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos3d::CC3ActionDelayTime*"
 * @param {float}
 */
create : function () {},

};

/**
 * @class CC3ActionBezierBy
 */
cc3.CC3ActionBezierBy = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos3d::CC3ActionInterval*"
 */
reverse : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {cocos3d::ccBezier3DConfig}
 */
initWithDuration : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos3d::CC3ActionBezierBy*"
 * @param {float}
 * @param {cocos3d::ccBezier3DConfig}
 */
create : function () {},

};

/**
 * @class CC3ActionBezierTo
 */
cc3.CC3ActionBezierTo = {

/**
 * @method startWithTarget
 * @param {cocos3d::CC3Node*}
 */
startWithTarget : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {cocos3d::ccBezier3DConfig}
 */
initWithDuration : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos3d::CC3ActionBezierTo*"
 * @param {float}
 * @param {cocos3d::ccBezier3DConfig}
 */
create : function () {},

};

/**
 * @class CC3NodeAnimation
 */
cc3.CC3NodeAnimation = {

/**
 * @method timeAtFrame
 * @return A value converted from C/C++ "float"
 * @param {unsigned int}
 */
timeAtFrame : function () {},

/**
 * @method getQuaternionAtFrame
 * @return A value converted from C/C++ "CC3Quaternion"
 * @param {unsigned int}
 */
getQuaternionAtFrame : function () {},

/**
 * @method establishFrameAt
 * @param {float}
 * @param {cocos3d::CC3NodeAnimationState*}
 */
establishFrameAt : function () {},

/**
 * @method isAnimatingQuaternion
 * @return A value converted from C/C++ "bool"
 */
isAnimatingQuaternion : function () {},

/**
 * @method getFrameIndexAt
 * @return A value converted from C/C++ "unsigned int"
 * @param {float}
 */
getFrameIndexAt : function () {},

/**
 * @method establishQuaternionAtFrame
 * @param {unsigned int}
 * @param {float}
 * @param {cocos3d::CC3NodeAnimationState*}
 */
establishQuaternionAtFrame : function () {},

/**
 * @method shouldInterpolate
 * @return A value converted from C/C++ "bool"
 */
shouldInterpolate : function () {},

/**
 * @method getLocationAtFrame
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getLocationAtFrame : function () {},

/**
 * @method getFrameCount
 * @return A value converted from C/C++ "unsigned int"
 */
getFrameCount : function () {},

/**
 * @method setShouldInterpolate
 * @param {bool}
 */
setShouldInterpolate : function () {},

/**
 * @method initWithFrameCount
 * @param {unsigned int}
 */
initWithFrameCount : function () {},

/**
 * @method establishLocationAtFrame
 * @param {unsigned int}
 * @param {float}
 * @param {cocos3d::CC3NodeAnimationState*}
 */
establishLocationAtFrame : function () {},

/**
 * @method establishFrame
 * @param {unsigned int}
 * @param {float}
 * @param {cocos3d::CC3NodeAnimationState*}
 */
establishFrame : function () {},

/**
 * @method isAnimating
 * @return A value converted from C/C++ "bool"
 */
isAnimating : function () {},

/**
 * @method getScaleAtFrame
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getScaleAtFrame : function () {},

/**
 * @method isAnimatingScale
 * @return A value converted from C/C++ "bool"
 */
isAnimatingScale : function () {},

/**
 * @method isAnimatingLocation
 * @return A value converted from C/C++ "bool"
 */
isAnimatingLocation : function () {},

/**
 * @method hasVariableFrameTiming
 * @return A value converted from C/C++ "bool"
 */
hasVariableFrameTiming : function () {},

/**
 * @method establishScaleAtFrame
 * @param {unsigned int}
 * @param {float}
 * @param {cocos3d::CC3NodeAnimationState*}
 */
establishScaleAtFrame : function () {},

/**
 * @method animationWithFrameCount
 * @return A value converted from C/C++ "cocos3d::CC3NodeAnimation*"
 * @param {unsigned int}
 */
animationWithFrameCount : function () {},

/**
 * @method getInterpolationEpsilon
 * @return A value converted from C/C++ "float"
 */
getInterpolationEpsilon : function () {},

/**
 * @method setInterpolationEpsilon
 * @param {float}
 */
setInterpolationEpsilon : function () {},

/**
 * @method CC3NodeAnimation
 * @constructor
 */
CC3NodeAnimation : function () {},

};

/**
 * @class CC3ActionManager
 */
cc3.CC3ActionManager = {

/**
 * @method addAction
 * @param {cocos3d::CC3Action*}
 * @param {cocos3d::CC3Node*}
 * @param {bool}
 */
addAction : function () {},

/**
 * @method removeAction
 * @param {cocos2d::CCObject*}
 */
removeAction : function () {},

/**
 * @method active
 */
active : function () {},

};

/**
 * @class CC3ResourceNode
 */
cc3.CC3ResourceNode = {

/**
 * @method initWithName
 * @return A value converted from C/C++ "bool"
 * @param {std::string}
 * @param {std::string}
 */
initWithName : function () {},

/**
 * @method populateFromResource
 * @param {cocos3d::CC3NodesResource*}
 */
populateFromResource : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3ResourceNode*"
 * @param {std::string}
 * @param {std::string}
 */
nodeWithName : function () {},

/**
 * @method CC3ResourceNode
 * @constructor
 */
CC3ResourceNode : function () {},

};

/**
 * @class CC3Material
 */
cc3.CC3Material = {

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 */
getTexture : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method removeTexture
 * @param {cocos3d::CC3Texture*}
 */
removeTexture : function () {},

/**
 * @method getEmissionColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getEmissionColor : function () {},

/**
 * @method shouldApplyOpacityToColor
 * @return A value converted from C/C++ "bool"
 */
shouldApplyOpacityToColor : function () {},

/**
 * @method getBlendFuncAlpha
 * @return A value converted from C/C++ "ccBlendFunc"
 */
getBlendFuncAlpha : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method addTexture
 * @param {cocos3d::CC3Texture*}
 */
addTexture : function () {},

/**
 * @method getEffectiveEmissionColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getEffectiveEmissionColor : function () {},

/**
 * @method getDiffuseColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getDiffuseColor : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {unsigned char}
 */
updateDisplayedOpacity : function () {},

/**
 * @method setIsOpaque
 * @param {bool}
 */
setIsOpaque : function () {},

/**
 * @method shouldBlendAtFullOpacity
 * @return A value converted from C/C++ "bool"
 */
shouldBlendAtFullOpacity : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getColor : function () {},

/**
 * @method setDestinationBlend
 * @param {unsigned int}
 */
setDestinationBlend : function () {},

/**
 * @method drawTexturesWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawTexturesWithVisitor : function () {},

/**
 * @method setShininess
 * @param {float}
 */
setShininess : function () {},

/**
 * @method applyEffectNamedFromRez
 * @param {std::string}
 * @param {std::string}
 */
applyEffectNamedFromRez : function () {},

/**
 * @method shouldDrawLowAlpha
 * @return A value converted from C/C++ "bool"
 */
shouldDrawLowAlpha : function () {},

/**
 * @method getLightDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLightDirection : function () {},

/**
 * @method getNameSuffix
 * @return A value converted from C/C++ "std::string"
 */
getNameSuffix : function () {},

/**
 * @method getDestinationBlend
 * @return A value converted from C/C++ "unsigned int"
 */
getDestinationBlend : function () {},

/**
 * @method getTextureCube
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 */
getTextureCube : function () {},

/**
 * @method isOpaque
 * @return A value converted from C/C++ "bool"
 */
isOpaque : function () {},

/**
 * @method getDestinationBlendAlpha
 * @return A value converted from C/C++ "unsigned int"
 */
getDestinationBlendAlpha : function () {},

/**
 * @method getEffectiveSpecularColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getEffectiveSpecularColor : function () {},

/**
 * @method setEmissionColor
 * @param {cocos2d::ccColor4F}
 */
setEmissionColor : function () {},

/**
 * @method getSourceBlendRGB
 * @return A value converted from C/C++ "unsigned int"
 */
getSourceBlendRGB : function () {},

/**
 * @method getReflectivity
 * @return A value converted from C/C++ "float"
 */
getReflectivity : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method drawWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawWithVisitor : function () {},

/**
 * @method getEffectiveDiffuseColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getEffectiveDiffuseColor : function () {},

/**
 * @method setAlphaTestReference
 * @param {float}
 */
setAlphaTestReference : function () {},

/**
 * @method setColor
 * @param {cocos3d::CCColorRef}
 */
setColor : function () {},

/**
 * @method setSourceBlend
 * @param {unsigned int}
 */
setSourceBlend : function () {},

/**
 * @method getDisplayedColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getDisplayedColor : function () {},

/**
 * @method setSpecularColor
 * @param {cocos2d::ccColor4F}
 */
setSpecularColor : function () {},

/**
 * @method getTextureCount
 * @return A value converted from C/C++ "unsigned int"
 */
getTextureCount : function () {},

/**
 * @method setSourceBlendRGB
 * @param {unsigned int}
 */
setSourceBlendRGB : function () {},

/**
 * @method setDiffuseColor
 * @param {cocos2d::ccColor4F}
 */
setDiffuseColor : function () {},

/**
 * @method hasBumpMap
 * @return A value converted from C/C++ "bool"
 */
hasBumpMap : function () {},

/**
 * @method setShouldDrawLowAlpha
 * @param {bool}
 */
setShouldDrawLowAlpha : function () {},

/**
 * @method setReflectivity
 * @param {float}
 */
setReflectivity : function () {},

/**
 * @method setAmbientColor
 * @param {cocos2d::ccColor4F}
 */
setAmbientColor : function () {},

/**
 * @method setDestinationBlendRGB
 * @param {unsigned int}
 */
setDestinationBlendRGB : function () {},

/**
 * @method setShouldBlendAtFullOpacity
 * @param {bool}
 */
setShouldBlendAtFullOpacity : function () {},

/**
 * @method getShininess
 * @return A value converted from C/C++ "float"
 */
getShininess : function () {},

/**
 * @method getTextureForTextureUnit
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {unsigned int}
 */
getTextureForTextureUnit : function () {},

/**
 * @method setSourceBlendAlpha
 * @param {unsigned int}
 */
setSourceBlendAlpha : function () {},

/**
 * @method texturesHaveChanged
 */
texturesHaveChanged : function () {},

/**
 * @method applyColorsWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyColorsWithVisitor : function () {},

/**
 * @method getAmbientColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getAmbientColor : function () {},

/**
 * @method setDestinationBlendAlpha
 * @param {unsigned int}
 */
setDestinationBlendAlpha : function () {},

/**
 * @method hasTextureCube
 * @return A value converted from C/C++ "bool"
 */
hasTextureCube : function () {},

/**
 * @method applyAlphaTestWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyAlphaTestWithVisitor : function () {},

/**
 * @method hasTextureAlpha
 * @return A value converted from C/C++ "bool"
 */
hasTextureAlpha : function () {},

/**
 * @method getDisplayedOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getDisplayedOpacity : function () {},

/**
 * @method setShouldUseLighting
 * @param {bool}
 */
setShouldUseLighting : function () {},

/**
 * @method getDestinationBlendRGB
 * @return A value converted from C/C++ "unsigned int"
 */
getDestinationBlendRGB : function () {},

/**
 * @method getSourceBlendAlpha
 * @return A value converted from C/C++ "unsigned int"
 */
getSourceBlendAlpha : function () {},

/**
 * @method getSourceBlend
 * @return A value converted from C/C++ "unsigned int"
 */
getSourceBlend : function () {},

/**
 * @method setLightDirection
 * @param {cocos3d::CC3Vector}
 */
setLightDirection : function () {},

/**
 * @method setBlendFuncAlpha
 * @param {cocos2d::ccBlendFunc}
 */
setBlendFuncAlpha : function () {},

/**
 * @method updateDisplayedColor
 * @param {cocos3d::CCColorRef}
 */
updateDisplayedColor : function () {},

/**
 * @method getAlphaTestFunction
 * @return A value converted from C/C++ "unsigned int"
 */
getAlphaTestFunction : function () {},

/**
 * @method hasTexturePremultipliedAlpha
 * @return A value converted from C/C++ "bool"
 */
hasTexturePremultipliedAlpha : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Material*}
 */
populateFrom : function () {},

/**
 * @method removeAllTextures
 */
removeAllTextures : function () {},

/**
 * @method getAlphaTestReference
 * @return A value converted from C/C++ "float"
 */
getAlphaTestReference : function () {},

/**
 * @method getBlendFuncRGB
 * @return A value converted from C/C++ "ccBlendFunc"
 */
getBlendFuncRGB : function () {},

/**
 * @method applyBlendWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
applyBlendWithVisitor : function () {},

/**
 * @method applyEffectNamedFromFile
 * @param {std::string}
 * @param {std::string}
 */
applyEffectNamedFromFile : function () {},

/**
 * @method setCascadeColorEnabled
 * @param {bool}
 */
setCascadeColorEnabled : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method setBlendFuncRGB
 * @param {cocos2d::ccBlendFunc}
 */
setBlendFuncRGB : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method getEffectiveAmbientColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getEffectiveAmbientColor : function () {},

/**
 * @method setAlphaTestFunction
 * @param {unsigned int}
 */
setAlphaTestFunction : function () {},

/**
 * @method getBlendFunc
 * @return A value converted from C/C++ "ccBlendFunc"
 */
getBlendFunc : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method getTextureNamed
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {const char*}
 */
getTextureNamed : function () {},

/**
 * @method setBlendFunc
 * @param {cocos2d::ccBlendFunc}
 */
setBlendFunc : function () {},

/**
 * @method getSpecularColor
 * @return A value converted from C/C++ "ccColor4F"
 */
getSpecularColor : function () {},

/**
 * @method shouldUseLighting
 * @return A value converted from C/C++ "bool"
 */
shouldUseLighting : function () {},

/**
 * @method shinyWhite
 * @return A value converted from C/C++ "cocos3d::CC3Material*"
 */
shinyWhite : function () {},

/**
 * @method materialWithName
 * @return A value converted from C/C++ "cocos3d::CC3Material*"
 * @param {std::string}
 */
materialWithName : function () {},

/**
 * @method material
 * @return A value converted from C/C++ "cocos3d::CC3Material*"
 */
material : function () {},

/**
 * @method setDefaultBlendFunc
 * @param {cocos2d::ccBlendFunc}
 */
setDefaultBlendFunc : function () {},

/**
 * @method unbindWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
unbindWithVisitor : function () {},

/**
 * @method shiny
 * @return A value converted from C/C++ "cocos3d::CC3Material*"
 */
shiny : function () {},

/**
 * @method getDefaultBlendFunc
 * @return A value converted from C/C++ "ccBlendFunc"
 */
getDefaultBlendFunc : function () {},

/**
 * @method CC3Material
 * @constructor
 */
CC3Material : function () {},

};

/**
 * @class CC3Texture
 */
cc3.CC3Texture = {

/**
 * @method shouldFlipVerticallyOnLoad
 * @return A value converted from C/C++ "bool"
 */
shouldFlipVerticallyOnLoad : function () {},

/**
 * @method incrementTextureUnitInVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
incrementTextureUnitInVisitor : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Texture*}
 */
populateFrom : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 */
getTexture : function () {},

/**
 * @method cachedTexturesDescription
 * @return A value converted from C/C++ "std::string"
 */
cachedTexturesDescription : function () {},

/**
 * @method replacePixels
 * @param {cocos3d::CC3Viewport}
 * @param {unsigned int}
 * @param {ccColor4B*}
 */
replacePixels : function () {},

/**
 * @method shouldFlipHorizontallyOnLoad
 * @return A value converted from C/C++ "bool"
 */
shouldFlipHorizontallyOnLoad : function () {},

/**
 * @method getHorizontalWrappingFunction
 * @return A value converted from C/C++ "unsigned int"
 */
getHorizontalWrappingFunction : function () {},

/**
 * @method initCubeFromFiles
 * @return A value converted from C/C++ "bool"
 * @param {std::string}
 * @param {std::string}
 * @param {std::string}
 * @param {std::string}
 * @param {std::string}
 * @param {std::string}
 */
initCubeFromFiles : function () {},

/**
 * @method getPixelType
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelType : function () {},

/**
 * @method getCoverage
 * @return A value converted from C/C++ "cocos2d::CCSize"
 */
getCoverage : function () {},

/**
 * @method getTextureUnitFromVisitor
 * @return A value converted from C/C++ "unsigned int"
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
getTextureUnitFromVisitor : function () {},

/**
 * @method markTextureParametersDirty
 */
markTextureParametersDirty : function () {},

/**
 * @method initCubeWithPixelFormat
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 * @param {unsigned int}
 */
initCubeWithPixelFormat : function () {},

/**
 * @method hasPremultipliedAlpha
 * @return A value converted from C/C++ "bool"
 */
hasPremultipliedAlpha : function () {},

/**
 * @method ensureGLTexture
 */
ensureGLTexture : function () {},

/**
 * @method setMagnifyingFunction
 * @param {unsigned int}
 */
setMagnifyingFunction : function () {},

/**
 * @method isPOTHeight
 * @return A value converted from C/C++ "bool"
 */
isPOTHeight : function () {},

/**
 * @method bindTextureParametersAt
 * @param {unsigned int}
 * @param {cocos3d::CC3OpenGL*}
 */
bindTextureParametersAt : function () {},

/**
 * @method getMagnifyingFunction
 * @return A value converted from C/C++ "unsigned int"
 */
getMagnifyingFunction : function () {},

/**
 * @method initCubeWithSideLength
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {unsigned int}
 */
initCubeWithSideLength : function () {},

/**
 * @method getInitialAttachmentFace
 * @return A value converted from C/C++ "unsigned int"
 */
getInitialAttachmentFace : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method initWithCCTexture
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3CCTexture*}
 */
initWithCCTexture : function () {},

/**
 * @method setCCTexture
 * @param {cocos3d::CC3CCTexture*}
 */
setCCTexture : function () {},

/**
 * @method drawWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawWithVisitor : function () {},

/**
 * @method initCubeFromFilePattern
 * @return A value converted from C/C++ "bool"
 * @param {std::string}
 */
initCubeFromFilePattern : function () {},

/**
 * @method setMinifyingFunction
 * @param {unsigned int}
 */
setMinifyingFunction : function () {},

/**
 * @method isTextureCube
 * @return A value converted from C/C++ "bool"
 */
isTextureCube : function () {},

/**
 * @method getSizedContent
 * @return A value converted from C/C++ "cocos3d::CC3CCTexture*"
 */
getSizedContent : function () {},

/**
 * @method setVerticalWrappingFunction
 * @param {unsigned int}
 */
setVerticalWrappingFunction : function () {},

/**
 * @method cacheCCTexture2D
 */
cacheCCTexture2D : function () {},

/**
 * @method getTextureUnit
 * @return A value converted from C/C++ "cocos3d::CC3TextureUnit*"
 */
getTextureUnit : function () {},

/**
 * @method getMinifyingFunction
 * @return A value converted from C/C++ "unsigned int"
 */
getMinifyingFunction : function () {},

/**
 * @method getTextureTarget
 * @return A value converted from C/C++ "unsigned int"
 */
getTextureTarget : function () {},

/**
 * @method initCubeColoredForAxes
 * @return A value converted from C/C++ "bool"
 */
initCubeColoredForAxes : function () {},

/**
 * @method getTextureParameters
 * @return A value converted from C/C++ "ccTexParams"
 */
getTextureParameters : function () {},

/**
 * @method getTextureID
 * @return A value converted from C/C++ "unsigned int"
 */
getTextureID : function () {},

/**
 * @method generateMipmap
 */
generateMipmap : function () {},

/**
 * @method setTextureParameters
 * @param {cocos2d::ccTexParams}
 */
setTextureParameters : function () {},

/**
 * @method setName
 * @param {std::string}
 */
setName : function () {},

/**
 * @method setHorizontalWrappingFunction
 * @param {unsigned int}
 */
setHorizontalWrappingFunction : function () {},

/**
 * @method bindTextureEnvironmentWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
bindTextureEnvironmentWithVisitor : function () {},

/**
 * @method getPixelFormat
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelFormat : function () {},

/**
 * @method hasAlpha
 * @return A value converted from C/C++ "bool"
 */
hasAlpha : function () {},

/**
 * @method bindTextureContent
 * @param {cocos3d::CC3CCTexture*}
 * @param {unsigned int}
 */
bindTextureContent : function () {},

/**
 * @method getVerticalWrappingFunction
 * @return A value converted from C/C++ "unsigned int"
 */
getVerticalWrappingFunction : function () {},

/**
 * @method getCCTexture
 * @return A value converted from C/C++ "cocos3d::CC3CCTexture*"
 */
getCCTexture : function () {},

/**
 * @method isPOT
 * @return A value converted from C/C++ "bool"
 */
isPOT : function () {},

/**
 * @method setTextureUnit
 * @param {cocos3d::CC3TextureUnit*}
 */
setTextureUnit : function () {},

/**
 * @method getByteAlignment
 * @return A value converted from C/C++ "unsigned int"
 */
getByteAlignment : function () {},

/**
 * @method checkTextureOrientation
 * @param {cocos3d::CC3CCTexture*}
 */
checkTextureOrientation : function () {},

/**
 * @method initFromFile
 * @return A value converted from C/C++ "bool"
 * @param {std::string}
 */
initFromFile : function () {},

/**
 * @method setIsUpsideDown
 * @param {bool}
 */
setIsUpsideDown : function () {},

/**
 * @method getSize
 * @return A value converted from C/C++ "CC3IntSize"
 */
getSize : function () {},

/**
 * @method setShouldFlipVerticallyOnLoad
 * @param {bool}
 */
setShouldFlipVerticallyOnLoad : function () {},

/**
 * @method setLightDirection
 * @param {cocos3d::CC3Vector}
 */
setLightDirection : function () {},

/**
 * @method hasMipmap
 * @return A value converted from C/C++ "bool"
 */
hasMipmap : function () {},

/**
 * @method setShouldFlipHorizontallyOnLoad
 * @param {bool}
 */
setShouldFlipHorizontallyOnLoad : function () {},

/**
 * @method checkGLDebugLabel
 */
checkGLDebugLabel : function () {},

/**
 * @method isTexture2D
 * @return A value converted from C/C++ "bool"
 */
isTexture2D : function () {},

/**
 * @method remove
 */
remove : function () {},

/**
 * @method setHasAlpha
 * @param {bool}
 */
setHasAlpha : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method getSamplerSemantic
 * @return A value converted from C/C++ "unsigned int"
 */
getSamplerSemantic : function () {},

/**
 * @method resizeTo
 * @param {cocos3d::CC3IntSize}
 */
resizeTo : function () {},

/**
 * @method setHasPremultipliedAlpha
 * @param {bool}
 */
setHasPremultipliedAlpha : function () {},

/**
 * @method deleteGLTexture
 */
deleteGLTexture : function () {},

/**
 * @method convertContent
 * @param {ccColor4B*}
 * @param {unsigned int}
 */
convertContent : function () {},

/**
 * @method getLightDirection
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLightDirection : function () {},

/**
 * @method constructorDescription
 * @return A value converted from C/C++ "std::string"
 */
constructorDescription : function () {},

/**
 * @method isPOTWidth
 * @return A value converted from C/C++ "bool"
 */
isPOTWidth : function () {},

/**
 * @method isUpsideDown
 * @return A value converted from C/C++ "bool"
 */
isUpsideDown : function () {},

/**
 * @method isBumpMap
 * @return A value converted from C/C++ "bool"
 */
isBumpMap : function () {},

/**
 * @method defaultTextureParameters
 * @return A value converted from C/C++ "ccTexParams"
 */
defaultTextureParameters : function () {},

/**
 * @method removeTextureNamed
 * @param {std::string}
 */
removeTextureNamed : function () {},

/**
 * @method textureNameFromFilePath
 * @return A value converted from C/C++ "std::string"
 * @param {std::string}
 */
textureNameFromFilePath : function () {},

/**
 * @method setDefaultShouldFlipVerticallyOnLoad
 * @param {bool}
 */
setDefaultShouldFlipVerticallyOnLoad : function () {},

/**
 * @method removeTexture
 * @param {cocos3d::CC3Texture*}
 */
removeTexture : function () {},

/**
 * @method setIsPreloading
 * @param {bool}
 */
setIsPreloading : function () {},

/**
 * @method textureCubeWithPixelFormat
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {unsigned int}
 * @param {unsigned int}
 */
textureCubeWithPixelFormat : function () {},

/**
 * @method addTexture
 * @param {cocos3d::CC3Texture*}
 */
addTexture : function () {},

/**
 * @method removeAllTextures
 */
removeAllTextures : function () {},

/**
 * @method textureWithPixelFormat
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {unsigned int}
 * @param {unsigned int}
 */
textureWithPixelFormat : function () {},

/**
 * @method setDefaultShouldFlipHorizontallyOnLoad
 * @param {bool}
 */
setDefaultShouldFlipHorizontallyOnLoad : function () {},

/**
 * @method setShouldCacheAssociatedCCTextures
 * @param {bool}
 */
setShouldCacheAssociatedCCTextures : function () {},

/**
 * @method getTextureNamed
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {std::string}
 */
getTextureNamed : function () {},

/**
 * @method shouldCacheAssociatedCCTextures
 * @return A value converted from C/C++ "bool"
 */
shouldCacheAssociatedCCTextures : function () {},

/**
 * @method setShouldGenerateMipmaps
 * @param {bool}
 */
setShouldGenerateMipmaps : function () {},

/**
 * @method textureCubeFromFiles
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 */
textureCubeFromFiles : function () {},

/**
 * @method defaultShouldFlipHorizontallyOnLoad
 * @return A value converted from C/C++ "bool"
 */
defaultShouldFlipHorizontallyOnLoad : function () {},

/**
 * @method textureFromFile
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {const char*}
 */
textureFromFile : function () {},

/**
 * @method setDefaultTextureParameters
 * @param {cocos2d::ccTexParams}
 */
setDefaultTextureParameters : function () {},

/**
 * @method defaultShouldFlipVerticallyOnLoad
 * @return A value converted from C/C++ "bool"
 */
defaultShouldFlipVerticallyOnLoad : function () {},

/**
 * @method textureCubeFromFilePattern
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {std::string}
 */
textureCubeFromFilePattern : function () {},

/**
 * @method textureCubeWithSideLength
 * @return A value converted from C/C++ "cocos3d::CC3Texture*"
 * @param {unsigned int}
 * @param {unsigned int}
 * @param {unsigned int}
 */
textureCubeWithSideLength : function () {},

/**
 * @method shouldGenerateMipmaps
 * @return A value converted from C/C++ "bool"
 */
shouldGenerateMipmaps : function () {},

/**
 * @method isPreloading
 * @return A value converted from C/C++ "bool"
 */
isPreloading : function () {},

/**
 * @method CC3Texture
 * @constructor
 */
CC3Texture : function () {},

};

/**
 * @class CC3CCTexture
 */
cc3.CC3CCTexture = {

/**
 * @method flipVertically
 */
flipVertically : function () {},

/**
 * @method getPixelWidth
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelWidth : function () {},

/**
 * @method setName
 * @param {unsigned int}
 */
setName : function () {},

/**
 * @method deleteImageData
 */
deleteImageData : function () {},

/**
 * @method getPixelGLType
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelGLType : function () {},

/**
 * @method hasAlpha
 * @return A value converted from C/C++ "bool"
 */
hasAlpha : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getImageData
 * @return A value converted from C/C++ "const void*"
 */
getImageData : function () {},

/**
 * @method getPixelGLFormat
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelGLFormat : function () {},

/**
 * @method flipHorizontally
 */
flipHorizontally : function () {},

/**
 * @method resizeTo
 * @param {cocos3d::CC3IntSize}
 */
resizeTo : function () {},

/**
 * @method addToCacheWithName
 * @param {const char*}
 */
addToCacheWithName : function () {},

/**
 * @method isUpsideDown
 * @return A value converted from C/C++ "bool"
 */
isUpsideDown : function () {},

/**
 * @method hasMipmap
 * @return A value converted from C/C++ "bool"
 */
hasMipmap : function () {},

/**
 * @method rotateHalfCircle
 */
rotateHalfCircle : function () {},

/**
 * @method getPixelHeight
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelHeight : function () {},

/**
 * @method initFromFile
 * @return A value converted from C/C++ "bool"
 * @param {std::string}
 */
initFromFile : function () {},

/**
 * @method getBytesPerPixel
 * @return A value converted from C/C++ "unsigned int"
 */
getBytesPerPixel : function () {},

/**
 * @method texturesAreLoadedUpsideDown
 * @return A value converted from C/C++ "bool"
 */
texturesAreLoadedUpsideDown : function () {},

};

/**
 * @class CC3Texture2DContent
 */
cc3.CC3Texture2DContent = {

/**
 * @method flipHorizontally
 */
flipHorizontally : function () {},

/**
 * @method deleteImageData
 */
deleteImageData : function () {},

/**
 * @method getPixelGLType
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelGLType : function () {},

/**
 * @method updatePixelFormat
 */
updatePixelFormat : function () {},

/**
 * @method initFromCC3Texture
 * @param {cocos3d::CC3Texture*}
 */
initFromCC3Texture : function () {},

/**
 * @method getImageData
 * @return A value converted from C/C++ "const void*"
 */
getImageData : function () {},

/**
 * @method getPixelGLFormat
 * @return A value converted from C/C++ "unsigned int"
 */
getPixelGLFormat : function () {},

/**
 * @method resizeTo
 * @param {cocos3d::CC3IntSize}
 */
resizeTo : function () {},

/**
 * @method isUpsideDown
 * @return A value converted from C/C++ "bool"
 */
isUpsideDown : function () {},

/**
 * @method flipVertically
 */
flipVertically : function () {},

/**
 * @method initFromFile
 * @return A value converted from C/C++ "bool"
 * @param {std::string}
 */
initFromFile : function () {},

/**
 * @method rotateHalfCircle
 */
rotateHalfCircle : function () {},

/**
 * @method textureFromCC3Texture
 * @return A value converted from C/C++ "cocos3d::CC3Texture2DContent*"
 * @param {cocos3d::CC3Texture*}
 */
textureFromCC3Texture : function () {},

/**
 * @method CC3Texture2DContent
 * @constructor
 */
CC3Texture2DContent : function () {},

};

/**
 * @class CC3PODCamera
 */
cc3.CC3PODCamera = {

/**
 * @method setPodIndex
 * @param {int}
 */
setPodIndex : function () {},

/**
 * @method setPodParentIndex
 * @param {int}
 */
setPodParentIndex : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3PODCamera*}
 */
populateFrom : function () {},

/**
 * @method setPodTargetIndex
 * @param {int}
 */
setPodTargetIndex : function () {},

/**
 * @method clearScaleContentIn
 * @param {SPODNode*}
 */
clearScaleContentIn : function () {},

/**
 * @method setPodContentIndex
 * @param {int}
 */
setPodContentIndex : function () {},

/**
 * @method getPodTargetIndex
 * @return A value converted from C/C++ "int"
 */
getPodTargetIndex : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method getPodParentIndex
 * @return A value converted from C/C++ "int"
 */
getPodParentIndex : function () {},

/**
 * @method adjustQuaternionsIn
 * @param {SPODNode*}
 * @param {unsigned int}
 */
adjustQuaternionsIn : function () {},

/**
 * @method getPodIndex
 * @return A value converted from C/C++ "int"
 */
getPodIndex : function () {},

/**
 * @method getPodContentIndex
 * @return A value converted from C/C++ "int"
 */
getPodContentIndex : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method nodeAtIndex
 * @return A value converted from C/C++ "cocos3d::CC3PODCamera*"
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
nodeAtIndex : function () {},

};

/**
 * @class CC3PODResourceNode
 */
cc3.CC3PODResourceNode = {

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3PODResourceNode*}
 */
populateFrom : function () {},

/**
 * @method getAnimationFrameCount
 * @return A value converted from C/C++ "unsigned int"
 */
getAnimationFrameCount : function () {},

/**
 * @method populateFromResource
 * @param {cocos3d::CC3NodesResource*}
 */
populateFromResource : function () {},

/**
 * @method getAnimationFrameRate
 * @return A value converted from C/C++ "float"
 */
getAnimationFrameRate : function () {},

/**
 * @method CC3PODResourceNode
 * @constructor
 */
CC3PODResourceNode : function () {},

};

/**
 * @class CC3PODLight
 */
cc3.CC3PODLight = {

/**
 * @method setPodIndex
 * @param {int}
 */
setPodIndex : function () {},

/**
 * @method setPodParentIndex
 * @param {int}
 */
setPodParentIndex : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3PODLight*}
 */
populateFrom : function () {},

/**
 * @method setPodTargetIndex
 * @param {int}
 */
setPodTargetIndex : function () {},

/**
 * @method setPodContentIndex
 * @param {int}
 */
setPodContentIndex : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method getPodTargetIndex
 * @return A value converted from C/C++ "int"
 */
getPodTargetIndex : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method getPodParentIndex
 * @return A value converted from C/C++ "int"
 */
getPodParentIndex : function () {},

/**
 * @method getPodIndex
 * @return A value converted from C/C++ "int"
 */
getPodIndex : function () {},

/**
 * @method getPodContentIndex
 * @return A value converted from C/C++ "int"
 */
getPodContentIndex : function () {},

/**
 * @method getGlobalHomogeneousPosition
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 */
getGlobalHomogeneousPosition : function () {},

/**
 * @method nodeAtIndex
 * @return A value converted from C/C++ "cocos3d::CC3PODLight*"
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
nodeAtIndex : function () {},

};

/**
 * @class CC3PODMesh
 */
cc3.CC3PODMesh = {

/**
 * @method setPodIndex
 * @param {int}
 */
setPodIndex : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3PODMesh*}
 */
populateFrom : function () {},

/**
 * @method deprecatedAlign
 * @param {cocos3d::CC3VertexTextureCoordinates*}
 * @param {cocos3d::CC3Texture*}
 */
deprecatedAlign : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method getPodIndex
 * @return A value converted from C/C++ "int"
 */
getPodIndex : function () {},

/**
 * @method meshAtIndex
 * @return A value converted from C/C++ "cocos3d::CC3PODMesh*"
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
meshAtIndex : function () {},

};

/**
 * @class CC3PODNode
 */
cc3.CC3PODNode = {

/**
 * @method setPodIndex
 * @param {int}
 */
setPodIndex : function () {},

/**
 * @method setPodParentIndex
 * @param {int}
 */
setPodParentIndex : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3PODNode*}
 */
populateFrom : function () {},

/**
 * @method setPodContentIndex
 * @param {int}
 */
setPodContentIndex : function () {},

/**
 * @method getPodParentIndex
 * @return A value converted from C/C++ "int"
 */
getPodParentIndex : function () {},

/**
 * @method getPodIndex
 * @return A value converted from C/C++ "int"
 */
getPodIndex : function () {},

/**
 * @method getPodContentIndex
 * @return A value converted from C/C++ "int"
 */
getPodContentIndex : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method nodeAtIndex
 * @return A value converted from C/C++ "cocos3d::CC3PODNode*"
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
nodeAtIndex : function () {},

};

/**
 * @class CC3PODNodeAnimation
 */
cc3.CC3PODNodeAnimation = {

/**
 * @method getQuaternionAtFrame
 * @return A value converted from C/C++ "CC3Quaternion"
 * @param {unsigned int}
 */
getQuaternionAtFrame : function () {},

/**
 * @method isAnimatingQuaternion
 * @return A value converted from C/C++ "bool"
 */
isAnimatingQuaternion : function () {},

/**
 * @method getLocationAtFrame
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getLocationAtFrame : function () {},

/**
 * @method getScaleAtFrame
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 * @param {unsigned int}
 */
getScaleAtFrame : function () {},

/**
 * @method isAnimatingScale
 * @return A value converted from C/C++ "bool"
 */
isAnimatingScale : function () {},

/**
 * @method isAnimatingLocation
 * @return A value converted from C/C++ "bool"
 */
isAnimatingLocation : function () {},

/**
 * @method CC3PODNodeAnimation
 * @constructor
 */
CC3PODNodeAnimation : function () {},

};

/**
 * @class CC3PODMaterial
 */
cc3.CC3PODMaterial = {

/**
 * @method setPodIndex
 * @param {int}
 */
setPodIndex : function () {},

/**
 * @method getPfxEffect
 * @return A value converted from C/C++ "cocos3d::CC3PFXEffect*"
 */
getPfxEffect : function () {},

/**
 * @method addBumpMapTexture
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
addBumpMapTexture : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3PODMaterial*}
 */
populateFrom : function () {},

/**
 * @method addTexture
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
addTexture : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method getPodIndex
 * @return A value converted from C/C++ "int"
 */
getPodIndex : function () {},

/**
 * @method getShininessExpansionFactor
 * @return A value converted from C/C++ "float"
 */
getShininessExpansionFactor : function () {},

/**
 * @method setShininessExpansionFactor
 * @param {float}
 */
setShininessExpansionFactor : function () {},

/**
 * @method materialAtIndex
 * @return A value converted from C/C++ "cocos3d::CC3PODMaterial*"
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
materialAtIndex : function () {},

/**
 * @method CC3PODMaterial
 * @constructor
 */
CC3PODMaterial : function () {},

};

/**
 * @class CC3PODMeshNode
 */
cc3.CC3PODMeshNode = {

/**
 * @method setPodIndex
 * @param {int}
 */
setPodIndex : function () {},

/**
 * @method setPodParentIndex
 * @param {int}
 */
setPodParentIndex : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3PODMeshNode*}
 */
populateFrom : function () {},

/**
 * @method setMaterial
 * @param {cocos3d::CC3PODMaterial*}
 */
setMaterial : function () {},

/**
 * @method setPodContentIndex
 * @param {int}
 */
setPodContentIndex : function () {},

/**
 * @method setPodMaterialIndex
 * @param {int}
 */
setPodMaterialIndex : function () {},

/**
 * @method initAtIndex
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
initAtIndex : function () {},

/**
 * @method getPodParentIndex
 * @return A value converted from C/C++ "int"
 */
getPodParentIndex : function () {},

/**
 * @method getPodIndex
 * @return A value converted from C/C++ "int"
 */
getPodIndex : function () {},

/**
 * @method getPodMaterialIndex
 * @return A value converted from C/C++ "int"
 */
getPodMaterialIndex : function () {},

/**
 * @method getPodContentIndex
 * @return A value converted from C/C++ "int"
 */
getPodContentIndex : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method nodeAtIndex
 * @return A value converted from C/C++ "cocos3d::CC3PODMeshNode*"
 * @param {int}
 * @param {cocos3d::CC3PODResource*}
 */
nodeAtIndex : function () {},

};

/**
 * @class Joystick
 */
cc3.Joystick = {

/**
 * @method initializeEvents
 */
initializeEvents : function () {},

/**
 * @method onEnter
 */
onEnter : function () {},

/**
 * @method getVelocity
 * @return A value converted from C/C++ "cocos2d::CCPoint"
 */
getVelocity : function () {},

/**
 * @method ccTouchEnded
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchEnded : function () {},

/**
 * @method ccTouchBegan
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchBegan : function () {},

/**
 * @method ccTouchCancelled
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchCancelled : function () {},

/**
 * @method getAngularVelocity
 * @return A value converted from C/C++ "AngularPoint"
 */
getAngularVelocity : function () {},

/**
 * @method ccTouchMoved
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchMoved : function () {},

/**
 * @method getTouchPriority
 * @return A value converted from C/C++ "int"
 */
getTouchPriority : function () {},

/**
 * @method setContentSize
 * @param {cocos2d::CCSize}
 */
setContentSize : function () {},

/**
 * @method registerWithTouchDispatcher
 */
registerWithTouchDispatcher : function () {},

/**
 * @method Joystick
 * @constructor
 */
Joystick : function () {},

};

/**
 * @class CC3Particle
 */
cc3.CC3Particle = {

/**
 * @method updateBeforeTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
updateBeforeTransform : function () {},

/**
 * @method setRotationVelocity
 * @param {cocos3d::CC3Vector}
 */
setRotationVelocity : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Particle*}
 */
populateFrom : function () {},

/**
 * @method getLifeSpan
 * @return A value converted from C/C++ "float"
 */
getLifeSpan : function () {},

/**
 * @method setParticleIndex
 * @param {unsigned int}
 */
setParticleIndex : function () {},

/**
 * @method finalizeParticle
 */
finalizeParticle : function () {},

/**
 * @method setSizeVelocity
 * @param {float}
 */
setSizeVelocity : function () {},

/**
 * @method getColor4B
 * @return A value converted from C/C++ "ccColor4B"
 */
getColor4B : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method setColor4B
 * @param {cocos2d::ccColor4B}
 */
setColor4B : function () {},

/**
 * @method getRotationAngleVelocity
 * @return A value converted from C/C++ "float"
 */
getRotationAngleVelocity : function () {},

/**
 * @method setColor4F
 * @param {cocos2d::ccColor4F}
 */
setColor4F : function () {},

/**
 * @method setLocation
 * @param {cocos3d::CC3Vector}
 */
setLocation : function () {},

/**
 * @method setLifeSpan
 * @param {float}
 */
setLifeSpan : function () {},

/**
 * @method getGlobalLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getGlobalLocation : function () {},

/**
 * @method setColorVelocity
 * @param {cocos2d::ccColor4F}
 */
setColorVelocity : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method getVelocity
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getVelocity : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method getColor4F
 * @return A value converted from C/C++ "ccColor4F"
 */
getColor4F : function () {},

/**
 * @method setRotationAxis
 * @param {cocos3d::CC3Vector}
 */
setRotationAxis : function () {},

/**
 * @method setCascadeColorEnabled
 * @param {bool}
 */
setCascadeColorEnabled : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method setRotationAngle
 * @param {float}
 */
setRotationAngle : function () {},

/**
 * @method setEmitter
 * @param {cocos3d::CC3ParticleEmitter*}
 */
setEmitter : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {unsigned char}
 */
updateDisplayedOpacity : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getEmitter
 * @return A value converted from C/C++ "cocos3d::CC3ParticleEmitter*"
 */
getEmitter : function () {},

/**
 * @method setRotationAngleVelocity
 * @param {float}
 */
setRotationAngleVelocity : function () {},

/**
 * @method getSizeVelocity
 * @return A value converted from C/C++ "float"
 */
getSizeVelocity : function () {},

/**
 * @method getRotationVelocity
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getRotationVelocity : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method getLocation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getLocation : function () {},

/**
 * @method getDisplayedOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getDisplayedOpacity : function () {},

/**
 * @method isAlive
 * @return A value converted from C/C++ "bool"
 */
isAlive : function () {},

/**
 * @method getParticleIndex
 * @return A value converted from C/C++ "unsigned int"
 */
getParticleIndex : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getColor : function () {},

/**
 * @method getRotationAxis
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getRotationAxis : function () {},

/**
 * @method updateAfterTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
updateAfterTransform : function () {},

/**
 * @method getTimeToLive
 * @return A value converted from C/C++ "float"
 */
getTimeToLive : function () {},

/**
 * @method getRotationAngle
 * @return A value converted from C/C++ "float"
 */
getRotationAngle : function () {},

/**
 * @method getColorVelocity
 * @return A value converted from C/C++ "ccColor4F"
 */
getColorVelocity : function () {},

/**
 * @method setRotation
 * @param {cocos3d::CC3Vector}
 */
setRotation : function () {},

/**
 * @method initializeParticle
 */
initializeParticle : function () {},

/**
 * @method pointNormalAt
 * @param {cocos3d::CC3Vector}
 */
pointNormalAt : function () {},

/**
 * @method getSize
 * @return A value converted from C/C++ "float"
 */
getSize : function () {},

/**
 * @method setColor
 * @param {cocos3d::CCColorRef}
 */
setColor : function () {},

/**
 * @method getDisplayedColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getDisplayedColor : function () {},

/**
 * @method setIsAlive
 * @param {bool}
 */
setIsAlive : function () {},

/**
 * @method fullDescription
 * @return A value converted from C/C++ "std::string"
 */
fullDescription : function () {},

/**
 * @method hasColor
 * @return A value converted from C/C++ "bool"
 */
hasColor : function () {},

/**
 * @method remove
 */
remove : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method setVelocity
 * @param {cocos3d::CC3Vector}
 */
setVelocity : function () {},

/**
 * @method updateDisplayedColor
 * @param {cocos3d::CCColorRef}
 */
updateDisplayedColor : function () {},

/**
 * @method setSize
 * @param {float}
 */
setSize : function () {},

/**
 * @method getRotation
 * @return A value converted from C/C++ "cocos3d::CC3Vector"
 */
getRotation : function () {},

/**
 * @method particle
 * @return A value converted from C/C++ "cocos3d::CC3Particle*"
 */
particle : function () {},

/**
 * @method CC3Particle
 * @constructor
 */
CC3Particle : function () {},

};

/**
 * @class CC3Layer
 */
cc3.CC3Layer = {

/**
 * @method onEnter
 */
onEnter : function () {},

/**
 * @method getCC3Scene
 * @return A value converted from C/C++ "cocos3d::CC3Scene*"
 */
getCC3Scene : function () {},

/**
 * @method ccTouchBegan
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchBegan : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method setScale
 * @param {float}
 */
setScale : function () {},

/**
 * @method ccTouchEnded
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchEnded : function () {},

/**
 * @method setContentSize
 * @param {cocos2d::CCSize}
 */
setContentSize : function () {},

/**
 * @method description
 * @return A value converted from C/C++ "std::string"
 */
description : function () {},

/**
 * @method shouldAlwaysUpdateViewport
 * @return A value converted from C/C++ "bool"
 */
shouldAlwaysUpdateViewport : function () {},

/**
 * @method updateViewport
 */
updateViewport : function () {},

/**
 * @method handleTouchType
 * @return A value converted from C/C++ "bool"
 * @param {unsigned int}
 * @param {cocos2d::CCPoint}
 */
handleTouchType : function () {},

/**
 * @method closeCC3Scene
 */
closeCC3Scene : function () {},

/**
 * @method setParent
 * @param {cocos2d::CCNode*}
 */
setParent : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method drawSceneWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawSceneWithVisitor : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method openCC3Scene
 */
openCC3Scene : function () {},

/**
 * @method ccTouchMoved
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchMoved : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method getCC3GestureRecognizers
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getCC3GestureRecognizers : function () {},

/**
 * @method setScaleY
 * @param {float}
 */
setScaleY : function () {},

/**
 * @method setScaleX
 * @param {float}
 */
setScaleX : function () {},

/**
 * @method shouldTrackViewSize
 * @return A value converted from C/C++ "bool"
 */
shouldTrackViewSize : function () {},

/**
 * @method setShouldAlwaysUpdateViewport
 * @param {bool}
 */
setShouldAlwaysUpdateViewport : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getColor : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getRenderStreamGroupMarker
 * @return A value converted from C/C++ "std::string"
 */
getRenderStreamGroupMarker : function () {},

/**
 * @method viewDidResizeTo
 * @param {cocos2d::CCSize}
 */
viewDidResizeTo : function () {},

/**
 * @method getTouchPriority
 * @return A value converted from C/C++ "int"
 */
getTouchPriority : function () {},

/**
 * @method setPosition
 * @param {cocos2d::CCPoint}
 */
setPosition : function () {},

/**
 * @method validateAndProcessTouchAt
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::CCPoint}
 * @param {unsigned int}
 */
validateAndProcessTouchAt : function () {},

/**
 * @method isRunningInActiveScene
 * @return A value converted from C/C++ "bool"
 */
isRunningInActiveScene : function () {},

/**
 * @method onExit
 */
onExit : function () {},

/**
 * @method setShouldTrackViewSize
 * @param {bool}
 */
setShouldTrackViewSize : function () {},

/**
 * @method onCloseCC3Layer
 */
onCloseCC3Layer : function () {},

/**
 * @method getSurfaceManager
 * @return A value converted from C/C++ "cocos3d::CC3SceneDrawingSurfaceManager*"
 */
getSurfaceManager : function () {},

/**
 * @method setColor
 * @param {cocos3d::CCColorRef}
 */
setColor : function () {},

/**
 * @method getMouseDelegatePriority
 * @return A value converted from C/C++ "int"
 */
getMouseDelegatePriority : function () {},

/**
 * @method initializeControls
 */
initializeControls : function () {},

/**
 * @method ccTouchCancelled
 * @param {cocos2d::CCTouch*}
 * @param {cocos2d::CCEvent*}
 */
ccTouchCancelled : function () {},

/**
 * @method cc3RemoveAllGestureRecognizers
 */
cc3RemoveAllGestureRecognizers : function () {},

/**
 * @method onOpenCC3Layer
 */
onOpenCC3Layer : function () {},

/**
 * @method onContentSizeChanged
 */
onContentSizeChanged : function () {},

/**
 * @method setCC3Scene
 * @param {cocos3d::CC3Scene*}
 */
setCC3Scene : function () {},

/**
 * @method setSurfaceManager
 * @param {cocos3d::CC3SceneDrawingSurfaceManager*}
 */
setSurfaceManager : function () {},

/**
 * @method CC3Layer
 * @constructor
 */
CC3Layer : function () {},

};

/**
 * @class CC3Scene
 */
cc3.CC3Scene = {

/**
 * @method checkNeedShadowVisitor
 */
checkNeedShadowVisitor : function () {},

/**
 * @method onOpen
 */
onOpen : function () {},

/**
 * @method setEnvMapDrawingVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
setEnvMapDrawingVisitor : function () {},

/**
 * @method setIsRunning
 * @param {bool}
 */
setIsRunning : function () {},

/**
 * @method getTouchedNodePicker
 * @return A value converted from C/C++ "cocos3d::CC3TouchedNodePicker*"
 */
getTouchedNodePicker : function () {},

/**
 * @method drawSceneContentWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawSceneContentWithVisitor : function () {},

/**
 * @method getTotalIllumination
 * @return A value converted from C/C++ "ccColor4F"
 */
getTotalIllumination : function () {},

/**
 * @method setDrawingSequenceVisitor
 * @param {cocos3d::CC3NodeSequencerVisitor*}
 */
setDrawingSequenceVisitor : function () {},

/**
 * @method closeDepthTestWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
closeDepthTestWithVisitor : function () {},

/**
 * @method initializeScene
 */
initializeScene : function () {},

/**
 * @method getMinUpdateInterval
 * @return A value converted from C/C++ "float"
 */
getMinUpdateInterval : function () {},

/**
 * @method updateCamera
 * @param {float}
 */
updateCamera : function () {},

/**
 * @method getUpdateVisitor
 * @return A value converted from C/C++ "cocos3d::CC3NodeUpdatingVisitor*"
 */
getUpdateVisitor : function () {},

/**
 * @method setMinUpdateInterval
 * @param {float}
 */
setMinUpdateInterval : function () {},

/**
 * @method setDrawingSequencer
 * @param {cocos3d::CC3NodeSequencer*}
 */
setDrawingSequencer : function () {},

/**
 * @method setFog
 * @param {cocos3d::CC3Fog*}
 */
setFog : function () {},

/**
 * @method getDeltaFrameTime
 * @return A value converted from C/C++ "float"
 */
getDeltaFrameTime : function () {},

/**
 * @method updateTimes
 * @param {float}
 */
updateTimes : function () {},

/**
 * @method close
 */
close : function () {},

/**
 * @method getMaxUpdateInterval
 * @return A value converted from C/C++ "float"
 */
getMaxUpdateInterval : function () {},

/**
 * @method open
 */
open : function () {},

/**
 * @method setShadowVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
setShadowVisitor : function () {},

/**
 * @method updateDrawSequence
 */
updateDrawSequence : function () {},

/**
 * @method pickNodeFromTapAt
 * @param {cocos2d::CCPoint}
 */
pickNodeFromTapAt : function () {},

/**
 * @method pause
 */
pause : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3Scene*}
 */
populateFrom : function () {},

/**
 * @method getShadowVisitor
 * @return A value converted from C/C++ "cocos3d::CC3NodeDrawingVisitor*"
 */
getShadowVisitor : function () {},

/**
 * @method getPerformanceStatistics
 * @return A value converted from C/C++ "cocos3d::CC3PerformanceStatistics*"
 */
getPerformanceStatistics : function () {},

/**
 * @method shouldDisplayPickingRender
 * @return A value converted from C/C++ "bool"
 */
shouldDisplayPickingRender : function () {},

/**
 * @method getDrawingSequencer
 * @return A value converted from C/C++ "cocos3d::CC3NodeSequencer*"
 */
getDrawingSequencer : function () {},

/**
 * @method setOpacity
 * @param {unsigned char}
 */
setOpacity : function () {},

/**
 * @method drawSceneWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawSceneWithVisitor : function () {},

/**
 * @method draw2DBillboardsWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
draw2DBillboardsWithVisitor : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method setMaxUpdateInterval
 * @param {float}
 */
setMaxUpdateInterval : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method getLights
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getLights : function () {},

/**
 * @method setActiveCamera
 * @param {cocos3d::CC3Camera*}
 */
setActiveCamera : function () {},

/**
 * @method getEnvMapDrawingVisitor
 * @return A value converted from C/C++ "cocos3d::CC3NodeDrawingVisitor*"
 */
getEnvMapDrawingVisitor : function () {},

/**
 * @method isUsingDrawingSequence
 * @return A value converted from C/C++ "bool"
 */
isUsingDrawingSequence : function () {},

/**
 * @method getBackdrop
 * @return A value converted from C/C++ "cocos3d::CC3MeshNode*"
 */
getBackdrop : function () {},

/**
 * @method play
 */
play : function () {},

/**
 * @method updateShadows
 * @param {float}
 */
updateShadows : function () {},

/**
 * @method setTouchedNodePicker
 * @param {cocos3d::CC3TouchedNodePicker*}
 */
setTouchedNodePicker : function () {},

/**
 * @method getLightProbes
 * @return A value converted from C/C++ "cocos2d::CCArray*"
 */
getLightProbes : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "CCColorRef"
 */
getColor : function () {},

/**
 * @method onClose
 */
onClose : function () {},

/**
 * @method drawSceneContentForEnvironmentMapWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawSceneContentForEnvironmentMapWithVisitor : function () {},

/**
 * @method getViewDrawingVisitor
 * @return A value converted from C/C++ "cocos3d::CC3NodeDrawingVisitor*"
 */
getViewDrawingVisitor : function () {},

/**
 * @method drawScene
 */
drawScene : function () {},

/**
 * @method didRemoveDescendant
 * @param {cocos3d::CC3Node*}
 */
didRemoveDescendant : function () {},

/**
 * @method collectFrameInterval
 */
collectFrameInterval : function () {},

/**
 * @method drawShadowsWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawShadowsWithVisitor : function () {},

/**
 * @method getAmbientLight
 * @return A value converted from C/C++ "ccColor4F"
 */
getAmbientLight : function () {},

/**
 * @method close3DWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
close3DWithVisitor : function () {},

/**
 * @method illuminateWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
illuminateWithVisitor : function () {},

/**
 * @method updateRelativeLightIntensities
 */
updateRelativeLightIntensities : function () {},

/**
 * @method nodeSelected
 * @param {cocos3d::CC3Node*}
 * @param {unsigned int}
 * @param {cocos2d::CCPoint}
 */
nodeSelected : function () {},

/**
 * @method setBackdrop
 * @param {cocos3d::CC3MeshNode*}
 */
setBackdrop : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method getActiveCamera
 * @return A value converted from C/C++ "cocos3d::CC3Camera*"
 */
getActiveCamera : function () {},

/**
 * @method setViewDrawingVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
setViewDrawingVisitor : function () {},

/**
 * @method setPerformanceStatistics
 * @param {cocos3d::CC3PerformanceStatistics*}
 */
setPerformanceStatistics : function () {},

/**
 * @method setColor
 * @param {cocos3d::CCColorRef}
 */
setColor : function () {},

/**
 * @method didAddDescendant
 * @param {cocos3d::CC3Node*}
 */
didAddDescendant : function () {},

/**
 * @method getElapsedTimeSinceOpened
 * @return A value converted from C/C++ "unsigned long"
 */
getElapsedTimeSinceOpened : function () {},

/**
 * @method doesContainShadows
 * @return A value converted from C/C++ "bool"
 */
doesContainShadows : function () {},

/**
 * @method isIlluminated
 * @return A value converted from C/C++ "bool"
 */
isIlluminated : function () {},

/**
 * @method pickNodeFromTouchEvent
 * @param {unsigned int}
 * @param {cocos2d::CCPoint}
 */
pickNodeFromTouchEvent : function () {},

/**
 * @method activeCameraChangedFrom
 * @param {cocos3d::CC3Camera*}
 */
activeCameraChangedFrom : function () {},

/**
 * @method touchEvent
 * @param {unsigned int}
 * @param {cocos2d::CCPoint}
 */
touchEvent : function () {},

/**
 * @method getDrawingSequenceVisitor
 * @return A value converted from C/C++ "cocos3d::CC3NodeSequencerVisitor*"
 */
getDrawingSequenceVisitor : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method getFog
 * @return A value converted from C/C++ "cocos3d::CC3Fog*"
 */
getFog : function () {},

/**
 * @method setAmbientLight
 * @param {cocos2d::ccColor4F}
 */
setAmbientLight : function () {},

/**
 * @method getScene
 * @return A value converted from C/C++ "cocos3d::CC3Scene*"
 */
getScene : function () {},

/**
 * @method configureFogWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureFogWithVisitor : function () {},

/**
 * @method descendantDidModifySequencingCriteria
 * @param {cocos3d::CC3Node*}
 */
descendantDidModifySequencingCriteria : function () {},

/**
 * @method isScene
 * @return A value converted from C/C++ "bool"
 */
isScene : function () {},

/**
 * @method drawBackdropWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawBackdropWithVisitor : function () {},

/**
 * @method updateBillboards
 * @param {float}
 */
updateBillboards : function () {},

/**
 * @method open3DWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
open3DWithVisitor : function () {},

/**
 * @method setUpdateVisitor
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
setUpdateVisitor : function () {},

/**
 * @method scene
 * @return A value converted from C/C++ "cocos3d::CC3Scene*"
 */
scene : function () {},

/**
 * @method CC3Scene
 * @constructor
 */
CC3Scene : function () {},

};

/**
 * @class CC3TouchedNodePicker
 */
cc3.CC3TouchedNodePicker = {

/**
 * @method getPickVisitor
 * @return A value converted from C/C++ "cocos3d::CC3NodePickingVisitor*"
 */
getPickVisitor : function () {},

/**
 * @method pickNodeFromTouchEvent
 * @param {unsigned int}
 * @param {cocos2d::CCPoint}
 */
pickNodeFromTouchEvent : function () {},

/**
 * @method pickTouchedNodeWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
pickTouchedNodeWithVisitor : function () {},

/**
 * @method initOnScene
 * @param {cocos3d::CC3Scene*}
 */
initOnScene : function () {},

/**
 * @method init
 */
init : function () {},

/**
 * @method getTouchPoint
 * @return A value converted from C/C++ "cocos2d::CCPoint"
 */
getTouchPoint : function () {},

/**
 * @method getPickedNode
 * @return A value converted from C/C++ "cocos3d::CC3Node*"
 */
getPickedNode : function () {},

/**
 * @method setPickedNode
 * @param {cocos3d::CC3Node*}
 */
setPickedNode : function () {},

/**
 * @method dispatchPickedNode
 */
dispatchPickedNode : function () {},

/**
 * @method setPickVisitor
 * @param {cocos3d::CC3NodePickingVisitor*}
 */
setPickVisitor : function () {},

/**
 * @method pickerOnScene
 * @return A value converted from C/C++ "cocos3d::CC3TouchedNodePicker*"
 * @param {cocos3d::CC3Scene*}
 */
pickerOnScene : function () {},

/**
 * @method CC3TouchedNodePicker
 * @constructor
 */
CC3TouchedNodePicker : function () {},

};

/**
 * @class CC3ShadowVolumeMeshNode
 */
cc3.CC3ShadowVolumeMeshNode = {

/**
 * @method getShadowExpansionLimitFactor
 * @return A value converted from C/C++ "float"
 */
getShadowExpansionLimitFactor : function () {},

/**
 * @method defaultBoundingVolume
 * @return A value converted from C/C++ "cocos3d::CC3NodeBoundingVolume*"
 */
defaultBoundingVolume : function () {},

/**
 * @method shouldShadowBackFaces
 * @return A value converted from C/C++ "bool"
 */
shouldShadowBackFaces : function () {},

/**
 * @method populateFrom
 * @param {cocos3d::CC3ShadowVolumeMeshNode*}
 */
populateFrom : function () {},

/**
 * @method setShouldDrawDescriptor
 * @param {bool}
 */
setShouldDrawDescriptor : function () {},

/**
 * @method nodeWasDestroyed
 * @param {cocos3d::CC3Node*}
 */
nodeWasDestroyed : function () {},

/**
 * @method getShadowCaster
 * @return A value converted from C/C++ "cocos3d::CC3MeshNode*"
 */
getShadowCaster : function () {},

/**
 * @method shouldDrawLocalContentWireframeBox
 * @return A value converted from C/C++ "bool"
 */
shouldDrawLocalContentWireframeBox : function () {},

/**
 * @method shouldDrawWireframeBox
 * @return A value converted from C/C++ "bool"
 */
shouldDrawWireframeBox : function () {},

/**
 * @method createShadowMesh
 */
createShadowMesh : function () {},

/**
 * @method setShouldShadowFrontFaces
 * @param {bool}
 */
setShouldShadowFrontFaces : function () {},

/**
 * @method setShouldDrawTerminator
 * @param {bool}
 */
setShouldDrawTerminator : function () {},

/**
 * @method checkShadowMaterial
 */
checkShadowMaterial : function () {},

/**
 * @method setShadowVolumeVertexOffsetFactor
 * @param {float}
 */
setShadowVolumeVertexOffsetFactor : function () {},

/**
 * @method processUpdateBeforeTransform
 * @param {cocos3d::CC3NodeUpdatingVisitor*}
 */
processUpdateBeforeTransform : function () {},

/**
 * @method getShadowLagCount
 * @return A value converted from C/C++ "unsigned short"
 */
getShadowLagCount : function () {},

/**
 * @method copyWithZone
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 * @param {cocos2d::CCZone*}
 */
copyWithZone : function () {},

/**
 * @method setShouldDrawLocalContentWireframeBox
 * @param {bool}
 */
setShouldDrawLocalContentWireframeBox : function () {},

/**
 * @method setShadowLagCount
 * @param {unsigned short}
 */
setShadowLagCount : function () {},

/**
 * @method setParent
 * @param {cocos3d::CC3Node*}
 */
setParent : function () {},

/**
 * @method populateShadowMesh
 */
populateShadowMesh : function () {},

/**
 * @method setShouldShadowBackFaces
 * @param {bool}
 */
setShouldShadowBackFaces : function () {},

/**
 * @method getShadowLagFactor
 * @return A value converted from C/C++ "unsigned short"
 */
getShadowLagFactor : function () {},

/**
 * @method configureDrawingParameters
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
configureDrawingParameters : function () {},

/**
 * @method isReadyToUpdate
 * @return A value converted from C/C++ "bool"
 */
isReadyToUpdate : function () {},

/**
 * @method setShadowLagFactor
 * @param {unsigned short}
 */
setShadowLagFactor : function () {},

/**
 * @method shouldDrawTerminator
 * @return A value converted from C/C++ "bool"
 */
shouldDrawTerminator : function () {},

/**
 * @method setShadowOffsetUnits
 * @param {float}
 */
setShadowOffsetUnits : function () {},

/**
 * @method shouldAddShadowVolumeEndCapsOnlyWhenNeeded
 * @return A value converted from C/C++ "bool"
 */
shouldAddShadowVolumeEndCapsOnlyWhenNeeded : function () {},

/**
 * @method markTransformDirty
 */
markTransformDirty : function () {},

/**
 * @method isShadowVisible
 * @return A value converted from C/C++ "bool"
 */
isShadowVisible : function () {},

/**
 * @method useDepthFailAlgorithm
 * @return A value converted from C/C++ "bool"
 */
useDepthFailAlgorithm : function () {},

/**
 * @method isTouchable
 * @return A value converted from C/C++ "bool"
 */
isTouchable : function () {},

/**
 * @method wasRemoved
 */
wasRemoved : function () {},

/**
 * @method setLight
 * @param {cocos3d::CC3Light*}
 */
setLight : function () {},

/**
 * @method addShadowVolumeCapFor
 * @return A value converted from C/C++ "bool"
 * @param {bool}
 * @param {cocos3d::CC3Vector4*}
 * @param {cocos3d::CC3Vector4}
 * @param {unsigned int*}
 */
addShadowVolumeCapFor : function () {},

/**
 * @method shouldContributeToParentBoundingBox
 * @return A value converted from C/C++ "bool"
 */
shouldContributeToParentBoundingBox : function () {},

/**
 * @method isShadowDirty
 * @return A value converted from C/C++ "bool"
 */
isShadowDirty : function () {},

/**
 * @method updateStencilAlgorithm
 */
updateStencilAlgorithm : function () {},

/**
 * @method drawToStencilIncrementing
 * @param {bool}
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawToStencilIncrementing : function () {},

/**
 * @method drawToStencilWithVisitor
 * @param {cocos3d::CC3NodeDrawingVisitor*}
 */
drawToStencilWithVisitor : function () {},

/**
 * @method getShadowOffsetFactor
 * @return A value converted from C/C++ "float"
 */
getShadowOffsetFactor : function () {},

/**
 * @method hasShadowVolumesForLight
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Light*}
 */
hasShadowVolumesForLight : function () {},

/**
 * @method setShouldAddShadowVolumeEndCapsOnlyWhenNeeded
 * @param {bool}
 */
setShouldAddShadowVolumeEndCapsOnlyWhenNeeded : function () {},

/**
 * @method getShadowVolumeVertexOffsetFactor
 * @return A value converted from C/C++ "float"
 */
getShadowVolumeVertexOffsetFactor : function () {},

/**
 * @method expand
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 * @param {cocos3d::CC3Vector4}
 * @param {cocos3d::CC3Vector4}
 */
expand : function () {},

/**
 * @method shadowOffsetUnits
 * @return A value converted from C/C++ "float"
 */
shadowOffsetUnits : function () {},

/**
 * @method shouldIncludeInDeepCopy
 * @return A value converted from C/C++ "bool"
 */
shouldIncludeInDeepCopy : function () {},

/**
 * @method addTerminatorLineFrom
 * @return A value converted from C/C++ "bool"
 * @param {cocos3d::CC3Vector4}
 * @param {cocos3d::CC3Vector4}
 * @param {unsigned int*}
 */
addTerminatorLineFrom : function () {},

/**
 * @method setShouldDrawWireframeBox
 * @param {bool}
 */
setShouldDrawWireframeBox : function () {},

/**
 * @method isShadowVolume
 * @return A value converted from C/C++ "bool"
 */
isShadowVolume : function () {},

/**
 * @method addShadowVolumesForLight
 * @param {cocos3d::CC3Light*}
 */
addShadowVolumesForLight : function () {},

/**
 * @method shouldDrawBoundingVolume
 * @return A value converted from C/C++ "bool"
 */
shouldDrawBoundingVolume : function () {},

/**
 * @method setShadowExpansionLimitFactor
 * @param {float}
 */
setShadowExpansionLimitFactor : function () {},

/**
 * @method updateShadow
 */
updateShadow : function () {},

/**
 * @method getShadowVolumeVertexOffsetForLightAt
 * @return A value converted from C/C++ "cocos3d::CC3Vector4"
 * @param {cocos3d::CC3Vector4}
 */
getShadowVolumeVertexOffsetForLightAt : function () {},

/**
 * @method hasShadowVolumes
 * @return A value converted from C/C++ "bool"
 */
hasShadowVolumes : function () {},

/**
 * @method initWithTag
 * @param {unsigned int}
 * @param {std::string}
 */
initWithTag : function () {},

/**
 * @method setShouldDrawBoundingVolume
 * @param {bool}
 */
setShouldDrawBoundingVolume : function () {},

/**
 * @method setShadowOffsetFactor
 * @param {float}
 */
setShadowOffsetFactor : function () {},

/**
 * @method shouldShadowFrontFaces
 * @return A value converted from C/C++ "bool"
 */
shouldShadowFrontFaces : function () {},

/**
 * @method nodeWasTransformed
 * @param {cocos3d::CC3Node*}
 */
nodeWasTransformed : function () {},

/**
 * @method shouldDrawDescriptor
 * @return A value converted from C/C++ "bool"
 */
shouldDrawDescriptor : function () {},

/**
 * @method setVisible
 * @param {bool}
 */
setVisible : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3ShadowVolumeMeshNode*"
 * @param {std::string}
 */
nodeWithName : function () {},

/**
 * @method setDefaultVisible
 * @param {bool}
 */
setDefaultVisible : function () {},

/**
 * @method defaultVisible
 * @return A value converted from C/C++ "bool"
 */
defaultVisible : function () {},

/**
 * @method CC3ShadowVolumeMeshNode
 * @constructor
 */
CC3ShadowVolumeMeshNode : function () {},

};

/**
 * @class CC3StencilledShadowPainterNode
 */
cc3.CC3StencilledShadowPainterNode = {

/**
 * @method setLight
 * @param {cocos3d::CC3Light*}
 */
setLight : function () {},

/**
 * @method getLight
 * @return A value converted from C/C++ "cocos3d::CC3Light*"
 */
getLight : function () {},

/**
 * @method updateShadow
 */
updateShadow : function () {},

/**
 * @method nodeWasDestroyed
 * @param {cocos3d::CC3Node*}
 */
nodeWasDestroyed : function () {},

/**
 * @method isShadowVisible
 * @return A value converted from C/C++ "bool"
 */
isShadowVisible : function () {},

/**
 * @method nodeWasTransformed
 * @param {cocos3d::CC3Node*}
 */
nodeWasTransformed : function () {},

/**
 * @method nodeWithName
 * @return A value converted from C/C++ "cocos3d::CC3StencilledShadowPainterNode*"
 * @param {std::string}
 * @param {cocos2d::ccColor4F}
 */
nodeWithName : function () {},

};
