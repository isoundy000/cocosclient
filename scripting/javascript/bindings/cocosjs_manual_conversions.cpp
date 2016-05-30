#include "jsapi.h"
#include "jsfriendapi.h"
#include "ScriptingCore.h"
#include "js_bindings_config.h"
#include "cocosjs_manual_conversions.h"

#define JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES

using namespace cocos2d;

JSBool jsval_to_CCPoint( JSContext *cx, jsval vp, CCPoint *ret )
{
#ifdef JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
    
	JSObject *jsobj;
	if( ! JS_ValueToObject( cx, vp, &jsobj ) )
		return JS_FALSE;
	
	JSB_PRECONDITION( jsobj, "Not a valid JS object");
    
	jsval valx, valy;
	JSBool ok = JS_TRUE;
	ok &= JS_GetProperty(cx, jsobj, "x", &valx);
	ok &= JS_GetProperty(cx, jsobj, "y", &valy);
    
	if( ! ok )
		return JS_FALSE;
	
	double x, y;
	ok &= JS_ValueToNumber(cx, valx, &x);
	ok &= JS_ValueToNumber(cx, valy, &y);
	
	if( ! ok )
		return JS_FALSE;
	
	ret->x = x;
	ret->y = y;
    
	return JS_TRUE;
    
#else // #! JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
    
	JSObject *tmp_arg;
	if( ! JS_ValueToObject( cx, vp, &tmp_arg ) )
		return JS_FALSE;
	
	JSB_PRECONDITION( tmp_arg && JS_IsTypedArrayObject( tmp_arg, cx ), "Not a TypedArray object");
	
	JSB_PRECONDITION( JS_GetTypedArrayByteLength( tmp_arg, cx ) == sizeof(cpVect), "Invalid length");
	
	*ret = *(CCPoint*)JS_GetArrayBufferViewData( tmp_arg, cx );
	
	return JS_TRUE;
#endif // #! JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
}


JSBool jsval_to_CGPoint( JSContext *cx, jsval vp, cpVect *ret )
{
#ifdef JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
    
	JSObject *jsobj;
	if( ! JS_ValueToObject( cx, vp, &jsobj ) )
		return JS_FALSE;
	
	JSB_PRECONDITION( jsobj, "Not a valid JS object");
    
	jsval valx, valy;
	JSBool ok = JS_TRUE;
	ok &= JS_GetProperty(cx, jsobj, "x", &valx);
	ok &= JS_GetProperty(cx, jsobj, "y", &valy);
    
	if( ! ok )
		return JS_FALSE;
	
	double x, y;
	ok &= JS_ValueToNumber(cx, valx, &x);
	ok &= JS_ValueToNumber(cx, valy, &y);
	
	if( ! ok )
		return JS_FALSE;
	
	ret->x = x;
	ret->y = y;
    
	return JS_TRUE;
    
#else // #! JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
    
	JSObject *tmp_arg;
	if( ! JS_ValueToObject( cx, vp, &tmp_arg ) )
		return JS_FALSE;
	
	JSB_PRECONDITION( tmp_arg && JS_IsTypedArrayObject( tmp_arg, cx ), "Not a TypedArray object");
	
	JSB_PRECONDITION( JS_GetTypedArrayByteLength( tmp_arg, cx ) == sizeof(cpVect), "Invalid length");
	
	*ret = *(cpVect*)JS_GetArrayBufferViewData( tmp_arg, cx );
	
	return JS_TRUE;
#endif // #! JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
}

