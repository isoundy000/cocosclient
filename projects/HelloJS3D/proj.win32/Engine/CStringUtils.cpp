#include "CStringUtils.h"
#include <stdlib.h>
USING_NS_CC;
bool CStringUtils::replace(std::string& str,const std::string& from, const std::string& to){
	if(from.empty())
		return false;
	size_t start_pos = str.find(from);
	if(start_pos == std::string::npos)
		return false;
	str.replace(start_pos,from.length(),to);
	return true;
}
bool CStringUtils::replace(std::string& str,const std::string& from, int to){
	char s_to[12];
	sprintf(s_to, "%d",to);
	return replace(str,from,s_to);
}
bool CStringUtils::replaceAll(std::string& str,const std::string& from, const std::string& to){
	if(from.empty())
		return false;
	size_t start_pos = 0;
	while((start_pos = str.find(from,start_pos))!= std::string::npos){
		str.replace(start_pos,from.length(),to);
		start_pos +=to.length();
	}
}
bool CStringUtils::replaceAll(std::string& str,const std::string& from, int to){
	char s_to[12];
    sprintf(s_to, "%d",to);
	return replaceAll(str,from,string(s_to));
}
bool CStringUtils::replaceAll(std::string& str,const std::string& from, long long to){
	char s_to[30];
    sprintf(s_to, "%",to);
	return replaceAll(str,from,string(s_to));
}

bool CStringUtils::StrToWstr(wstring &ws, const string &s ){
	std::wstring wsTmp(s.begin(),s.end());
	ws = wsTmp;
	return true;
}

bool CStringUtils::split(const std::string& str, char delim, std::vector<std::string>& elems)
{
	if (str.length() <= 1) return false;
	std::stringstream ss(str);
	std::string item;
	while(std::getline(ss, item, delim)){
		elems.push_back(item);
	}
	return true;
}

std::map<string,int> CStringUtils::populateMap(const std::string& str)
{
	std::map<string,int> returnMap;
	vector<string> tokens;
	string key;
	int value;

	CStringUtils::split(str, ';', tokens);
	for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		vector<string> innerToks;
		CStringUtils::split(*it, ':', innerToks);
		key = innerToks[0];
		value = atoi(innerToks[1].c_str());
		returnMap.insert(std::pair<string,int>(key, value));
	}
	return returnMap;
}

string CStringUtils::toString(int i){
	char s_to[12];
	sprintf(s_to, "%d",i);
	return string(s_to);
}
std::string CStringUtils::xOrString(std::string str)
{
	int length = strlen(str.c_str());
	if(length ==0)
		return str;
	
	string key = "adstrtr";
	string buf = "";
	int keySize = 7;
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		buf += str[i]^key[j];
		j++;
		if (j==keySize)
		{
			j = 0;
		}

	}
	return string(buf);
}

std::string CStringUtils::url_encode(const string &value) {
	ostringstream escaped;
	escaped.fill('0');
	escaped << hex;

	for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
		string::value_type c = (*i);

		// Keep alphanumeric and other accepted characters intact
		if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
			escaped << c;
			continue;
		}

		// Any other characters are percent-encoded
		escaped << '%' << setw(2) << int((unsigned char) c);
	}

	return escaped.str();
}

std::string CStringUtils::urlDecode(string &SRC) {
	string ret;
	char ch;
	int i, ii;
	for (i=0; i<SRC.length(); i++) {
		if (int(SRC[i])==37) {
			sscanf(SRC.substr(i+1,2).c_str(), "%x", &ii);
			ch=static_cast<char>(ii);
			ret+=ch;
			i=i+2;
		} else {
			ret+=SRC[i];
		}
	}
	return (ret);
}

void CStringUtils::trim(string& s, const string& delimiters)
{
	s.erase( s.find_last_not_of( delimiters ) + 1 ).erase( 0, s.erase( s.find_last_not_of( delimiters ) + 1 ).find_first_not_of( delimiters ) );
}

