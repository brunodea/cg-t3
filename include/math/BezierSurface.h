#ifndef _BRUNODEA_BEZIER_SURFACE_HPP_
#define _BRUNODEA_BEZIER_SURFACE_HPP_

#include "Core/matrix_functions.hpp"
#include "math/Bezier.hpp"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

namespace math
{
    class BezierSurface
    {
    public:
        enum DrawType
        {
            DRAW_LINES = 0,
            DRAW_TRIANGLES,
            DRAW_QUADS,
            DRAW_POINTS
        };

    public:
        BezierSurface(unsigned int degree, float start_x, float start_y, float start_z)
            : m_Bezier(), m_vPatch(), m_iDegree(degree)
        {
            init(start_x, start_y, start_z); 
        }

        void draw(DrawType dt=DRAW_LINES)
        {
            switch(dt)
            {
            case DRAW_LINES:
                drawWireframe();
                break;
            case DRAW_TRIANGLES:
                drawWithTexture();
                break;
            case DRAW_QUADS:
                drawWithTexture(DRAW_QUADS);
                break;
            case DRAW_POINTS:
                drawCloud();
                break;
            default:
                drawWireframe();
                break;
            }
        }

        void drawWithTexture(DrawType dt=DRAW_TRIANGLES)
        {
            glColor4f(1.f,1.f,1.f,1.f);

            if(dt == DRAW_TRIANGLES)
                glBegin(GL_TRIANGLE_FAN);
            else
                glBegin(GL_QUADS);

                float r = 1;
                for(unsigned int i = 0; i < m_PatchLen-1; i++)
                {
                    for(unsigned int j = 0; j < m_PatchLen-1; j++)
                    {
                        Core::Vector4 v = Core::toVector4f(m_vPatch.at((i*m_PatchLen)+j));
                        v = Util::MODELVIEW->getTop()*v;

                        Core::Vector4 v2 = Core::toVector4f(m_vPatch.at(((i+1)*m_PatchLen)+j));
                        v2 = Util::MODELVIEW->getTop()*v2;

                        Core::Vector4 v4 = Core::toVector4f(m_vPatch.at((i*m_PatchLen)+j+1));
                        v4 = Util::MODELVIEW->getTop()*v4;

                        if(dt == DRAW_TRIANGLES)
                        {
                            glVertex3f(v2[0], v2[1], v2[2]);
                            glVertex3f(v[0], v[1], v[2]);
                            glVertex3f(v4[0], v4[1], v4[2]);
                        }
                        else
                        {
                            Core::Vector4 v3 = Core::toVector4f(m_vPatch.at(((i+1)*m_PatchLen)+j+1));
                            v3 = Util::MODELVIEW->getTop()*v3;
                            glVertex3f(v[0], v[1], v[2]);
                            glVertex3f(v2[0], v2[1], v2[2]);
                            glVertex3f(v3[0], v3[1], v3[2]);
                            glVertex3f(v4[0], v4[1], v4[2]);
                        }
                    }
                }
            glEnd();
        }

        void drawWireframe()
        {
            glBegin(GL_LINES);
            for(unsigned int i = 0; i < m_PatchLen-1; i++)
                {
                    for(unsigned int j = 0; j < m_PatchLen-1; j++)
                    {
                        Core::Vector4 v = Core::toVector4f(m_vPatch.at((i*m_PatchLen)+j));
                        v = Util::MODELVIEW->getTop()*v;

                        Core::Vector4 v2 = Core::toVector4f(m_vPatch.at(((i+1)*m_PatchLen)+j));
                        v2 = Util::MODELVIEW->getTop()*v2;

                        Core::Vector4 v4 = Core::toVector4f(m_vPatch.at((i*m_PatchLen)+j+1));
                        v4 = Util::MODELVIEW->getTop()*v4;
                        
                        glVertex3f(v[0], v[1], v[2]);
                        glVertex3f(v2[0], v2[1], v2[2]);
                        glVertex3f(v[0], v[1], v[2]);
                        glVertex3f(v4[0], v4[1], v4[2]);

                        if(i == m_PatchLen-2)
                        {
                            Core::Vector4 v3 = Core::toVector4f(m_vPatch.at(((i+1)*m_PatchLen)+j+1));
                            v3 = Util::MODELVIEW->getTop()*v3;
                            
                            glVertex3f(v2[0], v2[1], v2[2]);
                            glVertex3f(v3[0], v3[1], v3[2]);
                        }
                        if(j == m_PatchLen-2)
                        {
                            Core::Vector4 v3 = Core::toVector4f(m_vPatch.at(((i+1)*m_PatchLen)+j+1));
                            v3 = Util::MODELVIEW->getTop()*v3;
                            glVertex3f(v4[0], v4[1], v4[2]);
                            glVertex3f(v3[0], v3[1], v3[2]);
                        }
                    }
                }
            glEnd();
        }

        void drawCloud()
        {
            glBegin(GL_POINTS);
                for(unsigned int i = 0; i < m_vPatch.size(); i++)
                {
                    Core::Vector4 v2 = Core::toVector4f(m_vPatch.at(i));
                    v2 = Util::MODELVIEW->getTop()*v2;

                    glVertex3f(v2[0], v2[1], v2[2]);
                }
            glEnd();
        }

        void adjustControlPoint(float val_y, unsigned int cp_row, unsigned int cp_col)
        {
            m_Bezier.adjustControlPointY(val_y, cp_row, cp_col);
            updateSubPatches(0.0415f);
        }
        
        void updateSubPatches(float precision)
        {
            m_vPatch.clear();
            for(float u = 0; u < 1.f; u += precision)
            {
                for(float v = 0; v < 1.f; v += precision)
                    m_vPatch.push_back(m_Bezier.point(u,v));
            }
            m_PatchLen = (int)sqrt((float)m_vPatch.size());
        }

        Bezier getBezier() { return m_Bezier; }

    private:
        void init(float start_x, float start_y, float start_z)
        {
            srand((unsigned int)time(0));
            for(unsigned int i = 0; i < m_iDegree; i++)
            {
                std::vector<Core::Vector3> vs;
                for(unsigned int j = 0; j < m_iDegree; j++)
                {
                    float x = i + start_x;
                    float y = rand()%10*pow(-1.f,(rand()%2)+1);
                    float z = j + start_z;
                    vs.push_back(Core::vector3f(x,y,z));
                }
                m_Bezier.addControlPoints(vs);
            }

            updateSubPatches(0.0415f); //0.0415f melhor precisao.
        }

    private:
        Bezier m_Bezier;
        std::vector<Core::Vector3> m_vPatch;
        unsigned int m_iDegree;
        int m_PatchLen;
    }; //end of class BezierSurface.
} //end of namespace math.


#endif
