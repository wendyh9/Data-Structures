// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
using namespace std;

// binary search -> array must be sorted
// recursive function

int binarySearchR(string* A, int array_size, string k, int left, int right, int sorted){
    // each time we search, we want to start at the middle of the array
    int i = (right + left) / 2;

    // as long as left is less than or equal to right, continue to search for k
    if (left <= right){
        // k was found
        if (A[i] == k){
            return i;
        }
        // ascending array
        if (sorted == 1){
            if (A[i] < k){
            // k was greater than A[i] so we need to look at the second half of array
                return binarySearchR(A, array_size, k, i + 1, right, sorted);
            }
            if (A[i] > k){
            // k was less than A[i] so we need to look at the first half of array
                return binarySearchR(A, array_size, k, left, i - 1, sorted);
            }
        }
        // descending array
        if (sorted == -1){
            if (A[i] < k){
            // k was greater than A[i] so we need to look at the first half of array
                return binarySearchR(A, array_size, k, left, i - 1, sorted);
            }
            if (A[i] > k){
            // k was less than A[i] so we need to look at the second half of array
                return binarySearchR(A, array_size, k, i + 1, right, sorted);
            }
        }
        
    }
    
    return -1;
}

int checkArraySort(string* A, int array_size){
    int sorted = 0;
    for (int i = 0; i < array_size - 1; i++){
        // array is not sorted
        if ((sorted == 1 && !(A[i] <= A[i+1])) || (sorted == -1 && !(A[i] >= A[i+1]))){
            return 0;
        }        
        // checks for ascending
        if (A[i] <= A[i+1]){
            sorted = 1;
        }
        // checks for descending
        if (A[i] >= A[i+1]){
            sorted = -1;
        }
    }
    return sorted;
}

int main(){

    // int variable to keep track of how many words in words_in.txt 
    int array_size = 0;

    // string variable to hold value of current line
    string line;

    // define a file to be read
    ifstream input;

    // open file that will be read
    input.open("words_in.txt", ios::in);

    // if input is unable to be opened, an error will be raised
    assert(!input.fail());

    // get first string from the file (priming the input statement)
    input >> line;
 
    while(getline(input, line)){
        array_size++; // increment array_size each time we encounter a new line
    }

    // create int pointer to heap to allocate enough space for an array of size array_size
    string* A = new string[array_size];
    
    // clear eof
    input.clear();
    // point back to beginning of input
    input.seekg(0);
    
    // set each line as an element of A
    for (int i = 0; i < array_size; i++){
        // read in each line and put inside A
        input >> line;
        A[i] = line;
    }


    // for (int i = 0; i < array_size; i++){
    //     cout << A[i] << endl;
    // }

    // close input file
    input.close();
    // check if file closed successfully
    assert(!input.fail());

    // create int variable called sorted and set equal to value returned by checkArraySort function
    int sorted = checkArraySort(A, array_size);
    // if sorted == 0, return 0
    if (sorted == 0){
        return 0;
    }

    // create string variable called k
    string k;
    // prompt user to input search key
    cout << "Input search key: ";
    // get value inputted by user and set equal to k
    getline(cin, k);

    // create an int variable called found and set equal to value of binarySearchR function
    int found = binarySearchR(A, array_size, k, 0, array_size - 1, sorted);

    // if found == -1, print that k is not in array
    if (found == -1){
        cout << "The key " << k << " was not found in the array!" << endl;
    }
    // if found != -1, print index of k
    else if (found != -1){
        cout << "The key " << k << " was found at index " << found << "!" << endl;
    }

    // release memory used by A in heap
    delete[] A;

    return 0;
}