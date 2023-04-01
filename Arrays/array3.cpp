// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){

    int n; // size of nxn array
    cout << "Enter the size of a 2D array: ";
    cin >> n;
    if (n > 10){
        cout << "ERROR: your array is too large! Enter 1 to 10." << endl;
        return 0;
    }
    if (n < 0){
        cout << "ERROR: you entered an incorrect value for the array size!" << endl;
        return 0;
    }

// create an int pointer to a pointer
    int** two_dim_arr = new int*[n];
// each pointer in two_dim_arr is given an int array of size n (allocate space)
    for (int i = 0; i < n; i++){
        two_dim_arr[i] = new int[n];
    }

    int negative_nums = 0;
    for (int i = 0; i < n; i++){
        cout << "Enter the values for the array in row " << i + 1 << ": ";
        for (int j = 0; j < n; j++){
            scanf("%d", &(two_dim_arr[i][j]));
            // check if integer is negative
            if (two_dim_arr[i][j] < 0){
                negative_nums += 1;
            }
        }
    }

    if (negative_nums > 0){
        cout << "There are " << negative_nums << " negative values!" << endl;
    }
    else{
        cout << "All values are non-negative!" << endl;
    }
  

// release memory used by pointers in two_dim_arr from heap
    for (int i = 0; i < n; i++){
        delete[] two_dim_arr[i];
    }
// release memory used by two_dim_arr itself from heap 
    delete[] two_dim_arr;

// set two_dim_arr to NULL so that it is not pointing to memory that does not belong to it anymore
    two_dim_arr = NULL;

    return 0;
}