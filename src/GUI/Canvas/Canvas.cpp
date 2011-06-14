#include "GUI/Canvas/Canvas.h"
#include "macros.h"
#include "Util/ModelViewMatrixStack.h"
#include "Core/Vector.hpp"

using namespace GUI;

Canvas::Canvas(int pos_x, int pos_y, int width, int height)
    : scv::Canvas(scv::Point(pos_x, pos_y), width, height), m_Camera(),
      m_Cubes(), m_Spheres(), m_Ground(), m_BezierSurface(13,0,0,0)
{
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
    gluPerspective(45.f, (float)this->getWidth()/(float)this->getHeight(), 0.1, 1000);

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
    //Util::MODELVIEW->pushMatrix();
    //    glColor4f(0.18f, 0.31f, 0.31f, 1.f);
    //    Util::MODELVIEW->scale(150.f,1.f,150.f);
    //    //Util::MODELVIEW->transform(m_Camera.transMatrix());
    //    m_Ground.draw();
    //Util::MODELVIEW->popMatrix();

    Util::MODELVIEW->pushMatrix();
        Util::MODELVIEW->scale(40.f,1.f,40.f);
        //Util::MODELVIEW->translate(0,-10,0);
        //Util::MODELVIEW->transform(m_Camera.transMatrix());
        //glColor4f(1.f,0.f,0.f,1.f);
        //m_BezierSurface.getBezier().drawControlPointsInLines();
        glColor4f(1.f,0.f,0.f,1.f);
        
        //m_BezierSurface.draw(Util::TEXTURE.getTextureID(Util::TextureID::TEX_GRASS), math::BezierSurface::DRAW_QUADS);
        m_BezierSurface.drawWireframe();
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

