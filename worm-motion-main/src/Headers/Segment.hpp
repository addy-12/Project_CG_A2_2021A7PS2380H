#pragma once

#include <vector>

#include "Spring.hpp"
#include "Mass.hpp"

using namespace std;

class Segment
{
public:
    vector<Spring *> springs;
    vector<Mass *> masses;

    Segment(GLfloat size, GLfloat x, GLfloat y, GLfloat z, GLfloat dX, GLfloat dY, GLfloat dZ);
    Segment(int i, GLfloat cubeSize = 1.0f);
    void draw();
    void update(GLfloat dt);
    void computeSpringForces(GLfloat dt);
};