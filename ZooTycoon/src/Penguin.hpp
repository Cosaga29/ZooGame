#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"


#define		DEFAULT_PENGUIN_AGE					1
#define		DEFAULT_PENGUIN_COST				1000
#define		DEFAULT_PENGUIN_BABIES				5
#define		DEFAULT_PENGUIN_FOOD_MULTIPLIER		1
#define		DEFAULT_PENGUIN_PAYOFF				0.1

class Penguin : public Animal {


private:


	double feedCost;		//feed_multiplier * food_base_constant
	double payoffValue;		//default payoff  * default cost




public:

	Penguin();


	double getFeedCost() const;

	double getPayoffValue() const;


	void printPenguin() {
		std::cout << "Penguin " << this << " Age: " << this->age << std::endl;
	}

	static double getCost();

};


#endif