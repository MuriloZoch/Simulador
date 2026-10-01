#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "especie.hpp"
#include "pokemon.hpp"
#include "ataques.hpp"

class Treinador{
public:
    std::string nome;
    std::vector<Pokemon> time;
    int INDEX_ativo;

    // Construtor
    Treinador (std::string nome, std::vector<Pokemon> time);

    //Destrutor
    ~Treinador();

    Pokemon& ativo();

    bool todosDesmaiados() const;
    
};

