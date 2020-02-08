# Compiler, linker, and delete functions
# May need to be changed per platform
CC=g++
LINK=$(CC)
PURGE=rm
# PURGE=del

program: creature party main
	$(CC) -o bin/oChre.exe bin/main.o bin/party.o bin/creature.o

creature:
	$(CC) -o bin/creature.o -c src/creature.cpp
party:
	$(CC) -o bin/party.o -c src/party.cpp
main:
	$(CC) -o bin/main.o -c src/main.cpp
clean:
	$(PURGE) bin/*.o bin/oChre.exe
