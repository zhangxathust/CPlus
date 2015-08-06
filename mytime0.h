#ifndef MYTIME0_H_
#define MYTIME0_H_

/**
* class defination
*/
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void addMin(int m);
	void addHour(int h);
	void reset(int h = 0, int m = 0);
	Time sum(const Time & t) const;
	// override operator + - *
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(double n) const;	//this only useful to time * n
	// friend method. used to n * time. it is also an inline method.
	friend Time operator*(double n, const Time & t)
	{
		// call method operator*(double n).
		return t * n;
	}

	void show() const;
	//an method override "<<" ,it is like java.lang.Object.toString().
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif