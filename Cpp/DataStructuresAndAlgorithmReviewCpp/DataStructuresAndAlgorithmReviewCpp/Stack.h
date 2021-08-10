#pragma once
#include "LinkedList.h"

template <typename T>
class Stack {
private:
	LinkedList<T> _stack;

public:
	// constructors
	Stack();

	// destructors
	~Stack();
};

// constructors
template <typename T>
Stack<T>::Stack() {
	_stack = new LinkedList<T>();
}