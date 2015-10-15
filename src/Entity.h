//
//  Entity.h
//  CGProj
//

#ifndef __CGProj__Entity__
#define __CGProj__Entity__

#include "Common.h"
#include "Vector3.h"

class Entity {
protected:
	Vector3 _position,
		_rotation,
		_scale;
	float _rotangle;
public:
	Entity::Entity();
    Entity(float posx, float posy, float posz, float rotangle, float rotx, float roty, float rotz, float scalex, float scaley, float scalez);
    ~Entity();
    Vector3& getPosition();
    void setPosition(GLdouble x, GLdouble y, GLdouble z);
    void setPosition(Vector3& vec);
};

#endif /* defined(__CGProj__Entity__) */
