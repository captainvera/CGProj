//
//  Car.h
//  CGProj
//

#ifndef __CGProj__Car__
#define __CGProj__Car__

#include "Common.h"
#include "DynamicObject.h"
#include "Vector3.h"
#include "Orange.h"
#include "Butter.h"
#include "Cheerio.h"

class Car : public DynamicObject {
    
public:
    
    
    GLdouble _turnSpeed,
		_angle,
		_friction,
		_maxSpeed,
		_breakAccel,
		_maxReverseSpeed,
        _frontWheelRotation,
        _drift;
    
    GLboolean _leftPressed,
		_rightPressed, 
		_downPressed, 
		_upPressed;

    Car();
    Car(GLdouble posx, GLdouble posy, GLdouble posz,
           GLdouble rotangle=0, GLdouble rotx=0, GLdouble roty=0, GLdouble rotz=0,
           GLdouble scalex=1, GLdouble scaley=1, GLdouble scalez=1);
    ~Car();
    void draw();
    void move(GLdouble accel, GLdouble delta_t);
    void turn(GLdouble turn, GLdouble delta_t);
    void update(GLdouble delta_t);
    void init();
    
    void collide(GameObject* obj);
	void collideWith(Butter* butter);
    void collideWith(Orange* orange);
    
};

#endif /* defined(__CGProj__Car__) */
