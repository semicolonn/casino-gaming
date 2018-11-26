#include "Solitaire.hpp"


Solitaire::Solitaire() : OnePlayerGame() {
	shuffleDeck();
	_pilesUnturned = vector<vector<pair<string,string>>>(7,vector<pair<string,string>>(0));
	_pilesTurned = vector<vector<pair<string,string>>>(7,vector<pair<string,string>>(0));
	_foundations = vector<vector<pair<string,string>>>(4,vector<pair<string,string>>(0));
	_turnedStock = {};
	_stock = {};
	score = 0;
	numberOfMoves = 0;
}

void Solitaire::welcomeMessage(User &user) {
	system ("clear");
	cout << "*******************************************************************************************" << endl;
	cout << "*        _____       _____               ___________              ____   _____            *" << endl;
	cout << "*       //         //     \\  |       |       |       /\\    |   |    | |                 *" << endl;
	cout << "*        \\___     |       |  |       |       |      /  \\   |   |____| |_____            *" << endl;
	cout << "*             \\   |       |  |       |       |     / __ \\  |   | \\   |                 *" << endl;
	cout << "*        ____ //   \\____//   |______ |       |    /      \\ |   |  \\  |_____            *" << endl;
	cout << "*******************************************************************************************" << endl;
	cout << "Press Enter to Continue!" << endl;
	cout << endl << endl << endl;

}

void Solitaire::runGame(User &user){
	welcomeMessage(user);
	instructions();
	// the \a is the responsible for the little beep on cout
	for(int i = 0; i < 7 ; i++){
		for(int j = 0; j < i; j++){
			pair<string,string> card =  _baralho.back();
			_pilesUnturned[i].push_back(card);
			_baralho.pop_back();
		}
		pair<string,string> card =  _baralho.back();
		_pilesTurned[i].push_back(card);
		_baralho.pop_back();
	}
	while(!_baralho.empty()){
		pair<string,string> card =  _baralho.back();
		_stock.push_back(card);
		_baralho.pop_back();
	}

	showGame();

	game();

	addScoreToUser(numberOfMoves, user);
	addCoinsToUser(numberOfMoves, user);
	numberOfMoves = 0;
}

void Solitaire::drawStock(){
	if(_stock.empty()){
		while(!_turnedStock.empty()){
			pair<string,string> card = _turnedStock.back();
			_turnedStock.pop_back();
			_stock.push_back(card);
		}
	}else{
		pair<string,string> card = _stock.back();
		_stock.pop_back();
		_turnedStock.push_back(card);
	}
}

bool Solitaire::differentColor(string suitCardPile, string suitCard) {
	if((suitCardPile==HEART || suitCardPile == DIAMOND) &&
		(suitCard == SPADE || suitCard == CLUB)){
		return true;
	}else if((suitCard ==HEART || suitCard == DIAMOND) &&
		(suitCardPile == SPADE || suitCardPile == CLUB)){
		return true;
	}else{
		return false;
	}
}


int Solitaire::symbolToValue(string card){
	if(card == "A"){
		card = "1";
	}else if(card == "J"){
		card = "11";
	}else if(card == "Q"){
		card = "12";
	}else if(card == "K"){
		card = "13";
	}
	return stoi(card);
}

bool Solitaire::lessThan(string cardA, string cardB){
	if((symbolToValue(cardA)+1) ==  (symbolToValue(cardB))){
		return true;
	}
	return false;
}

bool Solitaire::movePile(int oprm,int pilerm, int opadd, int pileadd, int ncards){
	vector<pair<string,string>> cards;

	if(oprm == opadd && pileadd==pilerm){
		return false;
	}

	switch(oprm){
		case 1:
			if(!_turnedStock.empty() && ncards == 1){
				cards.push_back(_turnedStock.back());
			}else{
				return true;
			}
			break;
		case 2:
			if(!_foundations[pilerm].empty()  && ncards == 1){
				cards.push_back(_foundations[pilerm].back());
			}else{
				return true;
			}
			break;
		case 3:
			if(_pilesTurned[pilerm].size()>=ncards){
				int firstCard = _pilesTurned[pilerm].size()-ncards;
				int lastCard = _pilesTurned[pilerm].size();
				for(int i = firstCard; i<lastCard; i++){
					cards.push_back(_pilesTurned[pilerm][i]);
				}
			}else{
				return true;
			}
			break;
	}

	pair<string, string> topCard;

	switch(opadd){
		case 2:
			if(ncards==1){
				pair<string,string> card = cards.back();
				if(_foundations[pileadd].empty()){
					if(card.first == "A"){
						_foundations[pileadd].push_back(card);
					}else{
						return true;
					}
				}else{
					topCard = _foundations[pileadd].back();
					if(card.second == topCard.second &&
						lessThan(topCard.first,card.first)){
						_foundations[pileadd].push_back(card);
					}else{
						return true;
					}

				}
			}else{
				return true;
			}
			break;

		case 3:
			if(_pilesTurned[pileadd].empty()){
				if(cards.front().first == "K"){
					for(auto card : cards){
						_pilesTurned[pileadd].push_back(card);
					}
				}else{
					return true;
				}
			}else{
				topCard = _pilesTurned[pileadd].back();
				if(differentColor(cards.front().second,topCard.second) &&
					lessThan(cards.front().first,topCard.first)){
					for(auto card : cards){
						_pilesTurned[pileadd].push_back(card);
					}
				}else{
					return true;
				}
			}
			break;

		default:
			return true;
			break;
	}

	switch(oprm){
		case 1:
			_turnedStock.pop_back();
			drawStock();
			if(opadd == 2){
				score += 10;
			}else{
				score += 5;
			}
			break;
		case 2:
			_foundations[pilerm].pop_back();
			score-=15;
			break;
		case 3:
			pair<string,string> card;
			for(int i = 0 ; i<ncards; i++){
				_pilesTurned[pilerm].pop_back();
			}
			if(_pilesTurned[pilerm].empty() && !_pilesUnturned[pilerm].empty()){
				pair<string,string> card = _pilesUnturned[pilerm].back();
				_pilesUnturned[pilerm].pop_back();
				_pilesTurned[pilerm].push_back(card);
				score+=5;
			}

			if(opadd==2){
				score+=10;
			}
			break;
	}

	return false;

}

