#ifndef _UTILITY_H_
#define _UTILITY_H_
#include <string>
#include <vector>
#include "cocos2d.h"
using namespace std;
class Utility
{
public:
	Utility(void);
	~Utility(void);
	string pointNumber(long);
	string convertIntLongToString(long num);
	string getNameImageByTypeItem(string type);
	int randomBetween(int,int);
	string convertToStringTime(long t);
	string convertToStringTime2(int t);
	static void xOrData(unsigned char *data, int len);
	static cocos2d::CCTexture2D* createTexture(const char *pszFileName);
	string replaceString(string rootStr,string strReplace,string strTo);
	bool checkMaintain();
	bool parseMaintain(string data);
	static string getDate(double time);
};

#endif
