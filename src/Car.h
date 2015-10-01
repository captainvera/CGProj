//
//  Car.h
//  CGProj
//

#ifndef __CGProj__Car__
#define __CGProj__Car__

#include "Common.h"
#include "DynamicObject.h"

class Car : public DynamicObject {

private:
	float _x = 0, _z = 0;
	float _turn = 0;
public:
	Car();
	~Car();
	void draw();
	void move(float accel);
	void turn(float turn);
};

#endif /* defined(__CGProj__Car__) */
