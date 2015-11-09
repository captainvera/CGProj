//
//  Material.h
//  CGProj
//

#ifndef __CGProj__Material__
#define __CGProj__Material__

#include "Common.h"

class Material {
public:	
	Material();
	~Material();
	void defineMaterial(GLfloat amb[], GLfloat diff[], GLfloat spec[], GLfloat shine);
};

#endif /* defined(__CGProj__Material__) */