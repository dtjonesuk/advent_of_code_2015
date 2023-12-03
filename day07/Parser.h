//
// Created by David on 22/10/2023.
//

#ifndef INC_2015_PARSER_H
#define INC_2015_PARSER_H

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>
#include "Node.h"

/* TODO: Fix all the memory leaks all over the place */

namespace day07 {

    class Parser {
    public:
        Parser(const std::string &filename);

        void parse();

        std::map<std::string, WireNode> wires;
        std::vector<StatementNode *> statements;

    private:
        bool getNextLine();


        bool advance();

        bool isNumber();

        bool isWire();

        bool match(const std::string &str);

        NumberNode number();

        WireNode *wire();

        BinaryOp binaryOp();

        ExpressionNode *expression();

        StatementNode *statement();

        std::ifstream input;
        std::string line;
        std::string currentLexeme;
        std::vector<std::string> lexemes;
        int nextLexemeIndex = 0;
    };

}
#endif //INC_2015_PARSER_H
