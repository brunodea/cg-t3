#include <SCV/SCV.h>
#include "macros.h"
#include "GUI/MainWindow.h"
#include "Util/ModelViewMatrixStack.h"

void help()
{
    std::cout << "-----------Camera Sintetica-------por Bruno Romero de Azevedo.\n";
    std::cout << " -Com a Canvas em foco:\n";
    std::cout << "1. Movimentacao da camera:\n";
    std::cout << "1.1 'w'/'s': frente/tras.\n";
    std::cout << "1.2 'a'/'d': esquerda/direita.\n";
    std::cout << "1.3 'z'/'x': cima/baixa.\n";
}

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
    delete Util::MODELVIEW;

    return 0;
}