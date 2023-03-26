


// Using only the first 5 mins of @ https://www.youtube.com/watch?v=u4IK_D_Jjrs, avoided looking at code
/*
    Basic Idea:
        Get the first value of the vector then place it in a separate vector. 
        Iterating through the first vector, move values that are successively greater
            ex: {5, 1, 10, 4, 13, 8, 11} -> vec1{5, 10, 13}, vec2{1, 4, 8, 11}. 
            11 is greater than five, but the value is successively changed. i.e. greater than 5, greater than 10, greater than 13, etc.
        Recursively perform the same operation on the remainders
            ex: vec2 from above
        Merge results at recursive return manually by greater value. 
            ex: {5, 1, 10, 4, 13, 8, 11} -> vec1(5, 10, 13), vec2(1, 4, 8, 11), vec3(). 1 is smaller than 5, thus...
                                            vec1(5, 10, 13), vec2(4, 8, 11), vec3(1). Next. . .
                                            vec1(5, 10, 13), vec2(8, 11), vec3(1, 4). Then. . .
                                            vec1(10, 13), vec2(8, 11), vec3(1, 4, 5). Etc. . .
*/

#include <iostream>
#include <vector>
#include "someFunctions.cpp"

std::vector<int> mergeVectors(std::vector<int> a, std::vector<int> b){
    std::vector<int> c;
    int ac = 0, am = a.size(), bc = 0, bm = b.size();
    // If both arrays aren't empty, take the smallest value;
    while(ac != am || bc != bm){
        if(ac != am && bc != bm){
            if(a[ac] > b[bc]){
                c.push_back(b[bc]);
                bc++;
            }
            else{
                c.push_back(a[ac]);
                ac++;
            }
        }
        // If either are empty, only take from the non-empty value
        else if(ac != am){
            c.push_back(a[ac]);
            ac++;
        }
        else{
            c.push_back(b[bc]);
            bc++;
        }
    }
    return c;
}

// Recursive call
std::vector<int> strandCall(std::vector<int> inputVector){
    if(inputVector.size() == 1)
        return inputVector;
    std::vector<int> subStrand;
    // Move the first value
    subStrand.push_back(inputVector[0]);
    inputVector.erase(inputVector.begin());
    // If there are more values, successively add greater values
    if(inputVector.size()){
        for(int i = 0; i < inputVector.size(); i++){
            if(inputVector[i] > subStrand[subStrand.size() - 1]){
                subStrand.push_back(inputVector[i]);
                inputVector.erase(inputVector.begin() + i);
                i--;
            }
        }
    }
    // If the initial vector still retains values, recursive call
    // merge than return
    if(inputVector.size())
        return mergeVectors(subStrand, strandCall(inputVector));
    // If initial vector is empty return ordered vector
    return subStrand;
}

int main(){
    std::vector<int> numberList = listOfNumbers();
    // std::vector<int> numberList = {12, 43, 1, 24, -2, -13, 43, 10, 0, 1, 8, -2};
    std::vector<int> sorted = strandCall(numberList);
    printVector(sorted);
    return 0;
}