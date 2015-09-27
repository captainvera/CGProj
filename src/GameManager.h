//
//  GameManager.h
//  CGProj
//

#ifndef __CGProj__GameManager__
#define __CGProj__GameManager__

#include "Common.h"

class GameManager {
public:
	GameManager();
	~GameManager();

	void display();
	void reshape(GLsizei w, GLsizei h);

	void keyPresseD();
	void onTimer();
	void idle();
	void update();
	void init();

};

#endif /* defined(__CGProj__GameManager__) */
