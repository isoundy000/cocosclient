#include "jsb_engine_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "CShake.h"
#include "Handler.h"
#include "CAvatar.h"
#include "UIAVatar.h"
#include "ClientBitZero.h"
#include "CPacket.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
	cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
	if (_ccobj) {
		_ccobj->autorelease();
	}
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
	JS_AddObjectRoot(cx, &pp->obj);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *jsb_HandlerListener_class;
JSObject *jsb_HandlerListener_prototype;

JSBool js_engine_HandlerListener_getHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerListener* cobj = (HandlerListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		Handler* ret = cobj->getHandler();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Handler>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_HandlerListener_getData(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerListener* cobj = (HandlerListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		std::string ret = cobj->getData();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_HandlerListener_onResponse(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerListener* cobj = (HandlerListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		Handler* arg0;
		std::string arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (Handler*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->onResponse(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_HandlerListener_autorelease(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerListener* cobj = (HandlerListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cocos2d::CCObject* ret = cobj->autorelease();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::CCObject>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_CCNode_prototype;

void js_engine_HandlerListener_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (HandlerListener)", obj);
}

static JSBool js_engine_HandlerListener_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    HandlerListener *nobj = new HandlerListener();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "HandlerListener");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_HandlerListener(JSContext *cx, JSObject *global) {
	jsb_HandlerListener_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_HandlerListener_class->name = "HandlerListener";
	jsb_HandlerListener_class->addProperty = JS_PropertyStub;
	jsb_HandlerListener_class->delProperty = JS_PropertyStub;
	jsb_HandlerListener_class->getProperty = JS_PropertyStub;
	jsb_HandlerListener_class->setProperty = JS_StrictPropertyStub;
	jsb_HandlerListener_class->enumerate = JS_EnumerateStub;
	jsb_HandlerListener_class->resolve = JS_ResolveStub;
	jsb_HandlerListener_class->convert = JS_ConvertStub;
	jsb_HandlerListener_class->finalize = js_engine_HandlerListener_finalize;
	jsb_HandlerListener_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getHandler", js_engine_HandlerListener_getHandler, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getData", js_engine_HandlerListener_getData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("onResponse", js_engine_HandlerListener_onResponse, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("autorelease", js_engine_HandlerListener_autorelease, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_HandlerListener_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_HandlerListener_prototype = JS_InitClass(
		cx, global,
		jsb_CCNode_prototype,
		jsb_HandlerListener_class,
		dummy_constructor<HandlerListener>, 0, // no constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "HandlerListener", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<HandlerListener> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_HandlerListener_class;
		p->proto = jsb_HandlerListener_prototype;
		p->parentProto = jsb_CCNode_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_Handler_class;
JSObject *jsb_Handler_prototype;

JSBool js_engine_Handler_addListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	Handler* cobj = (Handler *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		HandlerListener* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (HandlerListener*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->addListener(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_Handler_getID(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	Handler* cobj = (Handler *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		std::string ret = cobj->getID();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_Handler_cleanup(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	Handler* cobj = (Handler *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->cleanup();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_Handler_setTimeOut(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	Handler* cobj = (Handler *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setTimeOut(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_Handler_clearListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	Handler* cobj = (Handler *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->clearListener();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_Handler_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	Handler* cobj = NULL;
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new Handler(arg0);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<Handler> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "Handler");
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new Handler();
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<Handler> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "Handler");
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}




void js_engine_Handler_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Handler)", obj);
}

static JSBool js_engine_Handler_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    Handler *nobj = new Handler();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "Handler");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_Handler(JSContext *cx, JSObject *global) {
	jsb_Handler_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_Handler_class->name = "Handler";
	jsb_Handler_class->addProperty = JS_PropertyStub;
	jsb_Handler_class->delProperty = JS_PropertyStub;
	jsb_Handler_class->getProperty = JS_PropertyStub;
	jsb_Handler_class->setProperty = JS_StrictPropertyStub;
	jsb_Handler_class->enumerate = JS_EnumerateStub;
	jsb_Handler_class->resolve = JS_ResolveStub;
	jsb_Handler_class->convert = JS_ConvertStub;
	jsb_Handler_class->finalize = js_engine_Handler_finalize;
	jsb_Handler_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("addListener", js_engine_Handler_addListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getID", js_engine_Handler_getID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("cleanup", js_engine_Handler_cleanup, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTimeOut", js_engine_Handler_setTimeOut, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("clearListener", js_engine_Handler_clearListener, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_Handler_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_Handler_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_Handler_class,
		js_engine_Handler_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "Handler", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<Handler> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_Handler_class;
		p->proto = jsb_Handler_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_HandlerManager_class;
JSObject *jsb_HandlerManager_prototype;

JSBool js_engine_HandlerManager_addHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerManager* cobj = (HandlerManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		std::string arg0;
		HandlerListener* arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		do {
			if (!argv[1].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg1 = (HandlerListener*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		Handler* ret = cobj->addHandler(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Handler>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_HandlerManager_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerManager* cobj = (HandlerManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->update(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_HandlerManager_forceRemoveHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerManager* cobj = (HandlerManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->forceRemoveHandler(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_HandlerManager_stopHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerManager* cobj = (HandlerManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->stopHandler(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_HandlerManager_getHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	HandlerManager* cobj = (HandlerManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		Handler* ret = cobj->getHandler(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<Handler>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_HandlerManager_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		HandlerManager::destroyInstance();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_HandlerManager_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		HandlerManager* ret = HandlerManager::getInstance();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<HandlerManager>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_HandlerManager_localizedString(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		std::string ret = HandlerManager::localizedString(arg0);
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_HandlerManager_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		HandlerManager* cobj = new HandlerManager();
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<HandlerManager> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "HandlerManager");
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}




void js_engine_HandlerManager_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (HandlerManager)", obj);
}

static JSBool js_engine_HandlerManager_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    HandlerManager *nobj = new HandlerManager();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "HandlerManager");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_HandlerManager(JSContext *cx, JSObject *global) {
	jsb_HandlerManager_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_HandlerManager_class->name = "HandlerManager";
	jsb_HandlerManager_class->addProperty = JS_PropertyStub;
	jsb_HandlerManager_class->delProperty = JS_PropertyStub;
	jsb_HandlerManager_class->getProperty = JS_PropertyStub;
	jsb_HandlerManager_class->setProperty = JS_StrictPropertyStub;
	jsb_HandlerManager_class->enumerate = JS_EnumerateStub;
	jsb_HandlerManager_class->resolve = JS_ResolveStub;
	jsb_HandlerManager_class->convert = JS_ConvertStub;
	jsb_HandlerManager_class->finalize = js_engine_HandlerManager_finalize;
	jsb_HandlerManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("addHandler", js_engine_HandlerManager_addHandler, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_engine_HandlerManager_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("forceRemoveHandler", js_engine_HandlerManager_forceRemoveHandler, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("stopHandler", js_engine_HandlerManager_stopHandler, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getHandler", js_engine_HandlerManager_getHandler, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_HandlerManager_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("destroyInstance", js_engine_HandlerManager_destroyInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInstance", js_engine_HandlerManager_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("localizedString", js_engine_HandlerManager_localizedString, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_HandlerManager_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_HandlerManager_class,
		js_engine_HandlerManager_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "HandlerManager", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<HandlerManager> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_HandlerManager_class;
		p->proto = jsb_HandlerManager_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_CCAvatar_class;
JSObject *jsb_CCAvatar_prototype;

JSBool js_engine_CCAvatar_setImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CCAvatar* cobj = (CCAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		const char* arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setImage(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_CCAvatar_finishDownload(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CCAvatar* cobj = (CCAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		cocos2d::CCNode* arg0;
		void* arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		#pragma warning NO CONVERSION TO NATIVE FOR void*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->finishDownload(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_CCAvatar_checkAndSetTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CCAvatar* cobj = (CCAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		cocos2d::CCTexture2D* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::CCTexture2D*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->checkAndSetTexture(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_CCAvatar_loadingNCallBack(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CCAvatar* cobj = (CCAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		cocos2d::CCObject* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::CCObject*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->loadingNCallBack(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_CCAvatar_updateImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CCAvatar* cobj = (CCAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->updateImage();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CCAvatar_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	
	do {
		if (argc == 1) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			CCAvatar* ret = CCAvatar::create(arg0);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<CCAvatar>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	
	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg2;
			std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			CCAvatar* ret = CCAvatar::create(arg0, arg1, arg2);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<CCAvatar>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_engine_CCAvatar_filePathFromUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 2) {
		const char* arg0;
		const char* arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		std::string ret = CCAvatar::filePathFromUrl(arg0, arg1);
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_CCAvatar_createWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		CCAvatar* ret = CCAvatar::createWithSpriteFrame(arg0);
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<CCAvatar>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_CCAvatar_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		CCAvatar* cobj = new CCAvatar();
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<CCAvatar> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "CCAvatar");
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



extern JSObject *jsb_CCSprite_prototype;

void js_engine_CCAvatar_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CCAvatar)", obj);
}

static JSBool js_engine_CCAvatar_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    CCAvatar *nobj = new CCAvatar();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "CCAvatar");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_CCAvatar(JSContext *cx, JSObject *global) {
	jsb_CCAvatar_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_CCAvatar_class->name = "CCAvatar";
	jsb_CCAvatar_class->addProperty = JS_PropertyStub;
	jsb_CCAvatar_class->delProperty = JS_PropertyStub;
	jsb_CCAvatar_class->getProperty = JS_PropertyStub;
	jsb_CCAvatar_class->setProperty = JS_StrictPropertyStub;
	jsb_CCAvatar_class->enumerate = JS_EnumerateStub;
	jsb_CCAvatar_class->resolve = JS_ResolveStub;
	jsb_CCAvatar_class->convert = JS_ConvertStub;
	jsb_CCAvatar_class->finalize = js_engine_CCAvatar_finalize;
	jsb_CCAvatar_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setImage", js_engine_CCAvatar_setImage, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("finishDownload", js_engine_CCAvatar_finishDownload, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("checkAndSetTexture", js_engine_CCAvatar_checkAndSetTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadingNCallBack", js_engine_CCAvatar_loadingNCallBack, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("updateImage", js_engine_CCAvatar_updateImage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_CCAvatar_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_engine_CCAvatar_create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("filePathFromUrl", js_engine_CCAvatar_filePathFromUrl, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("createWithSpriteFrame", js_engine_CCAvatar_createWithSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_CCAvatar_prototype = JS_InitClass(
		cx, global,
		jsb_CCSprite_prototype,
		jsb_CCAvatar_class,
		js_engine_CCAvatar_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "CCAvatar", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<CCAvatar> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_CCAvatar_class;
		p->proto = jsb_CCAvatar_prototype;
		p->parentProto = jsb_CCSprite_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_UIAvatar_class;
JSObject *jsb_UIAvatar_prototype;

JSBool js_engine_UIAvatar_setTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	UIAvatar* cobj = (UIAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		cocos2d::CCTexture2D* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::CCTexture2D*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setTexture(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_finishDownload(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	UIAvatar* cobj = (UIAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		cocos2d::CCNode* arg0;
		void* arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		#pragma warning NO CONVERSION TO NATIVE FOR void*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->finishDownload(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_asyncExecuteWithUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	UIAvatar* cobj = (UIAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->asyncExecuteWithUrl(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_setDefaultImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	UIAvatar* cobj = (UIAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->setDefaultImage();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_setImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	UIAvatar* cobj = (UIAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setImage(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_getImageSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	UIAvatar* cobj = (UIAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cocos2d::CCSize ret = cobj->getImageSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_asyncExecute(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	UIAvatar* cobj = (UIAvatar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->asyncExecute();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	
	do {
		if (argc == 2) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			std::string arg1;
			ok &= jsval_to_std_string(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			UIAvatar* ret = UIAvatar::create(arg0, arg1);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<UIAvatar>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	
	do {
		if (argc == 3) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			std::string arg1;
			ok &= jsval_to_std_string(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			std::string arg2;
			ok &= jsval_to_std_string(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			UIAvatar* ret = UIAvatar::create(arg0, arg1, arg2);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<UIAvatar>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_engine_UIAvatar_createWithMask(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 3) {
		std::string arg0;
		std::string arg1;
		std::string arg2;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		ok &= jsval_to_std_string(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		UIAvatar* ret = UIAvatar::createWithMask(arg0, arg1, arg2);
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<UIAvatar>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_UIAvatar_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		UIAvatar* cobj = new UIAvatar();
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<UIAvatar> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "UIAvatar");
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



extern JSObject *jsb_Widget_prototype;

void js_engine_UIAvatar_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIAvatar)", obj);
}

static JSBool js_engine_UIAvatar_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    UIAvatar *nobj = new UIAvatar();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "UIAvatar");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_UIAvatar(JSContext *cx, JSObject *global) {
	jsb_UIAvatar_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIAvatar_class->name = "UIAvatar";
	jsb_UIAvatar_class->addProperty = JS_PropertyStub;
	jsb_UIAvatar_class->delProperty = JS_PropertyStub;
	jsb_UIAvatar_class->getProperty = JS_PropertyStub;
	jsb_UIAvatar_class->setProperty = JS_StrictPropertyStub;
	jsb_UIAvatar_class->enumerate = JS_EnumerateStub;
	jsb_UIAvatar_class->resolve = JS_ResolveStub;
	jsb_UIAvatar_class->convert = JS_ConvertStub;
	jsb_UIAvatar_class->finalize = js_engine_UIAvatar_finalize;
	jsb_UIAvatar_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setTexture", js_engine_UIAvatar_setTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("finishDownload", js_engine_UIAvatar_finishDownload, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("asyncExecuteWithUrl", js_engine_UIAvatar_asyncExecuteWithUrl, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDefaultImage", js_engine_UIAvatar_setDefaultImage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setImage", js_engine_UIAvatar_setImage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getImageSize", js_engine_UIAvatar_getImageSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("asyncExecute", js_engine_UIAvatar_asyncExecute, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_UIAvatar_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_engine_UIAvatar_create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("createWithMask", js_engine_UIAvatar_createWithMask, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIAvatar_prototype = JS_InitClass(
		cx, global,
		jsb_Widget_prototype,
		jsb_UIAvatar_class,
		js_engine_UIAvatar_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIAvatar", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<UIAvatar> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_UIAvatar_class;
		p->proto = jsb_UIAvatar_prototype;
		p->parentProto = jsb_Widget_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_MessageBuffer_class;
JSObject *jsb_MessageBuffer_prototype;

JSBool js_engine_MessageBuffer_putInt(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		MessageBuffer* ret = cobj->putInt(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<MessageBuffer>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getString(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		std::string ret = cobj->getString();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_putBytes(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		int arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		MessageBuffer* ret = cobj->putBytes(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<MessageBuffer>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getShort(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getShort();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_putByteArray(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		int arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		MessageBuffer* ret = cobj->putByteArray(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<MessageBuffer>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_putShort(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		MessageBuffer* ret = cobj->putShort(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<MessageBuffer>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getCapacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getCapacity();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_rewind(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->rewind();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getLimit(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getLimit();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_putByte(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		MessageBuffer* ret = cobj->putByte(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<MessageBuffer>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getByte(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getByte();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getBool(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getBool();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_putString(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		MessageBuffer* ret = cobj->putString(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<MessageBuffer>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_initData(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->initData(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_autorelease(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cocos2d::CCObject* ret = cobj->autorelease();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::CCObject>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getInt(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getInt();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getPosition();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getDouble(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getDouble();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_putDouble(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		MessageBuffer* ret = cobj->putDouble(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<MessageBuffer>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_reload(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		int arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->reload(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_getUnsignedShort(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	MessageBuffer* cobj = (MessageBuffer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getUnsignedShort();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_MessageBuffer_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	MessageBuffer* cobj = NULL;
	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new MessageBuffer(arg0);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<MessageBuffer> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "MessageBuffer");
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new MessageBuffer();
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<MessageBuffer> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "MessageBuffer");
		}
	} while(0);

	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new MessageBuffer(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<MessageBuffer> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "MessageBuffer");
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}




void js_engine_MessageBuffer_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (MessageBuffer)", obj);
}

static JSBool js_engine_MessageBuffer_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    MessageBuffer *nobj = new MessageBuffer();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "MessageBuffer");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_MessageBuffer(JSContext *cx, JSObject *global) {
	jsb_MessageBuffer_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_MessageBuffer_class->name = "MessageBuffer";
	jsb_MessageBuffer_class->addProperty = JS_PropertyStub;
	jsb_MessageBuffer_class->delProperty = JS_PropertyStub;
	jsb_MessageBuffer_class->getProperty = JS_PropertyStub;
	jsb_MessageBuffer_class->setProperty = JS_StrictPropertyStub;
	jsb_MessageBuffer_class->enumerate = JS_EnumerateStub;
	jsb_MessageBuffer_class->resolve = JS_ResolveStub;
	jsb_MessageBuffer_class->convert = JS_ConvertStub;
	jsb_MessageBuffer_class->finalize = js_engine_MessageBuffer_finalize;
	jsb_MessageBuffer_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("putInt", js_engine_MessageBuffer_putInt, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getString", js_engine_MessageBuffer_getString, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("putBytes", js_engine_MessageBuffer_putBytes, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getShort", js_engine_MessageBuffer_getShort, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("putByteArray", js_engine_MessageBuffer_putByteArray, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("putShort", js_engine_MessageBuffer_putShort, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCapacity", js_engine_MessageBuffer_getCapacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("rewind", js_engine_MessageBuffer_rewind, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getLimit", js_engine_MessageBuffer_getLimit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("putByte", js_engine_MessageBuffer_putByte, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getByte", js_engine_MessageBuffer_getByte, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBool", js_engine_MessageBuffer_getBool, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("putString", js_engine_MessageBuffer_putString, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initData", js_engine_MessageBuffer_initData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("autorelease", js_engine_MessageBuffer_autorelease, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInt", js_engine_MessageBuffer_getInt, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPosition", js_engine_MessageBuffer_getPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDouble", js_engine_MessageBuffer_getDouble, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("putDouble", js_engine_MessageBuffer_putDouble, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("reload", js_engine_MessageBuffer_reload, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getUnsignedShort", js_engine_MessageBuffer_getUnsignedShort, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_MessageBuffer_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_MessageBuffer_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_MessageBuffer_class,
		js_engine_MessageBuffer_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "MessageBuffer", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<MessageBuffer> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_MessageBuffer_class;
		p->proto = jsb_MessageBuffer_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_CPacket_class;
JSObject *jsb_CPacket_prototype;

JSBool js_engine_CPacket_getCmdID(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getCmdID();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_getError(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getError();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_parseHeader(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->parseHeader();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_getSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getSize();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_cleanup(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->cleanup();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_getControllerID(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getControllerID();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_getData(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getData();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_pack(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	CPacket* cobj = (CPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->pack();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_CPacket_getCmdId(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		short ret = CPacket::getCmdId(arg0);
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR short;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_CPacket_isBigSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = CPacket::isBigSize(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_CPacket_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	CPacket* cobj = NULL;
	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new CPacket(arg0);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<CPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "CPacket");
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new CPacket();
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<CPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "CPacket");
		}
	} while(0);

	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new CPacket(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<CPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "CPacket");
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}



extern JSObject *jsb_MessageBuffer_prototype;

void js_engine_CPacket_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CPacket)", obj);
}

static JSBool js_engine_CPacket_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    CPacket *nobj = new CPacket();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "CPacket");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_CPacket(JSContext *cx, JSObject *global) {
	jsb_CPacket_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_CPacket_class->name = "CPacket";
	jsb_CPacket_class->addProperty = JS_PropertyStub;
	jsb_CPacket_class->delProperty = JS_PropertyStub;
	jsb_CPacket_class->getProperty = JS_PropertyStub;
	jsb_CPacket_class->setProperty = JS_StrictPropertyStub;
	jsb_CPacket_class->enumerate = JS_EnumerateStub;
	jsb_CPacket_class->resolve = JS_ResolveStub;
	jsb_CPacket_class->convert = JS_ConvertStub;
	jsb_CPacket_class->finalize = js_engine_CPacket_finalize;
	jsb_CPacket_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getCmdID", js_engine_CPacket_getCmdID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getError", js_engine_CPacket_getError, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("parseHeader", js_engine_CPacket_parseHeader, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSize", js_engine_CPacket_getSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("cleanup", js_engine_CPacket_cleanup, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getControllerID", js_engine_CPacket_getControllerID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getData", js_engine_CPacket_getData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("pack", js_engine_CPacket_pack, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_CPacket_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("getCmdId", js_engine_CPacket_getCmdId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isBigSize", js_engine_CPacket_isBigSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_CPacket_prototype = JS_InitClass(
		cx, global,
		jsb_MessageBuffer_prototype,
		jsb_CPacket_class,
		js_engine_CPacket_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "CPacket", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<CPacket> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_CPacket_class;
		p->proto = jsb_CPacket_prototype;
		p->parentProto = jsb_MessageBuffer_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_InPacket_class;
JSObject *jsb_InPacket_prototype;

JSBool js_engine_InPacket_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	InPacket* cobj = (InPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		CPacket* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (CPacket*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->init(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_InPacket_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	InPacket* cobj = NULL;
	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			int arg1;
			ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new InPacket(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<InPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "InPacket");
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new InPacket();
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<InPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "InPacket");
		}
	} while(0);

	do {
		if (argc == 1) {
			CPacket* arg0;
			do {
				if (!argv[0].isObject()) { ok = JS_FALSE; break; }
				js_proxy_t *proxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				proxy = jsb_get_js_proxy(tmpObj);
				arg0 = (CPacket*)(proxy ? proxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new InPacket(arg0);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<InPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "InPacket");
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}



extern JSObject *jsb_CPacket_prototype;

void js_engine_InPacket_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (InPacket)", obj);
}

static JSBool js_engine_InPacket_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    InPacket *nobj = new InPacket();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "InPacket");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_InPacket(JSContext *cx, JSObject *global) {
	jsb_InPacket_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_InPacket_class->name = "InPacket";
	jsb_InPacket_class->addProperty = JS_PropertyStub;
	jsb_InPacket_class->delProperty = JS_PropertyStub;
	jsb_InPacket_class->getProperty = JS_PropertyStub;
	jsb_InPacket_class->setProperty = JS_StrictPropertyStub;
	jsb_InPacket_class->enumerate = JS_EnumerateStub;
	jsb_InPacket_class->resolve = JS_ResolveStub;
	jsb_InPacket_class->convert = JS_ConvertStub;
	jsb_InPacket_class->finalize = js_engine_InPacket_finalize;
	jsb_InPacket_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	static JSFunctionSpec funcs[] = {
		JS_FN("init", js_engine_InPacket_init, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_InPacket_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_InPacket_prototype = JS_InitClass(
		cx, global,
		jsb_CPacket_prototype,
		jsb_InPacket_class,
		js_engine_InPacket_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "InPacket", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<InPacket> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_InPacket_class;
		p->proto = jsb_InPacket_prototype;
		p->parentProto = jsb_CPacket_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_OutPacket_class;
JSObject *jsb_OutPacket_prototype;

JSBool js_engine_OutPacket_setControllerId(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	OutPacket* cobj = (OutPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setControllerId(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_OutPacket_setCmdId(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	OutPacket* cobj = (OutPacket *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setCmdId(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_OutPacket_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	OutPacket* cobj = NULL;
	do {
		if (argc == 1) {
			int arg0;
			ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new OutPacket(arg0);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<OutPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "OutPacket");
		}
	} while(0);

	do {
		if (argc == 0) {
			cobj = new OutPacket();
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<OutPacket> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "OutPacket");
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}



extern JSObject *jsb_CPacket_prototype;

void js_engine_OutPacket_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (OutPacket)", obj);
}

static JSBool js_engine_OutPacket_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    OutPacket *nobj = new OutPacket();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "OutPacket");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_OutPacket(JSContext *cx, JSObject *global) {
	jsb_OutPacket_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_OutPacket_class->name = "OutPacket";
	jsb_OutPacket_class->addProperty = JS_PropertyStub;
	jsb_OutPacket_class->delProperty = JS_PropertyStub;
	jsb_OutPacket_class->getProperty = JS_PropertyStub;
	jsb_OutPacket_class->setProperty = JS_StrictPropertyStub;
	jsb_OutPacket_class->enumerate = JS_EnumerateStub;
	jsb_OutPacket_class->resolve = JS_ResolveStub;
	jsb_OutPacket_class->convert = JS_ConvertStub;
	jsb_OutPacket_class->finalize = js_engine_OutPacket_finalize;
	jsb_OutPacket_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	static JSFunctionSpec funcs[] = {
		JS_FN("setControllerId", js_engine_OutPacket_setControllerId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCmdId", js_engine_OutPacket_setCmdId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_OutPacket_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_OutPacket_prototype = JS_InitClass(
		cx, global,
		jsb_CPacket_prototype,
		jsb_OutPacket_class,
		js_engine_OutPacket_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "OutPacket", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<OutPacket> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_OutPacket_class;
		p->proto = jsb_OutPacket_prototype;
		p->parentProto = jsb_CPacket_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_BZListener_class;
JSObject *jsb_BZListener_prototype;

JSBool js_engine_BZListener_onReceived(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	BZListener* cobj = (BZListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		CPacket* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (CPacket*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->onReceived(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_BZListener_getState(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	BZListener* cobj = (BZListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getState();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_BZListener_getSuccess(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	BZListener* cobj = (BZListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getSuccess();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_BZListener_autorelease(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	BZListener* cobj = (BZListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cocos2d::CCObject* ret = cobj->autorelease();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::CCObject>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_BZListener_onFinishConnect(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	BZListener* cobj = (BZListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->onFinishConnect(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_BZListener_onDisconnected(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	BZListener* cobj = (BZListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->onDisconnected();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_BZListener_getPacket(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	BZListener* cobj = (BZListener *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		CPacket* ret = cobj->getPacket();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<CPacket>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_BZListener_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		BZListener* cobj = new BZListener();
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<BZListener> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "BZListener");
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



extern JSObject *jsb_CCNode_prototype;

void js_engine_BZListener_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (BZListener)", obj);
}

static JSBool js_engine_BZListener_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    BZListener *nobj = new BZListener();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "BZListener");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_BZListener(JSContext *cx, JSObject *global) {
	jsb_BZListener_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_BZListener_class->name = "BZListener";
	jsb_BZListener_class->addProperty = JS_PropertyStub;
	jsb_BZListener_class->delProperty = JS_PropertyStub;
	jsb_BZListener_class->getProperty = JS_PropertyStub;
	jsb_BZListener_class->setProperty = JS_StrictPropertyStub;
	jsb_BZListener_class->enumerate = JS_EnumerateStub;
	jsb_BZListener_class->resolve = JS_ResolveStub;
	jsb_BZListener_class->convert = JS_ConvertStub;
	jsb_BZListener_class->finalize = js_engine_BZListener_finalize;
	jsb_BZListener_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("onReceived", js_engine_BZListener_onReceived, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getState", js_engine_BZListener_getState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSuccess", js_engine_BZListener_getSuccess, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("autorelease", js_engine_BZListener_autorelease, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("onFinishConnect", js_engine_BZListener_onFinishConnect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("onDisconnected", js_engine_BZListener_onDisconnected, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPacket", js_engine_BZListener_getPacket, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_BZListener_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_BZListener_prototype = JS_InitClass(
		cx, global,
		jsb_CCNode_prototype,
		jsb_BZListener_class,
		js_engine_BZListener_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "BZListener", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<BZListener> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_BZListener_class;
		p->proto = jsb_BZListener_prototype;
		p->parentProto = jsb_CCNode_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_ClientBitZero_class;
JSObject *jsb_ClientBitZero_prototype;

JSBool js_engine_ClientBitZero_setTimeoutForConnect(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setTimeoutForConnect(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_createSocket(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->createSocket();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_getIsDisconnectHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getIsDisconnectHandler();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_getTimeoutForConnect(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getTimeoutForConnect();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_connect(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		int arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->connect(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_reconnect(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->reconnect();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_disconnect(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->disconnect();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_initThread(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->initThread();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_setTimeoutForRead(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setTimeoutForRead(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_send(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		CPacket* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (CPacket*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->send(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_setListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		BZListener* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (BZListener*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setListener(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_dispatchResponseCallbacks(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->dispatchResponseCallbacks(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_setNeedConnect(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 3) {
		JSBool arg0;
		std::string arg1;
		int arg2;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setNeedConnect(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_getTimeoutForRead(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getTimeoutForRead();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_isDoConnection(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isDoConnection();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_setAutoReconnect(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setAutoReconnect(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_getIsReady(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getIsReady();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_setIsDisconnectHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	ClientBitZero* cobj = (ClientBitZero *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setIsDisconnectHandler(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_engine_ClientBitZero_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		ClientBitZero::destroyInstance();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_ClientBitZero_networkThread(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 1) {
		void* arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR void*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		void* ret = ClientBitZero::networkThread(arg0);
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR void*;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_ClientBitZero_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		ClientBitZero* ret = ClientBitZero::getInstance();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<ClientBitZero>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}

JSBool js_engine_ClientBitZero_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		ClientBitZero* cobj = new ClientBitZero();
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<ClientBitZero> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "ClientBitZero");
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}




void js_engine_ClientBitZero_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ClientBitZero)", obj);
}

static JSBool js_engine_ClientBitZero_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    ClientBitZero *nobj = new ClientBitZero();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "ClientBitZero");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_engine_ClientBitZero(JSContext *cx, JSObject *global) {
	jsb_ClientBitZero_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_ClientBitZero_class->name = "ClientBitZero";
	jsb_ClientBitZero_class->addProperty = JS_PropertyStub;
	jsb_ClientBitZero_class->delProperty = JS_PropertyStub;
	jsb_ClientBitZero_class->getProperty = JS_PropertyStub;
	jsb_ClientBitZero_class->setProperty = JS_StrictPropertyStub;
	jsb_ClientBitZero_class->enumerate = JS_EnumerateStub;
	jsb_ClientBitZero_class->resolve = JS_ResolveStub;
	jsb_ClientBitZero_class->convert = JS_ConvertStub;
	jsb_ClientBitZero_class->finalize = js_engine_ClientBitZero_finalize;
	jsb_ClientBitZero_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setTimeoutForConnect", js_engine_ClientBitZero_setTimeoutForConnect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("createSocket", js_engine_ClientBitZero_createSocket, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getIsDisconnectHandler", js_engine_ClientBitZero_getIsDisconnectHandler, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTimeoutForConnect", js_engine_ClientBitZero_getTimeoutForConnect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("connect", js_engine_ClientBitZero_connect, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("reconnect", js_engine_ClientBitZero_reconnect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("disconnect", js_engine_ClientBitZero_disconnect, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initThread", js_engine_ClientBitZero_initThread, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTimeoutForRead", js_engine_ClientBitZero_setTimeoutForRead, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("send", js_engine_ClientBitZero_send, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setListener", js_engine_ClientBitZero_setListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("dispatchResponseCallbacks", js_engine_ClientBitZero_dispatchResponseCallbacks, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setNeedConnect", js_engine_ClientBitZero_setNeedConnect, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTimeoutForRead", js_engine_ClientBitZero_getTimeoutForRead, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isDoConnection", js_engine_ClientBitZero_isDoConnection, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAutoReconnect", js_engine_ClientBitZero_setAutoReconnect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getIsReady", js_engine_ClientBitZero_getIsReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setIsDisconnectHandler", js_engine_ClientBitZero_setIsDisconnectHandler, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_engine_ClientBitZero_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("destroyInstance", js_engine_ClientBitZero_destroyInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("networkThread", js_engine_ClientBitZero_networkThread, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInstance", js_engine_ClientBitZero_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_ClientBitZero_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_ClientBitZero_class,
		js_engine_ClientBitZero_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "ClientBitZero", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<ClientBitZero> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_ClientBitZero_class;
		p->proto = jsb_ClientBitZero_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_engine(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	jsval nsval;
	JSObject *ns;
	JS_GetProperty(cx, obj, "engine", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "engine", &nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_engine_MessageBuffer(cx, obj);
	js_register_engine_CPacket(cx, obj);
	js_register_engine_InPacket(cx, obj);
	js_register_engine_ClientBitZero(cx, obj);
	js_register_engine_OutPacket(cx, obj);
	js_register_engine_HandlerListener(cx, obj);
	js_register_engine_HandlerManager(cx, obj);
	js_register_engine_Handler(cx, obj);
	js_register_engine_BZListener(cx, obj);
	js_register_engine_CCAvatar(cx, obj);
	js_register_engine_UIAvatar(cx, obj);
}

