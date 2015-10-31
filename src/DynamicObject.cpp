//
//  DynamicObject.cpp
//  CGProj
//

#include "DynamicObject.h"
#include "Logger.h"

DynamicObject::DynamicObject()
{
    _speed = 0;
}
DynamicObject::DynamicObject(GLdouble posx, GLdouble posy, GLdouble posz,
                   GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
                   GLdouble scalex, GLdouble scaley, GLdouble scalez)
:GameObject(posx, posy, posz,
               rotangle, rotx, roty, rotz,
               scalex, scaley, scalez)
{
    _direction.set(cos((rotangle*3.14)/180),0, sin((rotangle*3.14)/180));
    _speed = 0;
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::update(GLdouble delta_t)
{

}

void DynamicObject::setSpeed(GLdouble speed)
{
}

GLdouble DynamicObject::getSpeed()
{
    return _speed;
}

void DynamicObject::setDirection(GLdouble x, GLdouble y, GLdouble z)
{
}

Vector3 DynamicObject::getDirection()
{
	return _direction;
}
void DynamicObject::reset()
{
	_speed = 0;
	GameObject::reset();
}


