#include "Production.h"
#include <iostream>
#include <vector>

bool addedNumber = false;
bool winner = false;
bool invalid = false;

int main()
{
	while (winner == false)
	{
		int a, b, c, d, e, f;
		Production p;
		std::vector<int> guess;
		std::cout << "Please input your first number" << std::endl;
		std::cin >> a;
		guess.push_back(a);
		std::cout << "Please input your second number" << std::endl;
		std::cin >> b;
		guess.push_back(b);
		std::cout << "Please input your third number" << std::endl;
		std::cin >> c;
		guess.push_back(c);
		std::cout << "Please input your fourth number" << std::endl;
		std::cin >> d;
		guess.push_back(d);
		std::cout << "Please input your fifth number" << std::endl;
		std::cin >> e;
		guess.push_back(e);
		std::cout << "Please input your sixth number" << std::endl;
		std::cin >> f;
		guess.push_back(f);

		if (p.testSize(guess.size()) != 6)
		{
			std::cout << "You did not enter enough numbers" << std::endl;
		}
		for (int i = 0; i < guess.size(); i++)
		{
			if (p.testNumber(guess[i]) == 0)
			{
				std::cout << "You entered an invaled number " << +guess[i] << std::endl;
			}
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
				}
			}
		}
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
