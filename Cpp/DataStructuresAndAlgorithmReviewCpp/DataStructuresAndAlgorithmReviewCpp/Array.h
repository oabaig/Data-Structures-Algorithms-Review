#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T*  _array;
	int _size;
	int _maxSize;

public:
	Array(int length);
	void insert(T item);
	void print();
	void removeAt(int index);
};

template <typename T>
Array<T>::Array(int length) {
	_array = new T[length];
	_size = 0;
	_maxSize = length;
}

template <typename T>
void Array<T>::insert(T item) {
	if (_size == _maxSize) {
		std::wcout << "Array limit reached. Cannot add item." << std::endl;
		return;
	}
	_array[_size++] = item;
}

template <typename T>
void Array<T>::print() {
	for (int i = 0; i < _size; i++) {
		std::cout << _array[i] << " ";
		if (i % 5 == 0 && i != 0) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";
}

template <typename T>
void Array<T>::removeAt(int index) {
	for (int i = index; i < _size; i++) {
		_array[i] = array[i + 1];
	}
}