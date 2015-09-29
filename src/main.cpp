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

int main(int argc, char * argv[]) {
	
	GameManager* gameMgr = new GameManager();

	Car* car = new Car();
    Table* table = new Table();
    Roadside* roadside = new Roadside();
	Logger::printf("Initializing Game Manager");
	gameMgr->setCamera(new Camera(5, 200));
	gameMgr->addGameObject(car);
    gameMgr->addGameObject(table);
    gameMgr->addGameObject(roadside);
	gameMgr->init(argc, argv);

    return 0;

}
