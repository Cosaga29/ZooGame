#include "Zoo.hpp"



/*
Arrays are initialized with 10 animals each, but when the zoo updates
only the animals up to the count of the animal are updated and used in the
const calculations


*/
Zoo::Zoo(Player& player, std::ostream& pgmOutput) :
	bound_player(player), output(pgmOutput), tigerArraySize(STARTING_CAPACITY),
	penguinArraySize(STARTING_CAPACITY),
	turtleArraySize(STARTING_CAPACITY), dayCount(1),
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



	buildMenus();
	init();

}



/*
Function to return the state of the 'pens' of animals. If any of the pens are full
true is returned.

Return:
	bool - state of the pens of the zoo
*/
bool Zoo::isFull() const
{
	if (tigerCount == tigerArraySize || 
		penguinCount == penguinArraySize || 
		turtleCount == turtleArraySize) {
		return true;
	}
	return false;
}


/*
Takes a current pointer to the tiger array, creates an array twice the size, copies all previous tiger instances over
deletes the old animal array, doubles the size of the passed size variable,
and sets the old pointer to the new double arrayed size
*/
void Zoo::resizeTigerArray(Tiger*& animalArray, int& size) {

	//allocate memory for twice the current array size
	Tiger* arr = new Tiger[size * 2];
	
	//copy old elements to new array
	for (int i = 0; i < tigerCount; i++) {
		arr[i] = animalArray[i];
	}

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

	//copy old elements to new array
	for (int i = 0; i < penguinCount; i++) {
		arr[i] = animalArray[i];
	}

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

	//copy old elements to new array
	for (int i = 0; i < turtleCount; i++) {
		arr[i] = animalArray[i];
	}

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
	//old:(toReturn % (min + max)) - min;
	toReturn = (toReturn % (max - min + 1)) + min;

	return toReturn;

}


void Zoo::addTiger(const int &quantity, int age)
{

	for (int i = 0; i < quantity; i++) {
		if (tigerCount < tigerArraySize - 1) {	//if less tigers than capacity
			tigerCount++;
		}
		else {
			resizeTigerArray(m_tigers, tigerArraySize); //resize
			tigerCount++;
		}
		m_tigers[tigerCount - 1].setAge(age);

	}

	

}

void Zoo::addPenguin(const int &quantity, int age)
{
	
	for (int i = 0; i < quantity; i++) {
		if (penguinCount < penguinArraySize - 1) {	//if less tigers than capacity
			penguinCount++;
		}
		else {
			resizePenguinArray(m_penguins, penguinArraySize); //resize
			penguinCount++;
		}
		m_penguins[penguinCount - 1].setAge(age);
	}

}

void Zoo::addTurtle(const int &quantity, int age)
{

	for (int i = 0; i < quantity; i++) {

		if (turtleCount < turtleArraySize - 1) {	//if less tigers than capacity
			turtleCount++;
		}
		else {
			resizeTurtleArray(m_turtles, turtleArraySize); //resize
			turtleCount++;
		}
		m_turtles[turtleCount - 1].setAge(age);
	}

}

