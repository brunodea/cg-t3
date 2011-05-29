#ifndef _BRUNODEA_CG_T3_CANVAS_H_
#define _BRUNODEA_CG_T3_CANVAS_H_

#include <SCV/SCV.h>
#include "GUI/Canvas/Camera.h"

#include <vector>

namespace GUI
{
    class Canvas : public scv::Canvas
    {
    public:
        Canvas(int pos_x, int pos_y, int width, int height);

        void update();
        void render();
    protected:
        void onKeyPressed(const scv::KeyEvent &evt);

    private:
        void initCube();

    private:
        CANVAS::Camera m_Camera;

        std::vector<Core::Vector3> m_CubeVertices;

    }; //end of class Canvas.
} //end of namespace GUI.


#endif
