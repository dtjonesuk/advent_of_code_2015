//
// Created by David on 02/11/2023.
//
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include "Recipe.h"


void test() {
    std::ifstream input("..\\day15\\test.txt");
    std::string line;

    Recipe recipe;
    while (std::getline(input, line)) {
        Ingredient i(line);
        recipe.ingredients[i.name] = i;
    }

    long score = recipe.find_best_score();
    // std::cout << "Best Score: " << score << std::endl;

    // assert(recipe.score({44, 56}) == 62842880);

}

void partOne() {
    std::ifstream input("..\\day15\\input.txt");
    std::string line;

    Recipe recipe;
    while (std::getline(input, line)) {
        Ingredient i(line);
        recipe.ingredients[i.name] = i;
    }

    long score = recipe.find_best_score();
    std::cout << "Part One: " << score << std::endl;
}

void partTwo() {
    std::ifstream input("..\\day15\\input.txt");
    std::string line;

    Recipe recipe;
    while (std::getline(input, line)) {
        Ingredient i(line);
        recipe.ingredients[i.name] = i;
    }

    long score = recipe.find_best_score_for_calories(500);
    std::cout << "Part Two: " << score << std::endl;
}

int main() {
    //test();
    partOne();
    partTwo();
}