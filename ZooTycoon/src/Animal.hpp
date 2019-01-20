#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#define BASE_FOOD_COST 10


class Animal {

protected:

	int age;
	double cost;
	int number_of_babies;
	double base_food_cost;
	double payoff;




public:

	Animal();

	Animal(int, double, int, double, double);

	Animal(int, double, int, double);

	void incrementAge();

	int getAge() const;

	double getPayoff() const;

	void setAge(const int&);

};















#endif