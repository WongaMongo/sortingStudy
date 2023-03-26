


// Using the info of the images @ https://www.geeksforgeeks.org/quick-sort/
/*
    Basic idea:
        Take the leftmost value of the array as a pivot. 
        Sort the values into two arrays depending on if they're greater or less than the pivot
        Recursively call the function on the two subarrays until the value is single, then return
        Upon return merge the arrays. Left of the pivot, the pivot, then right.
            ex:
                { 2, 1, 5, 5, 8, -12, -1, -23, 34, 123412, 2, 90, 6 }
                p = 6
                a = {2, 1, 5, 5, -12, -1, -23, 2}   b = {8, 34, 123412, 90}

                p = 2
                {2, 1, 5, 5, -12, -1, -23}
                a = {1, -12, -1, -23}   b = {5, 5}

                p = -23
                {1, -12, -1}
                a = {} b = {1, -12, -1}
            In this example equivalent values, such as 2 and 5, are placed into the pivot array. 

*/


#include <iostream>
#include <vector>
#include "someFunctions.cpp"

// Recursive function
std::vector<int> pivot(std::vector<int> array){
    // Single values
    if(array.size() == 1)
        return array;
    
    int listSize = array.size(), pivotPoint = array[listSize - 1];
    // a = lesser values, b = greater values, c = equivalent values
    std::vector<int> a, b, c;
    for(int i = 0; i < listSize; i++){
        if(array[i] < pivotPoint)
            a.push_back(array[i]);
        else if(array[i] > pivotPoint)
            b.push_back(array[i]);
        else
            c.push_back(pivotPoint);
    }
    if(a.size())
        a = pivot(a);
    if(b.size())
        b = pivot(b);
    // As a are lesser values, append pivot to a, then b to a;
    a.insert(a.end(), c.begin(), c.end());
    a.insert(a.end(), b.begin(), b.end());
    return a;
};


int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = { 2, 1, 5, 5, 8, -12, -1, -23, 34, 123412, 2, 90, 6 };
    numberList = pivot(numberList);
    printVector(numberList);
}
