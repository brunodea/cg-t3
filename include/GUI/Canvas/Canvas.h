#ifndef _BRUNODEA_CG_T3_CANVAS_H_
#define _BRUNODEA_CG_T3_CANVAS_H_

#include <SCV/SCV.h>

namespace GUI
{
    class Canvas : public scv::Canvas
    {
    public:
        Canvas(int pos_x, int pos_y, int width, int height);

        void update();
        void render();

        inline void setBGColor(float r, float g, float b, float a = 1.f)
        {
            m_BGColor[0] = r;
            m_BGColor[1] = g;
            m_BGColor[2] = b;
            m_BGColor[3] = a;
        }

    private:
        scv::Color4f m_BGColor;

    }; //end of class Canvas.
} //end of namespace GUI.


#endif
