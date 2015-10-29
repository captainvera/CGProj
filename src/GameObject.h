//
//  GameObject.h
//  CGProj
//

#ifndef __CGProj__GameObject__
#define __CGProj__GameObject__

#include "Common.h"
#include "Entity.h"
#include "Vector3.h"

class Butter;
class Orange;
class Cheerio;
class Car;

class GameObject : public Entity {
protected:
    Vector3 _rotation,
    _scale;
    GLdouble _rotangle;
	GLboolean _hasParent, _draw;
	std::vector<GameObject*> _childs;
	GameObject* _parent;
	void setParent(GameObject* gobj);
    Vector3 _initRotation;
    Vector3 _initScale;
    GLdouble _initRotangle;
    
public:
    GLboolean _hascollider;
    GLdouble _collisionradius;
	GameObject();
    GameObject(GLdouble posx, GLdouble posy, GLdouble posz, GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz, GLdouble scalex, GLdouble scaley, GLdouble scalez);
	~GameObject();
	virtual void draw();
	virtual void render();
	virtual void update(GLdouble delta_t);

	void addChild(GameObject* gobj);
	void applyTransform();
    void reset();

	virtual void collide(GameObject* obj);
	virtual void collideWith(GameObject* obj);
	virtual void collideWith(Butter* obj);
	virtual void collideWith(Orange* obj);
	virtual void collideWith(Cheerio* obj);
    virtual void collideWith(Car* obj);

};
#endif /* defined(__CGProj__GameObject__) */
