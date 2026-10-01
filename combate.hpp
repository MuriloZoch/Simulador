#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "time.hpp"

int calcularCritico();

int calcularDano(Pokemon& atacante, Pokemon& defensor, int indiceMovimento);

void inicializarTabela();

void trocarPokemon(Treinador& treinador);