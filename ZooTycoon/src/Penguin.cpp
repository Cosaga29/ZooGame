#include "Penguin.hpp"

Penguin::Penguin() :
	Animal(DEFAULT_PENGUIN_AGE, DEFAULT_PENGUIN_COST, DEFAULT_PENGUIN_BABIES,
		DEFAULT_PENGUIN_FOOD_MULTIPLIER, DEFAULT_PENGUIN_PAYOFF)
{
	feedCost = DEFAULT_PENGUIN_FOOD_MULTIPLIER * BASE_FOOD_COST;
	payoffValue = DEFAULT_PENGUIN_PAYOFF * DEFAULT_PENGUIN_COST;
}

double Penguin::getFeedCost() const
{
	return feedCost;
}

double Penguin::getPayoffValue() const
{
	return payoffValue;
}
