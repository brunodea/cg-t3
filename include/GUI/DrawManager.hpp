/* Lida com o que vai ser desenhado na tela. */

#ifndef _BRUNODEA_DRAW_MANAGER_HPP_
#define _BRUNODEA_DRAW_MANAGER_HPP_

namespace Util
{
    class DrawManager
    {
    public:
        enum Type
        {
            BEZIER_PLANE = 0,
            BEZIER_PLANE_CP, //bezier plane control points
            BEZIER_GROUND,
            BEZIER_GROUND_CP,
            CUBES,
            SPHERES,
            SIZE //tamanho do vetor
        };//end of Type.
    public:
        static DrawManager *instance()
        {
            if(m_sInstance == 0)
                m_sInstance = new DrawManager();
            return m_sInstance;
        }

        bool drawObject(Type t) { return m_bDrawObject[t]; }
        void setDrawObject(Type t, bool state) { m_bDrawObject[t] = state; }
        void toggle(Type t) { m_bDrawObject[t] = !m_bDrawObject[t]; }

    private:
        DrawManager() 
        {
            m_bDrawObject[BEZIER_PLANE] = true;
            m_bDrawObject[BEZIER_GROUND] = true;
            m_bDrawObject[BEZIER_PLANE_CP] = false;
            m_bDrawObject[BEZIER_GROUND_CP] = false;
            m_bDrawObject[CUBES] = true;
            m_bDrawObject[SPHERES] = true;
        }

    private:
        static DrawManager *m_sInstance;
        bool m_bDrawObject[SIZE]; //desenhar objeto?
    }; //end of class DrawManager.
} //end of namespace Util.

#endif
