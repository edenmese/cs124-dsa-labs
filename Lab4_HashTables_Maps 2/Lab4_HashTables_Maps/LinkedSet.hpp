//
//  LinkedSet.hpp
//  Lab4_HashTables_Maps
//
//  Created by Eden Meseret on 5/16/24.
//

#ifndef LinkedSet_hpp
#define LinkedSet_hpp
#include <stdexcept>


/***********************************************************

 * Summary: Implementation of LinkedSet and TaskList classes.
 *          LinkedSet represents a set data structure with
 *          unique elements, providing operations like add,
 *          remove, and isEmpty. TaskList extends LinkedSet
 *          to manage a list of tasks, offering functions
 *          for task manipulation such as adding, editing,
 *          and deleting tasks.
 *
 * Changes from LinkedStack to LinkedSet:
 *  - Altered functionality to fit a set data structure.
 *  - Replaced stack-specific methods (push, pop, top) with
 *    set-specific methods (add, remove, isEmpty).
 *  - Adapted methods to maintain a set of unique elements
 *    instead of a stack's LIFO behavior.
 *
 ************************************************************/
template <typename T>
class LinkedSetNode {
public:
    T info;
    LinkedSetNode<T>* link = nullptr;
};

template <typename T>
class LinkedSet {
public:
    /*******************************************************

    Function Name: LinkedSet

    WHAT I CHANGED: Constructor of the LinkedSet class.

    Parameter: None

    Return: None

    *******************************************************/
    LinkedSet();

    /*******************************************************

    Function Name: ~LinkedSet

    WHAT I CHANGED: Destructor of the LinkedSet class.

    Parameter: None

    Return: None

    *******************************************************/
    ~LinkedSet();

    /*******************************************************

    Function Name: isEmpty

    WHAT I CHANGED: Checks if the set is empty.

    Parameter: None

    Return: bool - true if the set is empty, false otherwise.

    *******************************************************/
    bool isEmpty() const;

    /*******************************************************

    Function Name: add

    WHAT I CHANGED: Adds a new item to the set.

    Parameter: newItem - The item to add to the set.

    Return: None

    *******************************************************/
    void add(const T& newItem);

    /*******************************************************

    Function Name: remove

    WHAT I CHANGED: Removes an item from the set.

    Parameter: item - The item to remove from the set.

    Return: None

    *******************************************************/
    void remove(const T& item);


    /*******************************************************

    Function Name: contains

    WHAT I CHANGED: Checks if the specified item exists in the set.

    Parameter: item - The item to check for existence in the set.

    Return: bool - true if the item exists in the set, false otherwise.

    *******************************************************/
    bool contains(const T& item) const;
    
    /*******************************************************

    Function Name: getSetHead

    WHAT I CHANGED: Retrieves the head pointer of the set.

    Parameter: None

    Return: LinkedSetNode<T>* - Pointer to the head of the set.

    *******************************************************/
    LinkedSetNode<T>* getSetHead() const {
            return setHead;
        }
    /*******************************************************

    Function Name: getTop

    WHAT I CHANGED: Retrieves the top element of the set.

    Parameter: None

    Return: T& - Reference to the top element of the set.

    Throws: std::runtime_error - If the set is empty.

    *******************************************************/
    T& getTop() const {
            if (isEmpty()) {
                // Handle the case where the set is empty
                throw std::runtime_error("Error: The set is empty.");
            }
            return setHead->info;
        }

private:
    /*******************************************************

    Member Variable: setHead

    WHAT I CHANGED: Pointer to the head of the set.

    *******************************************************/
    LinkedSetNode<T>* setHead; // Pointer to the head of the set

    /*******************************************************

    Function Name: destroySet

    WHAT I CHANGED: Helper function to deallocate memory used by the set.

    Parameter: None

    Return: None

    *******************************************************/
    void destroySet();
};

/*******************************************************

Function Name: LinkedSet

WHAT I CHANGED: Constructor of the LinkedSet class.

Parameter: None

Return: None

*******************************************************/
template <typename T>
LinkedSet<T>::LinkedSet() {
    setHead = nullptr;
}

/*******************************************************

Function Name: ~LinkedSet

WHAT I CHANGED: Destructor of the LinkedSet class.

Parameter: None

Return: None

*******************************************************/
template <typename T>
LinkedSet<T>::~LinkedSet() {
    destroySet();
}

/*******************************************************

Function Name: isEmpty

WHAT I CHANGED: Checks if the set is empty.

Parameter: None

Return: bool - true if the set is empty, false otherwise.

*******************************************************/
template <typename T>
bool LinkedSet<T>::isEmpty() const {
    return (setHead == nullptr);
}

/*******************************************************

Function Name: add

WHAT I CHANGED: Adds a new item to the set if it doesn't already exist.

Parameter: newItem - The item to add to the set.

Return: None

*******************************************************/
template <typename T>
void LinkedSet<T>::add(const T& newItem) {
    if (!contains(newItem)) {
        LinkedSetNode<T>* newNode = new LinkedSetNode<T>;
        newNode->info = newItem;
        newNode->link = setHead;
        setHead = newNode;
    }
}


/*******************************************************

Function Name: remove

WHAT I CHANGED: Removes the specified item from the set if it exists.

Parameter: item - The item to remove from the set.

Return: None

*******************************************************/
template <typename T>
void LinkedSet<T>::remove(const T& item) {
    LinkedSetNode<T>* current = setHead;
    LinkedSetNode<T>* previous = nullptr;

    while (current != nullptr) {
        if (current->info == item) {
            if (previous != nullptr) {
                previous->link = current->link;
            } else {
                setHead = current->link;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->link;
    }
}

/*******************************************************

Function Name: contains

WHAT I CHANGED: Checks if the specified item exists in the set.

Parameter: item - The item to check for existence in the set.

Return: bool - true if the item exists in the set, false otherwise.

*******************************************************/
template <typename T>
bool LinkedSet<T>::contains(const T& item) const {
    LinkedSetNode<T>* current = setHead;
    while (current != nullptr) {
        if (current->info == item) {
            return true;
        }
        current = current->link;
    }
    return false;
}

/*******************************************************

Function Name: destroySet

WHAT I CHANGED: Helper function to deallocate memory used by the set.

Parameter: None

Return: None

*******************************************************/
template <typename T>
void LinkedSet<T>::destroySet() {
    LinkedSetNode<T>* temp;
    while (setHead != nullptr) {
        temp = setHead;
        setHead = setHead->link;
        delete temp;
    }
}

#endif /* LinkedSet_hpp */
