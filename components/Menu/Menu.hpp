#ifndef MENU_H
#define MENU_H
/**
*
*@brief  
*@file
*@version
*@author
*@date
*
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "../User/User.hpp"
#include "../Database/Database.hpp"
#include "../Blackjack/Blackjack.hpp"
#include "../Dealer/Dealer.hpp"
#include "../Solitaire/Solitaire.hpp"
#include "../MemoryGame/MemoryGame.hpp"

using namespace std;

#define CONVERSION_SCORE 2

class Menu{
	public:
		 /**
		* Função que cria o Menu<br />
		* @param nenhum<br />
		* @return nenhum <br />
		 */
	  	Menu(){};
		 /**
		 * Função que cria o menu do programa<br/>
		 * @param uma objeto do tipo DataBase e um objeto do tipo User<br />
		 * @return void <br />
		 */
	 	void menuPrograma(User &, DataBase &);
		 /**
		 * Função que cria o menu com as informações dos jogos disponíveis<br/>
		 * @param uma objeto do tipo DataBase e um objeto do tipo User<br />
		 * @return void <br />
		 */
	  	void menuInfoGames(User &, DataBase &);
		 /**
		 * Função que cria o menu com as informações do user e possíveis opções de alteração<br/>
		 * @param uma objeto do tipo DataBase e um objeto do tipo User<br />
		 * @return void <br />
		 */
	  	void menuInfoUser(User &, DataBase &);
		 /**
		 * Função que cria novos User<br/>
		 * @param nenhum<br />
		 * @return retorna um objeto User<br />
		 */
	  	User createNewUser();
		 /**
		 * Função que limpa a tela <br/>
		 * @param nenhum<br />
		 * @return void <br />
		 */
	  	void clearScreen();
};
#endif
