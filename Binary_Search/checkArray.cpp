// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
using namespace std;

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
    }

    // for (int i = 0; i < array_size; i++){
    //    a cout << A[i] << endl;
    // }

    // close input file
    input.close();
    // check if file closed successfully
    assert(!input.fail());

    // create int variable called sorted and initialize to value returned by checkArraySort function
    int sorted = checkArraySort(A, array_size);

    // if sorted == -1, array is in descending order 
    if (sorted == -1){
        cout << "The array is sorted in descending order!" << endl;
    }
    // if sorted == 0, array is not sorted
    else if (sorted == 0){
        cout << "The array is not sorted!" << endl;
    }
    // if sorted == 1, array is in ascending order
    else if (sorted == 1){
        cout << "The array is sorted in ascending order!" << endl;
    }

    // release memory used by A on heap
    delete[] A;

    return 0;
}