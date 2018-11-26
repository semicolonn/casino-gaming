#ifndef USER_H
#define USER_H

/**
*
*@brief Classe User
*@file  User.hpp
*@author Clarissa, Mateus, Hideki, Augusto
*
*/


#include <iostream>
#include <string>

using namespace std;

#define COINS_START_VALUE 30
#define MINIMUM_ALLOWED_AGE 18

class User{
	public:
		//create a new user
		/**
		* @brief Função de criar um objeto User<br />
		* @param strings para: nome, senha, gênero, cidade e escola e uma variável inteira para a idade<br />
		*/
		User(string, string, string, int, string, string);
		/**
		* @brief Função de criar um objeto User<br />
		*/
		User();
		/**
		* @brief Função de deletar um objeto User<br />
		*/
	  	~User();

		//SETTER METHDS
		/**
		* @brief Função que coloca um nome para o User<br />
		* @param uma string que recebe o nome<br />
		*/
		void setName(string);
		/**
		* @brief Função que coloca uma senha para o User<br />
		* @param uma string que recebe a senha<br />
		*/
		void setPassword(string);
		/**
		* @brief Função que coloca um gênero para o User<br />
		* @param uma string que recebe o genero<br />
		*/
		void setGender(string);
		/**
		* @brief Função que coloca uma idade para o User<br />
		* @param uma variável inteira que recebe a idade<br />
		*/
		void setAge(int);
		/**
		* @brief Função que coloca uma cidade para o User<br />
		* @param uma string que recebe o nome da cidade<br />
		*/
		void setCity(string);
		/**
		* @brief Função que coloca uma escola para o User<br />
		* @param uma string que recebe o nome da escola<br />
		*/
		void setCollege(string);
		/**
		* @brief Função que coloca moedas para o User<br />
		* @param uma variável do tipo inteiro com o valor a ser colocado<br />
		*/
		void setScore(int);
		/**
		* @brief Função que coloca pontos para o User<br />
		* @param uma variável do tipo inteiro com o valor a ser colocado<br />
		*/
		void setCoins(int);

	//GETTER METHODS
		/**
		* @brief Função que retorna o nome do User<br />
		* @return string <br />
		*/
		string getName() const;
		/**
		* @brief Função que retorna a senha do User<br />
		* @return string <br />
		*/
		string getPassword() const;
		/**
		* @brief Função que retorna o gênero do User<br />
		* @return string <br />
		*/
		string getGender() const;
		/**
		* @brief Função que retorna a idade do User<br />
		* @return inteiro <br />
		*/
		int  getAge() const;
		/**
		* @brief Função que retorna a cidade do User<br />
		* @return string <br />
		*/
		string getCity() const;
		/**
		* @brief Função que retorna a escola do User<br />
		* @return string <br />
		*/
		string getCollege() const;
		/**
		* @brief Função que retorna o número de pontos do User<br />
		* @return inteiro <br />
		*/
		int getScore() const;
		/**
		* @brief Função que retorna o número de moedas do User<br />
		* @return inteiro <br />
		*/
		int getCoins() const;

		//ADD METHODS
		/**
		* @brief Função que adiciona pontos ao User<br />
		* @return inteiro <br />
		*/
		void addScore(int);
		/**
		* @brief Função que adiciona moedas User<br />
		* @return inteiro <br />
		*/
		void addCoins(int);

	//PRINT METHODS
		/**
		* @brief Função que imprime todas as informações do User<br />
		*/
		void printUser() const;
		/**
		* @brief Função que imprime todas as informações do User<br />
		*/
		void printStatus() const;

	private:
		string name;
		string password;
		string gender;
		int age;
		string city;
		string college;
		int coins;
		int score;
};

#endif
