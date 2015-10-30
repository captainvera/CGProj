//
//  GameObject.cpp
//  CGProj
//

/*FIXME handle default collide comment*/

#include "GameObject.h"
#include "Logger.h"
#include "GameManager.h"


void GameObject::setParent(GameObject * gobj)
{
	_parent = gobj;
	_hasParent = true;
}

GameObject::GameObject()
{
	_hasParent = false;
    _rotangle = 0;
    _initRotangle = _rotangle;
    _rotation.set(0, 0, 0);
    _initRotation = _rotation;
    _scale.set(1, 1, 1);
	_draw = true;
    _initScale = _scale;
    _hascollider = false;
    _collisionradius = 1;
    
}


GameObject::GameObject(GLdouble posx, GLdouble posy, GLdouble posz,
                       GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
                       GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Entity(posx,posy,posz)
{
    _rotangle = rotangle;
    _initRotangle = _rotangle;
    _rotation.set(rotx, roty, rotz);
    _initRotation = _rotation;
    _scale.set(scalex, scaley, scalez);
    _initScale = _scale;
    _hascollider = false;
    _draw = true;
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
	if (_draw) {
		applyTransform();
		if (_hascollider == true && GameManager::getCurrentInstance()->wireframe()) {
			glColor4f(1, 0, 0, 0.5f);
			glutSolidSphere(_collisionradius*1.5, 8, 8);
		}
		render();
	}
}

void GameObject::render()
{
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

void GameObject::reset()
{
    Entity::reset();
    _rotangle = _initRotangle;
    _rotation = _initRotation;
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

void GameObject::collideWith(Car * obj)
{
}
