#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <regex>

#include "Molecule.h"

void print(auto transforms, auto molecule) {
    for (auto &[from, to]: transforms) {
        std::cout << from << " = " << to << std::endl;
    }

    std::cout << "\n" << molecule << std::endl;

}

void partOne() {
    std::ifstream input("..\\day19\\input.txt");

    // read the transforms
    std::multimap<Element, Molecule> transforms;
    std::string line;
    while (std::getline(input, line)) {
        // blank line indicates end of transforms
        if (line.size() == 0)
            break;

        // parse the transform
        std::regex re("(\\w+) => (\\w+)");
        std::smatch smatch;
        if (std::regex_match(line, smatch, re)) {
            std::string from = smatch.str(1);
            std::string to = smatch.str(2);

            transforms.insert({Element(from), Molecule(to)});
        }
    }

    // read the molecule
    std::getline(input, line);
    Molecule molecule(line);

    // print out what we have
//    print(transforms, molecule);

    std::set<Molecule> unique_molecules;

    for (auto it = molecule.elements.begin(); it != molecule.elements.end(); ++it) {
        auto replacements = transforms.equal_range(*it);
        for (auto it2 = replacements.first; it2 != replacements.second; ++it2) {
            auto &[element, replacement] = *it2;

            // create new molecule
            Molecule new_molecule = molecule;
            new_molecule.replace(std::distance(molecule.elements.begin(), it), replacement);
            // std::cout << element << " => " << replacement << std::endl;
            // std::cout << new_molecule << std::endl;
            unique_molecules.insert(new_molecule);
        }
    }

    std::cout << "Day 19: Part One=" << unique_molecules.size() << std::endl;
}



void partTwo() {
    std::ifstream input("..\\day19\\input.txt");

    // read the transforms
    std::multimap<Element, Molecule> transforms;
    std::string line;
    while (std::getline(input, line)) {
        // blank line indicates end of transforms
        if (line.size() == 0)
            break;

        // parse the transform
        std::regex re("(\\w+) => (\\w+)");
        std::smatch smatch;
        if (std::regex_match(line, smatch, re)) {
            std::string from = smatch.str(1);
            std::string to = smatch.str(2);

            transforms.insert({Element(from), Molecule(to)});
        }
    }

    // read the molecule
    std::getline(input, line);
    Molecule molecule(line);

    // print out what we have
//    print(transforms, molecule);

    std::set<Molecule> unique_molecules;

    for (auto it = molecule.elements.begin(); it != molecule.elements.end(); ++it) {
        auto replacements = transforms.equal_range(*it);
        for (auto it2 = replacements.first; it2 != replacements.second; ++it2) {
            auto &[element, replacement] = *it2;

            // create new molecule
            Molecule new_molecule = molecule;
            new_molecule.replace(std::distance(molecule.elements.begin(), it), replacement);
            // std::cout << element << " => " << replacement << std::endl;
            // std::cout << new_molecule << std::endl;
            unique_molecules.insert(new_molecule);
        }
    }

    std::cout << "Day 19: Part One=" << unique_molecules.size() << std::endl;
}

int main() {
    partOne();
    partTwo();

    return 0;
}