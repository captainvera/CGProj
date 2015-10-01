//
//  Roadside.h
//  CGproj
//

#ifndef __CGproj__Roadside__
#define __CGproj__Roadside__

#include "Common.h"
#include "StaticObject.h"
#include "Vector3.h"

class Roadside : public StaticObject {
public:
    Roadside();
    ~Roadside();
    void draw();
    void spawnCheerio(double x, double z);
    Vector3* calculateBezierPoint(float t,Vector3* p0, Vector3* p1, Vector3* p2, Vector3* p3);
    void drawBezier(float t,Vector3* p0, Vector3* p1, Vector3* p2, Vector3* p3);
};
    
#endif /* defined(__CGproj__Roadside__) */
