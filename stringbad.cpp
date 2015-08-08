#include <cstring>
#include "stringbad.h"

/**
* bug exists.
*/
using std::cout;
using std::endl;

int StringBad::string_num = 0;

StringBad::StringBad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	string_num++;
	cout << string_num << " : \"" << str << "\" object created." << endl;
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "c++");
	string_num ++;
	cout << string_num << " : \"" << str << "\" object created." << endl;
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" object deleted, ";
	--string_num;
	cout << string_num << " lefted" << endl;
	// delete operation.
	delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & s)
{
	os << s.str;
	return os;
}