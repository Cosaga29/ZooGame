#include "Zoo.hpp"



/*
Arrays are initialized with 10 animals each, but when the zoo updates
only the animals up to the count of the animal are updated and used in the
const calculations


*/
Zoo::Zoo(Player& player) :
	bound_player(player), tigerArraySize(STARTING_CAPACITY),
	penguinArraySize(STARTING_CAPACITY),
	turtleArraySize(STARTING_CAPACITY), dayCount(0),
	tigerCount(0), penguinCount(0), turtleCount(0)
{
	//seed RNG
	srand(time(NULL));


	//initialize dynamic arrays for each animal type
	m_tigers = new Tiger[STARTING_CAPACITY];
	m_penguins = new Penguin[STARTING_CAPACITY];
	m_turtles = new Turtle[STARTING_CAPACITY];

	tigerCost = Tiger::getCost();
	penguinCost = Penguin::getCost();
	turtleCost = Turtle::getCost();



	//buildMenus();
	//init();
}


bool Zoo::isFull() const
{
	if (tigerCount == tigerArraySize || 
		penguinCount == penguinArraySize || 
		turtleCount == turtleArraySize) {
		return true;
	}
	return false;
}



void Zoo::resizeTigerArray(Tiger*& animalArray, int& size) {

	//allocate memory for twice the current array size
	Tiger* arr = new Tiger[size * 2];

	//delete old tiger array
	delete[] animalArray;

	//double size index of array
	size = size * 2;

	//set pointer to new array of double size
	animalArray = arr;

	//safely set the new pointer to 0
	arr = 0;
}



void Zoo::resizePenguinArray(Penguin *& animalArray, int &size)
{
	//allocate memory for twice the current array size
	Penguin* arr = new Penguin[size * 2];

	//delete old penguin array
	delete[] animalArray;



	//double size index of array
	size = size * 2;

	//set pointer to new array of double size
	animalArray = arr;

	//safely set the new pointer to 0
	arr = 0;
}



void Zoo::resizeTurtleArray(Turtle *& animalArray, int &size)
{
	//allocate memory for twice the current array size
	Turtle* arr = new Turtle[size * 2];

	//delete old turtle array
	delete[] animalArray;

	//double size index of array
	size = size * 2;

	//set pointer to new array of double size
	animalArray = arr;

	//safely set the new pointer to 0
	arr = 0;
}




int Zoo::generateRandom(const int& min, const int& max) const
{

	int toReturn = rand();
	toReturn = (toReturn % (min + max)) - min;

	//
	std::cout << "random num: " <<  toReturn << std::endl;
	return toReturn;

}


void Zoo::addTiger(const int &quantity, ANIMAL_STATE age)
{

	for (int i = 0; i < quantity; i++) {
		if (tigerCount < tigerArraySize - 1) {	//if less tigers than capacity
			tigerCount++;
		}
		else {
			resizeTigerArray(m_tigers, tigerArraySize); //resize
			tigerCount++;
		}
		m_tigers[tigerCount].setAge(age);

	}

	

}

void Zoo::addPenguin(const int &quantity, ANIMAL_STATE age)
{
	
	for (int i = 0; i < quantity; i++) {
		if (penguinCount < penguinArraySize - 1) {	//if less tigers than capacity
			penguinCount++;
		}
		else {
			resizePenguinArray(m_penguins, penguinArraySize); //resize
			penguinCount++;
		}
		m_penguins[penguinCount].setAge(age);
	}

}

void Zoo::addTurtle(const int &quantity, ANIMAL_STATE age)
{

	for (int i = 0; i < quantity; i++) {

		if (turtleCount < turtleArraySize - 1) {	//if less tigers than capacity
			turtleCount++;
		}
		else {
			resizeTurtleArray(m_turtles, turtleArraySize); //resize
			turtleCount++;
		}
		m_turtles[turtleCount].setAge(age);
	}

}

bool Zoo::removeTiger()
{
	if (tigerCount > 0) {
		//generate random number between 0 and (tigerCount - 1)
		int randIndex = generateRandom(0, tigerCount);


		//set to-be-removed animal to default age
		m_tigers[randIndex].setAge(1);

		//swap to-be-removed animal with last 'owned' animal
		m_tigers[randIndex] = m_tigers[tigerCount - 1];

		//decrement tiger count
		--tigerCount;
		
		return true; //animal was able to be removed
	}
	else {
		return false; //animal was unable to be removed
	}
}


