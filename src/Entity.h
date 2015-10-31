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
	Vector3 _initPosition;
public:
    Vector3 _position;
	Entity();
    Entity(GLdouble posx, GLdouble posy, GLdouble posz);
    ~Entity();
    Vector3& getPosition();
    void setPosition(GLdouble x, GLdouble y, GLdouble z);
    void setPosition(Vector3& vec);
    virtual void reset();
};

#endif /* defined(__CGProj__Entity__) */
