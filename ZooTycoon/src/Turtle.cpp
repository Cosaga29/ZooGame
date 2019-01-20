#include "Turtle.hpp"

Turtle::Turtle() :
	Animal(DEFAULT_TURTLE_AGE, DEFAULT_TURTLE_COST, DEFAULT_TURTLE_BABIES,
		DEFAULT_TURTLE_FOOD_MULTIPLIER, DEFAULT_TURTLE_PAYOFF)
{
	feedCost = DEFAULT_TURTLE_FOOD_MULTIPLIER * BASE_FOOD_COST;
	payoffValue = DEFAULT_TURTLE_PAYOFF * DEFAULT_TURTLE_COST;
}

double Turtle::getFeedCost() const
{
	return feedCost;
}

double Turtle::getPayoffValue() const
{
	return payoffValue;
}
