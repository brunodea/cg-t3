#ifndef _BRUNODEA_CUBE_HPP_
#define _BRUNODEA_CUBE_HPP_

#include <SCV/SCV.h>
#include <vector>
#include "Core/matrix_functions.hpp"
#include "macros.h"
#include "Util/ModelViewMatrixStack.h"

namespace Model
{
    class Cube
    {
    public:
        Cube() { init(); }
        void draw()
        {
            glColor4f(1.f,1.f,1.f,1.f);
            glBegin(GL_LINE_STRIP);
            
                for(unsigned int i = 0; i < m_CubeVertices.size(); i += 4)
                {
                    Core::Vector4 v;
                    Core::Vector4 v2;
                    Core::Vector4 v3;
                    Core::Vector4 v4;
                
                    v = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(i));
                    v2 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(i+1));
                    v3 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(i+2));
                    v4 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(i+3));

                    Core::Vector3 vet1 = Core::toVector3f(v2-v);
                    Core::Vector3 vet2 = Core::toVector3f(v3-v);

                    //Core::Vector3 normal = Core::normalize(vet1.crossProduct(vet2));
                    //glNormal3f(normal[0],normal[1],normal[2]);

                    glVertex3f(v[0], v[1], v[2]);
                    glVertex3f(v2[0], v2[1], v2[2]);
                    glVertex3f(v3[0], v3[1], v3[2]);
                    glVertex3f(v4[0], v4[1], v4[2]);
                }

            glEnd();
        }

    private:
        void init()
        {
            float len = 1;
            Core::Vector3 v1 = Core::vector3f(-len,-len,-len);
            Core::Vector3 v2 = Core::vector3f(-len,-len,len);
            Core::Vector3 v3 = Core::vector3f(-len,len,len);
            Core::Vector3 v4 = Core::vector3f(-len,len,-len);

            Core::Vector3 v5 = Core::vector3f(len,len,len);
            Core::Vector3 v6 = Core::vector3f(len,-len,len);
            Core::Vector3 v7 = Core::vector3f(len,-len,-len);
            Core::Vector3 v8 = Core::vector3f(len,len,-len);

            Core::Vector3 v9 = Core::vector3f(-len,-len,-len);
            Core::Vector3 v10 = Core::vector3f(len,-len,-len);
            Core::Vector3 v11 = Core::vector3f(len,-len,len);
            Core::Vector3 v12 = Core::vector3f(-len,-len,len);

            Core::Vector3 v13 = Core::vector3f(len,len,len);
            Core::Vector3 v14 = Core::vector3f(len,len,-len);
            Core::Vector3 v15 = Core::vector3f(-len,len,-len);
            Core::Vector3 v16 = Core::vector3f(-len,len,len);

            Core::Vector3 v17 = Core::vector3f(-len,-len,-len);
            Core::Vector3 v18 = Core::vector3f(-len,len,-len);
            Core::Vector3 v19 = Core::vector3f(len,len,-len);
            Core::Vector3 v20 = Core::vector3f(len,-len,-len);

            Core::Vector3 v21 = Core::vector3f(len,len,len);
            Core::Vector3 v22 = Core::vector3f(-len,len,len);
            Core::Vector3 v23 = Core::vector3f(-len,-len,len);
            Core::Vector3 v24 = Core::vector3f(len,-len,len);

            //top face
            m_CubeVertices.push_back(v1);
            m_CubeVertices.push_back(v2);
            m_CubeVertices.push_back(v3);
            m_CubeVertices.push_back(v4);
                    /*      This is the front face*/
            m_CubeVertices.push_back(v5);
            m_CubeVertices.push_back(v6);
            m_CubeVertices.push_back(v7);
            m_CubeVertices.push_back(v8);
                    /*      This is the right face*/
            m_CubeVertices.push_back(v9);
            m_CubeVertices.push_back(v10);
            m_CubeVertices.push_back(v11);
            m_CubeVertices.push_back(v12);
                    /*      This is the left face*/
            m_CubeVertices.push_back(v13);
            m_CubeVertices.push_back(v14);
            m_CubeVertices.push_back(v15);
            m_CubeVertices.push_back(v16);
                    /*      This is the bottom face*/
            m_CubeVertices.push_back(v17);
            m_CubeVertices.push_back(v18);
            m_CubeVertices.push_back(v19);
            m_CubeVertices.push_back(v20);
                    /*      This is the back face*/
            m_CubeVertices.push_back(v21);
            m_CubeVertices.push_back(v22);
            m_CubeVertices.push_back(v23);
            m_CubeVertices.push_back(v24);
        }
    private:
        std::vector<Core::Vector3> m_CubeVertices;
    }; //end of class Cube.

} //end of namespace Model.

#endif
