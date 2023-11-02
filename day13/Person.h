//
// Created by David on 30/10/2023.
//

#ifndef INC_2015_PERSON_H
#define INC_2015_PERSON_H
#include<string>
#include<iostream>
#include<vector>
#include <array>
#include <map>

struct Person {
    std::string name;
    std::map<std::string, int> sentiments;
};

std::ostream &operator<<(std::ostream &ostream, const Person &p);

#endif //INC_2015_PERSON_H
