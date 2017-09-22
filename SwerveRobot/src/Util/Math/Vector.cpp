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
	return Vector(_x * scalar, _y * scalar);
}

Vector Vector::Add(Vector v) {
	return Vector(_x + v._x, _y + v._y);
}

Vector Vector::Subtract(Vector v) {
	return Vector(_x - v._x, _y - v._y);
}

Vector Vector::Rotate(double radians) {
	return Vector(_x * cos(radians) - _y * sin(radians), _x * sin(radians) + _y * cos(radians));
}
