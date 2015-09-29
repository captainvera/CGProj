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
        for (int t = 0;t < 360;t += 3){
            z = 40*cos(t);
            x = 40*sin(t);
            glColor3f(0, 1, 0);
            spawnCheerio(x, z);
        
        }
    glPopMatrix();
    
}

void Roadside::spawnCheerio(int x, int z){
    glPushMatrix();
	   glTranslatef(x, 0, z);
	   glScalef(1.5,1.5,1.5);
	   glutSolidTorus(0.5,1,12,15);
    glPopMatrix();
}