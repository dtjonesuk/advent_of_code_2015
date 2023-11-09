//
// Created by David on 09/11/2023.
//

#include "Instruction.h"
#include <string>
#include <regex>
#include <stdexcept>
#include <iostream>

Instruction::Instruction(OpCode opcode, Register reg, int literal) : opcode(opcode), reg(reg), literal(literal) {

}

static const std::string instruction_regex = "(\\w+)(?:\\s+)(\\w+)?(?:,?)(?:\\s+)?([\\+-]?\\d+)?";

static Register get_register(const std::string &assembly) {
    if (assembly == "a") {
        return Register::a;
    } else if (assembly == "b") {
        return Register::b;
    }
    throw std::domain_error("Invalid register " + assembly);
}

Instruction::Instruction(std::string &assembly) {
    std::regex re(instruction_regex);
    std::smatch smatch;
    if (std::regex_match(assembly, smatch, re)) {
        std::string raw_opcode = smatch.str(1);
        if (raw_opcode == "inc") {
            opcode = OpCode::inc;
            reg = get_register(smatch.str(2));
        } else if (raw_opcode == "tpl") {
            opcode = OpCode::tpl;
            reg = get_register(smatch.str(2));
        } else if (raw_opcode == "hlf") {
            opcode = OpCode::hlf;
            reg = get_register(smatch.str(2));
        } else if (raw_opcode == "jmp") {
            opcode = OpCode::jmp;
            literal = std::stoi(smatch.str(3));
        } else if (raw_opcode == "jie") {
            opcode = OpCode::jie;
            reg = get_register(smatch.str(2));
            literal = std::stoi(smatch.str(3));
        } else if (raw_opcode == "jio") {
            opcode = OpCode::jio;
            reg = get_register(smatch.str(2));
            literal = std::stoi(smatch.str(3));
        }
    } else {
        throw std::domain_error("Invalid assembly " + assembly);
    }
}



std::string get_string(OpCode opcode) {
    if (opcode == OpCode::hlf) {
        return "hlf";
    } else if (opcode == OpCode::tpl) {
        return "tpl";
    } else if (opcode == OpCode::inc) {
        return "inc";
    } else if (opcode == OpCode::jmp) {
        return "jmp";
    } else if (opcode == OpCode::jie) {
        return "jie";
    } else if (opcode == OpCode::jio) {
        return "jio";
    }
    return "<invalid opcode>";
}

std::string get_string(Register reg) {
    if (reg == Register::a) {
        return "a";
    } else if (reg == Register::b) {
        return "b";
    }
    return "<invalid register>";
}

std::ostream& operator<<(std::ostream& ostream, Instruction instruction) {
    ostream << get_string(instruction.opcode) << " " << get_string(instruction.reg) << " " << instruction.literal;
    return ostream;
}
