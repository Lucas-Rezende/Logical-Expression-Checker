#include "problema1.hpp"

problema1::problema1()
{
}

problema1::~problema1()
{
}

/**
 * \class eOperador
 *
 * \brief Essa função verifica se o char é um operador.
 * Os operadores ∧, ∨ e ¬ serão representados, respectivamente por "&", "|"e "∼".
 */
bool problema1::eOperador(char c)
{
    return (c == '&' || c == '|' || c == '~');
}

/**
 * \class isVariable
 *
 * \brief Essa função verifica se o char é um integrante da fórmula lógica
 */
bool problema1::isVariable(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * \class precedence
 *
 * \brief Avalia a precedência de um elemento. Quanto maior o valor, maior sua precedência
 */
int problema1::precedence(char op)
{
    if (op == '~')
    {
        return 3;
    }
    else if (op == '&')
    {
        return 2;
    }
    else if (op == '|')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/**
 * \class infixToPostfix
 *
 * \brief Esse método é responsável por transformar a expressão entre aspas (infix) e convertê-la
 * para postfix, a fim de facilitar a aplicação da lógica.
 */
std::string problema1::infixToPostfix(std::string infix, std::string valuation)
{
    std::string cleanedInfix = "";
    for (size_t i = 0; i < infix.size(); ++i)
    {
        char c = infix[i];
        if (c == '~' && i + 1 < infix.size() && infix[i + 2] == '~')
        {
            ++i;
            ++i;
            ++i;
            continue;
        }
        cleanedInfix += c;
    }

    Pilha stack;
    std::string postfix = "";
    for (size_t i = 0; i < cleanedInfix.size(); ++i)
    {
        char c = cleanedInfix[i];
        if (isVariable(c))
        {
            std::string var = "";
            while (isVariable(c) && i < cleanedInfix.size())
            {
                var += c;
                ++i;
                c = cleanedInfix[i];
            }
            --i;
            int index = std::stoi(var);
            postfix += valuation[index];
        }
        else if (eOperador(c))
        {
            while (!stack.vazia() && precedence(c) < precedence(stack.topo()))
            {
                postfix += stack.pop();
            }
            stack.push(c);
        }
        else if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            while (!stack.vazia() && stack.topo() != '(')
            {
                postfix += stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.vazia())
    {
        postfix += stack.pop();
    }
    return postfix;
}

/**
 * \class performOperation
 *
 * \brief Esse método é responsável por, basicamente, aplicar a função dos operadores.
 * & - E
 *
 * | - OU
 *
 * ~ - Negação
 */
int problema1::performOperation(char operation, int operand1, int operand2 = 0)
{
    if (operation == '&')
    {
        return operand1 & operand2;
    }
    else if (operation == '|')
    {
        return operand1 | operand2;
    }
    else if (operation == '~')
    {
        return !operand1;
    }
    return -1;
}

/**
 * \class evaluatePostfix
 *
 * \brief Esse método é responsável por fazer uso da expressão postfix, filtrá-la e aplicar o performOperation para trazer o resultado.
 */
int problema1::evaluatePostfix(std::string postfix)
{
    Pilha stack;
    for (char &c : postfix)
    {
        if (eOperador(c))
        {
            int operand1 = stack.pop();
            int operand2 = 0;
            if (!stack.vazia() && c!= '~')
            {
                operand2 = stack.pop();
            }
            int result = performOperation(c, operand1, operand2);
            stack.push(result);
        }
        else
        {
            stack.push(c - '0');
        }
    }
    return stack.pop();
}