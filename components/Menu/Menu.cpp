#include "Menu.hpp"


void Menu::menuInfoGames(User &temporary, DataBase &data ){
  cout << "******************* Games **********************************" << endl;
  cout << "* " << setw(37) << " Choose an option from below" << setw(33)  << "*" << endl;
  cout << "* " << setw(25) << "1. Blackjack " << setw(46) << " * " << endl;
  cout << "* " << setw(24) << "2. Solitaire" << setw(46) << " *" << endl;
  cout << "* " << setw(26) << "3. Memory Game" << setw(44) << " *" << endl;
  cout << "* " << setw(19) << "4. Exit" << setw(51) << " *" << endl;
  cout << "* " << setw(34) << "[Choose Your Option] : ";
  char Option = '0';
  cin >> Option;
  cout << "***********************************************************************" << endl;

  switch(Option) {
    case '1': {
      char answer = 'A';
      while(answer != 'N'){
        Dealer *dealer = new Blackjack(temporary, data);

        delete(dealer);
        system("clear");

        cout << "Do you want to play again? "<<endl;
        cout << "Y [yes] or N [not]: ";
        cin >> answer;
        while( answer != 'Y' && answer != 'N' ){
          cout << "Invalid Input! " << endl;
          cout << " Choose Y or N: ";
          cin >> answer;
        }
      }
      break;
    }
    case '2': {
      char answer = 'A';
      while(answer != 'N'){

        Solitaire solitaire = Solitaire();
        solitaire.runGame(temporary);
        data.dropUser(temporary.getName());
        data.setUser(temporary);

        cout << "Do you want to play again? "<<endl;
        cout << "Y [yes] or N [not]: ";
        cin >> answer;
        while( answer != 'Y' && answer != 'N' ){
          cout << "Invalid Input! " << endl;
          cout << " Choose Y or N: ";
          cin >> answer;
        }
      }
      
      break;
    }
    case '3': {
      char answer = 'A';
      while(answer != 'N'){
      MemoryGame memoryGame = MemoryGame();
      memoryGame.runGame(temporary);
      data.dropUser(temporary.getName());
      data.setUser(temporary);
      cout << "Do you want to play again? "<<endl;
        cout << "Y [yes] or N [not]: ";
        cin >> answer;
        while( answer != 'Y' && answer != 'N' ){
          cout << "Invalid Input! " << endl;
          cout << " Choose Y or N: ";
          cin >> answer;
        }
      }
      
      break;
    }

    case '4':{
      Menu::clearScreen();
      return;
      break;
    }
    default: {
      Menu::clearScreen();
      cout << "Select the right option" << endl;
      cout << "Press Enter!" << endl;
      cin.get();
      cin.get();
    }
  }
}

void Menu::menuInfoUser(User &temporary, DataBase &data){
  cout << endl;
  cout << "******************* "<< temporary.getName() <<" Informations " "**********************************" << endl;
  temporary.printUser();

  cout << endl;
  cout << "---- Do you want to change some informations? -----"<< endl;
  cout <<" Yes [Y] or No [N]: ";
  char Continue = 'A';
  cin >> Continue;
  while(Continue != 'Y' && Continue != 'N'){
    cout << "Invalid Input! " << endl;
    cout << " Choose Y or N: ";
    cin >> Continue;
  }
  cout << endl;
  Menu::clearScreen();
  if (Continue == 'Y'){
    cout << "* " <<  setw(37) << " Choose an option from below" << setw(33)  << "*" << endl;
    cout << "* " << setw(25) << "1. Change Name" << setw(46) << " * " << endl;
    cout << "* " << setw(27) << "2. Change Gender" << setw(43) << " *" << endl;
    cout << "* " << setw(24) << "3. Change Age" << setw(46) << " *" << endl;
    cout << "* " << setw(25) << "4. Change City" << setw(46) << " * " << endl;
    cout << "* " << setw(31) << "5. Change University" << setw(39) << " *" << endl;
    cout << "* " << setw(29) << "6. Change Password" << setw(41) << " *" << endl;
    cout << "* " << setw(28) << "7. Buy more Coins" << setw(42) << " *" << endl;
    cout << "* " << setw(18) << "8. Exit" << setw(52) << " *" << endl;
    cout << "* " << setw(34) << "[Choose Your Option] : ";
    char Option = '0';
    cin >> Option;
    if(Option == '8'){
      Menu::clearScreen();
      return;
    }else if(Option > '8' || Option < '1'){
      cout << "Invalid Option!" << endl;
      cout << "Press Enter!" << endl;
      cin.get();
      cin.get();
      Menu::clearScreen();
      return;

    }
    cout << "***********************************************************************" << endl;
    string passwordTest;
    cout << "Password: ";
    cin >> passwordTest;

    if ( passwordTest == temporary.getPassword()){
      switch(Option) {
        case '1': {
          Menu::clearScreen();
          data.dropUser(temporary.getName());
          string newName;
          cout << endl;
          cout << "New Name: ";
          cin >> newName;
          temporary.setName(newName);
          break;
        }
        case '2': {
          Menu::clearScreen();
          string newGender;
          cout << endl;
          cout << "New Gender: ";
          cin >> newGender;
          while(newGender[0] != 'F' && newGender[0] != 'M'){
            cout << "Error, select F or M" << endl;
            cout << "Gender  (Choose F or M): ";
            cin >> newGender;
          }
          temporary.setGender(newGender);
          break;
        }
        case '3': {
          Menu::clearScreen();
          int newAge;
          cout << endl;
          cout << "New Age: ";
          cin >> newAge;
          while(newAge <= 0){
            cout << "Error, " << endl;
            cout << "Age :";
            cin >> newAge;
          }
          temporary.setAge(newAge);
          break;
        }
        case '4': {
          Menu::clearScreen();
          string newCity;
          cout << endl;
          cout << "New City: ";
          cin >> newCity;
          temporary.setCity(newCity);
          break;
        }
        case '5': {
          Menu::clearScreen();
          string newUniversity;
          cout << endl;
          cout << "New University: ";
          cin >> newUniversity;
          temporary.setCollege(newUniversity);
          break;
        }
        case '6': {
          Menu::clearScreen();
          string newPassword;
          cout << endl;
          cout << "New Password: ";
          cin >> newPassword;
          if(newPassword == temporary.getPassword()){
            cout << "Same Password"<< endl;
            cout << "Press Enter!" << endl;
            cin.get();
            cin.get();
          } else {
            temporary.setPassword(newPassword);
          }

          break;
        }
        case '7': {
          Menu::clearScreen();
          int newCoins;
          char resposta;
          cout << endl;
          cout << "How much Coins do you want: ";
          cin >> newCoins;
         
          cout << "We'll subtract " << newCoins*CONVERSION_SCORE << " from you score, you have " <<  temporary.getScore() <<". Continue (y/n)? ";
          cin.clear();
          cin >> resposta;
          resposta = tolower(resposta);

          if(resposta == 'y'){
            if(newCoins <= 0){
              cout << "Incorrect value!" << endl;
              cout << "Press Enter!" << endl;
              cin.get();
              cin.get();
              Option = '8';
            } else if(temporary.getScore() <= 0){
              cout << "You dont have score for this operation!" << endl;
              cout << "Press Enter!" << endl;
              cin.get();
              cin.get();
              Option = '8';
            } else if(temporary.getScore() - (newCoins*CONVERSION_SCORE) <= 0) {
              cout << "You dont have score for this operation!" << endl;
              cout << "Press Enter!" << endl;
              cin.get();
              cin.get();
              Option = '8';
            } else {
              temporary.addCoins(newCoins);
              temporary.addScore(-(newCoins*CONVERSION_SCORE));
            }
          }

          break;
        }
        default: {
          cout << "Select the right option" << endl;
          cout << "Press Enter!" << endl;
          cin.get();
          cin.get();
          break;
        }
      }
    } else {
      cout << "Incorrect Password" <<endl;
      return;
    }

    if(Option < '8' && Option > '0'){
      Menu::clearScreen();
      if(Option != '1') data.dropUser(temporary.getName());
      data.setUser(temporary);
      cout << "Mudancas realizadas com sucesso" << endl;
      cout << "***********************************************************************" << endl;

      cout << "Press Enter!" << endl;
      cin.get();
      cin.get();
    }

    data.exportDataBase();
    data = DataBase();
    Menu::clearScreen();
  }
}


