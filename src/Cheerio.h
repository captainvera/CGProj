//
//  Orange.h
//  CGProj
//

#ifndef __CGProj__Cheerio__
#define __CGProj__Cheerio__

#include "Common.h"
#include "Obstacle.h"
#include "Vector3.h"
#include "Car.h"

class Cheerio : public Obstacle {
private:
	GLfloat _amb[4] = { 1.0f,0.85f,0.27f,1.0f },
			_diff[4] = { 0.53f,0.41f,0.44f,1.0f },
			_spec[4] = { 0.48f,0.45f,0.48f,1.0f },
			_shine = 74.0f;
public:

	Cheerio();
	Cheerio(GLdouble posx, GLdouble posy, GLdouble posz,
		GLdouble rotangle = 0, GLdouble rotx = 0, GLdouble roty = 0, GLdouble rotz = 0,
		GLdouble scalex = 1, GLdouble scaley = 1, GLdouble scalez = 1);

	~Cheerio();
	void render();
    
    void collide(GameObject* obj);
    void collideWith(Car* car);
    void collideWith(Butter* car);
    void collideWith(Cheerio* car);
};

#endif /* defined(__CGProj__Orange__) */
