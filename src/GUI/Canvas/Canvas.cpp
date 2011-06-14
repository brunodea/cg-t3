#include "GUI/Canvas/Canvas.h"
#include "macros.h"
#include "Util/ModelViewMatrixStack.h"
#include "Core/Vector.hpp"

using namespace GUI;

Canvas::Canvas(int pos_x, int pos_y, int width, int height)
    : scv::Canvas(scv::Point(pos_x, pos_y), width, height), m_Camera(),
      m_Cubes(), m_Spheres(), m_BezierSurface(13), m_BezierFlat(4)
{
    m_BezierFlat.flatSurface();
    m_BezierFlat.adjustControlPoint(2,3,3);
    init();
}

void Canvas::init()
{
    cameraInitialPosition();
    for(int i = 0; i < 15; i++)
        m_Cubes.push_back(Model::Cube());
    for(int i = 0; i < 2; i++)
        m_Spheres.push_back(Model::Sphere());
}

void Canvas::update()
{
}

void Canvas::render()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  
    
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.f,0.f,0.f,1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Util::MODELVIEW->loadIdentity();
    drawObjects();
}

void Canvas::drawObjects()
{
    Util::MODELVIEW->pushMatrix();
        Util::MODELVIEW->scale(10.f,10.f,10.f);
        Util::MODELVIEW->translate(40,40,40);
        Util::MODELVIEW->transform(m_Camera.transMatrix());
        //glColor4f(1.f,0.f,0.f,1.f);
        //m_BezierSurface.getBezier().drawControlPointsInLines();
        glColor4f(0.f,1.f,0.f,1.f);
        m_BezierSurface.drawWireframe();
    Util::MODELVIEW->popMatrix();

    Util::MODELVIEW->pushMatrix();
        Util::MODELVIEW->scale(100.f,100.f,100.f);
        Util::MODELVIEW->translate(-50,0,-50);
        Util::MODELVIEW->transform(m_Camera.transMatrix());
        glColor4f(1.f,1.f,1.f,1.f);
        m_BezierFlat.drawWireframe();
    Util::MODELVIEW->popMatrix();
    
    glColor4f(0.82f, 0.41f, 0.11f, 1.f);
    Util::MODELVIEW->pushMatrix();
        Util::MODELVIEW->translate(0,5,0);
        for(unsigned int i = 0; i < m_Spheres.size(); i++)
        {
            float x = 20*cos((float)i);
            float y = -20*sin((float)i);
            Util::MODELVIEW->translate(x,y,0);

            Util::MODELVIEW->pushMatrix();
                Util::MODELVIEW->transform(m_Camera.transMatrix());
                m_Spheres.at(i).draw();
            Util::MODELVIEW->popMatrix();
        }
        
    Util::MODELVIEW->popMatrix();
    
    glColor4f(0.f,0.f,1.f,1.f);
    Util::MODELVIEW->pushMatrix();
        for(unsigned int i = 0; i < m_Cubes.size(); i++)
        {
            float x = i*cos((float)i);
            float z = i*sin((float)i);
            Util::MODELVIEW->translate(x, 0, z);

            Util::MODELVIEW->pushMatrix();
                Util::MODELVIEW->transform(m_Camera.transMatrix());
                m_Cubes.at(i).draw();
            Util::MODELVIEW->popMatrix();
        }
    Util::MODELVIEW->popMatrix();
}

void Canvas::onKeyPressed(const scv::KeyEvent &evt)
{
    float rotate_angle = (float)PI/50.f;
    if(evt.getKeyCode() == 'l')
        m_Camera.rotate(0,-rotate_angle,0);
    else if(evt.getKeyCode() == 'j')
        m_Camera.rotate(0,rotate_angle,0);

    if(evt.getKeyCode() == 'i')
        m_Camera.rotate(rotate_angle,0,0);
    else if(evt.getKeyCode() == 'k')
        m_Camera.rotate(-rotate_angle,0,0);

    if(evt.getKeyCode() == 'u')
        m_Camera.rotate(0,0,-rotate_angle);
    else if(evt.getKeyCode() == 'o')
        m_Camera.rotate(0,0,rotate_angle);

    if(evt.getKeyCode() == 'a')
        m_Camera.moveLeft();
    else if(evt.getKeyCode() == 'd')
        m_Camera.moveRight();

    if(evt.getKeyCode() == 'w')
        m_Camera.moveForward();
    else if(evt.getKeyCode() == 's')
        m_Camera.moveBackwards();

    if(evt.getKeyCode() == 'z')
        m_Camera.moveUp();
    else if(evt.getKeyCode() == 'x')
        m_Camera.moveDown();

    if(evt.getKeyCode() == '1')
        cameraInitialPosition();
    Util::MODELVIEW->transform(m_Camera.transMatrix());
}

