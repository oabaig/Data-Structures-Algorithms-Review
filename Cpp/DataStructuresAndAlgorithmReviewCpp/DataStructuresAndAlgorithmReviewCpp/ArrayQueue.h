#pragma once
#include <iostream>

const int MAXSIZE = 100;

template <typename T>
class ArrayQueue {
private:
	T* _queue;
	int _front;
	int _back;

public:
	// constructors
	ArrayQueue();

	// destructors
	~ArrayQueue();

	// methods
};

// constructors
template <typename T>
ArrayQueue<T>::ArrayQueue() {
	_front = 0;
	_back = 0;

	_queue = new T[MAXSIZE];
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
	delete _queue;
}