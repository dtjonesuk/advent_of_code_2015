//
// Created by David on 22/10/2023.
//

#include "Parser.h"

namespace day07 {

    Parser::Parser(const std::string &filename) : input(filename) {
    }

    void Parser::parse() {
        while (getNextLine()) {
            StatementNode *s = statement();
            statements.push_back(s);
        }
    }

    bool Parser::getNextLine() {
        if (std::getline(input, line)) {
            std::stringstream ss(line);
            std::string lexeme;

            lexemes.clear();
            nextLexemeIndex = 0;
            while (ss >> lexeme) {
                lexemes.push_back(lexeme);
            }

            advance();

            return true;
        } else
            return false;
    }

    bool Parser::advance() {
        if (nextLexemeIndex < lexemes.size()) {
            currentLexeme = lexemes[nextLexemeIndex];
            ++nextLexemeIndex;
            return true;
        } else {
            return false;
        }
    }

    bool Parser::isNumber() {
        return std::all_of(currentLexeme.begin(), currentLexeme.end(), isdigit);
    }

    bool Parser::isWire() {
        return std::all_of(currentLexeme.begin(), currentLexeme.end(), islower);
    }

    bool Parser::match(const std::string &str) {
        if (currentLexeme != str) {
            std::cerr << "Parser error!" << std::endl;
            return false;
        } else {
            return true;
        }
    }

    NumberNode Parser::number() {
        unsigned short n = stoi(currentLexeme);
        advance();
        return NumberNode{n};
    }

    WireNode *Parser::wire() {
        std::string identifier = currentLexeme;
        advance();
        if (!wires.contains(identifier)) {
            wires.insert({identifier, WireNode(identifier)});
        }
        return &wires.find(identifier)->second;
    }

    BinaryOp Parser::binaryOp() {
        BinaryOp op;
        if (currentLexeme == "AND")
            op = AND;
        else if (currentLexeme == "OR")
            op = OR;
        else if (currentLexeme == "LSHIFT")
            op = LSHIFT;
        else if (currentLexeme == "RSHIFT")
            op = RSHIFT;
        else {
            std::cerr << "Unrecognised binary operator " << currentLexeme << std::endl;
            return AND;
        }
        advance();
        return op;
    }

    ExpressionNode *Parser::expression() {
        if (isWire()) {
            WireNode *wa = wire();
            if (currentLexeme == "->") {
                return wa;
            }
            BinaryOp op = binaryOp();
            if (isWire()) {
                WireNode *wb = wire();
                return new BinaryOpNode(op, wa, wb);
            } else if (isNumber()) {
                NumberNode nb = number();
                return new BinaryOpNode(op, wa, nb);
            }
        } else if (isNumber()) {
            NumberNode n = number();
            if (currentLexeme == "->") {
                return new NumberNode(n);
            } else {
                BinaryOp op = binaryOp();
                WireNode *w = wire();
                return new BinaryOpNode(op, n, w);
            }
        } else {
            match("NOT");
            advance();
            WireNode *w = wire();
            return new UnaryOpNode(NOT, w);
        }
    }

    StatementNode *Parser::statement() {
        ExpressionNode *expr = expression();
        match("->");
        advance();
        WireNode *w = wire();

        return new StatementNode(expr, w);
    }
}