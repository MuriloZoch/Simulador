#include <iostream>
#include <vector>
#include <string>

#include "especie.hpp"
#include "pokemon.hpp"
#include "ataques.hpp"
#include "time.hpp"

Treinador::Treinador(std::string nome, std::vector<Pokemon> time)
    : nome(nome), time(time), INDEX_ativo(0){
}

Treinador::~Treinador() {
}

Pokemon& Treinador::ativo() {
    return time[INDEX_ativo];
}

bool Treinador::todosDesmaiados() const {
    for (const auto& p: time) {
        if(p.finalStatus.hp > 0) return false;
    }
    return true;
}