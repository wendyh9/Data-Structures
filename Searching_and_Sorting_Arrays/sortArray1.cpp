// author: Wendy Haw
// collaborators: none
// selection sort
// descending
// chose maximum

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int arr_size;
    cout << "Enter the size of the array: ";
    cin >> arr_size;

    if (arr_size < 0){
        cout << "ERROR: you entered an incorrect value for the array size!" << endl;
        return 0;
    }

    int* arr = new int[arr_size];
    
    cout << "Enter the numbers in the array, separated by space, and press enter: ";
    for (int i = 0; i < arr_size; i++){
        scanf("%d", &(arr[i]));
    }

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


    cout << "This is the sorted array in descending order: ";
    for (int i = 0; i < arr_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl << "The algorithm selected the maximum for the traverse of the array." << endl;
    
    delete[] arr;
    return 0;
}