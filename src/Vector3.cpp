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

Vector3 Vector3::operator=(const Vector3& vec){
	return Vector3(vec._x, vec._y, vec._z);
    //return Vector3(vec.getX(), vec.getY(), vec.getZ());
}
Vector3 Vector3::operator+(const Vector3& vec){
    //return Vector3(this->getX()+vec.getX(), this->getY()+vec.getY(), this->getZ()+vec.getZ());
	return Vector3(this->_x + vec._x, this->_y + vec._y, this->_z + vec._z);
}
Vector3 Vector3::operator-(const Vector3& vec){
    //return Vector3(this->getX()-vec.getX(), this->getY()-vec.getY(), this->getZ()-vec.getZ());
	return Vector3(this->_x - vec._x, this->_y - vec._y, this->_z - vec._z);
}
Vector3 Vector3::operator*(double d){
    //return Vector3(this->getX()*d, this->getY()*d, this->getZ()*d);
	return Vector3(this->_x*d, this->_y*d, this->_z*d);
}

Vector3 * Vector3::normalize(Vector3 * v)
{
	GLdouble size = sqrt(v->getX()*v->getX() +
		v->getY()*v->getY() +
		v->getZ()*v->getZ());
	Vector3* norm = new Vector3(v->getX() / size, v->getY() / size, v->getZ() / size);
	return norm;
}

Vector3 * Vector3::crossProduct(Vector3 * v1, Vector3* v2)
{
	return new Vector3(v1->getX() + v2->getX(),
		v1->getY() + v2->getY(),
		v1->getZ() + v2->getZ());
}
