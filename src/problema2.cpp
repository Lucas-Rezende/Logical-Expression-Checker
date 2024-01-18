#include <string>

#include "problema1.hpp"
#include "problema2.hpp"

problema1 p1;

problema2::problema2()
{
}

problema2::~problema2()
{
}

/**
 * \class checkProbabilities
 *
 * \brief Esse método constrói a árvore e chama o método responsável por encontrar a satisfabilidade.
 */
void problema2::checkProbabilities(std::string valuation, std::string expression)
{
    ArvoreBinaria mytree;
    mytree.insert(valuation);
    foundSatisfiability(mytree.getRoot(), valuation, expression);
}

/**
 * \class foundSatisfiability
 *
 * \brief Responsável por encontrar a valoração satisfazível através de várias verificações lógicas.
 */
void problema2::foundSatisfiability(No *no, std::string valuation, std::string expression)
{
    ArvoreBinaria temptree;
    std::string temp = temptree.printLeaves(no);

    std::string leaf1;
    std::string leaf2;
    std::string satisfyingValuation;
    bool found = false;
    bool allSatisfy = true;
    bool esatisfy = false;
    bool checkallsons = true;

    Pilha possibleE;

    for (char e : {'0', '1'})
    {
        for (char a : {'0', '1'})
        {

            std::string tempValuation = valuation;
            for (size_t i = 0; i < tempValuation.size(); ++i)
            {
                if (tempValuation[i] == 'e')
                    tempValuation[i] = e;
                if (tempValuation[i] == 'a')
                    tempValuation[i] = a;
            }
            size_t pos = 0;
            while ((pos = temp.find(" ")) != std::string::npos)
            {
                leaf1 = temp.substr(0, pos);
                temp.erase(0, pos + 1);
                pos = temp.find(" ");
                leaf2 = temp.substr(0, pos);
                temp.erase(0, pos + 1);

                if (evaluateSatisfiability(leaf1, expression))
                {
                    possibleE.pushs(std::string(1, leaf1[valuation.find('e')]));
                    if (!found)
                    {
                        satisfyingValuation = leaf1;
                        found = true;
                    }
                    if (evaluateSatisfiability(leaf1, expression) && evaluateSatisfiability(leaf2, expression) && checkallsons == true)
                    {
                        possibleE.pushs(std::string(1, leaf2[valuation.find('e')]));
                        if (found)
                        {
                            satisfyingValuation = valuation;
                            evaluateSatisfiability(satisfyingValuation, expression);
                        }
                    }
                    if ((evaluateSatisfiability(leaf1, expression) && evaluateSatisfiability(leaf2, expression)) && checkallsons == false)
                    {
                        possibleE.pushs(std::string(1, leaf2[valuation.find('e')]));
                        if (found)
                        {
                            tempValuation = leaf2;
                            esatisfy = true;
                        }
                    }
                    if ((evaluateSatisfiability(leaf1, expression) && !evaluateSatisfiability(leaf2, expression)) && valuation.find("a"))
                    {
                        if (found)
                        {
                            satisfyingValuation = valuation;
                            evaluateSatisfiability(satisfyingValuation, expression);
                            if (!evaluateSatisfiability(leaf2, expression))
                            {
                                std::cout << "0" << std::endl;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    if (evaluateSatisfiability(leaf2, expression))
                    {
                        size_t pos = valuation.find('e');
                        size_t pos2 = valuation.find('a');
                        if (pos != std::string::npos)
                        {
                            possibleE.pushs(std::string(1, leaf2[pos]));
                            if (!found)
                            {
                                satisfyingValuation = leaf2;
                                found = true;
                                allSatisfy = false;
                                checkallsons = false;
                            }
                            else
                            {
                                std::string result = "";
                                for (size_t i = 0; i < leaf1.size(); i++)
                                {
                                    if (leaf1[i] != leaf2[i])
                                    {
                                        if (leaf1[i] == 'a')
                                        {
                                            result += leaf2[i];
                                        }
                                        else if (leaf2[i] == 'a')
                                        {
                                            result += leaf1[i];
                                        }
                                        else
                                        {
                                            result += 'a';
                                        }
                                    }
                                    else
                                    {
                                        result += leaf1[i];
                                    }
                                }
                                leaf2 = result;
                                if (evaluateSatisfiability(leaf2, expression))
                                {
                                    esatisfy = true;
                                    allSatisfy = true;
                                    satisfyingValuation = valuation;
                                }
                                else
                                {
                                    std::cout << "0" << std::endl;
                                }
                            }
                        }
                        if (valuation.find('e') != std::string::npos)
                        {
                            if (!evaluateSatisfiability(leaf1, expression) && !evaluateSatisfiability(leaf2, expression))
                            {
                                std::cout << "0" << std::endl;
                                return;
                            }
                        }
                        else if (pos2 != std::string::npos)
                        {
                            std::cout << "0" << std::endl;
                            return;
                        }
                    }
                    else
                    {
                        std::cout << "0" << std::endl;
                        return;
                    }
                }
            }

            if (found)
            {
                if (esatisfy && allSatisfy)
                {
                    if (valuation.find('e') < valuation.find('a'))
                    {
                        std::cout << "0" << std::endl;
                        return;
                    }
                    else
                    {
                        for (size_t i = 0; i < valuation.size(); ++i)
                        {
                            if (valuation[i] == 'e')
                            {
                                bool temp = true;

                                valuation[i] = '0';
                                std::cout << valuation << std::endl;
                                if (!evaluateSatisfiability(valuation, expression))
                                {
                                    temp = false;
                                }

                                valuation[i] = '1';
                                std::cout << valuation << std::endl;
                                if (!evaluateSatisfiability(valuation, expression))
                                {
                                    temp = false;
                                }

                                if (temp)
                                {
                                    valuation[i] = 'a';
                                }
                                else
                                {
                                    size_t pos = valuation.find('e');
                                    if (pos != std::string::npos)
                                    {
                                        char e_val = tempValuation[pos];
                                        if (valuation[i] == 'e')
                                            valuation[i] = e_val;
                                    }
                                }
                            }
                        }
                        satisfyingValuation = valuation;
                        std::cout << "1 " << satisfyingValuation << std::endl;
                        return;
                    }
                }
                if (allSatisfy)
                {
                    for (size_t i = 0; i < valuation.size(); ++i)
                    {
                        if (valuation[i] == 'e')
                            valuation[i] = 'a';
                    }
                    satisfyingValuation = valuation;
                }
                if (esatisfy)
                {
                    char e_val = tempValuation[valuation.find('e')];
                    for (size_t i = 0; i < valuation.size(); ++i)
                    {
                        if (valuation[i] == 'e')
                            valuation[i] = e_val;
                    }
                    satisfyingValuation = valuation;
                }
                if (!allSatisfy && !esatisfy && valuation.find('a') != std::string::npos)
                {
                    std::cout << "0" << std::endl;
                    return;
                }

                std::cout << "1 " << satisfyingValuation << std::endl;
                return;
            }
        }
    }

    std::cout << "0" << std::endl;
}

/**
 * \class evaluateSatisfiability
 *
 * \brief avalia se uma expressão lógica é satisfatível com base em uma valoração dada, retornando verdadeiro se for satisfatível e falso caso contrário.
 */
bool problema2::evaluateSatisfiability(std::string valuation, std::string expression)
{
    std::string tempex = p1.infixToPostfix(expression, valuation);
    bool result = p1.evaluatePostfix(tempex);

    if (result)
    {
        bool check = p1.evaluatePostfix(valuation);
        if (check)
        {
            for (unsigned int i = 0; i < valuation.size(); i++)
            {
                if (valuation[i] == 'e')
                    valuation[i] = 'a';
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}