#include <iostream>
#include "../../DataStructuresAndAlgorithmReviewCpp/HashTable.h"
#include "../../DataStructuresAndAlgorithmReviewCpp/LinkedList.h"

int main()
{
	HashTable newHashTable(5);

	newHashTable.put(0, "Omar");
	newHashTable.put(1, "Baboo");
	newHashTable.put(5, "Amnah");
	
	std::cout << newHashTable.get(0) << std::endl;
	std::cout << newHashTable.get(1) << std::endl;
	std::cout << newHashTable.get(5) << std::endl;
}