/* Classe que lida com a Canvas. Ela que guarda os modelos que vao ser desenhados. */

#ifndef _BRUNODEA_CG_T3_CANVAS_H_
#define _BRUNODEA_CG_T3_CANVAS_H_

#include <SCV/SCV.h>
#include "GUI/Canvas/Camera.h"
#include "Model/Cube.hpp"
#include "Model/Sphere.hpp"
#include "math/Bezier.hpp"
#include "math/BezierSurface.h"

#include <vector>

namespace GUI
{
    class Canvas : public scv::Canvas
    {
    public:
        Canvas(int pos_x, int pos_y, int width, int height);

        void update();
        void render();

        math::BezierSurface *getBezierSurface() { return &m_BezierSurface; }
        math::BezierSurface *getBezierFlat() { return &m_BezierFlat; }

    protected:
        void onKeyPressed(const scv::KeyEvent &evt);

    private:
        void cameraInitialPosition()
        {
            Core::Vector3 v = Core::vector3f(40, 30, -160);
            Core::Vector3 u = Core::vector3f(0, 1, 0);
            m_Camera.setEye(v);
            m_Camera.setUp(u);
            m_Camera.lookAt(m_Camera.getEye(), Core::Vector3(0), m_Camera.getUp());
        }

        void drawObjects();
        void init();

    private:
        CANVAS::Camera m_Camera;

        std::vector<Model::Cube> m_Cubes;
        std::vector<Model::Sphere> m_Spheres;

        math::BezierSurface m_BezierSurface;
        math::BezierSurface m_BezierFlat;

    }; //end of class Canvas.
} //end of namespace GUI.


#endif
