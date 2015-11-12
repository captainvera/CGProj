#include "Candle.h"

Candle::Candle()
{
	Candle(0, 0, 0);
}

Candle::Candle(GLdouble posx, GLdouble posy, GLdouble posz)
	: GameObject(posx, posy, posz)
{
	_light = GameManager::getCurrentInstance()->createPointLight();
	_light->setPosition(_position._x, _position._y+5,_position._z);
	_light->setAttenuation(0.0, 0.005, 0.0016);
	_light->setDiffuse(0.3, 0.3, 0.3, 1.0);
	_light->setAmbient(0.0, 0.0, 0.0, 1.0);
	_light->setSpecular(0.3, 0.3, 0.3, 1.0);
	_light->setState(true);
	_light_state = true;
	addLight(_light);
}

Candle::~Candle()
{
}

void Candle::render()
{
	glPushMatrix();
	glColor3f(0.3, 0.08, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidTorus(0.4, 0.9, 4, 10);
	glColor3f(0.15, 0.15, 0.15);
	glutSolidCone(2.0, 3.0, 4, 4);
	glScalef(1.0, 1.0, 8.0);
	glTranslatef(0.0,0.0,-0.5);
	glutSolidCube(1.0);
	glPopMatrix();
}

void Candle::toggleLight()
{
	if (_light_state)
		_light->setState(false);
	else
		_light->setState(true);
	_light_state = !_light_state;
}



