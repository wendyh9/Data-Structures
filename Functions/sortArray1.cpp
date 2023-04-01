// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <stdio.h>
using namespace std;

void sortArr(int arr[], const int arr_size, const int descending){
    if (descending == 0){
    // index of minimum value in arr
    int min_index;
        for (int i = 0; i < arr_size - 1; i++){
            // set min_index to current value of i
            min_index = i;
            // already set min_index to i so need to check the rest of arr
            for (int j = i + 1; j < arr_size; j++){
                if (arr[j] < arr[min_index]){
                    min_index = j;
                }
            }
            // check if min_index is not i (if min_index == i, no swapping needed)
            if (min_index != i){
                swap(arr[i], arr[min_index]);
            }

        }

    }
    else{
        // index of maximum value in arr 
        int max_index;
    
        for (int i = 0; i < arr_size - 1; i++){
            // set max_index to current value of i
            max_index = i;
            // already set max_index to i so need to check the rest of arr
            for (int j = i + 1; j < arr_size; j++){
                // if arr[j] is greater than arr[max_index] we know j is the new max_index
                if (arr[j] > arr[max_index]){
                    max_index = j;
                }
            }
            // check if max_index is not i (if max_index == i, no swapping needed)
            if (max_index != i){
                swap(arr[i], arr[max_index]);
            }
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