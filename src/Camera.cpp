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

	_up = new Vector3();
	_look = new Vector3(0,0,0);
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
		gluLookAt(25 * cos(rotator/30.0), 120, 25 * sin(rotator/30.0),
			0, 0, 0, 0, 1, 0);
		//WALK FORWARD CAMERA
		/*setPosition(getPosition()->getX()-_direction->getX(),
			getPosition()->getY()-_direction->getY(),
			getPosition()->getZ()-_direction->getZ());
		calculateCameraDirection();
		calculateRightAxis();*/
	}else {
		/*printf("%f %f %f %f %f %f %f %f %f \n", getPosition()->getX(), getPosition()->getY(), getPosition()->getZ(),
			getPosition()->getX() + _direction->getX(),
			getPosition()->getY() + _direction->getY(),
			getPosition()->getZ() + _direction->getZ(),
			_up->getX(), _up->getY(), _up->getZ());*/
		gluLookAt(getPosition()->getX(),
			getPosition()->getY(),
			getPosition()->getZ(),
			getPosition()->getX() - _direction->getX(),
			getPosition()->getY() - _direction->getY(),
			getPosition()->getZ() - _direction->getZ(),
			_up->getX(), _up->getY(), _up->getZ());
	}
	/*gluLookAt(25.00*cos(fmod(i/30,360)), 120, 25*sin(fmod(i/30,360)),
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);*/
}

void Camera::toggleRotate(){
	_radius = 25;
    _rotate = !_rotate;
}

void Camera::calculateCameraDirection()
{
	Vector3 a = *getPosition() - *_look;
	_direction = Vector3::normalize(&a); 
}

void Camera::calculateRightAxis()
{
	_rightaxis = Vector3::crossProduct(new Vector3(0,1,0), _direction);
}

void Camera::calculateUpVector() {
	_up = Vector3::crossProduct(_direction, _rightaxis);
}