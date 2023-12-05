#include "Headers/Spring.hpp"

Spring::Spring()
{
}
/**
 * @param m1 and m2 are the masses
 * 
 * @brief constructor for the spring class
*/
Spring::Spring(Mass *_m1, Mass *_m2)
{
    k = 1;
    l = 1;
    m1 = _m1;
    m2 = _m2;
}
