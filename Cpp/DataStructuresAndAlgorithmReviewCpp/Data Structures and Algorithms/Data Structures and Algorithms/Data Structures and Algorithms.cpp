#include <iostream>
#include "../../DataStructuresAndAlgorithmReviewCpp/HashTable.h"
#include "../../DataStructuresAndAlgorithmReviewCpp/LinkedList.h"

int main()
{
	HashTable newHashTable(5);

	newHashTable.put(0, "Omar");
	newHashTable.put(1, "Baboo");
	
	std::cout << newHashTable.get(0) << std::endl;
}