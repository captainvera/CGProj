//
//  Camera.cpp
//  CGProj
//

#include "Camera.h"
#include "Logger.h"
#include "Car.h"


Camera::Camera() {
	_rotate = false;
	_toFollow = false;
}

Camera::~Camera(){
}

void Camera::update(GLdouble w, GLdouble h){
    //glViewport(0, 0, w, h);
    // PASSAR PARA O UPDATE O MOVIMENTO DA CAMARA
	if (_toFollow) {
		setPosition(_follow->getPosition()._x - _follow->getDirection()._x * 50, 
			_follow->getPosition()._y + 20, _follow->getPosition()._z - _follow->getDirection()._z * 50);
		//std::cout <<"1: "<< getPosition() << " | " << _follow->_position << " | " << _follow->_direction << "\n";
		setLook(Vector3(_follow->getPosition()._x + _follow->getDirection()._x * 50,
			_follow->getPosition()._y, _follow->getPosition()._z + _follow->getDirection()._z * 50));
	}
	calculateCameraDirection();
	//calculateRightAxis();
	computeProjectionMatrix(w, h);
	computeVisualizationMatrix();

}

void Camera::computeProjectionMatrix(GLdouble w, GLdouble h){
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
    _rotate = !_rotate;
}

void Camera::calculateCameraDirection()
{
	Vector3 t = Vector3(_position);
	_direction = t - _look;
	Vector3::normalize(_direction); 
}

void Camera::calculateRightAxis()
{
    Vector3 vector = Vector3(0,1,0);
	Vector3::crossProduct(vector, _direction, _rightaxis);
}

void Camera::calculateUpVector() {
	Vector3::crossProduct(_direction, _rightaxis, _up);
}

void Camera::setDirection(Vector3& dir) {
	_direction.set(dir._x, dir._y, dir._z);
}

void Camera::setLook(Vector3 look) {
	_look.set(look._x, look._y, look._z);
}

void Camera::followCar(Car* gobj)
{
	_follow = gobj;
	_toFollow = true;
}

void Camera::stopFollow()
{
	_toFollow = false;
	_follow = NULL;
}


