#include "GUI/MainWindow.h"
#include "macros.h"

using namespace GUI;

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
    int sidebar_w = 150;
    m_pSidebar = new Sidebar(0, 0, sidebar_w, WINDOW_HEIGHT);
    m_pCanvas = new Canvas(sidebar_w, 0, WINDOW_WIDTH - sidebar_w, WINDOW_HEIGHT);
}

void MainWindow::addElementsToKernel()
{
    scv::Kernel::getInstance()->addComponent(m_pSidebar);
    scv::Kernel::getInstance()->addComponent(m_pCanvas);
}
