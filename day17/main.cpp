#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<int> parse_input(std::ifstream &f) {
    std::string line;
    std::vector<int> ints;
    while (std::getline(f, line)) {
        ints.push_back(std::stoi(line));
    }
    return ints;
}

void findUniqueCombinations(int target, std::vector<int>& containers, std::vector<int>& currentCombination, int index, std::vector<std::vector<int>>& result) {
    if (target == 0) {
        result.push_back(currentCombination);
        return;
    }

    if (index == containers.size() || target < 0) {
        return;
    }

    // Include the current container in the combination
    currentCombination.push_back(containers[index]);
    findUniqueCombinations(target - containers[index], containers, currentCombination, index, result);
    currentCombination.pop_back();

    // Skip the current container and move to the next one
    findUniqueCombinations(target, containers, currentCombination, index + 1, result);

}

void permute(int target, const std::vector<int> &list, const std::vector<int> &remaining, int &total) {
    if (target == 0) {
        int sum = 0;
        for (int n : list) {
            sum += n;
            std::cout << n << "+";
        }
        std::cout << "=" << sum << std::endl;
        ++total;
        return;
    }
    for (auto it = remaining.begin(); it != remaining.end(); ++it) {
        if ((target-*it) >= 0) {
            std::vector<int> newList(list);
            std::vector<int> newRemaining(remaining);

            // add current int to list
            newList.push_back(*it);

            // remaining -= current int
            newRemaining.erase(std::find(newRemaining.begin(), newRemaining.end(), *it));
//            std::copy_if(remaining.begin(), remaining.end(), std::back_inserter(newRemaining),
//                         [=](int n) { return n != *it; });

            permute(target - *it, newList, newRemaining, total);
        }
    }
}

void partOne() {
    std::ifstream input("..\\day17\\input.txt");

    // std::vector<int> containers = parse_input(input);
    std::vector<int> containers = { 20, 15, 10, 5, 5};
    std::sort(containers.begin(), containers.end());

    for (int i : containers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int total = 0;
    std::vector<int> currentCombination;
    std::vector<std::vector<int>> result;
    // permute(25, {}, containers, total);
    findUniqueCombinations(25, containers, currentCombination, 0, result);

    for (const std::vector<int>& combination : result) {
        for (int i = 0; i < combination.size(); ++i) {
            std::cout << combination[i];
            if (i < combination.size() - 1) {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Part One: " << result.size() << std::endl;
}

void partTwo() {

}

int main() {
    partOne();
    partTwo();
}