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
    m_pSidebar = new Sidebar(0, 0, SIDEBAR_WIDTH, SIDEBAR_HEIGHT);
    m_pCanvas = new Canvas(SIDEBAR_WIDTH, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
}

void MainWindow::addElementsToKernel()
{
    scv::Kernel::getInstance()->addComponent(m_pSidebar);
    scv::Kernel::getInstance()->addComponent(m_pCanvas);
}
