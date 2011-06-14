#ifndef _BRUNODEA_PROJECTION_HPP_
#define _BRUNODEA_PROJECTION_HPP_

#include "Core/matrix_functions.hpp"
#include "Core/Matrix.hpp"
#include "Core/Vector.hpp"

namespace CANVAS
{
    class Projection
    {
    public:
        enum Type
        {
            ORTHO = 0,
            PERSP = 1
        };
    public:
        static Projection *instance()
        {
            if(m_sInstance == NULL)
                m_sInstance = new Projection();
            return m_sInstance;
        }

        Core::Vector2 project(Core::Vector4 &v)
        {
            Core::Vector4 res;
            res = m_Matrix*v;

            Core::Vector2 proj;
            switch(m_Type)
            {
            case ORTHO:
                proj = projectOrtho(v);
                break;
            case PERSP:
                proj = projectPersp(v);
                break;
            }

            return proj;
        }

        void setType(Type t) { m_Type = t; }

    private:
        Projection() : m_Matrix(0)
        {
            setPerspective();
        }

        void setPerspective()
        {
            m_Type = PERSP;
            m_Matrix = Core::identity<4>();
            m_Matrix.set(1.f/-100.f,3,2);
            m_Matrix.set(0,3,3);
            //float f = (float)1.f/tan(fovy/2.f); //cotangent

            //res.set(f/aspect,0,0);
            //res.set(f,1,1);
            //res.set((zFar+zNear)/(zNear-zFar),2,2);
            //res.set(-1,3,2);
            //res.set((2*zFar*zNear)/(zNear-zFar),2,3);
        }
        void setOrtho()
        {
            m_Type = ORTHO;
            float right = 10.f;
            float left = -10.f;
            float top = -10.f;
            float bottom = 10.f;
            float perto = -10.f;
            float longe = 10.f;

            float tx = -1.f*((float)(right+left)/(right-left));
            float ty = -1.f*((float)(top+bottom)/(top-bottom));
            float tz = -1.f*((float)(longe+perto)/(longe-perto));
            
            m_Matrix = Core::identity<4>();
            m_Matrix.set(2.f/(right-left),0,0);
            m_Matrix.set(2.f/(top-bottom),1,1);
            m_Matrix.set(2.f/(longe-perto),2,2);
            
            m_Matrix.set(tx,0,3);
            m_Matrix.set(ty,1,3);
            m_Matrix.set(tz,2,3);
        }

        Core::Vector2 projectOrtho(Core::Vector4 &v)
        {
            Core::Vector4 res;
            res = m_Matrix*v;
            Core::Vector2 v2;
            v2[0] = res[0];
            v2[1] = res[1];

            return v2;
        }

        Core::Vector2 projectPersp(Core::Vector4 &v)
        {
            Core::Vector4 res;
            res = m_Matrix*v;
            Core::Vector2 v2;
            v2[0] = (float)res[0]/res[2];
            v2[1] = (float)res[1]/res[2];

            return v2;
        }

    private:
        static Projection *m_sInstance;
        Core::Matrix4 m_Matrix;

        Type m_Type;
    };
}

#endif
