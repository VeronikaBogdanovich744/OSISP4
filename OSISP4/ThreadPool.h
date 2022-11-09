#pragma once
#include "TaskQueue.h"
#include <thread>
#include "Task.h"
class ThreadPool
{
public:
	ThreadPool(int threads);
	~ThreadPool();

	void AddTask(Task* task);
	Task* GetReadyTask();

private:
	void ThreadFunc();
	std::vector<std::thread*> _threads;
	TaskQueue _taskQueue;
	TaskQueue _readyTaskQueue;
};

