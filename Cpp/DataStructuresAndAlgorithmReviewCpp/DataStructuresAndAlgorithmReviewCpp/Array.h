#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
	T*  _array;
	int _size;
	int _maxSize;

public:
	// constructors
	Array(int length);
	Array(const Array& arr);
	
	// getters
	int size()    const { return _size; }
	int maxSize() const { return _maxSize; }

	// operator overloads
	T& operator[](int index);	

	// methods
	void insert(T item);
	void print();
	void removeAt(int index);
	void resize();
	int  indexOf(T item);
	T*   toArray();
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

// operator overloads
template <typename T>
T& Array<T>::operator[](int index) {
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
	if (arr.size() > _size) {
		int greaterSize = arr.size();
		int lesserSize = _size;

		Array<T> tempArray(lesserSize);

		int count = 0;

		for (int i = 0; i < greaterSize; i++) {
			for (int j = 0; j < lesserSize; j++) {
				if (arr[i] == _array[j]) {
					tempArray[count] = arr[i];
				}
			}
		}

		// ---test
		tempArray.print();

		return tempArray.toArray();
	}
	else {
		int greaterSize = _size;
		int lesserSize = arr.size();

		Array<T> tempArray(lesserSize);

		int count = 0;

		for (int i = 0; i < greaterSize; i++) {
			for (int j = 0; j < lesserSize; j++) {
				if (_array[i] == arr[j]) {
					tempArray[count] = _array[i];
				}
			}
		}

		// ---test
		tempArray.print();

		return tempArray.toArray();
	}
}

template <typename T>
T* Array<T>::toArray() {
	return _array;
}