#ifndef PROBLEMA2_H
#define PROBLEMA2_H

#include <iostream>
#include <string>

#include "arvore.hpp"

class problema2
{
private:

public:
    problema2();
    ~problema2();

    void checkProbabilities(std::string valuation, std::string expression);
    void foundSatisfiability(No* no, std::string valuation, std::string expression);
    bool evaluateSatisfiability(std::string valuation, std::string expression);
};

#endif