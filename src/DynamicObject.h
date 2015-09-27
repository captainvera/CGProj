//
//  DynamicObject.h
//  CGProj
//
//  Created by João Vicente on 25/09/15.
//  Copyright (c) 2015 João Vicente. All rights reserved.
//

#ifndef __CGProj__DynamicObject__
#define __CGProj__DynamicObject__

#include "Common.h"
#include "GameObject.h"

class DynamicObject : public GameObject{
public:
	DynamicObject();
	~DynamicObject();
	void update(GLdouble delta_t);
	void setSpeed(Vector3& speed);
	void setSpeed(GLdouble x, GLdouble y, GLdouble z);
};

#endif /* defined(__CGProj__DynamicObject__) */
