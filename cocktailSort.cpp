


// Using only the description @ https://www.geeksforgeeks.org/cocktail-sort/
/*
    Basic Idea:
        Essentially bubble sort but forwards and backwards
        Just keep on iterating through, changing values that are greater
        When reaching the end, do the same but in reverse, switching values that are lesser
        At each end the greatest/least values will be placed each time so there should be a decrement/increment.
            ex: (5, 4, 1, -1, 2, 0) -> {4, 1, -1, 2, 0, 5) 
                The five is the greatest value, thus the values left of it must be less
            ex: starting before max begins at val "0" (4, 1, -1, 2, 0, 5) -> {-1, 4, 1, 0, 2, 5} 
                The negative one is the least value, thus the values right of it must be more.
        Done when no more swaps are available in either direction. 

*/

#include <iostream>
#include <vector>
#include "someFunctions.cpp"

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = {2, 45, 1 , -2, 34, 24, 124, -3, -98, 0};
    bool swaps = true;
    // Sorted iterators
    int leftSorted = 0, rightSorted = numberList.size();
    // Main loop
    while(swaps){
        swaps = false;
        // Brings greatest value to the left
        for(int i = leftSorted; i < rightSorted - 1; i++){
            if(numberList[i] > numberList[i + 1]){
                int temp = numberList[i];
                numberList[i] = numberList[i + 1];
                numberList[i + 1] = temp;
                swaps = true;
            }
        }
        rightSorted--;
        // Brings smallest value to the right
        for(int j = rightSorted; j > leftSorted; j--){
            if(numberList[j] < numberList[j - 1]){
                int temp = numberList[j];
                numberList[j] = numberList[j - 1];
                numberList[j - 1] = temp;
                swaps = true;
            }
        }
        leftSorted++;
    }
    printVector(numberList);
    return 0;
}