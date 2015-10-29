//
//  Entity.cpp
//  CGProj
//

#include "Entity.h"

Entity::Entity() {
	_position.set(0, 0, 0);
    _initPosition = _position;
}

Entity::Entity(GLdouble posx, GLdouble posy, GLdouble posz)
{
	_position.set(posx, posy, posz);
    _initPosition = _position;
}

Entity::~Entity(){
}

Vector3& Entity::getPosition(){
    return _position;
}

void Entity::setPosition(GLdouble x, GLdouble y, GLdouble z)
{
	_position.set(x, y, z);
}

void Entity::setPosition(Vector3& vec)
{
    _position = vec;
}

void Entity::reset()
{
    std::cout << "Reset\n";
    _position = _initPosition;
}