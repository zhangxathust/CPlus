#include <iostream>
#include "stringbad.h"
#include "vegnews.h"

using std::cout;

void testStringBad()
{
	using std::endl;
	{
		StringBad headline1("Celery stalks at midnight");
		StringBad headline2("Lettuce prey");
		StringBad sports("Spinach leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl << endl;
		cout << "initialize one object to another:\n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		cout << "assign one object to another:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "existing the block.\n";
	}
	cout << "end of main()" << endl;
}

void callme1(StringBad & rsb)
{
	cout << "string passed by reference.\n";
	cout << "    \"" << rsb << "\"  ";
}

void callme2(StringBad sb)
{
	cout << "string passed by value.\n";
	cout << "    \"" << sb << "\"  ";
}