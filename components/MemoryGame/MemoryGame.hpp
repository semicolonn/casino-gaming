#ifndef MEMORYGAME_H
#define MEMORYGAME_H
/**
*
*@brief  Classe Memory Game
*@file MemoryGame.hpp
*@author Hideki, Clarissa, Mateus, Augusto
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <thread>
#include <unistd.h>
#include "../User/User.hpp"
#include "../Database/Database.hpp"
#include "../Dealer/Dealer.hpp"
#include "../OnePlayer/OnePlayer.hpp"

using namespace std;


class MemoryGame: public OnePlayerGame{
  public:

    /**
    * Função de criar um objeto MemoryGame, ou seja cria o jogo Memory Game <br />
    */
    MemoryGame();
    /**
    * Função de deleta um objeto MemoryGame<br />
    */
    ~MemoryGame(){};
    /**
    * Função que imprime as instruções do jogo Memory Game<br />
    */

    void instructions() override;
    /**
    * Função que inicia o jogo<br />
    * @param um objeto da classe User<br />
    */

    void runGame(User &) override;
    /**
    * Função que adiciona pontos ao user<br />
    * @param uma variável do tipo inteiro e um objeto da classe User<br />
    */
    void addScoreToUser(int, User &) override;
    /**
    * Função que adiciona moedas ao user<br />
    * @param uma variável do tipo inteiro e um objeto da class User<br />
    */
    void addCoinsToUser(int, User &) override;
    /**
    * Função que imprime mensagem de boas vindas ao jogador<br />
    * @param  <br />
    */
    void welcomeMessage(User &) override;
    vector<vector < pair<string,string>>> _piles;
    /**
    * Função que limpa a tela<br />
    * @param nenhum <br />
    */
    void clearScreen();

  private:
    int numCartas;
};

#endif
