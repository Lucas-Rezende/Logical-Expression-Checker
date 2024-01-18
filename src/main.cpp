
#include "problema1.hpp"
#include "problema2.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    problema1 p1;
    problema2 p2;

    if (argc != 4 || (std::string(argv[1]) != "-a" && std::string(argv[1]) != "-s"))
    {
        std::cout << "Uso: " << argv[0] << " -a/-s \"expressao\" \"valores\""
                  << std::endl;
        return 1;
    }
    else
    {
        if (std::string(argv[1]) == "-a")
        {
            for (char &temp : std::string(argv[3]))
            {
                if ((temp != '1') && (temp != '0'))
                {
                    std::cout << "Você fez um input com valores diferentes de 0 ou 1, logo sua saída será incorreta. Esteja avisado das consequências." << std::endl;
                }
            }
            std::string expression = argv[2];
            std::string valuation = argv[3];

            std::string postfixExpression = p1.infixToPostfix(expression, valuation);
            int result = p1.evaluatePostfix(postfixExpression);

            std::cout << result << std::endl;
        }

        if (std::string(argv[1]) == "-s")
        {
            for (char &temp : std::string(argv[3]))
            {
                if ((temp != '1') && (temp != '0') && (temp != 'a') && (temp != 'e'))
                {
                    std::cout << "Você fez um input com valores diferentes de 0, 1, e, a.\nSua saída será incorreta, esteja avisado das consequências." << std::endl;
                }
            }
            std::string expression = argv[2];
            std::string valuation = argv[3];

            p2.checkProbabilities(valuation, expression);
        }
    }

    return 0;
}