//
// Created by David on 03/12/2023.
//

#ifndef INC_2015_NODE_H
#define INC_2015_NODE_H

#include <iostream>

namespace day07 {
    class Node {
    public:
        unsigned short getValue();

    protected:
        virtual unsigned short eval() = 0;

        unsigned int cachedValue;
        bool hasCachedValue = false;
    };

    class ExpressionNode : public Node {};

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


        explicit WireNode(const std::string &id);

        virtual unsigned short eval();
    };

    class NumberNode : public ExpressionNode {
    public:
        unsigned short value;

        NumberNode(const unsigned short val);

        virtual unsigned short eval();
    };


    class BinaryOpNode : public ExpressionNode {
    public:
        Node *a;
        Node *b;
        BinaryOp op;

        BinaryOpNode(BinaryOp op, WireNode *a, WireNode *b);

        BinaryOpNode(BinaryOp op, NumberNode &na, WireNode *b);

        BinaryOpNode(BinaryOp op, WireNode *a, NumberNode &nb);

        unsigned short eval() override;
    };

    class UnaryOpNode : public ExpressionNode {
    public:
        Node *a;
        UnaryOp op;

        UnaryOpNode(UnaryOp op, WireNode *a);

        unsigned short eval() override;
    };

    class StatementNode : public Node {
    public:
        ExpressionNode *expr;
        WireNode *output;

        StatementNode(ExpressionNode *expr, WireNode *output);

        unsigned short eval() override;
    };
}

#endif //INC_2015_NODE_H
