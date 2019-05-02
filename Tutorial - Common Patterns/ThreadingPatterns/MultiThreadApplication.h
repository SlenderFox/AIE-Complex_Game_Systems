#pragma once
#include "BaseApplication.h"
#include <mutex>
#include <atomic>

class MultiThreadApplication : public BaseApplication
{
public:
	MultiThreadApplication();
	~MultiThreadApplication();

	void Tick() override;

private:
	std::thread m_renderThread;
	std::mutex m_renderDataMutex;
	std::atomic<bool> m_waitingToWrite;
	std::thread m_pathFindingThread;
};