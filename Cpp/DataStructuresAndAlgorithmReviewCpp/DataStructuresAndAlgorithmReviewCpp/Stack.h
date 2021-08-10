#pragma once
#include "LinkedList.h"

template <typename T>
class Stack {
private:
	LinkedList<T> _stack;
	Node<T>* _top;

public:
	// methods
	void print();
	void push(T item);
	T    pop();
	T    top();

};

// methods
template <typename T>
void Stack<T>::push(T item) {
	_stack.addFirst(item);
	_top = _stack.getFirst();
}

template <typename T>
T Stack<T>::pop() {
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
	return _top->item;
}