//
//  GameObject.cpp
//  CGProj
//

/*FIXME handle default collide comment*/

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
    _collisionradius = 1;
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
	if (scalex > scaley) {
		if (scalex > scalez)
			_collisionradius = scalex;
		else _collisionradius = scalez;
	}
	else if (scaley > scalez) {
		_collisionradius = scaley;
	}
	else if (scalez > scaley)
		_collisionradius = scalez;
	else _collisionradius = scalex;

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

void GameObject::collide(GameObject* obj) 
{
	//Logger::printf("DEBUG: BOOP BOOP BOOP Something is very wrong in the GameObject, it seems to want to collide with someone, wonder how that happened! (Yes, this is the default collider)\n");
}

void GameObject::collideWith(GameObject* obj) 
{
}

void GameObject::collideWith(Butter * obj)
{
}

void GameObject::collideWith(Orange * obj)
{
}

void GameObject::collideWith(Cheerio * obj)
{
}
