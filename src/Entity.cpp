//
//  Entity.cpp
//  CGProj
//

#include "Entity.h"

Entity::Entity() {
	_position.set(0, 0, 0);
	_rotation.set(0, 0, 0);
	_scale.set(0, 0, 0);
	_rotangle = 0;
	printf("%f, %f, %f", _position.getX(), _position.getY(), _position.getZ());
}

Entity::Entity(float posx, float posy, float posz, float rotangle=0, float rotx = 0, float roty = 0, float rotz = 0, float scalex = 1, float scaley = 1, float scalez = 0){
	printf("%f, %f, %f", _position.getX(), _position.getY(), _position.getZ());
    _position.set(posx, posy, posz);
	_rotation.set(rotx, roty, rotz);
	_scale.set(scalex, scaley, scalez);
	_rotangle = rotangle;
}

Entity::~Entity(){
}

Vector3& Entity::getPosition(){
    return _position;
}

void Entity::setPosition(GLdouble x, GLdouble y, GLdouble z){
	_position.set(x, y, z);
}

void Entity::setPosition(Vector3& vec){
    _position = vec;
}