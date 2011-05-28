#ifndef _BRUNODEA_CG_T3_MAIN_WINDOW_H_
#define _BRUNODEA_CG_T3_MAIN_WINDOW_H_

#include "Sidebar/Sidebar.h"
#include "Canvas/Canvas.h"

namespace GUI
{
    class MainWindow
    {
    public:
        MainWindow();
        ~MainWindow();

    private:
        void init();
        void addElementsToKernel();

    private:
        Sidebar *m_pSidebar;
        Canvas *m_pCanvas;

    }; //end of class MainWindow.
} //end of namespace GUI.

#endif
