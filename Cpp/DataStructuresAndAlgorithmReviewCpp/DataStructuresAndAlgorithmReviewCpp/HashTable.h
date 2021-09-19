#pragma once
#include <list>

using namespace std;

class HashTable {
private:
	struct Entry {
	public:
		int key = 0;
		string value;
	};

	list<Entry>* _table;
	int _maxSize;
	int _size;

	int hash(int k) { return k % _maxSize; }

public:
	HashTable();
	HashTable(int size);
	string get(int k);
	void put(int k, string v);
	void remove(int k);
};

HashTable::HashTable(){
	_maxSize = 5;
	_size = 0;
	_table = new list<Entry>[_maxSize];
}

HashTable::HashTable(int size) {
	_maxSize = size;
	_size = 0;
	_table = new list<Entry>[_maxSize];
}

void HashTable::put(int k, string v) {
	int index = hash(k);

	Entry newEntry;
	newEntry.key = k;
	newEntry.value = v;

	list<Entry>::iterator i;
	for (i = _table[index].begin(); i != _table[index].end(); i++) {
		if (i->key == k) {
			_table[index].erase(i);
		}
	}
	_table[index].insert(i, newEntry);
}

string HashTable::get(int k) {
	int index = hash(k);

	list<Entry>::iterator i;
	for (i = _table[index].begin(); i != _table[index].end(); i++) {
		if (i->key == k) {
			return i->value;
		}
	}
}

void HashTable::remove(int k) {
	int index = hash(k);
	
	list<Entry>::iterator i;
	for (i = _table[index].begin(); i != _table[index].end(); i++) {
		if (i->key == k) {
			_table[index].erase(i);
		}
	}
}