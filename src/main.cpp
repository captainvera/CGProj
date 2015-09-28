//
//  main.cpp
//  CGProj
//

#include "Common.h"
#include "GameManager.h"
#include "Logger.h"

int main(int argc, char * argv[]) {
	
	GameManager* gameMgr = new GameManager();

	Logger::printf("Initializing Game Manager");
	gameMgr->init(argc, argv);

    return 0;

}
