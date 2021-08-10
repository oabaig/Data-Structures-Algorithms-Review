#pragma once
#include "LinkedList.h"

template <typename T>
class Stack {
private:
	LinkedList<T> _stack;
	Node<T>* _top;
	bool     _isEmpty;

public:
	// getters and setters
	bool isEmpty() const { return _isEmpty; }

	// constructors
	Stack();

	// methods
	void print();
	void push(T item);
	T    pop();
	T    top();

};

// constructors
template<typename T>
Stack<T>::Stack() {
	_top = new Node<T>;
	_isEmpty = true;
}

// methods
template <typename T>
void Stack<T>::push(T item) {
	_stack.addFirst(item);
	_top = _stack.getFirst();
	_isEmpty = false;
}

template <typename T>
T Stack<T>::pop() {
	if (_isEmpty) {
		std::cout << "Stack is empty." << std::endl;
		return NULL;
	}

	_stack.deleteFirst();
	T item = _top->item;
	_top = _stack.getFirst();

	return item;
}

template <typename T>
void Stack<T>::print() {
	_stack.print();
}

template <typename T>
T Stack<T>::top() {
	if (_isEmpty) {
		std::cout << "Stack is empty." << std::endl;
		return NULL;
	}

	return _top->item;
}