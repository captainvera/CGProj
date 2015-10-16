//
//  GameManager.h
//  CGProj
//

#ifndef __CGProj__GameManager__
#define __CGProj__GameManager__

#include "Common.h"
#include "GameObject.h"
#include "Camera.h"
#include "Car.h"

#define TIMER_VAL 15

class GameManager {
private:

	std::vector<GameObject*> _gobjs;

	Camera* _cam;

	Car* _car;


	GLdouble _time,
		_delta,
		_old,
		_fps,
		_count,
		_accum, _drawTimer;


	GLdouble _w,
		_h;

	GLsizei	_currentW,
		_currentH;
	
	GLboolean _wireframe;

	void setDisplayCallback();
	void setReshapeCallback();
	void setKeyboardCallback();
	void setTimerCallback();
public:
	GameManager();
	~GameManager();

	static void reshapeCallback(GLsizei w, GLsizei h);
	static void displayCallback();
	static void specialKeyboardCallback(int key, int x, int y);
    static void specialKeyboardUpCallback(int key, int x, int y);
	static void keyboardCallback(unsigned char key, int x, int y);
	static void keyboardUpCallback(unsigned char key, int x, int y);
	static void onTimer(int value);

	void reshape(GLsizei w, GLsizei h);
	void display();
	void specialKeyPressed(int key, int x, int y);
    void specialKeyPressedUp(int key, int x, int y);
	void keyPressed(unsigned char key, int x, int y);
    void keyboardUp(unsigned char key, int x, int y);

	void idle();

	void update(GLdouble delta_t);
	void draw();

	void init(int argc, char* argv[]);
	void addGameObject(GameObject* obj);
	void setCamera(Camera* cam);
	void setCar(Car * car);
	
	static GameManager* getCurrentInstance();
};

#endif /* defined(__CGProj__GameManager__) */
