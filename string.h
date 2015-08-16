#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>

/**
* class defination show dynamic heap allocate.
*/
class String
{
private:
	char * str;
	int len;
	static int string_num;
	static const int CINLIM = 80;

public:
	String(const char * s);
	String();
	String(const String &);
	~String();

	int length() const
	{
		return len;
	}

	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;

	friend bool operator<(const String & st1, const String & st2);
	friend bool operator>(const String & st1, const String & st2);
	friend bool operator==(const String & st1, const String & st2);

	friend std::istream & operator>>(std::istream & is, String & st);
	friend std::ostream & operator<<(std::ostream & os, const String & s);

	static int howMany();
};

#endif