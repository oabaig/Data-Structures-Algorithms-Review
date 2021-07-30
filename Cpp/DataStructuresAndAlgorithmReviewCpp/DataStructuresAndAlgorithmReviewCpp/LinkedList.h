#pragma once
#include <iostream>

template <typename T>
struct Node {
public:
	T     item;
	Node* next;
};

template <typename T>
class LinkedList {
private:
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
	bool contains(T item);
	int  indexOf(T item);

};

template <typename T>
LinkedList<T>::LinkedList() {
	_length = 0;

	Head = new Node<T>();
	Tail = new Node<T>();
}

template <typename T>
void LinkedList<T>::addLast(T item) {
	Node<T>* newNode;
	newNode = new Node<T>();
	newNode->item = item;
	newNode->next = NULL;

	Node<T>* currNode = new Node<T>();

	currNode = Head;

	while (currNode->next != NULL) {
		currNode = currNode->next;
	}

	currNode->next = newNode;

	if (_length == 0) {
		Head = newNode;
		Tail = newNode;
	}
	else{
		Tail = newNode;
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
}

template <typename T>
void LinkedList<T>::deleteFirst() {
	Head = Head->next;
}

template <typename T>
void LinkedList<T>::print() {
	Node<T>* currNode = new Node<T>();
	currNode = Head;

	while (currNode != NULL) {
		std::cout << currNode->item << std::endl;
		currNode = currNode->next;
	}
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