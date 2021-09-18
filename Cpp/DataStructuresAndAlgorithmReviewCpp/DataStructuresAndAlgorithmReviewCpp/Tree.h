#pragma once
#include <stdio.h>

class Tree {
private:
	struct Node {
		int value = 0;
		Node* leftChild = NULL;
		Node* rightChild = NULL;
	};

	Node* root;

public:
	Tree();
	void insert(int value);
};

Tree::Tree() {
	root = NULL;
}

void Tree::insert(int value) {
	Node* newNode = new Node();
	newNode->value = value;

	if (root == NULL) {
		root = newNode;
		return;
	}
	
	Node* current = root;
	Node* prevNode = NULL;

	while (current != NULL) {
		prevNode = current;
		if (value > current->value) {
			current = current->rightChild;
		}
		else {
			current = current->leftChild;
		}
	}

	current = newNode;
	if (value > prevNode->value) {
		prevNode->rightChild = current;
	}
	else {
		prevNode->leftChild = current;
	}
}