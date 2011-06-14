#ifndef _BRUNODEA_PROJECTION_FUNCTIONS_HPP_
#define _BRUNODEA_PROJECTION_FUNCTIONS_HPP_

#include "Core/matrix_functions.hpp"
#include <cmath>

namespace PROJECTION
{
    inline Core::Matrix4 perpective(float fovy, float aspect, float zNear, float zFar)
    {
        Core::Matrix4 res(0);
        float f = (float)1.f/tan(fovy/2.f); //cotangent

        res.set(f/aspect,0,0);
        res.set(f,1,1);
        res.set((zFar+zNear)/(zNear-zFar),2,2);
        res.set(-1,3,2);
        res.set((2*zFar*zNear)/(zNear-zFar),2,3);

        return res;
    }
}

#endif
