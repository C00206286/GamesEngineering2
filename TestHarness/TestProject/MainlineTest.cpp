#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"

using namespace std;

int main()
{
	Production p;

	int a = 10;

	cout << p.someMethod(a) << endl;
	assert(p.someMethod(a) == 0);
	assert(p.someMethod(a) == 1);
	cin.get();
}