#include "pilha.hpp"
#include <string>

Pilha::Pilha() {
    top = nullptr;
}

Pilha::~Pilha() {
    while (!vazia()) {
        pop();
    }
}

void Pilha::push(int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = top;
    top = novoNo;
}

int Pilha::pop() {
    if (!vazia()) {
        int valortop = top->valor;
        No* temp = top;
        top = top->proximo;
        delete temp;
        return valortop;
    } else {
        return -1; 
    }
}

bool Pilha::vazia() {
    return top == nullptr;
}

int Pilha::topo() {
    if (!vazia()) {
        return top->valor;
    } else {
        return -1; 
    }
}

/********************************************************************************/

void Pilha::pushs(std::string valor) {
    Nos* novoNo = new Nos;
    novoNo->valors = valor;
    novoNo->proximos = tops;
    tops = novoNo;
}

std::string Pilha::pops() {
    if (!vazia()) {
        std::string valortops = tops->valors;
        Nos* temp = tops;
        tops = tops->proximos;
        delete temp;
        return valortops;
    } else {
        return "-1"; 
    }
}

bool Pilha::vazias() {
    return tops == nullptr;
}

std::string Pilha::topos() {
    if (!vazia()) {
        std::string temp = tops->valors;
        return temp;
    } else {
        return "-1"; 
    }
}