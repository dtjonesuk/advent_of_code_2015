//
// Created by David on 05/11/2023.
//

#include "Element.h"

bool operator<(const Element &a, const Element &b) {
    return a.symbol < b.symbol;
}

bool operator==(const Element &a, const Element &b) {
    return a.symbol == b.symbol;
}

std::ostream &operator<<(std::ostream &ostream, const Element &e) {
    ostream << e.symbol;
    return ostream;
}