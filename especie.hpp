#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class Tipo {
    NORMAL,
    FOGO,
    AGUA,
    GRAMA,
    ELETRICO,
    GELO,
    LUTADOR,
    VENENO,
    TERRA,
    VOADOR,
    PSIQUICO,
    INSETO,
    PEDRA,
    FANTASMA,
    DRAGAO,
    SOMBRIO,
    ACO,
    FADA,
    QTD_TIPOS
};

typedef struct Status {
    int hp;
    int atk;
    int def;
    int spatk;
    int spdef;
    int spe;
} Status;

class Especie {
public:
    std::string nome;
    std::vector<Tipo> tipos;
    Status baseStatus;

// Mostrar o Tipo
    std::string TypeToString(Tipo tipo) const;

// Construtor
    Especie(std::string nome, std::vector<Tipo> Tipos, Status baseStatus);

// Destrutor
    ~Especie();

};