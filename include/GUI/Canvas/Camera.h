#ifndef _BRUNDOEA_CG_T3_CAMERA_H_
#define _BRUNDOEA_CG_T3_CAMERA_H_

#include "Core/matrix_functions.h"

namespace CANVAS
{
    class Camera
    {
    public:
        Camera() : m_vEye(0), m_vCenter(0), m_vUp(0)
        {}
        

        void lookAt(float eyex, float eyey, float eyez, 
                    float centerx, float centery, float centerz, 
                    float upx, float upy, float upz);
        inline void lookAt(const Core::Vector3 &eye, const Core::Vector3 &center, const Core::Vector3 &up)
        {
            m_vEye = eye;
            m_vCenter = center;
            m_vUp = up;
        }

    private:
        Core::Vector3 m_vEye;
        Core::Vector3 m_vCenter;
        Core::Vector3 m_vUp;

    }; //end of Camera.
} //end of namespace CANVAS.

#endif
