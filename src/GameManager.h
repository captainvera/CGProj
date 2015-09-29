//
//  GameManager.h
//  CGProj
//

#ifndef __CGProj__GameManager__
#define __CGProj__GameManager__

#include "Common.h"
#include <vector>
#include "GameObject.h"
#include "Camera.h"

class GameManager {
private:

	std::vector<GameObject*> _gobjs;

	Camera* _cam;

	GLdouble _time,
		_delta,
		_old,
		_fps,
		_count,
		_accum,
		_w,
		_h,
		_drawTimer;

	GLsizei	_currentW,
		_currentH;
	
	GLboolean _wireframe;

	void setDisplayCallback();
	void setReshapeCallback();
	void setKeyboardCallback();
public:
	GameManager();
	~GameManager();

	static void reshapeCallback(GLsizei w, GLsizei h);
	static void displayCallback();
	static void specialKeyboardCallback(int key, int x, int y);
	static void keyboardCallback(unsigned char key, int x, int y);

	void reshape(GLsizei w, GLsizei h);
	void display();
	void specialKeyPressed(int key, int x, int y);
	void keyPressed(unsigned char key, int x, int y);

	void onTimer();
	void idle();

	void update(GLdouble delta_t);
	void draw();

	void init(int argc, char* argv[]);
	void addGameObject(GameObject* obj);
	void setCamera(Camera* cam);
};

#endif /* defined(__CGProj__GameManager__) */
