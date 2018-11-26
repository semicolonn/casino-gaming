#include "OnePlayer.hpp"

OnePlayerGame::OnePlayerGame() : Dealer() {
  pontuacaoGanhador = 0;
}

//pega do bara. e imprime 
void OnePlayerGame::printCard(pair<string, string> card){
  if(shouldPrintRed(card.second)){
    cout << termcolor::on_white << termcolor::dark << termcolor::red;
    cout << card.first << card.second << " " << termcolor::reset <<"\t |\t";
  }
  else {
    cout << termcolor::on_white << termcolor::dark << termcolor::grey;
    cout << card.first << card.second << " " << termcolor::reset <<"\t |\t";
  }
}

//imprime a cartinha virada
void OnePlayerGame::printTurnedCard(){
  cout << termcolor::on_white << termcolor::dark << termcolor::red;
  cout << " " << CARD << " " << termcolor::reset << "\t |\t";
}