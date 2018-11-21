#include <iostream>
#include <assert.h>
#include <vector>

#include "../ProductionProject/Production.h"

using namespace std;

int main()
{
	Production p;

	int a = 10;
	int b = 20;
	int c = 11;
	int d = 12;
	int e = 13;
	int f = 14;

	int greater = 47;
	int less = 0;
	int minus = -47;
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(f);

	cout << p.someMethod(v[1]) << endl;
	assert(p.someMethod(v[1]) == 0);
	assert(p.testSize(v.size()) == 6);
	for (int i = 0; i < v.size(); i++)
	{
		assert(p.testNumber(v[i]) == 1);
	}
	assert(p.testDuplicate(v) == 1);

	v.clear();
	v.push_back(a);
	assert(p.testSize(v.size()) == 1);
	
	v.clear();

	v.push_back(greater);
	assert(p.testNumber(v[0]) == 0);

	v.clear();

	v.push_back(less);
	assert(p.testNumber(v[0]) == 0);

	v.clear();

	v.push_back(minus);
	assert(p.testNumber(v[0]) == 0);

	v.clear();

	v.push_back(a);
	v.push_back(a);
	assert(p.testDuplicate(v) == 0);

	cin.get();
}