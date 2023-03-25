


// Using only the description @ https://www.geeksforgeeks.org/selection-sort/
/*
    Basic Idea:
        (Assuming left to right i.e. sorting smallest to largest)
        Starting at leftmost unsorted value
        Run through the entire list and pick the smallest value
        Swap leftmost unsorted value with smallest value (can include the leftmost value itself)
        Swap values, not overwrite.
        rinse and repeat

    What I'm Thinking:
        Pretty much just that. 
*/

#include <iostream>
#include <vector>
#include <time.h>
#include "someFunctions.cpp"

int main(){
    srand(time(0));
    std::vector<int> numberList = listOfNumbers();

    int idx, listSize = numberList.size();

    // Main loop
    for(int i = 0; i < listSize; i++){
        // Includes the index being replaced since it can contain the smallest value
        idx = i;
        for(int j = i; j < listSize; j++){
            // If an index has a smaller value, store index 
            // Can't replace immediately since there can be an even smaller value
            if(numberList[j] < numberList[idx]){
                idx = j;
            }
        }
        // End of the inner loop means the smallest value has been found
        // Replaces here
        int temp = numberList[i];
        numberList[i] = numberList[idx];
        numberList[idx] = temp;
    }
    printVector(numberList);
    return 0;
}