#include "MultiThreadApplication.h"

MultiThreadApplication::MultiThreadApplication() : m_waitingToWrite(false)
{
	m_renderThread = std::thread([&]
	{
		while (true)
		{
			if (!m_waitingToWrite)
			{
				m_renderDataMutex.lock();
				m_culling.Execute();
				m_renderer.Execute();
				m_renderDataMutex.unlock();
			}
		}
	});

	m_pathFindingThread = std::thread([&]
	{
		while (true)
		{
			m_pathfinding.Execute();
		}
	});
}

MultiThreadApplication::~MultiThreadApplication()
{
}

void MultiThreadApplication::Tick()
{
	// Game mechanics
	m_input.Execute();
	m_gameLogic.Execute();
	m_physics.Execute();

	// Update render data
	m_waitingToWrite = true;
	m_renderDataMutex.lock();

	m_waitingToWrite = false;
	m_updateRenderData.Execute();
	m_renderDataMutex.unlock();
}