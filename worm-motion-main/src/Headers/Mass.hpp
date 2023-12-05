#pragma once

#include <GL/glut.h>

class Mass
{
public:
    GLfloat x, y, z;
    GLfloat vX, vY, vZ;
    Mass(GLfloat _x, GLfloat _y, GLfloat _z);
    void update(GLfloat dt, GLfloat aX = 0.0f, GLfloat aY = 0.0f, GLfloat aZ = 0.0f);
};