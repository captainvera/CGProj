//
//  main.cpp
//  CGProj
//

#include "Common.h"
#include "GameManager.h"
#include "Logger.h"

int main(int argc, const char * argv[]) {
	
	Logger logger = Logger();
	GameManager gameMgr = GameManager();

	logger.print("Initializing Game Manager");
	gameMgr.init();

    return 0;

}
