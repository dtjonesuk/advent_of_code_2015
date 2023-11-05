//
// Created by David on 05/11/2023.
//

#include "LightWindow.h"

bool LightWindow::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
//        std::cerr << "Could not initialize SDL!  Error: " << SDL_GetError() << std::endl;
//        exit(1);
    }
    window = SDL_CreateWindow("Day 18", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width * scale, height * scale,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        return false;
//        std::cerr << "Could not create window!  Error: " << SDL_GetError() << std::endl;
//        exit(2);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        return false;
    }
}

void LightWindow::destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void LightWindow::render() {
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xaa, 0xff);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (lightGrid.grid[y][x].state) {
                SDL_Rect r(x*scale, y*scale, scale, scale);
                SDL_RenderDrawRect(renderer, &r);
            }
        }
    }

    SDL_RenderPresent(renderer);
}
