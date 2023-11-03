//
// Created by David on 03/11/2023.
//

#include "Aunt.h"
#include <regex>

Aunt::Aunt(const std::string &input) {
    std::regex re("Sue (\\d+)");
    std::smatch smatch;
    if (std::regex_search(input, smatch, re)) {
        id = std::stoi(smatch.str(1));
        // std::cout << "Aunt " << n << " - ";
        re.assign("(\\w+): (\\d+)");
        for (auto i = std::sregex_iterator(input.begin(), input.end(), re); i != std::sregex_iterator(); ++i) {
            smatch = *i;

            std::string property = smatch.str(1);
            int value = std::stoi(smatch.str(2));

            properties[property] = value;
            // std::cout << property << ": " << value << ", ";
        }
        // std::cout << std::endl;
    } else {
        throw std::exception("Unable to parse input for Aunt.");
    }
}
