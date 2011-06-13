#ifndef _BRUNODEA_BEZIER_HPP_
#define _BRUNODEA_BEZIER_HPP_

#include "Core/matrix_functions.hpp"
#include "math/math_aux.hpp"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

namespace math
{
    class Bezier
    {
    public:
        Bezier() : m_vControlPoints() {}

        void addControlPoints(const std::vector<Core::Vector3> &ps) { m_vControlPoints.push_back(ps); }

        Core::Vector3 point(float u, float v)
        {
            Core::Vector3 p(0);

            unsigned int n = m_vControlPoints.size();
            unsigned int m = n;

            for(unsigned int i = 0; i < n; i++)
            {
                for(unsigned int j = 0; j < m; j++)
                    p += m_vControlPoints.at(i).at(j)*blend(m-1,j,v)*blend(n-1,i,u);
            }
            return p;
        }

        float blend(int n, int i, float u)
        {
            return (float)((float)factorial(n)/(float)(factorial(i)*factorial(n-i)))*pow(u,i)*pow(1-u,n-i);
        }

        void drawControlPointsInPoints()
        {
            glBegin(GL_POINTS);
                for(unsigned int i = 0; i < m_vControlPoints.size(); i++)
                {
                    for(unsigned int j = 0; j < m_vControlPoints.size(); j++)
                    {
                        Core::Vector4 v = Core::toVector4f(m_vControlPoints.at(i).at(j));
                        v = Util::MODELVIEW->getTop()*v;
                        glVertex3f(v[0], v[1], v[2]);
                    }
                }
            glEnd();
        }

        void adjustControlPointY(float val, unsigned int row, unsigned int col)
        {
            if(row < 0 || row >= m_vControlPoints.size() || col < 0 || col >= m_vControlPoints.size())
                return;
            m_vControlPoints.at(row).at(col)[1] = val;
        }

        void drawControlPointsInLines()
        {
            glBegin(GL_LINES);
                for(unsigned int i = 0; i < m_vControlPoints.size()-1; i++)
                {
                    for(unsigned int j = 0; j < m_vControlPoints.at(i).size()-1; j++)
                    {
                        Core::Vector4 v = Core::toVector4f(m_vControlPoints.at(i).at(j));
                        v = Util::MODELVIEW->getTop()*v;

                        Core::Vector4 v2 = Core::toVector4f(m_vControlPoints.at(i+1).at(j));
                        v2 = Util::MODELVIEW->getTop()*v2;

                        Core::Vector4 v4 = Core::toVector4f(m_vControlPoints.at(i).at(j+1));
                        v4 = Util::MODELVIEW->getTop()*v4;

                        glVertex3f(v[0], v[1], v[2]);
                        glVertex3f(v2[0], v2[1], v2[2]);
                        glVertex3f(v[0], v[1], v[2]);
                        glVertex3f(v4[0], v4[1], v4[2]);

                        if(i == m_vControlPoints.size()-2)
                        {
                            Core::Vector4 v3 = Core::toVector4f(m_vControlPoints.at(i+1).at(j+1));
                            v3 = Util::MODELVIEW->getTop()*v3;
                            
                            glVertex3f(v2[0], v2[1], v2[2]);
                            glVertex3f(v3[0], v3[1], v3[2]);
                        }
                        if(j == m_vControlPoints.size()-2)
                        {
                            Core::Vector4 v3 = Core::toVector4f(m_vControlPoints.at(i+1).at(j+1));
                            v3 = Util::MODELVIEW->getTop()*v3;
                            glVertex3f(v4[0], v4[1], v4[2]);
                            glVertex3f(v3[0], v3[1], v3[2]);
                        }
                    }
                }
            glEnd();
        }

    private:
        std::vector<std::vector<Core::Vector3>> m_vControlPoints;
    }; //end of class Bezier.
} //end of namespace math.

#endif
