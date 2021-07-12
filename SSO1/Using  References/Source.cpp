#include <iostream>
#include <cstdlib>
#include <ctime>

void RollTwoDice(int& dice1, int& dice2);

int main()
{
	// Seed the pseudo random number generate here.
	srand((int)time(0));

	// Declare two local integers, representing the two dice.
	int dice1;
	int dice2;

	// Set each dice to hold a value of zero.
	dice1 = 0;
	dice2 = 0;
	
	// Print out the contents of the two dice before the call.
	std::cout << "Before dice 1: " << dice1 << std::endl;
	std::cout << "Before dice 2: " << dice2 << std::endl;

	// Call rollTwoDice with the local dice variables.
	RollTwoDice(dice1, dice2);

	// Print out the contents of the two dice after the call.
	std::cout << "After dice 1: " << dice1 << std::endl;
	std::cout << "After dice 2: " << dice2 << std::endl;
	return 0;
}

void RollTwoDice(int& dice1, int& dice2)
{ 
	dice1 = (rand() % 6) + 1;
	dice2 = (rand() % 6) + 1;
}

