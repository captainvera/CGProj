//
//  Camera.cpp
//  CGProj
//

#include "Camera.h"
#include "Logger.h"

Camera::Camera(GLfloat near, GLfloat far){
    _near = 5.0f;
    _far = 75.0f;
	_left = -20.0f;
	_right = 20.0f;
	_bottom = -15.0f;
	_top = 15.0f;
}

Camera::~Camera(){
}

void Camera::update(GLdouble w, GLdouble h){
    glViewport(0, 0, w, h);
}

void Camera::computeProjectionMatrix(GLdouble w, GLdouble h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat ratio = (_right - _left) / (_top - _bottom);
	GLfloat aspect = (GLfloat)w / h;
	if (ratio < aspect)
	{
		GLfloat delta = ((_top - _bottom) * aspect - (_right - _left)) / 2;
		glOrtho(_left - delta, _right + delta, _bottom, _top, _near, _far);
	}
	else
	{
		GLfloat delta = ((_right - _left) / aspect - (_top - _bottom)) / 2;
		glOrtho(_left, _right, _bottom - delta, _top + delta, _near, _far);
	}
}
double i = 0;
void Camera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	i++;
	gluLookAt(25.00*cos(fmod(i/30,360)), 0, 25*sin(fmod(i/30,360)),
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
}
