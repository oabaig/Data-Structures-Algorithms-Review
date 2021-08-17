#pragma once
#include <iostream>

const int MAXSIZE = 100;

template <typename T>
class ArrayQueue {
private:
	bool _isEmpty;
	bool _isFull;
	int  _front;
	int  _back;
	T*   _queue;

public:
	// constructors
	ArrayQueue();

	// destructors
	~ArrayQueue();

	// methods
	bool enqueue(T item);
	bool dequeue();
	bool peek();
	bool isEmpty();
	bool isFull();
	void print();
};

// constructors
template <typename T>
ArrayQueue<T>::ArrayQueue() {
	_front = 0;
	_back = 0;
	_isEmpty = true;
	_isFull = false;

	_queue = new T[MAXSIZE];
}

// destructor
template <typename T>
ArrayQueue<T>::~ArrayQueue() {
	delete _queue;
}

// methods
template <typename T>
void ArrayQueue<T>::print() {
	for (int i = _front; i < _back; i++) {
		if (i % 10 == 0 && i != _front) {
			std::cout << std::endl << " " << _queue[i] << ", ";
			continue;
		}

		if (i == _front) {
			std::cout << "[" << _queue[i] << ", ";
			continue;
		}

		if (i == _back - 1) {
			std::cout << _queue[i] << "]" << std::endl;
			continue;
		}

		std::cout << _queue[i] << ", ";
	}
}

template <typename T>
bool ArrayQueue<T>::enqueue(T item) {
	if (!_isFull) {
		_isEmpty = false;

		_queue[_back] = item;

		_back++;

		return true;
	}

	return false;
}

