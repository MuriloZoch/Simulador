#include <iostream>
#include <vector>
#include <string>

#include "especie.hpp"
#include "itens.hpp"

const int NUM_ITENS = static_cast<int>(ItemID::QTD_ITENS);
double tabelaModificadorDano[NUM_ITENS];

void inicializarTabelaItens() {
    for (int i = 0; i < NUM_ITENS; i++){
        tabelaModificadorDano[i] = 1.0;
    }
    tabelaModificadorDano[(int)ItemID::LIFE_ORB] = 1.3;
    tabelaModificadorDano[(int)ItemID::BLACK_BELT] = 1.2;
    tabelaModificadorDano[(int)ItemID::BLACK_GLASSES] = 1.2;
    tabelaModificadorDano[(int)ItemID::CHARCOAL] = 1.2;
    tabelaModificadorDano[(int)ItemID::DRAGON_FANG] = 1.2;
    tabelaModificadorDano[(int)ItemID::FAIRY_FEATHER] = 1.2;
    tabelaModificadorDano[(int)ItemID::HARD_STONE] = 1.2;
    tabelaModificadorDano[(int)ItemID::MAGNET] = 1.2;
    tabelaModificadorDano[(int)ItemID::METAL_COAT] = 1.2;
    tabelaModificadorDano[(int)ItemID::MIRACLE_SEED] = 1.2;
    tabelaModificadorDano[(int)ItemID::MYSTIC_WATER] = 1.2;
    tabelaModificadorDano[(int)ItemID::NEVER_MELT_ICE] = 1.2;
    tabelaModificadorDano[(int)ItemID::POISON_BARB] = 1.2;
    tabelaModificadorDano[(int)ItemID::SHARP_BEAK] = 1.2;
    tabelaModificadorDano[(int)ItemID::SILK_SCARF] = 1.2;
    tabelaModificadorDano[(int)ItemID::SILVER_POWDER] = 1.2;
    tabelaModificadorDano[(int)ItemID::SOFT_SAND] = 1.2;
    tabelaModificadorDano[(int)ItemID::SPELL_TAG] = 1.2;
    tabelaModificadorDano[(int)ItemID::TWISTED_SPOON] = 1.2;
}

Item::Item(const std::string& nome, const std::string& descricao, Tipo tipoAssociado, ItemID id)
    : nome(nome), descricao(descricao), tipoAssociado(tipoAssociado), id(id) {}