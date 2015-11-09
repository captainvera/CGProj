//
//  LightSource.h
//  CGProj
//

#ifndef __CGProj__LightSource__
#define __CGProj__LightSource__

#include "Common.h"
#include "Vector3.h"

class LightSource {
protected:
	Vector3 _position,
			_direction;
	GLfloat _ambient[4] = { 0.0, 0.0, 0.0, 1.0 },
			 _diffuse[4] = { 0.0, 0.0, 0.0, 1.0 },
			 _specular[4] = { 0.0, 0.0, 0.0, 1.0 };
	GLdouble _cut_off,
			 _exponent,
			 _w;
	GLenum _num;
	GLboolean _state;

	virtual void setExponent(GLdouble exp);
	virtual void setCutoff(GLdouble cutoff);
	virtual void setAttenuation(GLdouble constant, GLdouble linear, GLdouble quadric);
	virtual void setDirection(GLdouble x, GLdouble y, GLdouble z);
	virtual void setDirection(Vector3& dir);

public:
	LightSource();
	LightSource(GLenum num);
	~LightSource();

	GLboolean getState();
	void setState(GLboolean state);
	GLenum getNum();

	Vector3& getPosition();
	void setPosition(GLdouble x, GLdouble y, GLdouble z);
	void setPosition(Vector3& vec);

	void setAmbient(GLdouble r, GLdouble g, GLdouble b, GLdouble a);
	void setDiffuse(GLdouble r, GLdouble g, GLdouble b, GLdouble a);
	void setSpecular(GLdouble r, GLdouble g, GLdouble b, GLdouble a);

	
	void draw();
};

#endif /* defined(__CGProj__LightSource__) */
