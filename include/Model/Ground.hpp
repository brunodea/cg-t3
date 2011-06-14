#ifndef _BRUNODEA_GROUND_HPP_
#define _BRUNODEA_GROUND_HPP_

#include <SCV/SCV.h>
#include "Core/matrix_functions.hpp"
#include "macros.h"

namespace Model
{
    class Ground
    {
    public:
        Ground() { init(); }

        void draw()
        {        
            glBegin(GL_LINES);
        
                int r = 50;
                for(unsigned int i = 0; i < m_vVertices.size(); i += 4)
                {
                    Core::Vector4 v;
                    Core::Vector4 v2;
                    Core::Vector4 v3;
                    Core::Vector4 v4;
                
                    v = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i));
                    v2 = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i+1));
                    v3 = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i+2));
                    v4 = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i+3));

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
            float w = 1;
            float h = 1;
            Core::Vector3 v1 = Core::vector3f(-w,0.f,h);
            Core::Vector3 v2 = Core::vector3f(w,0.f,h);
            Core::Vector3 v3 = Core::vector3f(w,0.f,-h);
            Core::Vector3 v4 = Core::vector3f(-w,0.f,-h);

            m_vVertices.push_back(v1);
            m_vVertices.push_back(v2);
            m_vVertices.push_back(v3);
            m_vVertices.push_back(v4);
        }
    
    private:
        std::vector<Core::Vector3> m_vVertices;
    }; //end of class ground.

} //end of namespace Model.


#endif
