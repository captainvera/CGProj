//
//  Orange.cpp
//  CGProj
//

#include "Orange.h"

Orange::Orange()
{
}

Orange::Orange(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Obstacle(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{
}


Orange::~Orange()
{
}

void Orange::draw()
{
    GameObject::draw();
	glPushMatrix();
	glTranslatef(0,0.2, 0);
    glScalef(2, 2, 2);
    
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


