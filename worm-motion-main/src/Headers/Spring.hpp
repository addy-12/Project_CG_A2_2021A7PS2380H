#pragma once

#include "Mass.hpp"

class Spring
{
public:
    GLfloat k;
    GLfloat l;
    Mass *m1;
    Mass *m2;
    Spring();
    Spring(Mass *_m1, Mass *_m2);
};