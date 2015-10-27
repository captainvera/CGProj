//
//  CollisionSystem.cpp
//  CGProj
//

/*FIXME implement square and circle coliders, coexisting*/ 

#include "CollisionSystem.h"


CollisionSystem::CollisionSystem(GLdouble radius){
    _radius = radius;
}

CollisionSystem::~CollisionSystem(){
}

void CollisionSystem::searchCollisions(std::vector<GameObject*>& objs, GameObject* target){
    
    
    //COLLISION SYSTEM baaaaaasico 
    for(std::vector<GameObject*>::iterator it = objs.begin(); it != objs.end(); ++it){
            
        if((*it)->_hascolider == true){
                    std::cout<< "Collision detected" << (*target)._collisionradius << " and " <<(*it)->_collisionradius <<"\n" ;
            
                
        }
    }
}

GLboolean CollisionSystem::checkCollision(GameObject* obj1, GameObject* obj2)
{
    if (pow(((*obj1)._position._x - (*obj2)._position._x), 2) +
        
        pow(((*obj2)._position._z - (*obj1)._position._z), 2) <=
        
        pow((*obj1)._collisionradius + (*obj2)._collisionradius, 2) && (*obj1)._collisionradius != (*obj2)._collisionradius)
        
        return true;
    
    return false;
    
}

template <>
bool CollisionSystem::handleCollision(Car c, Orange c2 )
{

}