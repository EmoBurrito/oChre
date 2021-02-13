#include "catch.hpp"
#include "../party.hpp"
#include <iostream> //print and getting input
void empty_party(Party party) {
	for (unsigned char i = 0; i < party.MEMBERS_MAX; i++) {
		party.members[i] = NULL;
	}
}

SCENARIO("Members can be managed", "[party]") {
	GIVEN("One party and six creatures") {
		Party my_party;
		Human human1("First");
		Human human2("Second");
		Human human3("Third");
		Human human4("Fourth");
		Human human5("Fifth");
		Human human6("Sixth");
		WHEN ("We add a member") {
			THEN ("The party gains a member in the first available slot.") {
				my_party.add_member(&human1);
				my_party.add_member(&human2);
				my_party.add_member(&human3);
				REQUIRE(my_party.members[0]->get_name() == "First");
				REQUIRE(my_party.members[1]->get_name() == "Second");
				REQUIRE(my_party.members[2]->get_name() == "Third");
				REQUIRE_FALSE(my_party.members[3]);
				REQUIRE_FALSE(my_party.members[4]);
				REQUIRE_FALSE(my_party.members[5]);
				empty_party(my_party);
			}
		}
		WHEN ("We add a member with a specific slot") {
			THEN ("The part gains a member in that specific slot.") {
				my_party.add_member(&human1, 0);
				my_party.add_member(&human2, 2);
				my_party.add_member(&human3, 4);
				REQUIRE(my_party.members[0]->get_name() == "First");
				REQUIRE_FALSE(my_party.members[1]);
				REQUIRE(my_party.members[2]->get_name() == "Second");
				REQUIRE_FALSE(my_party.members[3]);
				REQUIRE(my_party.members[4]->get_name() == "Third");
				REQUIRE_FALSE(my_party.members[5]);
				empty_party(my_party);
			}
		}
		WHEN ("We try to add a member but there are no available slots") {
			THEN ("The new member will not be added.") {
				my_party.add_member(&human1);
				my_party.add_member(&human2);
				my_party.add_member(&human3);
				my_party.add_member(&human4);
				my_party.add_member(&human5);
				my_party.add_member(&human6);
				Human human7("Seventh");
				my_party.add_member(&human7);
				for (unsigned char i = 0; i < my_party.MEMBERS_MAX; i++) {
					REQUIRE(my_party.members[i]->get_name() != "Seventh");
				}
				empty_party(my_party);
			}
		}
		WHEN ("We remove a member") {
			THEN ("The party loses a member.") {
				my_party.add_member(&human1);
				my_party.add_member(&human2);
				my_party.add_member(&human3);
				my_party.remove_member(1);
				REQUIRE(my_party.members[0]->get_name() != "Second");
				REQUIRE_FALSE(my_party.members[1]);
				REQUIRE(my_party.members[2]->get_name() != "Second");
				REQUIRE_FALSE(my_party.members[3]);
				REQUIRE_FALSE(my_party.members[4]);
				REQUIRE_FALSE(my_party.members[5]);
				empty_party(my_party);
			}
		}
		WHEN ("We swap to existing party members") {
			THEN ("The two existing party memembers will swap slots.") {
				my_party.add_member(&human1);
				my_party.add_member(&human2);
				my_party.add_member(&human3);
				my_party.swap_members(0, 2);
				REQUIRE(my_party.members[0]->get_name() == "Third");
				REQUIRE(my_party.members[1]->get_name() == "Second");
				REQUIRE(my_party.members[2]->get_name() == "First");
				REQUIRE_FALSE(my_party.members[3]);
				REQUIRE_FALSE(my_party.members[4]);
				REQUIRE_FALSE(my_party.members[5]);
				empty_party(my_party);
			}
		}
		WHEN ("We swap an existing party memeber with an empty slot.")
			THEN("The existing party member will be moved to that slot. Their old slot will be empty.") {
				my_party.add_member(&human1);
				my_party.swap_members(0, 5);
				REQUIRE_FALSE(my_party.members[0]);
				REQUIRE_FALSE(my_party.members[1]);
				REQUIRE_FALSE(my_party.members[2]);
				REQUIRE_FALSE(my_party.members[3]);
				REQUIRE_FALSE(my_party.members[4]);
				REQUIRE(my_party.members[5]->get_name() == "First");
				empty_party(my_party);
			}
	}
}

SCENARIO("One party can be instantiated", "[party]") {
	GIVEN("One party") {
		Party my_party;

		REQUIRE(my_party.adjust_food(0) == 6);
		REQUIRE(my_party.adjust_gold(0) == 100);
	}
}
