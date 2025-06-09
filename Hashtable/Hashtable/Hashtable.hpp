


//
//  Hashtable.hpp
//  Hashtable
//
//  Created by Eden Meseret on 4/11/24.
//

#ifndef Hashtable_hpp
#define Hashtable_hpp
//#include <unordered_map>
#include <iostream>
#include "task.h"


using namespace std;

template <typename K, typename V>
struct DataItem{
    K key;
    V value; //the value will be the task
};


template <typename K>
size_t computeHash(const K& key) {
    size_t h = 0;
    for (size_t i = 0; i < key.length(); i++)   {
        h = 31 * h + key[i];
    }
    return std::hash<K>{}(key);
}

template <typename K>
bool operator==(const K& lhs, const K& rhs) {
    // Example: If K is std::string, use std::string comparison
    return lhs == rhs;
}

template <typename K, typename V>
class Hashtable {
public:
    Hashtable(size_t numElements) : numElements(numElements) {
        table = new DataItem<K, V>[numElements]();
    }

    ~Hashtable() {
        delete[] table;
    }

    void add(const K& key, const V& value) {
        size_t index = computeHash(key) % numElements;
        while (!table[index].key.empty()) {
            index = (index + 1) % numElements;
        }
        table[index] = { key, value };
    }

    void deleteKey(const K& key) {
        size_t index = findIndex(key);
        if (index != numElements) {
            table[index].key.clear(); // Mark slot as empty
            // Optionally clear the value too: table[index].value = V{};
        } else {
            cout << "Item with key " << key << " not found." << endl;
        }
    }

    void editValue(const K& key, const V& newValue) {
        size_t index = findIndex(key);
        if (index != numElements) {
            table[index].value = newValue;
        } else {
            cout << "Item with key " << key << " not found." << endl;
        }
    }

    V* search(const K& key) {
        size_t index = findIndex(key);
        if (index != numElements) {
            return &table[index].value;
        } else {
            return nullptr; // Key not found
        }
    }

    void printValues(bool completedTasks) {
        for (size_t i = 0; i < numElements; ++i) {
            if (!table[i].key.empty() && (completedTasks == table[i].value.isCompleted())) {
                cout << "Key: " << table[i].key << ", Value: " << table[i].value << endl;
            }
        }
    }

private:
    size_t numElements;
    DataItem<K, V>* table;

    size_t findIndex(const K& key) {
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






//template <typename K, typename V>
//class Hashtable {
//public:
//    Hashtable(size_t num_elements) : numElements(numElements) {
//        table = new DataItem<K,V>[numElements];
//    }
//    ~Hashtable() {
//      delete[] table;
//    }
//    
//    void add(const K &key, const V &value) {
//      int hashCode = computeHash(key);
//      int index = hashCode % numElements; // < num_elements
//        while(table[index].key != ""){
//            index++;
//            index %= numElements;
//        }
//        table[index].key = key;
//        table[index].value = value;
//    }
//    
//    void deleteKey(const K &key) {
//        int hashIndex = computeHash(key);
//        while (table[hashIndex] != nullptr){
//            if (table[hashIndex]->key == key){
//                delete table[hashIndex];
//                table[hashIndex] = nullptr;
//                return;
//            }
//            ++hashIndex;
//            hashIndex %= numElements;
//        }
//        cout << "Item with key " << key << " not found." << endl;
//        
//    }
//    
//    void editValue(const K &key) {
//        int hashIndex = computeHash(key);
//        while (table[hashIndex] != nullptr){
//            if (table[hashIndex]->key == key){
//                //set value at key 
//                return;
//            }
//            ++hashIndex;
//            hashIndex %= numElements;
//        }
//        cout << "Item with key " << key << " not found." << endl;
//        
//    }
//    
//    V *search(const K &key) {
//        int hashCode = computeHash(key);
//        int index = hashCode %= numElements;
//        while (table[index].key != "" && table[index].key != key){
//            index++;
//            index %= numElements;
//        }
//        if(table[index].key == ""){
//            return nullptr; //key not found
//        }else {
//            return &table[index].value;
//        }
//    }
//    
//    void printValues(){
//        for (size_t i = 0; i < numElements; ++i){
//            if(!table[i].key.empty()){
//                cout << "Key " << table[i].key << ", Value: " << table[i].value << endl;
//            }
//        }
//    }
//    
//    int computeHash(const string& str) {
//       int h = 0;
//       for (int i = 0; i < str.length(); i++)   {
//          h = 31 * h + str[i];
//       }
//       return h;
//    }
//    
//    //add
//    //delete
//    //printallvalues
//    //edit (value)
//    //search
//
//private:
//    size_t numElements;
//    DataItem<K,V> *table;
//};





//      table = new DataItem<K, V>[num_elements];


//    DataItem<K, V> *table;

//DataItem<Task>* search(string key) {
//   // get the hash
//   int hashIndex = hashCode(key);
//   
//   // move in the map until an empty slot is found or the key is found
//   
//    try{
//        // If the key is found, return the corresponding DataItem pointer
//        if (hashMap[hashIndex]->key.getName() == key){
//            return hashMap[hashIndex];
//        }
//        throw runtime_error("Hash collision");
//    }catch (const exception& e){
//        cerr << "Error: " << e.what() << endl;
//        // If the key is not found, return nullptr
//        return nullptr;
//    }
//   }
//
//int compute_hash(const string& str) {
//   int h = 0;
//   for (int i = 0; i < str.length(); i++)   {
//      h = 31 * h + str[i];
//   }
//   return h;
//}
//int compute_hash(int obj) {
//  return obj;
//}
////int compute_hash(long long obj) {
////   return (obj & 0xffffffff) ^ (obj >> 32);
////}
//
//template <typename K, typename V>
//struct DataItem {
//    K key;
//    V value;
//};
//



//something to add value , what value can you add to the application
//what features can i add

#endif /* Hashtable_hpp */





//
////  Hashtable.hpp
////  Hashtable
////
////  Created by Eden Meseret on 4/11/24.
////
//
//#ifndef Hashtable_hpp
//#define Hashtable_hpp
//#include <unordered_map>
//#include <iostream>
//#include "task.h"
//
//
//using namespace std;
//
//template <typename T>
//struct DataItem{
//    T key;
//};
//
//
//unordered_map<int, DataItem<Task>*> hashMap;
//
//int hashCode(const string& str) {
//   int h = 0;
//   for (int i = 0; i < str.length(); i++)   {
//      h = 31 * h + str[i];
//   }
//   return h;
//}
//
//DataItem<Task>* search(string key) {
//   // get the hash
//   int hashIndex = hashCode(key);
//
//   // move in the map until an empty slot is found or the key is found
//
//    try{
//        // If the key is found, return the corresponding DataItem pointer
//        if (hashMap[hashIndex]->key.getName() == key){
//            return hashMap[hashIndex];
//        }
//        throw runtime_error("Hash collision");
//    }catch (const exception& e){
//        cerr << "Error: " << e.what() << endl;
//        // If the key is not found, return nullptr
//        return nullptr;
//    }
//   }
//
//
//void insert(int key, Task data){
//    vector <DataItem<Task>*> hashArray(SIZE, nullptr);
//
//}
//
//
//
//
//
//template <typename T>
//class Hashtable{
//public:
//        Hashtable    (size_t num_elements)
//private:
//    size_t num_elements;
//    DataItem<T> tableArray;
//
//};
//
//
//#endif /* Hashtable_hpp */
//
