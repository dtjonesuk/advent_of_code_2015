//
// Created by David on 03/12/2023.
//

#include "Node.h"

namespace day07 {
    unsigned short Node::getValue() {
        if (hasCachedValue) {
            return cachedValue;
        }

        cachedValue = eval();

        hasCachedValue = true;
        return cachedValue;
    }

    WireNode::WireNode(const std::string &id) : identifier(id) {}

    unsigned short WireNode::eval() {
        if (input) {
            return input->getValue();
        } else {
            std::cerr << "Wire " << identifier << " has no input!" << std::endl;
        }
    }

    NumberNode::NumberNode(const unsigned short val) : value(val) {}

    unsigned short NumberNode::eval() {
        return value;
    }

    BinaryOpNode::BinaryOpNode(BinaryOp op, WireNode *a, WireNode *b) : a(a), b(b), op(op) {}

    BinaryOpNode::BinaryOpNode(BinaryOp op, NumberNode &na, WireNode *b) : b(b), op(op) {
        a = new NumberNode(na);
    }

    BinaryOpNode::BinaryOpNode(BinaryOp op, WireNode *a, NumberNode &nb) : a(a), op(op) {
        b = new NumberNode(nb);
    }

    unsigned short BinaryOpNode::eval() {

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

    UnaryOpNode::UnaryOpNode(UnaryOp op, WireNode *a) : a(a), op(op) {}

    unsigned short UnaryOpNode::eval() {
        unsigned short nA = a->getValue();

        switch (op) {
            case NOT:
                return ~nA;
            default:
                std::cerr << "Invalid unary op: " << op << std::endl;
                return 0;
        }
    }

    StatementNode::StatementNode(ExpressionNode *expr, WireNode *output) : expr(expr), output(output) {
        output->input = expr;
    }

    unsigned short StatementNode::eval() {
        return expr->getValue();
    }
}