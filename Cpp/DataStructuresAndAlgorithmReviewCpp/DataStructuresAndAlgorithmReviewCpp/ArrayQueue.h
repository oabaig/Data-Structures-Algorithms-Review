#pragma once
#include <iostream>

template <typename T>
class ArrayQueue {
private:
	bool _isEmpty;
	bool _isFull;
	int  _front;
	int  _back; 
	int  _maxSize;
	int  _count;
	T*   _queue;

public:
	// getters and setters
	int getLength() const { return _count; }
	
	// constructors
	ArrayQueue(int size);

	// destructors
	~ArrayQueue();

	// methods
	bool enqueue(T item);
	T dequeue();
	bool peek();
	bool isEmpty();
	bool isFull();
	void print();
};

// constructors
template <typename T>
ArrayQueue<T>::ArrayQueue(int size) {
	_front = 0;
	_back = 0;
	_isEmpty = true;
	_isFull = false;
	_maxSize = size;
	_count = 0;

	_queue = new T[_maxSize];
}

// destructor
template <typename T>
ArrayQueue<T>::~ArrayQueue() {
	delete _queue;
}

// methods
template <typename T>
void ArrayQueue<T>::print() {
	int start = _front;
	for (int i = 0; i < _count; i++) {
		std::cout << _queue[start] << " ";
		start = (start + 1) % _maxSize;
	}
	std::cout << std::endl;
}

template <typename T>
bool ArrayQueue<T>::enqueue(T item) {
	if (!_isFull) {

		_queue[_back] = item;
		_back = (_back + 1) % _maxSize;
		_count++;


		if (_count == _maxSize) {
			_isFull = true;
		}

		_isEmpty = false;


		return true;
	}

	return false;
}

template <typename T>
T ArrayQueue<T>::dequeue() {
	if (!_isEmpty) {
		_isFull = false;

		T item = _queue[_front];

		_front = (_front + 1) % _maxSize;

		_count--;

		if (_count == 0) {
			_isEmpty = true;
		}

		return item;
	}

	return NULL;
}