//
//  Camera.h
//  CGProj
//

#ifndef __CGProj__Camera__
#define __CGProj__Camera__

#include "Common.h"

class Camera {
private:
	GLdouble _near;
	GLdouble _far;
public:
	Camera(GLdouble near, GLdouble far);
	~Camera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif /* defined(__CGProj__Camera__) */
