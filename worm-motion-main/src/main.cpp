#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

#include "Headers/Control.hpp"
#include "Headers/Spring.hpp"
#include "Headers/Segment.hpp"
#include "Headers/Worm.hpp"

using namespace std;

int lastX = 0, lastY = 0;
bool left = false, right = false;

Control control = Control();

/**
 * @brief control the worm with the help of mouse
*/
void mouse(int button, int state, int x, int y)
{
    control.mouse(button, state, x, y);
}

/**
 * @brief control the motion of the mouse
*/
void motion(int x, int y)
{
    control.motion(x, y);
}

Worm *worm;

/**
 * @brief used to display the worm on the screen
 * 
 * @return used to render the worm and update its position on the screen
*/
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(
        control.zoom * control.cameraDistance * sin(control.cameraAngleY),
        control.zoom * control.cameraDistance * sin(control.cameraAngleX),
        control.zoom * control.cameraDistance * cos(control.cameraAngleY) + control.tZ,
        control.tX, control.tY, control.tZ,
        0.0, 0.1, 0.0);

    worm->draw();
    worm->update(0.001);

    glScalef(2.0, 2.0, 2.0);

    glutSwapBuffers();
}

/**
 * @brief   used to reshape the screen
 */
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * @brief  to create the window,set the window size and the background color
 */
void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Snake Simulation");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
}

/**
 * @brief main function
 *
 * @return used to call the worm function and render a screen
 */
int main(int argc, char **argv)
{
    worm = new Worm(5, 10.0, -40.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    glutInit(&argc, argv);
    init();

    glutMainLoop();
    return 0;
}
