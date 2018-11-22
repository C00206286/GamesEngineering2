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

	// Test size of 6 passes
	assert(p.testSize(v) == 1);
	for (int i = 0; i < v.size(); i++)
	{
		// Test good numbers pass
		assert(p.testNumber(v[i]) == 1);
	}
	// Test no duplicates pass
	assert(p.testDuplicate(v) == 1);

	v.clear();
	v.push_back(a);
	// Test size of 1 fails
	assert(p.testSize(v) == 0);
	
	v.clear();

	// Test greater than fails
	v.push_back(greater);
	assert(p.testNumber(v[0]) == 0);

	v.clear();

	// Test less than fails
	v.push_back(less);
	assert(p.testNumber(v[0]) == 0);

	v.clear();

	v.push_back(minus);
	// Test minus
	assert(p.testNumber(v[0]) == 0);

	v.clear();

	// Test duplicates fail
	v.push_back(a);
	v.push_back(a);
	assert(p.testDuplicate(v) == 0);

	v.clear();
	// Test empty size fails
	assert(p.testSize(v) == 0);

	cin.get();
}