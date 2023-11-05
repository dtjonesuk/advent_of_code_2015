//
// Created by David on 04/11/2023.
//

#include <iostream>
#include <SDL.h>
#include "LightGrid.h"
#include "LightWindow.h"

void partOne() {
    const int width = 100;
    const int height = 100;
    const int scale = 10;
    const int number_of_steps = 100;
    int n = 0;

    std::ifstream input("..\\day18\\input.txt");

    LightGrid lightGrid(width, height);
    lightGrid.initialize();
    lightGrid.read_file(input);

    LightWindow window(lightGrid, width, height, scale);

    if (!window.initialize()) {
        std::cerr << "Could not initialize SDL window!" << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_Event e;
    while (true) {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            break;

        window.render();

        if (n < number_of_steps) {
            ++n;
//            std::cout << "Simulating step " << n << std::endl;
            lightGrid.simulate();
            _sleep(10);
        } else
            break;
    }

    std::cout << "Day 18: Part One = " << lightGrid.count() << std::endl;
}

void partTwo() {
    const int width = 100;
    const int height = 100;
    const int scale = 10;
    const int number_of_steps = 100;
    int n = 0;

    std::ifstream input("..\\day18\\input.txt");

    LightGrid lightGrid(width, height);
    lightGrid.initialize();
    lightGrid.read_file(input);

    // part two
    lightGrid.init_stuck();

    LightWindow window(lightGrid, width, height, scale);

    if (!window.initialize()) {
        std::cerr << "Could not initialize SDL window!" << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_Event e;
    while (true) {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            break;

        window.render();

        if (n < number_of_steps) {
            ++n;
//            std::cout << "Simulating step " << n << std::endl;
            lightGrid.simulate();
            _sleep(10);
        } else
            break;
    }

    std::cout << "Day 18: Part Two = " << lightGrid.count() << std::endl;
}

int main(int argc, char *argv[]) {
    partOne();
    partTwo();

    return 0;
}