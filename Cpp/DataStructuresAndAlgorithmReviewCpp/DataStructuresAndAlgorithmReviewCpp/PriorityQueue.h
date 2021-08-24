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
	if (!_isFull) {

		int index = _front;
		bool foundLoc = false;
		for (int i = 0; i < _size; i++) {
			if (item < _queue[index]) {
				int tempArraySize = _size - (index);

				int* tempArray = new int[tempArraySize];
				int tempIndex = index;
				for (int k = 0; k < tempArraySize; k++) {
					tempArray[k] = _queue[tempIndex];

					tempIndex = (tempIndex + 1) % _maxSize;
				}

				_queue[index] = item;

				int newIndex = (index + 1) % _maxSize;
				for (int j = 0; j < tempArraySize; j++) {
					_queue[newIndex] = tempArray[j];

					newIndex = (newIndex + 1) % _maxSize;
				}

				_back = (_back + 1) % _maxSize;
				foundLoc = true;
				break;
			}
			index = (index + 1) % _maxSize;
		}

		if (!foundLoc) {
			_queue[_back] = item;
			_back = (_back + 1) % _maxSize;
		}

		_size++;
		if (_size == _maxSize) {
			_isFull = true;
		}
	}
	return false;
}

void PriorityQueue::print() {
	int index = _front;
	for (int i = 0; i < _size; i++) {
		std::cout << _queue[index] << " ";
		index = (index + 1) % _maxSize;
	}
	std::cout << std::endl;
}