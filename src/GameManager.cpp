//
//  GameManager.cpp
//  CGProj
//

#include "GameManager.h"
#include "Logger.h"

GameManager* current;

void GameManager::setDisplayCallback()
{
	current = this;
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
	glutKeyboardFunc(GameManager::keyboardCallback);
	glutKeyboardUpFunc(GameManager::keyboardUpCallback);
}

void GameManager::setTimerCallback()
{
	glutTimerFunc(TIMER_VAL, GameManager::onTimer, TIMER_VAL);
}

GameManager::GameManager()
{
	_count = 0;
	_accum = 0;
	_w = 1024;
	_h = 768;
	_drawTimer = 0;
	_wireframe = false;
	int i = 0;
	for ( i; i < 255; i++) {
		_isKeyPressed[i] = 0;
	}
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
	
	//Limit fps
	/*if (_drawTimer > 15) {
		draw();
		_drawTimer = 0;
		_count++;
	}*/
	
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

void GameManager::keyboardCallback(unsigned char key, int x, int y)
{
	current->keyPressed(key, x, y);
}

void GameManager::keyboardUpCallback(unsigned char key, int x, int y) {

	current->keyboard_up(key, x, y);
}

void GameManager::specialKeyPressed(int key, int x, int y)
{
	/*
	if (key == GLUT_KEY_UP) {
		Logger::printf("Up pressed");
		_car->move(0.4,0);
	}
	
	if (key == GLUT_KEY_RIGHT){
		Logger::printf("Right pressed");
		_car->move(0, 0.4);
	}
	if (key == GLUT_KEY_LEFT){
		Logger::printf("Left pressed");
		_car->move(0, -0.4);
	}
	if (key == GLUT_KEY_DOWN){
		Logger::printf("Down pressed");
		_car->move(-0.4, 0);
	}
	*/
}

void GameManager::keyboard_up(unsigned char key, int _x, int _y)
{

	if (_isKeyPressed[key] == false) {

	}
	else {
		_isKeyPressed[key] = false;
		std::cout << key << " was pressed up\n";
	}
    
    if(key == 105 && _car->_upPressed != false){
        _car->_upPressed = false;
        std::cout << key << "up was pressed down\n";

    }
    if(key == 107 && _car->_downPressed != false){
        _car->_downPressed = false;
    }
    
    if(key == 106 && _car->_leftPressed != false){
        _car->_leftPressed = false;
    }
    if(key == 108 && _car->_rightPressed != false){
        _car->_rightPressed = false;
    }
}

void GameManager::keyPressed(unsigned char key, int x, int y)
{

	if (key == 'a') {
		Logger::printf("A pressed");
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
	
	if (_isKeyPressed[key] == true) {

	}
	else {
		_isKeyPressed[key] = true;
		std::cout << key << " was pressed down\n";
	}
    
    if(key == 105 && _car->_upPressed == false){
        _car->_upPressed = true;
        std::cout << key << "up was pressed down\n";
    }
    if(key == 107 && _car->_downPressed == false){
        _car->_downPressed = true;
    }
    
    if(key == 106 && _car->_leftPressed == false){
        _car->_leftPressed = true;
    }
    if(key == 108 && _car->_rightPressed == false){
        _car->_rightPressed = true;
    }
    
}

void GameManager::onTimer(int value)
{
	current->update(value);
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
	//Redraw
	glutPostRedisplay();
}

void GameManager::draw()
{
	glClearColor(0.0f, 0.4f, 0.7f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	_cam->computeProjectionMatrix(_currentW, _currentH);
	_cam->computeVisualizationMatrix();
	for (std::vector<GameObject*>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
		glPushMatrix();
		(*it)->draw();
		glPopMatrix();
	}	
	glFlush();
}

void GameManager::init(int argc, char* argv[])
{
	Logger::printf("Creating window");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(1920/2 - _w / 2, 1080/2 - _h / 2);
	glutCreateWindow("Micro Machines");

	glClearDepth(1.0f);                     // Depth buffer setup
	glEnable(GL_DEPTH_TEST);                // Enable depth testing
	glDepthFunc(GL_LEQUAL);                 // Type of depth test to do
	glDepthRange(0, 1);

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

void GameManager::setCar(Car * car) {

	_car = car;
	Logger::printf("Car added");
	_gobjs.push_back(_car);

}