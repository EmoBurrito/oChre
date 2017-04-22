CC=g++
EXT=o
PURGE=rm
program: hero.$(EXT) main.$(EXT)
	$(CC) -o oChre.exe obj/hero.$(EXT) obj/main.$(EXT) -lm
main.o:
	$(CC) -c src/main.cpp -o obj/main.o
hero.o:
	$(CC) -c src/hero.cpp -o obj/hero.o
clean: 
	$(PURGE) obj/*.$(EXT) *.exe