#ifndef _BRUNODEA_CG_T3_MAIN_WINDOW_H_
#define _BRUNODEA_CG_T3_MAIN_WINDOW_H_

#include "Sidebar/Sidebar.h"

namespace GUI
{
    class MainWindow
    {
    public:
        MainWindow();
        ~MainWindow();

    private:
        void initSidebar();
        void addElementsToKernel();

    private:
        Sidebar *m_pSideBar;

    }; //end of class MainWindow.
} //end of namespace GUI.

#endif
