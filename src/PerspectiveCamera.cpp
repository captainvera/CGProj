#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera()
{
	PerspectiveCamera::PerspectiveCamera(45.0, 5, 200);
}

PerspectiveCamera::PerspectiveCamera(GLfloat fov, GLfloat near, GLfloat far)
{
	Camera::Camera();
	_fov = fov;
	_near = near;
	_far = far;

	_up = Vector3();
	_look = Vector3(0, 0, 0);
	setPosition(0, 125, 1);
	calculateCameraDirection();
	calculateRightAxis();
	calculateUpVector();
}

PerspectiveCamera::~PerspectiveCamera()
{
}


void PerspectiveCamera::computeProjectionMatrix(GLdouble w, GLdouble h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fov, w/ h, _near, _far);
}
