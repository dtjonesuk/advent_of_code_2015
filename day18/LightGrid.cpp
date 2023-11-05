//
// Created by David on 05/11/2023.
//

#include "LightGrid.h"
#include <string>
#include <iostream>
#include <algorithm>

void LightGrid::initialize() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x].neighbours = find_neighbours(x, y);
//            std::cout << x << " " << y << ":" << grid[y][x].neighbours.size() << std::endl;
        }
    }
}

void LightGrid::simulate() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int n = grid[y][x].neighbour_count();
            if (grid[y][x].state) {
                if (!((n == 2) || (n == 3)))
                    grid[y][x].set_state(false);
            } else {
                if (n == 3)
                    grid[y][x].set_state(true);
            }
        }
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x].flip();
        }
    }
}

std::vector<Light *> LightGrid::find_neighbours(int x, int y) {
    std::vector<Light *> neighbours;
    for (int i = y - 1; i <= (y + 1); ++i)
        for (int j = x - 1; j <= (x + 1); ++j) {
            if ((i >= 0) && (i < height))
                if ((j >= 0) && (j < width))
                    if (!((i == y) && (j == x)))
                        neighbours.push_back(&grid[i][j]);
        }
    return neighbours;
}

void LightGrid::read_file(std::ifstream &file) {
    std::string line;

    int y = 0;
    while (std::getline(file, line) && (y < height)) {
        if (line.size() != width) {
            std::cerr << "Invalid input file!" << std::endl;
            return;
        }
        for (int x = 0; x < line.size(); ++x) {
            grid[y][x].state = line[x] == '#';
            grid[y][x].next_state = line[x] == '#';
        }
        ++y;
    }
}

int LightGrid::count() const {
    int total = 0;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x].state)
                ++total;
        }
    }
    return total;
}

void LightGrid::init_stuck() {
    std::vector<std::pair<int, int>> stuck_lights = {{0,          0},
                                                     {0,          width - 1},
                                                     {height - 1, 0},
                                                     {height - 1, width - 1}};

    for (auto [y, x]: stuck_lights) {
        grid[y][x].state = true;
        grid[y][x].stuck = true;
    }
}
