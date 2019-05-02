#pragma once
#include <atomic>

class CircularQueue
{
public:
	/*
		@brief The default constructor
	*/
	CircularQueue();

	/*
		@brief The default destructor
	*/
	~CircularQueue();

	/*
		@brief Adds an item to the circular queue
		@param The item you want to add
		@return Whether the function was successful
	*/
	bool push(const int& pItem);

	/*
		@brief Removes an item to the circular queue
		@param The item you want to remove
		@return Whether the function was successful
	*/
	bool pop(int& pItem);

	/*
		@brief Returns whether or not the queue is empty
		@return Whether or not the queue is empty
	*/
	bool isEmpty() const;

	/*
		@brief Returns whether or not the queue is full
		@return Whether or not the queue is full
	*/
	bool isFull() const;

private:
	/*
		@brief 
		@param
		@return
	*/
	size_t increment(size_t pIndex) const;

	std::atomic<size_t> m_readIndex;		// The index that the read thread looks at
	std::atomic<size_t> m_writeIndex;		// The index that the write thread looks at

	static const int		SIZE = 11;			// The size of the circular array
	int							m_data[SIZE];		// The data to be used by the program
};