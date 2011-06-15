/* Classe MainWindow: classe que ajusta os componentes da janela. */

#ifndef _BRUNODEA_CG_T3_MAIN_WINDOW_H_
#define _BRUNODEA_CG_T3_MAIN_WINDOW_H_

#include "Sidebar/Sidebar.h"
#include "Canvas/Canvas.h"

namespace GUI
{
    class MainWindow
    {
    public:
        ~MainWindow();

        static MainWindow *instance()
        {
            if(m_sInstance == NULL)
                m_sInstance = new MainWindow();
            return m_sInstance;
        }

        Canvas *getCanvas() { return m_pCanvas; }

    private:
        MainWindow();

        void init();
        void addElementsToKernel();

    private:
        static MainWindow *m_sInstance;

        Sidebar *m_pSidebar;
        Canvas *m_pCanvas;

    }; //end of class MainWindow.
} //end of namespace GUI.

#endif
