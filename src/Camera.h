//
//  Camera.h
//  CGProj
//

#ifndef __CGProj__Camera__
#define __CGProj__Camera__

#include "Common.h"
#include "Vector3.h"
#include "GameObject.h"

class Camera : public GameObject{
private:
	GLfloat _near, 
			_far, 
			_left, 
			_right, 
			_bottom, 
			_top, 
			_radius;
	Vector3 _up,
			_look,
			_direction,
			_rightaxis;
    GLboolean _rotate;
public:

	Camera(GLfloat near, GLfloat far);
	~Camera();

	void update(GLdouble w, GLdouble h);
	void computeProjectionMatrix(GLdouble w, GLdouble h);
	void computeVisualizationMatrix();

    void toggleRotate();

	void calculateCameraDirection();
	void calculateRightAxis();
	void calculateUpVector();
};

#endif /* defined(__CGProj__Camera__) */
