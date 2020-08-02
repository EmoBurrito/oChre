#include <climits> // variable max and mins
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../creature.h"

SCENARIO("Creatures can be instantiated", "[creature]") {
	GIVEN("Two creatures") {
		Human tester;
		Human dummy("Test Dummy");

		WHEN("we offend someone") {
			THEN("they get offended.") {
				dummy.change_relationship(-10);
				REQUIRE(dummy.change_relationship(0) == 40);
			}
			THEN("but there there is a limit to how offended they get.") {
				dummy.change_relationship(CHAR_MIN);
				REQUIRE(dummy.change_relationship(0) == dummy.RELATIONSHIP_MIN);
			}
		}
		WHEN("we charm someone") {
			THEN("they get charmed.") {
				dummy.change_relationship(10);
				REQUIRE(dummy.change_relationship(0) == 60);
			}
			THEN("but there there is a limit to how charmed they get.") {
				dummy.change_relationship(CHAR_MAX);
				REQUIRE(dummy.change_relationship(0) == dummy.RELATIONSHIP_MAX);
			}
		}
	}
}
