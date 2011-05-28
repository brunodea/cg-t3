#include "GUI/Canvas/Canvas.h"

using namespace GUI;

Canvas::Canvas(int pos_x, int pos_y, int width, int height)
    : scv::Canvas(scv::Point(pos_x, pos_y), width, height)
{}

void Canvas::update()
{
}

void Canvas::render()
{
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_DEPTH_TEST);
}
