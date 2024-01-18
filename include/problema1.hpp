#ifndef PROBLEMA1_H
#define PROBLEMA1_H

#include <iostream>
#include <string>

#include "pilha.hpp"

class problema1
{
private:

public:
    problema1(/* args */);
    ~problema1();

    bool eOperador(char c);
    bool isVariable(char c);
    int precedence(char op);
    
    std::string infixToPostfix(std::string infix, std::string valuation);
    int performOperation(char operation, int operand1, int operand2);
    
    int evaluatePostfix(std::string postfix);
};

#endif