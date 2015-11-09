//
//  Orange.cpp
//  CGProj
//

#include "Orange.h"
#include "Logger.h"

/*FIXME glutTimerFunc */

GLboolean Orange::checkOutOfBounds()
{
	GLdouble x = getPosition()._x, z = getPosition()._z;
	if (x > 75 || x < -75 || z > 50 || z < -50)
		return true;
	return false;
}

void Orange::setOrangeRespawnCallback()
{
	glutTimerFunc(RESPAWN_TIME, Orange::orangeRespawnCallback, (int)(size_t)this);
}

void Orange::setOrangeSpeedCallback()
{
	glutTimerFunc(SPEED_UP_INTERVAL, Orange::orangeSpeedCallback, (int)(size_t)this);
}
	
Orange::Orange()
{
	Orange(0, 0, 0);
    _hascollider = true;
    _collisionradius *= 1.1;

}


Orange::Orange(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Obstacle(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{

	_direction = Vector3(2*((double)(std::rand()) / RAND_MAX)-1, 0, 2 * ((double)(std::rand()) / RAND_MAX) - 1);
	_direction.normalize();
	_speedModifier = 1;
	_speed = ((double)std::rand() / RAND_MAX)*0.010+0.005;
	_baseSpeed = _speed;
	setOrangeSpeedCallback();
    _hascollider = true;
    _collisionradius *= 1.1;
}


Orange::~Orange()
{
}

void Orange::render()
{
	glPushMatrix();
	 glTranslatef(0,0.2, 0);
     glScalef(2, 2, 2);
    
	 //corpo	
     glPushMatrix();
	  _material.defineMaterial(_amb, _diff, _spec, _shine);
	  glColor3f(0.85f, 0.53f, 0.1f);
	  glutSolidSphere(1, 16, 16);
	 glPopMatrix();

	 //pe da laranja
	 glPushMatrix();
	 _material.defineMaterial(_ambpe, _diffpe, _specpe, _shinepe);
	  glColor3f(0.2f,0.0f,0.0f);
	  glTranslatef(0.5f, 0.8f, 0.0f);
	  glRotatef(-30, 0, 0, 1);
	  glScalef(0.15, 0.7f, 0.15);
	  glutSolidCube(1);

	 glPopMatrix();
	 
	glPopMatrix();

}

void Orange::update(GLdouble delta_t)
{
	_speed = _speedModifier*_baseSpeed;
	//setPosition(_position._x + _speedModifier*_speed*delta_t*_direction._x , _position._y,
		//_position._z + _speedModifier*_speed*delta_t*_direction._z);
	DynamicObject::move(delta_t);

	_rotation.set(_direction._z, _direction._y,- _direction._x);
	_rotangle += delta_t*50*_speed;

	if (checkOutOfBounds() == true) {
		_draw = false;
		setOrangeRespawnCallback();
		setPosition(0, 0, 0);
    }
}

void Orange::collide(GameObject* obj)
{
    obj->collideWith(this);
}

void Orange::respawn()
{
    setPosition((std::rand() % (60 - 0 + 1)) - 30, _position._y, (std::rand() % (60 - 0 + 1)) - 30);
	_direction = Vector3(2 * ((double)(std::rand()) / RAND_MAX) - 1, 0, 2 * ((double)(std::rand()) / RAND_MAX) - 1);
	_direction.normalize();
	_baseSpeed = ((double)std::rand() / RAND_MAX)*0.010 + 0.005;
	_draw = true;
}

void Orange::increaseSpeed()
{
	_speedModifier++;
	Logger::printf("Speed increase!");
}

void Orange::resetSpeed() {	
	_speedModifier = 1;
}
void Orange::orangeRespawnCallback(int obj)
{
	Orange* o = (Orange*)obj;
	o->respawn();
}

void Orange::orangeSpeedCallback(int obj)
{
	Orange* o = (Orange*)obj;
	o->increaseSpeed();
	o->setOrangeSpeedCallback();
}

void Orange::collideWith(Car* obj)
{
    GameManager::getCurrentInstance()->GGWP();
}

void Orange::reset()
{
	respawn();
	resetSpeed();
}

