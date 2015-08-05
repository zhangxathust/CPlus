#include <iostream>
using namespace std;

typedef unsigned short int UShort;

/**
* @author zx
*/

void testPointer();

void testWildPointer();

void getAddr();

void testRef();

/**
* class defination.
*/
class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_val()
	{
		total_val = shares * share_val;
	}
public:
	Stock();
	Stock(const std::string & co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
};

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

/**
* 函数入口.
*/
int main()
{
	//cout << "Hello world!" << endl;
	//testRef();

	Stock stock1("zhang", 20, 40.0);

	return 0;
}

void testPointer()
{
	unsigned short int shortVar = 5;
	unsigned long longVar=65535;
	long sVar = -65535;

	cout << "shortVar:\t" << shortVar;
	cout << "\tAddress of shortVar:\t";
	cout << &shortVar << endl;

	cout << "longVar:\t" << longVar;
	cout << "\tAddress of longVar:\t";
	cout << &longVar << endl;

	cout << "sVar:\t\t" << sVar;
	cout << "\tAddress of sVar:\t";
	cout << &sVar << endl;
}

void testWildPointer()
{
	UShort *pInt = new UShort;
	*pInt = 10;
	cout << "*pInt: " << *pInt <<endl;
	delete pInt;
	// a stray pointer versus a null pointer.
	pInt = 0;

	long *pLong = new long;
	*pLong = 90000;
	cout << "*pLong: " << *pLong << endl;

	*pInt = 20;
	cout << "*pint: " << *pInt << endl;
	cout << "*pLong: " << *pLong << endl;
	delete pLong;
}

void getAddr()
{
	unsigned short shortVar=5;
	unsigned long longVar=65535;
	long sVar = -65535;

	cout << "shortVar:\t" << shortVar;
	cout << "\tAddress of shortVar:\t";
	cout << &shortVar << endl;

	cout << "longVar:\t" << longVar;
	cout << "\tAddress of longVar:\t";
	cout << &longVar << endl;

	cout << "sVar:\t\t" << sVar;
	cout << "\tAddress of sVar:\t";
	cout << &sVar << endl;
	cout << sizeof(int) << endl;
}

void testRef()
{
	int intOne;
	int &rSomeRef = intOne;

	intOne = 5;
	
	cout << "intOne: " << intOne << endl;
	cout << "rSomeRef: " << rSomeRef << endl;

	cout << "&intOne: " << &intOne << endl;
	cout << "&rSomeRef: " << &rSomeRef << endl;

	int intTwo = 8;
	rSomeRef = intTwo;

	cout << "\nintOne: " << intOne << endl;
	cout << "intTwo: " << intTwo << endl;
	cout << "rSomeRef: " << rSomeRef << endl;

	cout << "&intOne: " << &intOne << endl;
	cout << "&intTwo: " << &intTwo << endl;
	cout << "&rSomeRef: " << &rSomeRef << endl;

}
