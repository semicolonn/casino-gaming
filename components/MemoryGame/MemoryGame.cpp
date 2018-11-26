#include "MemoryGame.hpp"


MemoryGame::MemoryGame() : OnePlayerGame() {
  _piles = vector<vector<pair<string,string>>>(18,vector<pair<string,string>>(0));
  numCartas = 0;
}

void MemoryGame::instructions(){
	cout << "Memory Game can be player by a single player. " << endl;
	cout << "Try to find the pairs" <<endl;
	cout << "Enter 18 to exit" << endl;
	cout << "Press Enter to Continue!" << endl;
	cin.get();
	cin.get();
	system("clear");
}

void MemoryGame::welcomeMessage(User &user){
  cout <<"****************************************************************************************"<< endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                              Memory Game                                             *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"*                                                                                      *"<<endl;
  cout <<"****************************************************************************************"<< endl;
  cout << "Press Enter to Continue!" << endl;
  cout << endl << endl << endl;
}


void MemoryGame::runGame(User &user){
  	MemoryGame::clearScreen();
	int i,j;
	MemoryGame::welcomeMessage(user);
	MemoryGame::instructions();
	int carta1=1;
	int carta2=1;
	int respostaValida = 0;
	int numeroDeAcertos = 0;
	vector<int> achadas(18);

	for(i=0;i< 18;i++){
	 	achadas[i] = 0;
	}


  
	for(i=0;i<=8;i++){
		pair<string,string> card =  _baralho.back();
		_piles[i].push_back(card);
		_baralho.pop_back();
	}

    int contador =0;

    for(j=0;j<=8;j++){
		contador ++;
		_piles[j+9] = _piles[j];
    }

    i=1;


    while(numeroDeAcertos < 9 && carta1 !=18){		
		int contador = 0;
		int pular = 1;
		i = 0;


		for(auto pile : _piles){
			for(auto card : pile){
			  if(achadas[contador] == 1){
					printCard(card);
			  }else{
					printTurnedCard();
			  }
			  if(pular%6 == 0){
			  	cout << endl;
			  	cout << endl;
			  }
			}
			pular ++;
			contador ++;
		  }

		cout << "Choose a pair of cards: "<<endl;
		cout << "Card 1: ";
		cin >> carta1;
		cout << "Card 2: ";
		cin >> carta2;

		while(carta1 <0 || carta1 > 18 || carta2 < 0 || carta2 > 18 || achadas[carta1] == 1 || achadas[carta2] == 1){
			cout << "Invalid value" << endl;
			cout << "choose a card between 0 and 17"<< endl;
			if(achadas[carta1] == 1 || achadas[carta2] == 1){
				cout << "Attention, this card has been previously selected"<<endl;
			}
			cout << "Card1: ";
			cin >> carta1;
			cout << "Card 2: ";
			cin >> carta2;
		}

		MemoryGame::clearScreen();

		if(carta1 != 18){
			contador = 0;
			pular = 1;

			for(auto pile : _piles){
				for(auto card : pile){
				  if(contador == carta1 || contador == carta2 || achadas[contador] == 1){
						printCard(card);
				  }else{
						printTurnedCard();
				  }
				  if(pular%6 == 0){
				  	cout << endl;
				  	cout << endl;
				  }
				}
				pular ++;
				contador ++;
			  }


			cout << endl;

			if(_piles[carta1] == _piles[carta2]){
			 	cout << "Congratulations" << endl;
			 	achadas[carta1] = 1;
			 	achadas[carta2] = 1;
			  numeroDeAcertos ++;
			  cout << numeroDeAcertos << endl;
			}else{
			 	cout << "Invalid value" << endl;
			 	cout << "Try Again!" << endl;
			}
		}
  }

  if(numeroDeAcertos == 9){
  	cout << "Congratulation!!!!!" << endl;
  	addScoreToUser(30, user);
  	addCoinsToUser(30, user);
  }

}


void MemoryGame::addScoreToUser(int num, User &user){
	MemoryGame::clearScreen();
	cout << "Adding points to your account"<<endl;
	cout << "You won " << num <<" points"<<endl;
	user.addScore(num);

	int quantidade = user.getScore();

	cout << "You have:" << quantidade << " points" << endl;

} 

void MemoryGame::addCoinsToUser(int num, User &user){
	MemoryGame::clearScreen();
	cout << "Adding coins ... "<<endl;
	cout << "You won " << num <<" coins"<<endl;
	user.addCoins(num);

	int quantidade = user.getCoins();
	cout << "You have:" << quantidade << " coins" << endl;

}


void MemoryGame::clearScreen(){
  #ifdef _WIN32
      std::system("cls");
  #else
      std::system ("clear");
  #endif
}
