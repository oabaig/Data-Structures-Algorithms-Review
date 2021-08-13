#pragma once
#include "LinkedList.h"

template <typename T>
class Queue {
private:
	LinkedList _queue;
	Node<T>* _front;
	Node<T>* _back;
	bool     _isEmpty;

public:
	// getters and setters
	bool isEmpty() const { return _isEmpty; }

	// constructors
	Queue();

	// methods
	void enqueue(T item);
	T    dequeue();
	T    peek();


};

template <typename T>
Queue<T>::Queue() {
	_front = NULL;
	_back = NULL;
	_isEmpty = true;
}

