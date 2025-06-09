//
//  AbstractLinkedList.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/27/24.
//

#ifndef AbstractLinkedList_hpp
#define AbstractLinkedList_hpp
#include "Node.hpp"
#include <iostream>


/**
 * AbstractLinkedList: A generic abstract class representing a linked list.
 * This class provides a basic framework for a linked list and declares
 * pure virtual functions to be implemented by derived classes.
 *
 * @tparam T The type of data stored in the linked list.
 */
using namespace std;
template <typename T>

class AbstractLinkedList{
    
public:
    // Constructors and Destructor
    AbstractLinkedList(); //Default constructor
    virtual ~AbstractLinkedList(); //Destructor
    AbstractLinkedList(const AbstractLinkedList& other); //Copy constructor
    
    //headers and getters
    Node<T>* getHead() const;
    Node<T>* getTail() const;
    void setHead(Node<T>* newHead) const;
    void setTail(Node<T>* newTail) const;


      // Insertion and Deletion
      virtual void append(const T& data) const; // append a new node to end of the list
      virtual void prepend(const T& data); // prepend a new node to end of the list
      virtual void insertAfter(Node<T>* preNode, const T& data) = 0; // pure virtual function to insert a node after a given node
      virtual void remove(const T& data) const = 0;// pure virtual function to remove a node with given data from the list

      // Display and Traversal
      virtual void display() const; // Display all elements in the list
      virtual int getSize() const; // Get the number of elements in the list
      virtual bool search(const T& data) const; // Search for a specific element in the list
//      virtual void printNodeAt(int pos, Node<T>* node) = 0; // Pure virtual function to print the node at a given position
 
      // Accessors and Modifiers
      virtual T& getFirst() const; // Get the first element of the list
      virtual T& getLast() const; // Get the last element of the list
      virtual T& getAt(int pos) const; // Get the element at a specific position in the list
      virtual void setAt(int pos, const T& data); // Set the element at a specific position in the list
      virtual void sort() const = 0; // Pure virtual function for sorting the list
 
      // Misc functions
      virtual bool isEmpty() const; // Check if the list is empty
      virtual void clear(); // Remove all elements from the list
      virtual void reverse() const; // Reverse the list

      // Overloaded operators
      AbstractLinkedList& operator=(const AbstractLinkedList& other); // Assignment operator
      bool operator==(const AbstractLinkedList& other) const; // Equality operator
      bool operator!=(const AbstractLinkedList& other) const; // Inequality operator
      AbstractLinkedList<T> operator+(const AbstractLinkedList& other) const; // Addition operator to concatenate two lists
      AbstractLinkedList<T> operator-(const AbstractLinkedList& other) const; // Subtraction operator to subtract elements of other list from this list
      virtual T& operator[](int pos) const; // Get the element at a specific position in the list using []
    
    
    
protected: //private??
    mutable Node<T>* head; // pointer to the first node
    mutable Node<T>* tail; // pointer to the last node
    Node<T>* current;  // Pointer to the current node in the list
};

/*******************************************************

 * Function Name: <AbstractLinkedList>

 * Purpose: <constructo>

 * Parameter: <N/A>

 * Return: <AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
AbstractLinkedList<T>::AbstractLinkedList() : head(nullptr), tail(nullptr) {}

/*******************************************************

 * Function Name: <~AbstractLinkedList>

 * Purpose: <deconstructo>

 * Parameter: <N/A>

 * Return: <AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
AbstractLinkedList<T>::~AbstractLinkedList() {
    clear();  // Calls the clear method to delete all nodes
}


/*******************************************************

 * Function Name: <AbstractLinkedList>

 * Purpose: <copy constructor>

 * Parameter: <const AbstractLinkedList& other>

 * Return: <AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
AbstractLinkedList<T>::AbstractLinkedList(const AbstractLinkedList& other) : head(nullptr), tail(nullptr) {
    Node<T>* current = other.head;
    while (current) {
        append(current->data);  // Appends data from other list to the new list
        current = current->next;
    }
}

// Getters

/*******************************************************

 * Function Name: <getHead>

 * Purpose: <getter>

 * Parameter: <>

 * Return: <Node<T>* AbstractLinkedList<T>>

 *******************************************************/
template<typename T>
Node<T>* AbstractLinkedList<T>::getHead() const {
    return head;  // Returns the head node
}


/*******************************************************

 * Function Name: <getTail>

 * Purpose: <getter>

 * Parameter: <>

 * Return: <Node<T>* AbstractLinkedList<T>>

 *******************************************************/
template<typename T>
Node<T>* AbstractLinkedList<T>::getTail() const {
    return tail;  // Returns the tail node
}

// Setters

