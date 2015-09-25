//
//  Vector3.h
//  CGProj
//
//  Created by João Vicente on 25/09/15.
//  Copyright (c) 2015 João Vicente. All rights reserved.
//

#ifndef __CGProj__Vector3__
#define __CGProj__Vector3__

#include <stdio.h>
#include "Common.h"

class Vector3 { 
    GLdouble _x, _y, _z;
    
    Vector3();
    Vector3(GLdouble x, GLdouble y, GLdouble z);
    
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
