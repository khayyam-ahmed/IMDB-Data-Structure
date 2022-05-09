#pragma once

#include <iostream>
#include <type_traits>
#include <cstring>
#include "LinkedList_Pair.h"

using namespace std;

//Hashtable to implement phone book

template <class Key, class Data>
class HashTable {
private:
    static const int hashGroups = 1000;
    //list<pair<Key, Data*>> table[hashGroups]; // List 1 Index 0, List 2 Index 1...
    LinkedList_Pair<Data, Key>* table = new LinkedList_Pair<Data, Key>[hashGroups];
public:
    bool isEmpty() const;
    int hashFunction(Key key);
    void insertItem(Key key, Data* value);
    Data* searchTable(Key key);
};

template <class Key, class Data>
bool HashTable<Key, Data>::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i]->size();
    }

    if (!sum) {
        return true;
    }
    return false;
}

template <class Key, class Data>
int HashTable<Key, Data>::hashFunction(Key key) {
    int sum{};
    if constexpr (is_same_v<Key, string>) {
        for (int i = 0; i < key.size() ; i++)
            sum = sum + key[i];
        return sum % hashGroups;
    }
    else
        return key % hashGroups;
}

template <class Key, class Data>
void HashTable<Key, Data>::insertItem(Key key, Data* data) {
    int hashValue = hashFunction(key);

    table[hashValue].Search(key);
    if (table[hashValue].Loc_ != NULL) {
        table[hashValue].Loc_->data = data;
        cout << "[WARNING] Key \""<<key<<"\" exists. Value replaced" << endl;
    }
    else {
        table[hashValue].InsertSorted(key, data);
    }
    return;
}

template <class Key, class Data>
Data* HashTable<Key, Data> :: searchTable(Key key) {
    int hashValue = hashFunction(key);
    table[hashValue].Search(key);
    if (table[hashValue].Loc_ != NULL) {
        cout << "[INFO] Key \"" << key << "\" found. Returning Data*."<<endl;
    }
    else {
        cout << "[INFO] Key \"" << key << "\" found." << endl;
    }
    return table[hashValue].Loc_->data;
}