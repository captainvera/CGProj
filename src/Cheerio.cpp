#include "Cheerio.h"

Cheerio::Cheerio()
{
    _hascollider = true;
    _collisionradius *= 0.2;
    _friction = 0.009;
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
    _friction = 0.009;
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

void Cheerio::update(GLdouble delta_t)
{
    
    if (_speed > 0) {
        move(delta_t);
        _speed -= _friction*delta_t;
        if (_speed < 0) _speed = 0;
    }
    
}

void Cheerio::move(GLdouble delta_t)
{
    _position.set(_position.getX()+_direction.getX()*_speed*delta_t,0,_position.getZ()+_direction.getZ()*_speed*delta_t);
}

void Cheerio::collide(GameObject* obj)
{
    obj->collideWith(this);
}

void Cheerio::collideWith(Car* car)
{
    
    std::cout << _position <<"stuff";
    _speed = fabs(car->getSpeed());
    _direction.set(_position.getX() - car->_position.getX(), _position.getY() - car->_position.getY(),_position.getZ() - car->_position.getZ());
    _direction.normalize();
    std::cout << _direction;
    std::cout <<"car: " << car -> getSpeed() << " butt: " << _speed << "po: " << _position<< "\n";
}