jsval c3dvector3_to_jsval(JSContext* cx, CC3Vector& v) {
	JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
	if (!tmp) return JSVAL_NULL;
	JSBool ok = JS_DefineProperty(cx, tmp, "x", DOUBLE_TO_JSVAL(v.x), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "y", DOUBLE_TO_JSVAL(v.y), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "z", DOUBLE_TO_JSVAL(v.z), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
	if (ok) {
		return OBJECT_TO_JSVAL(tmp);
	}
	return JSVAL_NULL;
}

jsval c3dvector4_to_jsval(JSContext* cx, CC3Vector4& v) {
	JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
	if (!tmp) return JSVAL_NULL;
	JSBool ok = JS_DefineProperty(cx, tmp, "x", DOUBLE_TO_JSVAL(v.x), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "y", DOUBLE_TO_JSVAL(v.y), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "z", DOUBLE_TO_JSVAL(v.z), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "w", DOUBLE_TO_JSVAL(v.w), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
	if (ok) {
		return OBJECT_TO_JSVAL(tmp);
	}
	return JSVAL_NULL;
}

jsval c3dquaternion_to_jsval(JSContext* cx, CC3Quaternion& v) {
	JSObject *tmp = JS_NewObject(cx, NULL, NULL, NULL);
	if (!tmp) return JSVAL_NULL;
	JSBool ok = JS_DefineProperty(cx, tmp, "x", DOUBLE_TO_JSVAL(v.x), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "y", DOUBLE_TO_JSVAL(v.y), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "z", DOUBLE_TO_JSVAL(v.z), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) &&
		JS_DefineProperty(cx, tmp, "w", DOUBLE_TO_JSVAL(v.w), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT);
	if (ok) {
		return OBJECT_TO_JSVAL(tmp);
	}
	return JSVAL_NULL;
}

JSBool jsval_to_c3dvector3(JSContext *cx, jsval v, CC3Vector* ret) {
	JSObject *tmp;
	jsval jsx, jsy,jsz;
	double x, y,z;
	JSBool ok = v.isObject() &&
		JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "x", &jsx) &&
		JS_GetProperty(cx, tmp, "y", &jsy) &&
		JS_GetProperty(cx, tmp, "z", &jsz) &&
		JS_ValueToNumber(cx, jsx, &x) &&
		JS_ValueToNumber(cx, jsy, &y);
		JS_ValueToNumber(cx, jsz, &z);

	JSB_PRECONDITION3(ok, cx, JS_FALSE, "Error processing arguments");

	ret->x = (float)x;
	ret->y = (float)y;
	ret->z = (float)z;

	return JS_TRUE;
}

JSBool jsval_to_c3dvector4(JSContext *cx, jsval v, CC3Vector4* ret) {
	JSObject *tmp;
	jsval jsx, jsy,jsz,jsw;
	double x, y,z,w;
	JSBool ok = v.isObject() &&
		JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "x", &jsx) &&
		JS_GetProperty(cx, tmp, "y", &jsy) &&
		JS_GetProperty(cx, tmp, "z", &jsz) &&
		JS_GetProperty(cx, tmp, "w", &jsw) &&

		JS_ValueToNumber(cx, jsx, &x) &&
		JS_ValueToNumber(cx, jsy, &y) &&
		JS_ValueToNumber(cx, jsz, &z) &&
		JS_ValueToNumber(cx, jsw, &w);


	JSB_PRECONDITION3(ok, cx, JS_FALSE, "Error processing arguments");

	ret->x = (float)x;
	ret->y = (float)y;
	ret->z = (float)z;
	ret->w = (float)w;

	return JS_TRUE;
}

JSBool jsval_to_c3dquaternion(JSContext *cx, jsval v, CC3Quaternion* ret) {
	JSObject *tmp;
	jsval jsx, jsy, jsz, jsw;
	double x, y, z, w;
	JSBool ok = v.isObject() &&
		JS_ValueToObject(cx, v, &tmp) &&
		JS_GetProperty(cx, tmp, "x", &jsx) &&
		JS_GetProperty(cx, tmp, "y", &jsy) &&
		JS_GetProperty(cx, tmp, "z", &jsz) &&
		JS_GetProperty(cx, tmp, "w", &jsw) &&

		JS_ValueToNumber(cx, jsx, &x) &&
		JS_ValueToNumber(cx, jsy, &y) &&
		JS_ValueToNumber(cx, jsz, &z) &&
		JS_ValueToNumber(cx, jsw, &w);


	JSB_PRECONDITION3(ok, cx, JS_FALSE, "Error processing arguments");

	ret->x = (float)x;
	ret->y = (float)y;
	ret->z = (float)z;
	ret->w = (float)w;

	return JS_TRUE;
}


jsval CGPoint_to_jsval( JSContext *cx, cpVect p)
{
	
#ifdef JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
    
	JSObject *object = JS_NewObject(cx, NULL, NULL, NULL );
	if (!object)
		return JSVAL_VOID;
    
	if (!JS_DefineProperty(cx, object, "x", DOUBLE_TO_JSVAL(p.x), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) ||
		!JS_DefineProperty(cx, object, "y", DOUBLE_TO_JSVAL(p.y), NULL, NULL, JSPROP_ENUMERATE | JSPROP_PERMANENT) )
		return JSVAL_VOID;
	
	return OBJECT_TO_JSVAL(object);
    
#else // JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
	
#ifdef __LP64__
	JSObject *typedArray = JS_NewFloat64Array( cx, 2 );
#else
	JSObject *typedArray = JS_NewFloat32Array( cx, 2 );
#endif
    
	cpVect *buffer = (cpVect*)JS_GetArrayBufferViewData(typedArray, cx );
	*buffer = p;
	return OBJECT_TO_JSVAL(typedArray);
#endif // ! JSB_COMPATIBLE_WITH_COCOS2D_HTML5_BASIC_TYPES
}
