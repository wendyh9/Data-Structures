// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
using namespace std;

int main(){
    // int variable to keep track of how many words in words_in.txt 
    int counter = 0;

    // string variable to hold value of current line
    string line;

    // define a file to be read
    ifstream input;

    // open file that will be read
    input.open("words_in.txt", ios::in);

    // if input is unable to be opened, an error will be raised
    assert(!input.fail());

    // define a file to be written on
    ofstream output;

    // open file that will be written on
    output.open("words_out.txt", ios::out);

    // if input is unable to be opended, an error will be raised
    assert(!output.fail());

    // get first string from the file (priming the input statement)
    input >> line;
 
    while(getline(input, line)){
        counter++; // increment counter each time we encounter a new line
    }

    // create int pointer to heap to allocate enough space for an array of size counter
    string* arr = new string[counter];
    
    // clear eof
    input.clear();
    // point back to beginning of input
    input.seekg(0);
    
    // set each line as an element of arr
    for (int i = 0; i < counter; i++){
        input >> line;
        arr[i] = line;
    }

    // for (int i = 0; i < counter; i++){
    //     cout << arr[i] << endl;
    // }
    
    // write out each line of arr onto output
    for (int i = 0; i < counter; i++){
        output << arr[i] << "\n";
    }

    // close input file
    input.close();
    // check if file closed successfully
    assert(!input.fail());
    // close output file
    output.close();
    // check if file closed successfully
    assert(!output.fail());

    // release memory used by arr on heap
    delete[] arr;


    return 0;
}
