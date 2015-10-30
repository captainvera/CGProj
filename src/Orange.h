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

#define SPEED_UP_INTERVAL 8000 // miliseconds
#define RESPAWN_TIME 500 

class Orange : public Obstacle{
private:
	GLboolean checkOutOfBounds();
	GLdouble _speedModifier;
	void setOrangeRespawnCallback();
public:
    
	Orange();
    Orange(GLdouble posx, GLdouble posy, GLdouble posz,
           GLdouble rotangle=0, GLdouble rotx=0, GLdouble roty=0, GLdouble rotz=0,
           GLdouble scalex=1, GLdouble scaley=1, GLdouble scalez=1);
	~Orange();
	void render();
	void update(GLdouble delta_t);
	void respawn();
	void increaseSpeed();
	void resetSpeed();
	void setOrangeSpeedCallback();
	static void orangeRespawnCallback(int obj);
	static void orangeSpeedCallback(int obj);
    void collide(GameObject* obj);
    void collideWith(Car* obj);
	void reset();
};

#endif /* defined(__CGProj__Orange__) */
