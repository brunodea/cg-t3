#include <SCV/SCV.h>
#include "macros.h"
#include "GUI/MainWindow.h"

#include "Core/matrix_functions.hpp"

int main()
{
    scv::Kernel *kernel = scv::Kernel::getInstance();
    scv::ColorScheme *color_scheme = scv::ColorScheme::getInstance();

    color_scheme->loadScheme(scv::ColorScheme::clean);
    kernel->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    kernel->setWindowTitle("Synthetic Camera by Bruno Romero de Azevedo.");

    GUI::MainWindow *mainWindow = new GUI::MainWindow(); //para inicializar as componentes da tela.

    kernel->setFramesPerSecond(60);
    kernel->run();

    delete mainWindow;

    return 0;
}