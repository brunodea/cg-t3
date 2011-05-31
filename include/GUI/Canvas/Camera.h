#ifndef _BRUNDOEA_CG_T3_CAMERA_H_
#define _BRUNDOEA_CG_T3_CAMERA_H_

#include "Core/matrix_functions.hpp"
#include "macros.h"
#include "Util/MatrixHandler.hpp"

namespace CANVAS
{
    class Camera
    {
    public:
        Camera() : m_View3(0), m_XAxis3(0), m_YAxis3(0), m_ZAxis3(0), m_vUp(0), m_vEye3(0)
        {}

        void lookAt(float eyex, float eyey, float eyez, 
                    float centerx, float centery, float centerz, 
                    float upx, float upy, float upz);
        inline void lookAt(const Core::Vector3 &eye, const Core::Vector3 &center, const Core::Vector3 &up)
        {
            m_vEye3 = eye;
            m_View3 = Core::normalize(center-eye);
            m_vUp = up;
            m_ZAxis3 = m_View3;
            m_ZAxis3 *= -1;

            m_XAxis3 = Core::normalize(m_View3.crossProduct(m_vUp));
            m_YAxis3 = m_XAxis3.crossProduct(m_ZAxis3);

            /*Core::Vector3 orig(0.f);
            orig[0] = 1.f;

            Core::Vector3 x_orig = m_XAxis3;
            x_orig *= -1;
            x_orig = Core::translate(x_orig)*m_XAxis3;

            float angx = Core::angle(x_orig, orig);

            orig[0] = 0.f;
            orig[1] = 1.f;

            Core::Vector3 y_orig = m_YAxis3;
            y_orig *= -1;
            y_orig = Core::translate(y_orig)*m_YAxis3;

            float angy = Core::angle(y_orig, orig);

            orig[1] = 0.f;
            orig[2] = 1.f;

            Core::Vector3 z_orig = m_ZAxis3;
            z_orig *= -1;
            z_orig = Core::translate(z_orig)*m_ZAxis3;

            float angz = Core::angle(z_orig, orig);

            Core::Matrix4 m = Core::rotateX(angx)*Core::rotateY(angy)*Core::rotateZ(angz);

            Util::MODELVIEW.transform(m);
            m_CameraMatrix = m;*/


            ///* Construcao da matriz de transformacao da camera. */

            ///* Copia a matriz dos eixos da camera para o canto esquerdo superior de r. */
            Core::Matrix4 r = Core::identity<4>();
            for(int i = 0; i < 3; i++)
                r.set(m_XAxis3[i],i,0);
            for(int i = 0; i < 3; i++)
                r.set(m_YAxis3[i],i,1);
            for(int i = 0; i < 3; i++)
                r.set(m_ZAxis3[i],i,2);

            r = Core::transpose(r);

            Core::Matrix4 t = Core::identity<4>();
            Core::Vector4 eye4(1.f);
            
            for(int i = 0; i < 3; i++)
                eye4[i] = eye(i,0);
            eye4 *= -1;

            t = Core::translate(eye4);

            Core::Matrix4 mt = r*t; //matriz inversa.

            Util::MODELVIEW.transform(mt);
            m_CameraMatrix = mt;
        }

        Core::Vector2 project(const Core::Vector3 &point);

        Core::Vector3 getView() { return m_View3; }
        Core::Vector3 getXAxis() { return m_XAxis3; }
        Core::Vector3 getYAxis() { return m_YAxis3; }
        Core::Vector3 getZAxis() { return m_ZAxis3; }
        Core::Vector3 getUp() { return m_vUp; }
        Core::Vector3 getEye() { return m_vEye3; }

    private:
        Core::Vector3 m_View3;
        Core::Vector3 m_XAxis3;
        Core::Vector3 m_YAxis3;
        Core::Vector3 m_ZAxis3;
        Core::Vector3 m_vUp;
        Core::Vector3 m_vEye3;

        Core::Matrix4 m_CameraMatrix;

    }; //end of Camera.
} //end of namespace CANVAS.

#endif
