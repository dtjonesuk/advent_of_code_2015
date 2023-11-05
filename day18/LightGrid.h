//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_LIGHTGRID_H
#define INC_2015_LIGHTGRID_H
#include "Light.h"

#include <vector>
#include <fstream>

class LightGrid {
public:
    LightGrid(int x_size, int y_size) : width(x_size), height(y_size) {
        grid.resize(y_size, std::vector<Light>(x_size));
    }

    void read_file(std::ifstream &file);
    void initialize();
    void init_stuck();
    void simulate();
    int count() const;
    std::vector<std::vector<Light>> grid;

private:
    int width;
    int height;

    std::vector<Light *> find_neighbours(int x, int y);
};


#endif //INC_2015_LIGHTGRID_H
