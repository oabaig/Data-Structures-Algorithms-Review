#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
	int _size;
	int _maxSize;
	T* _array;

public:
	// constructors
	Array(int length);
	Array(const Array& arr);

	// destructor
	~Array();
	
	// getters
	int size()    const { return _size; }
	int maxSize() const { return _maxSize; }

	// operator overloads
	T operator[](int index);

	// methods
	void insert(T item);
	void insertAt(T item, int index);
	void print();
	void removeAt(int index);
	void resize();
	void reverse();
	int  indexOf(T item);
	T*   getArray();
	T*   intersect(Array arr);
	T    getAt(int index);

};

// constructors
template <typename T>
Array<T>::Array(int length) {
	_array = new T[length];
	_size = 0;
	_maxSize = length;
}

template <typename T>
Array<T>::Array(const Array& arr) {
	_size = arr._size;
	_maxSize = arr._maxSize;
	
	_array = new T[_size];

	for (int i = 0; i < _size; i++) {
		_array[i] = arr._array[i];
	}
}

// destructors
template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
T Array<T>::operator[](int index) {
	return _array[index];
}

// methods
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
	for (int i = index; i < _size - 1; i++) {
		_array[i] = _array[i + 1];
	}
	_size--;
}

template <typename T>
T Array<T>::getAt(int index) {
	return _array[index];
}

template <typename T>
int Array<T>::indexOf(T item) {
	for (int i = 0; i < _size; i++) {
		if (_array[i] == item) {
			return i;
		}
	}
	
	return -1;
}

template<typename T>
void Array<T>::resize() {
	T* temp = new T[_size];
	for (int i = 0; i < _size; i++) {
		temp[i] = _array[i];
	}

	delete _array;
	_array = new T[_size];
	for (int i = 0; i < _size; i++) {
		_array[i] = temp[i];
	}
	_maxSize = _size;
}

template <typename T>
T* Array<T>::intersect(Array arr) {
	int arrSize = (_size > arr.size()) ? arr.size() : _size;

	Array<T> tempArray(arrSize);

	for (int i = 0; i < _size; i++) {
		std::cout << _array[i] << " i" << std::endl;
		for (int j = 0; j < arr.size(); j++) {
			if (_array[i] == arr[j]) {
				tempArray.insert(_array[i]);
			}
		}
	}

	return tempArray.getArray();
}

template <typename T>
T* Array<T>::getArray() {
	return _array;
}

template <typename T>
void Array<T>::reverse() {

	Array<T> tempArray(_size);

	for (int i = _size - 1; i >= 0; i--) {
		tempArray.insert(_array[i]);
	}

	delete[] _array;

	_array = new T[_maxSize];
	for (int i = 0; i < _size; i++) {
		_array[i] = tempArray[i];
	}
}

template <typename T>
void Array<T>::insertAt(T item, int index) {
	Array<T> tempArray(++_size);
	_maxSize++;

	for (int i = 0; i < _size; i++) {
		if (i == index) {
			tempArray.insert(item);
		}

		tempArray.insert(_array[i]);
	}

	delete[] _array;
	_array = new T[_maxSize];
	for (int i = 0; i < _size; i++) {
		_array[i] = tempArray[i];
	}
}