/*******************************************************

 * Function Name: <setHead>

 * Purpose: <setter>

 * Parameter: <Node<T>* newHead>

 * Return: <Node<T>* AbstractLinkedList<T>>

 *******************************************************/
template<typename T>
void AbstractLinkedList<T>::setHead(Node<T>* newHead) const {
    head = newHead;  // Sets the head node
}

/*******************************************************

 * Function Name: <setTail>

 * Purpose: <setter>

 * Parameter: <Node<T>* newTail>

 * Return: <Node<T>* AbstractLinkedList<T>>

 *******************************************************/
template<typename T>
void AbstractLinkedList<T>::setTail(Node<T>* newTail) const {
    tail = newTail;  // Sets the tail node
}

// Insertion and Deletion

/*******************************************************

 * Function Name: <append>

 * Purpose: <Appends a node to the end of the list>

 * Parameter: <const T& datal>

 * Return: <Node<T>* AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
void AbstractLinkedList<T>::append(const T& data) const {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = tail = newNode;  // If the list is empty, the new node becomes both head and tail
    } else {
        tail->next = newNode;  // Appends the new node to the end of the list
        tail = newNode;
    }
}


/*******************************************************

 * Function Name: <prepend>

 * Purpose: <Prepends a node to the beginning of the list>

 * Parameter: <const T& datal>

 * Return: <void>

 *******************************************************/
template <typename T>
void AbstractLinkedList<T>::prepend(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = tail = newNode;  // If the list is empty, the new node becomes both head and tail
    } else {
        newNode->next = head;  // Inserts the new node at the beginning of the list
        head = newNode;
    }
}

/*******************************************************

 * Function Name: <insertAfter>

 * Purpose: <Inserts a node after a given node>

 * Parameter: <const T& datal>

 * Return: <void>

 *******************************************************/
template <typename T>
void AbstractLinkedList<T>::insertAfter(Node<T>* preNode, const T& data) {
    if (!preNode) {
        throw std::invalid_argument("Previous node cannot be null");
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->next = preNode->next;  // Inserts the new node after the given node
    preNode->next = newNode;

    if (preNode == tail) {
        tail = newNode;  // Updates the tail if the new node is inserted after the current tail
    }
}


/*******************************************************

 * Function Name: <remove>

 * Purpose: <Removes a node with a given data>

 * Parameter: <const T& datal>

 * Return: <void>

 *******************************************************/
template <typename T>
void AbstractLinkedList<T>::remove(const T& data) const {
    Node<T>* current = head;
    Node<T>* prev = nullptr;

    while (current) {
        if (current->data == data) {
            if (prev) {
                prev->next = current->next;  // Removes the current node from the list
            } else {
                head = current->next;
            }

            if (current == tail) {
                tail = prev;  // Updates the tail if the current node is the tail
            }

            delete current;  // Deletes the current node
            return;
        }

        prev = current;
        current = current->next;
    }

    throw std::runtime_error("Data not found in the list");  // Throws an exception if the data is not found
}


// Display and Traversal
/*******************************************************

 * Function Name: <display>

 * Purpose: <displays nodes>

 * Parameter: <const T& datal>

 * Return: <void>

 *******************************************************/
template <typename T>
void AbstractLinkedList<T>::display() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";  // Prints the data of each node
        current = current->next;
    }
    std::cout << std::endl;
}


/*******************************************************

 * Function Name: <getSize>

 * Purpose: <gets size of linked list>

 * Parameter: <const T& datal>

 * Return: <void>

 *******************************************************/
template <typename T>
int AbstractLinkedList<T>::getSize() const {
    int count = 0;
    Node<T>* current = head;
    while (current) {
        count++;  // Counts the number of nodes in the list
        current = current->next;
    }
    return count;
}


/*******************************************************

 * Function Name: <search>

 * Purpose: <searched for data in linked list>

 * Parameter: <const T& datal>

 * Return: <bool>

 *******************************************************/
template <typename T>
bool AbstractLinkedList<T>::search(const T& data) const {
    Node<T>* current = head;
    while (current) {
        if (current->data == data) {
            return true;  // Returns true if the data is found in the list
        }
        current = current->next;
    }
    return false;  // Returns false if the data is not found in the list
}

// Accessors and Modifiers

