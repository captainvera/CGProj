//
//  Table.cpp
//  CGproj
//

#include "Table.h"
#include "Logger.h"

Table::Table()
{
}

Table::~Table()
{
}

void Table::draw()
{
    glPushMatrix();
	 glTranslatef(_position.getX(), _position.getY() - 78.9375, _position.getX());
	 glRotatef(_rotangle, _rotation.getX(), _rotation.getY(), _rotation.getZ());
	 glScalef(_scale.getX(), _scale.getY(), _scale.getX());
    //cubo
     glColor3f(0, 0.6, 0);
     glPushMatrix();
      glScalef(150, 156.5f, 150);
      glutSolidCube(1);
     glPopMatrix();
    
    glPopMatrix();
    
}
