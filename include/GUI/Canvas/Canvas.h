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
    }; //end of class Canvas.
} //end of namespace GUI.


#endif
