#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>

class Tree {
private:
	struct Node {
		int value = 0;
		Node* leftChild = NULL;
		Node* rightChild = NULL;
	};

	Node* _root;

	void traversePreOrder(Node* root);
	void traverseInOrder(Node* root);
	void traversePostOrder(Node* root);
	int height(Node* root);
	int minValue(Node* root);

public:
	Tree();
	void insert(int value);
	bool find(int value);
	int height() { return height(_root); }
	int minValue() { return minValue(_root); }
	void traversePreOrder() { traversePreOrder(_root); }
	void traverseInOrder() { traverseInOrder(_root); }
	void traversePostOrder() { traversePostOrder(_root); }
	
};

Tree::Tree() {
	_root = NULL;
}

void Tree::insert(int value) {
	Node* newNode = new Node();
	newNode->value = value;

	if (_root == NULL) {
		_root = newNode;
		return;
	}
	
	Node* current = _root;
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

bool Tree::find(int value) {
	Node* currentNode = _root;

	while (currentNode != NULL) {
		if (currentNode->value == value) {
			return true;
		}

		value > currentNode->value ?
			currentNode = currentNode->rightChild : currentNode = currentNode->leftChild;
	}

	return false;

}

void Tree::traversePreOrder(Node* root) {
	if (root == NULL) {
		return;
	}

	std::cout << root->value << std::endl;
	traversePreOrder(root->leftChild);
	traversePreOrder(root->rightChild);
}

void Tree::traverseInOrder(Node* root) {
	if (root == NULL) {
		return;
	}

	traverseInOrder(root->leftChild);
	std::cout << root->value << std::endl;
	traversePreOrder(root->rightChild);
}

void Tree::traversePostOrder(Node* root) {
	if (root == NULL) {
		return;
	}

	traversePostOrder(root->leftChild);
	traversePostOrder(root->rightChild);
	std::cout << root->value << std::endl;
}

int Tree::height(Node* root) {
	if (root == NULL) {
		return -1;
	}

	if (root->leftChild == NULL && root->rightChild == NULL) {
		return 0;
	}

	return 1 + std::max(
		height(root->leftChild), 
		height(root->rightChild));
}

int Tree::minValue(Node* root) {
	return std::min(minValue(root->leftChild), minValue(root->rightChild));
}