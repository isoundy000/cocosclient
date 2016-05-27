#pragma once

#include <vector>
using namespace std;

#define MAX_BUFFER 100240
class BZPacket
{
public:
	BZPacket()
	{
		size = 0;
	}
	~BZPacket()
	{
	}
	vector <char> vectorBuffer;
	unsigned int size;
	void append(vector <char> data, int dataSize){
		vectorBuffer.insert(vectorBuffer.end(), data.begin(), data.end());
	}
	bool split(BZPacket &packet){
		// Check for complete data
		if(vectorBuffer.size() < packet.size)
			return false;

		// Get full data from buffer
		packet.vectorBuffer.insert(packet.vectorBuffer.begin(), vectorBuffer.begin(), vectorBuffer.begin() + packet.size);

		// Erase read data from buffer
		vectorBuffer.erase(vectorBuffer.begin(), vectorBuffer.begin()+packet.size);

		return true;
	}
};