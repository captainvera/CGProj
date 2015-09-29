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
	Logger::printf("draw GameObject");
}

void GameObject::update(GLdouble delta_t)
{
}
