//
//  Table.h
//  CGproj
//

#ifndef __CGproj__Table__
#define __CGproj__Table__

#include "Common.h"
#include "StaticObject.h"
#include "SOIL.h";

#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLuint texName;

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
	void static drawBoxTable(GLfloat size, GLenum type);
	void SolidCubeTable(GLdouble size);
};


#endif /* defined(__CGproj__Table__) */
