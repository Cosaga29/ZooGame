/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 01/27/19
*	Project: Project 2
*
*	Description:
**************************************************************/

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