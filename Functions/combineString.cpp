// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
using namespace std;

string combineStr(string& str, const int times){
    // holds value of original string
    string original_str = str;
    for (int i = 0; i < times - 1; i++){
        // adds original string to str variable
        // iterate (times - 1) times because str already holds one instance of original string
        str += original_str;
    }
    return str;
}

int main(){
    string str;
    cout << "Enter a string: ";
    // getline function used to get entire string, including spaces
    getline(cin, str);

    int times;
    cout << "Enter a number of times: ";
    cin >> times;
    // if times is 0 user does not want to print the string
    if (times == 0){
        return 0;
    }

    str = combineStr(str, times);
    cout << "The resulting string is: " << str << endl;

    return 0;
}