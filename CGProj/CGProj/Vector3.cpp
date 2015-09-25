//
//  Vector3.cpp
//  CGProj
//
//  Created by João Vicente on 25/09/15.
//  Copyright (c) 2015 João Vicente. All rights reserved.
//

#include "Vector3.h"

Vector3::Vector3(){
    Vector3(0,0,0);
}

Vector3::Vector3 (GLdouble x, GLdouble y, GLdouble z) : _x(x), _y(y), _z(z) {
}

GLdouble Vector3::getX() const{
    return _x;
}

GLdouble Vector3::getY() const{
    return _x;
}

GLdouble Vector3::getZ() const{
    return _x;
}

void Vector3::set(GLdouble x, GLdouble y, GLdouble z){
    _x = x;
    _y = y;
    _z = z;
}

Vector3 Vector3::operator=(const Vector3& vec){
    return Vector3(vec.getX(), vec.getY(), vec.getZ());
}
Vector3 Vector3::operator+(const Vector3& vec){
    return Vector3(this->getX()+vec.getX(), this->getY()+vec.getY(), this->getZ()+vec.getZ());
}
Vector3 Vector3::operator-(const Vector3& vec){
    return Vector3(this->getX()-vec.getX(), this->getY()-vec.getY(), this->getZ()-vec.getZ());
}
Vector3 Vector3::operator*(double d){
    return Vector3(this->getX()*d, this->getY()*d, this->getZ()*d);

}