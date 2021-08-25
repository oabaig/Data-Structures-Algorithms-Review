#pragma once
#include <iostream>

class PriorityQueue {
private:
	int* _queue;
	int  _size;
	int  _maxSize;
	bool _isEmpty;
	bool _isFull;

	int _front;
	int _back;

public:
	// getters and setters
	bool isEmpty() const { return _isEmpty; }
	bool isFull()  const { return _isFull; }

	// constructors
	PriorityQueue(int size);

	// methods
	bool enqueue(int item);
	int  dequeue();
	void print();
};

PriorityQueue::PriorityQueue(int size) {
	_size = 0;
	_maxSize = size;
	_isEmpty = true;
	_isFull = false;

	_front = 0;
	_back = 0;
	
	_queue = new int[size];
}

bool PriorityQueue::enqueue(int item) {
	if (_isFull) {
		return false;
	}
	_isEmpty = false;

	int i;
	for (i = _size - 1; i >= 0; i--) {
		if (_queue[i] > item) {
			_queue[i + 1] = _queue[i];
		}
		else {
			break;
		}
	}

	_queue[i + 1] = item;

	_size++;
	if (_size == _maxSize) {
		_isFull = true;
	}
}

int PriorityQueue::dequeue() {
	if (_isEmpty) {
		return NULL;
	}
	_isFull = false;
	_size--;

	if (_size == 0) {
		_isEmpty = true;
	}

	return _queue[_size];
}

void PriorityQueue::print() {
	int index = _front;
	for (int i = 0; i < _size; i++) {
		std::cout << _queue[index] << " ";
		index = (index + 1) % _maxSize;
	}
	std::cout << std::endl;
}