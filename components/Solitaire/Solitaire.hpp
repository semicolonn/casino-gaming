/**
*
*@brief Classe Solitaire
*@file Soliraire.hpp
*@author Mateus, Hideki, Clarissa, Augusto
*
*/

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <thread>
#include <unistd.h>
#include "../Dealer/Dealer.hpp"
#include "../OnePlayer/OnePlayer.hpp"

#define TOTALSCORE 200
#define TOTALCOINS 100

using namespace std;

#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\x06"
   #define HEART   "\x03"
   #define CLUB    "\x05"
   #define DIAMOND "\x04"
#else
   #define SPADE   "\xE2\x99\xA0"
   #define HEART   "\xE2\x99\xA5"
   #define CLUB    "\xE2\x99\xA3"
   #define DIAMOND "\xE2\x99\xA6"
#endif

class Solitaire : public OnePlayerGame{
	private:
		int numberOfMoves;
		int score;
		vector < pair<string,string>> _stock;
		vector < pair<string,string>> _turnedStock;
		vector<vector < pair<string,string>>> _foundations;
		vector<vector < pair<string,string>>> _pilesTurned;
		vector<vector < pair<string,string>>> _pilesUnturned;
	public:
		/**
		* @brief Função de criar um objeto Solitaire<br />
		*/
		Solitaire();
		/**
		* @brief Função para mostrar o jogo<br />
		*/
		void showGame();
    	/**
		* @brief Função que mvimenta a carta do topo do restante do baralho  <br />
		*/
		void drawStock();
    	/**
		* @brief Função que verifica se os naipes da carta movimentada e da pilha no 
    	* topo da pilha para qual ela sera movimentada  sao de cor diferente <br />
		* @param[in] suitCardPile Naipe da carta que esta na pilha <br />
    	* @param[in] suitCard     Naipe da carta que sera movida <br />
		* @return Verdadeiro ou falso <br />
		*/
		bool differentColor(string,string);
	    /**
	    * @brief Função que verifica os simbolos da carta e os converte para inteiro<br />
	    * @param[in] card Simbolo da carta <br />
	    * @return card <br />
	    */
	    int symbolToValue(string card);
	    /**
	    * @brief Função que verifica se uma carta e maior que a outra com distancia de 1 <br />
	    * @param[in] cardA Simbolo da carta <br />
	    * @param[in] cardB Simbolo da carta <br />
	    * @return Verdadeiro ou Falso <br />
	    */
	    bool lessThan(string cardA, string cardB);
	    /**
		* @brief Função que movimenta as cartas da pilha selecionada para o local 
	    * de destino escolhido <br />
		* @param[in] oprm lugar de remocao <br />
	    * @param[in] pilerm pilha de remocao <br />
	    * @param[in] opadd lugar de insercao<br />
	    * @param[in] pileadd pilha de insercao<br />
	    * @param[in] ncards numero de cartas a remover <br />
		* @return Verdadeiro ou Falso <br />
		*/
			bool movePile(int ,int , int, int, int);
	    /**
	    * @brief Função para exibir as opcoes do jogo<br />
	    */
			void game();
	    /**
	    * @brief Função para que distribui o baralho entre as pilhas do jogo<br />
	    * @param nenhum<br />
	    */
		void runGame(User&) override;
		/**
		* @brief Função criar uma mensagem de boas vindas para o User<br />
		* @param user Objeto da classe User <br />
		*/
		void welcomeMessage(User&) override;
		/**
		* @brief Função que mostra as instruções do jogo<br />
		*/
		void instructions() override;
		/**
		* @brief Função que adiciona pontos ao user<br />
		* @param uma variável do tipo int e um objeto da classe user<br />
		*/
		void addScoreToUser(int, User&) override;
		/**
		* @brief Função que adiciona moedas ao user<br />
		* @param uma variável do tipo inteiro e um objeto da classe user<br />
		*/
		void addCoinsToUser(int, User&) override;
};
