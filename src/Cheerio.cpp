#include "Cheerio.h"

Cheerio::Cheerio()
{
    _hascollider = true;
    _collisionradius *= 0.2;
    _friction = 0.0000009;
}

Cheerio::Cheerio(GLdouble posx, GLdouble posy, GLdouble posz,
	GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
	GLdouble scalex, GLdouble scaley, GLdouble scalez)
	:Obstacle(posx, posy, posz,
		rotangle, rotx, roty, rotz,
		scalex, scaley, scalez)
{
	_hascollider = true;
	_collisionradius *= 0.2;
	_friction = 0.000009;
}


Cheerio::~Cheerio()
{
}

void Cheerio::render()
{
	glColor3f(1, 1, 0.4);
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidTorus(0.4, 0.9, 4, 10);
	glPopMatrix();

}

void Cheerio::collide(GameObject* obj)
{
    obj->collideWith(this);
}

void Cheerio::collideWith(Car* car)
{
	if (_speed < car->getSpeed())
		_speed = fabs(car->getSpeed()*0.9);
    _direction.set(_position.getX() - car->_position.getX(), _position.getY() - car->_position.getY(),_position.getZ() - car->_position.getZ());
    _direction.normalize2D();
}


