


// Using only the description @ https://www.youtube.com/watch?v=gZNOM_yMdSQ and https://www.geeksforgeeks.org/cycle-sort/
/*
    Basic Idea:
        Incrementing from left to right;
        At the index of the incremental value "n" (i.e. starts at 0, next increment 1, etc) count, from n + 1, all lesser values. 
            ex: {3, 2, 1} n = 0. 3 > 2 |count++| 3 > 1 |count++|
        Store the value at the counted index 
            ex: {3, 2, 1} count == 2. Thus val = vector[count] which is 1. So val = 1;
        Replace (not swap) value at the counted value. 
            ex: {3, 2, 1} vector[count] -> {3, 2, 3}
        If the counted index isn't the same as the incremental value, repeat process. 
        When the values are equivalent, replace 
            ex: {3, 2, 3} 1 is not > 3, 1 is not > 2, 1 is not > 3. count = 0. vector[count] = 1 -> {1, 2, 3};
        Repeat process until incremental value == vector size. 

*/




#include <iostream>
#include <vector>
#include "someFunctions.cpp"

// Counts the cycle, i.e. from the cycleIdx (i.e. unsorted section)
// where values are less than current stored value
int cycle(std::vector<int> numberList, int cycleIdx, int val){
    int temp = 0;
    for(int i = cycleIdx + 1; i < numberList.size(); i++){
        if(numberList[i] < val)
            temp++;
    }
    return temp;
}

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = {100, 20, 4, 4, 23, 18, 1500, 12018, 0};
    int cycleIdx = 0, pos = 0, val, vecSize = numberList.size();
    // Main loop
    while(cycleIdx < vecSize){
        // First value is the cycleIdx
        val = numberList[cycleIdx];
        pos = cycle(numberList, cycleIdx, val);
        // While there are values less than the current value, repeat
        while(pos){
            // Stores new value and replaces value at index
            int temp = numberList[pos + cycleIdx];
            numberList[pos + cycleIdx] = val;
            val = temp;
            // If there are values less than the new value, i.e. cycle > 0, repeat.
            pos = cycle(numberList, cycleIdx, val);
        }
        // If there are no values less than the new value, the index is the new place for the value
        numberList[cycleIdx] = val;
        // Repeat for the next cycle in case there are unordered values greater than the current value.
        cycleIdx++;
    }
    printVector(numberList);
    return 0;
}