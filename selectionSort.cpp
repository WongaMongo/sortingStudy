


// Using only the description @ https://www.geeksforgeeks.org/selection-sort/
/*
    Basic Idea:
        (Assuming left to right i.e. sorting smallest to  largest)
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

// Just a printer
void printVector(std::vector<int> numberList){
    std::cout << "[";
    for(int i : numberList)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
};

// Randomly generated vector of ints, limit size 1-100, limit range 0 - 9999;
std::vector<int> listOfNumbers(){
    // std::vector<int> numberList = {8, 4, 1, 92, 2, 48, 408, 48, 13, 308, 17173, 9};
    std::vector<int> numberList;
    int vecSize = rand() % 100 + 1;
    for(int i = 0; i < vecSize; i++)
        numberList.push_back(rand() % 10000);
    printVector(numberList);
    return numberList;
};

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