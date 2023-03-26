


// Using instructions @ https://www.geeksforgeeks.org/pancake-sorting/
/*
    Following are the detailed steps. Let given array be arr[] and size of array be n. 
    Start from current size equal to n and reduce current size by one while it’s greater than 1. Let the current size be curr_size. 
    Do following for every curr_size
    Find index of the maximum element in arr[0 to curr_szie-1]. Let the index be ‘mi’
    Call flip(arr, mi)
    Call flip(arr, curr_size – 1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "someFunctions.cpp"

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = {1, 3, 2, 13, 2, 234, -2, 3, 43, -2342, 0, 432, -1, -11, 0};
    // Main loop
    // Largest values are placed first, so it's a decrementing loop
    for(int curSize = numberList.size(); curSize > 1; curSize--){
        int max = 0;
        // Find the largest number in the "unsorted" left section of the array
        for(int i = 1; i < curSize; i++){
            if(numberList[i] > numberList[max])
                max = i;
        }
        // Flip the unsorted array limited at the max value, thereby placing the max value on top
        std::reverse(numberList.begin(), numberList.begin() + max + 1);
        // The unsorted section of the array is flipped, thus bringing the max on top to the left
        std::reverse(numberList.begin(), numberList.begin() + curSize);
    }
    printVector(numberList);
}