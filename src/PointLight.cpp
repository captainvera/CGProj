#include "PointLight.h"

PointLight::PointLight(GLenum num) : LightSource(num)
{
	_w = 1.0;
}

PointLight::~PointLight()
{
}

void PointLight::setAttenuation(GLdouble constant, GLdouble linear, GLdouble quadric)
{
	LightSource::setAttenuation(constant, linear, quadric);
}

void PointLight::setCutoff(GLdouble cutoff)
{
	LightSource::setCutoff(cutoff);
}

void PointLight::setExponent(GLdouble exp)
{
	LightSource::setExponent(exp);
}
