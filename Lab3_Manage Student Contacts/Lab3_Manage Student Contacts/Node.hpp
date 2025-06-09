//
//  Node.hpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/27/24.
//

#ifndef Node_hpp
#define Node_hpp
template <typename T>
class Node{
public:
    // Constructor for the Node class.
    // Initializes the node with given data and sets the next pointer to nullptr by default.
    Node(const T& data, Node<T>* next = nullptr);
    
    T data;          // Contains the data of the node.
    Node<T>* next;   // Pointer to the next node.
};


/*******************************************************

 * Function Name: <Node>

 * Purpose: <Initializes the node with given data and next node pointer.>

 * Parameter: <const T& data, Node<T>* next>

 * Return: <Node<T>>

 *******************************************************/
template <typename T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next){}

#endif /* Node_hpp */
