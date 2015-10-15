//
//  Entity.cpp
//  CGProj
//

#include "Entity.h"

Entity::Entity() {
	_position.set(0, 0, 0);
}

Entity::Entity(GLdouble posx, GLdouble posy, GLdouble posz){
	    _position.set(posx, posy, posz);
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