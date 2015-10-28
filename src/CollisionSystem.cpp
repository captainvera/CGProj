//
//  CollisionSystem.cpp
//  CGProj
//

/*FIXME implement square and circle colliders, coexisting*/ 

#include "CollisionSystem.h"


CollisionSystem::CollisionSystem(GLdouble radius){
    _radius = radius;
}

CollisionSystem::~CollisionSystem(){
}

void CollisionSystem::searchCollisions(std::vector<GameObject*>& objs, GameObject* target){
    
	if(target->_hascollider == true){
		//COLLISION SYSTEM baaaaaasico 
		for(std::vector<GameObject*>::iterator it = objs.begin(); it != objs.end(); ++it){

			if((*it)->_hascollider == true){

				if (checkCollision(*it, target) == true) {
					target->collide(*it);
					(*it)->collide(target);
				}
			}
		}
	}
	else std::cout << "DEBUG: Seriously.. Something can't colide if it has no collider (Hint: CollisionSystem)";
}

GLboolean CollisionSystem::checkCollision(GameObject* obj1, GameObject* obj2)
{
    if (pow(((*obj1)._position._x - (*obj2)._position._x), 2) +
        
        pow(((*obj2)._position._z - (*obj1)._position._z), 2) <=
        
        pow((*obj1)._collisionradius + (*obj2)._collisionradius, 2))
        
        return true;
    
    return false;
    
}