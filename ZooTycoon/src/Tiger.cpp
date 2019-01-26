#include "Tiger.hpp"



Tiger::Tiger() :
	Animal(DEFAULT_TIGER_AGE, DEFAULT_TIGER_COST, DEFAULT_TIGER_BABIES,
			DEFAULT_TIGER_FOOD_MULTIPLIER, DEFAULT_TIGER_PAYOFF)
{
	feedCost		= DEFAULT_TIGER_FOOD_MULTIPLIER * BASE_FOOD_COST;
	payoffValue		= DEFAULT_TIGER_PAYOFF * DEFAULT_TIGER_COST;
}

double Tiger::getFeedCost() const
{
	return feedCost;
}

double Tiger::getPayoffValue() const 
{
	return payoffValue;
}

double Tiger::getCost()
{
	return DEFAULT_TIGER_COST;
}
