#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"


#define		DEFAULT_TURTLE_AGE					1
#define		DEFAULT_TURTLE_COST					100
#define		DEFAULT_TURTLE_BABIES				10
#define		DEFAULT_TURTLE_FOOD_MULTIPLIER		0.5
#define		DEFAULT_TURTLE_PAYOFF				0.05

class Turtle : public Animal {


private:

	double feedCost;		//feed_multiplier * food_base_constant
	double payoffValue;		//default payoff  * default cost




public:

	Turtle();

	double getFeedCost() const;

	double getPayoffValue() const;

	void printTurtle() {
		std::cout << "Turtle: " << this << " Age: " << this->age << std::endl;
	}

	static double getCost();



};


#endif