bool Zoo::removeTiger()
{
	if (tigerCount > 0) {
		//generate random number between 0 and (tigerCount - 1)
		int randIndex = generateRandom(0, tigerCount - 1);


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
		int randIndex = generateRandom(0, (penguinCount - 1));


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
		int randIndex = generateRandom(0, (turtleCount - 1));


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
					addTiger(userChoice, 1);
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
					addPenguin(userChoice, 1);
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
					addTurtle(userChoice, 1);
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

	dailyBuyPromptMenu.addPrompt("Would you like to buy an adult animal? (y/n)");

	dailyBuyMenu.addPrompt("Purchase adult Tiger:   ");
	dailyBuyMenu.addPrompt("Purchase adult Penguin: ");
	dailyBuyMenu.addPrompt("Purchase adult Turtle:  ");

	repeatMenu.addPrompt("Continue");
	repeatMenu.addPrompt("Exit");


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
void Zoo::start()
{
	int userChoice = 0;
	bool playerBroke = false;
	char playerBuyChoice;

	double bonus;
	double dailyProfit;

	//check that the player didn't buy too many animals at the start:
	if (!playerCanBuy(getFeedCost())) {
		output << "GAME OVER: You cannot afford feed cost of " << getFeedCost()
			<< " with current balance of " << bound_player.getBalance();
		return;
	}


	while ((userChoice != repeatMenu.getExitCode())) {	//game loop, exit only if player gives exit code
		bonus = 0.0;			//reset profit variables for the day
		dailyProfit = 0.0;

		printAnimalContents();

		//format and display player balance and day Number
		output << "\n\n\n";
		output << "[DAY: " << dayCount << "]";
		output << "\tYour Balance: " << bound_player.getBalance() << "\n" << std::endl;
		

		//age all the animals
		ageAnimals();

		//user needs to pay feeding cost (calculate feed cost)
		bound_player.buy(getFeedCost());
		output << "You paid " << getFeedCost() << " in feeding costs.\n" << std::endl;


		//get a random number for a random event
		switch (static_cast<EVENT_TYPE>(generateRandom(0, 3))) {

		case SICK_EVENT:
			removeAnimalEvent();
			break;


		case ATTENDANCE_EVENT:
			bonus = attendanceBoomEvent();
			break;


		case BABY_EVENT:
			animalBirthEvent();
			break;


		case NOTHING:
			output << "[Day] " << dayCount << std::endl;
			output << "\t";
			output << "Nothing eventful happened today." << std::endl;
			break;


		}

		//calculate profit for the day
		dailyProfit = (m_tigers[0].getPayoffValue() * tigerCount) + bonus
			+ (m_penguins[0].getPayoffValue() * penguinCount)
			+ (m_turtles[0].getPayoffValue() * turtleCount);


		//display profit for the user
		output << std::endl;
		output << "Profits for day: " << dayCount << "\n"
			<< "\tFrom Tigers:   " << (m_tigers[0].getPayoffValue() * tigerCount) << "\tBonus: " << (bonus) << "\n"
			<< "\tFrom Penguins: " << (m_penguins[0].getPayoffValue() * penguinCount) << "\n"
			<< "\tFrom Turtles:  " << (m_turtles[0].getPayoffValue() * turtleCount) << "\n"
			<< "\tTOTAL:         " << (dailyProfit) << "\n\n" << std::endl;;

		bound_player.deposit(dailyProfit);

		//ask player if they would like to buy an adult animal, if they do, ask for animal type
		//add the ADULT animal to the zoo and subtract cost

		playerBuyChoice = validateInputYN(dailyBuyPromptMenu.getPrompt(1));

		if (playerBuyChoice == 'y') {
			switch (dailyBuyMenu.getUserChoice()) {
			case 1:
				output << "\nYou have purchased an adult tiger!\n " << std::endl;
				addTiger(1, ADULT);
				bound_player.buy(m_tigers[0].getCost());
				break;

			case 2:
				output << "\nYou have purchased an adult penguin!\n " << std::endl;
				addPenguin(1, ADULT);
				bound_player.buy(m_penguins[0].getCost());
				break;

			case 3:
				output << "\nYou have purchased an adult turtle!\n " << std::endl;
				addTurtle(1, ADULT);
				bound_player.buy(m_turtles[0].getCost());
				break;
			}

		}


		//check if player has enough money to pay for feeding cost for next round
		if (!playerCanBuy(getFeedCost())) {
			playerBroke = true;
			output << "GAME OVER: You cannot afford feed cost of " << (getFeedCost())
				<< " with current balance of " << bound_player.getBalance();
			return;
		}
		else {
			//check to see if the player would like to exit
			repeatMenu.displayMessage("Would you like to continue playing? ");
			userChoice = repeatMenu.getUserChoice();
		}
	}

	dayCount++;
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
	switch (generateRandom(1, 3)) {
		output << "[Day: " << (dayCount) << "]"  "   (Event)" << std::endl;
		output << "\t";

	//tiger death
	case 1:
		if (removeTiger()) {
			output << "A sudden sickness has affected the tigers, one has died. " << std::endl;
		}
		else {
			output << "You hear rumors of tigers being affected by a sickness, but you don't own any!" << std::endl;
		}
		break;

	//penguin death
	case 2:
		if (removePenguin()) {
			output << "A sudden sickness has affected the penguins, one has died. " << std::endl;
		}
		else {
			output << "You hear rumors of penguins being affected by a sickness, but you don't own any!" << std::endl;
		}
		break;

	//turtle death
	case 3:
		if (removeTurtle()) {
			output << "A sudden sickness has affected the turtle, one has died. " << std::endl;
		}
		else {
			output << "You hear rumors of turtles being affected by a sickness, but you don't own any!" << std::endl;
		}
		break;
	}

	output << std::endl;

}

double Zoo::attendanceBoomEvent()
{

	output << "[Day: " << (dayCount) << "]"  "   (Event)" << std::endl;
	output << "\t";

	double bonusReturn = 0.0;
	int tigerBonus;

	//calculate the bonus money from an attendence boom
	if (tigerCount == 0) {
		output << "A boom in attendance occured at your zoo, but the guests wanted to see tigers." << std::endl;
	}
	else {
		output << "A boom in attendance occured at your zoo, each tiger produced extra money!" << std::endl;
		for (int i = 0; i < tigerCount; i++) {
			//for each tiger, generate a random bonus
			tigerBonus = generateRandom(250, 500);
			bonusReturn += tigerBonus;
		}
	}

	output << "\tBonus Money: " << (bonusReturn) << std::endl;

	output << std::endl;

	return bonusReturn;
}



void Zoo::animalBirthEvent()
{
	output << "[Day: " << (dayCount) << "]"  "   (Event)"<< std::endl;
	output << "\t";
	
	int zooAdultState = zooHasAdult();

	if (zooAdultState == -1) {
		output << "You hear tales of other zoos having a population boom today..." << std::endl;
		return;
	}


	//pick an animal type to have a baby
	ANIMAL_TYPE animalType = static_cast<ANIMAL_TYPE>(generateRandom(0, 2));


	//check that the zoo contains an adult animal of that type:
	if (hasAdult(animalType)) {
		//generate baby event from randomly picked animal adult
		switch (animalType) {
		case TIGER:
			output << "A tiger has given birth to " << (m_tigers[0].getNumberOfBabies()) << " babie(s)!" << std::endl;
			addTiger(m_tigers[0].getNumberOfBabies(), BABY);
			break;

		case PENGUIN:
			output << "A penguin has given birth to " << (m_penguins[0].getNumberOfBabies()) << " babie(s)!" << std::endl;
			addPenguin(m_penguins[0].getNumberOfBabies(), BABY);
			break;

		case TURTLE:
			output << "A turtle has given birth to " << (m_turtles[0].getNumberOfBabies()) << " babie(s)!" << std::endl;
			addTurtle(m_turtles[0].getNumberOfBabies(), BABY);
			break;
		}



	}
	else {
		//generate a baby event from the guarenteed adult from zooAdultState
		switch (zooAdultState) {
		case TIGER:
			output << "A tiger has given birth to " << (m_tigers[0].getNumberOfBabies()) << " babies!" << std::endl;
			addTiger(m_tigers[0].getNumberOfBabies(), BABY);
			break;

		case PENGUIN:
			output << "A penguin has given birth to " << (m_penguins[0].getNumberOfBabies()) << " babies!" << std::endl;
			addPenguin(m_penguins[0].getNumberOfBabies(), BABY);
			break;

		case TURTLE:
			output << "A turtle has given birth to " << (m_turtles[0].getNumberOfBabies()) << " babies!" << std::endl;
			addTurtle(m_turtles[0].getNumberOfBabies(), BABY);
			break;
		}
	}

	output << std::endl;
}

bool Zoo::hasAdult(ANIMAL_TYPE animalType)
{
	switch (animalType) {
	case TIGER:
		for (int i = 0; i < tigerCount; i++) {
			if (m_tigers[i].getAge() >= ADULT) {
				return true;
			}
		}
		return false;

	case PENGUIN:
		for (int i = 0; i < tigerCount; i++) {
			if (m_penguins[i].getAge() >= ADULT) {
				return true;
			}
		}
		return false;

	case TURTLE:
		for (int i = 0; i < tigerCount; i++) {
			if (m_turtles[i].getAge() >= ADULT) {
				return true;
			}
		}
		return false;
	}

	return false;
}

int Zoo::zooHasAdult()
{
	if (hasAdult(TIGER)) {
		return TIGER;
	}
	else if (hasAdult(PENGUIN)){
		return PENGUIN;
	}
	else if (hasAdult(TURTLE)) {
		return TURTLE;
	}
	else {
		return -1;
	}
}

