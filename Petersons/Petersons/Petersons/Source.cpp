#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>

using std::deque;  // Allows fast insertion and deletion at start and end.
std::mutex mu, cout_mu;  // Protect shared data from being accesed at the same time.
std::condition_variable cond;  // Used to block threads.

const int n = 3;
int inN[n];
int lastArray[n];

void functionAll(void*i)
{
	int number = (int)i;
		while (true) {
			for (int j = 0; j < n - 1; j++) {
				inN[number] = j;
				lastArray[j] = number;
				while (lastArray[j] == number) {
					for (int k = 0; k <= n; k++) {
						if (k != number)
						{
							if (inN[k] >= j) {
							}
							else {
								std::cout << "CALLED = " << +number << std::endl;
								break;
							}
						}
					}

				}
					//and there exists k ≠ i, such that level[k] ≥ ℓ
					//wait
			}
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

	std::thread n1thread(functionAll,(void*)0);
	std::thread n2thread(functionAll,(void*)1);
	std::thread n3thread(functionAll,(void*)2);
	//std::thread n4thread(functionAll, (void*)3);
	//std::thread consumer_thread(function2);

	n1thread.join();
	n2thread.join();
	n3thread.join();
	return 0;
}