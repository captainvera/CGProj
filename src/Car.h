//
//  Car.h
//  CGProj
//

#ifndef __CGProj__Car__
#define __CGProj__Car__

#include "Common.h"
#include "DynamicObject.h"
#include "Vector3.h"

class Car : public DynamicObject {
    
private:
    
    
    
public:
    Vector3 _position,
    _direction;
    GLdouble _accel,
    _speed,
    _turnSpeed,
    _angle,
    _friction,
    _maxSpeed;
    
    bool _leftPressed, _rightPressed, _downPressed, _upPressed;
    Car();
    ~Car();
    void draw();
    void move(GLdouble accel, GLdouble delta_t);
    void turn(GLdouble turn, GLdouble delta_t);
    void update(GLdouble delta_t);
    
};

#endif /* defined(__CGProj__Car__) */
