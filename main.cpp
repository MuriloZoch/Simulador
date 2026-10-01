#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "especie.hpp"
#include "pokemon.hpp"
#include "combate.hpp"
#include "ataques.hpp"
#include "time.hpp"
#include "itens.hpp"

void exibirStatus(const Pokemon& pokemon) {
    std::cout << "POKEMON: " << pokemon.especie.nome << "\n" << std::endl;
    std::cout << "HP: " << pokemon.finalStatus.hp << std::endl;
    std::cout << "ATK: " << pokemon.finalStatus.atk << std::endl;
    std::cout << "DEF: " << pokemon.finalStatus.def << std::endl;
    std::cout << "SPATK: " << pokemon.finalStatus.spatk << std::endl;
    std::cout << "SPDEF: " << pokemon.finalStatus.spdef << std::endl;
    std::cout << "SPE: " << pokemon.finalStatus.spe << std::endl;
}

void exibirMovimento(const Pokemon& pokemon) {

    for (size_t i = 0; i < pokemon.movimento.size(); i++){
        std::cout << "Movimento: " << pokemon.movimento[i].nome << std::endl;
        std::cout << "Descricao: " << pokemon.movimento[i].descricao << std::endl;
        std::cout << "Tipo: " << pokemon.especie.TypeToString(pokemon.movimento[i].statusAtaque.tipo) << std::endl;
        std::cout << "Poder: " << pokemon.movimento[i].statusAtaque.poder << std::endl;
        std::cout << "Precisao: " << pokemon.movimento[i].statusAtaque.precisao << std::endl;
        std::cout << "\n";
    }
}

