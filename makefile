CC=g++
EXT=o
PURGE=del
program: hero.$(EXT) main.$(EXT)
	$(CC) -o oChre.exe hero.$(EXT) main.$(EXT) -lm
main.o: main.cpp
	$(CC) -c main.cpp
hero.o: hero.cpp hero.h
	$(CC) -c hero.cpp
clean: 
	$(CC) *.$(EXT) *.exe