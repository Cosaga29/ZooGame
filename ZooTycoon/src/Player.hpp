#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {

private:

	double balance;



public:

	Player();

	Player(double);

	double getBalance() const;	//return the players money

	void buy(double);			//player buys something, withdraw money 

	void deposit(double);		//perform a deposit action

};


#endif