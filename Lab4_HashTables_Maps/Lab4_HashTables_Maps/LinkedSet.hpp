//
//  LinkedSet.hpp
//  Lab4_HashTables_Maps
//
//  Created by Eden Meseret on 5/13/24.
//

#ifndef LinkedSet_hpp
#define LinkedSet_hpp

#include <iostream>
#include <unordered_set>
#include "linkedlist.h"
using namespace std;

#include <iostream>



template <typename T>
class LinkedSet : public LinkedList<T> {
public:
    
    class LinkedSetIterator {
    public:
        /**
         * class Name: <LinkedSetIterator constructor>
         *
         * WHAT I CHANGED: <Constructs an iterator pointing to a given position in the linked set.>
         *
         * parameter:
         *  - position: a pointer to the current node
         *  - container: a pointer to the linked set container
         */
        LinkedSetIterator(Node<T>* position, LinkedSet<T>* container) : position(position), container(container) {}

        /**
         * class Name: <get>
         *
         * WHAT I CHANGED: <Retrieves the value of the current node pointed to by the iterator.>
         *
         * return: the value of the current node
         */
        T get() const {
            return position->data;
        }

        /**
         * class Name: <next>
         *
         * WHAT I CHANGED: <Advances the iterator to the next node in the linked set.>
         */
        void next() {
            position = position->next;
        }

        /**
         * class Name: <previous>
         *
         * WHAT I CHANGED: <Moves the iterator to the previous node in the linked set.>
         */
        void previous() {
            position = position->previous;
        }

        /**
         * class Name: <equals>
         *
         * WHAT I CHANGED: <Compares two iterators for equality.>
         *
         * parameter:
         *  - other: the iterator to compare with
         *
         * return: true if this iterator and other are equal, false otherwise
         */
        bool equals(const LinkedSetIterator<T>& other) const {
            return position == other.position;
        }

    private:
        Node<T>* position; // Pointer to the current node
        LinkedSet<T>* container; // Pointer to the linked set container
    };
    
    /**
     * class Name: <LinkedSet constructor>
     *
     * WHAT I CHANGED: <Constructs an empty set by calling the constructor of the base class (LinkedList). Initializes the elementSet to store unique elements.>
     *
     * parameter: None
     */
    LinkedSet() : LinkedList<T>() {}
    
    
    
    /**
     * class Name: <insert>
     *
     * WHAT I CHANGED: <Inserts an element into the set if it is not already present. Checks whether the element exists in the set before adding it to both the linked list and the elementSet.>
     *
     * parameter: <T element> - the value to insert
     */
    void insert(T element) {
        // Check if the element already exists in the set
        if (elementSet.find(element) == elementSet.end()) {
            LinkedList<T>::push_back(element);
            elementSet.insert(element);
        }
    }

    
    
    
    /**
     * class Name: <erase>
     *
     * WHAT I CHANGED: <Erases an element from the set. Checks whether the element exists in the set before searching and removing it from the linked list. Removes the element from the elementSet if found.>
     *
     * parameter: <T element> - the value to erase
     *
     * return: <bool> - true if the element was erased, false otherwise
     */
    bool erase(T element) {
        // Check if the element exists in the set
        if (elementSet.find(element) != elementSet.end()) {
            typename LinkedList<T>::Iterator iter = LinkedList<T>::begin();
            while (!iter.equals(LinkedList<T>::end())) {
                if (iter.get() == element) {
                    LinkedList<T>::erase(iter);
                    elementSet.erase(element);
                    return true;
                }
                iter.next();
            }
        }
        return false;
    }
    
    
    LinkedSetIterator<T> begin() {
            return LinkedSetIterator<T>(first, this);
    }
        /**
         * Returns an iterator pointing to the element following the last element of the set.
         * @return an iterator pointing past the end of the set
         */
        LinkedSetIterator<T> end() {
            return LinkedSetIterator<T>(nullptr, this);
        }

        // Expose a method to access the first node from the iterator
        Node<T>* getFirstNode() const {
            return first;
        }
private:
    /**
     * class Name: <elementSet>
     *
     * WHAT I CHANGED: <Provides direct access to the underlying unordered_set containing unique elements.>
     *
     * return: <unordered_set<T>&> - reference to the element set
     */
    Node<T>* first; // Pointer to the first node in the linked set
    unordered_set<T> elementSet;
};
#endif /* LinkedSet_hpp */
