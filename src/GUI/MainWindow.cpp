#include "GUI/MainWindow.h"
#include "macros.h"

using namespace GUI;

MainWindow::MainWindow()
{
    initSidebar();

    addElementsToKernel();
}

MainWindow::~MainWindow()
{
    delete m_pSideBar;
}

void MainWindow::initSidebar()
{
    m_pSideBar = new Sidebar(0, 0, 100, WINDOW_HEIGHT);
}

void MainWindow::addElementsToKernel()
{
    scv::Kernel::getInstance()->addComponent(m_pSideBar);
}
