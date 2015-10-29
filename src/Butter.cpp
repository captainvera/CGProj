//
//  Butter.cpp
//  CGProj
//

#include "Butter.h"

Butter::Butter()
{
    _hascollider = true;
    _collisionradius *= 1;
    _friction = 0.00002;
}

Butter::Butter(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Obstacle(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{
    _hascollider = true;
    _collisionradius *= 1;
    _friction = 0.00002;
	
}

Butter::~Butter()
{
}

void Butter::render()
{
    glPushMatrix();
     glTranslated(0,-0.3f, 0);
     glScalef(1.5f, 1.5f, 1.5f);
    //Body
     glPushMatrix();
      glColor3f(1, 1, 0.67f);
      glScalef(3.0f,1.0f,1.5f);
      glutSolidCube(1);
     glPopMatrix();
	 //Droplet 1
     glPushMatrix();
      glTranslatef(1.5f, -0.25f, 0.2f);
      glutSolidSphere(0.5f, 16, 16);
    //Droplet 2
      glPushMatrix();
       glTranslatef(0.4f, -0.1f,0.5f);
       glutSolidSphere(0.4f, 16, 16);
    //Droplet3
       glPushMatrix();
        glTranslatef(0.25f, -0.05f,0.25f);
        glutSolidSphere(0.3f, 16, 16);
       glPopMatrix();

      glPopMatrix();

     glPopMatrix();
    
    glPopMatrix();
    
}


void Butter::update(GLdouble delta_t) 
{
	
	if (_speed > 0) {
        move(delta_t);
		_speed -= _friction*delta_t;
		if (_speed < 0) _speed = 0;
	}
    
}

void Butter::move(GLdouble delta_t)
{
   _position.set(_position.getX()+_direction.getX()*_speed*delta_t,0,_position.getZ()+_direction.getZ()*_speed*delta_t);
}

void Butter::collide(GameObject* obj) 
{
	obj->collideWith(this);
}

void Butter::collideWith(Car* car)
{

    std::cout << _position <<"stuff";
    _speed = fabs(car->getSpeed());
    _direction.set(_position.getX() - car->_position.getX(), _position.getY() - car->_position.getY(),_position.getZ() - car->_position.getZ());
    _direction.normalize();
    std::cout << _direction;
    std::cout <<"car: " << car -> getSpeed() << " butt: " << _speed << "po: " << _position<< "\n";
}

