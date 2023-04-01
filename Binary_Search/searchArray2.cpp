// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
using namespace std;

// binary search -> array must be sorted
// use a loop

int binarySearchR(string* A, int array_size, string k, int sorted){
    // create an int variable called left and initialize to 0
    int left = 0;
    // create an int variable called right and initialize to array_size - 1
    int right = array_size - 1;

    // as long as left is less than or equal to right, continue to search for k
    while (left <= right){
        // each time we search, we want to start at the middle of the array
        int i = (right + left) / 2;

        // k was found
        if (k == A[i]){
            return i;   
        }
        // ascending array
        if (sorted == 1){
            // k was greater than A[i] so we need to look at the second half of array
            if (A[i] < k){
                left = i + 1;
            }
            // k was less than A[i] so we need to look at the first half of array
            if (A[i] > k){
                right = i - 1; 
            }            
        }
        // descending array
        if (sorted == -1){
            // k was greater than A[i] so we need to look at the first half of array
            if (A[i] < k){
                right = i - 1;
            }
            // k was less than A[i] so we need to look at the second half of array
            if (A[i] > k){
                left = i + 1; 
            }  
        }

    } 
    // if k was not found return -1
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
        input >> line;
        A[i] = line;
        // cout << "A[i]: " << A[i] << endl;;
    }


    // for (int i = 0; i < array_size; i++){
    //     cout << *(A + i) << endl;
    // }

    // close input file
    input.close();
    // check if file closed successfully
    assert(!input.fail());

    int sorted = checkArraySort(A, array_size);

    // check if A is sorted
    if (sorted == 0){
        // stop program if A is not sorted
        return 0;
    }

    // create a string variable k
    string k;
    //prompt user to enter search key
    cout << "Please input search key: ";
    // get value of search key and store in k
    getline(cin, k);

    // call binary search function and set value equal to index
    int index = binarySearchR(A, array_size, k, sorted);
 
    // if index is not -1 print key and its index
    if (index != -1){
        cout << "The key " << k << " was found at index " << index << "!" << endl;
    }
    // otherwise print that k was not found
    else{
        cout << "The key " << k << " was not found in the array!" << endl;
    }

    // release memory used by A on the heap
    delete[] A;

    return 0;
}