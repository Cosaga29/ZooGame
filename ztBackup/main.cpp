#include <iostream>
#include "Zoo.hpp"






int main() {

	std::cout << "Zoo start: " << std::endl;

	Player player1(100000);
	Zoo zoo1(player1, std::cout);
	zoo1.start();



	std::cin.ignore(34747, '\n');
	std::cin.get();
	
	return 0;
}