void Menu::menuPrograma(User & temporary, DataBase &data) {
  bool options = true;

  while(options == true) {
    cout << " Hello " << temporary.getName() << endl;
    cout << "******************* " << "Profile" << " *******************************************" << endl;
    cout << "* " << setw(37) << " Choose an option from below" << setw(32)  << "*" << endl;
    cout << "* " << setw(25) << "1. Play a game" << setw(45) << " * " << endl;
    cout << "* " << setw(23) << "2. Info User" << setw(46) << " *" << endl;
    cout << "* " << setw(21) << "3. Ranking" << setw(48) << " *" << endl;
    cout << "* " << setw(20) << "4. Logout" << setw(49) << " *" << endl;
    cout << "* " << setw(33) << "[Choose Your Option] : ";
    char option;
    string pressKey;
    cin >> option;
    cout << "***********************************************************************" << endl;
    switch(option) {
      case '1': {
        Menu::clearScreen();
        Menu::menuInfoGames(temporary, data);
        break;
      }
      case '2': {
        Menu::clearScreen();
        Menu::menuInfoUser(temporary, data);
        break;
      }
      case '3':{
        Menu::clearScreen();
        data.ranking();
        cout << "Press Enter!" << endl;
        cin.get();
        cin.get();
        Menu::clearScreen();
        break;
      }
      case '4': {
        Menu::clearScreen();
        options = false;
        break;
      }
      default: {
        cout << "Select the right option" << endl;
        cout << "Press Enter!" << endl;
        cin.get();
        cin.get();
        Menu::clearScreen();
      }
    }
  }

  if(options == false){
    data.exportDataBase();
    cout << "You've been logged out." << endl;
    cout << "Press Enter!" << endl;
    cin.get();
    cin.get();
    return;
  }

}

User Menu::createNewUser(){
  string name, password, gender, city, college;
  int age;

  Menu::clearScreen();
  cout << "Name :";
  cin >> name;
  cout << endl;
  cout << "Password :";
  cin >> password;
  cout << endl;
  cout << "Gender  (Choose F or M): ";
  cin >> gender;
  while(gender[0] != 'F' && gender[0] != 'M'){
    cout << "Error, select F or M" << endl;
    cout << "Gender  (Choose F or M): ";
    cin >> gender;
  }
  cout << endl;
  cout << "Age :";
  cin >> age;
  while(age <= 0){
    cout << "Error, " << endl;
    cout << "Age :";
    cin >> age;
  }
  cout << endl;
  cout << "City :";
  cin >> city;
  cout << endl;
  cout << "College :";
  cin >> college;
  cout << endl;

  return User(name, password, gender, age, city, college);
}

void Menu::clearScreen(){
  #ifdef _WIN32
      std::system("cls");
  #else
      std::system ("clear");
  #endif
}
