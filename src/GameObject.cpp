//
//  GameObject.cpp
//  CGProj
//

#include "GameObject.h"
#include "Logger.h"


void GameObject::setParent(GameObject * gobj)
{
	_parent = gobj;
	_hasParent = true;
}

GameObject::GameObject()
{
	_hasParent = false;
    _rotangle = 0;
    _rotation.set(0, 0, 0);
    _scale.set(1, 1, 1);
    _hascollider = false;
    _collisionradius = 0;
}


GameObject::GameObject(GLdouble posx, GLdouble posy, GLdouble posz,
                       GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
                       GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Entity(posx,posy,posz)
{
    _rotangle = rotangle;
    _rotation.set(rotx, roty, rotz);
    _scale.set(scalex, scaley, scalez);
    _hascollider = false;
    _collisionradius = 0;
}

GameObject::~GameObject()
{
}

void GameObject::draw()
{
	//First apply parent transform
	//Then object transform
	applyTransform();
    if(_hascollider == true){
        glColor4f(1,0,0,0.5f);
        glutSolidSphere(_collisionradius*1.5, 8, 8);
    }
}

void GameObject::update(GLdouble delta_t)
{

}

void GameObject::addChild(GameObject * gobj)
{
	_childs.push_back(gobj);
	gobj->setParent(this);
}

void GameObject::applyTransform()
{
	if (_hasParent == true && _parent != NULL) {
		_parent->applyTransform();
	}
	glTranslated(_position.getX(), _position.getY(), _position.getZ());
	glRotated(_rotangle, _rotation.getX(), _rotation.getY(), _rotation.getZ());
	glScaled(_scale.getX(), _scale.getY(), _scale.getX());
}
