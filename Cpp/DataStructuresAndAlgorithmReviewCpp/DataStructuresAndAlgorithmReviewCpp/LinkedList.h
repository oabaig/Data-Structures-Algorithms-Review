#pragma once
#include <iostream>
#include <list>

template <typename T>
struct Node {
public:
	T     item;
	Node* next = NULL;
};

template <typename T>
struct IndexNode {
public:
	T   item;
	int index = 0;
};

template <typename T>
class LinkedList {
private:
	Node<T>* Head;
	Node<T>* Tail;

	Node<T>* Ptr;

	int _length;

public:
	// getters and setters
	Node<T>* getFirst() const { return Head; }
	Node<T>* getLast()  const { return Tail; }
	int      getLength()const { return _length; }
	int      isEmpty()  const { return _length == 0 ? true : false; }

	// constructors
	LinkedList();

	// destructors
	~LinkedList();

	// methods
	void addLast(T item);
	void addFirst(T item);
	void addAtIndex(int k, T item);
	void deleteLast();
	void deleteFirst();
	void print();
	void printMiddle();
	void reverse();
	void addAtIndex(int k, T item);
	bool contains(T item);
	bool hasLoop();
	int  indexOf(T item);
	T*   toArray();
	T    getKthFromTheEnd(int k);
	T    getNext();

};

// constructors
template <typename T>
LinkedList<T>::LinkedList() {
	_length = 0;

	Head = NULL;
	Tail = NULL;

	Ptr = Head;
}

// destructors
template <typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* currNode = Head;

	while (currNode != NULL) {
		Node<T>* nextNode = currNode->next;

		delete currNode;

		currNode = nextNode;
	}

	Head = NULL;
	Tail = NULL;
}

// methods
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
	Node<T>* currNode = Head;

	newNode->item = item;
	newNode->next = currNode;

	Head = newNode;

	if (Tail == NULL) {
		Tail = newNode;
	}

	_length++;
}

template <typename T>
void LinkedList<T>::deleteLast() {
	Node<T>* currNode = Head;

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
	Node<T>* currNode = Head;

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
	Node<T>* currNode = Head;

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
	Node<T>* currNode = Head;

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

	Node<T>* currNode = Head;

	int count = 0;

	while (currNode != NULL) {
		temp[count++] = currNode->item;

		currNode = currNode->next;
	}

	return temp;
}

template <typename T>
void LinkedList<T>::reverse() {
	Node<T>* currNode = NULL;
	Node<T>* prevNode = NULL;
	Node<T>* nextNode = NULL;

	currNode = Head;

	while (currNode != NULL) {

		nextNode = currNode->next;

		currNode->next = prevNode;

		prevNode = currNode;

		currNode = nextNode;
	}
	Tail = Head;
	Tail->next = NULL;
	Head = prevNode;
}

template<typename T>
T LinkedList<T>::getKthFromTheEnd(int k) {
	Node<T>* leadingNode = Head;
	Node<T>* trailingNode = Head;

	int count = 0;
	while (count < k) {
		if (leadingNode->next == NULL) {
			return NULL;
		}
		
		leadingNode = leadingNode->next;
		count++;
	}

	while (leadingNode->next != NULL) {
		leadingNode = leadingNode->next;
		trailingNode = trailingNode->next;
	}

	return trailingNode->item;	
}

template <typename T>
void LinkedList<T>::printMiddle() {

	if (Head == NULL) {
		return;
	}

	Node<T>* leadingNode  = Head;
	Node<T>* trailingNode = Head;

	int count = 1;
	while (leadingNode->next != NULL) {
		leadingNode = leadingNode->next;

		count++;
	}

	int count2 = 1;
	while (count2 < count / 2) {
		trailingNode = trailingNode->next;
		count2++;
	}

	if (count % 2 == 0) {
		std::cout << trailingNode->item << " ";

		trailingNode = trailingNode->next;

		std::cout << trailingNode->item << std::endl;
	}
	else {
		std::cout << trailingNode->item << std::endl;
	}
}

template <typename T>
bool LinkedList<T>::hasLoop() {
	Node<T>* slowPointer = Head;
	Node<T>* fastPointer = Head;

	while (fastPointer->next != NULL || slowPointer->next != NULL) {
		fastPointer = fastPointer->next;
		if (fastPointer == NULL) {
			return false;
		}
		fastPointer = fastPointer->next;
		slowPointer = slowPointer->next;

		if (fastPointer == slowPointer) {
			return true;
		}
	}

	return false;
}

template <typename T>
T LinkedList<T>::getNext() {
	if (Ptr == NULL) {
		Ptr = Head;

		if (Ptr != NULL) {
			return Ptr->item;
		}
		else {
			return NULL;
		}
	}

	if (Ptr->next != NULL) {
		Ptr = Ptr->next;
		return Ptr->item;
	}
}

template <typename T>
void LinkedList<T>::addAtIndex(int k, T item) {
	Node<T>* currNode = Head;
	Node<T>* prevNode = currNode;;
	for (int i = 0; i < k; i++) {
		prevNode = currNode;
		currNode = currNode->next;
	}

	Node<T>* newNode = new Node<T>;
	newNode->item = item;
	if (currNode == NULL) {
		addLast(item);
	}
	else {
		prevNode->next = newNode;
		newNode->next = currNode;
	}

	newNode->next = (currNode->next == NULL ? NULL : currNode->next);

	currNode->next = newNode;
}