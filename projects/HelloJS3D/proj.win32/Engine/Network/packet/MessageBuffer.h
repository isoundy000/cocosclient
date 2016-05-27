#ifndef _MESSAGE_BUFFER_H_
#define _MESSAGE_BUFFER_H_
#include <stdio.h>
#include <string>
#include "cocos2d.h"

#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace std;
class MessageBuffer : public CCObject{
public:
	int capacity;
	int limit;
	char* buf;
	int pos;
public:
	MessageBuffer();
	MessageBuffer(int capacity);
	MessageBuffer(const char* data, int size);
	~MessageBuffer();
	MessageBuffer* putByte(int b);
	MessageBuffer* putBytes(const char* bytes, int size);
	MessageBuffer* putByteArray(const char* bytes, int size);
	MessageBuffer* putShort(int v);
	MessageBuffer* putInt(int v);
	MessageBuffer* putDouble(double d);
	MessageBuffer* putString(string str);

	void initData(int capacity);


	void reload(const char* data, int size);
	int* getBytes(int size);
	char* getUnsignedBytes(int size);
	int getByte();
	int getShort();
	int getUnsignedShort();
	int getInt();
	double getDouble();
	bool getBool();
	char* getCharArray(int& size) ;
	string getString();
	inline int getCapacity() {
		return capacity;
	};
	inline int getLimit() {
		return limit;
	};
	inline int getPosition() {
		return pos;
	}
	inline void rewind() {
		pos = 0;
	};
	bool* getBools();
	double* getDoubles();
	int* getBytes();

	CCObject* autorelease(){return this;};

};
#endif