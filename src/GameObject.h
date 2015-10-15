//
//  GameObject.h
//  CGProj
//

#ifndef __CGProj__GameObject__
#define __CGProj__GameObject__

#include "Common.h"
#include "Entity.h"
#include "Vector3.h"

class GameObject : public Entity {
private:
    Vector3 _rotation,
    _scale;
    GLdouble _rotangle;
    
public:
	GameObject();
    GameObject(GLdouble posx, GLdouble posy, GLdouble posz, GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz, GLdouble scalex, GLdouble scaley, GLdouble scalez);
	~GameObject();
	virtual void draw();
	virtual void update(GLdouble delta_t);
};
#endif /* defined(__CGProj__GameObject__) */
