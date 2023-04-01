// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "HTable.h"

// custom constructor
HTable::HTable(int t_size){
    max_size = t_size;
    dt = new data[max_size];

    for (int i = 0; i < max_size; i++){
        dt[i].key = -1;
        dt[i].value = "N/A";   
    }
    numel = 0;    
}

// default constructor
HTable::HTable(){
    HTable(23);
}


// destructor
HTable::~HTable(){
    delete[] dt;
}

int HTable::hash(int& k){
// use the modulo operator (%) to evaluate the hash code
// returns the hash code, which is the remainder of k divided by the size of the table 
// hash code will be used as the index value of the hash table when storing the data
    return k % max_size;
}

int HTable::rehash(int& k){
    // linear probing
    return (k + 1) % max_size;
}

int HTable::add(data& d){
    // check if table is full before adding data to it
    if (numel == max_size){
        return -1;
    }

    int index = HTable::hash(d.key);
    
    // space at index is available
    if (dt[index].key == -1){
        dt[index].value = d.value;
        dt[index].key = d.key;
        numel += 1;
        return 0;
    }
    // need to rehash to find available space
    else{
        for (int i = 0; i < max_size; i++){
            if (dt[index].key != -1){
                index = HTable::rehash(index);
            }
            else{
                break;
            }             
        }    
        dt[index].key = d.key; 
        dt[index].value = d.value;
        numel += 1;
        return 0;
    }

}

int HTable::remove(data& d){

    int index = HTable::hash(d.key);
    // data was found in hash table
    if (dt[index].key == d.key){
        dt[index].key = -1;
        dt[index].value = "N/A";
        numel -= 1;
        return 0;
    }
    else{
        // keep track of how many times index is rehashed
        int counter = 0;
        do{
            counter++;
            index = HTable::rehash(index);
            // was not able to find data in hash table
            if (counter == max_size){
                return -1;
            }            
        }
        while(dt[index].key != d.key);        
        dt[index].key = -1;
        dt[index].value = "N/A";
        numel -= 1;
        return 0;        
    }
}

void HTable::output(){
    // print out hash table and numel
    for (int i = 0; i < max_size; i++){
        cout << i << " -> " << dt[i].key << " " << dt[i].value << endl;
    }
    cout << "There are " << numel << " data in the table." << endl;
}