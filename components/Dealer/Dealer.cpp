#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include "Dealer.hpp"
#include "termcolor.hpp"

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

#define NAIPES 4
#define CARTAS 13

string cartas[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string naipes[] = {SPADE,HEART,CLUB,DIAMOND};

Dealer::Dealer() {
	int i,j;
	for(auto i : naipes){
		for(auto j : cartas){
			_baralho.push_back(make_pair(j,i));
		}
	}
}

bool Dealer::shouldPrintRed(string naipe) {
	return (naipe==HEART || naipe == DIAMOND) ? true : false;
}

void Dealer::showDeck() {
	int i;
	for(i=0;i<_baralho.size();i++){
		if(shouldPrintRed(_baralho[i].second)){
			cout << termcolor::on_white << termcolor::dark << termcolor::red;
			cout << _baralho[i].first << _baralho[i].second << " " << termcolor::reset << endl;
		}
		else {
			cout << termcolor::on_white << termcolor::dark << termcolor::grey;
			cout << _baralho[i].first << _baralho[i].second << " " << termcolor::reset << endl;
		}
		if((i+1)%13==0) cout << endl;
	}
}

void Dealer::shuffleDeck() {
	//Fisher–Yates' algorithm
	srand (time(NULL));
	int i,j;
	pair<string,string> aux;

	for(i=_baralho.size()-1;i>=1;i--){
		j=rand() % (i+1);
		aux			= _baralho[j];
		_baralho[j] = _baralho[i];
		_baralho[i] = aux;
	}
}
