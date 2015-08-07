#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

/**
* class defination
*/
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {RECT, POLAR};
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;

		void set_x();
		void set_y();
		void set_mag();
		void set_ang();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();
		void reset(double n1, double n2, Mode form = RECT);
		
		double xval() const
		{
			return x;
		}
		double yval() const
		{
			return y;
		}
		double magval() const
		{
			return mag;
		}
		double angval() const
		{
			return ang;
		}
		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector & v) const;
		Vector operator-(const Vector & v) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		
		// friend method.
		friend Vector operator*(double n, const Vector & v);
		//an method override "<<" ,it is like java.lang.Object.toString().
		friend std::ostream & operator<<(std::ostream & os, const Vector & t);
	};
}

#endif