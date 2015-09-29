//
//  Entity.cpp
//  CGProj
//

#include "Entity.h"

Entity::Entity(){
    _position = Vector3(0,0,0);
}

Entity::~Entity(){
}

Vector3* Entity::getPosition(){
    return &_position;
}

void Entity::setPosition(GLdouble x, GLdouble y, GLdouble z){
    _position = Vector3(x, y, z);
}

void Entity::setPosition(const Vector3& vec){
    _position = vec;
}