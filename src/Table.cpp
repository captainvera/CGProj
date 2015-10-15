//
//  Table.cpp
//  CGproj
//

#include "Table.h"
#include "Logger.h"

Table::Table()
{
}

Table::Table(GLdouble posx, GLdouble posy, GLdouble posz,
               GLdouble rotangle, GLdouble rotx, GLdouble roty, GLdouble rotz,
               GLdouble scalex, GLdouble scaley, GLdouble scalez)
:StaticObject(posx, posy, posz,
          rotangle, rotx, roty, rotz,
          scalex, scaley, scalez)
{
}

Table::~Table()
{
}

void Table::draw()
{
    GameObject::draw();
    
    glPushMatrix();
	 glTranslatef(0,- 78.9375,0);

    //cubo
     glColor3f(0, 0.6, 0);
     glPushMatrix();
      glScalef(150, 156.5f, 150);
      glutSolidCube(1);
     glPopMatrix();
    
    glPopMatrix();
    
}
