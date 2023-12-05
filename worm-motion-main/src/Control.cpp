#include "Headers/Control.hpp"

/***
 * @param button, state, x and y coordinate of the mouse
 * 
 * @brief function to handle the mouse click
*/
void Control::mouse(int button, int state, int x, int y)
{

    if (button == 4)
    {
        zoom *= 1.01f;
    }
    else if (button == 3)
    {
        zoom /= 1.01f;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseX = x;
        mouseY = y;
    }

    if (button == GLUT_LEFT_BUTTON)
    {
        left = (state == GLUT_DOWN);
    }
    else if (button == GLUT_MIDDLE_BUTTON)
    {
        middle = (state == GLUT_DOWN);
    }
}

/***
 * @param x and y corrdiantes of the particle
 * 
 * @brief updating the motion of the particle by click of the mouse
*/
void Control::motion(int x, int y)
{
    GLfloat dX = x - mouseX;
    GLfloat dY = y - mouseY;

    if (left)
    {
        cameraAngleY += dX * 0.01f;
        cameraAngleX += dY * 0.01f;
    }
    else if (middle)
    {
        tX -= dX * 0.01f;
        tY += dY * 0.01f;
    }

    mouseX = x;
    mouseY = y;

    glutPostRedisplay();
}

/***
 * @param x and y corrdiantes of the particle
 * 
 * @brief controlling the motion of the particle by scroll of the mouse
*/
void Control::mouseWheel(int wheel, int direction, int x, int y)
{
    if (direction > 0)
    {
        zoom *= 1.1f;
    }
    else
    {
        zoom /= 1.1f;
    }

    glutPostRedisplay();
}