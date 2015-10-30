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
#include "CollisionSystem.h"


#define TIMER_VAL 8

class Camera;
class CollisionSystem;

class GameManager {
private:

	std::vector<GameObject*> _gobjs;

	Camera *_cam1, *_cam2, *_cam;
	Car* _car;
    CollisionSystem* _collisionSystem;


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
	
	GLboolean _wireframe,
		_camFollow;

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
	void setCameras(Camera* cam1, Camera* cam2);
	void setCar(Car * car);
    void setCollisionSystem(CollisionSystem* collisionSystem);
    
	GLboolean wireframe();
    void GGWP();
	
	static GameManager* getCurrentInstance();
};

#endif /* defined(__CGProj__GameManager__) */
