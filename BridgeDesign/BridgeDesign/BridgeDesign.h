#include <iostream>
using namespace std;
class Character
{
public:
	Character() {}
	void Print() { cout << "Printing Character" << endl; }
};
class HandleToCharacter
{
public:
	HandleToCharacter() : character(new Character()) {}
	Character* operator->() { return character; } //overloaded ->
private:
	Character * character;
};
