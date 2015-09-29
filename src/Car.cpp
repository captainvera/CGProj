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

	

	glPushMatrix();

	 //cubo1
	 glColor3f(0.33, 0.2, 0.15);
	 glPushMatrix();
	  glTranslatef(0, 0, 0);
	  glScalef(14, 3, 8);
	  glutSolidCube(1);
	 glPopMatrix();
  
	 //cubo2
	 glColor3f(0.20, 0.21, 0.22);
	 glPushMatrix();
	  glTranslatef(-3.5, 3.5, 0);
	  glScalef(7, 4, 8);
	  glutSolidCube(1);
	 glPopMatrix();
 
	 //cubo3
	 glColor3f(0.37, 0.34, 0-.33);
	 glPushMatrix();
	  glTranslatef(2.5, 2.5, 0);
	  glScalef(5, 2, 4);
	  glutSolidCube(1);
	 glPopMatrix();

	 //rodas frente
	 glColor3f(0, 0, 0);
	 glPushMatrix();
	  glPushMatrix();
	   glTranslatef(4, -1.5, -4.5);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.7,1,12,15);
	  glPopMatrix();
	  glPushMatrix();
	   glTranslatef(4, -1.5, 4.5);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.7,1,12,15);
	  glPopMatrix();
	 glPopMatrix();

	//rodas trás
	 glColor3f(0, 0, 0);
	 glPushMatrix();
	  glPushMatrix();
	   glTranslatef(-5.5, -0.75, -5);
	   glScalef(2.25, 2.25, 2);
	   glutSolidTorus(0.6, 1, 12, 15);
	  glPopMatrix();
	  glPushMatrix();
	   glTranslatef(-5.5, -0.75, 5);
	   glScalef(2.25, 2.25, 2);
	   glutSolidTorus(0.6, 1, 12, 15);
	  glPopMatrix();
	 glPopMatrix();
	glPopMatrix();

}


