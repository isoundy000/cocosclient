#ifndef __COCOSJS_MANUAL_CONVERSIONS_H__
#define __COCOSJS_MANUAL_CONVERSIONS_H__

#include "chipmunk.h"
#include "cocos2d.h"
#include "js_manual_conversions.h"
#include "cocos3d.h"

USING_NS_COCOS3D;

//#ifdef __cplusplus
//extern "C" {
//#endif
  
JSBool jsval_to_CGPoint( JSContext *cx, jsval vp, cpVect *out );
jsval CGPoint_to_jsval( JSContext *cx, cpVect p );

    
//#ifdef __cplusplus
//}
//#endif

#define cpVect_to_jsval CGPoint_to_jsval
#define jsval_to_cpVect jsval_to_CGPoint

JSBool jsval_to_c3dvector3(JSContext *cx, jsval v, CC3Vector* ret);
JSBool jsval_to_c3dvector4(JSContext *cx, jsval v, CC3Vector4* ret);
JSBool jsval_to_c3dquaternion(JSContext *cx, jsval v, CC3Quaternion* ret);

jsval c3dvector3_to_jsval(JSContext* cx, CC3Vector& v);
jsval c3dvector4_to_jsval(JSContext* cx, CC3Vector4& v);
jsval c3dquaternion_to_jsval(JSContext* cx, CC3Quaternion& v);


#endif /* __COCOSJS_MANUAL_CONVERSIONS_H__ */

