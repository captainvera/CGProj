//
//  GameManager.h
//  CGProj
//

#ifndef __CGProj__GameManager__
#define __CGProj__GameManager__

#include "Common.h"
#include <vector>
#include "GameObject.h"

class GameManager {
private:
	std::vector<GameObject> _gobjs;
	void setDisplayCallback();
	GLdouble _time, _delta, _old, _fps, _count, _accum;
public:
	GameManager();
	~GameManager();

	static void reshape(GLsizei w, GLsizei h);
	static void displayCallback();
	void display();
	void keyPresseD();
	void onTimer();
	void idle();
	void update(GLdouble delta_t);
	void draw();
	void init(int argc, char* argv[]);
	void addGameObject(GameObject obj);
};

#endif /* defined(__CGProj__GameManager__) */
