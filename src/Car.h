//
//  Car.h
//  CGProj
//

#ifndef __CGProj__Car__
#define __CGProj__Car__

#include "Common.h"
#include "DynamicObject.h"

class Car : public DynamicObject {
public:
	Car();
	~Car();
	void draw();
};

#endif /* defined(__CGProj__Car__) */
