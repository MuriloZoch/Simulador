#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "especie.hpp"
#include "pokemon.hpp"
#include "ataques.hpp"
#include "time.hpp"
#include "itens.hpp"

int calcularCritico() {
    int critico = rand() % 100;
    
    if (critico < 5) {
        return 1;
    }
    else {
        return 0;
    }
}

double calcularStab(Pokemon& atacante, int indiceMovimento) {
        Tipo tipoGolpe = atacante.movimento[indiceMovimento].statusAtaque.tipo;
        if (tipoGolpe == atacante.especie.tipos[0]) {
            return 1.5;
        }
        if (atacante.especie.tipos.size() > 1 && tipoGolpe == atacante.especie.tipos[1]) {
            return 1.5;
        }
        return 1.0;
}

const int NUM_TIPOS = static_cast<int>(Tipo::QTD_TIPOS);

double tabelaEfetividade[NUM_TIPOS][NUM_TIPOS];

void inicializarTabela() {
    for (int i = 0; i < NUM_TIPOS; i++){
        for (int j = 0; j < NUM_TIPOS; j++){
            tabelaEfetividade[i][j] = 1.0;
        }
    }
    //NORMAL
    tabelaEfetividade[(int)Tipo::NORMAL][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::NORMAL][(int)Tipo::PEDRA] = 0.5;
    tabelaEfetividade[(int)Tipo::NORMAL][(int)Tipo::FANTASMA] = 0.0;

    //FOGO
    tabelaEfetividade[(int)Tipo::FOGO][(int)Tipo::GRAMA] = 2.0;
    tabelaEfetividade[(int)Tipo::FOGO][(int)Tipo::INSETO] = 2.0;
    tabelaEfetividade[(int)Tipo::FOGO][(int)Tipo::GELO] = 2.0;
    tabelaEfetividade[(int)Tipo::FOGO][(int)Tipo::PEDRA] = 0.5;
    tabelaEfetividade[(int)Tipo::FOGO][(int)Tipo::FOGO] = 0.5;
    tabelaEfetividade[(int)Tipo::FOGO][(int)Tipo::AGUA] = 0.5;
    tabelaEfetividade[(int)Tipo::FOGO][(int)Tipo::DRAGAO] = 0.5;

    //AGUA
    tabelaEfetividade[(int)Tipo::AGUA][(int)Tipo::TERRA] = 2.0;
    tabelaEfetividade[(int)Tipo::AGUA][(int)Tipo::PEDRA] = 2.0;
    tabelaEfetividade[(int)Tipo::AGUA][(int)Tipo::FOGO] = 2.0;
    tabelaEfetividade[(int)Tipo::AGUA][(int)Tipo::AGUA] = 0.5;
    tabelaEfetividade[(int)Tipo::AGUA][(int)Tipo::GRAMA] = 0.5;
    tabelaEfetividade[(int)Tipo::AGUA][(int)Tipo::DRAGAO] = 0.5;

    //GRAMA
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::TERRA] = 2.0;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::PEDRA] = 2.0;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::AGUA] = 2.0;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::VOADOR] = 0.5;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::VENENO] = 0.5;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::INSETO] = 0.5;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::FOGO] = 0.5;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::GRAMA] = 0.5;
    tabelaEfetividade[(int)Tipo::GRAMA][(int)Tipo::DRAGAO] = 0.5;

    //ELETRICO
    tabelaEfetividade[(int)Tipo::ELETRICO][(int)Tipo::VOADOR] = 2.0;
    tabelaEfetividade[(int)Tipo::ELETRICO][(int)Tipo::AGUA] = 2.0;
    tabelaEfetividade[(int)Tipo::ELETRICO][(int)Tipo::GRAMA] = 0.5;
    tabelaEfetividade[(int)Tipo::ELETRICO][(int)Tipo::ELETRICO] = 0.5;
    tabelaEfetividade[(int)Tipo::ELETRICO][(int)Tipo::DRAGAO] = 0.5;
    tabelaEfetividade[(int)Tipo::ELETRICO][(int)Tipo::TERRA] = 0.0;

    //TERRA
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::VENENO] = 2.0;
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::PEDRA] = 2.0;
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::ACO] = 2.0;
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::FOGO] = 2.0;
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::ELETRICO] = 2.0;
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::INSETO] = 0.5;
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::GRAMA] = 0.5;
    tabelaEfetividade[(int)Tipo::TERRA][(int)Tipo::VOADOR] = 0.0;

     //PEDRA
    tabelaEfetividade[(int)Tipo::PEDRA][(int)Tipo::VOADOR] = 2.0;
    tabelaEfetividade[(int)Tipo::PEDRA][(int)Tipo::INSETO] = 2.0;
    tabelaEfetividade[(int)Tipo::PEDRA][(int)Tipo::FOGO] = 2.0;
    tabelaEfetividade[(int)Tipo::PEDRA][(int)Tipo::GELO] = 2.0;
    tabelaEfetividade[(int)Tipo::PEDRA][(int)Tipo::LUTADOR] = 0.5;
    tabelaEfetividade[(int)Tipo::PEDRA][(int)Tipo::TERRA] = 0.5;
    tabelaEfetividade[(int)Tipo::PEDRA][(int)Tipo::ACO] = 0.5;
            
    //AÇO
    tabelaEfetividade[(int)Tipo::ACO][(int)Tipo::PEDRA] = 2.0;
    tabelaEfetividade[(int)Tipo::ACO][(int)Tipo::GELO] = 2.0;
    tabelaEfetividade[(int)Tipo::ACO][(int)Tipo::FADA] = 2.0;
    tabelaEfetividade[(int)Tipo::ACO][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::ACO][(int)Tipo::FOGO] = 0.5;
    tabelaEfetividade[(int)Tipo::ACO][(int)Tipo::AGUA] = 0.5;
    tabelaEfetividade[(int)Tipo::ACO][(int)Tipo::ELETRICO] = 0.5;

    //LUTADOR
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::NORMAL] = 2.0;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::PEDRA] = 2.0;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::ACO] = 2.0;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::GELO] = 2.0;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::SOMBRIO] = 2.0;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::VOADOR] = 0.5;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::VENENO] = 0.5;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::INSETO] = 0.5;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::PSIQUICO] = 0.5;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::FADA] = 0.5;
    tabelaEfetividade[(int)Tipo::LUTADOR][(int)Tipo::FANTASMA] = 0.0;

    //SOMBRIO
    tabelaEfetividade[(int)Tipo::SOMBRIO][(int)Tipo::FANTASMA] = 2.0;
    tabelaEfetividade[(int)Tipo::SOMBRIO][(int)Tipo::PSIQUICO] = 2.0;
    tabelaEfetividade[(int)Tipo::SOMBRIO][(int)Tipo::LUTADOR] = 0.5;
    tabelaEfetividade[(int)Tipo::SOMBRIO][(int)Tipo::SOMBRIO] = 0.5;
    tabelaEfetividade[(int)Tipo::SOMBRIO][(int)Tipo::FADA] = 0.5;

    //FANTASMA
    tabelaEfetividade[(int)Tipo::FANTASMA][(int)Tipo::FANTASMA] = 2.0;
    tabelaEfetividade[(int)Tipo::FANTASMA][(int)Tipo::PSIQUICO] = 2.0;
    tabelaEfetividade[(int)Tipo::FANTASMA][(int)Tipo::SOMBRIO] = 0.5;
    tabelaEfetividade[(int)Tipo::FANTASMA][(int)Tipo::NORMAL] = 0.0;

    //PSIQUICO
    tabelaEfetividade[(int)Tipo::PSIQUICO][(int)Tipo::LUTADOR] = 2.0;
    tabelaEfetividade[(int)Tipo::PSIQUICO][(int)Tipo::VENENO] = 2.0;
    tabelaEfetividade[(int)Tipo::PSIQUICO][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::PSIQUICO][(int)Tipo::PSIQUICO] = 0.5;
    tabelaEfetividade[(int)Tipo::PSIQUICO][(int)Tipo::SOMBRIO] = 0.0;

    //VENENO
    tabelaEfetividade[(int)Tipo::VENENO][(int)Tipo::GRAMA] = 2.0;
    tabelaEfetividade[(int)Tipo::VENENO][(int)Tipo::FADA] = 2.0;
    tabelaEfetividade[(int)Tipo::VENENO][(int)Tipo::VENENO] = 0.5;
    tabelaEfetividade[(int)Tipo::VENENO][(int)Tipo::TERRA] = 0.5;
    tabelaEfetividade[(int)Tipo::VENENO][(int)Tipo::PEDRA] = 0.5;
    tabelaEfetividade[(int)Tipo::VENENO][(int)Tipo::FANTASMA] = 0.5;
    tabelaEfetividade[(int)Tipo::VENENO][(int)Tipo::ACO] = 0.0;

    //INSETO

    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::GRAMA] = 2.0;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::PSIQUICO] = 2.0;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::SOMBRIO] = 2.0;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::LUTADOR] = 0.5;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::VOADOR] = 0.5;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::VENENO] = 0.5;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::FANTASMA] = 0.5;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::FOGO] = 0.5;
    tabelaEfetividade[(int)Tipo::INSETO][(int)Tipo::FADA] = 0.5;

    //VOADOR
    tabelaEfetividade[(int)Tipo::VOADOR][(int)Tipo::LUTADOR] = 2.0;
    tabelaEfetividade[(int)Tipo::VOADOR][(int)Tipo::INSETO] = 2.0;
    tabelaEfetividade[(int)Tipo::VOADOR][(int)Tipo::GRAMA] = 2.0;
    tabelaEfetividade[(int)Tipo::VOADOR][(int)Tipo::PEDRA] = 0.5;
    tabelaEfetividade[(int)Tipo::VOADOR][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::VOADOR][(int)Tipo::ELETRICO] = 0.5;
            
    //GELO
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::LUTADOR] = 2.0;
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::VOADOR] = 2.0;
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::GRAMA] = 2.0;
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::DRAGAO] = 2.0;
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::FOGO] = 0.5;
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::AGUA] = 0.5;
    tabelaEfetividade[(int)Tipo::GELO][(int)Tipo::GELO] = 0.5;

    //DRAGAO
    tabelaEfetividade[(int)Tipo::DRAGAO][(int)Tipo::DRAGAO] = 2.0;
    tabelaEfetividade[(int)Tipo::DRAGAO][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::DRAGAO][(int)Tipo::FADA] = 0.0;

    //FADA
    tabelaEfetividade[(int)Tipo::FADA][(int)Tipo::LUTADOR] = 2.0;
    tabelaEfetividade[(int)Tipo::FADA][(int)Tipo::DRAGAO] = 2.0;
    tabelaEfetividade[(int)Tipo::FADA][(int)Tipo::SOMBRIO] = 2.0;
    tabelaEfetividade[(int)Tipo::FADA][(int)Tipo::VENENO] = 0.5;
    tabelaEfetividade[(int)Tipo::FADA][(int)Tipo::ACO] = 0.5;
    tabelaEfetividade[(int)Tipo::FADA][(int)Tipo::FOGO] = 0.5;
    
}

