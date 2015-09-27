//
//  Vector3.h
//  CGProj
//
//  Created by João Vicente on 25/09/15.
//  Copyright (c) 2015 João Vicente. All rights reserved.
//

#ifndef __CGProj__Vector3__
#define __CGProj__Vector3__

#include "Common.h"

class Vector3 { 
    GLdouble _x, _y, _z;
    
    public: Vector3();
    public: Vector3(GLdouble x, GLdouble y, GLdouble z);
    public: ~Vector3();
    
    public: GLdouble getX() const;
    public: GLdouble getY() const;
    public: GLdouble getZ() const;
    
    public: void set(GLdouble x, GLdouble y, GLdouble z);
    public: Vector3 operator=(const Vector3& vec);
    public: Vector3 operator+(const Vector3& vec);
    public: Vector3 operator-(const Vector3& vec);
    public: Vector3 operator*(double d);
};
#endif /* defined(__CGProj__Vector3__) */
