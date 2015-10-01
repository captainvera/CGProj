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

void Roadside::draw()
{
    /*int x, z;
    
    glPushMatrix();
        for (int t = 1;t < 340;t += 9){
            z = 50*cos(t);
            x = 35*sin(t);
            spawnCheerio(x, z);
        
        }
    glPopMatrix();
    
    glPushMatrix();
    for (int t = 1;t < 330;t += 9){
        z = 40*cos(t);
        x = 25*sin(t);
        spawnCheerio(x, z);
        
    }
    glPopMatrix();*/
    
    float t;
    Vector3* p0 = new Vector3(-1,0,1);
    Vector3* p1 = new Vector3(-1.5,0,-1.5);
    Vector3* p2 = new Vector3(2.0,0,-2.0);
    Vector3* p3 = new Vector3(1.0,0,1.0);
    
    drawBezier(t, p0, p1, p2, p3);
    
}

void Roadside::spawnCheerio(double x, double z)
{
    glColor3f(1, 1, 0.4);
    glPushMatrix();
        glTranslatef(x, 0, z);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(0.5,0.5,0.5);
        glutSolidTorus(0.4,1,12,15);
    glPopMatrix();
}

Vector3* Roadside::calculateBezierPoint(float t,Vector3* p0, Vector3* p1, Vector3* p2, Vector3* p3)
{
    double u = 1-t;
    double tt = t*t;
    double uu = u*u;
    double uuu = uu * u;
    double ttt = tt * t;
    
    Vector3* p = new Vector3();
    p = &(*p0 * uuu); //first term
    p = &(*p + (*p1 * (3 * uu * t))); //second term
    p = &(*p + (*p2 * (3 * u * tt))); //third term
    p = &(*p + (*p3 * ttt)); //fourth term
    
    return p;
}

void Roadside::drawBezier(float t,Vector3* p0, Vector3* p1, Vector3* p2, Vector3* p3)
{
    for(int i = 0; i <= 30; i++){
        t = i / 30;
        Vector3* point = calculateBezierPoint(t, p0, p1, p2, p3);
        spawnCheerio(point->getX(), point->getZ());
    }
}