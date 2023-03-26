


// From the details @ https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
/*
    Basic Idea:
        Starting from the left most value, check if the current value and the next value are the same
        If so, proceed one right. 
        If not, flip values, then move back. 
        If flipping at the beginning, move forward.
        If the end is reached, the sort is completed.
*/

#include <iostream>
#include <vector>
#include "someFunctions.cpp"

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = {1, 3, 2, 34, 2, 13, 0, -2, 1, 3, -324, -1, -7, 0, 4, 2, 3, 4};
    // Compares current numebr to right number, therefore must end before last number.
    int pos = 0, end = numberList.size() - 1;
    while(pos != end){
        // If the current number is larger than the next, swap them;
        if(numberList[pos] > numberList[pos + 1]){
            int temp = numberList[pos];
            numberList[pos] = numberList[pos + 1];
            numberList[pos + 1] = temp;
            // If the swap isn't at the beginning, move back with the changed number
            // This is done in case the number is smaller than the last
            if(pos){
                pos--;
                continue;
            }
        }
        pos++;
    }
    printVector(numberList);
    return 0;
}