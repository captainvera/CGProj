//
//  Orange.cpp
//  CGProj
//

#include "Orange.h"

Orange::Orange()
{
}

Orange::~Orange()
{
}

void Orange::draw()
{
	glPushMatrix();
	 
	 glPushMatrix();
	  glColor3f(0.85f, 0.53f, 0.1f);
	  glutSolidSphere(1, 16, 16);
	  
	 glPopMatrix();

	 glPushMatrix();
	  glColor3f(0.2f,0.0f,0.0f);
	  /*
	  glLineWidth(5);
	  glBegin(GL_LINES);
	  glVertex3f(0.0f, 1, 0.0f);
	  glVertex3f(0.4f, 1.35, 0.0f);
	  glEnd();
	  glLineWidth(1);
	  */
	  glTranslatef(0.5f, 0.8f, 0.0f);
	  glRotatef(-30, 0, 0, 1);
	  glScalef(0.15, 0.7f, 0.15);
	  
	  glutSolidCube(1);
	 glPopMatrix();
	 
	 
	glPopMatrix();
   

    
}


