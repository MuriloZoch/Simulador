#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "especie.hpp"

enum class ItemID {
    NENHUM,
    CHOICE_SPECS,
    CHOICE_BAND,
    CHOICE_SCARF,
    LIFE_ORB,
    BLACK_BELT,
    BLACK_GLASSES,
    CHARCOAL,
    DRAGON_FANG,
    FAIRY_FEATHER,
    HARD_STONE,
    MAGNET,
    METAL_COAT,
    MIRACLE_SEED,
    MYSTIC_WATER,
    NEVER_MELT_ICE,
    POISON_BARB,
    SHARP_BEAK,
    SILK_SCARF,
    SILVER_POWDER,
    SOFT_SAND,
    SPELL_TAG,
    TWISTED_SPOON,
    ASSAULT_VEST,
    QTD_ITENS
};

struct Item {
    std::string nome;
    std::string descricao;
    Tipo tipoAssociado;
    ItemID id;

    Item(const std::string& nome,const std::string& descricao, Tipo tipoAssociado, ItemID id);
};

void inicializarTabelaItens();



extern double tabelaModificadorDano[];