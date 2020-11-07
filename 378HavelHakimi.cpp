#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//passing vectors by reference for easy use during recursion later on


//function to make it easier when printing int vectors to double check work
void printVec(vector<int> &numList){
    for(int i = 0; i <numList.size(); i++) {
        cout << numList[i] << " ";
    };

    cout << "\n";
};

//Warm Up 1: eliminating 0's
void removeZero(vector<int> &numList) {
    //loop through list and remove zeros
    for(int i = 0; i < numList.size(); i++) {
        if(!numList[i]){
            numList.erase(numList.begin() + i);
            //because we remove an element we need to reset i to check the new value in that position
            i--;
        }
    }
};


//Warm Up 2: descending sort
bool greaterThan(int i, int j) { return i > j; }

void descendingSort(vector<int> &numList) {
    //use sort() with third parameter set to greater() for decending order
    sort(numList.begin(), numList.end(), greaterThan);

}

/*
Warm Up 3: length check
Given a number N and a sequence of answers, return true if N is greater than the number of answers
 (i.e. the length of the sequence), and false if N is less than or equal to the number of answers. 
*/

bool lengthCheck(vector<int> numList, int N) {
    return( N > numList.size());
}

/*
Warm Up 4: front elimination
Given a number N and a sequence in descending order, 
subtract 1 from each of the first N answers in the sequence, and return the result. 
Assumptions:  N is greater than 0, and no greater than the length of the sequence
*/
void frontElimintation(vector<int> &numList, int N) {
    for(int i = 0; i < N; i++){
        numList[i] = numList[i] - 1;
    }
}

bool HavelHakimi(vector<int> &numList){

    //1. Remove all 0's
    removeZero(numList);

    //2. If list is empty now return true STOP (basecase)
    if(!numList.size()){
        return true;
    }

    //3. Sort remaining in decending order
    descendingSort(numList);

    //4. remove first element and call it N
    int N = numList[0];
    numList.erase(numList.begin());

    //5. if N greater than length of updated list return false STOP (basecase)
    if(lengthCheck(numList, N)) {
        return false;
    }

    //6. subtract 1 from each of the first N elements of updated list
    frontElimintation(numList, N);

    //7. repeat with new list (recursive case) 
    HavelHakimi(numList);

};

int main()
{
    vector<int> example1 {16, 9, 9, 15, 9, 7, 9, 11, 17, 11, 4, 9, 12, 14, 14, 12, 17, 0, 3, 16};
    cout << HavelHakimi(example1);
}