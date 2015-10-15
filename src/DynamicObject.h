//
//  DynamicObject.h
//  CGProj
//

#ifndef __CGProj__DynamicObject__
#define __CGProj__DynamicObject__

#include "Common.h"
#include "GameObject.h"

class DynamicObject : public GameObject{
private:
	Vector3* _speed;
	GLdouble _accel;
public:
	DynamicObject();
    DynamicObject(GLdouble posx, GLdouble posy, GLdouble posz,
                                 GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
                                 GLdouble scalex, GLdouble scaley, GLdouble scalez);
	~DynamicObject();
	void update(GLdouble delta_t);
	void setSpeed(Vector3& speed);
	void setSpeed(GLdouble x, GLdouble y, GLdouble z);
};

#endif /* defined(__CGProj__DynamicObject__) */