int turno(Treinador& atacante, Treinador& defensor){
    std::cout << "escolha sua acao:\n0- ATACAR\n1- TROCAR" << std::endl;
    int escolha;
    int escolhaMovimento;
    std::cin >> escolha;

    switch (escolha){
        case 0: //ATACAR
            for (size_t i = 0; i < atacante.ativo().movimento.size(); i++){
                std::cout << i << " - " << atacante.ativo().movimento[i].nome << std::endl;
            }

            std::cin >> escolhaMovimento;
            if (escolhaMovimento < 0 || escolhaMovimento >= (int)atacante.ativo().movimento.size()){
                std::cout << "MOVIMENTO INVALIDO" << std::endl;
                return -1;
            }

            if (atacante.ativo().statusEfetivo().spe >= defensor.ativo().statusEfetivo().spe){
                int danoCausado = calcularDano(atacante.ativo(), defensor.ativo(), escolhaMovimento);
                defensor.ativo().finalStatus.hp -= danoCausado;
                std::cout << "DANO CAUSADO: " << danoCausado << std::endl;

                if(defensor.ativo().finalStatus.hp <= 0) {
                    if (defensor.todosDesmaiados()) {
                        return 2;   //ATACANTE GANHOU
                    }
                    trocarPokemon(defensor);
                }

                else {
                    int danoCausado = calcularDano(defensor.ativo(), atacante.ativo(), 0);
                    atacante.ativo().finalStatus.hp -= danoCausado;
                    std::cout << "DANO RECEBIDO: " << danoCausado << std::endl;

                        if(atacante.ativo().finalStatus.hp <= 0) {
                            if (atacante.todosDesmaiados()) {
                                return 1;   //DEFENSOR GANHOU
                            }
                            trocarPokemon(atacante);
                        }
                }
            }
            else {
                int danoCausado = calcularDano(defensor.ativo(), atacante.ativo(), 0);
                atacante.ativo().finalStatus.hp -= danoCausado;
                std::cout << "DANO RECEBIDO: " << danoCausado << std::endl;

                if(atacante.ativo().finalStatus.hp <= 0) {
                    if (atacante.todosDesmaiados()) {
                        return 1;   //DEFENSOR GANHOU
                    }
                    trocarPokemon(atacante);
                }
                else {
                    int danoCausado = calcularDano(atacante.ativo(), defensor.ativo(), escolhaMovimento);
                    defensor.ativo().finalStatus.hp -= danoCausado;
                    std::cout << "DANO CAUSADO: " << danoCausado << std::endl;

                    if (defensor.ativo().finalStatus.hp <= 0) {
                        if (defensor.todosDesmaiados()) {
                            return 2;   //ATACANTE GANHOU
                        }
                        trocarPokemon(defensor);
                    }
                }
            }
            return 0; //    CONTINUACAO DO TURNO

            break;
            
        case 1: { //TROCAR
            trocarPokemon(atacante);
            int danoCausado = calcularDano(defensor.ativo(), atacante.ativo(), 0);
            atacante.ativo().finalStatus.hp -= danoCausado;
            std::cout << "DANO RECEBIDO: " << danoCausado << std::endl;

            if (atacante.ativo().finalStatus.hp <= 0) {
                if (atacante.todosDesmaiados()) {
                    return 1;   //DEFENSOR GANHOU
                }
                trocarPokemon(atacante);
            }
            return 0;   //CONTINUACAO DO TURNO
        }
        
        default:
            std::cout << "ESCOLHA INVALIDA" << std::endl;
            return -1; //   JOGADA INVALIDA
    }
    
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    inicializarTabela();
    inicializarTabelaItens();

    Item spell_tag("SPELL_TAG", "DANO EXTRA PARA FANTASMA", Tipo::FANTASMA, ItemID::SPELL_TAG);
    Item nenhum("NENHUM", "NENHUM EFEITO", Tipo::QTD_TIPOS, ItemID::NENHUM);

    // Especie GENGAR
    Status baseStatusGengar = {60, 65, 60, 130, 75, 110};
    Especie especieGengar("GENGAR", {Tipo::FANTASMA, Tipo::VENENO}, baseStatusGengar);
    Movimento movimentoGengar("SHADOW BALL", "DANO", {Tipo::FANTASMA, 80, 100, Categoria::ESPECIAL});

    Status EvGengar = {0, 0, 0, 0, 0, 0};
    Status IvGengar = {31, 31, 31, 31, 31, 31};


    Pokemon gengar(especieGengar, {movimentoGengar}, EvGengar, IvGengar, spell_tag);

    // Especie GRENINJA
    Status baseStatusGreninja = {72, 95, 67, 103, 71, 122};
    Especie especieGreninja("GRENINJA", {Tipo::AGUA, Tipo::SOMBRIO}, baseStatusGreninja);
    Movimento movimentoGreninja("HYDRO PUMP", "DANO", {Tipo::AGUA, 110, 80, Categoria::ESPECIAL});

    Status EvGreninja = {0, 0, 0, 0, 0, 0};
    Status IvGreninja = {31, 31, 31, 31, 31, 31};

    Pokemon greninja(especieGreninja, {movimentoGreninja}, EvGreninja, IvGreninja, nenhum);

    // Especie Galvantula
    Status baseStatusGalvantula = {70, 77, 60, 97, 60, 108};
    Especie especieGalvantula("GALVANTULA", {Tipo::INSETO, Tipo::ELETRICO}, baseStatusGalvantula);

    Movimento movimento_Galvantula_1("ElectroWeb", "DANO", {Tipo::ELETRICO, 55, 95, Categoria::ESPECIAL});
    Movimento movimento_Galvantula_2("Bug Buzz","DANO", {Tipo::INSETO, 90, 100, Categoria::ESPECIAL});

    Status EvGalvantula = {0, 0, 0, 0, 0, 0};
    Status IvGalvantula = {31, 31, 31, 31, 31, 31};

    Pokemon galvantula(especieGalvantula, {movimento_Galvantula_1,movimento_Galvantula_2}, EvGalvantula, IvGalvantula, nenhum);

    // Especie HISUI_TYPHLOSION
    Status baseStatusHisuiTyphlosion = {73, 84, 78, 119, 85, 95};
    Especie especieHisuiTyphlosion("HISUI TYPHLOSION", {Tipo::FOGO, Tipo::FANTASMA}, baseStatusHisuiTyphlosion);

    Movimento movimento_Hisui_Typhlosion_1("Overheat", "DANO", {Tipo::FOGO, 130, 90, Categoria::ESPECIAL});

    Status EvHisui_typhlosion = {0, 0, 0, 0, 0, 0};
    Status IvHisui_Typhlosion = {31, 31, 31, 31, 31, 31};

    Pokemon hisui_typhlosion(especieHisuiTyphlosion, {movimento_Hisui_Typhlosion_1}, EvHisui_typhlosion, IvHisui_Typhlosion, nenhum);

    Treinador jogador("VOCE", {gengar, galvantula});
    
    Treinador inimigo("inimigo", {greninja, hisui_typhlosion});

    exibirStatus(gengar);
    std::cout << "\n" << std::endl;
    exibirMovimento(gengar);
    std::cout << "\n" << std::endl;

    exibirStatus(greninja);
    std::cout << "\n" << std::endl;
    exibirMovimento(greninja);
    std::cout << "\n" << std::endl;

    exibirStatus(galvantula);
    std::cout << "\n" << std::endl;
    exibirMovimento(galvantula);
    std::cout << "\n" << std::endl;

    int contador = 1;
        while (!jogador.todosDesmaiados() > 0 && !inimigo.todosDesmaiados()) {

            std::cout << "\nTurno " << contador << std::endl;
            int resultado = turno(jogador, inimigo);
            if (resultado == 2) {
                std::cout << "GALVANTULA venceu a batalha!" << std::endl;
                break;
            } else if (resultado == 1) {
                std::cout << "GRENINJA venceu a batalha!" << std::endl;
                break;
            }
            contador++;

        }


    int verificador = 0;
    std::cout << "\nPressione 1 para sair...";
    std::cin >> verificador;

    return 0;
}