#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>

using std::deque;  // Allows fast insertion and deletion at start and end.
std::mutex mu, cout_mu;  // Protect shared data from being accesed at the same time.
std::condition_variable cond;  // Used to block threads.

class Buffer
{
public:
	void add(int num) {
		while (true) {
			std::unique_lock<std::mutex> locker(mu);  // locks so remove cant happen.
			cond.wait(locker, [this]() {return buffer_.size() < size_; }); // Thread will go to sleep until woken up
			buffer_.push_back(num);
			std::cout << "ADD" << std::endl;
			locker.unlock();
			cond.notify_all();  // Wakes up all sleeping threads
			return;
		}
	}
	int remove() {
		while (true)
		{
			// Thread will go to sleep if locked
			std::unique_lock<std::mutex> locker(mu);  // Can only lock if add has not locked.
			cond.wait(locker, [this]() {return buffer_.size() > 0; });  // Thread will go to sleep until woken up
			int back = buffer_.back();
			buffer_.pop_back();
			std::cout << "REMOVE" << std::endl;
			locker.unlock();
			cond.notify_all();  // Wakes up all sleeping threads
			return back;
		}
	}
	Buffer() {}
private:
	deque<int> buffer_;
	const unsigned int size_ = 10;
};

class Producer
{
public:
	int num = 0;
	Producer(Buffer* buffer)
	{
		this->buffer_ = buffer;
	}
	void run() {
		while (true) {
			num = num + 1;
			buffer_->add(num);
			cout_mu.lock();  // Lock cout so only one can do it.
			//std::cout << "Produced: " << num << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			cout_mu.unlock();
		}
	}
private:
	Buffer * buffer_;
};

class Consumer
{
public:
	Consumer(Buffer* buffer)
	{
		this->buffer_ = buffer;
	}
	void run() {
		while (true) {
			int num = buffer_->remove();
			cout_mu.lock();  // Lock cout so only one can do it.
			//std::cout << "Consumed: " << num << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			cout_mu.unlock();
		}
	}
private:
	Buffer * buffer_;
};

int main() {
	Buffer b;
	Producer p(&b);
	Consumer c(&b);

	std::thread producer_thread(&Producer::run, &p);
	std::thread consumer_thread(&Consumer::run, &c);
	
	producer_thread.join();
	consumer_thread.join();
	getchar();
	return 0;
}