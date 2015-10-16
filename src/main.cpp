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
#include <time.h>

#define NUM_ORANGES 3
#define NUM_BUTTERS 5

int main(int argc, char * argv[]) {
	
    srand (static_cast <unsigned> (time(0)));

    int posx,posy,posz,angle,rotx=0,roty=0,rotz=0;
    float scale;
    
	GameManager* gameMgr = new GameManager();
    
	Car* car = new Car(-16,0,-20,0,0,0,0,0.5f,0.5f,0.5f);
    Table* table = new Table(0,0,0);
    Roadside* roadside = new Roadside(-4,0,0);

	Logger::printf("Initializing Game Manager");

	Camera* cam = new Camera(-55, 60, -35, 35, 5, 300);
	cam->setPosition(0, 125, 1);
	cam->calculateCameraDirection();

	gameMgr->setCamera(cam);
	gameMgr->setCar(car);
	
	gameMgr->addGameObject(car);
    gameMgr->addGameObject(table);
    gameMgr->addGameObject(roadside);

	table->addChild(car);
	table->addChild(roadside);
	GameObject* temp;
    //Orange Generator
    for(long i = 0; i < NUM_ORANGES; i++){
        posx =((std::rand() % (60 -0 + 1)))-30;
        posy = 0;
        posz = (std::rand() % (60-0 + 1))-30;
        roty = 1;
        angle = (std::rand() % (360-0 + 1));
        scale = 0.8+(std::rand() % (40-0 + 1))/100.0f;
		temp = new Orange(posx, posy, posz
			, angle, rotx, roty, rotz
			, scale, scale, scale);
        gameMgr->addGameObject(temp);
		table->addChild(temp);
    }
    //Butter Generator
    for(long i = 0; i < NUM_BUTTERS; i++){
        posx =((std::rand() % (60 -0 + 1)))-30;
        posy = 0;
        posz = (std::rand() % (60-0 + 1))-30;
        roty = 1;
        angle = (std::rand() % (360-0 + 1));
        scale = 0.8+(std::rand() % (20-0 + 1))/100.0f;
		temp = new Butter(posx, posy, posz
			, angle, rotx, roty, rotz
			, scale, scale, scale);
        gameMgr->addGameObject(temp);
		table->addChild(temp);
    }
    
    
	gameMgr->init(argc, argv);
	return 0;

}
