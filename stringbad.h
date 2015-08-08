#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>

/**
* class defination show dynamic heap allocate.
*/
class StringBad
{
private:
	char * str;
	int len;
	static int string_num;
public:
	StringBad(const char * s);
	StringBad();
	~StringBad();

	friend std::ostream & operator<<(std::ostream & os, const StringBad & s);
};

#endif