#include"hashtable.h"

HashTable ::HashTable(){}

HashTable::~HashTable(){}

// Core functionality
int HashTable:: insert(int value) {return 0;}
      // Returns 1 if it inserted correctly and 0 if it failed to insert. If an entry was already in the table, return 1.
    int HashTable::search(int value){return 0;}      // Returns 1 if the entry was in the table, 0 otherwise.

    int HashTable::remove(int value){return 0;}      // Returns 1 if the entry was deleted correctly and 0 if it failed to delete. If the entry was not in the table to begin, return 1.

    int HashTable::load(string file){return 0;}      // Returns 1 if the input file was loaded and all entries were inserted correctly, 0 otherwise.
                                    // You may assume that input files do not cause inserts that return 0.
    void HashTable::print(){return;}
