#include <GL/glut.h>

class Control
{
public:
    GLint mouseX, mouseY;
    GLfloat panX = 0.0f, panY = 0.0f;
    GLfloat cameraAngleX = 0.0f;
    GLfloat cameraAngleY = 0.0f;
    GLfloat cameraDistance = 100.0f;
    GLfloat zoom = 1.0f;
    GLfloat tX = 0.0f;
    GLfloat tY = 0.0f;
    GLfloat tZ = 0.0f;

    bool left = false;
    bool middle = false;

    void mouse(int button, int state, int x, int y);
    void motion(int x, int y);
    void mouseWheel(int wheel, int direction, int x, int y);
};