/*******************************************************

 * Function Name: <getFirst>

 * Purpose: <gets data of first node in list>

 * Parameter: <const T& datal>

 * Return: <T& AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
T& AbstractLinkedList<T>::getFirst() const {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }
    return head->data;  // Returns the data of the first node
}


/*******************************************************

 * Function Name: <getLast>

 * Purpose: <gets data of last node in list>

 * Parameter: <const T& datal>

 * Return: <T& AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
T& AbstractLinkedList<T>::getLast() const {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;  // Returns the data of the last node
}


/*******************************************************

 * Function Name: <getAt>

 * Purpose: <gets data of node at pos in list>

 * Parameter: <int pos>

 * Return: <T& AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
T& AbstractLinkedList<T>::getAt(int pos) const {
    if (pos < 0 || pos >= getSize()) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;
    for (int i = 0; i < pos; i++) {
        current = current->next;  // Traverses the list to find the node at the given position
    }
    return current->data;
}


/*******************************************************

 * Function Name: <setAt>

 * Purpose: <sets data at position in list>

 * Parameter: <int pos, const T& data>

 * Return: <T& AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
void AbstractLinkedList<T>::setAt(int pos, const T& data) {
    if (pos < 0 || pos >= getSize()) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;
    for (int i = 0; i < pos; i++) {
        current = current->next;  // Traverses the list to find the node at the given position
    }
    current->data = data;  // Sets the data of the node at the given position
}

// Misc functions

/*******************************************************

 * Function Name: <isEmpty>

 * Purpose: <check if list is empty>

 * Parameter: <int pos, const T& data>

 * Return: <T& AbstractLinkedList<T>>

 *******************************************************/
template <typename T>
bool AbstractLinkedList<T>::isEmpty() const {
    return head == nullptr;  // Returns true if the list is empty
}

/*******************************************************

 * Function Name: <clear>

 * Purpose: <deletes all nodes in list>

 * Parameter: <>

 * Return: <void>

 *******************************************************/

template <typename T>
void AbstractLinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;  // Deletes all nodes in the list
        delete temp;
    }
    tail = nullptr;
}

/*******************************************************

 * Function Name: <reverse>

 * Purpose: <reverses list>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
template <typename T>
void AbstractLinkedList<T>::reverse() const {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;  // Reverses the list
        prev = current;
        current = next;
    }

    tail = head;
    head = prev;
}


// Overloaded operators
/*******************************************************

 * Function Name: <operator = >

 * Purpose: <Assignment operator >

 * Parameter: <const AbstractLinkedList& other>

 * Return: <void>

 *******************************************************/
template <typename T>
AbstractLinkedList<T>& AbstractLinkedList<T>::operator=(const AbstractLinkedList& other) {
    if (this != &other) {
        clear();  // Clears the current list
        Node<T>* current = other.head;
        while (current) {
            append(current->data);  // Appends data from other list to the current list
            current = current->next;
        }
    }
    return *this;
}

/*******************************************************

 * Function Name: <operator == >

 * Purpose: <equal to operator >

 * Parameter: <const AbstractLinkedList& other>

 * Return: <void>

 *******************************************************/
template <typename T>
bool AbstractLinkedList<T>::operator==(const AbstractLinkedList& other) const {
    if (getSize() != other.getSize()) {
        return false;
    }

    Node<T>* current1 = head;
    Node<T>* current2 = other.head;
    while (current1 && current2) {
        if (current1->data != current2->data) {
            return false;  // Compares each node of the two lists
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}


/*******************************************************

 * Function Name: <operator != >

 * Purpose: <Inequality operator >

 * Parameter: <const AbstractLinkedList& other>

 * Return: <bool>

 *******************************************************/
template <typename T>
bool AbstractLinkedList<T>::operator!=(const AbstractLinkedList& other) const {
    return !(*this == other);  // Returns the negation of the equality operator
}


/*******************************************************

 * Function Name: <operator + >

 * Purpose: <addition operator >

 * Parameter: <const AbstractLinkedList& other>

 * Return: <bool>

 *******************************************************/

template <typename T>
AbstractLinkedList<T> AbstractLinkedList<T>::operator+(const AbstractLinkedList& other) const {
    AbstractLinkedList<T> newList(*this);  // Copies the current list
    Node<T>* current = other.head;
    while (current) {
        newList.append(current->data);  // Appends data from other list to the new list
        current = current->next;
    }
    return newList;
}

/*******************************************************

 * Function Name: <operator + >

 * Purpose: <subtraction operator >

 * Parameter: <const AbstractLinkedList& other>

 * Return: <bool>

 *******************************************************/
template <typename T>
AbstractLinkedList<T> AbstractLinkedList<T>::operator-(const AbstractLinkedList& other) const {
    AbstractLinkedList<T> newList;
    Node<T>* current = head;
    while (current) {
        if (!other.search(current->data)) {
            newList.append(current->data);  // Creates a new list with elements that are not in the other list
        }
        current = current->next;
    }
    return newList;
}

/*******************************************************

 * Function Name: < operator [] >

 * Purpose: <indexing operator >

 * Parameter: <const AbstractLinkedList& other>

 * Return: <bool>

 *******************************************************/
template <typename T>
T& AbstractLinkedList<T>::operator[](int pos) const {
    return getAt(pos);  // Returns the data of the node at the given position
}

#endif /* AbstractLinkedList_hpp */
