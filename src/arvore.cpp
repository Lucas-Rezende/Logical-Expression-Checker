#include "arvore.hpp"

ArvoreBinaria::ArvoreBinaria()
{
    root = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
}

void ArvoreBinaria::deleteTree(No *currentNo)
{
}

No *ArvoreBinaria::getRoot()
{
    return root;
}

bool ArvoreBinaria::isEmpty()
{
    return (root == NULL);
}

bool ArvoreBinaria::isFull()
{
    try
    {
        No *temp = new No;
        delete temp;
        return false;
    }
    catch (const std::exception &e)
    {
        return true;
    }
}

void ArvoreBinaria::insert(std::string valuation)
{
    root = new No(valuation);
    insert(root);
}

void ArvoreBinaria::insert(No* no)
{
    for (unsigned int i = 0; i < no->insertvaluation.size(); i++)
    {
        if (no->insertvaluation[i] == 'e' || no->insertvaluation[i] == 'a')
        {
            std::string leftValuation = no->insertvaluation;
            leftValuation[i] = '0';
            no->left = new No(leftValuation);
            insert(no->left);

            std::string rightValuation = no->insertvaluation;
            rightValuation[i] = '1';
            no->right = new No(rightValuation);
            insert(no->right);
            break;
        }
    }
}

void ArvoreBinaria::remove(std::string valuation)
{
    No *parent = nullptr;
    No *current = root;
    while (current != nullptr && current->insertvaluation != valuation)
    {
        parent = current;
        if (valuation < current->insertvaluation)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == nullptr)
    {
        return;
    }

    if (current->left == nullptr && current->right == nullptr)
    {
        if (current != root)
        {
            if (parent->left == current)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        else
        {
            root = nullptr;
        }
        delete current;
    }
    else if (current->left && current->right)
    {
        if (current != root)
        {
            if (parent->left == current)
            {
                parent->left = current->left;
            }
            else
            {
                parent->right = current->left;
            }
        }
        else
        {
            root = current->left;
        }
        No *temp = current->left;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        temp->right = current->right;

        delete current;
    }
    else
    {
        No *child = (current->left) ? current->left : current->right;
        if (current != root)
        {
            if (current == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        else
        {
            root = child;
        }
        delete current;
    }
}

void ArvoreBinaria::search(std::string &valuation, bool &rsearch)
{
    No *current = root;
    while (current != nullptr)
    {
        if (current->insertvaluation == valuation)
        {
            rsearch = true;
            return;
        }
        else if (valuation < current->insertvaluation)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}

void ArvoreBinaria::PreOrdem(No *p)
{
    if (p != nullptr)
    {
        std::cout << p->insertvaluation << " ";
        PreOrdem(p->left);
        PreOrdem(p->right);
    }
}

void ArvoreBinaria::InOrdem(No *p)
{
    if (p != nullptr)
    {
        InOrdem(p->left);
        std::cout << p->insertvaluation << " ";
        InOrdem(p->right);
    }
}

void ArvoreBinaria::PosOrdem(No *p)
{
    if (p != nullptr)
    {
        PosOrdem(p->left);
        PosOrdem(p->right);
        std::cout << p->insertvaluation << " ";
    }
}

std::string ArvoreBinaria::printLeaves(No* no) {
    std::string leaves = "";

    if (no == NULL)
        return leaves;

    if (no->left == NULL && no->right == NULL) {
        leaves += no->insertvaluation + " ";
    } else {
        if (no->left != NULL)
            leaves += printLeaves(no->left);

        if (no->right != NULL)
            leaves += printLeaves(no->right);
    }

    return leaves;
}