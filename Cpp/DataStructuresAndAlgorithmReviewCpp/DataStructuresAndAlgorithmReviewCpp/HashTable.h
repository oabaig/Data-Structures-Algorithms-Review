#pragma once
#include "LinkedList.h"

class HashTable {
private:
	struct Entry {
		int key = 0;
		std::string value;
	};

	LinkedList<Entry>* _table;
	int _maxSize;

	int hash(int key) {
		return key % _maxSize;
	}

public:
	// constructors
	HashTable(int size);

	// methods
	void put(int k, std::string v);
	std::string get(int k);
};

HashTable::HashTable(int size) {
	_maxSize = size;

	_table = new LinkedList<Entry>[_maxSize];
}

void HashTable::put(int k, std::string v) {

	int index = hash(k);

	Entry newEntry;
	newEntry.key = k;
	newEntry.value = v;
	/*
	int i = 0;
	if (!_table[index].isEmpty()) {
		for (i; i < _table[index].getLength(); i++) {
			//Entry retrievedEntry = _table[index].GetKthIndex(i);

			if (retrievedEntry.key == k) {
				break;
			}
		}


	}

	_table[index].addAtIndex(i, newEntry);*/

	while (_table[index].getNext().key != k) {

	}
}

std::string HashTable::get(int k) {
	int index = hash(k);

	Entry getEntry;

	LinkedList<Entry> getList = _table[index];

	//return getList.GetKthIndex(k).value;
}