std::string CStringUtils::cut(string& s,int length)
{
	if (s.length() > length)
	{
		if (s.length() <= length +2)
		{
			return s;
		}
		int count = length;
		for (int i = length;i>=0;i++)
		{
			int tmp = s.at(i);
			if (tmp >= 0 && tmp < 128)
			{
				count = i;
				break;
			}
		}
		std::string str = s.substr(0,count);
		str.append("...");
		return str;
	}
	return s;
}

// Tim kiem chuoi thu 2 trong chuoi thu nhat
unsigned int CStringUtils::findString(std::string strSrc,std::string strFind)
{
	size_t found = strSrc.find(strFind);
	if (found != string::npos)
	{
		return found;
	}
	return -1;
}

std::string CStringUtils::toLower(std::string str)
{
	std::string result;
	result.resize(str.size());
	std::transform(str.begin(),str.end(),result.begin(),::tolower);
	return result;
}

std::string CStringUtils::standartNumber(long _number)
{
	vector<std::string> listStr;
	long number = _number;
	while ((number/1000) != 0)
	{
		int b = number%1000;
		listStr.push_back(CCString::createWithFormat("%3.3d",b)->getCString());
		number /= 1000;
	}
	std::string result = CCString::createWithFormat("%d",(int)number)->getCString();
	if (listStr.size() != 0)
	{
		for (int i = listStr.size()-1;i>=0;i--)
		{
			result.append(".");
			result.append(listStr.at(i));
		}
	}
	return result;
}

std::string CStringUtils::standartTime(int num)
{
	if(num < 10)
		return "0" + toString(num);
	else
		return toString(num);
}

std::string CStringUtils::displayGold(double _gold)
{
	double saveGold = _gold;
	_gold = fabs(_gold);
	int ti = (int)(_gold/1000000000);
	if(ti == 0)
	{
		long lG = (long)_gold;
		int trieu = lG/1000000;
		if (trieu == 0)
		{
			int nghin = lG/1000;
			std::string gold = CCString::createWithFormat("%d",nghin)->getCString();
			int tram = lG%1000;
			if (tram != 0)
			{
				tram = tram / 10;
				if (tram != 0)
				{
					gold.append(".");
					gold.append(CCString::createWithFormat("%2.2d",tram)->getCString());
				}
			}
			gold.append("K");
			if(saveGold < 0)
				return "-" + gold;
			else
			{
				return gold;
			}
		}
		else
		{
			std::string gold = CCString::createWithFormat("%d",trieu)->getCString();
			int nghin = (lG%1000000)/1000;
			nghin /= 10;
			gold.append(".");
			gold.append(CCString::createWithFormat("%2.2d",nghin)->getCString());
			gold.append("M");
			if(saveGold < 0)
				return "-" + gold;
			else
			{
				return gold;
			}
		}
	}
	else
	{
		double a = 1000000000;
		long phandu = _gold - a * ti;
		std::string gold = CCString::createWithFormat("%d",ti)->getCString();
		int trieu = (phandu%1000000000)/1000000;
		trieu /= 10;
		gold.append(".");
		gold.append(CCString::createWithFormat("%2.2d",trieu)->getCString());
		gold.append("B");
		if(saveGold < 0)
			return "-" + gold;
		else
		{
			return gold;
		}
	}

}

std::string CStringUtils::configNumber(double _number)
{
	double save = _number;
	_number = fabs(_number);
	std::string result;
	if (_number <= 0)
	{
		result = "0";
		return result;
	}
	vector<std::string> listStr;
	double number = _number;
	while (floor(number/1000) != 0)
	{
		double tiso = floor(number/1000);
		double a = 1000;
		int b = number - tiso * a;
		listStr.push_back(CCString::createWithFormat("%3.3d",b)->getCString());
		number /= 1000;
		//number = floor(number);
	}

	if (floor(number) > 0)
	{
		int c = floor(number);
		result = CCString::createWithFormat("%d",c)->getCString();
	}

	if (listStr.size() != 0)
	{
		for (int i = listStr.size()-1;i>=0;i--)
		{
			result.append(".");
			result.append(listStr.at(i));
		}
	}
	if(save < 0)
		result = "-" + result;
	return result;
}

std::vector<std::string> CStringUtils::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}


string CStringUtils::json_2_string(rapidjson::Document &d)
{
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	d.Accept(writer);
	return buffer.GetString();
}