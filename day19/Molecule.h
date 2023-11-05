//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_MOLECULE_H
#define INC_2015_MOLECULE_H

#include "Element.h"
#include <iostream>
#include <vector>

class Molecule {
public:
    Molecule(const std::string input);

    std::vector<Element> elements;

    void replace(int pos,
                 Molecule molecule);
};

std::ostream &operator<<(std::ostream &ostream, const Molecule &m);
bool operator<(const Molecule &a, const Molecule &b);

#endif //INC_2015_MOLECULE_H
