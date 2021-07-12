#include <iostream>
#include <cstdlib>
#include <ctime>

void ClearInput();
void PlayTwoPlayer();
void PlayAI();
void RollTwoDice(int *dice);
void AskToRoll(char title[]);
void PrintTwoDiceResults(char title[], int *dice);
int EvaluateTwoDiceWinner(int *dice1, int *dice2);


int main()
{
	// Seed the pseudo random number generate here.
	srand((int)time(0));

	char exit = '\0';
	do
	{
		// Print info
		std::cout << "Simple Dice Game:" << std::endl;
		std::cout << "(1) Player V Player" << std::endl;
		std::cout << "(2) Player V AI" << std::endl;

		// Get play type
		char input = '\0';
		do
		{
			std::cin >> input;
		} while (input != '1' && input != '2');
		// Clean input
		ClearInput();

		// Break into gamemode
		switch (input)
		{
		case '1':
			PlayTwoPlayer();
			break;
		case '2':
			PlayAI();
			break;
		}

		std::cout << "Replay? (q to exit)" << std::endl;
		exit = std::cin.get();
		ClearInput();
	}
	while (exit != 'q');

	return 0;
}

void ClearInput()
{
	// Clear input
	std::cin.clear();
	while (std::cin.get() != '\n')
	{
		continue;
	}
}

void PlayTwoPlayer()
{
	// Declare two local integers, representing the two dice.
	int player1Dice[] = { 0, 0 };
	int player2Dice[] = { 0, 0 };
	RollTwoDice(player1Dice);
	RollTwoDice(player2Dice);

	char player1[] = "Player 1";
	char player2[] = "Player 2";

	AskToRoll(player1);
	PrintTwoDiceResults(player1, player1Dice);

	AskToRoll(player2);
	PrintTwoDiceResults(player2, player2Dice);

	int winner = EvaluateTwoDiceWinner(player1Dice, player2Dice);
	if (winner == 0)
	{
		std::cout << "Draw!" << std::endl;
	}
	else
	{
		std::cout << "Player " << winner << " wins!" << std::endl;
	}
}

void PlayAI()
{
	int diceRoll1[] = { 0, 0 };
	int diceRoll2[] = { 0, 0 };
	RollTwoDice(diceRoll1);
	RollTwoDice(diceRoll2);

	int winner = EvaluateTwoDiceWinner(diceRoll1, diceRoll2);

	int* playerDice = diceRoll1;
	int* aiDice = diceRoll2;
	// AI fixed 70% winrate
	if ((rand() % 10) < 7)
	{
		std::cout << "Ai forced." << std::endl;
		// If player was meant to win
		if (winner = 1)
		{
			// Switch dice
			playerDice = diceRoll2;
			aiDice = diceRoll1;
			winner = 2;
		}
	}


	char player[] = "Player";
	char ai[] = "AI";

	AskToRoll(player);
	PrintTwoDiceResults(player, playerDice);

	std::cout << "AI rolls..." << std::endl;
	PrintTwoDiceResults(ai, aiDice);
	switch(winner)
	{
	case 0:
		std::cout << "Draw!" << std::endl;
		break;
	case 1:
		std::cout << "Player wins!" << std::endl;
		break;
	case 2:
		std::cout << "AI wins!" << std::endl;
		break;
	}
}

void RollTwoDice(int *dice)
{
	dice[0] = (rand() % 6) + 1;
	dice[1] = (rand() % 6) + 1;
}

void AskToRoll(char title[])
{
	std::cout << title << " press enter to roll dice.";
	std::cin.get();
}

void PrintTwoDiceResults(char title[], int *dice)
{
	std::cout << title << " rolled " << dice[0] << "," << dice[1] << std::endl;
}

int EvaluateTwoDiceWinner(int *dice1, int *dice2)
{
	bool pair1 = dice1[0] == dice1[1];
	bool pair2 = dice2[0] == dice2[1];

	int total1 = dice1[0] + dice1[1];
	int total2 = dice2[0] + dice2[1];

	if (pair1 && pair2)
	{
		if (total1 == total2)
		{
			return 0;
		}
	}
	else if (pair1)
	{
		return 1;
	}
	else if (pair2)
	{
		return 2;
	}
	else if (total1 == total2)
	{
		return 0;
	}
	return total1 > total2 ? 1 : 2;
}