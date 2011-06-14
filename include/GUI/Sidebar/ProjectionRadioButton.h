#ifndef _BRUNODEA_PROJECTION_BUTTON_GROUP_HPP_
#define _BRUNODEA_PROJECTION_BUTTON_GROUP_HPP_

#include <SCV/SCV.h>
#include "Gui/Canvas/Projection.h"
#include <string>

namespace GUI
{
    class ProjectionRadioButton : public scv::RadioButton
    {
    public:
        enum Type
        {
            ORTHO = 0,
            PERSP = 1
        }; //end of enum Type.
    public:
        ProjectionRadioButton(Type type, const scv::Point &p, bool state, const std::string &s) 
            : m_Type(type),scv::RadioButton(p,state,s)
        {}


    protected:
        void onMouseClick(const scv::MouseEvent &evt)
        {
            switch(m_Type)
            {
            case ORTHO:
                CANVAS::PROJECTION->setType(CANVAS::Projection::ORTHO);
                break;
            case PERSP:
                CANVAS::PROJECTION->setType(CANVAS::Projection::PERSP);
                break;
            }
        }

    private:
        Type m_Type;
    }; //end of class ProjectionRadioButton.
} //end of namespace GUI.

#endif
