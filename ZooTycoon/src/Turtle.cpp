/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 01/27/19
*	Project: Project 2
*
*	Description: Turtle class, defines age, cost, babies, foodx,
*	payoff value for the turtle class. The payoff value is precalculates
*	and stored as a variable to improve run-time speed.

INHERITS FROM ANIMAL
**************************************************************/

#include "Turtle.hpp"

/*Default connstructor, sets class variables to constants defined at top of class header*/
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

double Turtle::getCost()
{
	return DEFAULT_TURTLE_COST;
}
