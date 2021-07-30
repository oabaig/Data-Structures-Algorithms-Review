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
	LinkedList();
	void addLast(T item);
	void print();

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
void LinkedList<T>::print() {
	Node<T>* currNode = new Node<T>();
	currNode = Head;

	while (currNode != NULL) {
		std::cout << currNode->item << std::endl;
		currNode = currNode->next;
	}
}