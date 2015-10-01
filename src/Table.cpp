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

void Table::draw(){
    
    glPushMatrix();
    
    //cubo
    glColor3f(0, 0.6, 0);
    glPushMatrix();
     glTranslatef(0, -53.9375, 0);
     glScalef(100, 100, 100);
     glutSolidCube(1);
    glPopMatrix();
    
    glPopMatrix();
    
}
