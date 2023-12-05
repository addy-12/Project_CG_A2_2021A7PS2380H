#include <iostream>

#include "Headers/Mass.hpp"

using namespace std;

/***
 * @param x,y and z coordinate of the mass
 * 
 * @brief constructor for the mass class
*/
Mass::Mass(GLfloat _x, GLfloat _y, GLfloat _z)
{
    x = _x;
    y = _y;
    z = _z;

    vX = 0.0f;
    vY = 0.0f;
    vZ = 0.0f;
}

/***
 * @param x,y and z coordinate of the mass
 * 
 * @brief updating the mass of the object
*/
void Mass::update(GLfloat dt, GLfloat aX, GLfloat aY, GLfloat aZ)
{

    vX = aX * dt;
    vY += aY * dt;
    vZ += aZ * dt;
    // cout << aX << endl;
    // cout << dt << endl;

    x += vX * dt;
    y += vY * dt;
    z += vZ * dt;

    // cout << vX << ' ' << vY << ' ' << vZ << endl;
    // cout << x << ' ' << y << ' ' << z << endl;
}