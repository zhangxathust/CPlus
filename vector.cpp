#include <iostream>
#include <cmath>
#include "vector.h"


using namespace std;	

namespace VECTOR
{
	const double Rad_to_Deg = 45.0 / atan(1.0);	//坐标转换

	void Vector::set_x()
	{
		x = mag * sin(ang);
	}

	void Vector::set_y()
	{
		x = mag * cos(ang);
	}

	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if(x == 0.0 && y == 0.0)
		{
			ang = 0.0;
		}
		else
		{
			ang = atan2(y, x);
		}
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form/* = RECT*/)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POLAR)
		{
			mag = n1;
			ang = n2 / Rad_to_Deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "incorrect 3rd argument to Vector()--" << "Vector set to 0" << endl;
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{

	}

	void Vector::reset(double n1, double n2, Mode form/* = RECT*/)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POLAR)
		{
			mag = n1;
			ang = n2 / Rad_to_Deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "incorrect 3rd argument to Vector()--" << "Vector set to 0" << endl;
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::polar_mode()
	{
		mode = POLAR;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector & v) const
	{
		return Vector(x + v.x, y + v.y);
	}

	Vector Vector::operator-(const Vector & v) const
	{
		return Vector(x - v.x, y - v.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(x * n, y * n);
	}

	// friend method.
	Vector operator*(double n, const Vector & v)
	{
		return v * n;
	}
	//display Vector.
	std::ostream & operator<<(std::ostream & os, const Vector & t)
	{
		if(t.mode == Vector::RECT)
		{
			os << "(x, y) = (" << t.x << ", " << t.y << ")";
		}
		else if (t.mode == Vector::POLAR)
		{
			os << "(mag, ang) = (" << t.mag << ", " << t.ang << ")";
		}
		else
		{
			os << "Vector object mode is invalid.";
		}
		return os;
	}

}