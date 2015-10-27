//
//  ColisionSystem.h
//  CGProj
//

#ifndef __CGProj__ColisionSystem__
#define __CGProj__ColisionSystem__

#include "Common.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Car.h"
#include "Orange.h"


class ColisionSystem {
    
public:
    GLdouble _radius;
    GameObject * _obj;
    ColisionSystem(GLdouble radius);
    ~ColisionSystem();
    void handleColisions(std::vector<GameObject*>& objs, Car* car);
};

#endif /* defined(__CGProj__ColisionSystem__) */
