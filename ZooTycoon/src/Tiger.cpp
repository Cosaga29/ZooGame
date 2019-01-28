/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 01/27/19
*	Project: Project 2
*
*	Description: Tiger class, defines age, cost, babies, foodx,
*	payoff value for the tiger class. The payoff value is precalculates
*	and stored as a variable to improve run-time speed.

INHERITS FROM ANIMAL
**************************************************************/

#include "Tiger.hpp"


/*Default connstructor, sets class variables to constants defined at top of class header*/
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
