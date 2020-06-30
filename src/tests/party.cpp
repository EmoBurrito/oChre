#include "catch.hpp"
#include "../party.h"

SCENARIO("One party can be instantiated", "[party]") {
	GIVEN("One party") {
		Party my_party;

		REQUIRE(my_party.adjust_food(0) == 6);
		REQUIRE(my_party.adjust_gold(0) == 100);
	}
}