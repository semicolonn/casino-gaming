#include "User.hpp"

using namespace std;
//setter constructor
User::User(string name, string password, string gender, int age,  string city,
  string college){
  this->name = name;
  this->password = password;
  this->gender = gender;
  this->age = age;
  this->city = city;
  this->college = college;
  this->score = 0;
  this->coins = COINS_START_VALUE;
}

//default constructor
User::User() : User(" ", " ", " ", MINIMUM_ALLOWED_AGE, " ", " "){}

User::~User(){}

void User::setName(string name){
    this->name = name;
}

void User::setPassword(string password){
    this->password = password;
}

void  User::setGender(string gender){
    this->gender = gender;
}

void  User::setAge(int age){
    if(age < 0){
      age = 0;
    }
    this->age = age;
}

void  User::setCity(string city){
    this->city = city;
}

void  User::setCollege(string college){
    this->college = college;
}

void User::setCoins(int coins){
    this->coins = coins;
}

void User::addCoins(int addCoins){
    this->coins = this->coins + addCoins;
}

void User::setScore(int score){
    this->score = score;
}

void User::addScore(int addscore){
    this->score = this->score + addscore;
}


string User::getName() const{
    return this->name;
}

string User::getPassword() const{
    return this->password;
}

string  User::getGender() const{
    return this->gender;
}

int  User::getAge() const{
    return this->age;

}

string User:: getCity() const{
    return this->city;
}

string  User::getCollege() const{
    return this->college;
}

int User::getCoins() const{
  return this->coins;
}

int User::getScore() const{
  return this->score;
}

//print the all about the User
void  User::printUser() const{
   cout  << "User :       " << getName()<< endl
    <<  "Gender :     " << getGender() <<endl
    <<  "Age :        " << getAge() <<endl
    <<  "City :       " << getCity() << endl
    <<  "University : "<<getCollege() << endl
    << "Score: " << User::getScore() << endl
    << "Coins : "<<getCoins() <<endl<<endl;
}


//print the important informations about the User
void  User::printStatus() const{
   cout << "----------- User -----------" << endl;
   cout << "User: " << User::getName() << endl;
   cout << "Score: " << User::getScore() << endl;
   cout << "Coins: " << User::getCoins() << endl;
   cout << endl;
}
