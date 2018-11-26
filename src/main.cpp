#include <iostream>
#include <cstdio>
#include "../components/Menu/Menu.hpp"
#include "../components/Database/Database.hpp"
#include "../components/User/User.hpp"
#include "../components/Dealer/Dealer.hpp"
#include "../components/Blackjack/Blackjack.hpp"
using namespace std;

int main() {
    Menu menu;
    DataBase database = DataBase();
    User temporary;

    int input = 0;

    while(input == 0) {
        menu.clearScreen();
        cout << "\n-------------------Welcome  ---------------------\n\n\n";
        cout << "* " << setw(37) << " Choose an option from below" << setw(33)  << "*" << endl;
        cout << "* " << setw(25) << "1. Login" << setw(46) << " * " << endl;
	      cout << "* " << setw(23) << "2. New" << setw(47) << " *" << endl;
        cout << "* " << setw(24) << "3. Exit" << setw(46) << " *" << endl;
        cout << "* " << setw(33) << "[Choose Your Option] : ";

        char Option = '0';
        cin >> Option;

        switch(Option) {
        case '1': {
          menu.clearScreen();
          string name;
          string password;
          cout << "Username: ";
          cin >> name;
          temporary.setName(name);
          cout << "Password: ";
          cin >> password;
          temporary.setPassword(password);
          if(database.login(temporary) != 0){
            menu.clearScreen();
            menu.menuPrograma(temporary, database);
          }
          break;
        }
        case '2': {
          menu.clearScreen();
          temporary = menu.createNewUser();
          database.setUser(temporary);
          break;
        }
        case '3': {
          cout << "Bye Bye!" << endl;
          database.exportDataBase();
          database.removeDataBase();
          return 0;
        }
        default: {
          cout << "Select the right option" << endl;
          cout << "Pres Enter!" << endl;
          cin.get();
          cin.get();
        }
      }
    }

    return 0;
}
