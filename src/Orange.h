//
//  Orange.h
//  CGProj
//

#ifndef __CGProj__Orange__
#define __CGProj__Orange__

#include "Common.h"
#include "Obstacle.h"

class Orange : Obstacle{
public:
	Orange();
	~Orange();
	void draw();
    void spawnOrange(int x, int z);
};

#endif /* defined(__CGProj__Orange__) */
