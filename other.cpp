#include <iostream>
#include "other.h"

#include "vector.h"
#include <cstdlib>
#include <ctime>

#include <cmath>

using namespace std;

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

void testMathMethod()
{
	// 三角函数用的是PI来进行计算，atan(1.0) = PI / 4 = 45度
	cout << sqrt(2) << endl;
	cout << sin(PI / 6) << endl;

	cout << atan(1.0) * 4 / PI << endl;
}

void testVector()
{
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	double dstep;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;

	cout << "enter target distance (q to quit)";

	while(cin >> target)
	{
		cout << "enter step length:";
		
		if(!(cin >> dstep))
		{
			break;
		}

		while(result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POLAR);
			result = result + step;
			steps ++;
		}

		cout << "after " << steps << " steps, the subject has the following location:" << result << endl;
		result.polar_mode();
		cout << "or, the following location is " << result << endl;
		cout << "average outward distance per step = " << result.magval() / steps << endl;
		// reset job.
		steps = 0;
		result.reset(0.0, 0.0);

		cout << "enter target distance (q to quit)";
	}
	cout << "Bye." << endl;
	cin.clear();
	while(cin.get() != '\n')
	{
		continue;
	}
}
