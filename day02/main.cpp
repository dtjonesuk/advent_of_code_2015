#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cassert>

/* find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. The elves also need a little extra paper for each present: the area of the smallest side. */
int paperRequired(int length, int width, int height) {
    int required = (2 * length * width) + (2 * width * height) + (2 * height * length);
    int slack = std::min({length * width, width * height, height * length});

    return (required + slack);
}

/* The ribbon required to wrap a present is the shortest distance around its sides, or the smallest perimeter of any one face.
 * Each present also requires a bow made out of ribbon as well; the feet of ribbon required for the perfect bow is equal to the cubic feet of volume of the present. */
int ribbonRequired(int length, int width, int height) {
    int shortestPerimeter = std::min({2 * (length + width), 2 * (width + height), 2 * (height + length)});
    int volume = length * width * height;

    return (shortestPerimeter + volume);
}

void testPaperRequired() {
    assert(paperRequired(2, 3, 4) == 58);
    assert(paperRequired(1, 1, 10) == 43);
}

void testRibbonRequired() {
    assert(ribbonRequired(2, 3, 4) == 34);
    assert(ribbonRequired(1,1,10) == 14);
}

void partOne() {
    std::ifstream input("..\\day02\\input.txt");
    std::string line;
    int totalRequired = 0;

    while (std::getline(input, line)) {
        std::stringstream ss(line);
        int length, width, height;
        char x;

        if (ss >> length >> x >> width >> x >> height) {
            int paper = paperRequired(length, width, height);
            totalRequired += paper;
        } else {
            std::cerr << "Invalid input detected!" << std::endl;
            exit(1);
        }

    }

    std::cout << "Part One: total required = " << totalRequired << std::endl;

}

void partTwo() {
    std::ifstream input("..\\day02\\input.txt");
    std::string line;
    int totalRequired = 0;

    while (std::getline(input, line)) {
        std::stringstream ss(line);
        int length, width, height;
        char x;

        if (ss >> length >> x >> width >> x >> height) {
            int ribbon = ribbonRequired(length, width, height);
            totalRequired += ribbon;
        } else {
            std::cerr << "Invalid input detected!" << std::endl;
            exit(1);
        }

    }

    std::cout << "Part Two: total required = " << totalRequired << std::endl;
}


int main() {
    testPaperRequired();
    testRibbonRequired();

    partOne();
    partTwo();
}