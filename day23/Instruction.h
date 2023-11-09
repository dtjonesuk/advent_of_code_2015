//
// Created by David on 09/11/2023.
//

#ifndef INC_2015_INSTRUCTION_H
#define INC_2015_INSTRUCTION_H
#include <string>

enum class OpCode {
    hlf,
    tpl,
    inc,
    jmp,
    jie,
    jio,
};

enum class Register {
    a,
    b
};


struct Instruction {
public:
    Instruction(OpCode opcode, Register reg, int literal);
    explicit Instruction(std::string &assembly);

    OpCode opcode;
    Register reg;
    int literal{0};
};

std::string get_string(OpCode opcode);
std::string get_string(Register reg);
std::ostream& operator<<(std::ostream& ostream, Instruction instruction);

#endif //INC_2015_INSTRUCTION_H
