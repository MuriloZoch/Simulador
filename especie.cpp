#include <iostream>
#include <string>
#include <vector>

#include "especie.hpp"
#include "pokemon.hpp"
#include "ataques.hpp"


std::string Especie::TypeToString(Tipo tipo) const {
    switch (tipo) {
        case Tipo::NORMAL: return "NORMAL";
        case Tipo::FOGO: return "FOGO";
        case Tipo::AGUA: return "AGUA";
        case Tipo::GRAMA: return "GRAMA";
        case Tipo::ELETRICO: return "ELETRICO";
        case Tipo::GELO: return "GELO";
        case Tipo::LUTADOR: return "LUTADOR";
        case Tipo::VENENO: return "VENENO";
        case Tipo::TERRA: return "TERRA";
        case Tipo::VOADOR: return "VOADOR";
        case Tipo::PSIQUICO: return "PSIQUICO";
        case Tipo::INSETO: return "INSETO";
        case Tipo::PEDRA: return "PEDRA";
        case Tipo::FANTASMA: return "FANTASMA";
        case Tipo::DRAGAO: return "DRAGAO";
        case Tipo::SOMBRIO: return "SOMBRIO";
        case Tipo::ACO: return "ACO";
        case Tipo::FADA: return "FADA";
    }
}
// Construtor
    Especie::Especie(std::string nome, std::vector<Tipo> Tipos, Status baseStatus) {
        this->nome = nome;
        this->tipos = Tipos;
        this->baseStatus = baseStatus;
    }
    
// Destrutor
    Especie::~Especie() {
    }
;
