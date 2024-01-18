#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP

#include <iostream>

/**
 * \class No
 *
 * \brief Essa estrutura representa um nó em uma árvore binária.
 */
struct No
{
    std::string insertvaluation;
    std::string valuation;
    No *left;
    No *right;

    /**
     * \brief Construtor padrão da estrutura No.
     */
    No() : insertvaluation(""), left(nullptr), right(nullptr) {}

    /**
     * \brief Construtor da estrutura No que aceita um valor de string.
     *
     * \param valuation O valor de string a ser inserido no nó.
     */
    No(const std::string& valuation) : insertvaluation(valuation), left(nullptr), right(nullptr) {}
};

/**
 * \class ArvoreBinaria
 *
 * \brief Essa classe representa uma estrutura de dados do tipo Árvore Binária.
 */
class ArvoreBinaria
{
private:
    No *root;

public:
    /**
     * \brief Construtor da classe ArvoreBinaria.
     */
    ArvoreBinaria();

    /**
     * \brief Destrutor da classe ArvoreBinaria.
     */
    ~ArvoreBinaria();

    /**
     * \brief Deleta a árvore a partir de um nó especificado.
     *
     * \param currentNo O nó a partir do qual a árvore será deletada.
     */
    void deleteTree(No* currentNo);

    /**
     * \brief Retorna a raiz da árvore.
     *
     * \return O nó raiz da árvore.
     */
    No* getRoot();

    /**
     * \brief Verifica se a árvore está vazia.
     *
     * \return Verdadeiro se a árvore estiver vazia, falso caso contrário.
     */
    bool isEmpty();

    /**
     * \brief Verifica se a árvore está cheia.
     *
     * \return Verdadeiro se a árvore estiver cheia, falso caso contrário.
     */
    bool isFull();

    /**
     * \brief Insere um valor de string na árvore.
     *
     * \param valuation O valor de string a ser inserido na árvore.
     */
    void insert(std::string valuation);

    /**
     * \brief Insere um nó na árvore.
     *
     * \param no O nó a ser inserido na árvore.
     */
    void insert(No* no);

    /**
     * \brief Remove um valor de string da árvore.
     *
     * \param valuation O valor de string a ser removido da árvore.
     */
    void remove(std::string valuation);

    /**
     * \brief Busca um valor de string na árvore e retorna se foi encontrado ou não.
     *
     * \param valuation O valor de string a ser buscado na árvore.
     * \param rsearch Variável booleana que será verdadeira se o valor for encontrado, e falsa caso contrário.
     */
    void search(std::string& valuation, bool& rsearch);

    /**
     * \brief Realiza uma travessia em pré-ordem na árvore a partir de um nó especificado.
     *
     * \param p O nó a partir do qual a travessia em pré-ordem será realizada.
     */
    void PreOrdem(No* p);

    /**
     * \brief Realiza uma travessia em ordem na árvore a partir de um nó especificado.
     *
     * \param p O nó a partir do qual a travessia em ordem será realizada.
     */
    void InOrdem(No* p);

    /**
      *\brief Realiza uma travessia em pós-ordem na árvore a partir de um nó especificado. 
      *
      *\param p O nó a partir do qual a travessia em pós-ordem será realizada. 
      */ 
      void PosOrdem(No* p); 

      /** 
       *\brief Imprime as folhas da árvore. 
       *
       *\param no O nó inicial para começar a imprimir as folhas. 
       *\return Uma string contendo as folhas da árvore. 
       */ 
       std::string printLeaves(No* no); 
};


#endif