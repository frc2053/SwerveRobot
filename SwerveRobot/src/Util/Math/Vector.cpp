#include "Vector.h"

Vector::Vector(double x, double y) {
	_x = x;
	_y = y;
}

Vector::~Vector() {

}

double Vector::GetAngle() {
	return atan2(_y, _x);
}

double Vector::GetMagnitude() {
	return hypot(_x, _y);
}

Vector Vector::Multiply(double scalar) {
	_x = _x * scalar;
	_y = _y * scalar;
	return *this;
}

Vector Vector::Add(Vector v) {
	_x = _x + v._x;
	_y = _y + v._y;
	return *this;
}

Vector Vector::Subtract(Vector v) {
	_x = _x - v._x;
	_y = _y - v._y;
	return *this;
}

Vector Vector::Rotate(double radians) {
	double tempX = _x;
	_x = _x * cos(radians) - _y * sin(radians);
	_y = tempX * sin(radians) + _y * cos(radians);
	return *this;
}
