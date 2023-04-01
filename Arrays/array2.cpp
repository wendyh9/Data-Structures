// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout << "Enter the string to reverse: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << str << endl;
    // for (int i = str.length(); i > -1; i--){
    //     cout << str[i];
    // }
    // cout << "\n";
    return 0;
}