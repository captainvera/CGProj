//
//  Butter.cpp
//  CGProj
//

#include "Butter.h"

Butter::Butter()
{
}

Butter::Butter(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:Obstacle(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{
}

Butter::~Butter()
{
}

void Butter::render()
{
    glPushMatrix();
     glTranslated(0,-0.3f, 0);
     glScalef(1.5f, 1.5f, 1.5f);
    //Body
     glPushMatrix();
      glColor3f(1, 1, 0.67f);
      glScalef(3.0f,1.0f,1.5f);
      glutSolidCube(1);
     glPopMatrix();
	 //Droplet 1
     glPushMatrix();
      glTranslatef(1.5f, -0.25f, 0.2f);
      glutSolidSphere(0.5f, 16, 16);
    //Droplet 2
      glPushMatrix();
       glTranslatef(0.4f, -0.1f,0.5f);
       glutSolidSphere(0.4f, 16, 16);
    //Droplet3
       glPushMatrix();
        glTranslatef(0.25f, -0.05f,0.25f);
        glutSolidSphere(0.3f, 16, 16);
       glPopMatrix();

      glPopMatrix();

     glPopMatrix();
    
    glPopMatrix();
    
}
