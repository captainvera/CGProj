//
//  GameObject.h
//  CGProj
//

#ifndef __CGProj__GameObject__
#define __CGProj__GameObject__

#include "Common.h"
#include "Entity.h"

class GameObject : public Entity {
public:
	GameObject();
	~GameObject();
	virtual void draw();
	virtual void update(GLdouble delta_t);
};
#endif /* defined(__CGProj__GameObject__) */
