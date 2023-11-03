//
// Created by David on 03/11/2023.
//

#ifndef INC_2015_AUNT_H
#define INC_2015_AUNT_H

#include <string>
#include <vector>
#include <map>

class Aunt {
public:
    Aunt(int id, const std::map<std::string, int> &props) : id(id), properties(props) {}
    Aunt(const std::string& input);

    int id;
    std::map<std::string, int> properties;
};


#endif //INC_2015_AUNT_H
