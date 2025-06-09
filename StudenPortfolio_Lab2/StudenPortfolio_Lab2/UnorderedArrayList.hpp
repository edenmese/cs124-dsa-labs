//
//  UnorderedArrayList.hpp
//  StudenPortfolio_Lab2
//
//  Created by Eden Meseret on 3/27/24.
//

#ifndef UnorderedArrayList_hpp
#define UnorderedArrayList_hpp
#include "AbstractList.hpp"

template <typename T>
class UnorderedArrayList : public AbstractList<T>{
public:
    using AbstractList<T>::AbstractList;
    
    T& get(int index) override;// Method to get an element at a specific index
    void set(int index, const T& value)override;// Method to set a value at a specific index
    void add(const T& element)override; // Add element to the end of the AbstractList
    void remove(int index)override;

};

template<typename T>
T& UnorderedArrayList<T>::get(int index) {
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->array[index];
}

template<typename T>
void UnorderedArrayList<T>::set(int index, const T& value) {
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("Index out of bounds");
    }
    this->array[index] = value;
}

template<typename T>
void UnorderedArrayList<T>::add(const T& element) {
    if (this->size == this->capacity) {
        this->capacity *= 2;
        T* newArray = new T[this->capacity];
        for (int i = 0; i < this->size; ++i) {
            newArray[i] = this->array[i];
        }
        delete[] this->array;
        this->array = newArray;
    }
    this->array[this->size++] = element;
}

template<typename T>
void UnorderedArrayList<T>::remove(int index) {
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("Index out of range");
    }

    for (int i = index; i < this->size - 1; ++i) {
        this->array[i] = this->array[i + 1];
    }
    this->size--;
}




#endif /* UnorderedArrayList_hpp */


