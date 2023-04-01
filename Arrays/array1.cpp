// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int arr_size;
    cout << "Enter the size of the array: ";
    cin >> arr_size;
    cin.ignore();

    if (arr_size < 0){
        cout << "ERROR: you entered an incorrect value for the array size!" << endl;
        return 0;
    }

    int* arr = new int[arr_size];
    bool ascending = true;

    string nums;
    cout << "Enter the numbers in the array, separated by space, and press enter: ";
    for (int i = 0; i < arr_size; i++){
        scanf("%d", &(arr[i]));
        if (i > 0){
            if (arr[i] < arr[i - 1]){
                ascending = false;
            }
        }
    }

    if (ascending){
        cout << "This IS an increasing array!" << endl;
    }
    else{
        cout << "This is NOT an increasing array!" << endl;
    }

    for (int i = 0; i < arr_size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
// release memory used by arr from heap
    delete[] arr;
// set arr to NULL so it isn't pointing to memory that doesn't belong to it
    arr = NULL;
    
    return 0;
}