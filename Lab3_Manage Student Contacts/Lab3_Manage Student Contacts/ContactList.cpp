//
//  ContactList.cpp
//  Lab3_Manage Student Contacts
//
//  Created by Eden Meseret on 3/27/24.
//

#include "ContactList.hpp"

/*******************************************************

 * Function Name: <ContactList>

 * Purpose: <constructor >

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
ContactList::ContactList() : AbstractLinkedList<Contact>() {}

/*******************************************************

 * Function Name: <~ContactList>

 * Purpose: <deconstructor >

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/

ContactList::~ContactList() {
    clear();
}


/*******************************************************

 * Function Name: <sort>

 * Purpose: <Sort the contacts using Selection Sort>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
void ContactList::sort() const {
    Node<Contact>* current = head;
    Node<Contact>* minNode = nullptr;
    Contact temp;

    // Traverse the list
    while (current != nullptr) {
        // Find the minimum node starting from the current node
        minNode = findMiniNode(current);
        
        // Swap the data of current node and the minimum node if they are different
        if (minNode != current) {
            temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }
        
        current = current->next;
    }
}



/*******************************************************

 * Function Name: <displayContacts>

 * Purpose: <Display contact details in the linked list>

 * Parameter: <N/A>

 * Return: <N/A>

 *******************************************************/
void ContactList::displayContacts() const {
    Node<Contact>* current = head;
    
    // Traverse the list and print each contact
    if (isEmpty()) {
        cout << "Empty!\n";
        return;
    }
    cout << setw(6) << "ID" ;
    cout << setw(12) << "First Name";
//    cout << setw(12) << "Middle Name" ;
    cout << setw(12) <<"Last Name" ;
    cout << setw(10) << "Role" ;
    cout << setw(32) << "Company\n" ;
//    cout << setw(24) << "Address" ;
//    cout << setw(12) << "City";
//    cout << setw(12) << "County" ;
//    cout << setw(4) << "State" ;
//    cout << setw(8) << "ZIP"  << endl;
//    //cout << setw(16) << "Primary Phone" ;
//    //cout << setw(16) << "Secondary Phone" ;
    //cout << setw(16) << "Email\n";
    
    while (current) {
        printNode(current);
        current = current->next;
    }
}

void ContactList::printAt(int position) const{
    Node<Contact>* current = head;
            int currentPosition = 1;

            while (current != nullptr && currentPosition < position) {
                current = current->next;
                currentPosition++;
            }

            if (currentPosition == position && current != nullptr) {
                printNodeAt(current);  // Using the printNode function to print the Contact details
            } else {
                cout << "Contact not found at position " << position << ".\n";
            }
}



/*******************************************************

 * Function Name: <append>

 * Purpose: <Append a contact to the end of the list>

 * Parameter: <const Contact& data>

 * Return: <void>

 *******************************************************/
void ContactList::append(const Contact& data) const {
    AbstractLinkedList<Contact>::append(data);
}

/*******************************************************

 * Function Name: <prepend>

 * Purpose: <Prepend a contact to the beginning of the list>

 * Parameter: <const Contact& data>

 * Return: <void>

 *******************************************************/
void ContactList::prepend(const Contact& data) {
    AbstractLinkedList<Contact>::prepend(data);
}


/*******************************************************

 * Function Name: <insertAfter>

 * Purpose: <Insert a contact after a given node>

 * Parameter: <Node<Contact>* preNode, const Contact& data>

 * Return: <void>

 *******************************************************/
void ContactList::insertAfter(Node<Contact>* preNode, const Contact& data) {
    AbstractLinkedList<Contact>::insertAfter(preNode, data);
}

/*******************************************************

 * Function Name: <insertAfter>

 * Purpose: <Remove a contact with a given data>

 * Parameter: <const Contact& data>

 * Return: <void>

 *******************************************************/
void ContactList::remove(const Contact& data) const {
    AbstractLinkedList<Contact>::remove(data);
}


/*******************************************************

 * Function Name: <addContact>

 * Purpose: <Add a contact to the list>

 * Parameter: <const Contact& data>

 * Return: <void>

 *******************************************************/
