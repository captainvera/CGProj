//
//  ColisionSystem.h
//  CGProj
//

#ifndef __CGProj__ColisionSystem__
#define __CGProj__ColisionSystem__

#include "Common.h"
#include "Vector3.h"
#include "GameObject.h"

class ColisionSystem {
    
public:
    GLdouble _radius;
    GameObject * _obj;
    ColisionSystem(GLdouble radius);
    ~ColisionSystem();
    void handleColisions(std::vector<GameObject*>& objs);
};

#endif /* defined(__CGProj__ColisionSystem__) */
