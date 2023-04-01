// author: Wendy Haw
// collaborators: none

#include <iostream>
using namespace std;

int main(){
    string correct_sentence = "I will always use object oriented programming.";
    string typo_sentence = "I will always use object oriented programing.";
    int times;
    int typo_line;
    
    cout << "Enter the number of lines for the punishment: ";
    cin >> times;

    if (times < 0){
        cout << "You entered an incorrect value for the number of lines!" << endl;
        return 0;
    }

    cout << "Enter the line for which we want to make the typo: ";
    cin >> typo_line;
    
    if (typo_line < 0){
        cout << "You entered an incorrect value for the line typo!" << endl;
        return 0;
    }

    else{
        for (int i = 0; i < times; i++){
            if ((i + 1) == typo_line){
                cout << typo_sentence << " ";
            }
            else{
                cout << correct_sentence << " ";
            }
        }
        cout << endl;
    }

    return 0;
}