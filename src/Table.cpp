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
    GLfloat amb[4] = {0.15f,0.012f,0.0f,1.0f},
    diff[4] = {0.12f,0.08f,0.0f,1.0f},
    spec[4] = {0.0f,0.0f,0.0f,1.0f},
    shine = 80.0f;
    setMaterial(amb, diff, spec, shine);
    cube_size = 2;
}

Table::~Table()
{
}

void Table::render()
{
    /*
    glPushMatrix();
	 glTranslatef(0,- 79.9375,0);

    //cubo
     glColor3f(0, 0.6, 0);
     glPushMatrix();
      glScalef(150, 156.5f, 150);
      glutSolidCube(1);
     glPopMatrix();
    glPopMatrix();
    */
	glColor3f(0.0,0.6,0.0);
    glTranslatef(-75, -3, -75);
    for(int u = -75; u < 75; u=u+cube_size)
    {
        glTranslatef(cube_size, 0, 0);
        for(int i = -75; i < 75; i=i+cube_size)
        {
            glTranslatef(0, 0, cube_size);
            glutSolidCube(cube_size);
        }
        glTranslatef(0, 0, -150);
    }
}

void Table::update(GLdouble delta_t) {
	//_position.set(_position._x - delta_t / 200.0, _position._y , _position._z - delta_t / 200.0);
}