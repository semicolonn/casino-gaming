#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../components/User/User.hpp"

TEST_CASE("Constructor test"){

   User user = User("Clarissa", "senha", "F", 20,  "BH", "UFMG");

   REQUIRE(user.getName() == "Clarissa");
   REQUIRE(user.getPassword() == "senha");
   REQUIRE(user.getGender() == "F");
   REQUIRE(user.getAge() == 20);
   REQUIRE(user.getCity() == "BH");
   REQUIRE(user.getCollege() == "UFMG");
   REQUIRE(user.getScore() == 0);
   REQUIRE(user.getCoins() == 30);
}

TEST_CASE("Setter tests"){

   User user = User("Clarissa", "senha", "F", 20,  "BH", "UFMG");

   user.setName("Juaninha");
   user.setPassword("password");
   user.setGender("M");
   user.setAge(78);
   user.setCity("Santa Barbara");
   user.setCollege("EJA");
   user.setScore(100);
   user.setCoins(50);

   CHECK(user.getName() == "Juaninha");
   REQUIRE(user.getPassword() == "password");
   REQUIRE(user.getGender() == "M");
   REQUIRE(user.getAge() == 78);
   REQUIRE(user.getCity() == "Santa Barbara");
   REQUIRE(user.getCollege() == "EJA");
   REQUIRE(user.getScore() == 100);
   REQUIRE(user.getCoins() == 50);
}
