#include "GL/glut.h"
#include <iostream>
#include <cmath>

#include "Headers/Segment.hpp"

using namespace std;

/**
 * @param size,x,y,z and the change in these positions over time of the segment
 * 
 * @brief the main logic behind making each segment of the worm with spring and masses
*/
Segment::Segment(GLfloat size, GLfloat x, GLfloat y, GLfloat z, GLfloat dX, GLfloat dY, GLfloat dZ)
{

    for (int i = 0; i <= 1; ++i)
    {
        for (int j = 0; j <= 1; ++j)
        {
            for (int k = 0; k <= 1; ++k)
            {
                GLfloat X = x + static_cast<GLfloat>(i * (size)) + static_cast<GLfloat>(size * dX);
                GLfloat Y = y + static_cast<GLfloat>(j * (size)) + static_cast<GLfloat>(size * dY);
                GLfloat Z = z + static_cast<GLfloat>(k * (size)) + static_cast<GLfloat>(size * dZ);

                masses.push_back(new Mass(X, Y, Z));
            }
        }
    }
    // cout << masses.size();
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            springs.push_back(new Spring(masses[i], masses[j]));
        }
    }
}

/***
 * @param none
 * 
 * @brief The function is used to draw each segment of the worm
 * 
 * @return used to render each segment of the worm on the screen
*/
void Segment::draw()
{
    glBegin(GL_POINTS);
    for (auto mass : masses)
    {
        // glVertex3f(mass.x, mass.y, mass.z);
        glPushMatrix();
        glTranslatef(mass->x, mass->y, mass->z);
        glutSolidCube(1.00f);
        glPopMatrix();
    }
    glEnd();
    glBegin(GL_LINES);
    for (auto spring : springs)
    {
        glVertex3f(spring->m1->x, spring->m1->y, spring->m1->z);
        glVertex3f(spring->m2->x, spring->m2->y, spring->m2->z);
    }
    glEnd();
}

/***
 * @param - change in time
 * 
 * @brief The function is used to change the forces acting on the springs and masses
*/
void Segment::computeSpringForces(GLfloat dt)
{
    for (auto spring : springs)
    {
        GLfloat dX = spring->m2->x - spring->m1->x;
        GLfloat dY = spring->m2->y - spring->m1->y;
        GLfloat dZ = spring->m2->z - spring->m1->z;

        GLfloat d = sqrt(dX * dX + dY * dY + dZ * dZ);

        GLfloat f = spring->k * (d - spring->l);

        GLfloat fX = f * (dX / d);
        GLfloat fY = f * (dY / d);
        GLfloat fZ = f * (dZ / d);

        spring->m1->update(dt, fX, fY, fZ);
        spring->m2->update(dt, -fX, -fY, -fZ);
    }
}

/***
 * @param - change in time
 * 
 * @brief The function is used to update the mass of each segment of the worm
*/
void Segment::update(GLfloat dt)
{
    computeSpringForces(dt);
    for (auto mass : masses)
    {
        mass->update(dt, 10000);
    }
}
