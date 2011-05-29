#include "GUI/Canvas/Canvas.h"
#include "macros.h"
#include "Util/MatrixHandler.hpp"
#include "Core/Vector.hpp"

using namespace GUI;

Canvas::Canvas(int pos_x, int pos_y, int width, int height)
    : scv::Canvas(scv::Point(pos_x, pos_y), width, height), m_Camera()
{
    m_Camera.lookAt(0.f,10.f,10.f, 0.f,0.f,0.f, 0.f,0.f,1.f);
    initCube();
    for(int i = 0; i < m_CubeVertices.size(); i++)
    {
        Core::Vector3 *v = &m_CubeVertices.at(i);
        Core::Vector4 v2(1.f);
        v2[0] = (*v)[0];
        v2[1] = (*v)[1];
        v2[2] = (*v)[2];

        /*Core::Vector2 proj = m_Camera.project(*v);
        v2[0] = proj[0];
        v2[1] = proj[1];*/

        Core::Matrix4 m(*Util::MODELVIEW.getCurrMatrix());
        v2 = m*v2;

        (*v)[0] = v2[0];
        (*v)[1] = v2[1];
        (*v)[2] = v2[2];
    }
}

void Canvas::update()
{
    /*Core::Vector3 axis(0.f);
    axis[0] = 1.f;

    Core::Vector3 cam = m_Camera.getCenter();
    float ang = Core::angle(cam, axis);

    Core::Matrix4 mat = Core::identity<4>();
    mat = Core::rotateX(ang);

    axis[0] = 0.f;
    axis[1] = 1.f;

    cam = m_Camera.getUp();
    ang = Core::angle(cam, axis);
    mat = Core::rotateY(ang)*mat;

    axis[1] = 0.f;
    axis[2] = 1.f;

    cam = m_Camera.getCenter().crossProduct(cam);
    ang = Core::angle(cam, axis);
    mat = Core::rotateZ(ang)*mat;*/

    //Util::MODELVIEW.transform(mat);

    
}

void Canvas::render()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(45, getWidth()/getHeight(), 0.1, 500);
    glOrtho(-100,100,-100,100,100,-100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //glEnable(GL_DEPTH_TEST);

    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor4f(1.f,1.f,1.f,1.f);

    Util::MODELVIEW.pushMatrix();
            
        glColor4f(1.f,1.f,1.f,1.f);
        //desenha um cubo.
        glBegin(GL_LINE_STRIP);
            
        for(int i = 0; i < m_CubeVertices.size(); i++)
        {
            Core::Vector3 v = m_CubeVertices.at(i);
            glVertex3f(m_CubeVertices.at(i)[0], m_CubeVertices.at(i)[1], m_CubeVertices.at(i)[2]);// /*-m_Camera.getEye()[2]*/);
        }

        glEnd();
    Util::MODELVIEW.popMatrix();


    //glDisable(GL_DEPTH_TEST);
}

void Canvas::initCube()
{
    float one = 50.f;
    Core::Vector3 v1(0.f);
    Core::Vector3 v2(0.f); v2[2] = -one;
    Core::Vector3 v3(-one); v3[1] = 0.f;
    Core::Vector3 v4(0.f); v4[0] = -one;

    Core::Vector3 v5(0.f);
    Core::Vector3 v6(0.f); v6[0] = -one;
    Core::Vector3 v7(-one); v7[2] = 0.f;
    Core::Vector3 v8(0.f); v8[1] = -one;

    Core::Vector3 v9(0.f);
    Core::Vector3 v10(0.f); v10[1] = -one;
    Core::Vector3 v11(-one); v11[0] = 0.f;
    Core::Vector3 v12(0.f); v12[2] = -one;

    Core::Vector3 v13(0.f); v13[0] = -one;
    Core::Vector3 v14(-one); v14[1] = 0.f;
    Core::Vector3 v15(-one);
    Core::Vector3 v16(-one); v16[2] = 0.f;

    Core::Vector3 v17(0.f);
    Core::Vector3 v18(-one); v18[0] = 0.f;
    Core::Vector3 v19(-one);
    Core::Vector3 v20(-one); v20[2] = 0.f;

    Core::Vector3 v21(0.f);
    Core::Vector3 v22(-one); v22[1] = 0.f;
    Core::Vector3 v23(-one);
    Core::Vector3 v24(-one); v24[0] = 0.f;

 
    //top face
    m_CubeVertices.push_back(v1);
    m_CubeVertices.push_back(v2);
    m_CubeVertices.push_back(v3);
    m_CubeVertices.push_back(v4);
            /*      This is the front face*/
    m_CubeVertices.push_back(v5);
    m_CubeVertices.push_back(v6);
    m_CubeVertices.push_back(v7);
    m_CubeVertices.push_back(v8);
            /*      This is the right face*/
    m_CubeVertices.push_back(v9);
    m_CubeVertices.push_back(v10);
    m_CubeVertices.push_back(v11);
    m_CubeVertices.push_back(v12);
            /*      This is the left face*/
    m_CubeVertices.push_back(v13);
    m_CubeVertices.push_back(v14);
    m_CubeVertices.push_back(v15);
    m_CubeVertices.push_back(v16);
            /*      This is the bottom face*/
    m_CubeVertices.push_back(v17);
    m_CubeVertices.push_back(v18);
    m_CubeVertices.push_back(v19);
    m_CubeVertices.push_back(v20);
            /*      This is the back face*/
    m_CubeVertices.push_back(v21);
    m_CubeVertices.push_back(v22);
    m_CubeVertices.push_back(v23);
    m_CubeVertices.push_back(v24);
}

void Canvas::onKeyPressed(const scv::KeyEvent &evt)
{
    if(evt.getKeyCode() == 'a')
        m_Camera.getEye()[0] -= 10.f;
}

