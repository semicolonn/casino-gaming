#ifndef DATA_HPP
#define DATA_HPP
/**
*
*@brief  Class DataBase
*@file Database.hpp
*@author Mateus, Clarissa, Augusto, Hideki
*
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>

#include "../User/User.hpp"
#include <exception>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::stoi;
using std::ifstream;
using std::ofstream;
using std::list;
using std::find_if;


//CHARACTER TO FIND IN STRING LINE
#define DELIMITER ','
//FILE TYPE TO USE IN DATABASE
#define DATA_STORAGE "data.csv"

class ExceptionDataBase: public exception{

  virtual const char* what() const throw()
  {
    return "Failed to open a file!";
  }
};

class DataBase{
  private:
    list<User> users;

  public:
    /**
    * @brief Função construtora de um objeto DataBase<br />
    */
    DataBase();
    /**
    * @brief Função de deleta um objeto DataBase<br />
    */
    ~DataBase();
    /**
    * @brief Função para inserir o usuario na DataBase <br />
    * @param[in] user Usuario a ser inserido <br />
    */
    void setUser(User);
    /**
    * @brief Função que retorna todos os usuarios contidos na DataBase <br />
    * @return Users Usuarios do banco de dados <br />
    */
    list<User> getUsers();
    /**
    * @brief Função que retorna apenas um usuario contido na DataBase <br />
    * @return Users Um usuario do DataBase <br />
    */
    User getUser(string);
    /**
    * @brief Função para remover um usuario na DataBase <br />
    * @param[in] name Nome do usuario a ser removido <br />
    */
    void dropUser(string);
    /**
    * @brief Função para importar os dados de usuarios contidos em um tipo de arquivo <br />
    * @return Users Usuario a ser removido<br />
    */
    list<User> importDataBase();
    /**
    * @brief Função para copiar a linha de um arquivo e alocar as strings de acordo
    * com os atributos de usuario <br />
    * @param  line <br />
    * @return User Usuario a ser inserido no DataBase <br />
    */
    User insertData(string);
    /**
    * @brief Função para exportar os dados de usuarios na lista para um tipo de arquivo <br />
    */
    void exportDataBase();
    /**
    * @brief Função para Apagar os usuarios da Database <br />
    */
    void removeDataBase();
    /**
    * @brief Função de criar um rancking com os Users do programa<br />
    */
    void ranking();
    /**
    * @brief Função para verificar se o usuario existe no banco de dados <br />
    * @param user Usuario possivelmente existente<br />
    * @return 1 ou 0 <br />
    */
    int login(User&);
};

#endif
