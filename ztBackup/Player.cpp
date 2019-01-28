#include "Player.hpp"

Player::Player() :
	balance(100000) {}

Player::Player(double value) :
	balance(value) {}

double Player::getBalance() const
{
	return balance;
}

void Player::buy(double value)
{
	balance -= value;
}

void Player::deposit(double value)
{
	balance += value;
}
