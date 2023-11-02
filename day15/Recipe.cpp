//
// Created by David on 02/11/2023.
//

#include "Recipe.h"
#include <regex>
#include <cassert>
#include <numeric>
#include <iostream>

const static std::string ingredientExpression = "([A-Z]\\w+)\\: capacity (-?\\d+), durability (-?\\d+), flavor (-?\\d+), texture (-?\\d+), calories (-?\\d+)";

Ingredient::Ingredient(const std::string &s) {
    std::regex re(ingredientExpression);
    std::smatch match;
    if (std::regex_search(s, match, re)) {
        name = match.str(1);
        capacity= stoi(match.str(2));
        durability= stoi(match.str(3));
        flavor = stoi(match.str(4));
        texture = stoi(match.str(5));
        calories = stoi(match.str(6));
    }
}

long Recipe::score(const std::vector<int> &percentages) const {
    long capacity{0};
    long durability{0};
    long flavor{0};
    long texture{0};

    assert(ingredients.size() == percentages.size());

    //accumulate ingredient properties multiplied by ingredient percentage
    auto i = ingredients.begin();
    auto p = percentages.begin();
    for (; i != ingredients.end(); ++i, ++p) {
        capacity += (*p)*(i->second.capacity);
        durability += (*p)*(i->second.durability);
        flavor += (*p)*(i->second.flavor);
        texture += (*p)*(i->second.texture);
    }

    // zero any negative number
    if ((capacity < 0) || (durability < 0) || (flavor < 0) || (texture < 0))
        return 0;

    // score is product of property totals
    return (capacity * durability * flavor * texture);
}

int Recipe::calories(const std::vector<int> &percentages) const {
    int calories{0};

    assert(ingredients.size() == percentages.size());

    //accumulate ingredient properties multiplied by ingredient percentage
    auto i = ingredients.begin();
    auto p = percentages.begin();
    for (; i != ingredients.end(); ++i, ++p) {
        calories += (*p)*(i->second.calories);
    }

    return calories;
}

void Recipe::permute(int n, const std::vector<int> &list, void (Recipe::*handle_permutation) (const std::vector<int> &)) {
    int curTotal = std::accumulate(list.begin(), list.end(), 0);

    if (n == 1) {
        int i = 100 - curTotal;
        std::vector<int> newList{list};
        newList.push_back(i);
        (this->*handle_permutation)(newList);
        return;
    } else {
        for (int i = 0; i <= (100 - curTotal); ++i) {
            std::vector<int> newList{list};
            newList.push_back(i);

            permute(n - 1, newList, handle_permutation);
        }
    }
}

void print(const std::vector<int> &list) {
    for (int n: list) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
}

void Recipe::part_one(const std::vector<int> &permutation) {
    int s = score(permutation);
    if (s > bestScore) {
        bestScore = s;
        bestPermutation = permutation;
    }
}

void Recipe::part_two(const std::vector<int> &permutation) {
    int c = calories(permutation);
    if (c == caloriesRequired) {
        int s = score(permutation);
        if (s > bestScore) {
            bestScore = s;
            bestPermutation = permutation;
        }
    }
}

long Recipe::find_best_score() {
    bestScore = 0;
    bestPermutation.clear();
    int length = static_cast<int>(ingredients.size());
    permute(length, {}, &Recipe::part_one);
    return bestScore;
}

long Recipe::find_best_score_for_calories(int calories) {
    caloriesRequired = calories;
    bestScore = 0;
    bestPermutation.clear();
    int length = static_cast<int>(ingredients.size());
    permute(length, {}, &Recipe::part_two);
    return bestScore;
}
