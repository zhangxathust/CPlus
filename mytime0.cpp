#include <iostream>
#include "mytime0.h"

using namespace std;

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m/* = 0*/)
{
	hours = h;
	minutes = m;
}

void Time::addMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::addHour(int h)
{
	hours += h;
}

void Time::reset(int h/* = 0*/, int m/* = 0*/)
{
	hours = h;
	minutes = m;
}

Time Time::sum(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time & t) const
{
	Time minus;
	if (minutes < t.minutes)
	{
		minus.hours = hours - t.hours -1;
		minus.minutes = 60 + minutes - t.minutes;
	}
	else
	{
		minus.hours = hours - t.hours;
		minus.minutes = minutes - t.minutes;
	}
	return minus;
}

Time Time::operator*(double n) const
{
	Time multiply;
	multiply.minutes = n * minutes;
	multiply.hours = n * hours + multiply.minutes / 60;
	multiply.minutes %= 60;
	return multiply;
}

void Time::show() const
{
	cout << hours << " hours, " << minutes << " minutes!";
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << "hours: " << t.hours << " minutes: " << t.minutes;
	return os;
}