CC=g++
PURGE=rm

#The main bin
program: item hero main
	$(CC) build/item.o build/hero.o build/main.o -o bin/oChre.exe -lm
main:
	$(CC) -c src/main.cpp -o build/main.o

#Creatures
hero:
	$(CC) -c src/hero.cpp -o build/hero.o
#Items
item:
	$(CC) -c src/item.cpp -o build/item.o
clean:
	$(PURGE) build/*.o bin/*.exe
