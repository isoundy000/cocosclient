#ifndef CStringUtils_h__
#define CStringUtils_h__
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include "cocos2d.h"
#include "CocoStudio/Json/rapidjson/stringbuffer.h"
#include "CocoStudio/Json/rapidjson/writer.h"
#include "CocoStudio/Json/rapidjson/document.h"
#include <cctype>
#include <iomanip>
#include <sstream>

using namespace std;
class CStringUtils
{
public:
	//example replace(string,"$name","somename")
	static bool replace(std::string& str,const std::string& from, const std::string& to);
	static bool replace(std::string& str,const std::string& from, int to);
	static bool replaceAll(std::string& str,const std::string& from, const std::string& to);
	static bool replaceAll(std::string& str,const std::string& from, int to);
	static bool replaceAll(std::string& str,const std::string& from, long long to);
	static bool split(const std::string& str, char delim, std::vector<std::string> &elems);
	static std::map<string,int> populateMap(const std::string& str);
	bool StrToWstr(wstring &ws, const string &s );
	static string toString(int i);
	static std::string xOrString(std::string str);


	static string url_encode(const string &value);
	static string urlDecode(string &SRC);
	static void trim(string& s, const string& delimiters = " " );
	static std::string cut(string& s,int length);
	// Tim kiem chuoi thu 2 trong chuoi thu nhat
	static unsigned int findString(std::string strSrc,std::string strFind);
	static std::string toLower(std::string str);
	static std::string standartNumber(long _number);
	static std::string standartTime(int num);
	static std::string displayGold(double _gold);
	static std::string configNumber(double _number);
	//static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
	static std::vector<std::string> split(const std::string &s, char delim);
	static string json_2_string(rapidjson::Document &d);
};

#endif // StringUtils_h__
