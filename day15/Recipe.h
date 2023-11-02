//
// Created by David on 02/11/2023.
//

#ifndef INC_2015_RECIPE_H
#define INC_2015_RECIPE_H

#include <string>
#include <map>
#include <vector>

struct Ingredient {
    Ingredient() = default;
    Ingredient(const std::string &s);

    std::string name;
    int capacity{0};
    int durability{0};
    int flavor{0};
    int texture{0};
    int calories{0};
};

class Recipe {

public:
    std::string name;
    std::map<std::string, Ingredient> ingredients;

    Recipe() = default;

    long find_best_score();
    long find_best_score_for_calories(int calories);

private:
    void permute(int n, const std::vector<int> &list, void (Recipe::*handle_permutation) (const std::vector<int> &));
    void part_one(const std::vector<int> &permutation);
    void part_two(const std::vector<int> &permutation);
    long score(const std::vector<int> &percentages) const;
    int calories(const std::vector<int> &percentages) const;


    int caloriesRequired{0};
    long bestScore{0};
    std::vector<int> bestPermutation;
};


#endif //INC_2015_RECIPE_H
