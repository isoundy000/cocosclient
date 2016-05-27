#ifndef _CPACKET_H_
#define _CPACKET_H_
#include <string>
#include "MessageBuffer.h"

using namespace std;
class MessageBuffer;
class CPacket:
public MessageBuffer{
public:
	CPacket();
	CPacket(int capacity);
	CPacket(const char* data, int size);
	~CPacket();
protected:
	//da loc du lieu header
	bool readHeadered;
public:
	// ma goi tin
	short cmdId;
	int controllerId;
	char error;
	const char* getData();
	
	void parseHeader();
	int getSize();
	void pack();
	int getControllerID(){return controllerId;}
	int getCmdID(){return cmdId;}
	int getError(){return error;}
	void cleanup(){delete this;}
	static bool isBigSize(const char* data){

		return true;
	}
	static short getCmdId(const char* data){
		return (data[4]<<8)+(data[5]&255);
	};



};

class InPacket : public CPacket
{
public:
	InPacket(): CPacket(){}
	InPacket(const char* data, int size) : CPacket(data,size){

	};
	InPacket(CPacket *packet)
	{
		CPacket(packet->buf,packet->capacity);
	}
	void init(CPacket *pkg)
	{
		pos = 0;
		capacity = pkg->capacity;
		limit = pkg->limit;
		buf = new char[capacity];
		memcpy(buf,pkg->buf,pkg->capacity);
		readHeadered = false;

		parseHeader();
	}

};

class OutPacket : public CPacket
{
public:
	OutPacket() : CPacket(1000)
	{}
	OutPacket(int capacity) : CPacket(capacity){

	};
	void setCmdId(int cmdId)
	{
		this->cmdId = cmdId;
	}
	void setControllerId(int controllerId)
	{
		this->controllerId = controllerId;
	}


};
#endif // _CPACKET_H_
