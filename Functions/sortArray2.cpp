// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <stdio.h>
using namespace std;

void sortArr(int arr[], const int arr_size, const int descending){
    // int variable current_val to hold current value we are looking at
    int current_val;    
    if (descending == 0){
        for (int i = 1; i < arr_size; i++){
            // set current_val to current element in arr
            current_val = arr[i];
            // create int element j to i - 1
            int j = i - 1;
            // check if current_val is less than arr[j] and if j is greater than or equal to 0
            while (current_val < arr[j] && j >= 0){
                // shift other elements to the right to make room for current_val because we want small value first
                // ascending -> least to greatest 
                arr[i] = arr[j];
                // decrement j
                j--;
                // decrement i
                i--;
            }
            // set arr[j + 1] to current_val
            arr[j + 1] = current_val;
        }
    }
    else{        
        for (int i = 1; i < arr_size; i++){
            // set current_val to current element in arr
            current_val = arr[i];
            // create int element j to i - 1
            int j = i - 1;
            // check if current_val is greater than arr[j] and if j is greater than or equal to 0
            while (current_val > arr[j] && j >= 0){
                // shift other elements to the right to make room for current_val because we want big values at the beginning
                // descending -> greatest to least
                arr[i] = arr[j];
                // decrement j
                j--;
                // decrement i
                i--;
            }
            // set arr[j + 1] to current_val
            arr[j + 1] = current_val;
        }

    }

}

int main(){

    int arr_size;
    cout << "Enter the size of the array: ";
    cin >> arr_size;
    
    if (arr_size < 0){
        cout << "ERROR: you entered an incorrect value for the array size!";
        return 0;
    }

    int* arr = new int[arr_size];
    cout << "Enter the numbers in the array, separated by space, and press enter: ";
    for (int i = 0; i < arr_size; i++){
        scanf("%d", &(arr[i]));
    }

    int descending;
    cout << "Sort in ascending (0) or descending (1) order: ";
    cin >> descending;

    sortArr(arr, arr_size, descending);
    if (descending == 0){
        cout << "This is the sorted array in ascending order." << endl;
    }
    else{
        cout << "This is the sorted array in descending order." << endl;
    }

    for (int i = 0; i < arr_size; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;

    delete[] arr;

    return 0;
}