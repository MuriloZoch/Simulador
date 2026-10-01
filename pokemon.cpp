#include <iostream>
#include "especie.hpp"
#include "pokemon.hpp"


Status Pokemon::calcularStatus(Status baseStatus, Status Ev, Status Iv) {
    Status finalStatus;
    finalStatus.hp = ((2 * baseStatus.hp + Iv.hp + (Ev.hp / 4))) + 110;
    finalStatus.atk = ((2 * baseStatus.atk + Iv.atk + (Ev.atk / 4))) + 5;
    finalStatus.def = ((2 * baseStatus.def + Iv.def + (Ev.def / 4))) + 5;
    finalStatus.spatk = ((2 * baseStatus.spatk + Iv.spatk + (Ev.spatk / 4))) + 5;
    finalStatus.spdef = ((2 * baseStatus.spdef + Iv.spdef + (Ev.spdef / 4))) + 5;
    finalStatus.spe = ((2 * baseStatus.spe + Iv.spe + (Ev.spe / 4))) + 5;

    return finalStatus;
}

double Pokemon::multiplicadorEstagio(int estagio) const {
        if (estagio >= 0){
            return (2.0 + estagio)/2.0;
        }
        else
            return (2.0 - estagio)/2.0;
        
}

Status Pokemon::statusEfetivo() const {
        Status s;
        s.hp = finalStatus.hp;
        s.atk = static_cast<int>(finalStatus.atk * multiplicadorEstagio(estagios.atk));
        s.def = static_cast<int>(finalStatus.def * multiplicadorEstagio(estagios.def));
        s.spatk = static_cast<int>(finalStatus.spatk * multiplicadorEstagio(estagios.spatk));
        s.spdef = static_cast<int>(finalStatus.spdef * multiplicadorEstagio(estagios.spdef));
        s.spe = static_cast<int>(finalStatus.spe * multiplicadorEstagio(estagios.spe));

        return s;
}

// Construtor
Pokemon::Pokemon(Especie especie, std::vector<Movimento> movimento, Status Ev, Status Iv, Item item)
    : especie(especie), movimento(movimento), item(item) {
    this->finalStatus = calcularStatus(especie.baseStatus, Ev, Iv);
}

// Destrutor
Pokemon::~Pokemon() {
}
