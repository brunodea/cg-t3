/* Bruno Romnero de Azevedo - 2910098 */


#include <SCV/SCV.h>
#include "macros.h"
#include "GUI/MainWindow.h"
#include "Util/ModelViewMatrixStack.h"

int main()
{
    scv::Kernel *kernel = scv::Kernel::getInstance();
    scv::ColorScheme *color_scheme = scv::ColorScheme::getInstance();

    color_scheme->loadScheme(scv::ColorScheme::clean);
    kernel->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    kernel->setWindowTitle("Synthetic Camera by Bruno Romero de Azevedo.");
    
    GUI::MAIN_WINDOW; //para inicializar as componentes da tela.

    kernel->setFramesPerSecond(60);
    kernel->run();

    delete GUI::MAIN_WINDOW;
    delete Util::MODELVIEW;
    delete Util::DRAW_MANAGER;

    return 0;
}