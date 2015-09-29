//
//  Roadside.h
//  CGproj
//

#ifndef __CGproj__Roadside__
#define __CGproj__Roadside__

#include "Common.h"
#include "StaticObject.h"
#include <vector>

class Roadside : public StaticObject {
public:
    Roadside();
    ~Roadside();
    void draw();
    void spawnCheerio(int x, int z);
};

#endif /* defined(__CGproj__Roadside__) */
