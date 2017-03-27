#ifndef SRC_UTIL_MATH_VECTOR_H_
#define SRC_UTIL_MATH_VECTOR_H_

class Vector {
public:
	Vector(double x, double y);
	virtual ~Vector();
	double GetAngle();
	double GetMagnitude();
	Vector Multiply(double scalar);
	Vector Add(Vector v);
	Vector Subtract(Vector v);
	Vector Rotate(double radians);
	double _x;
	double _y;
};

#endif
