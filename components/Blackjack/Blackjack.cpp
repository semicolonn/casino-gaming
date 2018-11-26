#include "Blackjack.hpp"

using namespace std;

Blackjack::Blackjack(User &loginUser, DataBase &database) : Dealer() {
	_usersDatabase = &database;
	this->_usersLogin.push_back( make_pair(loginUser, 0));
	this->welcomeMessage();
	Dealer::shuffleDeck();
	this->dealCards();
	this->runBlackjack();
}

Blackjack::~Blackjack() {
	system("clear");
	// winner players: the ones who have more points than the dealer and didn't exploded
	cout << "************************* Awarding players *************************" << endl;
	for(int i=0;i<_numeroJogadores;i++){
		cout << setw(50) << left << _usersLogin[i].first.getName() << " (" << _points[i+1] << " points) ";

		if(_points[i+1] <= 21 && (_points[i+1] > _points[0] || _points[0] > 21)) {
			cout << internal << "Reward: " << _usersLogin[i].second*2 << " coins ";
			cout << right << termcolor::on_green << "WINNER WINNER CHICKEN DINNER" << termcolor::reset << endl;

			_usersLogin[i].first.addCoins(_usersLogin[i].second*2);
			_usersLogin[i].first.addScore(_usersLogin[i].second);
		}
		else {
			cout << internal << "Reward: NOTHING!   ";
			cout << right << termcolor::on_red << "LOSER! " << termcolor::reset << endl;

			_usersLogin[i].first.addCoins(-(_usersLogin[i].second));
		}

		_usersDatabase->dropUser(_usersLogin[i].first.getName());
		_usersDatabase->setUser(_usersLogin[i].first);
	}

	cout << endl;
	cout << "Press enter to continue!" << endl;
	cin.get();
	cin.get();
}

void Blackjack::welcomeMessage() {
	system ("clear");
	cout << "*******************************************************************************************" << endl;
	cout << "*        _____                     _____  |  /                      _____  |  /           *" << endl;
	cout << "*       |     |  |         /\\     |       | /          |    /\\     |       | /            *" << endl;
	cout << "*       |____/   |        /__\\    |       |\\           |   /__\\    |       |\\             *" << endl;
	cout << "*       |    \\   |       /    \\   |       | \\     |    |  /    \\   |       | \\            *" << endl;
	cout << "*       |_____|  |____  /      \\  |_____  |  \\    |____| /      \\  |_____  |  \\           *" << endl;
	cout << "*******************************************************************************************" << endl;
	cout << endl << endl;
}

void Blackjack::printingWithColor(string carta, string naipe) {
	if(shouldPrintRed(naipe)){
		cout << termcolor::on_white << termcolor::dark << termcolor::red;
		cout << carta << naipe << " " << termcolor::reset <<" |" << endl;
	}
	else {
		cout << termcolor::on_white << termcolor::dark << termcolor::grey;
		cout << carta << naipe << " " << termcolor::reset <<" |" << endl;
	}
}

bool Blackjack::userAlreadyRegistered(string name) {
	auto it = find_if(this->_usersLogin.begin(), this->_usersLogin.end(),[&name](const pair<User, int>& user) {
		return user.first.getName() == name;
	});
	if (it != this->_usersLogin.end()){
		return true;
	}
	return false;
}

void Blackjack::handleLogin() {
	for(int i=1;i<_numeroJogadores;i++){
		system ("clear");
		cout << "Before we start, every single player must log in!" << endl << endl;

		char resposta;
		cout << "Player " << i+1 << ", have you already got an account? (y/n)? ";
		cin.clear();
		cin >> resposta;
		resposta = tolower(resposta);

		while(resposta != 'y' && resposta != 'n') {
			cout << endl << "Please sir, press (y/n), you can do this: ";
			cin.clear();
			cin >> resposta;
			resposta = tolower(resposta);
		}

		if(resposta == 'y'){
			string name;
      string password;

      cout << "Username: ";
      cin >> name; 
      cout << "Password: ";
      cin >> password;

			User temp;
			temp.setName(name);
			temp.setPassword(password);

			while(!_usersDatabase->login(temp) || userAlreadyRegistered(name)) {
				cout << "Invalid login or already signed up user!" << endl << endl;
				cout << "Username: ";
	      cin >> name; 
	      cout << "Password: ";
	      cin >> password;

				temp.setName(name);
				temp.setPassword(password);
			}

			this->_usersLogin.push_back(make_pair(temp, 0));
		}
		else if(resposta == 'n') {
			Menu menuAux;
			User temp;

			temp = menuAux.createNewUser();
			this->_usersLogin.push_back(make_pair(temp, 0));
			_usersDatabase->setUser(_usersLogin[i].first);
		}

		system ("clear");
	}
}

