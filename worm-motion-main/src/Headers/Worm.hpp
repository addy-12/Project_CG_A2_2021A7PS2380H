#pragma once
#include <vector>
#include "GL/glut.h"

#include "Segment.hpp"

using namespace std;

class Worm
{

public:
    vector<Segment *> segments;
    Worm();
    Worm(int n, GLfloat size, GLfloat x, GLfloat y, GLfloat z, GLfloat dX, GLfloat dY, GLfloat dZ);
    void draw();
    void update(GLfloat dt);
};