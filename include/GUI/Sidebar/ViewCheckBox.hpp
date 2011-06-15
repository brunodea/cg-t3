/* Checkbox que diz se eh ou nao pra desenhar determinado objeto da cena. */

#ifndef _BRUNODEA_VIEW_CHECKBOX_HPP_
#define _BRUNODEA_VIEW_CHECKBOX_HPP_

#include <SCV/SCV.h>
#include <string>

#include "macros.h"
#include "GUI/DrawManager.hpp"

namespace GUI
{
    class ViewCheckBox : public scv::CheckBox
    {
    public:
        enum Type
        {
            SHOW_BEZIER_PLANE = 0,
            SHOW_BEZIER_PLANE_CP,
            SHOW_BEZIER_GROUND,
            SHOW_BEZIER_GROUND_CP,
            SHOW_CUBES,
            SHOW_SPHERES
        }; //end of enum Type.
    public:
        ViewCheckBox(Type t, const scv::Point &p, bool state, const std::string &str) : m_Type(t), scv::CheckBox(p,state,str) {}

    protected:

        void onMouseClick(const scv::MouseEvent &evt)
        {
            switch(m_Type)
            {
            case SHOW_BEZIER_PLANE:
                Util::DRAW_MANAGER->toggle(Util::DrawManager::BEZIER_PLANE);
                break;
            case SHOW_BEZIER_GROUND:
                Util::DRAW_MANAGER->toggle(Util::DrawManager::BEZIER_GROUND);
                break;
            case SHOW_BEZIER_PLANE_CP:
                Util::DRAW_MANAGER->toggle(Util::DrawManager::BEZIER_PLANE_CP);
                break;
            case SHOW_BEZIER_GROUND_CP:
                Util::DRAW_MANAGER->toggle(Util::DrawManager::BEZIER_GROUND_CP);
                break;
            case SHOW_CUBES:
                Util::DRAW_MANAGER->toggle(Util::DrawManager::CUBES);
                break;
            case SHOW_SPHERES:
                Util::DRAW_MANAGER->toggle(Util::DrawManager::SPHERES);
                break;
            }
        }

    private:
        Type m_Type;
    }; //end of class ViewCheckBox.
} //end of namespace GUI.

#endif
