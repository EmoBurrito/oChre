#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../creature.h"

SCENARIO("Creatures can be instantiated", "[creature]") {
	GIVEN("Two creatures") {
		Creature my_creature;  //No bracket invoke because no arguments passed. Compiler confuses with declaring function, like in a header file.
		Creature dummy("Test Dummy");

		REQUIRE(dummy.get_name() == "Test Dummy");
	}
}