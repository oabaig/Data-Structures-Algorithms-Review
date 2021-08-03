#pragma once
#include <iostream>

template <typename T>
class LinkedList {
private:
	template <typename T>
	struct Node {
	public:
		T     item;
		Node* next;
	};

	Node<T>* Head;
	Node<T>* Tail;

	int _length;

public:
	// getters and setters
	int getLength() const { return _length; }

	// constructors
	LinkedList();

	// methods
	void addLast(T item);
	void addFirst(T item);
	void deleteLast();
	void deleteFirst();
	void print();
	void reverse();
	bool contains(T item);
	int  indexOf(T item);
	T*   toArray();

};

template <typename T>
LinkedList<T>::LinkedList() {
	_length = 0;

	Head = NULL;
	Tail = NULL;
}

template <typename T>
void LinkedList<T>::addLast(T item) {
	Node<T>* newNode = new Node<T>();
	newNode->item = item;
	newNode->next = NULL;

	if (Head == NULL) {
		Head = newNode;
		Tail = newNode;
	}
	else {
		Tail->next = newNode;
		Tail = Tail->next;
	}

	_length++;
}

template <typename T>
void LinkedList<T>::addFirst(T item) {
	Node<T>* newNode  = new Node<T>();
	Node<T>* currNode = new Node<T>();

	currNode = Head;

	newNode->item = item;
	newNode->next = currNode;

	Head = newNode;

	if (_length == 0) {
		Tail = newNode;
	}

	_length++;
}

template <typename T>
void LinkedList<T>::deleteLast() {
	Node<T>* currNode = new Node<T>();

	currNode = Head;

	while (currNode->next != NULL) {

		if (currNode->next == Tail) {
			break;
		}

		currNode = currNode->next;
	}

	currNode->next = NULL;

	_length--;
}

template <typename T>
void LinkedList<T>::deleteFirst() {
	Head = Head->next;

	_length--;
}

template <typename T>
void LinkedList<T>::print() {
	Node<T>* currNode = new Node<T>();
	currNode = Head;

	int count = 0;

	while (currNode != NULL) {
		std::cout << currNode->item << " ";
		if (count % 5 == 0 && count != 0) {
			std::cout << std::endl;
		}
		currNode = currNode->next;
		count++;
	}
	std::cout << std::endl;
}

template <typename T>
bool LinkedList<T>::contains(T item) {
	Node<T>* currNode = new Node<T>();

	currNode = Head;

	while (currNode != NULL) {
		if (currNode->item == item) {
			return true;
		}

		currNode = currNode->next;
	}

	return false;
}

template <typename T>
int LinkedList<T>::indexOf(T item) {
	Node<T>* currNode = new Node<T>();

	currNode = Head;

	int index = 0;

	while (currNode != NULL) {
		if (currNode->item == item) {
			return index;
		}

		currNode = currNode->next;

		index++;
	}

	return -1;
}

template <typename T>
T* LinkedList<T>::toArray() {
	T* temp = new T[_length];

	Node<T>* currNode = new Node<T>();

	int count = 0;

	while (currNode != NULL) {
		temp[count++] = currNode->item;

		currNode = currNode->next;
	}

	return temp;
}

template <typename T>
void LinkedList<T>::reverse() {
	Node<T>* currNode = new Node<T>();
	Node<T>* prevNode = new Node<T>();
	Node<T>* nextNode = new Node<T>();

	currNode = Head;

	while (currNode != NULL) {

		nextNode = currNode->next;

		currNode->next = prevNode;

		prevNode = currNode;

		currNode = nextNode;
	}
	Tail = Head;

	//std::cout << Tail->item;
	Head = prevNode;
}