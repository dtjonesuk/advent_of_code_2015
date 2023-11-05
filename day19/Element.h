//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_ELEMENT_H
#define INC_2015_ELEMENT_H

#include <string>
#include <iostream>


struct Element {
    std::string symbol;

    Element(const std::string &symbol) : symbol(symbol) {}
};

bool operator<(const Element &a, const Element &b);

bool operator==(const Element &a, const Element &b);

std::ostream &operator<<(std::ostream &ostream, const Element &e);

#endif //INC_2015_ELEMENT_H
