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
protected:
    Vector3 _rotation,
    _scale;
    GLdouble _rotangle;
	GLboolean _hasParent;
	std::vector<GameObject*> _childs;
	GameObject* _parent;
	void setParent(GameObject* gobj);
    virtual void colideWith(GameObject&);
public:
    GLboolean _hascolider;
    GLdouble _colisionradius;
	GameObject();
    GameObject(GLdouble posx, GLdouble posy, GLdouble posz, GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz, GLdouble scalex, GLdouble scaley, GLdouble scalez);
	~GameObject();
	virtual void draw();
	virtual void update(GLdouble delta_t);

	void addChild(GameObject* gobj);
	void applyTransform();
    virtual void colide(GameObject&);
};
#endif /* defined(__CGProj__GameObject__) */
