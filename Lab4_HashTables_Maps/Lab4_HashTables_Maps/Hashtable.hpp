//
//  Hashtable.hpp
//  Lab4_HashTables_Maps
//
//  Created by Eden Meseret on 4/16/24.
//
/**
* Author: Eden Meseret
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#ifndef Hashtable_hpp
#define Hashtable_hpp
#include<iostream>
#include "task.h"
#include <functional>


using namespace std;


/*******************************************************

 * struct Name: <DataItem struct>

 * WHAT I CHANGED : <Modified TaskMenu to take the size numElements as a parameter and created a new Hashtable and Map at initialization>

 * Return: <struct>

 *******************************************************/
template <typename K, typename V>
struct DataItem{
    K key;
    V& value; //the value will be the task
    DataItem(const K& k, const V& v) : key(k), value(v) {}

};



/*******************************************************

 * class Name: <computeHash>

 * WHAT I CHANGED : <Modified the function to compute the hash value for a given key.>

 * Return: <size_t>

 *******************************************************/
template <typename K>
size_t computeHash(const K& key) {
    size_t h = 0;
    for (size_t i = 0; i < key.length(); i++)   {
        h = 31 * h + key[i];
    }
    return std::hash<K>{}(key);
}


/*******************************************************

 * class Name: <== operator>

 * WHAT I CHANGED : <Implemented the equality comparison operator for keys of type K.>

 * parameter: <constK& ihs, const K& rhs>
 
 * Return: <bool>

 *******************************************************/
template <typename K>
bool operator==(const K& lhs, const K& rhs) {
    // Example: If K is std::string, use std::string comparison
    return lhs == rhs;
}



/*******************************************************

 * class Name: <Hashtable constructor>

 * WHAT I CHANGED : <Created a hashtable data structure that stores key-value pairs, with functionality to add, delete, edit, search, and print values>

 * parameter: <size_t numElements>
 
 * Return: <K,V>

 *******************************************************/
template <typename K, typename V>
class Hashtable {
public:
    
    /*******************************************************
     * class Name: <Hashtable constructor>

     * WHAT I CHANGED : <Initializes a hashtable with a specified number of elements.>

     * parameter: <size_t numElements>
     *******************************************************/
    Hashtable(size_t numElements) : numElements(numElements) {
        table = new DataItem<K, V>[numElements];
    }
    
    
    /*******************************************************
     * class Name: <~Hashtable>

     * WHAT I CHANGED : <Deallocates memory used by the hashtable.>
     *******************************************************/
    ~Hashtable() {
        delete[] table;
    }

    
    /*******************************************************
     * class Name: <add>

     * WHAT I CHANGED : <Adds a key-value pair to the hashtable.>

     * parameter: <const K& key, const V& value>
     *******************************************************/
    void add(const K& key, const V& value) {
        size_t index = computeHash(key) % numElements;
        while (!table[index].key.empty()) {
            index = (index + 1) % numElements;
        }
        table[index] = { key, value };
    }

    
    /*******************************************************
     * class Name: <deleteKey>

     * WHAT I CHANGED : <Deletes a key and its associated value from the hashtable.>

     * parameter: <const K& key>
     *******************************************************/
    void deleteKey(const K& key) {
        size_t index = findIndex(key);
        if (index != numElements) {
            table[index].key.clear(); // Mark slot as empty
            // Optionally clear the value too: table[index].value = V{};
        } else {
            cout << "Item with key " << key << " not found." << endl;
        }
    }
    
    /*******************************************************
     * class Name: <editValue>

     * WHAT I CHANGED : <Modifies the value associated with a given key in the hashtable.>

     * parameter: <const K& key, const V& newValue>
     *******************************************************/
    void editValue(const K& key, const V& newValue) {
        size_t index = findIndex(key);
        if (index != numElements) {
            table[index].value = newValue;
        } else {
            cout << "Item with key " << key << " not found." << endl;
        }
    }

    
    /*******************************************************
     * class Name: <search>

     * WHAT I CHANGED : <Searches for a key in the hashtable and returns a pointer to its associated value if found, nullptr otherwise.>

     * parameter: <const K& key>
     *Return <V*>
     *******************************************************/
    V& search(const K& key) const {
        size_t index = findIndex(key);
        if (index != numElements) {
            return &table[index].value;
        } else {
            return nullptr; // Key not found
        }
    }

    
    /*******************************************************
     * class Name: <printValues>

     * WHAT I CHANGED : <Prints the values stored in the hashtable, optionally filtering by whether tasks are completed or not.>

     * parameter: <bool completedTasks>
     *******************************************************/
    void printValues(bool completedTasks) {
        for (size_t i = 0; i < numElements; ++i) {
            if (!table[i].key.empty() && (completedTasks == table[i].value.isCompleted())) {
                cout << table[i].key << " " << table[i].value << endl;
            }
        }
    }
    
    /**
         * @brief Returns the number of elements currently stored in the hashtable.
         *
         * @return size_t The number of elements.
         */
    size_t size() const{
        return numElements;
    }
    
    
    const V& operator[](const K& key) const {
            size_t index = findIndex(key);
            if (index != numElements) {
                return table[index].value;
            } else {
                throw std::out_of_range("Key not found");
            }
        }
    
    
    void printAll(std::function<void(const K&, const V&)> printFunction) const {
        for (size_t i = 0; i < numElements; ++i) {
            if (!table[i].key.empty()) {
                printFunction(table[i].key, table[i].value);
            }
        }
    }

private:
    size_t numElements = 0; //coutner for the number of elements
    DataItem<K, V>* table;

    
    /*******************************************************
     * private function Name: <findIndex>

     * WHAT I CHANGED : <Finds the index of a given key in the hashtable.>

     * parameter: <const K& key>
    
     *Return: <size_t>
     *******************************************************/
    size_t findIndex(const K& key) const {
            size_t index = computeHash(key) % numElements;
            size_t originalIndex = index;
            do {
                if (table[index].key == key) {
                    return index; // Key found
                }
                index = (index + 1) % numElements;
            } while (index != originalIndex && !table[index].key.empty());
            return numElements; // Key not found
        }
    };



#endif /* Hashtable_hpp */
