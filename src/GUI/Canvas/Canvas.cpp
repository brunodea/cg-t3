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
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
}
