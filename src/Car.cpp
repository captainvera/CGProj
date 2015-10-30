//
//  Car.cpp
//  CGProj
//

#include "Car.h"
#include "Logger.h"

GLboolean Car::checkOutOfBounds()
{
	GLdouble x = _position.getX(), z = _position.getZ();
	if (x > 75 || x < -75 || z > 50 || z < -50)
		return true;
	return false;
}

Car::Car()
{
    _position.set(0,0,0);
    init();
}

Car::Car(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:DynamicObject(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{
    
    init();
}


Car::~Car()
{
}

void Car::init()
{
    /*FIXME direction should be set with rotation*/
    _direction.set(1,0,0);
	_moving.set(1, 0, 0);
    _accel = 0.000012;
    _breakAccel = 0.000035;
    _speed = 0;
    _turnSpeed = 0.035;
	_maxTurnSpeed = 2;
    _friction = 0.000006;
    _angle = 0;
    _maxSpeed = 0.035;
    _maxReverseSpeed = 0.008;
    _upPressed = false;
    _downPressed = false;
    _leftPressed = false;
    _rightPressed = false;
	_turnVelocity = 0;
	_turnFriction = 0.93;
	_facingAngle = 0;
	_maxFacingAngle = 1;
	_drift = 0.98;
    _hascollider = true;
    _collisionradius *= 2;
    _frontWheelRotation = 0;
    _drift = 0;
}

void Car::render()
{   
	/*glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 1, 0.0);
	glVertex3f(_direction._x*10, 1, _direction._z*10);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0, 0.0);
	glVertex3f(_moving._x*10, 0, _moving._z*10);
	glEnd();
    glLineWidth(1);*/

    glPushMatrix();
     glRotatef(_angle,0,1,0);
     glScalef(0.2,0.2,0.2);
    
    //base
     glColor3f(0.33, 0.2, 0.15);
     glPushMatrix();
      glTranslatef(0, 0, 0);
      glScalef(14, 3, 8);
      glutSolidCube(1);
     glPopMatrix();
    
    //capot
     glColor3f(0.20, 0.21, 0.22);
     glPushMatrix();
      glTranslatef(-3.5, 3.5, 0);
      glScalef(7, 4, 8);
      glutSolidCube(1);
     glPopMatrix();
    
    //motor
     glColor3f(0.37, 0.34, 0-.33);
     glPushMatrix();
      glTranslatef(2.5, 2.5, 0);
      glScalef(5, 2, 4);
      glutSolidCube(1);
     glPopMatrix();
    
    //rodas frente
     glColor3f(0, 0, 0);
     glPushMatrix();
    
      glPushMatrix();
	   glTranslatef(4, -1.5, -4.5);
       glRotatef(_frontWheelRotation, 0,1,0);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.7,1,12,15);
      glPopMatrix();
    
      glPushMatrix();
	   glTranslatef(4, -1.5, 4.5);
       glRotatef(_frontWheelRotation, 0,1,0);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.7,1,12,15);
      glPopMatrix();
    
     glPopMatrix();
    
    //rodas trás
     glColor3f(0, 0, 0);
     glPushMatrix();
    
      glPushMatrix();
	   glTranslatef(-5.5, -0.75, -5);
	   glScalef(2.25, 2.25, 2);
	   glutSolidTorus(0.6, 1, 12, 15);
      glPopMatrix();
    
      glPushMatrix();
	   glTranslatef(-5.5, -0.75, 5);
	   glScalef(2.25, 2.25, 2);
	   glutSolidTorus(0.6, 1, 12, 15);
      glPopMatrix();
    
     glPopMatrix();
    glPopMatrix();
    
}

void Car::move( GLdouble accel, GLdouble delta_t){
	
	if (accel < 0 && _speed > 0) {
		_speed += accel*_breakAccel*delta_t;
	}
	if (accel < 0 && fabs(_speed) < _maxReverseSpeed) {
		_speed += accel*_accel*delta_t;
	}else if(accel > 0 && fabs(_speed) < _maxSpeed){
        _speed += accel*_accel*delta_t;
    }
    else if(_speed > 0 && accel == 0){
        _speed -= _friction*delta_t;
		if (_speed < 0) _speed = 0;
    }
	else if (_speed < 0 && accel == 0) {
		_speed += _friction*delta_t;
		if (_speed > 0) _speed = 0;
	}
   _position.set(_position.getX()+_direction.getX()*_speed*delta_t,_position.getY(),_position.getZ()+_direction.getZ()*_speed*delta_t);
}

void Car::turn(GLdouble turn, GLdouble delta_t) {
	if(fabs(_turnVelocity)<_maxTurnSpeed)
		_turnVelocity += turn*_turnSpeed*delta_t*(1.2*_maxSpeed-_speed)*50;
	_turnVelocity *= _turnFriction;
	_angle += _turnVelocity;
	

	//_angle += turn * _turnSpeed * delta_t;
	_direction.set(cos((_angle*M_PI) / 180), 0, -sin((_angle*M_PI) / 180));
	_moving.set(cos((_angle*M_PI) / 180), 0, -sin((_angle*M_PI) / 180));
	_direction.normalize();
	_moving.normalize();

}

void Car::update(GLdouble delta_t) {
    if(_leftPressed == true && _rightPressed == false){
        turn(1, delta_t);
        _frontWheelRotation = 50;
    }
    else if(_leftPressed == false && _rightPressed == true){
        turn(-1, delta_t);
		_frontWheelRotation = -50;
	}
	else {
		_frontWheelRotation = 0;
		turn(0, delta_t);
	}
    
    
    if(_upPressed == true && _downPressed == false){
        move(1, delta_t);
    }
	else if (_upPressed == false && _downPressed == true){
		move(-1, delta_t);
	}
	else {
		move(0, delta_t);
	}

	if (checkOutOfBounds() == true)
		reset();

}

GLdouble Car::getSpeed()
{
    return _speed;
}

void Car::collide(GameObject *obj)
{
    obj->collideWith(this);
}

void Car::collideWith(Butter* butter)
{
    _speed = _speed * 0.7;

}

void Car::collideWith(Orange* orange)
{
    _speed = 0;

}

void Car::collideWith(Cheerio* butter)
{
    _speed = _speed * 0.8;
    
}


