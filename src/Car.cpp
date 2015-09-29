//
//  Car.cpp
//  CGProj
//

#include "Car.h"
#include "Logger.h"

Car::Car()
{
}

Car::~Car()
{
}
int t = 0;
void Car::draw()
{
	glColor3f(1, 0, 0);
	if (t < 100) {
		glPushMatrix();
		glTranslatef(1, 1, 1);
		glutSolidCube(1);
		glPopMatrix();
	}else if (t < 200) {
		glPushMatrix();
		glTranslatef(-1, -1, -1);
		glutSolidCube(1);
		glPopMatrix();
	}else if (t < 300) {
		glPushMatrix();
		glTranslatef(-1, 1, -1);
		glutSolidCube(1);
		glPopMatrix();
	}
	else if( t < 400){
		glPushMatrix();
		glTranslatef(1, -1, 1);
		glutSolidCube(1);
		glPopMatrix();
	}
	else {
		t = 0;
	}
	t++;
}
