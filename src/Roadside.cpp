//
//  Roadside.cpp
//  CGproj
//

#include "Roadside.h"
#include "Logger.h"

Roadside::Roadside()
{
    Vector3* p0 = new Vector3(-10,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(0,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(0,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(10,0,-10);
    _controlPoints.push_back(*p0);
    
    p0 = new Vector3(10,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(20,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(20,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(20,0,5);
    _controlPoints.push_back(*p0);
    
    p0 = new Vector3(20,0,5);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(15,0,20);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(5,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(0,0,5);
    _controlPoints.push_back(*p0);
    
    p0 = new Vector3(0,0,5);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(0,0,10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(0,0,10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(-10,0,10);
    _controlPoints.push_back(*p0);
    
    p0 = new Vector3(-10,0,10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(-20,0,10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(-20,0,-10);
    _controlPoints.push_back(*p0);
    p0 = new Vector3(-10,0,-10);
    _controlPoints.push_back(*p0);
    
    drawBezierPath();
    calculatePerpendicularPoints();
    
    printf("Number of Cheerios Spawned: %lu\n",_inside.size()+_outside.size());
}

Roadside::~Roadside()
{
}

void Roadside::draw()
{
    for(int i = 0; i < _spawnedCheerios.size()-1; i++)
    {
        spawnCheerio(_inside[i].getX()*2, _inside[i].getZ()*2);
        spawnCheerio(_outside[i].getX()*2, _outside[i].getZ()*2);
    }
    
}

void Roadside::spawnCheerio(double x, double z)
{
    glColor3f(1, 1, 0.4);
    glPushMatrix();
        glTranslatef(x, 0, z);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(0.5,0.5,0.5);
        glutSolidTorus(0.4,0.9,3,12);
    glPopMatrix();
}

Vector3 Roadside::calculateBezierPoint(float t,Vector3 p0, Vector3 p1, Vector3 p2, Vector3 p3)
{
    float u = (1-t);
    float tt = t*t;
    float uu = u*u;
    float uuu = uu * u;
    float ttt = tt * t;
    Vector3 p = *new Vector3();
    p = p0 * uuu; //first term
    p = p + (p1 * (3 * uu * t)); //second term
    p = p + (p2 * (3 * u * tt)); //third term
    p = p + (p3 * ttt); //fourth term
    
    
    return p;
}


void Roadside::drawBezierPath()
{
    int max = 10;
    for(int i = 0; i < _controlPoints.size() - 3; i+=4)
    {
        Vector3 p0 = _controlPoints[i];
        Vector3 p1 = _controlPoints[i + 1];
        Vector3 p2 = _controlPoints[i + 2];
        Vector3 p3 = _controlPoints[i + 3];
        
        if(i == 0) //Only do this for the first endpoint. When i != 0, this coincides with the end point of the previous segment
        {
            _spawnedCheerios.push_back(calculateBezierPoint(0, p0, p1, p2, p3));
        }
        
        for(int j = 1; j <= max; j++)
        {
            float t = j / (float) max;
            _spawnedCheerios.push_back(calculateBezierPoint(t, p0, p1, p2, p3));
        }
    }
}

void Roadside::calculatePerpendicularPoints()
{
    double angle1, angle2;
    float pi = M_PI;
	Vector3 normal;
    
    for(int i = 0; i < _spawnedCheerios.size(); i++)
    {
        if (i == 0)
        {
            angle1 = (atan2(_spawnedCheerios[i+1].getX()-_spawnedCheerios[_spawnedCheerios.size()-1].getX(), _spawnedCheerios[i+1].getZ()-_spawnedCheerios[_spawnedCheerios.size()-1].getZ()) + pi/2);
            
            angle2 = (atan2(_spawnedCheerios[i+1].getX()-_spawnedCheerios[_spawnedCheerios.size()-1].getX(), _spawnedCheerios[i+1].getZ()-_spawnedCheerios[_spawnedCheerios.size()-1].getZ()) - pi/2);
            
            normal = Vector3(_spawnedCheerios[i].getX()+2*sin(angle1),0,_spawnedCheerios[i].getZ()+2*cos(angle1));
            _outside.push_back(normal);
            normal = Vector3(_spawnedCheerios[i].getX()+2*sin(angle2),0,_spawnedCheerios[i].getZ()+2*cos(angle2));
            _inside.push_back(normal);
            
		}
		else if (i == (_spawnedCheerios.size()-1)) {
        
			angle1 = (atan2(_spawnedCheerios[0].getX()-_spawnedCheerios[i-1].getX(), _spawnedCheerios[0].getZ()-_spawnedCheerios[i-1].getZ()) + pi/2);
        
			angle2 = (atan2(_spawnedCheerios[0].getX()-_spawnedCheerios[i-1].getX(), _spawnedCheerios[0].getZ()-_spawnedCheerios[i-1].getZ()) - pi/2);
        
			normal = Vector3(_spawnedCheerios[i].getX()+2*sin(angle1),0,_spawnedCheerios[i].getZ()+2*cos(angle1));
			_outside.push_back(normal);
			normal = Vector3(_spawnedCheerios[i].getX()+2*sin(angle2),0,_spawnedCheerios[i].getZ()+2*cos(angle2));
				_inside.push_back(normal);
		}
		else {
			angle1 = (atan2(_spawnedCheerios[i + 1].getX() - _spawnedCheerios[i - 1].getX(), _spawnedCheerios[i + 1].getZ() - _spawnedCheerios[i - 1].getZ()) + pi / 2);

			angle2 = (atan2(_spawnedCheerios[i + 1].getX() - _spawnedCheerios[i - 1].getX(), _spawnedCheerios[i + 1].getZ() - _spawnedCheerios[i - 1].getZ()) - pi / 2);

			normal = Vector3(_spawnedCheerios[i].getX() + 2 * sin(angle1), 0, _spawnedCheerios[i].getZ() + 2 * cos(angle1));
			_outside.push_back(normal);
			normal = Vector3(_spawnedCheerios[i].getX() + 2 * sin(angle2), 0, _spawnedCheerios[i].getZ() + 2 * cos(angle2));
			_inside.push_back(normal);
		}
    }
}