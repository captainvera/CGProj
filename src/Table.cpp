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
    
    //cubo
    glColor3f(0, 0.6, 0);
    glPushMatrix();
     glTranslatef(0, -78.9375, 0);
     glScalef(150, 150, 150);
     glutSolidCube(1);
    glPopMatrix();
    
    glPopMatrix();
    
}
