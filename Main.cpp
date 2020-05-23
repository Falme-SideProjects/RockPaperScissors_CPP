#include <iostream>
#include <string>
#include <time.h>

std::string ROCK = "Rock";
std::string PAPER = "Paper";
std::string SCISSORS = "Scissors";

int GetRandomInteger()
{
	return (rand() % 3 + 1);
}

std::string GetRandomResult()
{
	std::string result;

	switch (GetRandomInteger())
	{
		case 1:
			result = ROCK;
			break;
		case 2:
			result = PAPER;
			break;
		case 3:
			result = SCISSORS;
			break;
	}

	return result;
}

std::string GetVersusResult(std::string playerOneMove, std::string playerTwoMove)
{
	std::string result = "";

	if (playerOneMove == playerTwoMove) result = "Draw";
	else result = "Still Not Defined";

	return result;
}

int main()
{
	srand(time(NULL));

	std::cout << "=============================================" << std::endl;
	std::cout << "||          Rock, Paper, Scissors          ||" << std::endl;
	std::cout << "=============================================" << std::endl;

	std::string actionOne = GetRandomResult();
	std::string actionTwo = GetRandomResult();

	std::cout << actionOne << std::endl;
	std::cout << actionTwo << std::endl;
	std::cout << GetVersusResult(actionOne, actionTwo) << std::endl;

	system("pause");
	return 0;
}