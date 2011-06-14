#ifndef _BRUNODEA_CUBE_HPP_
#define _BRUNODEA_CUBE_HPP_

#include <SCV/SCV.h>
#include <vector>
#include "Core/matrix_functions.hpp"
#include "macros.h"
#include "Util/ModelViewMatrixStack.h"
#include "GUI/Canvas/Projection.h"

using namespace CANVAS;

namespace Model
{
    class Cube
    {
    public:
        Cube() { init(); }
        void draw()
        {
            glBegin(GL_LINES);
            
                Core::Vector4 v;
                Core::Vector4 v2;
                Core::Vector4 v3;
                Core::Vector4 v4;

                Core::Vector4 v5;
                Core::Vector4 v6;
                Core::Vector4 v7;
                Core::Vector4 v8;
                
                v = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(0));
                v2 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(1));
                v3 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(2));
                v4 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(3));
                
                v5 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(4));
                v6 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(5));
                v7 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(6));
                v8 = Util::MODELVIEW->getTop()*Core::toVector4f(m_CubeVertices.at(7));

                Core::Vector2 p = PROJECTION->project(v);
                Core::Vector2 p2 = PROJECTION->project(v2);
                Core::Vector2 p3 = PROJECTION->project(v3);
                Core::Vector2 p4 = PROJECTION->project(v4);
                
                Core::Vector2 p5 = PROJECTION->project(v5);
                Core::Vector2 p6 = PROJECTION->project(v6);
                Core::Vector2 p7 = PROJECTION->project(v7);
                Core::Vector2 p8 = PROJECTION->project(v8);

                glVertex2f(p[0], p[1]);
                glVertex2f(p2[0], p2[1]);

                glVertex2f(p2[0], p2[1]);
                glVertex2f(p3[0], p3[1]);
                
                glVertex2f(p3[0], p3[1]);
                glVertex2f(p4[0], p4[1]);
                
                glVertex2f(p4[0], p4[1]);
                glVertex2f(p[0], p[1]);

                
                glVertex2f(p[0], p[1]);
                glVertex2f(p5[0], p5[1]);
                
                glVertex2f(p5[0], p5[1]);
                glVertex2f(p6[0], p6[1]);
                
                glVertex2f(p6[0], p6[1]);
                glVertex2f(p2[0], p2[1]);
                
                glVertex2f(p6[0], p6[1]);
                glVertex2f(p7[0], p7[1]);
                
                glVertex2f(p7[0], p7[1]);
                glVertex2f(p3[0], p3[1]);
                
                glVertex2f(p7[0], p7[1]);
                glVertex2f(p8[0], p8[1]);
                
                glVertex2f(p8[0], p8[1]);
                glVertex2f(p4[0], p4[1]);
                
                glVertex2f(p8[0], p8[1]);
                glVertex2f(p5[0], p5[1]);

            glEnd();
        }

    private:
        void init()
        {
            float len = 1;
            Core::Vector3 v1 = Core::vector3f(-len,-len,-len);
            Core::Vector3 v2 = Core::vector3f(-len,-len,len);
            Core::Vector3 v3 = Core::vector3f(len,-len,len);
            Core::Vector3 v4 = Core::vector3f(len,-len,-len);

            Core::Vector3 v5 = Core::vector3f(-len,len,-len);
            Core::Vector3 v6 = Core::vector3f(-len,len,len);
            Core::Vector3 v7 = Core::vector3f(len,len,len);
            Core::Vector3 v8 = Core::vector3f(len,len,-len);

            //top face
            m_CubeVertices.push_back(v1);
            m_CubeVertices.push_back(v2);
            m_CubeVertices.push_back(v3);
            m_CubeVertices.push_back(v4);

            m_CubeVertices.push_back(v5);
            m_CubeVertices.push_back(v6);
            m_CubeVertices.push_back(v7);
            m_CubeVertices.push_back(v8);
        }
    private:
        std::vector<Core::Vector3> m_CubeVertices;
    }; //end of class Cube.

} //end of namespace Model.

#endif
