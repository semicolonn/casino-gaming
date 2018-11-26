#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../components/Database/Database.hpp"
#include "../../components/User/User.hpp"

TEST_CASE("DataBase Login Succefully"){

   DataBase data = DataBase();
   User user = User("Crocodilo", "senha", "F", 20,  "BH", "UFMG");

   data.setUser(user);
   REQUIRE(data.login(user) == 1);
}

TEST_CASE("Login test Error"){

   DataBase data = DataBase();
   User user = User("Banjo", "senha", "F", 20,  "BH", "UFMG");

   REQUIRE(data.login(user) == 0);
}
