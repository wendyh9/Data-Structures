// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
using namespace std;

int main(){
    string sentence = "I will always use object oriented programming.";
    int times;
    cout << "Enter the number of lines for the punishment: ";
    cin >> times;

    if (times < 0){
        cout << "You entered an incorrect value for the number of lines!" << endl;
        return 0;
    }

    else{
        for (int i = 0; i < times; i++){
            cout << sentence << " ";
        }
        cout << endl;
    }
    
    return 0;
}