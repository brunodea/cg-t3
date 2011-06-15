#ifndef _BRUNODEA_RANDOM_BEZIER_BUTTON_HPP_
#define _BRUNODEA_RANDOM_BEZIER_BUTTON_HPP_

#include <SCV/SCV.h>
#include <string>
#include "GUI/Canvas/Canvas.h"
#include "macros.h"

namespace GUI
{
    class RandomBezierButton : public scv::Button
    {
    public:
        enum Type
        {
            BEZIER_PLANE = 0,
            BEZIER_GROUND
        }; //end of enum Type.
    public:
        RandomBezierButton(Type t, const scv::Point &p, int width, const std::string &str) : m_Type(t), scv::Button(p,width,str), m_pCanvas(NULL) {}

        void setCanvas(Canvas *canvas) { m_pCanvas = canvas; }

    protected:
        void onMouseClick(const scv::MouseEvent &evt)
        {
            if(m_pCanvas == NULL)
                return;
            switch(m_Type)
            {
            case BEZIER_PLANE:
                m_pCanvas->getBezierSurface()->randomControlPoints();
                break;
            case BEZIER_GROUND:
                m_pCanvas->getBezierFlat()->randomControlPoints();
                break;
            }
        }

    private:
        Type m_Type;
        Canvas *m_pCanvas;
    }; //end of class RandomBezierButton.
} //end of namespace GUI.

#endif
