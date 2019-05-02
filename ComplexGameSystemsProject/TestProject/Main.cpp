#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int main()
{
	// Creates a vector of threads
	std::vector<std::thread> threads;
	// The mutex will only allow one thread to print at a time
	std::mutex myMutex;

	// Creating 50 threads
	for (int i = 0; i < 50; ++i)
	{
		threads.push_back(std::thread(
			// Using lambda to print the text
			[&myMutex](int i) {
			std::lock_guard<std::mutex> guard(myMutex);
			std::cout << "Hello Thread " << i << "\n";
			std::cout << "I'm here...\n";
			std::cout << "...not there.\n";
		}, i
		));
	}

	// Iterate through the threads
	for (auto& thread : threads)
	{
		thread.join();
	}

	// Pauses the program to view results
	system("pause");

	return 0;
}