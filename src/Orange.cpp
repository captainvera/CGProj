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
	glTranslatef(_position.getX(), _position.getY()+0.2, _position.getX());
	glRotatef(_rotangle, _rotation.getX(), _rotation.getY(), _rotation.getZ());
	glScalef(_scale.getX(), _scale.getY(), _scale.getX());
	 glPushMatrix();
	  glColor3f(0.85f, 0.53f, 0.1f);
	  glutSolidSphere(1, 16, 16);
	  
	 glPopMatrix();

	 glPushMatrix();
	  glColor3f(0.2f,0.0f,0.0f);
	  glTranslatef(0.5f, 0.8f, 0.0f);
	  glRotatef(-30, 0, 0, 1);
	  glScalef(0.15, 0.7f, 0.15);
	  
	  glutSolidCube(1);
	 glPopMatrix();
	 
	 
	glPopMatrix();
   

    
}


