#include <SCV/SCV.h>
#include "macros.h"

int main()
{
    scv::Kernel *kernel = scv::Kernel::getInstance();
    scv::ColorScheme *color_scheme = scv::ColorScheme::getInstance();

    color_scheme->loadScheme(scv::ColorScheme::clean);
    kernel->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    kernel->setWindowTitle("Synthetic Camera by Bruno Romero de Azevedo.");


    kernel->setFramesPerSecond(60);
    kernel->run();

    return 0;
}