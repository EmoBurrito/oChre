CC=g++
PURGE=rm

#The main bin
program: consumable equippable human main
	$(CC) build/consumable.o build/equippable.o build/item.o build/creature.o build/human.o build/main.o -o bin/oChre.exe -lm
main:
	$(CC) -c src/main.cpp -o build/main.o

#Creatures
creature:
	$(CC) -c src/creature.cpp -o build/creature.o
human: creature
	$(CC) -c src/human.cpp -o build/human.o

#Items
item:
	$(CC) -c src/item.cpp -o build/item.o
consumable: item
	$(CC) -c src/consumable.cpp -o build/consumable.o
equippable: item
	$(CC) -c src/equippable.cpp -o build/equippable.o

#Cleaning up
clean:
	$(PURGE) build/*.o bin/*.exe
