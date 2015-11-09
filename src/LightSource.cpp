#include "LightSource.h"

LightSource::LightSource()
{
	_position = Vector3(0,0,0);
	_direction = Vector3(0,0,0);
	setPosition(0, 0, 0);
	setDirection(0, 0, 1);
	_w = 0.0;
}

LightSource::LightSource(GLenum num)
{
	_num = num;
}

LightSource::~LightSource()
{
}

GLboolean LightSource::getState()
{
	return _state;
}

void LightSource::setState(GLboolean state)
{
	state = _state;
	if (state)
		glEnable(_num);
	else
		glDisable(_num);
}

GLenum LightSource::getNum()
{
	return _num;
}

Vector3 & LightSource::getPosition()
{
	return _position;
}

void LightSource::setPosition(GLdouble x, GLdouble y, GLdouble z)
{
	_position.set(x, y, z);
	GLfloat pos[4] = {x, y, z, _w};
	glLightfv(_num, GL_POSITION, pos);
}

void LightSource::setPosition(Vector3 & vec)
{
	_position.set(vec);
	GLfloat pos[4] = { _position._x,
					   _position._y,
					   _position._z,
					   0.0 };
	glLightfv(_num, GL_POSITION, pos);
}

void LightSource::setDirection(GLdouble x, GLdouble y, GLdouble z)
{
	_direction.set(x, y, z);
	GLfloat dir[4] = {x ,y ,z ,0.0};
	glLightfv(_num, GL_SPOT_DIRECTION, dir);
}

void LightSource::setDirection(Vector3 & dir)
{
	_direction.set(dir);
	GLfloat vec[4] = { _direction._x,
						_direction._y, 
						_direction._z,
						0.0 };
	glLightfv(_num, GL_SPOT_DIRECTION, vec);
}

void LightSource::setAmbient(GLdouble r, GLdouble g, GLdouble b, GLdouble a)
{
	_ambient[0] = r;
	_ambient[1] = g;
	_ambient[2] = b;
	_ambient[3] = b;
	glLightfv(_num, GL_AMBIENT, _ambient);
}

void LightSource::setDiffuse(GLdouble r, GLdouble g, GLdouble b, GLdouble a)
{
	_diffuse[0] = r;
	_diffuse[1] = g;
	_diffuse[2] = b;
	_diffuse[3] = b;
	glLightfv(_num, GL_DIFFUSE, _diffuse);
}
 
void LightSource::setSpecular(GLdouble r, GLdouble g, GLdouble b, GLdouble a)
{
	_specular[0] = r;
	_specular[1] = g;
	_specular[2] = b;
	_specular[3] = b;
	glLightfv(_num, GL_SPECULAR, _specular);
}

void LightSource::setExponent(GLdouble exp)
{
	_exponent = exp;
	GLfloat val[1] = { exp };
	glLightfv(_num, GL_SPOT_EXPONENT, val);
}

void LightSource::setCutoff(GLdouble cutoff)
{
	_cut_off = cutoff;
	GLfloat val[1] = { cutoff };
	glLightfv(_num, GL_SPOT_CUTOFF, val);
}

void LightSource::setAttenuation(GLdouble constant, GLdouble linear, GLdouble quadric)
{
	GLfloat val[1] = { constant };
	glLightfv(_num, GL_CONSTANT_ATTENUATION, val);
	val[0] = linear;
	glLightfv(_num, GL_LINEAR_ATTENUATION, val);
	val[0] = quadric;
	glLightfv(_num, GL_QUADRATIC_ATTENUATION, val);
}

void LightSource::draw()
{
	setPosition(_position._x, _position._y, _position._z);
	setDirection(_direction);
	//setExponent(_exponent);
}
