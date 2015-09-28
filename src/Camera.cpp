//
//  Camera.cpp
//  CGProj
//

#include "Camera.h"

Camera::Camera(GLdouble near, GLdouble far){
    _near = near;
    _far = far;
}

Camera::~Camera(){
}

void Camera::update(GLdouble w, GLdouble h){
    glViewport(0, 0, w, h);
}

void Camera::computeProjectionMatrix(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0f, 10.0f, -10.0f, 10.0f, _near, _far);
}

void Camera::computeVisualizationMatrix(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
