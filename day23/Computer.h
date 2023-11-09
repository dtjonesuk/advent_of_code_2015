//
// Created by David on 09/11/2023.
//

#ifndef INC_2015_COMPUTER_H
#define INC_2015_COMPUTER_H
#include <string>
#include <vector>
#include <istream>

#include "Instruction.h"

class Computer {
public:
    explicit Computer(std::istream &input);

    void run();
    void step();
    int& reg(Register r);

private:
    void execute(Instruction i);
    void hlf(Register r);
    void tpl(Register r);
    void inc(Register r);
    void jmp(int offset);
    void jie(Register r, int offset);
    void jio(Register r, int offset);

public:
    std::vector<Instruction> instructions;
    int reg_a{0};
    int reg_b{0};
    int pc{0};
};


#endif //INC_2015_COMPUTER_H
