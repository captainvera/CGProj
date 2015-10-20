//
//  DynamicObject.cpp
//  CGProj
//

#include "DynamicObject.h"
#include "Logger.h"

DynamicObject::DynamicObject()
{
}
DynamicObject::DynamicObject(GLdouble posx, GLdouble posy, GLdouble posz,
                   GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
                   GLdouble scalex, GLdouble scaley, GLdouble scalez)
:GameObject(posx, posy, posz,
               rotangle, rotx, roty, rotz,
               scalex, scaley, scalez)
{
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

void DynamicObject::setDirection(GLdouble x, GLdouble y, GLdouble z)
{
}

Vector3 DynamicObject::getDirection()
{
	return _direction;
}
