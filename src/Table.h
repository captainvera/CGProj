//
//  Table.h
//  CGproj
//

#ifndef __CGproj__Table__
#define __CGproj__Table__

#include "Common.h"
#include "StaticObject.h"

class Table : public StaticObject {
public:
    Table();
    Table(GLdouble posx, GLdouble posy, GLdouble posz,
           GLdouble rotangle=0, GLdouble rotx=0, GLdouble roty=0, GLdouble rotz=0,
           GLdouble scalex=1, GLdouble scaley=1, GLdouble scalez=1);
    ~Table();

    void render();
	void update(GLdouble delta_t);
};


#endif /* defined(__CGproj__Table__) */
