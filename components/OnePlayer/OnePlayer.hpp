#ifndef ONEPLAYER_H
#define ONEPLAYER_H
/**
*
*@brief  Classe One Player
*@file OnePlayer.hpp
*@author Clarissa, Hideki, Mateus, Augusto
*
*/


#include <iostream>
#include <string>
#include "../User/User.hpp"
#include "../Dealer/termcolor.hpp"
#include "../Database/Database.hpp"
#include "../Dealer/Dealer.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

#define CARD "※"


class OnePlayerGame : public Dealer{
  public:

    /**
    * @brief Função construtora um objeto OnePlayerGame<br />
    */

    OnePlayerGame();

    /**
    * @brief Função que deleta um objeto OnePlayerGame<br />
    */

    ~OnePlayerGame(){};
  
    /**
    * @brief Função que envia uma mensagem inicial sobre o jogo<br />
    * @param user Um objeto da classe User<br />
    */

    virtual void welcomeMessage(User &) = 0;

    /**
    * @brief Função que escreve as instruções do jogo<br />
    * @param user Um objeto da classe User<br />
    */

    virtual void instructions() = 0;

    /**
    * @brief Função que executa o jogo<br />
    * @param user Um objeto da classe User<br />
    */

    virtual void runGame(User &) = 0;

    /**
    * @brief Função que adiciona pontuação ao user<br />
    * @param addScore Uma variável de valor inteiro <br />
    * @param user Um objeto da classe user
    */


    virtual void addScoreToUser(int, User &) = 0;

    /**
    * @brief Função que adiciona moedas ao user<br />
    * @param addCoins Uma variável de valor inteiro <br />
    * @param user Um objeto do tipo user
    */

    virtual void addCoinsToUser(int, User &) = 0;
    
    /**
    * @brief Função que imprime as cartas do jogo viradas para cima<br />
    * @param pair<string,string>card Pair com duas strings <br />
    */


    void printCard(pair<string, string> card);

    /**
    * @brief Função imprime as cartas do jogo viradas para baixo<br />
    */

    void printTurnedCard();


  private:
    int pontuacaoGanhador;

};

#endif
