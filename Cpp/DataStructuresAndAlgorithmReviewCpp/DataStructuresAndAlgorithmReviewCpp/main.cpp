// DataStructuresAndAlgorithmReviewCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "Array.h"

int main()
{
    Array<int> newArray(3);

    newArray.insert(12423);
    newArray.insert(45356);
    newArray.insert(32466);
    newArray.insert(23);
    newArray.insert(23334);
    newArray.print();

    newArray.removeAt(4);
    newArray.print();

    return 0;
}
