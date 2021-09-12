#pragma once
#include <list>

class HashTable {
private:
	struct Entry {
	public:
		int key = 0;
		std::string value;
	};

	std::list<Entry>* _table;
	int _maxSize;
	int _size;

	int hash(int k) { return k % _maxSize; }

public:
	HashTable();
	HashTable(int size);
	void put(int k, std::string v);
	std::string get(int k);
};

HashTable::HashTable(){
	_maxSize = 5;
	_size = 0;
	_table = new std::list<Entry>[_maxSize];
}

HashTable::HashTable(int size) {
	_maxSize = size;
	_size = 0;
	_table = new std::list<Entry>[_maxSize];
}

void HashTable::put(int k, std::string v) {
	int index = hash(k);

	Entry newEntry;
	newEntry.key = k;
	newEntry.value = v;

	std::list<Entry>::iterator i;
	for (i = _table[index].begin(); i != _table[index].end(); i++) {
		if (i->key == k) {
			_table[index].erase(i);
		}
	}
	_table[index].insert(i, newEntry);

}

std::string HashTable::get(int k) {
	int index = hash(k);

	std::list<Entry>::iterator i;
	for (i = _table[index].begin(); i != _table[index].end(); i++) {
		if (i->key == k) {
			return i->value;
		}
	}

	return NULL;
}