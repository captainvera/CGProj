//
//  Vector3.h
//  CGProj
//

#ifndef __CGProj__Vector3__
#define __CGProj__Vector3__

#include "Common.h"

class Vector3 {
private:
    GLdouble _x, _y, _z;
public:
    Vector3();
    Vector3(GLdouble x, GLdouble y, GLdouble z);
    ~Vector3();
    
    GLdouble getX() const;
    GLdouble getY() const;
    GLdouble getZ() const;
    
	void set(GLdouble x, GLdouble y, GLdouble z);
    Vector3 operator=(const Vector3& vec);
    Vector3 operator+(const Vector3& vec);
    Vector3 operator-(const Vector3& vec);
    Vector3 operator*(double d);
};
#endif /* defined(__CGProj__Vector3__) */
