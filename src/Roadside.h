//
//  Roadside.h
//  CGproj
//

#ifndef __CGproj__Roadside__
#define __CGproj__Roadside__

#include "Common.h"
#include "StaticObject.h"
#include "Vector3.h"
#include <vector>

class Roadside : public StaticObject {
private:
    std::vector<Vector3> _spawnedCheerios;
    std::vector<Vector3> _controlPoints;
    std::vector<Vector3> _outside;
    std::vector<Vector3> _inside;
    
public:
    Roadside();
    ~Roadside();
    void draw();
    void spawnCheerio(double x, double z);
    Vector3 calculateBezierPoint(float t,Vector3 p0, Vector3 p1, Vector3 p2, Vector3 p3);
    void drawBezierPath();
    void calculatePerpendicularPoints();
};
    
#endif /* defined(__CGproj__Roadside__) */
