#pragma once
#include <mutex>
#include "Task.h"
#include "windows.h"



class TaskQueue
{
public:
	TaskQueue();
	~TaskQueue();
	void Add(Task* task);
	void Close();
	Task* Extract();

private:
	std::vector<Task*> _tasks;
	CRITICAL_SECTION criticalSection;
	bool _closed;
	bool _empty;
};

