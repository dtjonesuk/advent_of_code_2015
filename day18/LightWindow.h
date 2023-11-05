//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_LIGHTWINDOW_H
#define INC_2015_LIGHTWINDOW_H

#include <SDL.h>
#include "LightGrid.h"

class LightWindow {
public:
    LightWindow(LightGrid &grid, const int x, const int y, const int scale = 10) : lightGrid(grid), scale(scale),
                                                                                  width(x), height(y) {}

    bool initialize();

    void destroy();

    void render();

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    LightGrid &lightGrid;
    const int scale;
    const int height;
    const int width;
};


#endif //INC_2015_LIGHTWINDOW_H
