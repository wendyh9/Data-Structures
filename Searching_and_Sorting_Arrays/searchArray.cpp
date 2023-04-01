// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <stdio.h>
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
    
    int v;
    cout << "Enter a number to search for in the array: ";
    cin >> v;

    bool found = false;
    int index;
    int x;
    for (int i = 0; i < arr_size; i++){
        if (arr[i] == v){
            index = i;
            x = i + 1;
            found = true;
            break;
        }
    }

    if (found){
        cout << "Found value " << v << " at index " << index << ", which took " << x << " checks." << endl;
        if (index == 0){
            cout << "We ran into the best case scenario!" << endl;
        }
        if (index == arr_size - 1){
            cout << "We ran into the worst case scenario!" << endl; 
        }
    }
    else{
        cout << "The value " << v << " was not found in the array!" << endl;
    }

    return 0;
}