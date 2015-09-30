//
//  Roadside.cpp
//  CGproj
//

#include "Roadside.h"
#include "Logger.h"

Roadside::Roadside()
{
}

Roadside::~Roadside()
{
}

void Roadside::draw(){
    double x, z;
    
    glPushMatrix();
        for (int t = 1;t < 360;t += 9){
            z = 40*cos(t);
            x = 40*sin(t);
            glColor3f(0, 1, 0);
            spawnCheerio(x, z);
        
        }
    glPopMatrix();
    
    glPushMatrix();
    for (int t = 1;t < 360;t += 9){
        z = 30*cos(t);
        x = 30*sin(t);
        glColor3f(0, 1, 0);
        spawnCheerio(x, z);
        
    }
    glPopMatrix();
    
}

void Roadside::spawnCheerio(int x, int z){
    glColor3f(1, 1, 0.4);
    glPushMatrix();
        glTranslatef(x, 0, z);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(1,1,1);
        glutSolidTorus(0.4,1,12,15);
    glPopMatrix();
}