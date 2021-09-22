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
	int maxValue(Node* root);
	bool equals(Node* root1, Node* root2);
	bool validateBinaryTree(Node* root, int min, int max);
	void printNodesAtDistance(int k, Node* root);
	int size(Node* root);
	int countLeaves(Node* root);
	bool contains(Node* root, int value);
	bool areSiblings(Node* root, int val1, int val2);

public:
	Tree();
	void insert(int value);
	bool find(int value);
	int height() { return height(_root); }
	int minValue() { return minValue(_root); }
	int maxValue() { return maxValue(_root); }
	void traversePreOrder() { traversePreOrder(_root); }
	void traverseInOrder() { traverseInOrder(_root); }
	void traversePostOrder() { traversePostOrder(_root); }
	bool equals(Tree tree) { equals(_root, tree._root); }
	bool validateBinaryTree() { return validateBinaryTree(_root, INT_MIN, INT_MAX); }
	void printNodesAtDistance(int k) { printNodesAtDistance(k, _root); }
	int size() { return size(_root); }
	int countLeaves() { return countLeaves(_root); }
	bool contains(int value) { return contains(_root, value); }
	bool areSiblings(int val1, int val2) { return areSiblings(_root, val1, val2); }
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
	if (root->leftChild == NULL) {
		return root->value;
	}

	minValue(root->leftChild);
}

int Tree::maxValue(Node* root) {
	if (root->rightChild == NULL) {
		return root->value;
	}

	maxValue(root->rightChild);
}

bool Tree::equals(Node* root1, Node* root2) {
	if (root1 == NULL && root2 == NULL) {
		return true;
	}

	if (root1 != NULL && root2 != NULL) {
		return root1->value == root2->value
			&& equals(root1->leftChild, root2->leftChild)
			&& equals(root1->rightChild, root2->rightChild);
	}

	return false;
}

bool Tree::validateBinaryTree(Node* root, int min, int max) {
	if (root == NULL) {
		return true;
	}

	if (root->value < min || root->value > max) {
		return false;
	}

	return validateBinaryTree(root->leftChild, min, root->value - 1)
		&& validateBinaryTree(root->rightChild, root->value + 1, max);
}

void Tree::printNodesAtDistance(int k, Node* root) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		std::cout << root->value << std::endl;
	}

	printNodesAtDistance(k - 1, root->leftChild);
	printNodesAtDistance(k - 1, root->rightChild);
}

int Tree::size(Node* root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + size(root->leftChild) + size(root->rightChild);
}

int Tree::countLeaves(Node* root) {
	if (root == NULL) {
		return 0;
	}

	if (root->leftChild == NULL && root->rightChild == NULL) {
		return 1 + countLeaves(root->leftChild) + countLeaves(root->rightChild);
	}

	return  countLeaves(root->leftChild) + countLeaves(root->rightChild);
}

bool Tree::contains(Node* root, int value) {
	if (root == NULL) {
		return false;
	}

	if (root->value == value) {
		return true;
	}

	return contains(root->leftChild, value) || contains(root->rightChild, value);
}

bool Tree::areSiblings(Node* root, int val1, int val2) {
	if (root == NULL) {
		return false;
	}

	if (root->leftChild == NULL || root->rightChild == NULL) {
		return false;
	}

	if (root->leftChild->value == val1 || root->leftChild->value == val2
		&& root->rightChild->value == val2 || root->rightChild->value == val1) {
		return true;
	}

	return areSiblings(root->leftChild, val1, val2) || areSiblings(root->rightChild, val1, val2);
}