CC=g++
EXT=o
PURGE=rm

#The main bin
program: item.o hero.$(EXT) main.$(EXT)
	$(CC) -o oChre.exe obj/hero.$(EXT) obj/main.$(EXT) -lm
main.o:
	$(CC) -c src/main.cpp -o obj/main.o

#Creatures
hero.o:
	$(CC) -c src/hero.cpp -o obj/hero.o

#items
item.o:
	$(CC) -c src/item.cpp -o obj/item.o

clean:
	$(PURGE) obj/*.$(EXT) *.exe