void Solitaire::game(){
	int op,opremove,pileremove, opadd, pileadd, ncards;
	bool invalid = false;
	while(1){
		std::system("clear");
		showGame();

		if(invalid){
			cout << "Invalid Move\n";
			invalid = false;
		}

		cout << "Type 1 to move a card, 2 to draw a card from the stock or 3 to exit: ";
		cin >> op;

		if(op == 3){
			char answer;
			cout << "Are you sure you want to quit? "<<endl;
	        cout << "Y [yes] or N [not]: ";
	        cin >> answer;
	        while( answer != 'Y' && answer != 'N' ){
	          cout << "Invalid Input! " << endl;
	          cout << " Choose Y or N: ";
	          cin >> answer;
	        }

	        if(answer=='Y'){
	        	return;
	        }else{
	        	continue;
	        }
		}else if(op == 2){
			drawStock();
			numberOfMoves++;
		}else if(op == 1){
			cout << "From where you want to remove (1,2 or 3): ";
			cin >> opremove;

			switch(opremove){
				case 1:
					ncards=1;
					break;

				case 2:
					cout << "From which pile you want to remove (1,2,3 or 4): ";
					cin >> pileremove;
					if(pileremove<1 || pileremove>4){
						invalid = true;
						continue;
					}
					ncards=1;
					break;

				case 3:
					cout << "From which pile you want to remove (1,2,3,4,5,6 or 7): ";
					cin >> pileremove;
					if(pileremove<1 || pileremove>7){
						invalid = true;
						continue;
					}
					cout << "How much cards do you want to remove: ";
					cin >> ncards;
					if(ncards<1){
						invalid=true;
						continue;
					}
					break;

				default:
					invalid = true;
					continue;
					break;
			}

			cout << "Where you want to put the card(s) (2 or 3): ";
			cin >> opadd;

			switch(opadd){
				case 2:
					cout << "To which pile you want to add the card(s) (1,2,3 or 4): ";
					cin >> pileadd;
					if(pileadd<1 || pileadd>4){
						invalid = true;
						continue;
					}
					break;

				case 3:
					cout << "To which pile you want to add the card(s) (1,2,3,4,5,6 or 7): ";
					cin >> pileadd;
					if(pileadd<1 || pileadd>7){
						invalid = true;
						continue;
					}
					break;

				default:
					invalid = true;
					continue;
					break;
			}

			invalid = movePile(opremove,pileremove-1,opadd,pileadd-1,ncards);

			if(!invalid){
				numberOfMoves++;
			}
		}else{
			invalid = true;
			continue;
		}
	}
}



void Solitaire::showGame() {
	// the \a is the responsible for the little beep on cout
  std::system("clear");
	cout << "***********1- Stock***********"<<endl;

	if(_stock.empty()){
		cout << "   " << "\t |\t";
	}else{
		printTurnedCard();
	}

	if(_turnedStock.empty()){
		cout << "   " << "\t |\t";
	}else{
		printCard(_turnedStock.back());
	}

	cout << endl;

	cout << "***********2- Foundations***********"<<endl;
	for(auto pile : _foundations){
		if(pile.empty()){
			printTurnedCard();
		}else{
			pair<string,string> card = pile.back();
			printCard(card);
		}
	}
	cout << endl;
	cout << "***********3- Piles***********"<<endl;

	int maxpile = 0;
	for(int i = 0; i < 7 ; i++){
		if(_pilesUnturned[i].size()+_pilesTurned[i].size()>maxpile){
			maxpile = _pilesUnturned[i].size()+_pilesTurned[i].size();
		}
	}

	for(int i = 0; i < maxpile ; i++){
		for(int j = 0; j < 7 ; j++){
			if(_pilesUnturned[j].size()>i){
				printTurnedCard();
			}else if((_pilesUnturned[j].size()+_pilesTurned[j].size())>i){
				printCard(_pilesTurned[j][i-_pilesUnturned[j].size()]);
			}else{
				cout << " " << "\t |\t";
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << "Cards left in the stock: " << _stock.size() << endl << endl;
	cout << "Number of moves: " << numberOfMoves << endl;
	cout << "Score: " << score << endl;
	cout << endl;
}

void Solitaire::instructions(){
	cout << "** HELLO **" << endl;
	cout << "Solitaire can be player by a single player. " << endl;
	cout << "Release and play into position certain cards to build up each ";
	cout << "foundation, in sequence and in suit,from the ace through the king." << endl;
	cout << "Press Enter to Continue!" << endl;
	cin.get();
	cin.get();
	system("clear");
}

void Solitaire::addScoreToUser(int numberOfMoves, User &user){

	user.addScore(score);
}

void Solitaire::addCoinsToUser(int numberOfMoves, User &user){

	user.addCoins(score/2);
}
