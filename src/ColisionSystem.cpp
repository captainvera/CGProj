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

void ColisionSystem::handleColisions(std::vector<GameObject*>& objs, Car* car){
    
    
    //COLLISION SYSTEM baaaaaasico 
    for(std::vector<GameObject*>::iterator it = objs.begin(); it != objs.end(); ++it){
        Car* i = car;
            
        if((*it)->_hascolider == true && /*WTF IS THIS PORQUE E QUE TAS A FAZER *i????? ------>*/(*i)._hascolider == true){
            /* PORQUE NAO UMA FUNÇAO PARA NAO TERES COMBOIOS DE CODIGO*/
            if (pow(((*i)._position._x - (*it)->_position._x), 2) +
                
                pow(((*it)->_position._z - (*i)._position._z), 2) <=
                
                pow((*i)._colisionradius + (*it)->_colisionradius, 2) && (*i)._colisionradius != (*it)->_colisionradius){
        
                // RIP SE QUIZERES COISAS COM O MM COLLISION RADIUS OU ALTERAR O COLLISION RADIUS
                if( (*it)->_colisionradius == 1.1){
                    i->_position = i->_initposition;
                    i->init();
                    // PELAS MEMAS RAZOES
                    for(std::vector<GameObject*>::iterator it2 = objs.begin(); it2 != objs.end(); ++it2){
                        if((*it2)->_colisionradius == 1.1){
                            ((Orange*)*it2)->resetPosition();
                        }
                    }
                    
                    
                }
                if( (*it)->_colisionradius == 1){
                    i->butterSlow();
                }
                
                if( (*it)->_colisionradius == 1.1){
                    
                }
                
                    std::cout<< "Colision detected" << (*i)._colisionradius << " and " <<(*it)->_colisionradius <<"\n" ;
                
            }
        }
    }
}