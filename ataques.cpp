#include <iostream>
#include <string>
#include "ataques.hpp"

// Construtor
    Movimento::Movimento(std::string nome, std::string descricao, Ataque statusAtaque) {
        this->nome = nome;
        this->descricao = descricao;
        this->statusAtaque = statusAtaque;
    }

// Destrutor
    Movimento::~Movimento() {
    }