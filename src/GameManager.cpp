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

	_light_pool.push_back(GL_LIGHT0);
	_light_pool.push_back(GL_LIGHT1);
	_light_pool.push_back(GL_LIGHT2);
	_light_pool.push_back(GL_LIGHT3);
	_light_pool.push_back(GL_LIGHT4);
	_light_pool.push_back(GL_LIGHT5);
	_light_pool.push_back(GL_LIGHT6);
	_light_pool.push_back(GL_LIGHT7);
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
	_current_w = w;
	_current_h = h;
	_cam->computeProjectionMatrix(_current_w, _current_h);
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
    
    if(key == GLUT_KEY_UP && _car->_up_pressed == false){
        _car->_up_pressed = true;
    }
    if(key == GLUT_KEY_DOWN && _car->_down_pressed == false){
        _car->_down_pressed = true;
    }
    
    if(key == GLUT_KEY_LEFT && _car->_left_pressed == false){
        _car->_left_pressed = true;
    }
    if(key == GLUT_KEY_RIGHT && _car->_right_pressed == false){
        _car->_right_pressed = true;
    }
}

void GameManager::specialKeyPressedUp(int key, int x, int y)
{
    
    if(key == GLUT_KEY_UP && _car->_up_pressed != false){
        _car->_up_pressed = false;
        
    }
    if(key == GLUT_KEY_DOWN && _car->_down_pressed != false){
        _car->_down_pressed = false;
    }
    
    if(key == GLUT_KEY_LEFT && _car->_left_pressed != false){
        _car->_left_pressed = false;
    }
    if(key == GLUT_KEY_RIGHT && _car->_right_pressed != false){
        _car->_right_pressed = false;
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
		_cam->followCar(_car, Vector3(35,15,35));
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

	_cam->update();
	for (std::vector<GameObject*>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
		(*it)->update(delta_t);
	}
    
	/*for (std::vector<GameObject*>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
        if((*it)->_hascollider == true)
            _collisionSystem->searchCollisions(_gobjs, (*it));
    }*/
	_collision_system->searchCollisions(_gobjs, _car);
    /*for (std::vector<GameObject*>::iterator it = _gobjs.begin(); it != _gobjs.end(); ++it) {
		if ((*it)->_hascollider == true) {
			DynamicObject* din;
			din = (DynamicObject*)(*it);
			if(din->getSpeed() > 0)
				_collisionSystem->searchCollisions(_gobjs, din);
		}
    }*/
	//Redraw
	glutPostRedisplay();
}

void GameManager::draw()
{
	glClearColor(0.0f, 0.4f, 0.7f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	int a = 0;
	_cam->calculateCameraDirection();
	_cam->computeProjectionMatrix(_current_w, _current_h);
	for (std::vector<LightSource*>::iterator it = _light_sources.begin(); it != _light_sources.end(); ++it) {
		(*it)->draw();
	}
	_cam->computeVisualizationMatrix();
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

    glEnable(GL_BLEND);

	glEnable(GL_LIGHTING);

	//glEnable(GL_COLOR_MATERIAL);
	
	/*
	glEnable(GL_LIGHT7);
	GLfloat t[4] = { 0,0,0,1 };
	glLightfv(GL_LIGHT7, GL_AMBIENT, t);
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, t);
	t[0] = 1; t[1] = 1; t[2] = 1;
	glLightfv(GL_LIGHT7, GL_DIFFUSE, t);
	glLightfv(GL_LIGHT7, GL_SPECULAR, t);
	t[0] = 0; t[1] = 0; t[3] = 0;
	glLightfv(GL_LIGHT7, GL_POSITION, t);
	*/

	setDisplayCallback();
	setReshapeCallback();
	setKeyboardCallback();
	setTimerCallback();
}

void GameManager::start()
{
	_old = glutGet(GLUT_ELAPSED_TIME);
	printf("Starting Game with %d GameObjects\n", _gobjs.size());
	glutMainLoop();
}

void GameManager::addGameObject(GameObject* obj)
{
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
	_collision_system = collisionSystem;
	Logger::printf("CollisionSystem added");
}

PointLight* GameManager::createPointLight()
{
	PointLight* l = nullptr;
	if (_light_pool.size() > 0) {
		GLenum n = _light_pool.back();
		_light_pool.pop_back();

		l = new PointLight(n);
		l->setState(true);

		//Default PointLight Settings
		l->setAmbient(0, 0, 0, 1);
		l->setDiffuse(1, 1, 1, 1);
		l->setSpecular(1, 1, 1, 1);
		l->setPosition(0, 0, 1);

		std::cout << "Enabled light " << n << "\n";
		_light_sources.push_back(l);
	}
	else
		Logger::print("Error: tried to create lights but all lights are used");
	return l;
}

DirectionalLight* GameManager::createDirectionalLight()
{
	DirectionalLight* l = nullptr;
	if (_light_pool.size() > 0) {
		GLenum n = _light_pool.back();
		_light_pool.pop_back();
		
		l = new DirectionalLight(n);
		l->setState(true);

		//Default Light Settings
		l->setAmbient(0, 0, 0, 1);
		l->setDiffuse(1, 1, 1, 1);
		l->setSpecular(1, 1, 1, 1);
		l->setPosition(0, 0, 1);
	
		std::cout << "Enabled light " << n << "\n";
		_light_sources.push_back(l);
	}
	else
		Logger::print("Error: tried to create lights but all lights are used");
	return l;
}

void GameManager::deleteLight(LightSource * light)
{
	std::cout << "Deleting light " << light->getNum();
	_light_pool.push_back(light->getNum());
	glDisable(light->getNum());
	delete light;
}

GLboolean GameManager::wireframe()
{
	return _wireframe;
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
