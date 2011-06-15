/* Classe que arruma a sidebar com os botoes, checkboxes, labels, etc. */

#ifndef _BRUNODEA_CG_T3_SIDEBAR_H_
#define _BRUNODEA_CG_T3_SIDEBAR_H_

#include <SCV/SCV.h>
#include "GUI/Sidebar/ProjectionRadioButton.h"
#include "GUI/Sidebar/ViewCheckBox.hpp"
#include "GUI/Sidebar/RandomBezierButton.hpp"
#include "GUI/Canvas/Canvas.h"

namespace GUI
{
    class Sidebar : public scv::Panel
    {
    public:
        Sidebar(Canvas *canvas, int pos_x, int pos_y, int width, int height)
            : scv::Panel(scv::Point(pos_x, pos_y), width, height), m_ProjButtonGroup(), m_pCanvas(canvas)
        {
            initProjButtonGroup();
            initCheckBoxes();
            initRandomBezierButtons();
            helpLabels();
        }
    private:
        void initProjButtonGroup()
        {
            scv::Label *label = new scv::Label(scv::Point(5,10), "Projecao:");

            ProjectionRadioButton *b = new ProjectionRadioButton(ProjectionRadioButton::PERSP, scv::Point(5,label->getHeight()+label->getRelativePosition().y), true, "Perspectiva");
            ProjectionRadioButton *b2 = new ProjectionRadioButton(ProjectionRadioButton::ORTHO, scv::Point(5, 20+b->getHeight()), false, "Ortografica");
            
            this->addComponent(label);
            this->addComponent(b);
            this->addComponent(b2);

            b->registerButtonGroup(&m_ProjButtonGroup);
            b2->registerButtonGroup(&m_ProjButtonGroup);
        }

        void initCheckBoxes()
        {
            int y = 70;
            scv::Label *label = new scv::Label(scv::Point(5,y), "Visualizar:");
            y += label->getHeight();
            ViewCheckBox *cb1 = new ViewCheckBox(ViewCheckBox::SHOW_BEZIER_PLANE, scv::Point(10,y), true, "Bezier(Verde)");
            int h = cb1->getHeight();
            ViewCheckBox *cb2 = new ViewCheckBox(ViewCheckBox::SHOW_BEZIER_PLANE_CP, scv::Point(10,h+y), false, "Pontos de Controle do Bezier(Verde)");
            ViewCheckBox *cb3 = new ViewCheckBox(ViewCheckBox::SHOW_BEZIER_GROUND, scv::Point(10,y+h*2), true, "Bezier(Branco)");
            ViewCheckBox *cb4 = new ViewCheckBox(ViewCheckBox::SHOW_BEZIER_GROUND_CP, scv::Point(10,y+h*3), false, "Pontos de Controle do Bezier(Branco)");
            ViewCheckBox *cb5 = new ViewCheckBox(ViewCheckBox::SHOW_CUBES, scv::Point(10,y+h*4), true, "Cubos");
            ViewCheckBox *cb6 = new ViewCheckBox(ViewCheckBox::SHOW_SPHERES, scv::Point(10,y+h*5), true, "Esferas");
            
            this->addComponent(label);
            this->addComponent(cb1);
            this->addComponent(cb2);
            this->addComponent(cb3);
            this->addComponent(cb4);
            this->addComponent(cb5);
            this->addComponent(cb6);
        }

        void initRandomBezierButtons()
        {
            std::string s = "Random Bezier(Branco)";
            RandomBezierButton *b1 = new RandomBezierButton(RandomBezierButton::BEZIER_GROUND, scv::Point(10,170), s.size()*6, s);
            RandomBezierButton *b2 = new RandomBezierButton(RandomBezierButton::BEZIER_PLANE, scv::Point(10,170+b1->getHeight()), s.size()*6, "Random Bezier(Verde)");

            b1->setCanvas(m_pCanvas);
            b2->setCanvas(m_pCanvas);

            this->addComponent(b1);
            this->addComponent(b2);
        }

        void helpLabels()
        {
            int y = 220;
            scv::Label *mov = new scv::Label(scv::Point(5,y), "Movimentacao:");
            scv::Label *ws = new scv::Label(scv::Point(10,y+mov->getHeight()), "w/s - frente/tras");
            scv::Label *ad = new scv::Label(scv::Point(10,y+mov->getHeight()*2), "a/d - esquerda/direita");
            scv::Label *zw = new scv::Label(scv::Point(10,y+mov->getHeight()*3), "z/x - cima/baixo");

            y += 5;

            scv::Label *rot = new scv::Label(scv::Point(5,y+mov->getHeight()*4), "Rotacao:");
            scv::Label *ik = new scv::Label(scv::Point(10,y+mov->getHeight()*5), "i/k - roll");
            scv::Label *jl = new scv::Label(scv::Point(10,y+mov->getHeight()*6), "j/l - yaw");
            scv::Label *uo = new scv::Label(scv::Point(10,y+mov->getHeight()*7), "u/o - pitch");

            this->addComponent(mov);
            this->addComponent(ws);
            this->addComponent(ad);
            this->addComponent(zw);

            this->addComponent(rot);
            this->addComponent(ik);
            this->addComponent(jl);
            this->addComponent(uo);
        }

    private:
        scv::ButtonGroup m_ProjButtonGroup;
        Canvas *m_pCanvas;

    }; //end of class Sidebar.
} //end of namespace GUI.

#endif
