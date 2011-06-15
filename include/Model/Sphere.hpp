/* Classe que representa uma Esfera. */

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
            glBegin(GL_LINES);
                for(unsigned int i = 0; i < m_vVertices.size(); i += 3)
                {
                    Core::Vector4 v;
                    Core::Vector4 v2;
                    Core::Vector4 v3;
                
                    v = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i));
                    v2 = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i+1));
                    v3 = Util::MODELVIEW->getTop()*Core::toVector4f(m_vVertices.at(i+2));
                    
                    Core::Vector2 p = PROJECTION->project(v);
                    Core::Vector2 p2 = PROJECTION->project(v2);
                    Core::Vector2 p3 = PROJECTION->project(v3);
                    
                    glVertex2f(p[0], p[1]);
                    glVertex2f(p2[0], p2[1]);
                    glVertex2f(p3[0], p3[1]);
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
