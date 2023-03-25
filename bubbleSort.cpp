


#include <iostream>
#include <vector>
#include "someFunctions.cpp"

// Using only the description @ https://www.geeksforgeeks.org/bubble-sort/
/*
    Basic Idea:
        Just keep on iterating through, changing values that are greater
        Done when no more swaps are available. 

*/

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = {5, 1, 6, 435, 34, 1, -23, -1};
    int listSize = numberList.size();

    bool swaps = true;
    // Main Loop
    while(swaps){
        swaps = false;
        for(int i = 0; i < listSize - 1; i++){
            // If there's a need to swap we have to repeat
            if(numberList[i] > numberList[i + 1]){
                // swapping values
                int temp = numberList[i];
                numberList[i] = numberList[i + 1];
                numberList[i + 1] = temp;
                swaps = true;
            }
        }
    }
    printVector(numberList);
    return 0;
}