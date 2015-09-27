//
//  GameObject.h
//  CGProj
//
//  Created by João Vicente on 25/09/15.
//  Copyright (c) 2015 João Vicente. All rights reserved.
//

#ifndef __CGProj__GameObject__
#define __CGProj__GameObject__

#include "Common.h"
#include "Entity.h"

class GameObject : public Entity {
	GameObject();
	~GameObject();
	virtual void draw();
	virtual void update(GLdouble delta_t);
};
#endif /* defined(__CGProj__GameObject__) */
