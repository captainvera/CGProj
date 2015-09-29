//
//  Camera.h
//  CGProj
//

#ifndef __CGProj__Camera__
#define __CGProj__Camera__

#include "Common.h"
#include "Vector3.h"

class Camera {
private:
	GLfloat _near, _far, _left, _right, _bottom, _top;
	Vector3* _center;
	Vector3* _up;
	Vector3* _at;
public:
	Camera(GLfloat near, GLfloat far);
	~Camera();
	void update(GLdouble w, GLdouble h);
	void computeProjectionMatrix(GLdouble w, GLdouble h);
	void computeVisualizationMatrix();
};

#endif /* defined(__CGProj__Camera__) */
