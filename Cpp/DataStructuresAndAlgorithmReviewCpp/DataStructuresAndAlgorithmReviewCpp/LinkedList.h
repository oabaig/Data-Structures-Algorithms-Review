#pragma once

template <typename T>
struct Node {
public:
	T item;
	Node* next;
};

template <typename T>
class LinkedList {
private:
	Node* Head;
	Node* Tail;

	int _length;

public:
	LinkedList();


};

template <typename T>
LinkedList<T>::LinkedList() {
	_length = 0;
}