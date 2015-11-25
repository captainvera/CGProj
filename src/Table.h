//
//  Table.h
//  CGproj
//

#ifndef __CGproj__Table__
#define __CGproj__Table__

#include "Common.h"
#include "StaticObject.h"

#define TEXTURE_PATH "..\\..\\..\\CGProj\\assets\\wood.jpg"

class Table : public StaticObject {
private:
    GLfloat _cube_size;
public:
    Table();
    Table(GLdouble posx, GLdouble posy, GLdouble posz,
           GLdouble rotangle=0, GLdouble rotx=0, GLdouble roty=0, GLdouble rotz=0,
           GLdouble scalex=1, GLdouble scaley=1, GLdouble scalez=1);
    ~Table();

    void render();
	void update(GLdouble delta_t);
	GLuint texture;
	//void static drawBoxTable(GLfloat size, GLenum type);
	//void SolidCubeTable(GLdouble size);
};


#endif /* defined(__CGproj__Table__) */
