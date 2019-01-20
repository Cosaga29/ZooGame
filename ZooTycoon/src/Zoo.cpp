#include "Zoo.hpp"

bool Zoo::isFull() const
{
	if (tigerCount == 10 || penguinCount == 10 || turtleCount == 10) {
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
	return toReturn;

}

/*
Arrays are initialized with 10 animals each, but when the zoo updates
only the animals up to the count of the animal are updated and used in the 
const calculations


*/
Zoo::Zoo(Player& player) :
	bound_player(player),tigerArraySize(STARTING_CAPACITY), 
	penguinArraySize(STARTING_CAPACITY), 
	turtleArraySize(STARTING_CAPACITY), dayCount(0), 
	tigerCount(0), penguinCount(0), turtleCount(0)
{
	//seed RNG
	srand(time(NULL));


//initialize dynamic arrays for each animal type
	m_tigers = new Tiger[10];
	m_penguins = new Penguin[10];
	m_turtles = new Turtle[10];
}




void Zoo::addTiger(const int &age)
{
	std::cout << "adding tiger... " << tigerCount << "Arraysize: " << tigerArraySize << std::endl;



	if (tigerCount < tigerArraySize - 1) {	//if less tigers than capacity
		tigerCount++;
	}
	else {
		resizeTigerArray(m_tigers, tigerArraySize); //resize
		tigerCount++;
	}
	m_tigers[tigerCount].setAge(age);
}

void Zoo::addPenguin(const int &age)
{
	if (penguinCount < penguinArraySize - 1) {	//if less tigers than capacity
		penguinCount++;
	}
	else {
		resizePenguinArray(m_penguins, penguinArraySize); //resize
		penguinCount++;
	}
	m_penguins[penguinCount].setAge(age);
}

void Zoo::addTurtle(const int &age)
{
	if (turtleCount < turtleArraySize - 1) {	//if less tigers than capacity
		turtleCount++;
	}
	else {
		resizeTurtleArray(m_turtles, turtleArraySize); //resize
		turtleCount++;
	}
	m_turtles[turtleCount].setAge(age);
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



