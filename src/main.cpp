//
//  main.cpp
//  CGProj
//

#include "Common.h"
#include "GameManager.h"
#include "Logger.h"
#include "Car.h"
#include "Table.h"
#include "Roadside.h"
#include "Orange.h"
#include "butter.h"


int main(int argc, char * argv[]) {
	
    srand (static_cast <unsigned> (time(0)));
    int posx,posy,posz,angle,rotx,roty,rotz;
    float scale;
    
	GameManager* gameMgr = new GameManager();
    
	Car* car = new Car(0,0,0,0,0,0,0,0.5f,0.5f,0.5f);
    Table* table = new Table(0,-1,0);
    Roadside* roadside = new Roadside();
	Logger::printf("Initializing Game Manager");
    
	gameMgr->setCamera(new Camera(5, 200));
	gameMgr->setCar(car);
	gameMgr->addGameObject(car);
    gameMgr->addGameObject(table);
    gameMgr->addGameObject(roadside);
    //Orange Generator
    for(long i = 0; i < 5; i++){
        posx =((std::rand() % (60 -0 + 1)))-30;
        posy = 0;
        posz = (std::rand() % (60-0 + 1))-30;
        roty = 1;
        angle = (std::rand() % (360-0 + 1));
        scale = 0.8+(std::rand() % (40-0 + 1))/100.0f;
        gameMgr->addGameObject(new Orange(posx,posy,posz
                                          ,angle,rotx,roty,rotz
                                          ,scale, scale, scale));
    }
    //Butter Generator
    for(long i = 0; i < 5; i++){
        posx =((std::rand() % (60 -0 + 1)))-30;
        posy = 0;
        posz = (std::rand() % (60-0 + 1))-30;
        roty = 1;
        angle = (std::rand() % (360-0 + 1));
        scale = 0.8+(std::rand() % (20-0 + 1))/100.0f;

        gameMgr->addGameObject(new Butter(posx,posy,posz
                                          ,angle,rotx,roty,rotz
                                          ,scale, scale, scale));
    }
    
    
	gameMgr->init(argc, argv);
	return 0;

}
