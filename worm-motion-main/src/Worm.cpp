#include "Headers/Worm.hpp"
Worm::Worm()
{
}
/**
 * @param n is the number of segments along with x,y,z and the change in these positions over time of the segment
 *
 * @brief constructor for the worm class
 */
Worm::Worm(int n, GLfloat len, GLfloat x, GLfloat y, GLfloat z, GLfloat dX, GLfloat dY, GLfloat dZ)
{
    for (int i = 0; i < n; i++)
    {
        segments.push_back(new Segment(len, x, y, z, dX, dY, dZ));
        x += dX * len;
        y += dY * len;
        z += dZ * len;
    }
}

/**
 * @brief used to draw each segment of the worm
 *
 * @return used to render each segment of the worm on the screen
 */
void Worm::draw()
{
    for (auto segment : segments)
    {
        segment->draw();
    }
}

/**
 * @brief used to update each segment of the worm
 */
void Worm::update(GLfloat dt)
{
    for (auto segment : segments)
    {
        segment->update(dt);
    }
}