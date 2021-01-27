#include <climits> // variable max and mins
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../creature.h"
#include <iostream> //print and getting input
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

SCENARIO("Creatures can have their statistics changed", "[creature]") {
    GIVEN("One creature") {
        Human tester;

        WHEN("magically has a statistic increase or decrease.") {
            THEN("their strength increases.") {
                short int original = tester.get_statistic(tester.STRENGTH, false);
                tester.change_statistic(tester.STRENGTH, false, 10);
                std::cout << "Asserting " << original << " + " << 10 << " is " << tester.get_statistic(tester.STRENGTH, false) << "\n";
                REQUIRE(tester.get_statistic(tester.STRENGTH, false == original + 10));
            }
            THEN("their strength cannot exceed an upper limit.") {
                short int original = tester.get_statistic(tester.STRENGTH, false);
                tester.change_statistic(tester.STRENGTH, false, tester.STATISTIC_MAX);
                std::cout << "Asserting " << original << " + " << tester.STATISTIC_MAX << " is " << tester.get_statistic(tester.STRENGTH, false) << "\n";
                REQUIRE(tester.get_statistic(tester.STRENGTH, false == tester.STATISTIC_MAX));
            }
            THEN("their strength decreases.") {
                short int original = tester.get_statistic(tester.STRENGTH, false);
                tester.change_statistic(tester.STRENGTH, false, -20);
                std::cout << "Asserting " << original << " + " << -20 << " is " << tester.get_statistic(tester.STRENGTH, false) << "\n";
                REQUIRE(tester.get_statistic(tester.STRENGTH, false == original - 20));
            }
            THEN("their strength cannot exceed a lower limit.") {
                short int original = tester.get_statistic(tester.STRENGTH, false);
                tester.change_statistic(tester.STRENGTH, false, tester.STATISTIC_MIN);
                std::cout << "Asserting " << original << " + " << tester.STATISTIC_MIN << " is " << tester.get_statistic(tester.STRENGTH, false) << "\n";
                REQUIRE(tester.get_statistic(tester.STRENGTH, false == tester.STATISTIC_MIN));
            }
        }
    }
}
