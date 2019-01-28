/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 01/27/19
*	Project: Project 2
*
*	Description: Penguin class, defines age, cost, babies, foodx,
*	payoff value for the penguin class. The payoff value is precalculates
*	and stored as a variable to improve run-time speed.

INHERITS FROM ANIMAL
**************************************************************/

#include "Penguin.hpp"


/*Default connstructor, sets class variables to constants defined at top of class header*/
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

double Penguin::getCost()
{
	return DEFAULT_PENGUIN_COST;
}
