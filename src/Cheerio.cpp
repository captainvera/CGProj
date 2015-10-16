#include "Cheerio.h"

Cheerio::Cheerio()
{
}

Cheerio::Cheerio(GLdouble posx, GLdouble posy, GLdouble posz,
	GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
	GLdouble scalex, GLdouble scaley, GLdouble scalez)
	:Obstacle(posx, posy, posz,
		rotangle, rotx, roty, rotz,
		scalex, scaley, scalez)
{

}


Cheerio::~Cheerio()
{
}

void Cheerio::draw()
{
	GameObject::draw();
	glColor3f(1, 1, 0.4);
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidTorus(0.4, 0.9, 4, 10);
	glPopMatrix();

}


