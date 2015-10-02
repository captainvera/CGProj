//
//  Vector3.cpp
//  CGProj
//

#include "Vector3.h"

Vector3::Vector3(){
    Vector3(0,0,0);
}

Vector3::Vector3 (GLdouble x, GLdouble y, GLdouble z) : _x(x), _y(y), _z(z) {
}

Vector3::~Vector3(){
}

GLdouble Vector3::getX() {
    return _x;
}

GLdouble Vector3::getY() {
	return _y;
}

GLdouble Vector3::getZ() {
	return _z;
}

void Vector3::set(GLdouble x, GLdouble y, GLdouble z){
    _x = x;
    _y = y;
    _z = z;
}

Vector3& Vector3::operator=(const Vector3& vec){
	this->set(vec._x, vec._y, vec._z);
	return *this;
}
Vector3& Vector3::operator+(const Vector3& vec){
	this->set(_x + vec._x, _y + vec._y, _z + vec._z);
	return *this;
}
Vector3& Vector3::operator-(const Vector3& vec){
	this->set(_x - vec._x, _y - vec._y, _z - vec._z);
	return *this;
}
Vector3& Vector3::operator*(double d){
	this->set(_x*d, _y*d, _z*d);
	return *this;
}

void Vector3::normalize(Vector3& v)
{
	GLdouble size = sqrt(v._x*v._x +
		v._y*v._y +
		v._z*v._z);
	v.set(v._x / size, v._y / size, v._z / size);
}


void Vector3::crossProduct(Vector3& v1, Vector3& v2, Vector3& res)
{
	res.set(v1._y*v2._z - v1._z*v2._y,
		v1._z*v2._x - v1._x*v2._z,
		v1._x*v2._y - v1._y*v2._x);
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
	os << "< " << v._x << " , " << v._y << " , " << v._z << " >";
	return os;
}