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

double Vector::GetX() {
	return _x;
}

double Vector::GetY() {
	return _y;
}

void Vector::SetX(double x) {
	_x = x;
}

void Vector::SetY(double y) {
	_y = y;
}

Vector& Vector::Multiply(double scalar) {
	_x = _x * scalar;
	_y = _y * scalar;
	return *this;
}

Vector& Vector::Add(Vector& v) {
	_x = _x + v.GetX();
	_y = _y + v.GetY();
	return *this;
}

Vector& Vector::Subtract(Vector& v) {
	_x = _x - v.GetX();
	_y = _y - v.GetY();
	return *this;
}

Vector& Vector::Rotate(double radians) {
	_x = _x * cos(radians) - _y * sin(radians);
	_y = _x * sin(radians) + _y * cos(radians);
	return *this;
}
