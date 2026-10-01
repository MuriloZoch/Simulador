#pragma once

#include "especie.hpp"
#include "ataques.hpp"
#include "itens.hpp"

#include <iostream>
#include <vector>

struct Estagios {
    int atk = 0;
    int def = 0;
    int spatk = 0;
    int spdef = 0;
    int spe = 0;
};

class Pokemon{
public:
    Especie especie;
    std::vector<Movimento> movimento;
    Status Ev;
    Status Iv;
    Status finalStatus;
    Estagios estagios;
    Item item;

    Status calcularStatus(Status baseStatus, Status Ev, Status Iv);

    double multiplicadorEstagio(int estagio) const;

    Status statusEfetivo() const;
    
    // Construtor
    Pokemon(Especie especie, std::vector<Movimento> movimento, Status Ev, Status Iv, Item item);

    // Destrutor
    ~Pokemon();
};