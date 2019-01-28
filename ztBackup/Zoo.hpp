#ifndef ZOO_HPP
#define ZOO_HPP

#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <iomanip>

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Player.hpp"
#include "Menu.hpp"


#define STARTING_CAPACITY 10

enum ANIMAL_STATE {BABY = 0, ADULT = 3};

enum EVENT_TYPE {SICK_EVENT, ATTENDANCE_EVENT, BABY_EVENT, NOTHING};

enum ANIMAL_TYPE {TIGER, PENGUIN, TURTLE};

class Zoo {

private:

	Player& bound_player;		//current bound player controlling the zoo
	std::ostream& output;		//current bound output stream

	int tigerArraySize;			//max size of array, default = 10, will double if full
	int penguinArraySize;		//max size of array, default = 10, will double if full
	int turtleArraySize;		//max size of array, default = 10, will double if full

	int dayCount;

	int tigerCount;				//tiger counter
	int penguinCount;			//penguin counter
	int turtleCount;			//turtle counter

	double tigerCost;
	double penguinCost;
	double turtleCost;


	Tiger*		m_tigers;		//tiger exhibit
	Penguin*	m_penguins;		//penguin exhibit
	Turtle*		m_turtles;		//turtle exhibit


	Menu startMenu;
	Menu startQuantityMenu;
	Menu dailyBuyPromptMenu;
	Menu dailyBuyMenu;
	Menu repeatMenu;


	bool isFull() const;						//check to see if a container needs resized
	
	void resizeTigerArray(Tiger*&, int&);		//double the size constant and array passed in

	void resizePenguinArray(Penguin*&, int&);	

	void resizeTurtleArray(Turtle*&, int&);

	int generateRandom(const int&, const int&) const;	//generate random number within range

	void ageAnimals();

	void init();

	void buildMenus();

	bool playerCanBuy(double) const;

	double getFeedCost();

	void removeAnimalEvent();

	double attendanceBoomEvent();

	void animalBirthEvent();

	bool hasAdult(ANIMAL_TYPE);

	int zooHasAdult();

public:

	Zoo(Player&, std::ostream&);

	void addTiger(const int&, int);

	void addPenguin(const int&, int);

	void addTurtle(const int&, int);

	bool removeTiger();

	bool removePenguin();

	bool removeTurtle();

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

	std::string getPlayerMoney() {
		return std::to_string(bound_player.getBalance());
	}

	void start();

};








#endif