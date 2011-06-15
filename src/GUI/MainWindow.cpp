/* Classe que, como o nome diz, quarda as informacoes da Janela Principal (Canvas e a Sidebar). */

#include "GUI/MainWindow.h"
#include "macros.h"

using namespace GUI;

MainWindow *MainWindow::m_sInstance = NULL;

MainWindow::MainWindow()
{
    init();

    addElementsToKernel();
}

MainWindow::~MainWindow()
{
    delete m_pSidebar;
    delete m_pCanvas;
}

void MainWindow::init()
{
    m_pCanvas = new Canvas(SIDEBAR_WIDTH, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
    m_pSidebar = new Sidebar(m_pCanvas, 0, 0, SIDEBAR_WIDTH, SIDEBAR_HEIGHT);
}

void MainWindow::addElementsToKernel()
{
    scv::Kernel::getInstance()->addComponent(m_pSidebar);
    scv::Kernel::getInstance()->addComponent(m_pCanvas);
}
