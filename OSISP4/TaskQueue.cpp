#include "TaskQueue.h"

TaskQueue::TaskQueue() {
	_empty = true;
	_closed = false;
	InitializeCriticalSection(&criticalSection);
}
TaskQueue::~TaskQueue() {
	
	DeleteCriticalSection(&criticalSection);
}

void TaskQueue::Add(Task* task) {
	EnterCriticalSection(&criticalSection);
	_tasks.push_back(task);

	_empty = false; 
	LeaveCriticalSection(&criticalSection);

}
void TaskQueue::Close() {
	_closed = true;
}

Task* TaskQueue::Extract() {

	while (_empty==true && _closed==false) {}
	EnterCriticalSection(&criticalSection);

	if (_closed && !_tasks.size()) {
		LeaveCriticalSection(&criticalSection);
		return nullptr;
	}

	Task* task = _tasks.front(); //first element of _tasks vector
	_tasks.erase(_tasks.begin()); //delete task

	if (!_tasks.size()) {
		_empty = true;
	}
	LeaveCriticalSection(&criticalSection);

	return task;
}