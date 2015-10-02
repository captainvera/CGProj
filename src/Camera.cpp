//
//  Camera.cpp
//  CGProj
//

#include "Camera.h"
#include "Logger.h"

Camera::Camera(GLfloat near, GLfloat far){

	//ORTHO
    _near = 5.0f;
    _far = 200.0f;
	_left = -50.0f;
	_right = 50.0f;
	_bottom = -40.0f;
	_top = 40.0f;

    _rotate = false;

	_up = Vector3();
	_look = Vector3(0,0,0);
	setPosition(25, 120, 25);

	calculateCameraDirection();
	calculateRightAxis();
	calculateUpVector();
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
double rotator = 0;
void Camera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (_rotate) {
		rotator++;
		setPosition(50*cos(rotator/30.0), _position._y, 50*sin(rotator/30.0));
		calculateCameraDirection();
		calculateRightAxis();
		gluLookAt(_position._x,
			_position._y,
			_position._z,
			_position._x - _direction._x,
			_position._y - _direction._y,
			_position._z - _direction._z,
			0, 1, 0);
	}else {
		gluLookAt(_position._x,
			_position._y,
			_position._z,
			_position._x - _direction._x,
			_position._y - _direction._y,
			_position._z - _direction._z,
			0, 1, 0);
	}
}

void Camera::toggleRotate(){
	_radius = 25;
    _rotate = !_rotate;
}

void Camera::calculateCameraDirection()
{
	_direction = _position - _look;
	Vector3::normalize(_direction); 
}

void Camera::calculateRightAxis()
{
	Vector3::crossProduct(Vector3(0,1,0), _direction, _rightaxis);
}

void Camera::calculateUpVector() {
	Vector3::crossProduct(_direction, _rightaxis, _up);
}