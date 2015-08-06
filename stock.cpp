#include <iostream>
#include "stock.h"

using namespace std;


/**
* class methods realization.
*/

Stock::Stock()
{
	cout << "default constructor is called." << endl;
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
	cout << "constructor " << co << " is called." << endl;
	company = co;
	if(n < 0)
	{
		cout << "shares should not be negative." << endl;
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_val();
}

Stock::~Stock()
{
	cout << "bye: " << company << endl;
}

void Stock::buy(long num, double price)
{
	//TODO
	if (num < 0)
	{
		cout << "num of shares purchase cannot be negative." << "Transaction is aborted." << endl;
	}
	else
	{
		shares += num;
		share_val = price;
		set_val();
	}
}
void Stock::sell(long num, double price)
{
	//TODO
	if (num < 0)
	{
		cout << "num of shares sell cannot be negative." << "Transaction is aborted." << endl;
	}
	else if(num > shares)
	{
		cout << "num of shares sell cannot be over than shares." << "Transaction is aborted." << endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_val();
	}
}

void Stock::update(double price)
{
	//TODO
	share_val = price;
	set_val();
}

// this method should not change the object itself. so const is used like this.
void Stock::show() const
{
	//TODO
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	// set #.###
	streamsize prec = cout.precision(3);

	cout << "company: " << company << " | shares: " << shares << endl;
	cout << " share_price: " << share_val;
	cout.precision(2);
	cout << " total_shares: " << total_val << endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}