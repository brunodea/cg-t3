#ifndef _BRUNODEA_CG_T3_SIDEBAR_H_
#define _BRUNODEA_CG_T3_SIDEBAR_H_

#include <SCV/SCV.h>

namespace GUI
{
    class Sidebar : public scv::Panel
    {
    public:
        Sidebar(int pos_x, int pos_y, int width, int height)
            : scv::Panel(scv::Point(pos_x, pos_y), width, height)
        {}

    private:
    }; //end of class Sidebar.
} //end of namespace GUI.

#endif
