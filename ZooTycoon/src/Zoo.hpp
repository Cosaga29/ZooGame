#ifndef ZOO_HPP
#define ZOO_HPP

#include <stdlib.h>
#include <time.h>

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Player.hpp"



#define STARTING_CAPACITY 10



class Zoo {

private:



	Player& bound_player;		//current bound player controlling the zoo

	int tigerArraySize;			//max size of array, default = 10, will double if full
	int penguinArraySize;		//max size of array, default = 10, will double if full
	int turtleArraySize;		//max size of array, default = 10, will double if full

	int dayCount;

	int tigerCount;				//tiger counter
	int penguinCount;			//penguin counter
	int turtleCount;			//turtle counter

	Tiger*		m_tigers;		//tiger exhibit
	Penguin*	m_penguins;		//penguin exhibit
	Turtle*		m_turtles;		//turtle exhibit




	bool isFull() const;						//check to see if a container needs resized
	
	void resizeTigerArray(Tiger*&, int&);		//double the size constant and array passed in

	void resizePenguinArray(Penguin*&, int&);	

	void resizeTurtleArray(Turtle*&, int&);

	int generateRandom(const int&, const int&) const;	//generate random number within range



public:

	Zoo(Player&);


	void addTiger(const int&);

	void addPenguin(const int&);

	void addTurtle(const int&);


	void printAnimalContents() const {
		std::cout << "TIGERS: " << std::endl;
		for (int i = 0; i < tigerCount; i++) {
			m_tigers[i].printTiger();
		}

		std::cout << "PENGUINS: " << std::endl;
		for (int i = 0; i < penguinCount; i++) {
			m_penguins[i].printPenguin();
		}


		std::cout << "TURTLES: " << std::endl;
		for (int i = 0; i < turtleCount; i++) {
			m_turtles[i].printTurtle();
		}

	}



	void ageAnimals();



	



};








#endif