void Blackjack::handleBets() {
	for(int i=0;i<_numeroJogadores;i++){
		system ("clear");
		cout << "***************** TIME TO BET! *****************" << endl << endl;
		cout << _usersLogin[i].first.getName() << ", how much will you bet? You've got " <<  _usersLogin[i].first.getCoins() << " coins: ";

		int aposta;
		cin >> aposta;
		
		while(aposta > _usersLogin[i].first.getCoins()) {
			cout << "I'm sorry, but you only have " << _usersLogin[i].first.getCoins() << " coins, it's possible to buy more on main menu, but for now put a valid value! ";
			cout << endl;

			cout << "How much will you bet? ";
			cin >> aposta;
			cout << endl;
		}
		_usersLogin[i].second = aposta;
	}

	system("clear");
}

void Blackjack::dealCards() {
	int i=0,j;
	int maiorNomeSize = 0;
	bool primeiraIteracao = true;

	cout << "How much players will be playing today? ";
	cin >> _numeroJogadores;
	while (_numeroJogadores >= 7 ) {
		cout << "I'm sorry, the max allowed number of players is 6! " << endl;
		cout << "Type again the number of players ";
		cin >> _numeroJogadores;
	}
	while (_numeroJogadores <= 1) {
		cout << "I'm sorry, the min allowed number of players is 2! " << endl;
		cout << "Type again the number of players ";
		cin >> _numeroJogadores;
	}

	this->handleLogin();
	this->handleBets();
	for(j=1;j<=_numeroJogadores;j++){
		if(_usersLogin[j-1].first.getName().size() > maiorNomeSize) maiorNomeSize = _usersLogin[j-1].first.getName().size();
	}

	cout << endl << "DEALER" << "|";
	for(j=1;j<=_numeroJogadores;j++){
		cout << setw(maiorNomeSize+5) << _usersLogin[j-1].first.getName() << "|"; 
	}
	cout << endl;

	while(i<2*_numeroJogadores){
		for(j=0;j<=_numeroJogadores;j++){
			vector< pair<string,string>> aux;

			if(primeiraIteracao){
				/* the matrix should be filled with new values just in the first iteration, in the second one it'll be filled with new cards
				but on the already existing positions. */
				aux.push_back(make_pair(_baralho[0].first, _baralho[0].second));
				_playersCards.push_back(aux);
			}
			else {
				_playersCards[j].push_back(make_pair(_baralho[0].first, _baralho[0].second));
			}

			// the \a is the responsible for the little beep on cout
			cout << '\a';
			if(primeiraIteracao || j != 0){
				if(shouldPrintRed(_baralho[0].second)){
					if(j!=0) cout << setw(maiorNomeSize+7) << termcolor::on_white << termcolor::dark << termcolor::red;
					else cout << setw(8) << termcolor::on_white << termcolor::dark << termcolor::red;

					cout << _baralho[0].first << _baralho[0].second;
					//size > 1 significa número de duas casas decimais, é preciso ter um espaco a menos
					if(_baralho[0].first.size() > 1) cout << termcolor::reset << "|";
					else cout << " " << termcolor::reset << "|";
				}
				else {
					if(j!=0) cout << setw(maiorNomeSize+7) << termcolor::on_white << termcolor::dark << termcolor::grey;
					else cout << setw(8) << termcolor::on_white << termcolor::dark << termcolor::grey;

					cout <<_baralho[0].first << _baralho[0].second;

					if(_baralho[0].first.size() > 1) cout << termcolor::reset << "|";
					else cout << " " << termcolor::reset << "|";
				}
			}
			else {
				// the dealer's second card should be kept in secret
				cout << setw(7) << "?|";
			}
			
			i++;
			cout.flush();
			//function that slow terminal down
			usleep( 1000000/2 );
			_baralho.erase(_baralho.begin());
		}

		primeiraIteracao = false;
		cout << endl;
	}

	for(i=0;i<_playersCards.size();i++){
    _points.push_back(0);
    _wantsOneMoreCard.push_back(true);
	}
}

