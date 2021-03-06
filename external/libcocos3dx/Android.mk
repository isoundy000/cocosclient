LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := cocos3dx_static

LOCAL_MODULE_FILENAME := libcocos3dx

LOCAL_SRC_FILES :=\
cocos3d.cpp \
Animations/CC3ActionManager.cpp \
Animations/CC3Actions.cpp \
Animations/CC3NodeAnimation.cpp \
cc3Extras/CC3MeshParticleSamples.cpp \
cc3Extras/CC3ModelSampleFactory.cpp \
cc3Extras/CC3ParticleSamples.cpp \
cc3Extras/CC3PointParticleSamples.cpp \
cc3PVR/CC3PFXResource.cpp \
cc3PVR/CC3PODCamera.cpp \
cc3PVR/CC3PODLight.cpp \
cc3PVR/CC3PODMaterial.cpp \
cc3PVR/CC3PODMesh.cpp \
cc3PVR/CC3PODMeshNode.cpp \
cc3PVR/CC3PODNode.cpp \
cc3PVR/CC3PODResource.cpp \
cc3PVR/CC3PODResourceNode.cpp \
cc3PVR/CC3PODVertexSkinning.cpp \
cc3PVR/CC3PVRFoundation.cpp \
cc3PVR/CC3PVRShamanShaderSemantics.cpp \
cc3PVR/CC3PVRTexture.cpp \
cc3PVR/PVRT/PVRTBoneBatch.cpp \
cc3PVR/PVRT/PVRTDecompress.cpp \
cc3PVR/PVRT/PVRTError.cpp \
cc3PVR/PVRT/PVRTFixedPoint.cpp \
cc3PVR/PVRT/PVRTMatrixF.cpp \
cc3PVR/PVRT/PVRTModelPOD.cpp \
cc3PVR/PVRT/PVRTPFXParser.cpp \
cc3PVR/PVRT/PVRTQuaternionF.cpp \
cc3PVR/PVRT/PVRTResourceFile.cpp \
cc3PVR/PVRT/PVRTString.cpp \
cc3PVR/PVRT/PVRTStringHash.cpp \
cc3PVR/PVRT/PVRTTexture.cpp \
cc3PVR/PVRT/PVRTTrans.cpp \
cc3PVR/PVRT/PVRTVector.cpp \
cc3PVR/PVRT/PVRTVertex.cpp \
cc3PVR/PVRT/OGLES/PVRTglesExt.cpp \
cc3PVR/PVRT/OGLES/PVRTTextureAPI.cpp \
Common/CC3Foundation.cpp \
Common/CC3Math.cpp \
Common/CC3Platform.cpp \
Common/CC3String.cpp \
Common/CC3Vector.cpp \
Common/CC3Vector4.cpp \
Common/LineScanner.cpp \
Common/LogDelegate.cpp \
Common/LogManager.cpp \
Controls/CCNodeAdornments.cpp \
Controls/Joystick.cpp \
Materials/stb_image.c \
Materials/CC3Material.cpp \
Materials/CC3STBImage.cpp \
Materials/CC3Texture.cpp \
Materials/CC3TextureUnit.cpp \
Matrices/CC3AffineMatrix.cpp \
Matrices/CC3LinearMatrix.cpp \
Matrices/CC3Matrix.cpp \
Matrices/CC3Matrix3x3.cpp \
Matrices/CC3Matrix4x3.cpp \
Matrices/CC3Matrix4x4.cpp \
Matrices/CC3ProjectionMatrix.cpp \
Meshes/CC3Mesh.cpp \
Meshes/CC3VertexArrays.cpp \
Meshes/CC3VertexSkinning.cpp \
Nodes/CC3Billboard.cpp \
Nodes/CC3BitmapLabelNode.cpp \
Nodes/CC3BoundingVolumes.cpp \
Nodes/CC3Camera.cpp \
Nodes/CC3EnvironmentNodes.cpp \
Nodes/CC3Light.cpp \
Nodes/CC3LocalContentNode.cpp \
Nodes/CC3MeshNode.cpp \
Nodes/CC3Node.cpp \
Nodes/CC3NodeListeners.cpp \
Nodes/CC3NodeVisitor.cpp \
Nodes/CC3UtilityMeshNodes.cpp \
OpenGL/CC3OpenGL.cpp \
OpenGL/CC3OpenGLFoundation.cpp \
OpenGL/CC3OpenGLProgPipeline.cpp \
OpenGL/CC3OpenGLUtility.cpp \
OpenGL/OpenGL2/CC3OpenGL2.cpp \
OpenGL/OpenGLES2/CC3OpenGLES2.cpp \
Particles/CC3CVAParticle.cpp \
Particles/CC3CVAParticleEmitter.cpp \
Particles/CC3MeshParticle.cpp \
Particles/CC3MeshParticleEmitter.cpp \
Particles/CC3Particle.cpp \
Particles/CC3ParticleEmitter.cpp \
Particles/CC3ParticleNavigator.cpp \
Particles/CC3PointParticle.cpp \
Particles/CC3PointParticleEmitter.cpp \
Resources/CC3DataStreams.cpp \
Resources/CC3NodesResource.cpp \
Resources/CC3Resource.cpp \
Resources/CC3ResourceNode.cpp \
Scenes/CC3Layer.cpp \
Scenes/CC3NodeSequencer.cpp \
Scenes/CC3RenderSurfaces.cpp \
Scenes/CC3Scene.cpp \
Shaders/CC3GLSLVariable.cpp \
Shaders/CC3ShaderContext.cpp \
Shaders/CC3ShaderMatcher.cpp \
Shaders/CC3Shaders.cpp \
Shaders/CC3ShaderSemantics.cpp \
Shadows/CC3ShadowVolumes.cpp \
Utility/CC3Backgrounder.cpp \
Utility/CC3Cache.cpp \
Utility/CC3DataArray.cpp \
Utility/CC3Identifiable.cpp \
Utility/CC3PerformanceStatistics.cpp \
Utility/CC3Rotator.cpp 

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ $(LOCAL_PATH)/../../extensions

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    
LOCAL_CFLAGS := -D__ANDROID__ -fexceptions -std=c++11
LOCAL_LDLIBS := -lGLESv2  -lEGL -llog -lz -landroid -lGLESv1_CM
                                    
include $(BUILD_STATIC_LIBRARY)

                           
