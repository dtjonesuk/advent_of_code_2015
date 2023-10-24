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

/* TODO: Fix all the memory leaks all over the place */

class Node {
protected:
    unsigned int cachedValue;
    bool hasCachedValue = false;
public:
    unsigned short getValue() {
        if (hasCachedValue) {
            return cachedValue;
        }

        cachedValue = eval();

        hasCachedValue = true;
        return cachedValue;
    }
protected:
    virtual unsigned short eval() = 0;
};

class ExpressionNode : public Node {
public:
};

enum BinaryOp {
    AND,
    OR,
    LSHIFT,
    RSHIFT
};

enum UnaryOp {
    NOT
};

class WireNode : public ExpressionNode {
public:
    std::string identifier;
    Node *input = nullptr;


    explicit WireNode(const std::string &id) : identifier(id) {}

    virtual unsigned short eval() {
        if (input) {
            return input->getValue();
        } else {
            std::cerr << "Wire " << identifier << " has no input!" << std::endl;
        }
    }
};

class NumberNode : public ExpressionNode {
public:
    unsigned short value;

    NumberNode(const unsigned short val) : value(val) {}

    virtual unsigned short eval() {
        return value;
    }
};


class BinaryOpNode : public ExpressionNode {
public:
    Node* a;
    Node* b;
    BinaryOp op;

    explicit BinaryOpNode(BinaryOp op, WireNode* a, WireNode* b) : a(a), b(b), op(op) {}
    explicit BinaryOpNode(BinaryOp op, NumberNode &na, WireNode* b) : b(b), op(op) {
        a = new NumberNode(na);
    }
    explicit BinaryOpNode(BinaryOp op, WireNode* a, NumberNode &nb) : a(a),  op(op) {
        b = new NumberNode(nb);
    }

    virtual unsigned short eval() {

        unsigned short nA = a->getValue();
        unsigned short nB = b->getValue();

        switch (op) {
            case AND:
                return nA & nB;
            case OR:
                return nA | nB;
            case LSHIFT:
                return nA << nB;
            case RSHIFT:
                return nA >> nB;
            default:
                std::cerr << "Invalid binary op: " << op << std::endl;
                return 0;
        }
    }
};

class UnaryOpNode : public ExpressionNode {
public:
    Node* a;
    UnaryOp op;

    UnaryOpNode(UnaryOp op, WireNode* a) : a(a), op(op) {}

    virtual unsigned short eval() {
        unsigned short nA = a->getValue();

        switch (op) {
            case NOT:
                return ~nA;
            default:
                std::cerr << "Invalid unary op: " << op << std::endl;
                return 0;
        }
    }
};

class StatementNode : public Node {
public:
    ExpressionNode* expr;
    WireNode* output;

    StatementNode(ExpressionNode* expr, WireNode* output) : expr(expr), output(output) {
        output->input = expr;
    }

    virtual unsigned short eval() {
        return expr->getValue();
    }
};

class Parser {
public:
    std::map<std::string, WireNode> wires;
    std::vector<StatementNode*> statements;
private:
    std::ifstream input;
    std::string line;
    std::string currentLexeme;
    std::vector<std::string> lexemes;
    int nextLexemeIndex = 0;


public:
    Parser(const std::string &filename) : input(filename) {
    }

    void parse() {
        while (getNextLine()) {
            StatementNode* s = statement();
            statements.push_back(s);
        }
        std::cout << "Done parsing!" << std::endl;
    }

private:
    bool getNextLine() {
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


    bool advance() {
        if (nextLexemeIndex < lexemes.size()) {
            currentLexeme = lexemes[nextLexemeIndex];
            ++nextLexemeIndex;
            return true;
        } else {
            return false;
        }
    }

    bool isNumber() {
        return std::all_of(currentLexeme.begin(), currentLexeme.end(), isdigit);
    }

    bool isWire() {
        return std::all_of(currentLexeme.begin(), currentLexeme.end(), islower);
    }

    bool match(const std::string &str) {
        if (currentLexeme != str) {
            std::cerr << "Parser error!" << std::endl;
            return false;
        } else {
            return true;
        }
    }

    NumberNode number() {
        unsigned short n = stoi(currentLexeme);
        advance();
        return NumberNode{n};
    }

    WireNode *wire() {
        std::string identifier = currentLexeme;
        advance();
        if (!wires.contains(identifier)) {
            wires.insert({identifier, WireNode(identifier)});
        }
        return &wires.find(identifier)->second;
    }

    BinaryOp binaryOp() {
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

    ExpressionNode *expression() {
        if (isWire()) {
            WireNode* wa = wire();
            if (currentLexeme == "->") {
                return wa;
            }
            BinaryOp op = binaryOp();
            if (isWire()) {
                WireNode* wb = wire();
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
                WireNode* w = wire();
                return new BinaryOpNode(op, n, w);
            }
        } else {
            match("NOT");
            advance();
            WireNode* w = wire();
            return new UnaryOpNode(NOT, w);
        }
    }

    StatementNode* statement() {
        ExpressionNode *expr = expression();
        match("->");
        advance();
        WireNode* w = wire();

        return new StatementNode(expr, w);
    }

};


#endif //INC_2015_PARSER_H
