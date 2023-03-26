

// Using first ~2-ish minutes for the logic @ https://www.youtube.com/watch?v=4VqmGXwpLqc
/*
    Basic Idea: 
        Recursively break the array down into subarrays until they're singular values
        On the way back up the return, (sorted) merge the resulting subarrays 
*/

#include <iostream>
#include <vector>
#include "someFunctions.cpp"

// Recursive function
std::vector<int> subMerge(std::vector<int> subArray){
    // Base case
    if(subArray.size() == 1)
        return subArray;
    
    // halfIsh allows a pseudo division of the array in case of odd and even values
    int listSize = subArray.size(), halfIsh = listSize / 2;
    std::vector<int> a, b;
    for(int i = 0; i < listSize; i++){
        if(i < halfIsh)
            a.push_back(subArray[i]);
        else
            b.push_back(subArray[i]);
    }
    // Recursive call for both subarrays, then a merge once they're returned
    return mergeVectors(subMerge(a), subMerge(b));
}

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = { 1, 34, 2, 1, 3, 4, 1, 97, -98, -2, 0, 8, 7 };
    numberList = subMerge(numberList);
    printVector(numberList);
    return 0;
}
