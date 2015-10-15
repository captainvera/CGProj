//
//  Butter.h
//  CGProj
//

#ifndef __CGProj__Butter__
#define __CGProj__Butter__

#include "Common.h"
#include "Obstacle.h"

class Butter : public Obstacle{
private:

public:
	Butter();
    Butter(GLdouble posx, GLdouble posy, GLdouble posz,
           GLdouble rotangle=0, GLdouble rotx=0, GLdouble roty=0, GLdouble rotz=0,
           GLdouble scalex=1, GLdouble scaley=1, GLdouble scalez=1);
	~Butter();
	void draw();
};
#endif /* defined(__CGProj__Butter__) */
