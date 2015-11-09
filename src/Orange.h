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
	GLdouble _speed_modifier, 
			 _base_speed;
	void setOrangeRespawnCallback();
	GLfloat _amb[4] = { 1.0f,0.53f,0.03f,1.0f },
			_diff[4] = { 0.68f,0.45f,0.43f,1.0f },
			_spec[4] = { 0.51f,0.43f,0.62f,1.0f },
			_shine = 60.0f,
			_ambpe[4] = { 0.15f,0.14f,0.0f,1.0f },
			_diffpe[4] = { 0.59f,0.43f,0.36f,1.0f },
			_specpe[4] = { 0.46f,0.45f,0.48f,1.0f },
			_shinepe = 108.0f;
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
