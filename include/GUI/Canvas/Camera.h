#ifndef _BRUNDOEA_CG_T3_CAMERA_H_
#define _BRUNDOEA_CG_T3_CAMERA_H_

#include "Core/matrix_functions.hpp"
#include "macros.h"
#include <SCV/SCV.h>

namespace CANVAS
{
    class Camera
    {
    public:
        Camera() : m_vDirection3(0), m_vUp3(0), m_vEye3(0), m_vRight3(0), m_fSpeed(1.f)
        {
            m_vUp3[1] = 1.f;
            m_vEye3[2] = 1.f;
            m_vDirection3 = m_vDirection3 - m_vEye3;
            m_vRight3 = m_vDirection3.crossProduct(m_vUp3);
        }

        void lookAt(float eyex, float eyey, float eyez, 
                    float centerx, float centery, float centerz, 
                    float upx, float upy, float upz);
        inline void lookAt(const Core::Vector3 &eye, const Core::Vector3 &center, const Core::Vector3 &up)
        {
            m_vDirection3 = Core::normalize(eye - center);
            m_vUp3 = Core::normalize(up);
            Core::Vector3 perp = Core::normalize(m_vDirection3.crossProduct(m_vUp3));
            m_vUp3 = m_vDirection3.crossProduct(perp);
            m_vRight3 = perp;

            //Util::MODELVIEW->transform(transMatrix());
        }

        void rotate(float roll_angle, float yaw_angle, float pitch_angle)
        {
            Core::Matrix4 m = Core::rotateZ(pitch_angle)*Core::rotateY(yaw_angle)*Core::rotateX(roll_angle);
            transform(m);
        }

        void move(float factor_x, float factor_y, float factor_z)
        {
            m_vEye3[0] += factor_x;
            m_vEye3[1] += factor_y;
            m_vEye3[2] += factor_z;
        }

        void moveForward() { m_vEye3 -= m_vDirection3*m_fSpeed; }
        void moveBackwards() { m_vEye3 += m_vDirection3*m_fSpeed; }
        void moveLeft() { m_vEye3 -= m_vRight3*m_fSpeed; }
        void moveRight() { m_vEye3 += m_vRight3*m_fSpeed; }
        void moveUp() { m_vEye3 += m_vUp3*m_fSpeed; }
        void moveDown() { m_vEye3 -= m_vUp3*m_fSpeed; }

        Core::Vector3 getDirection() { return m_vDirection3; }
        void setDirection(Core::Vector3 &v) { m_vDirection3 = v; }

        Core::Vector3 getUp() { return m_vUp3; }
        void setUp(Core::Vector3 &v) { m_vUp3 = v; }

        Core::Vector3 getEye() { return m_vEye3; }
        void setEye(Core::Vector3 &v) { m_vEye3 = v; }

        Core::Vector3 getRight() { return m_vRight3; }

        void setSpeed(float speed) { m_fSpeed = speed; }

        Core::Matrix4 transMatrix()
        {
            Core::Matrix4 m = Core::identity<4>();
            for(int i = 0; i < 3; i++)
                m.set(m_vRight3[i],0,i);
            Core::Vector3 e = m_vEye3;
            m.set(-(m_vRight3.dotProduct(e)),0,3);

            for(int i = 0; i < 3; i++)
                m.set(m_vUp3[i],1,i);
            m.set(-(m_vUp3.dotProduct(e)),1,3);
            
            for(int i = 0; i < 3; i++)
                m.set(m_vDirection3[i],2,i);
            m.set(-(m_vDirection3.dotProduct(e)),2,3);

            return m;
        }
    private:
        void transform(const Core::Matrix4 &mat)
        {
            Core::Matrix4 m = mat;

            Core::Vector4 dir = Core::toVector4f(m_vDirection3);
            dir = m*dir;
            m_vDirection3 = Core::normalize(Core::toVector3f(dir));

            Core::Vector4 up = Core::toVector4f(m_vUp3);
            up = m*up;
            m_vUp3 = Core::normalize(Core::toVector3f(up));

            Core::Vector4 right = Core::toVector4f(m_vRight3);
            right = m*right;
            m_vRight3 = Core::normalize(Core::toVector3f(right));
        }

    private:
        Core::Vector3 m_vDirection3;
        Core::Vector3 m_vUp3;
        Core::Vector3 m_vEye3;
        Core::Vector3 m_vRight3;
        
        float m_fSpeed;

    }; //end of Camera.
} //end of namespace CANVAS.

#endif
