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
	glTranslated(getPosition()->getX(),getPosition()->getY(),getPosition()->getZ());
}

void GameObject::update(GLdouble delta_t)
{
}
