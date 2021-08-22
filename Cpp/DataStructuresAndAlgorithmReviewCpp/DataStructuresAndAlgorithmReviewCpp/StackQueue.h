#pragma once
#include "Stack.h"

template <typename T>
class StackQueue {
private:
	Stack<T> _stack1;
	Stack<T> _stack2;

public:
	// getters and setters
	bool isEmpty() const { return _stack1.isEmpty(); }

	// methods
	void enqueue(T item);
	T    dequeue();
	void print();

};

template <typename T>
void StackQueue<T>::enqueue(T item) {
	_stack1.push(item);
}

template <typename T>
T StackQueue<T>::dequeue() {
	while (!_stack1.isEmpty()) {
		_stack2.push(_stack1.pop());
	}

	T item = _stack2.pop();

	return item;
}

template <typename T>
void StackQueue<T>::print() {
	while (!_stack1.isEmpty()) {
		_stack2.push(_stack1.pop());
	}

	_stack2.print();

	while (!_stack2.isEmpty()) {
		_stack1.push(_stack2.pop());
	}
}