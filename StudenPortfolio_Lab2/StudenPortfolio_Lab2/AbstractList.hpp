//
//  AbstractList.hpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/26/24.
//

#ifndef AbstractList_hpp
#define AbstractList_hpp
#include <stdexcept>

using namespace std;
template<typename T>
class AbstractList {
protected:
    T* array;
    int capacity;
    int size;

public:
    // Constructor
    AbstractList(int initialCapacity = 10);

    // Destructor
    ~AbstractList();

    // Copy constructor
    AbstractList(const AbstractList& other);

    //pure virtual methods
    virtual T& get(int index) = 0;  // Method to get an element at a specific index
    virtual void set(int index, const T& value) = 0;// Method to set a value at a specific index
    virtual void add(const T& element) = 0; // Add element to the end of the AbstractList
    virtual void remove(int index) = 0; // Remove from the array

    // Overloaded assignment operator
    AbstractList& operator=(const AbstractList& other);

   

    // Get the size of the AbstractList
    int getSize() const;

   
};

template<typename T>
AbstractList<T>::AbstractList(int initialCapacity) : capacity(initialCapacity), size(0) {
    array = new T[capacity];
}

template<typename T>
AbstractList<T>::~AbstractList() {
    delete[] array;
}

template<typename T>
AbstractList<T>::AbstractList(const AbstractList& other) : capacity(other.capacity), size(other.size) {
    array = new T[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}


template<typename T>
AbstractList<T>& AbstractList<T>::operator=(const AbstractList& other) {
    if (this != &other) {
        delete[] array;
        capacity = other.capacity;
        size = other.size;
        array = new T[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}


template<typename T>
int AbstractList<T>::getSize() const {
    return size;
}




#endif /* AbstractList_hpp */