void ContactList::addContact(const Contact& contact) const {
    Node<Contact>* newNode = new Node<Contact>(contact);

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

/*******************************************************

 * Function Name: <getSize>

 * Purpose: <Get the size of the list>

 * Parameter: <N/A>

 * Return: <int>

 *******************************************************/
int ContactList::getSize() const {
    return AbstractLinkedList<Contact>::getSize();
}


/*******************************************************

 * Function Name: <search>

 * Purpose: <Search for a contact in the list>

 * Parameter: <N/A>

 * Return: <bool>

 *******************************************************/
bool ContactList::search(const Contact& data) const {
    return AbstractLinkedList<Contact>::search(data);
}


/*******************************************************

 * Function Name: <getFirst>

 * Purpose: <Get the first contact in the list>

 * Parameter: <N/A>

 * Return: <Contact>

 *******************************************************/
Contact& ContactList::getFirst() const {
    return AbstractLinkedList<Contact>::getFirst();
}


/*******************************************************

 * Function Name: <getLast>

 * Purpose: < Get the last contact in the list>

 * Parameter: <N/A>

 * Return: <Contact>

 *******************************************************/
Contact& ContactList::getLast() const {
    return AbstractLinkedList<Contact>::getLast();
}


/*******************************************************

 * Function Name: <getAt>

 * Purpose: <Get the contact at a given position in the list>

 * Parameter: < int pos>

 * Return: <Contact>

 *******************************************************/
Contact& ContactList::getAt(int pos) const {
    return AbstractLinkedList<Contact>::getAt(pos);
}


/*******************************************************

 * Function Name: <getAt>

 * Purpose: <Set the contact at a given position in the list>

 * Parameter: < int pos, const Contact& data>

 * Return: <void>

 *******************************************************/
void ContactList::setAt(int pos, const Contact& data) {
    AbstractLinkedList<Contact>::setAt(pos, data);
}


/*******************************************************

 * Function Name: <getAt>

 * Purpose: <Check if the list is empty>

 * Parameter: <>

 * Return: <bool>

 *******************************************************/
bool ContactList::isEmpty() const {
    return AbstractLinkedList<Contact>::isEmpty();
}


/*******************************************************

 * Function Name: <clear>

 * Purpose: <Clear the list>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::clear() {
    AbstractLinkedList<Contact>::clear();
}


/*******************************************************

 * Function Name: <reverse>

 * Purpose: <Reverse the list>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::reverse() const {
    AbstractLinkedList<Contact>::reverse();
}


/*******************************************************

 * Function Name: <sortByFirstName>

 * Purpose: <Sort the list by first name>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::sortByFirstName() const {
    for (Node<Contact>* i = head; i != nullptr; i = i->next) {
        Node<Contact>* min = i;
        for (Node<Contact>* j = i->next; j != nullptr; j = j->next) {
            if (min->data.getFirstName() > j->data.getFirstName()) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}


/*******************************************************

 * Function Name: <sortByMiddleName>

 * Purpose: <Sort the list by middle name>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::sortByMiddleName() const {
    for (Node<Contact>* i = head; i != nullptr; i = i->next) {
        Node<Contact>* min = i;
        for (Node<Contact>* j = i->next; j != nullptr; j = j->next) {
            // Handle empty middle names by placing them at the end
            if (min->data.getMiddleName().empty() && !j->data.getMiddleName().empty()) {
                min = j;
            } else if (!min->data.getMiddleName().empty() && !j->data.getMiddleName().empty()) {
                if (min->data.getMiddleName() > j->data.getMiddleName()) {
                    min = j;
                }
            } else if (min->data.getMiddleName().empty() && j->data.getMiddleName().empty()) {
                // If both middle names are empty, keep the order as is
                if (min->data.getMiddleName() > j->data.getMiddleName()) {
                    min = j;
                }
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}


/*******************************************************

 * Function Name: <sortByLastName>

 * Purpose: <Sort the list by last name>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::sortByLastName() const {
    for (Node<Contact>* i = head; i != nullptr; i = i->next) {
        Node<Contact>* min = i;
        for (Node<Contact>* j = i->next; j != nullptr; j = j->next) {
            if (min->data.getLastName() > j->data.getLastName()) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}


/*******************************************************

 * Function Name: <sortByAddress>

 * Purpose: <Sort the list by address>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::sortByAddress() const {
    for (Node<Contact>* i = head; i != nullptr; i = i->next) {
        Node<Contact>* min = i;
        for (Node<Contact>* j = i->next; j != nullptr; j = j->next) {
            if (min->data.getAddress() > j->data.getAddress()) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}

/*******************************************************

 * Function Name: <sortByPrimaryPhone>

 * Purpose: <Sort the list by primary phone number>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::sortByPrimaryPhone() const {
    for (Node<Contact>* i = head; i != nullptr; i = i->next) {
        Node<Contact>* min = i;
        for (Node<Contact>* j = i->next; j != nullptr; j = j->next) {
            if (min->data.getPrimaryPhone() > j->data.getPrimaryPhone()) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}


/*******************************************************

 * Function Name: <sortByPrimaryPhone>

 * Purpose: <Sort the list by secondary phone number>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::sortBySecondaryPhone() const {
    for (Node<Contact>* i = head; i != nullptr; i = i->next) {
        Node<Contact>* min = i;
        for (Node<Contact>* j = i->next; j != nullptr; j = j->next) {
            if (min->data.getSecondaryPhone() > j->data.getSecondaryPhone()) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}


/*******************************************************

 * Function Name: <sortByEmail>

 * Purpose: <Sort the list by email>

 * Parameter: <>

 * Return: <void>

 *******************************************************/
void ContactList::sortByEmail() const {
    for (Node<Contact>* i = head; i != nullptr; i = i->next) {
        Node<Contact>* min = i;
        for (Node<Contact>* j = i->next; j != nullptr; j = j->next) {
            if (min->data.getEmail() > j->data.getEmail()) {
                min = j;
            }
        }
        if (min != i) {
            swap(i->data, min->data);
        }
    }
}


/*******************************************************

 * Function Name: <printNodeAt>

 * Purpose: <Find the node with the minimum contact data starting from a given node>

 * Parameter: <Node<Contact>* start>

 * Return: <Node<Contact>* ContactList>

 *******************************************************/
void ContactList::printNodeAt(Node<Contact>* node) const {
    cout << "ID: " << node->data.getId() << "\n";
    cout << "First Name: " << node->data.getFirstName() << "\n";
    cout << "Middle Name: " << node->data.getMiddleName() << "\n";
    cout << "Last Name: " << node->data.getLastName() << "\n";
    cout << "Role: " << node->data.getRole() << "\n";
    cout << "Company: " << node->data.getCompany() << "\n";
    cout << "Address: " << node->data.getAddress() << "\n";
    cout << "City: " << node->data.getCity() << "\n";
    cout << "County: " << node->data.getCounty() << "\n";
    cout << "State: " << node->data.getState() << "\n";
    cout << "ZIP: " << node->data.getZip() << "\n";
    cout << "Primary Phone: " << node->data.getPrimaryPhone() << "\n";
    cout << "Secondary Phone: " << node->data.getSecondaryPhone() << "\n";
    cout << "Email: " << node->data.getEmail() << "\n";
}

/*******************************************************

 * Function Name: <findMiniNode>

 * Purpose: <Find the node with the minimum contact data starting from a given node>

 * Parameter: <Node<Contact>* start>

 * Return: <Node<Contact>* ContactList>

 *******************************************************/
Node<Contact>* ContactList::findMiniNode(Node<Contact>* start) const {
    Node<Contact>* minNode = start;
    Node<Contact>* current = start->next;
    
    // Traverse the list to find the minimum node
    while(current != nullptr) {
        if(current->data.getId() < minNode->data.getId()) {
            minNode = current;
        }
        current = current->next;
    }
    return minNode;
}


/*******************************************************

 * Function Name: <moveFirst>

 * Purpose: <move to first contact>

 * Parameter: <>

 * Return: <>

 *******************************************************/

void ContactList::moveFirst() {
        current = getHead();
    }


/*******************************************************

 * Function Name: <moveNext>

 * Purpose: <move to next contact>

 * Parameter: <>

 * Return: <>

 *******************************************************/
void ContactList::moveNext() {
        if (current != nullptr) {
            current = current->next;
        }
    }

/*******************************************************

 * Function Name: <movePrevious>

 * Purpose: <move to previous contact>

 * Parameter: <>

 * Return: <>

 *******************************************************/
void ContactList::movePrevious() {
        // Since it's a singly linked list, moving previous will iterate from the head
        Node<Contact>* temp = head;
        while (temp != nullptr && temp->next != current) {
            temp = temp->next;
        }
        current = temp;
    }

/*******************************************************

 * Function Name: <moveLast>

 * Purpose: <move to last contact>

 * Parameter: <>

 * Return: <>

 *******************************************************/
void ContactList::moveLast() {
       current = tail;
   }

/*******************************************************

 * Function Name: <printNode>

 * Purpose: <prefix increment>

 * Parameter: <>

 * Return: <>

 *******************************************************/
    ContactList& ContactList::operator++() {
        moveNext();
        return *this;
    }

/*******************************************************

 * Function Name: <printNode>

 * Purpose: <postfix increment>

 * Parameter: <>

 * Return: <>

 *******************************************************/
    ContactList ContactList::operator++(int) {
        ContactList temp = *this;
        moveNext();
        return temp;
    }


/*******************************************************

 * Function Name: <printNode>

 * Purpose: <prefix decrement>

 * Parameter: <>

 * Return: <>

 *******************************************************/
    ContactList& ContactList::operator--() {
        movePrevious();
        return *this;
    }

/*******************************************************

 * Function Name: <printNode>

 * Purpose: <postfix decrement>

 * Parameter: <>

 * Return: <>

 *******************************************************/
    ContactList ContactList::operator--(int) {
        ContactList temp = *this;
        movePrevious();
        return temp;
    }


/*******************************************************

 * Function Name: <getCurrent>

 * Purpose: <display current node>

 * Parameter: <>

 * Return: <>

 *******************************************************/
Contact& ContactList::getCurrent() const {
       if (current != nullptr) {
           return current->data;
       }
       throw std::out_of_range("No current contact");
   }



/*******************************************************

 * Function Name: <printNode>

 * Purpose: <Override the function to print elements in a node>

 * Parameter: <>

 * Return: <>

 *******************************************************/
void ContactList::printNode(Node<Contact>* node) const {
    cout << node->data << endl;
}
