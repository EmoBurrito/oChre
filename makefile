CC=g++
LINK=$(CC)

ifeq ($(OS),Windows_NT)
	extension=.exe
	purge=del
	extra_args=-static-libgcc -static-libstdc++
else
	purge=rm
endif

exec_main: creature party main
	$(CC) -o bin/oChre$(extension) bin/main.o bin/party.o bin/creature.o $(extra_args)
exec_tests:  test_creature test_party
	$(CC) -o bin/tests$(extension) bin/creature.o bin/tests_creature.o bin/party.o bin/tests_party.o

creature:
	$(CC) -o bin/creature.o -c src/creature.cpp
main:
	$(CC) -o bin/main.o -c src/main.cpp -DOCHRE_VERSION=\"Change.Me\"
party:
	$(CC) -o bin/party.o -c src/party.cpp

test_creature: creature
	$(CC) -o bin/tests_creature.o -c src/tests/creature.cpp
test_party: party
	$(CC) -o bin/tests_party.o -c src/tests/party.cpp

clean:
	$(PURGE) bin/*.o bin/*$(extension)
