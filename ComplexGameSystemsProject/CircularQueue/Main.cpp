#include <iostream>
#include <thread>
#include "CircularQueue.h"

const int MAX_VALUE = 50;

void push_function(CircularQueue& pCircularQueue)
{
	int count = 0;
	while (count <= MAX_VALUE)
	{
		if (pCircularQueue.push(count))
		{
			std::cout << "Pushed " << count << " to the queue" << std::endl;
			count++;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void pop_function(CircularQueue& pCircularQueue)
{
	int value = 0;
	while (value <= MAX_VALUE)
	{
		if (pCircularQueue.pop(value))
		{
			std::cout << "Popped " << value << " from the queue" << std::endl;
			value++;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main()
{
	CircularQueue m_circularQueue;

	auto publisher = std::thread(push_function, std::ref(m_circularQueue));
	auto consumer = std::thread(pop_function, std::ref(m_circularQueue));

	publisher.join();
	consumer.join();

	system("pause");
	return 0;
}