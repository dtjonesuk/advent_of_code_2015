//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_LIGHT_H
#define INC_2015_LIGHT_H

#include <vector>

class Light {
public:
    bool stuck{false};
    bool state{false};
    bool next_state{false};

    std::vector<Light*> neighbours;

    int neighbour_count() const;
    void set_state(bool new_state);
    void flip();
};


#endif //INC_2015_LIGHT_H
