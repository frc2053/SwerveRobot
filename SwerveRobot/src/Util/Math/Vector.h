#ifndef SRC_UTIL_MATH_VECTOR_H_
#define SRC_UTIL_MATH_VECTOR_H_

#include <math.h>

class Vector {
public:
	Vector(double x, double y);
	virtual ~Vector();
	double GetAngle();
	double GetMagnitude();
	double GetX();
	double GetY();
	void SetX(double x);
	void SetY(double y);
	Vector& Multiply(double scalar);
	Vector& Add(Vector& v);
	Vector& Subtract(Vector& v);
	Vector& Rotate(double radians);
private:
	double _x;
	double _y;
};

#endif
