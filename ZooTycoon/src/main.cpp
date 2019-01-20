#include <iostream>
#include "Zoo.hpp"






int main() {

	std::cout << "Zoo start: " << std::endl;

	Player player1;
	Zoo zoo1(player1);


	for (int i = 0; i < 20; i++) {
		zoo1.addTiger(20);
	}
	for (int i = 0; i < 20; i++) {
		zoo1.addPenguin(20);
	}
	for (int i = 0; i < 20; i++) {
		zoo1.addTurtle(20);
	}

	zoo1.printAnimalContents();
	//zoo1.addTiger(1);


	zoo1.ageAnimals();

	zoo1.printAnimalContents();




	std::cin.ignore(34747, '\n');
	std::cin.get();
	
	return 0;
}