CC=g++
LINK=$(CC)

PLATFORM=linux  # Change this to your platform. TODO Auto-dectect.
ifeq "$(PLATFORM)" "linux"
	extension=""
	purge=rm
else ifeq "$(PLATFORM)" "windows"
	extension=.exe
	purge=del
endif

exec_main: creature party main
	$(CC) -o bin/oChre$(extension) bin/main.o bin/party.o bin/creature.o
exec_tests:  test_creature test_party
	$(CC) -o bin/tests$(extension) bin/creature.o bin/tests_creature.o bin/party.o bin/tests_party.o

creature:
	$(CC) -o bin/creature.o -c src/creature.cpp
main:
	$(CC) -o bin/main.o -c src/main.cpp
party:
	$(CC) -o bin/party.o -c src/party.cpp

test_creature: creature
	$(CC) -o bin/tests_creature.o -c src/tests/creature.cpp
test_party: party
	$(CC) -o bin/tests_party.o -c src/tests/party.cpp

clean:
	$(PURGE) bin/*.o bin/*$(extension)