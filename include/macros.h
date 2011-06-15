#ifndef _BRUNODEA_CG_T3_MAXROS_H_
#define _BRUNODEA_CG_T3_MAXROS_H_

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#define MODELVIEW ModelViewMatrixStack::instance()
#define PI 3.14159265

#define SIDEBAR_WIDTH 250
#define SIDEBAR_HEIGHT WINDOW_HEIGHT

#define CANVAS_WIDTH (WINDOW_WIDTH - SIDEBAR_WIDTH)
#define CANVAS_HEIGHT WINDOW_HEIGHT

#define PROJECTION Projection::instance()

#define DRAW_MANAGER DrawManager::instance()

#define MAIN_WINDOW MainWindow::instance()

#endif