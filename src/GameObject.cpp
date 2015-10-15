//
//  GameObject.cpp
//  CGProj
//

#include "GameObject.h"
#include "Logger.h"

GameObject::GameObject()
{
    _rotangle = 0;
    _rotation.set(0, 0, 0);
    _scale.set(1, 1, 1);
}


GameObject::GameObject(GLdouble posx, GLdouble posy, GLdouble posz,
                       GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
                       GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Entity(posx,posy,posz)
{
    
    _rotangle = rotangle;
    _rotation.set(rotx, roty, rotz);
    _scale.set(scalex, scaley, scalez);
}

GameObject::~GameObject()
{
}

void GameObject::draw()
{

	glTranslated(_position.getX(),_position.getY(),_position.getZ());
    glRotated(_rotangle, _rotation.getX(), _rotation.getY(), _rotation.getZ());
    glScaled(_scale.getX(), _scale.getY(), _scale.getX());
}

void GameObject::update(GLdouble delta_t)
{
}
