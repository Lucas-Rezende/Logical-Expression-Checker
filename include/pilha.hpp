#include <string>

#ifndef PILHA_H
#define PILHA_H

/**
 * \class Pilha
 *
 * \brief Essa classe representa uma estrutura de dados do tipo Pilha.
 */
class Pilha
{
public:
    /**
     * \brief Construtor da classe Pilha.
     */
    Pilha();

    /**
     * \brief Destrutor da classe Pilha.
     */
    ~Pilha();

    /**
     * \brief Insere um elemento inteiro no topo da pilha.
     *
     * \param valor O valor inteiro a ser inserido.
     */
    void push(int valor);

    /**
     * \brief Remove e retorna o elemento inteiro do topo da pilha.
     *
     * \return O valor inteiro removido do topo da pilha.
     */
    int pop();

    /**
     * \brief Verifica se a pilha de inteiros está vazia.
     *
     * \return Verdadeiro se a pilha estiver vazia, falso caso contrário.
     */
    bool vazia();

    /**
     * \brief Retorna o valor inteiro do topo da pilha sem removê-lo.
     *
     * \return O valor inteiro no topo da pilha.
     */
    int topo();

    /**
     * \brief Insere um elemento string no topo da pilha.
     *
     * \param valor O valor string a ser inserido.
     */
    void pushs(std::string valor);

    /**
     * \brief Remove e retorna o elemento string do topo da pilha.
     *
     * \return O valor string removido do topo da pilha.
     */
    std::string pops();

    /**
     * \brief Verifica se a pilha de strings está vazia.
     *
     * \return Verdadeiro se a pilha estiver vazia, falso caso contrário.
     */
    bool vazias();

    /**
     * \brief Retorna o valor string do topo da pilha sem removê-lo.
     *
     * \return O valor string no topo da pilha.
     */
    std::string topos();

private:
    struct No
    {
        int valor;      ///< Valor inteiro armazenado no nó.
        No *proximo;  ///< Ponteiro para o próximo nó na pilha de inteiros.
    };

    struct Nos
    {
        std::string valors;  ///< Valor string armazenado no nó.
        Nos *proximos;  ///< Ponteiro para o próximo nó na pilha de strings.
    };

    No *top;   ///< Ponteiro para o topo da pilha de inteiros.
    Nos *tops; ///< Ponteiro para o topo da pilha de strings.
};
;

#endif