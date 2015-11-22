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
    _cube_size = 2;

	int width, height, channels;
	GLubyte* texture = SOIL_load_image("D:\\IST\\3_Ano\\CG\\Simple OpenGL Image Library\\img_cheryl.jpg", &width, &height, &channels, SOIL_LOAD_RGBA);

	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);
	SOIL_free_image_data(texture);
}

Table::~Table()
{
}

void Table::render()
{

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texName);
    
    /*glPushMatrix();
	 glTranslatef(0,- 79.9375,0);

    //cubo
     glColor3f(0, 0.6, 0);
     glPushMatrix();
      glScalef(150, 156.5f, 150);
      glutSolidCube(1);
     glPopMatrix();
    glPopMatrix();
    */

	glColor3f(0.30,0.15,0.0);
    glTranslatef(-75, -_cube_size*1.5, -75);
    for(int u = -75; u < 75; u=u+_cube_size)
    {
        glTranslatef(_cube_size, 0, 0);
        for(int i = -75; i < 75; i=i+_cube_size)
        {
            glTranslatef(0, 0, _cube_size);
            SolidCubeTable(_cube_size);
        }
        glTranslatef(0, 0, -150);
    }
}

void Table::update(GLdouble delta_t) {
	//_position.set(_position._x - delta_t / 200.0, _position._y , _position._z - delta_t / 200.0);
}

void Table::drawBoxTable(GLfloat size, GLenum type)
{
	static GLfloat n[6][3] =
	{
		{ -1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 1.0, 0.0, 0.0 },
		{ 0.0, -1.0, 0.0 },
		{ 0.0, 0.0, 1.0 },
		{ 0.0, 0.0, -1.0 }
	};
	static GLint faces[6][4] =
	{
		{ 0, 1, 2, 3 },
		{ 3, 2, 6, 7 },
		{ 7, 6, 5, 4 },
		{ 4, 5, 1, 0 },
		{ 5, 6, 2, 1 },
		{ 7, 4, 0, 3 }
	};
	GLfloat v[8][3];
	GLint i;

	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

	for (i = 5; i >= 0; i--) {
		
			glBegin(type);
			glNormal3fv(&n[i][0]);
			glTexCoord2f(0, 0);
			glVertex3fv(&v[faces[i][0]][0]);
			glTexCoord2f(0, 1);
			glVertex3fv(&v[faces[i][1]][0]);
			glTexCoord2f(1, 1);
			glVertex3fv(&v[faces[i][2]][0]);
			glTexCoord2f(1, 0);
			glVertex3fv(&v[faces[i][3]][0]);
			glEnd();
	}
}

void Table::SolidCubeTable(GLdouble size)
{
	drawBoxTable(size, GL_QUADS);
}