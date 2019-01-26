#include <iostream>
#include "Zoo.hpp"






int main() {

	std::cout << "Zoo start: " << std::endl;

	Player player1(100000);
	Zoo zoo1(player1);




	//zoo1.addTiger(1);

	//zoo1.printAnimalContents();

	zoo1.addTiger(1, BABY);
	zoo1.addTiger(1, ADULT);
	zoo1.addTiger(1, BABY);

	zoo1.printAnimalContents();

	std::cout << zoo1.removeTiger() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	zoo1.printAnimalContents();


	


	std::cin.ignore(34747, '\n');
	std::cin.get();
	
	return 0;
}