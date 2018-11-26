#ifndef BLACKJACK_H
#define BLACKJACK_H
/**
*
*@brief  Classe Blackjack
*@file	Blackjack.hpp
*@author Augusto, Hideki, Mateus, Clarissa
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
#include <string>
#include <cctype>

#include "../Database/Database.hpp"
#include "../Menu/Menu.hpp"
#include "../User/User.hpp"
#include "../Dealer/Dealer.hpp"
#include "../Dealer/termcolor.hpp"

using namespace std;

class Blackjack : public Dealer{
	private:
		int _numeroJogadores;

		DataBase *_usersDatabase;
		vector< pair<User, int> > _usersLogin;

		vector< vector< pair<string,string>>> _playersCards;
		vector<int>  _points;
		vector<bool> _wantsOneMoreCard;
	public:

		/**
		* Construtor da classe, irá printar na tela a mensagem de boas vindas,
		embaralhar o deck, distribuir as cartas e chamar o loop principal do jogo.<br />
		* @see welcomeMessage()
		* @see Dealer#shuffleDeck()
		* @see dealCards()
		* @see runBlackjack()
		* @param o usuário que logou no cassino e o banco de dados para que as alterações sejam feitas<br />
		*/

	    Blackjack(User &loginUser, DataBase &database);

		/**
	    * Método que irá printar na tela a mensagem de boas vindas para o usuário.<br />
	    */

		void welcomeMessage();

		/**
	    * Método que irá realizar o login de todos os jogadores.<br />
	    */

    	void handleLogin();

		/**
	    * Método que irá realizar a lógica de apostas do jogo, pedirá apostas coerentes dos jogadores.<br />
	    */

		void handleBets();

		/**
    	* Método auxiliar que irá dizer, no início do jogo, se um usuário já foi cadastrado nesse jogo ou não ao pedirmos
		* o login dele.<br />
	    * @param string contendo o login do jogador <br />
	    * @return true (usuário já cadastrado no banco de dados) ou false <br />
	    */

		bool userAlreadyRegistered(string name);

		/**
    	* Método que irá representar o loop principal do blackjack, é responsável por todos
		*os prints e lógica do jogo.<br />
    	*/

		void runBlackjack();

		/**
    	* Método auxiliar que ajudará o loop do jogo a saber se precisa continuar
		*focando no usuário atual ou se esse usuário já acabou seu turno (e então o
		*loop irá para o próximo jogador).<br />
	    * @param inteiro que representará o índice do usuário atual no vector<br />
	    * @return verdadeiro (deve perguntar o próximo player) ou falso <br />
	    */

		bool shouldAskNextPlayer(int index);

		/**
    	* Método que irá sobrescrever o método virtual de dar as cartas do
		* Dealer, ele será responsável pela lógica de distribuir as cartas.<br />
	    * @param nenhum <br />
	    * @return nenhum <br />
	    */

    	void dealCards() override;
		// void calculateBets() override{};

		/**
	    * Método que irá fazer a conta dos pontos na mão de cada jogador do blackjack.<br />
	    * @param inteiro que representará o índice do usuário atual no vector. <br />
	    * @return nenhum <br />
	    */

		void calculatePoints(int index);

		/**
    	* Método que irá auxiliar nos prints feitos, evita repetições desnecessárias
		* do mesmo trecho de código.<br />
	    * @param duas strings representando a carta e o naipe em questão <br />
	    * @return nenhum <br />
	    */

		void printingWithColor(string carta, string naipe);

		/**
	    * Destrutor do código, irá atualizar o banco de dados com todas as mudanças realizadas aqui.<br />
	    * @param nenhum <br />
	    * @return nenhum <br />
	    */

		~Blackjack();
};

#endif
