#include "GUI/Canvas/Camera.h"
#include "Core/matrix_functions.hpp"

using namespace CANVAS;

void Camera::lookAt(float eyex, float eyey, float eyez, 
                    float centerx, float centery, float centerz, 
                    float upx, float upy, float upz)
{
    Core::Vector3 eye;
    eye[0] = eyex;
    eye[1] = eyey;
    eye[2] = eyez;

    Core::Vector3 center;
    center[0] = centerx;
    center[1] = centery;
    center[2] = centerz;

    Core::Vector3 up;
    up[0] = upx;
    up[1] = upy;
    up[2] = upz;

    lookAt(eye, center, up);
}
