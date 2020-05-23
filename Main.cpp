#include <iostream>
#include <string>
#include <time.h>

std::string ROCK = "Rock";
std::string PAPER = "Paper";
std::string SCISSORS = "Scissors";

class PlayerMove
{
	public:
		std::string moveName;
		std::string winsAgainst;
};



int GetRandomInteger()
{
	return (rand() % 3 + 1);
}

PlayerMove GetResult(int value)
{
	std::string result;

	PlayerMove playerMove;

	switch (value)
	{
		case 1:
			playerMove.moveName = ROCK;
			playerMove.winsAgainst = SCISSORS;
			break;
		case 2:
			playerMove.moveName = PAPER;
			playerMove.winsAgainst = ROCK;
			break;
		case 3:
			playerMove.moveName = SCISSORS;
			playerMove.winsAgainst = PAPER;
			break;
	}

	return playerMove;
}

std::string GetVersusResult(PlayerMove playerOneMove, PlayerMove playerTwoMove)
{
	std::string result = "";

	if (playerOneMove.winsAgainst == playerTwoMove.moveName) 
		result = "Player One Wins!";
	else if (playerTwoMove.winsAgainst == playerOneMove.moveName)
		result = "Player Two Wins!";
	else 
		result = "Draw";

	return result;
}

void CheckValidInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}


int GetPlayerInput()
{
	int input;

	std::cin >> input;

	CheckValidInput();

	while (!(input > 0 && input < 5))
	{
		std::cout << "Inputted wrong values, only 1 to 4 is acceptable" << std::endl;
		std::cin >> input;
		CheckValidInput();
	}

	return input;
}

bool GameRound()
{
	system("CLS");

	std::cout << "=============================================" << std::endl;
	std::cout << "||                                         ||" << std::endl;
	std::cout << "||          Rock, Paper, Scissors          ||" << std::endl;
	std::cout << "||                                         ||" << std::endl;
	std::cout << "|| Input the Number to Play:               ||" << std::endl;
	std::cout << "||   1 -> ROCK                             ||" << std::endl;
	std::cout << "||   2 -> PAPER                            ||" << std::endl;
	std::cout << "||   3 -> SCISSORS                         ||" << std::endl;
	std::cout << "||   4 -> EXIT                             ||" << std::endl;
	std::cout << "||                                         ||" << std::endl;
	std::cout << "=============================================" << std::endl;

	int input = GetPlayerInput();
	
	if (input == 4) return false;

	PlayerMove actionOne = GetResult(input);
	PlayerMove actionTwo = GetResult(GetRandomInteger());

	std::cout << "\n" << actionOne.moveName << " X " << actionTwo.moveName << "\n" << std::endl;
	std::cout << "RESULT : " << GetVersusResult(actionOne, actionTwo) << "\n" << std::endl;

	system("pause");

	return true;
}

int main()
{
	srand(time(NULL));

	bool isPlaying = true;

	while (isPlaying) isPlaying = GameRound();
	
	system("pause");
	return 0;
}