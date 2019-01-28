#include "Animal.hpp"

Animal::Animal() :
	age(1), cost(5000), number_of_babies(2), base_food_cost(5.0), payoff(0.20) {}

Animal::Animal(int age, double cost, int number_of_babies, double base_food_cost, double payoff) :
	age(age), cost(cost), number_of_babies(number_of_babies), base_food_cost(base_food_cost), payoff(payoff) {}

Animal::Animal(int age, double cost, int number_of_babies, double base_food_cost) :
	age(age), cost(cost), number_of_babies(number_of_babies), base_food_cost(base_food_cost) {}

void Animal::incrementAge()
{
	++age;
}

int Animal::getAge() const
{
	return age;
}

double Animal::getPayoff() const
{
	return payoff * cost;
}

void Animal::setAge(const int &value)
{
	age = value;
}

bool Animal::isAdult() const
{
	return age >= ADULT_AGE;
}

int Animal::getNumberOfBabies() const
{
	return number_of_babies;
}

