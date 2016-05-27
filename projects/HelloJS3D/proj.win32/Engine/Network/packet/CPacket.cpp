#include "CPacket.h"

CPacket::CPacket() : MessageBuffer(){
	readHeadered = false;
}
CPacket::CPacket(int capacity):MessageBuffer(capacity){
	readHeadered = false;
	controllerId = 1;
}
CPacket::CPacket(const char* data, int size):MessageBuffer(data,size){
	readHeadered = false;
}
CPacket::~CPacket(){
//	CCLOG("~CPacket");
	//delete[] data;
}
const char* CPacket::getData(){
	return buf;
}
void CPacket::parseHeader(){
	if(readHeadered)
		return;
	readHeadered = true;
	controllerId = getByte();
	cmdId = getShort();
	error =  getByte();
}
int CPacket::getSize(){
	return getPosition();
}
void CPacket::pack(){

}