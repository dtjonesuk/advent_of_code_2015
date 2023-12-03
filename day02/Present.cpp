//
// Created by David on 03/12/2023.
//

#include "Present.h"

/// find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. The elves also need a little extra paper for each present: the area of the smallest side.

int Present::paperRequired() {
    int required = (2 * length * width) + (2 * width * height) + (2 * height * length);
    int slack = std::min({length * width, width * height, height * length});

    return (required + slack);
}

/// The ribbon required to wrap a present is the shortest distance around its sides, or the smallest perimeter of any one face.
/// Each present also requires a bow made out of ribbon as well; the feet of ribbon required for the perfect bow is equal to the cubic feet of volume of the present.

int Present::ribbonRequired() {
    int shortestPerimeter = std::min({2 * (length + width), 2 * (width + height), 2 * (height + length)});
    int volume = length * width * height;

    return (shortestPerimeter + volume);
}
