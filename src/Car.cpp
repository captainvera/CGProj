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
    _break_accel = 0.000035;
    _speed = 0;
    _turnSpeed = 0.035;
	_max_turn_speed = 2;
    _friction = 0.000006;
    _angle = 0;
    _max_speed = 0.035;
    _max_reverse_speed = 0.008;
    _up_pressed = false;
    _down_pressed = false;
    _left_pressed = false;
    _right_pressed = false;
	_turn_velocity = 0;
	_turn_friction = 0.93;
	_facing_angle = 0;
	_max_facing_angle = 1;
	_drift = 0.98;
    _hascollider = true;
    _collisionradius *= 1.7;
    _front_wheel_rotation = 0;
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
       glRotatef(_front_wheel_rotation, 0,1,0);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.7,1,12,15);
      glPopMatrix();
    
      glPushMatrix();
	   glTranslatef(4, -1.5, 4.5);
       glRotatef(_front_wheel_rotation, 0,1,0);
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
		_speed += accel*_break_accel*delta_t;
	}
	if (accel < 0 && fabs(_speed) < _max_reverse_speed) {
		_speed += accel*_accel*delta_t;
	}else if(accel > 0 && fabs(_speed) < _max_speed){
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
	DynamicObject::move(delta_t);
}

void Car::turn(GLdouble turn, GLdouble delta_t) {
	if(fabs(_turn_velocity)<_max_turn_speed && fabs(_speed) >0)
		_turn_velocity += turn*_turnSpeed*delta_t*(1.2*_max_speed-_speed)*50;
	_turn_velocity *= _turn_friction;
	_angle += _turn_velocity;
	

	//_angle += turn * _turnSpeed * delta_t;
	_direction.set(cos((_angle*M_PI) / 180), 0, -sin((_angle*M_PI) / 180));
	_moving.set(cos((_angle*M_PI) / 180), 0, -sin((_angle*M_PI) / 180));
	_direction.normalize();
	_moving.normalize();

}

void Car::update(GLdouble delta_t) {
    if(_left_pressed == true && _right_pressed == false){
        turn(1, delta_t);
        _front_wheel_rotation = 50;
    }
    else if(_left_pressed == false && _right_pressed == true){
        turn(-1, delta_t);
		_front_wheel_rotation = -50;
	}
	else {
		_front_wheel_rotation = 0;
		turn(0, delta_t);
	}
    
    
    if(_up_pressed == true && _down_pressed == false){
        move(1, delta_t);
    }
	else if (_up_pressed == false && _down_pressed == true){
		move(-1, delta_t);
	}
	else {
		move(0, delta_t);
	}

	if (checkOutOfBounds() == true) {
		reset();
	}

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
    _speed = _speed*0.6;

}

void Car::collideWith(Cheerio* butter)
{
    _speed = _speed * 0.9;
    
}

void Car::reset()
{
	DynamicObject::reset();
	_angle = 0.0;
	_direction.set(1, 0, 0);
}


