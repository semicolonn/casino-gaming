#ifndef DEALER_H
#define DEALER_H
/**
*
*@brief  Classe Dealer
*@file Dealer.hpp
*@author Augusto, Hideki, Mateus, Clarissa
*
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Dealer {
	public:
		vector< pair<string,string> > _baralho;

		/**
        * Construtor da classe, sua função é de montar o baralho e deixá-lo pronto para
        *o uso (mas não embaralhado). <br />
        */

		Dealer();

		/**
        * Método que irá mostrar o baralho na tela, printando o vector responsável
		*por ele. <br />
        */

		void showDeck();

		/**
        * Método que é responsável por embaralhar, deixa o baralho de uma forma aleatória.<br />
        */


		void shuffleDeck();

		/**
        * Método virtual que espera ser substituído pela forma correta de dar as cartas, de
		*acordo com o jogo.<br />
        */

		virtual void dealCards() {};

		/**
        * Método virtual que espera ser substituído pela lógica de cálculo das apostas, novamente
		*de acordo com o jogo.<br />
        */

		virtual void calculateBets() {};

		/**
        * Método que irá auxiliar nos prints feitos, irá decidir se a carta deve ser printada
		*vermelha (copas ou ouros) ou não (espadas ou paus). <br />
        * @param[in] uma variável do tipo string representando o naipe da carta <br />
        * @return um numero inteiro 0 ou 1 <br />
        */
	
		bool shouldPrintRed(string naipe);

        /**
        *Destrutor da classe <br />
        */

		virtual ~Dealer(){};
};

#endif
