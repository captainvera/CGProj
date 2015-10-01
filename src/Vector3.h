//
//  Vector3.h
//  CGProj
//

#ifndef __CGProj__Vector3__
#define __CGProj__Vector3__

#include "Common.h"

class Vector3 {
private:
public:
	GLdouble _x, _y, _z;
	Vector3();
    Vector3(GLdouble x, GLdouble y, GLdouble z);
    ~Vector3();
    
	GLdouble getX() ;
    GLdouble getY() ;
    GLdouble getZ() ;
    
	void set(GLdouble x, GLdouble y, GLdouble z);
    Vector3 operator=(const Vector3& vec);
    Vector3 operator+(const Vector3& vec);
    Vector3 operator-(const Vector3& vec);
    Vector3 operator*(double d);

	static Vector3* normalize(Vector3* v);
	static Vector3* crossProduct(Vector3* v1, Vector3* v2);
};
#endif /* defined(__CGProj__Vector3__) */
