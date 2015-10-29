//
//  GameManager.cpp
//  CGProj
//

#include "GameManager.h"
#include "Logger.h"

GameManager* current;
GLdouble t,
delta,
old;

void GameManager::setDisplayCallback()
{
	glutDisplayFunc(GameManager::displayCallback);
	//glutIdleFunc(GameManager::displayCallback);
}

void GameManager::setReshapeCallback()
{
	glutReshapeFunc(GameManager::reshapeCallback);
}

void GameManager::setKeyboardCallback()
{
	glutSpecialFunc(GameManager::specialKeyboardCallback);
    glutSpecialUpFunc(GameManager::specialKeyboardUpCallback);
	glutKeyboardFunc(GameManager::keyboardCallback);
	glutKeyboardUpFunc(GameManager::keyboardUpCallback);
}

void GameManager::setTimerCallback()
{
	glutTimerFunc(TIMER_VAL, GameManager::onTimer, TIMER_VAL);
}

GameManager::GameManager()
{
	current = this;
	_count = 0;
	_accum = 0;
	_w = 1024;
	_h = 768;
	_drawTimer = 0;
	_wireframe = false;
	_camFollow = false;
}

GameManager::~GameManager()
{
}

void GameManager::display()
{
	//Calculate delta time between frames
	_time = glutGet(GLUT_ELAPSED_TIME);
	_delta = _time - _old;
	_old = _time;
	_accum += _delta;
	_drawTimer += _delta;
	
	//Update everything
	draw();
	_count++;
	
	//Calculate fps 
	if (_accum > 1000) {
		_fps = _count;
		_count = 0;
		_accum = 0;
		Logger::print("FPS: ");
		Logger::print(_fps);
		Logger::print("\n");
	}
}

void GameManager::reshapeCallback(GLsizei w, GLsizei h)
{
	current->reshape(w, h);
}

void GameManager::reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	_currentW = w;
	_currentH = h;
	_cam->computeProjectionMatrix(_currentW, _currentH);
	_cam->computeVisualizationMatrix();
}

void GameManager::displayCallback()
{
	current->display();
}

void GameManager::specialKeyboardCallback(int key, int x, int y)
{
	current->specialKeyPressed(key, x, y);
}

void GameManager::specialKeyboardUpCallback(int key, int x, int y)
{
    current->specialKeyPressedUp(key, x, y);
}

void GameManager::keyboardCallback(unsigned char key, int x, int y)
{
	current->keyPressed(key, x, y);
}

void GameManager::keyboardUpCallback(unsigned char key, int x, int y) {

	current->keyboardUp(key, x, y);
}

void GameManager::specialKeyPressed(int key, int x, int y)
{
    
    if(key == GLUT_KEY_UP && _car->_upPressed == false){
        _car->_upPressed = true;
    }
    if(key == GLUT_KEY_DOWN && _car->_downPressed == false){
        _car->_downPressed = true;
    }
    
    if(key == GLUT_KEY_LEFT && _car->_leftPressed == false){
        _car->_leftPressed = true;
    }
    if(key == GLUT_KEY_RIGHT && _car->_rightPressed == false){
        _car->_rightPressed = true;
    }
}

void GameManager::specialKeyPressedUp(int key, int x, int y)
{
    
    if(key == GLUT_KEY_UP && _car->_upPressed != false){
        _car->_upPressed = false;
        
    }
    if(key == GLUT_KEY_DOWN && _car->_downPressed != false){
        _car->_downPressed = false;
    }
    
    if(key == GLUT_KEY_LEFT && _car->_leftPressed != false){
        _car->_leftPressed = false;
    }
    if(key == GLUT_KEY_RIGHT && _car->_rightPressed != false){
        _car->_rightPressed = false;
    }

}



void GameManager::keyboardUp(unsigned char key, int _x, int _y)
{
    
}

void GameManager::keyPressed(unsigned char key, int x, int y)
{

	if (key == 'a') {
		Logger::printf("Toggle wireframe");
		if (_wireframe) 
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		_wireframe = !_wireframe;
	}
    if(key == 'r'){
        _cam->toggleRotate();
        Logger::printf("Toggle rotate");
    }
	if (key == '1') {
		_cam->stopFollow();
		_cam = _cam1;

	}
	if (key == '2') {
		_cam = _cam2;
		_cam->stopFollow();
		_cam->setPosition(0, 100, 1);
		_cam->setLook(Vector3(0, 0, 0));
	}
	if (key == '3') {
		_cam = _cam2;
		_cam->followCar(_car);
	}
	if (key == 27) {
		exit(1);

	}

}

void GameManager::onTimer(int value)
{

	t = glutGet(GLUT_ELAPSED_TIME);
	delta = t - old;
	old = t;

	current->update(delta);
	current->setTimerCallback();
}

void GameManager::idle()
{
}

void GameManager::update(GLdouble delta_t)
{

	for (std::vector<GameObject*>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
		(*it)->update(delta_t);
	}
    
    _collisionSystem->searchCollisions(_gobjs, _car);

	//Redraw
	glutPostRedisplay();
}

void GameManager::draw()
{
	glClearColor(0.0f, 0.4f, 0.7f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	int a = 0;
	_cam->update(_currentW, _currentH);
	for (std::vector<GameObject*>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
		glPushMatrix();
		(*it)->draw();
		glPopMatrix();
		a++;
	}	
	//std::cout << "Draw " << a << " objects\n";
	glFlush();
}

void GameManager::init(int argc, char* argv[])
{
	Logger::printf("Creating window");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(_w, _h);
	glutInitWindowPosition(1920/2 - _w / 2, 1080/2 - _h / 2);
	glutCreateWindow("Micro Machines");

	glClearDepth(1.0f);                     // Depth buffer setup
	glEnable(GL_DEPTH_TEST);                // Enable depth testing
	glDepthFunc(GL_LEQUAL);                 // Type of depth test to do
	glDepthRange(0, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    
	Logger::printf("Starting Game");
	setDisplayCallback();
	setReshapeCallback();
	setKeyboardCallback();
	setTimerCallback();
	_old = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();
}

void GameManager::addGameObject(GameObject* obj)
{
	Logger::printf("GameObject added");
	_gobjs.push_back(obj);
}

void GameManager::setCamera(Camera * cam)
{
	_cam = cam;
}

void GameManager::setCameras(Camera * cam1, Camera * cam2)
{
	_cam1 = cam1;
	_cam2 = cam2;
	_cam = _cam1;
}


void GameManager::setCar(Car * car) {

	_car = car;
	Logger::printf("Car added");

}

void GameManager::setCollisionSystem(CollisionSystem* collisionSystem)
{
	_collisionSystem = collisionSystem;
	Logger::printf("collisionSystem added");
}

void GameManager::GGWP()
{
    for (std::vector<GameObject*>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
        (*it)->reset();
    }

}

GameManager * GameManager::getCurrentInstance()
{
	return current;
}
