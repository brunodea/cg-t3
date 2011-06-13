#ifndef _BRUNODEA_SPHERE_HPP_
#define _BRUNODEA_SPHERE_HPP_

#include <SCV/SCV.h>
#include "Core/matrix_functions.hpp"
#include <vector>
#include <cmath>
#include "macros.h"

namespace Model
{
    class Sphere
    {
    public:
        Sphere() { init(); }

        void draw()
        {
            glColor4f(0.f,0.f,1.f,1.f);
            glBegin(GL_TRIANGLE_FAN);
                for(unsigned int i = 0; i < m_vVertices.size(); i += 3)
                {
                    Core::Vector4 v;
                    Core::Vector4 v2;
                    Core::Vector4 v3;
                
                    v = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i));
                    v2 = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i+1));
                    v3 = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i+2));

                    Core::Vector3 vet1 = Core::toVector3f(v2-v);
                    Core::Vector3 vet2 = Core::toVector3f(v3-v);

                    //Core::Vector3 normal = Core::normalize(vet1.crossProduct(vet2));
                    //glNormal3f(normal[0],normal[1],normal[2]);

                    glVertex3f(v[0], v[1], v[2]);
                    glVertex3f(v2[0], v2[1], v2[2]);
                    glVertex3f(v3[0], v3[1], v3[2]);
                }
            glEnd();
        }

    private:
        void init()
        {
            /*Esfera eh criada utilizando funcoes parametricas.*/
            float r = 1;
            for(float i = 0; i < PI; i += .09f)
            {
                float u = r*cos((float)i);
                for(float j = 0; j < 2*PI; j += .3f)
                {
                    float x = sqrt(pow(r,2) - pow(u,2))*cos(j);
                    float y = sqrt(pow(r,2) - pow(u,2))*sin(j);
                    float z = u;
                    m_vVertices.push_back(Core::vector3f(x,y,z));
                }
            }
        }

    private:
        std::vector<Core::Vector3> m_vVertices;

    }; //end of class Sphere.
} //end of namespace Model.

#endif
