#include "Production.h"
#include <iostream>
#include <vector>
#include <ctime>

bool addedNumber = false;
bool winner = false;
bool invalid = false;

int main()
{
	srand(time(NULL));

	while (winner == false)
	{
		int guessNumber;
		Production p;
		std::vector<int> guess;
		for (int i = 0; i < 6; i++)
		{
			std::cout << "Please input a number" << std::endl;
			std::cin >> guessNumber;
			if (p.testNumber(guessNumber) == 1)
			{
				guess.push_back(guessNumber);
			}
			else
			{
				std::cout << "Your input is invalid" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;
			}
		}

		if (p.testSize(guess) == 0)
		{
			std::cout << "You did not enter enough numbers" << std::endl;
		}
		if (p.testDuplicate(guess) == 0)
		{
			std::cout << "You entered duplicate values" << std::endl;
		}

		std::vector<int> lottoNumbers;
		for (int i = 0; i < 6; i++)
		{
			addedNumber = false;
			while (addedNumber == false)
			{
				int randNum = rand() % 46 + 1;
				lottoNumbers.push_back(randNum);
				if (p.testDuplicate(lottoNumbers) == 1)
				{
					addedNumber = true;
				}
				else
				{
					lottoNumbers.pop_back();
					addedNumber = false;
					std::cout << "Duplicate" << std::endl;
				}
			}
		}

		std::sort(lottoNumbers.begin(), lottoNumbers.end()); 
		std::sort(guess.begin(), guess.end());

		std::cout << "The lotto numbers are = ";
		for (auto i = lottoNumbers.begin(); i != lottoNumbers.end(); ++i)
		{
			std::cout << *i << ' ';
		}
		std::cout << std::endl;
		std::cout << "Your numbers are = ";
		for (auto i = guess.begin(); i != guess.end(); ++i)
		{
			std::cout << *i << ' ';
		}
		std::cout << std::endl;
		if (lottoNumbers == guess)
		{
			std::cout << "WINNER WINNER CHICKEN DINNER!!!!!!" << std::endl;
			winner = true;
		}
		else
		{
			std::cout << "Sorry you have not won, please try again :)" << std::endl;
			guess.clear();
			lottoNumbers.clear();
		}
	}
	system("PAUSE");
	return 0;
}
