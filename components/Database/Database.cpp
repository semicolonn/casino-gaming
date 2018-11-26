#include "Database.hpp"

DataBase::DataBase() : users(DataBase::importDataBase()) {}

DataBase::~DataBase(){}

//create a list of object from a text file
list<User> DataBase::importDataBase(){

  string line;
  list<User> usersAux;
  User user = User();
  ifstream fileData(DATA_STORAGE);

  try{
    if(!fileData.is_open()) throw ExceptionDataBase();

    while(getline(fileData, line)){
      //receive object and put on list
      user = DataBase::insertData(line);
      usersAux.push_back(user);
      line.clear();
    }
    fileData.close();
  } catch (exception& e){
    cout << '\n' << e.what() << '\n' << '\n';
    terminate();
  }
  return usersAux;
}

//get user's data from text line
User DataBase::insertData(string line){
	stringstream substring(line);
  string name, password, gender, age, city, college, coins, score;
  User user = User();

	//get a substring until delimiter into string
	getline(substring, name, DELIMITER);
	getline(substring, password, DELIMITER);
	getline(substring, gender, DELIMITER);
	getline(substring, age, DELIMITER);
	getline(substring, city, DELIMITER);
	getline(substring, college, DELIMITER);
	getline(substring, score, DELIMITER);
	getline(substring, coins, DELIMITER);

	//set User's data
	user.setName(name);
	user.setPassword(password);
	user.setGender(gender);
	user.setAge(stoi(age));
	user.setCity(city);
  user.setCollege(college);
	user.setScore(stoi(score));
	user.setCoins(stoi(coins));
	substring.clear();

	return user;
}

list<User> DataBase::getUsers(){
	return this->users;
}

//get user data by the name
User DataBase::getUser(string name){
	User user = User();

    	//get user position
    auto it = find_if(this->users.begin(), this->users.end(),[&name](const User& user) {
      return user.getName() == name;
    });
    //check if user exists in database
    if (it != this->users.end()){
      return *it;
    }
    else{
      return user;
    }
}

//insert user
void DataBase::setUser(User user){
    string name = user.getName();

    //get user position
    auto it = find_if(this->users.begin(), this->users.end(),
    [&name](const User& user) {
      return user.getName() == name;
    });
    //check if user exists in database
    if (it == this->users.end()){
      this->users.push_back(user);
    }
}

//remove user from database
void DataBase::dropUser(string name){

    //get user position
    auto it = find_if(this->users.begin(), this->users.end(),
      [&name](const User& user) {
        return user.getName() == name;
      });
    //check if user exists in database
    if(it != this->users.end()){
      this->users.erase(it);
    }
}

void DataBase::removeDataBase(){
	this->users.clear();
}

//Write all list content and save in a text file
void DataBase::exportDataBase(){
  ofstream fileData(DATA_STORAGE);

  try{
    if(!fileData.is_open()) throw ExceptionDataBase();

    for(User i : DataBase::getUsers()){
      fileData << i.getName() << DELIMITER << i.getPassword() << DELIMITER <<
      i.getGender() << DELIMITER << i.getAge() << DELIMITER <<
      i.getCity() << DELIMITER << i.getCollege() << DELIMITER <<
      i.getScore() << DELIMITER << i.getCoins() << endl;
    }
    fileData.close();
  }catch (exception& e){
    cout << '\n' <<  e.what() << '\n'<< '\n';
    terminate();
  }
}

//sort users by highest score
void DataBase::ranking(){

  list<User> usersAux;
  int position = 1;

  usersAux = DataBase::getUsers();
  //native function to sort elements in a estructure
	usersAux.sort([](const User& userA, const User& userB){
    return userA.getScore() > userB.getScore();
  });
	for(User i : usersAux){
    cout << position << "# ";
    i.printStatus();
    position++;
	}
}

//Get user and compare name and password
int DataBase::login(User& user){

  User userDB = DataBase::getUser(user.getName());

  if(userDB.getName() == user.getName() && userDB.getPassword() == user.getPassword()){
    user = userDB;
    return 1;
  }else{
    return 0;
  }
}
