//
//  Butter.h
//  CGProj
//

#ifndef __CGProj__Butter__
#define __CGProj__Butter__

#include "Common.h"
#include "Obstacle.h"
#include "Car.h"

class Butter : public Obstacle{
private:
	GLboolean checkOutOfBounds();
	GLfloat _amb[4] = { 1.0f,0.92f,0.48f,1.0f },
			_diff[4] = { 0.43f,0.45f,0.48f,1.0f },
			_spec[4] = { 0.48f,0.4f,0.47f,1.0f },
			_shine = 26.0f;
public:
	Butter();
    Butter(GLdouble posx, GLdouble posy, GLdouble posz,
           GLdouble rotangle=0, GLdouble rotx=0, GLdouble roty=0, GLdouble rotz=0,
           GLdouble scalex=1, GLdouble scaley=1, GLdouble scalez=1);
	~Butter();
	void render();
	void update(GLdouble delta_t);

	void collide(GameObject* obj);
    void collideWith(Car* car);
};
#endif /* defined(__CGProj__Butter__) */
