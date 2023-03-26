


#include <iostream>
#include <vector>
#include <time.h>


// Just a printer
void printVector(std::vector<int> numberList){
    std::cout << "[ ";
    for(int i : numberList)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
};

// Randomly generated vector of ints, limit size 1-100, limit range 0 - 9999;
std::vector<int> listOfNumbers(){
    srand(time(0));
    // std::vector<int> numberList = {8, 4, 1, 92, 2, 48, 408, 48, 13, 308, 17173, 9};
    std::vector<int> numberList;
    int vecSize = rand() % 100 + 1;
    for(int i = 0; i < vecSize; i++)
        numberList.push_back(rand() % 10000);
    printVector(numberList);
    return numberList;
};

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