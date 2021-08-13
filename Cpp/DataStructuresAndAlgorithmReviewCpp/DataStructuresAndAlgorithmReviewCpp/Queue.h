#pragma once
#include "LinkedList.h"

template <typename T>
class Queue {
private:
	LinkedList<T> _queue;
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
	void print();


};

template <typename T>
Queue<T>::Queue() {
	_front = NULL;
	_back = NULL;
	_isEmpty = true;
}

template <typename T>
void Queue<T>::enqueue(T item){
	_queue.addLast(item);

	if (_front == NULL) {
		_front = _queue.getFirst();
	}

	_isEmpty = false;
}

template <typename T>
T Queue<T>::dequeue() {
	if (_isEmpty) {
		std::cout << "Queue is empty";
		return NULL;
	}

	T item = _queue.getFirst()->item;
	_queue.deleteFirst();

	_front = _queue.getFirst();

	if (_front == NULL) {
		_isEmpty = true;
	}
	
	return item;
}

template <typename T>
T Queue<T>::peek() {
	if (_isEmpty) {
		std::cout << "Queue is empty";
		return NULL;
	}

	return _queue.getFirst()->item;
}

template <typename T>
void Queue<T>::print() {
	_queue.print();
}