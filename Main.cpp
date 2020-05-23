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

PlayerMove GetRandomResult()
{
	std::string result;

	PlayerMove playerMove;

	switch (GetRandomInteger())
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

int main()
{
	srand(time(NULL));

	std::cout << "=============================================" << std::endl;
	std::cout << "||                                         ||" << std::endl;
	std::cout << "||          Rock, Paper, Scissors          ||" << std::endl;
	std::cout << "||                                         ||" << std::endl;
	std::cout << "=============================================" << std::endl;

	PlayerMove actionOne = GetRandomResult();
	PlayerMove actionTwo = GetRandomResult();

	std::cout << "\n" << actionOne.moveName << " X " << actionTwo.moveName << "\n" << std::endl;
	std::cout << "RESULT : " << GetVersusResult(actionOne, actionTwo) << std::endl;

	system("pause");
	return 0;
}