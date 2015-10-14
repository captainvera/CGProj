//
//  Butter.cpp
//  CGProj
//

#include "Butter.h"

Butter::Butter()
{
}

Butter::~Butter()
{
}

void Butter::draw()
{
    glPushMatrix();
     glTranslatef(0,-1,0);
     glPushMatrix();
      glColor3f(1, 1, 0.67f);
      glScalef(3.0f,1.0f,1.5f);
      glutSolidCube(1);
     glPopMatrix();
    
     glPushMatrix();
      glTranslatef(1.5f, -0.25f, 0.2f);
      glutSolidSphere(0.5f, 16, 16);
      glPushMatrix();
       glTranslatef(0.4f, 0,0.5f);
       glutSolidSphere(0.4f, 16, 16);
       glPushMatrix();
        glTranslatef(0.25f, 0,0.25f);
        glutSolidSphere(0.3f, 16, 16);
       glPopMatrix();
      glPopMatrix();
     glPopMatrix();
    
    glPopMatrix();
    
}
