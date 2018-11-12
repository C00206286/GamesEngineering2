#include "Production.h"

int Production::someMethod(int a)
{
	return a - a;
}
int Production::testSize(int size)
{
	return size;
}
int Production::testNumber(int number)
{
	if (number > 0 && number <= 46)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Production::testDuplicate(std::vector<int> vector)
{
	int index = 0;
	std::vector<int>::iterator it;
	it = std::unique(vector.begin(), vector.end());
	index = std::distance(vector.begin(), it);
	if (index == vector.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}