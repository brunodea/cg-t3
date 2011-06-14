#ifndef _BRUNODEA_CG_T3_SIDEBAR_H_
#define _BRUNODEA_CG_T3_SIDEBAR_H_

#include <SCV/SCV.h>
#include "GUI/Sidebar/ProjectionRadioButton.h"

namespace GUI
{
    class Sidebar : public scv::Panel
    {
    public:
        Sidebar(int pos_x, int pos_y, int width, int height)
            : scv::Panel(scv::Point(pos_x, pos_y), width, height), m_ProjButtonGroup()
        {
            initProjButtonGroup();
        }
    private:
        void initProjButtonGroup()
        {
            ProjectionRadioButton *b = new ProjectionRadioButton(ProjectionRadioButton::PERSP, scv::Point(5,10), true, "Perspectiva");
            ProjectionRadioButton *b2 = new ProjectionRadioButton(ProjectionRadioButton::ORTHO, scv::Point(5, 20+b->getHeight()), false, "Ortografica");
            
            this->addComponent(b);
            this->addComponent(b2);

            b->registerButtonGroup(&m_ProjButtonGroup);
            b2->registerButtonGroup(&m_ProjButtonGroup);
        }

    private:
        scv::ButtonGroup m_ProjButtonGroup;

    }; //end of class Sidebar.
} //end of namespace GUI.

#endif
