//
// Created by David on 01/11/2023.
//
#include "Person.h"

std::ostream &operator<<(std::ostream &ostream, const Person &p) {
    ostream << p.name << ":\n";
    for (auto &[name, value]: p.sentiments)
        ostream << name << " : " << value << "\n";
    return ostream;
}