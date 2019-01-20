#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {

private:

	double balance;



public:

	Player();

	Player(double);

	double getBalance() const;	//return the players money

	void modifyBalance(double);	//adjust the players money 

};


#endif