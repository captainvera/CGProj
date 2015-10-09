//
//  GameObject.cpp
//  CGProj
//

#include "GameObject.h"
#include "Logger.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::draw()
{
	glTranslated(_position._x,_position._y,_position._z);
}

void GameObject::update(GLdouble delta_t)
{
}
