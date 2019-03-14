#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <vector>
#include <chrono>
#include <condition_variable>


const int n = 4;
int inN[n];
int lastArray[n];

std::vector<std::thread> threads;

void functionAll(void*i)
{
	int number = (int)i;
	while (true) {
		for (int j = 1; j <= n; j++) {
			inN[number] = j;
			lastArray[j] = number;

			for (int k = 1; k <= n; k++) {
				if (k != number)
				{
					while (inN[k] >= inN[number] && lastArray[j] == number);
				}
			}
		}

		//and there exists k ≠ i, such that level[k] ≥ ℓ
		//wait
		std::cout << "CALLED = " << +number << std::endl;
		inN[number] = 0;
	}
	}


bool in1 = false;
bool in2 = false;
int last = 1;

void function1() {
	while (true) {
		inN[0] = 1;
		//lastArray[0] = ;
		while (in2 == true && last == 1)
		{
			break;
		}
		std::cout << "CALLED 1" << std::endl;
		in1 = false;
	}
}
void function2() {
	while (true) {
		in2 = true;
		last = 2;
		while (in1 == true && last == 2)
		{
			break;
		}
		std::cout << "CALLED 2" << std::endl;
		in2 = false;
	}
}

int main() {

	for (int i = 1; i <= n; i++)
	{
		threads.push_back(std::thread(functionAll, (void*)i));
	}
	for (int i = 0; i <= n; i++)
	{
		threads[i].join();
	}
	return 0;
}