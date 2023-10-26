#include <iostream>
#include <fstream>
#include <cassert>

#include "json.h"

using json = nlohmann::json;

double parseItem(json item) {
    double sum = 0.0;
    switch (item.type()) {
        case nlohmann::detail::value_t::object:
        case nlohmann::detail::value_t::array:
            for (auto& [key, val] : item.items()) {
                sum += parseItem(val);
            }
            break;
        case nlohmann::detail::value_t::number_unsigned:
        case nlohmann::detail::value_t::number_integer:
            sum += item.template get<int>();
            break;
        case nlohmann::detail::value_t::number_float:
            sum += item.template get<float>();
            break;
        default:
            // ignore everything else
            break;
    }
    return sum;
}

double parseItem2(json item) {
    double sum = 0.0;
    switch (item.type()) {
        case nlohmann::detail::value_t::object:
            // if object contains any value equalling 'red', we ignore
            for (auto& [key, val] : item.items()) {
                if (val.type()==nlohmann::detail::value_t::string && val.template get<std::string>() == "red")
                    return sum;
            }
            // fall through
        case nlohmann::detail::value_t::array:
            for (auto& [key, val] : item.items()) {
                sum += parseItem2(val);
            }
            break;
        case nlohmann::detail::value_t::number_unsigned:
        case nlohmann::detail::value_t::number_integer:
            sum += item.template get<int>();
            break;
        case nlohmann::detail::value_t::number_float:
            sum += item.template get<float>();
            break;
        default:
            // ignore everything else
            break;
    }
    return sum;
}

void partOne() {
    std::ifstream input("..\\day12\\input.json");
    json data = json::parse(input);

    double total = parseItem(data);

    std::cout << "Part One: " << total << std::endl;
}


void partTwo() {
    std::ifstream input("..\\day12\\input.json");
    json data = json::parse(input);

    double total = parseItem2(data);

    std::cout << "Part One: " << total << std::endl;
}

int main() {
    partOne();
    partTwo();
}