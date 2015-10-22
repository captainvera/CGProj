//
//  ColisionSystem.cpp
//  CGProj
//

#include "ColisionSystem.h"


ColisionSystem::ColisionSystem(GLdouble radius){
    _radius = radius;
}

ColisionSystem::~ColisionSystem(){
}

void ColisionSystem::handleColisions(std::vector<GameObject*>& objs){
    
    for(std::vector<GameObject*>::iterator it = objs.begin(); it != objs.end(); ++it){
        

        for(std::vector<GameObject*>::iterator i = it + 1; i != objs.end(); ++i){
            
            if((*it)->_hascolider == true && (*i)->_hascolider == true){
                
                
                
                if (pow(((*i)->_position._x - (*it)->_position._x), 2) +
                
                    pow(((*it)->_position._z - (*i)->_position._z), 2) <=
                
                    pow((*i)->_colisionradius + (*it)->_colisionradius, 2)){
        
                    std::cout<< "Colision detected" << (*i)->_colisionradius << " and " <<(*it)->_colisionradius <<"\n" ;
                
                }
            }
        }
    }
    std::cout<< "Colisions ended"<<"\n";
}