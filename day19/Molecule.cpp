//
// Created by David on 05/11/2023.
//

#include "Molecule.h"
#include <algorithm>

Molecule::Molecule(const std::string input) {
    for (auto it = input.begin(); it != input.end(); ) {
        auto start = it;

        // look ahead
        do {
            ++it;
        }while ((it != input.end()) && (std::islower(*it)));

        std::string symbol(start, it);
        elements.push_back({symbol});
    }
}

void Molecule::replace(int pos, Molecule molecule) {
    auto it = elements.erase(elements.begin() + pos);
    elements.insert(it, molecule.elements.begin(), molecule.elements.end());
}

std::ostream &operator<<(std::ostream &ostream, const Molecule &m) {
    for (Element e: m.elements) {
        ostream << e << " ";
    }
    return ostream;
}

bool operator<(const Molecule &a, const Molecule &b) {
    return a.elements < b.elements;
}
