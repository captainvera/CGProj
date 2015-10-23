//
//  Orange.cpp
//  CGProj
//

#include "Orange.h"

GLboolean Orange::checkOutOfBounds()
{
	GLdouble x = getPosition()._x, z = getPosition()._z;
	if (x > 75 || x < -75 || z > 75 || z < -75)
		return true;
	return false;
}

Orange::Orange()
{
	Orange(0, 0, 0);
    _hascolider = true;
    _colisionradius = 1.1;
}

Orange::Orange(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Obstacle(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{

	_direction = Vector3(2*((double)(std::rand()) / RAND_MAX)-1, 0, 2 * ((double)(std::rand()) / RAND_MAX) - 1);
	Vector3::normalize(_direction);
	_time = 0;
	_speedModifier = 1;
	_speed = 0.015;
    _hascolider = true;
    _colisionradius = 1.1;
}


Orange::~Orange()
{
}

void Orange::draw()
{
    GameObject::draw();
	glPushMatrix();
	 glTranslatef(0,0.2, 0);
     glScalef(2, 2, 2);
    
	 //corpo	
     glPushMatrix();
	  glColor3f(0.85f, 0.53f, 0.1f);
	  glutSolidSphere(1, 16, 16);
	 glPopMatrix();

	 //pe da laranja
	 glPushMatrix();
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
	_time += delta_t;
	if (_time > SPEED_UP_INTERVAL) {
		std::cout << "Speed Increased!\n";
		_speedModifier++;
		_time = 0;
	}
	setPosition(_position._x + _speedModifier*_speed*delta_t*_direction._x , _position._y,
		_position._z + _speedModifier*_speed*delta_t*_direction._z);
	
	_rotation.set(_direction._z, _direction._y,- _direction._x);
	_rotangle += delta_t*0.5;

	if (checkOutOfBounds() == true) {
        setPosition((std::rand() % (60 - 0 + 1)) - 30, _position._y, (std::rand() % (60 - 0 + 1)) - 30);
        _direction = Vector3(2 * ((double)(std::rand()) / RAND_MAX) - 1, 0, 2 * ((double)(std::rand()) / RAND_MAX) - 1);
        Vector3::normalize(_direction);
    }
}

void Orange::resetPosition(){
    setPosition((std::rand() % (60 - 0 + 1)) - 30, _position._y, (std::rand() % (60 - 0 + 1)) - 30);
    _direction = Vector3(2 * ((double)(std::rand()) / RAND_MAX) - 1, 0, 2 * ((double)(std::rand()) / RAND_MAX) - 1);
    Vector3::normalize(_direction);
    _speedModifier = 1;
    _time = 0;
}


