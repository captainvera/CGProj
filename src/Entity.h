//
//  Entity.h
//  CGProj
//

#ifndef __CGProj__Entity__
#define __CGProj__Entity__

#include "Common.h"
#include "Vector3.h"

class Entity {
private: 
	Vector3 _position;
public:
    Entity();
    ~Entity();
    Vector3* getPosition();
    Vector3* setPosition(GLdouble x, GLdouble y, GLdouble z);
    Vector3* setPosition(const Vector3& vec);
};

#endif /* defined(__CGProj__Entity__) */