void Blackjack::calculatePoints(int index) {
	// function that calculates the player's point by their hand
  int i=0,j=0;

  _points[index] = 0;

	for(j=0;j<_playersCards[index].size();j++){
    if(_playersCards[index][j].first == "J" || _playersCards[index][j].first == "Q" ||
    	 _playersCards[index][j].first == "K" || _playersCards[index][j].first == "10") {

      _points[index] += 10; 
    }
    else if(_playersCards[index][j].first == "A"){
    	if(_points[index] + 11 > 21)
    		_points[index] += 1;
    	else
      	_points[index] += 11;
    }
    else {
    	if(_playersCards[index][j].first == "2") _points[index] += 2;
    	else if(_playersCards[index][j].first == "3") _points[index] += 3;
    	else if(_playersCards[index][j].first == "4") _points[index] += 4;
    	else if(_playersCards[index][j].first == "5") _points[index] += 5;
    	else if(_playersCards[index][j].first == "6") _points[index] += 6;
    	else if(_playersCards[index][j].first == "7") _points[index] += 7;
    	else if(_playersCards[index][j].first == "8") _points[index] += 8;
    	else if(_playersCards[index][j].first == "9") _points[index] += 9;
    }
	}
}

bool Blackjack::shouldAskNextPlayer(int index) {
	return (!_wantsOneMoreCard[index] || _points[index] >= 21);
}

void Blackjack::runBlackjack() {
	int i=0,j=0;
	bool shouldGoForAnotherHand = true;

	cout << endl;
	for(i=1;i<_playersCards.size();i++){
		while(!shouldAskNextPlayer(i)) {
			this->calculatePoints(i);
			char answer;
			/* player 0 will be the dealer, but this is valid just for the players, when the subject is the database, the vector is 0-indexed
			and we must access the position i-1 to see the player's one name*/
			cout << _usersLogin[i-1].first.getName() << ", you've got " << _points[i] <<" points. Do you want to get one more card (y/n)? ";
			cin.clear();
			cin >> answer;

			// the answer is converted to lower case to prevent bugs (like "Y" as answer)
			answer = tolower(answer);
		
			while(answer != 'y' && answer != 'n') {
				cout << endl << "Please sir, press (y/n), you can do this: ";
				cin.clear();
				cin >> answer;
				answer = tolower(answer);
			}
		
			if(answer == 'n') _wantsOneMoreCard[i] = false;
			else {
				_playersCards[i].push_back(make_pair(_baralho[0].first, _baralho[0].second));

				cout << _usersLogin[i-1].first.getName() << endl;

				for(int j=0;j<_playersCards[i].size();j++){
					printingWithColor(_playersCards[i][j].first,_playersCards[i][j].second);
				}

				this->calculatePoints(i);
				if(_points[i] > 21) cout << termcolor::on_red << "LOSER!" << termcolor::reset << " You blew! Reached " << _points[i] << endl;
				else cout << "Points: " << _points[i] << endl;

				//erasing the first position of the deck, because we won't use it again
				_baralho.erase(_baralho.begin());
			}
		}
		cout << endl << endl;
	}
	this->calculatePoints(0);

	cout << "************** Dealer **************" << endl;
	//the dealer will reach 16 points on more and stop
	while(_points[0] < 16) {
		for(j=0;j<_playersCards[0].size();j++){
			printingWithColor(_playersCards[0][j].first,_playersCards[0][j].second);
		}

		usleep( 1000000/2 );
		cout << "Points: " << _points[0] << endl;
		_playersCards[0].push_back(make_pair(_baralho[0].first, _baralho[0].second));
		_baralho.erase(_baralho.begin());
		this->calculatePoints(0);
	}

	cout << endl << "End of round! Dealer's final hand and score: " << endl;
	for(j=0;j<_playersCards[0].size();j++){
		printingWithColor(_playersCards[0][j].first,_playersCards[0][j].second);
		usleep( 1000000/2 );
	}
	cout << endl << "Points: " << _points[0] << endl << endl;
	cout << "Press enter to continue!" << endl;
	cin.get();
	cin.get();
}
