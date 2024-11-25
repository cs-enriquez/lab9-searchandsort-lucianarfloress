#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // flexibleType is a templete parameter
void printArray(flexibleType arr[], int length) {}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    if(start > end || start < 0 ) {
        return false;
    }
    for(int i = start; i <= end; i++) {
        if(arr[i] == target) {
            return true;
        }
    }
    return false;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int start = 0;
    int end = n - 1;
    int middle = (start + end) / 2;
    while(start <= end) {
        if (arr[middle] == target) {
            return true;
        }
        else if(arr[middle] < target) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
        middle = (start + end) / 2;
    }
   return false;	
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    // base case: if array size is 0
    if (n < 0) {
        return false;
    }

    int middle = n / 2;

    // base case: we found the target
    if(charray[middle] == target) {
        return true;
    }
    
    // recursive case
    if(target > charray[middle]) { // target is larger than the middle
        char *rightside = &charray[middle + 1];
        int rigthsize = n - middle - 1;
        return binSearchR(target, rightside, rigthsize);
    }
    else {
        return binSearchR(target, charray, middle);
    }
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int one, int two) {
    double tmp = darray[one];
    darray[one] = darray[two];
    darray[two] = tmp;
}

int minFind(double darray[], int length) {
    int minIndex = 0;
    
    for (int i = 1; i < length; i++) {
        if (darray[i] < darray[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void newSort(double darray[], int n) {
    for (int i = 0; i < n - 1; i++) {
        double temp[n-i];
        for(int j = 0; j < n-i; j++) {
            temp[j] = darray[i+j];
        }
        
        int minIndex = minFind(temp, n-i);

        minIndex += i;
        swap(darray, i, minIndex);
    }
}