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

public:
	HashTable();
	HashTable(int size);
	void put(int k, std::string v);
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

}