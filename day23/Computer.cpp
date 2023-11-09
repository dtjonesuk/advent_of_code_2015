//
// Created by David on 09/11/2023.
//

#include "Computer.h"

Computer::Computer(std::istream &input) {
    std::string line;
    while (std::getline(input, line)) {
        Instruction instruction(line);

        instructions.push_back(instruction);
    }
}

void Computer::run() {
    while ( (pc >= 0) && (pc < instructions.size())) {
        execute(instructions[pc]);
    }
}

void Computer::step() {
    if ((pc >= 0) && (pc < instructions.size())) {
        execute(instructions[pc]);
    }
}


void Computer::execute(Instruction i) {
    switch(i.opcode) {
        case OpCode::hlf:
            hlf(i.reg);
            ++pc;
            break;
        case OpCode::inc:
            inc(i.reg);
            ++pc;
            break;
        case OpCode::tpl:
            tpl(i.reg);
            ++pc;
            break;
        case OpCode::jmp:
            jmp(i.literal);
            break;
        case OpCode::jio:
            jio(i.reg, i.literal);
            break;
        case OpCode::jie:
            jie(i.reg, i.literal);
            break;
    }
}

void Computer::hlf(Register r) {
    reg(r) /= 2;
}

void Computer::tpl(Register r) {
    reg(r) *= 3;
}

void Computer::inc(Register r) {
    ++reg(r);
}

void Computer::jmp(int offset) {
    pc += offset;
}

void Computer::jie(Register r, int offset) {
    if (reg(r) % 2 == 0)
        pc += offset;
    else
        ++pc;
}

void Computer::jio(Register r, int offset) {
    if (reg(r) == 1)
        pc += offset;
    else
        ++pc;
}

int &Computer::reg(Register r) {
    switch (r) {
        case Register::a:
            return reg_a;
        case Register::b:
            return reg_b;
        default:
            throw std::domain_error("Invalid register #" + std::to_string(static_cast<int>(r)));
    }
}
