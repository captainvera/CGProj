//
//  Orange.h
//  CGProj
//

#ifndef __CGProj__Orange__
#define __CGProj__Orange__

#include "Common.h"
#include "Obstacle.h"
#include "Vector3.h"
#include "Car.h"
#include "GameManager.h"

#define SPEED_UP_INTERVAL 20000 //20s

class Orange : public Obstacle{
private:
	GLboolean checkOutOfBounds();
    GLdouble _time;
public:
    GLdouble _speedModifier;
    
	Orange();
    Orange(GLdouble posx, GLdouble posy, GLdouble posz,
           GLdouble rotangle=0, GLdouble rotx=0, GLdouble roty=0, GLdouble rotz=0,
           GLdouble scalex=1, GLdouble scaley=1, GLdouble scalez=1);
	~Orange();
	void draw();
	void update(GLdouble delta_t);
    void resetPosition();
    void collide(GameObject* obj);
    void collideWith(Car* obj);
};

#endif /* defined(__CGProj__Orange__) */
