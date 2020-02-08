g++ -o bin/creature.o -c src/creature.cpp
g++ -o bin/party.o -c src/party.cpp
g++ -o bin/main.o -c src/main.cpp
g++ -o bin/oChre.exe bin/main.o bin/party.o bin/creature.o
