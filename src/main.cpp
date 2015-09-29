//
//  main.cpp
//  CGProj
//

#include "Common.h"
#include "GameManager.h"
#include "Logger.h"
#include "Car.h"

int main(int argc, char * argv[]) {
	
	GameManager* gameMgr = new GameManager();

	Car* car = new Car();
	Logger::printf("Initializing Game Manager");
	gameMgr->setCamera(new Camera(1, 200));
	gameMgr->addGameObject(car);
	gameMgr->init(argc, argv);

    return 0;

}
