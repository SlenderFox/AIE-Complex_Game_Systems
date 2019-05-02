#include "CircularQueue.h"

CircularQueue::CircularQueue() : m_readIndex(0), m_writeIndex(0)
{
}

CircularQueue::~CircularQueue()
{
}

bool CircularQueue::push(const int& pItem)
{
	if (isFull())
		return false;

	auto currentIndex = m_writeIndex.load();
	auto nextIndex = increment(currentIndex);
	m_data[currentIndex] = pItem;
	m_writeIndex.store(nextIndex);
	return true;
}

bool CircularQueue::pop(int & pItem)
{
	if (isEmpty())
		return false;

	auto currentIndex = m_readIndex.load();
	pItem = m_data[currentIndex];
	m_readIndex.store(increment(currentIndex));
	return true;
}

bool CircularQueue::isEmpty() const
{
	return m_readIndex.load() == m_writeIndex.load();
}

bool CircularQueue::isFull() const
{
	const auto nextWriteIndex = increment(m_writeIndex.load());
	return (nextWriteIndex == m_readIndex.load());
}

size_t CircularQueue::increment(size_t pIndex) const
{
	return (pIndex + 1) % SIZE;
}