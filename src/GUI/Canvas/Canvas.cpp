#include "GUI/Canvas/Canvas.h"

using namespace GUI;

Canvas::Canvas(int pos_x, int pos_y, int width, int height)
    : scv::Canvas(scv::Point(pos_x, pos_y), width, height), m_BGColor(1.f, 1.f, 1.f)
{}

void Canvas::update()
{
}

void Canvas::render()
{
    glClearColor(m_BGColor[0], m_BGColor[1], m_BGColor[2], m_BGColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}
