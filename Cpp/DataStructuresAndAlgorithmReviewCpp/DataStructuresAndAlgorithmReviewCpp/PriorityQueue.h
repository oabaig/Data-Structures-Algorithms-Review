#pragma once

class PriorityQueue {
private:
	int* _queue;
	int  _size;
	int  _maxSize;
	bool _isEmpty;
	bool _isFull;

public:
	// getters and setters
	bool isEmpty() const { return _isEmpty; }
	bool isFull()  const { return _isFull; }

	// constructors
	PriorityQueue(int size);
};

PriorityQueue::PriorityQueue(int size) {
	 _size = 0;
	 _maxSize = size;
	 _isEmpty = true;
	 _isFull = false;
	
	_queue = new int[size];
}

