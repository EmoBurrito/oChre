# The user will need to pass in binary extension and purge command
# EXAMPLE: make binary=bin purge=rm

#The main bin
program: consumable equippable human dwarf goblin rat main
	g++ build/consumable.o build/equippable.o build/item.o build/creature.o build/human.o build/dwarf.o build/goblin.o build/rat.o build/main.o -o bin/oChre.$(binary) -lm
main:
	g++ -c src/main.cpp -o build/main.o

#Creatures
creature:
	g++ -c src/creature.cpp -o build/creature.o
human: creature
	g++ -c src/human.cpp -o build/human.o
dwarf: creature
	g++ -c src/dwarf.cpp -o build/dwarf.o
goblin: creature
	g++ -c src/goblin.cpp -o build/goblin.o
rat: creature
	g++ -c src/rat.cpp -o build/rat.o

#Items
item:
	g++ -c src/item.cpp -o build/item.o
consumable: item
	g++ -c src/consumable.cpp -o build/consumable.o
equippable: item
	g++ -c src/equippable.cpp -o build/equippable.o

#Cleaning up
clean:
	$(purge) build/*.o bin/oChre.$(binary)
