

// Using only the description @ https://www.geeksforgeeks.org/insertion-sort/
/*
    Basic Idea:
        Incrementing from left to right;
        When a value is found to be less than the value directly to the left, switch places
        Follow the changed value and while it continues to be less than the left value, switch places
        Repeat until it's no longer less than it's left value, thus becoming sorted
        Repeat by index until the end

*/

#include <iostream>
#include <vector>
#include "someFunctions.cpp"

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = {3, 2, 30, 4302, 19, -2, -432, 0};
    int listSize = numberList.size();
    // Main loop
    for(int i = 1; i < listSize; i++){
        // Unsure of effect, but did this in reverse
        // Instead of checking the right of value, I'm checking the left
        if(numberList[i] < numberList[i - 1]){
            // If less than, we follow a second index until the value is sorted
            int place = i;
            // While it's less than, move it further down the list unless its at the very first spot
            while(numberList[place] < numberList[place - 1] && place > 0){
                int temp = numberList[place];
                numberList[place] = numberList[place - 1];
                numberList[place - 1] = temp;
                place--;
            }
        } 
    }
    printVector(numberList);
    return 0;
}