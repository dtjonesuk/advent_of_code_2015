//
// Created by David on 05/11/2023.
//

#include "Light.h"
#include <algorithm>

int Light::neighbour_count() const {
    return std::count_if(neighbours.begin(), neighbours.end(), [](Light *l) {
        return l->state;
    });
}

void Light::set_state(bool new_state) {
    if (!stuck)
        next_state = new_state;
}

void Light::flip() {
    if (!stuck)
        state = next_state;
}