bool Zoo::removePenguin()
{
	if (penguinCount > 0) {
		//generate random number between 0 and (tigerCount - 1)
		int randIndex = generateRandom(0, (penguinCount));


		//set to-be-removed animal to default age
		m_penguins[randIndex].setAge(1);

		//swap to-be-removed animal with last 'owned' animal
		m_penguins[randIndex] = m_penguins[tigerCount - 1];

		//decrement tiger count
		--penguinCount;

		return true; //animal was able to be removed
	}
	else {
		return false; //animal was unable to be removed
	}

}


bool Zoo::removeTurtle()
{
	if (turtleCount > 0) {
		//generate random number between 0 and (tigerCount - 1)
		int randIndex = generateRandom(0, (turtleCount));


		//set to-be-removed animal to default age
		m_turtles[randIndex].setAge(1);

		//swap to-be-removed animal with last 'owned' animal
		m_turtles[randIndex] = m_turtles[turtleCount - 1];

		//decrement tiger count
		--turtleCount;

		return true; //animal was able to be removed
	}
	else {
		return false; //animal was unable to be removed
	}
}



void Zoo::ageAnimals()
{

	for (int i = 0; i < tigerCount; i++) {
		m_tigers[i].incrementAge();
	}

	for (int i = 0; i < penguinCount; i++) {
		m_penguins[i].incrementAge();
	}

	for (int i = 0; i < turtleCount; i++) {
		m_turtles[i].incrementAge();
	}

}



void Zoo::init() {

	//start game
	bool goodStart = false;
	int userChoice;


	while (!goodStart) {
		startMenu.displayMessage("Purchase at least 1 of each animal to continue.");
		startMenu.displayMessage("\tBalance: " + getPlayerMoney());
		switch (startMenu.getUserChoice()) {

			case 1:
				//set starting tigers
				startQuantityMenu.displayMessage("1 or 2?");
				userChoice = startQuantityMenu.getUserChoice();

				if (playerCanBuy(userChoice * tigerCost)) {
					addTiger(userChoice, BABY);
					bound_player.buy(userChoice * tigerCost);
				}
				else {
					std::cout << "Not enough money" << std::endl;
				}

				break;

			case 2:
				//set starting penguins
				startQuantityMenu.displayMessage("1 or 2?");
				userChoice = startQuantityMenu.getUserChoice();

				if (playerCanBuy(userChoice * penguinCost)) {
					addPenguin(userChoice, BABY);
					bound_player.buy(userChoice * penguinCost);
				}
				else {
					std::cout << "Not enough money" << std::endl;
				}

				break;

			case 3:
				//set starting turtles
				startQuantityMenu.displayMessage("1 or 2?");
				userChoice = startQuantityMenu.getUserChoice();

				if (playerCanBuy(userChoice * turtleCost)) {
					addTurtle(userChoice, BABY);
					bound_player.buy(userChoice * turtleCost);
				}
				else {
					std::cout << "Not enough money" << std::endl;
				}

				break;
		}

		if (tigerCount >= 1 && penguinCount >= 1 && turtleCount >= 1) {
			goodStart = true;
		}
	}
	










}

void Zoo::buildMenus()
{
	startMenu.addPrompt("Purchase Tiger:   ");
	startMenu.addPrompt("Purchase Penguin: ");
	startMenu.addPrompt("Purchase Turtle:  ");

	startQuantityMenu.addPrompt("Purchase 1");
	startQuantityMenu.addPrompt("Purchase 2");

}

bool Zoo::playerCanBuy(double cost) const
{
	if (bound_player.getBalance() - cost >= 0) {
		return true;
	}
	else {
		return false;
	}
}


/*
Simulate one day at the zoo
*/
void Zoo::step()
{
	double bonus = 0.0;


	//while the player hasnt chosen to exit OR player hasn't ran out of money



	//age all the animals
	ageAnimals();


	//user needs to pay feeding cost (calculate feed cost)
	bound_player.buy(getFeedCost());


	//get a random number for a random event
	//TODO: implement events
	switch (static_cast<EVENT_TYPE>(generateRandom(0, 3))){

		case SICK_EVENT:
			break;


		case ATTENDANCE_EVENT:
			break;


		case BABY_EVENT:
			break;


		case NOTHING:
			break;


	}



	//calculate profit for the day



	//ask player if they would like to buy adult animal, if they do, ask for animal type
	//add the ADULT animal to the zoo and subtract cost



}

double Zoo::getFeedCost()
{
	double total = 0;
	//cost of tigers:
	total += (tigerCount * m_tigers[0].getFeedCost());

	//cost of penguins
	total += (penguinCount * m_penguins[0].getFeedCost());

	//cost of turtles
	total += (turtleCount * m_turtles[0].getFeedCost());

	return total;
}



void Zoo::removeAnimalEvent()
{


}

