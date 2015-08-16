#include "string.h"
#include <iostream>

using namespace std;

// initialize class variable
int String::string_num = 0;

int String::howMany()
{
	return string_num;
}

String::String(const char * s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	string_num++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	string_num++;
}

String::String(const String & st)
{
	string_num++;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
}

String::~String()
{
	--string_num;
	delete [] str;
}

String & String::operator=(const String & st)
{
	if(this == &st)
	{
		return *this;
	}
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char * s)
{
	delete [] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const
{
	return str[i];
}

// 友元函数
bool operator<(const String & st1, const String & st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

// 
std::istream & operator>>(std::istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if(is)
	{
		st = temp;
	}
	while(is && is.get()!='\n')
	{
		continue;
	}
	return is;
}

std::ostream & operator<<(std::ostream & os, const String & s)
{
	os << s.str;
	return os;
}