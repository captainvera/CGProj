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
}

GameManager::GameManager()
{
	_count = 0;
	_accum = 0;
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
	//Update everything
	update(_delta);

	Logger::print(_accum);
	Logger::print("\n");
	//Draw everything
	draw();

	//Calculate fps
	_count++;
	if (_accum > 1000) {
		_fps = _count;
		_count = 0;
		_accum = 0;
		Logger::print("FPS: ");
		Logger::print(_fps);
		Logger::print("\n");
	}
	
	//Request re-draw screen
	glutPostRedisplay();
}

void GameManager::reshape(GLsizei w, GLsizei h)
{

}

void GameManager::displayCallback()
{
	current->display();
}

void GameManager::keyPresseD()
{
}

void GameManager::onTimer()
{
}

void GameManager::idle()
{
}

void GameManager::update(GLdouble delta_t)
{
	for (std::vector<GameObject>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
		(*it).update(delta_t);
	}
}

void GameManager::draw()
{
	glClearColor(0.0f, 0.4f, 0.7f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (std::vector<GameObject>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
		(*it).draw();
	}
	glFlush();
}

void GameManager::init(int argc, char* argv[])
{
	Logger::printf("Creating window");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(1920/2 - 1024 / 2, 1080/2 - 768 / 2);
	glutCreateWindow("Micro Machines");

	Logger::printf("Starting Game");
	setDisplayCallback();
	glutReshapeFunc(GameManager::reshape);
	_old = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();
}

void GameManager::addGameObject(GameObject obj)
{
	_gobjs.push_back(obj);
}
