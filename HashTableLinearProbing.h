//
//  HashTableLinearProbing.h
//  
//
//  Created by Jesse Hamlin on 12/7/21.
//

#ifndef HashTableLinearProbing_h
#define HashTableLinearProbing_h


#include "hashtable.h"

class HashTableLinearProbing : private HashTable{
    
private:
    
public:
    HashTableLinearProbing(){
        m=0;
    }
    ~HashTableLinearProbing(){
        delete [] hash;
    }
    
    int * hash;
    
    int load(string file);      // Returns 1 if the input file was loaded and all entries were inserted correctly, 0 otherwise.
    void print();               // Print the table in a pretty way
    int insert(int value);      // Returns 1 if it inserted correctly and 0 if it failed to insert. If an entry was already in the table, return 1.
    int search(int value);      // Returns 1 if the entry was in the table, 0 otherwise.
    int remove(int value);      // Returns 1 if the entry was deleted correctly and 0 if it failed to delete. If the entry was not in the table to begin, return 1.

};




#endif /* HashTableLinearProbing_h */