double calcularEfetividade(Tipo atacante, Tipo defensor1, Tipo defensor2 = Tipo::QTD_TIPOS) {
    double mult = tabelaEfetividade[(int)atacante][(int)defensor1];
    if (defensor2 != Tipo::QTD_TIPOS) // pokemon com 2 tipos
        mult *= tabelaEfetividade[(int)atacante][(int)defensor2];
    return mult;
}

int calcularDano(Pokemon& atacante, Pokemon& defensor, int indiceMovimento) {
    Movimento& movimentoUsado = atacante.movimento[indiceMovimento];

    int danoBase = 0;
    if (movimentoUsado.statusAtaque.categoria == Categoria::FISICO){
        danoBase = ((((42 * movimentoUsado.statusAtaque.poder * atacante.statusEfetivo().atk) / defensor.statusEfetivo().def) / 50) + 2);
    }
    else if (movimentoUsado.statusAtaque.categoria == Categoria::ESPECIAL){
        danoBase = ((((42 * movimentoUsado.statusAtaque.poder * atacante.statusEfetivo().spatk) / defensor.statusEfetivo().spdef) / 50) + 2);
    }

    Tipo tipo2 = (defensor.especie.tipos.size() > 1) ? defensor.especie.tipos[1] : Tipo::QTD_TIPOS;
    double mult = calcularEfetividade(movimentoUsado.statusAtaque.tipo, defensor.especie.tipos[0], tipo2);

    double dano = danoBase;

    if(calcularCritico() == 1){
        dano = static_cast<int>(dano * 1.5);
    }

    dano = static_cast<int>(dano * calcularStab(atacante, indiceMovimento));
    if (atacante.item.tipoAssociado == movimentoUsado.statusAtaque.tipo) {
        dano *= tabelaModificadorDano[(int)atacante.item.id];
    }

    
    dano *= mult;

    return static_cast<int>(dano);
}

void trocarPokemon(Treinador& treinador) {
    std::cout << "POKEMON:\n" << std::endl;
    for (size_t i = 0; i < treinador.time.size(); i++) {
        if (treinador.time[i].finalStatus.hp > 0) {
            std::cout << i << " - " << treinador.time[i].especie.nome << std::endl;
        }
    }

    int escolha;
    std::cin >> escolha;

    while (escolha < 0 || escolha >= (int)treinador.time.size() || treinador.time[escolha].finalStatus.hp <= 0) {
        std::cout << "ESCOLHA INVALIDA" << std::endl;
        std::cin >> escolha;
    }

    treinador.INDEX_ativo = escolha;
}



