#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "especie.hpp"

enum class Categoria {
    FISICO,
    ESPECIAL,
    STATUS,
};

typedef struct Ataque {
    Tipo tipo;
    int poder;
    int precisao;
    Categoria categoria;
    
} Ataque;

class Movimento {
    public:
        std::string nome;
        std::string descricao;
        Ataque statusAtaque;

    // Construtor
        Movimento(std::string nome, std::string descricao, Ataque statusAtaque);

    // Destrutor
        ~Movimento();
};