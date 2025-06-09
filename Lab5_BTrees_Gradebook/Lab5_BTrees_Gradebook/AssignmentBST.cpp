//
//  AssignmentBST.cpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 5/6/24.
//

#include "AssignmentBST.hpp"
#include <algorithm>


/*******************************************************

 * Function Name: AssignmentBST (constructor)

 * Purpose: Initializes an empty binary search tree for assignments.

 * Parameter: None

 * Return: void

 *******************************************************/
AssignmentBST::AssignmentBST(const AssignmentBST& other) {
    root = cloneNode(other.root);
}

/*******************************************************

 * Function Name: AssignmentBST (move constructor)

 * Purpose: Moves the content of the provided AssignmentBST to the newly constructed AssignmentBST.

 * Parameter:
 * - other: An rvalue reference to another AssignmentBST to be moved.

 * Return: void

 *******************************************************/AssignmentBST::AssignmentBST(AssignmentBST&& other) noexcept {
    root = std::move(other.root);
    other.root = nullptr;
}

/*******************************************************

 * Function Name: operator= (copy assignment)

 * Purpose: Assigns the content of the provided AssignmentBST to this AssignmentBST through deep copy.

 * Parameter:
 * - other: A constant reference to another AssignmentBST to be assigned.

 * Return: AssignmentBST& - Reference to this AssignmentBST after assignment.

 *******************************************************/AssignmentBST& AssignmentBST::operator=(const AssignmentBST& other) {
    if (this != &other) {
        root = cloneNode(other.root);
    }
    return *this;
}

/*******************************************************

 * Function Name: operator= (move assignment)

 * Purpose: Moves the content of the provided AssignmentBST to this AssignmentBST.

 * Parameter:
 * - other: An rvalue reference to another AssignmentBST to be moved.

 * Return: AssignmentBST& - Reference to this AssignmentBST after assignment.

 *******************************************************/AssignmentBST& AssignmentBST::operator=(AssignmentBST&& other) noexcept {
    if (this != &other) {
        root = std::move(other.root);
        other.root = nullptr;
    }
    return *this;
}


/*******************************************************

 * Function Name: insert

 * Purpose: Inserts the provided assignment into the binary search tree.

 * Parameter:
 * - assignment: A constant reference to an Assignment object to be inserted.

 * Return: void

 *******************************************************/
void AssignmentBST::insert(const Assignment& assignment) {
    if (!root){ //empty tree
        root =  std::make_unique<AssignmentNode>(assignment);
    }else{
        insertHelper(root, assignment);
    }
}

/*******************************************************

 * Function Name: searchAssignmentByID

 * Purpose: Searches for an assignment with the specified ID in the binary search tree.

 * Parameter:
 * - assignmentID: An integer representing the ID of the assignment to search for.

 * Return: Assignment* - A pointer to the assignment if found, nullptr otherwise.

 *******************************************************/
// Search for an assignment by its ID
Assignment* AssignmentBST::searchAssignmentByID(int assignmentID) const {
    return searchAssignmentByIDHelper(root, assignmentID);
}

/*******************************************************

 * Function Name: printInorder

 * Purpose: Prints the assignments in the binary search tree in inorder traversal.

 * Parameter: None

 * Return: void
 *******************************************************/
// Print the BST in inorder traversal
void AssignmentBST::printInorder() const {
    int currentGroup = -1;  // Initial value to start with any group
    inorderTraversal(root, currentGroup);
}

/*******************************************************

 * Function Name: inorderTraversal

 * Purpose: Performs an inorder traversal of the binary search tree, printing assignments grouped by categories.

 * Parameter:
 * - node: A constant reference to a unique pointer to an AssignmentNode representing the current node in the traversal.
 * - currentGroup: A reference to an integer representing the current assignment group being processed.

 * Return: void

 *******************************************************/
void AssignmentBST::inorderTraversal(const std::unique_ptr<AssignmentNode>& node, int& currentGroup) const {
    if (!node) {
        return;
    }

    inorderTraversal(node->left, currentGroup);
    
    // If the current node's group is different from the currentGroup, print a separator
    if (node->data.getGroupNum() != currentGroup) {
        cout << endl;  // Add spacing between different groups
        cout << "Group " << node->data.getGroupNum() << ":" << endl;
        currentGroup = node->data.getGroupNum();
    }

    // Print information for the current node
    cout << "  Assignment ID: " << node->data.getId() << ", Description: " << node->data.getDescription() << endl;
    
    inorderTraversal(node->right, currentGroup);
}


/*******************************************************

 * Function Name: remove

 * Purpose: Removes the assignment with the specified ID from the binary search tree.

 * Parameter:
 * - assignmentID: An integer representing the ID of the assignment to remove.

 * Return: bool - True if the assignment was successfully removed, false otherwise.

 *******************************************************/
bool AssignmentBST::remove(int assignmentID) {
    root = removeRecursive(std::move(root), assignmentID);
    return true; // Assuming successful removal
}

/*******************************************************

 * Function Name: removeRecursive

 * Purpose: Recursively removes the assignment with the specified ID from the binary search tree.

 * Parameter:
 * - root: A unique pointer to an AssignmentNode representing the root of the subtree.
 * - assignmentID: An integer representing the ID of the assignment to remove.

 * Return: std::unique_ptr<AssignmentNode> - A unique pointer to the root of the modified subtree after removal.

 *******************************************************/
std::unique_ptr<AssignmentNode> AssignmentBST::removeRecursive(std::unique_ptr<AssignmentNode> root, int assignmentID) {
    if (!root) {
        return nullptr;
    }
    
    if (assignmentID < root->data.getId()) {
        root->left = removeRecursive(std::move(root->left), assignmentID);
    } else if (assignmentID > root->data.getId()) {
        root->right = removeRecursive(std::move(root->right), assignmentID);
    } else {
        // Node with only one child or no child
        if (!root->left) {
            return std::move(root->right);
        } else if (!root->right) {
            return std::move(root->left);
        }
        
        // Node with two children: Get the inorder successor
        std::unique_ptr<AssignmentNode> successor = findMinNode(std::move(root->right));
        root->data = successor->data;
        
        // Remove the inorder successor
        root->right = removeRecursive(std::move(root->right), successor->data.getId());
    }
    return root;
}

/*******************************************************

 * Function Name: findMinNode

 * Purpose: Finds the node with the minimum value in the subtree rooted at the given node.

 * Parameter:
 * - node: A unique pointer to an AssignmentNode representing the root of the subtree.

 * Return: std::unique_ptr<AssignmentNode> - A unique pointer to the node with the minimum value.

 *******************************************************/
std::unique_ptr<AssignmentNode> AssignmentBST::findMinNode(std::unique_ptr<AssignmentNode> node) {
    if (!node->left) {
        return node;
    }
    return findMinNode(std::move(node->left));
}

/*******************************************************

 * Function Name: getAllAssignments

 * Purpose: Retrieves all assignments stored in the binary search tree.

 * Parameter:
 * - allAssignments: A reference to a vector of Assignment objects to store the retrieved assignments.

 * Return: void

 *******************************************************/
void AssignmentBST::getAllAssignments(std::unique_ptr<AssignmentNode>& node, vector<Assignment>& allAssignments){
    if (node != nullptr){
        allAssignments.push_back(node->data);
        
        //call recursive
        getAllAssignments(node->left, allAssignments);
        getAllAssignments(node->right, allAssignments);
    }
}


/*******************************************************

 * Function Name: increaseIDs

 * Purpose: Increases the IDs of all assignments in the binary search tree.

 * Parameter: None

 * Return: void

 *******************************************************/
void AssignmentBST::increaseIDs(std::unique_ptr<AssignmentNode>& node){
    if (node != nullptr){
        node->data.increaseId();
        
        //call recursive
        increaseIDs(node->left);
        increaseIDs(node->right);
    }
}

/*******************************************************

 * Function Name: reduceIDs

 * Purpose: Reduces the IDs of all assignments in the binary search tree starting from the specified ID.

 * Parameter:
 * - currentID: An integer representing the starting ID from which to reduce.

 * Return: void

 *******************************************************/
void AssignmentBST::reduceIDs(std::unique_ptr<AssignmentNode>& node, int currentID){
    if (node != nullptr){
        
        if (node->data.getId() > currentID){
            node->data.reduceId();
        }
        
        //call recursive
        reduceIDs(node->left, currentID);
        reduceIDs(node->right, currentID);
    }
}

/*******************************************************

 * Function Name: save

 * Purpose: Saves the binary search tree to the specified output file stream.

 * Parameter:
 * - file: A reference to an output file stream to which the binary search tree will be saved.

 * Return: void

 *******************************************************/

void AssignmentBST::save(ofstream& file){
    saveHelper(root, file);
}

/*******************************************************

 * Function Name: insertHelper

 * Purpose: Recursively inserts an assignment into the binary search tree.

 * Parameter:
 * - node: A reference to a unique pointer to an AssignmentNode representing the current node in the traversal.
 * - assignment: A constant reference to an Assignment object to be inserted.

 * Return: void

 *******************************************************/
void AssignmentBST::insertHelper(std::unique_ptr<AssignmentNode>& node, const Assignment& assignment) {

    if (assignment.getId() < node->data.getId()) {
        if (node->left == nullptr){
            node->left =std::make_unique<AssignmentNode>(assignment);
        }else{
            insertHelper(node->left, assignment);
        }
    } else if (assignment.getId() > node->data.getId()) {
        if (node->right == nullptr){
            node->right = std::make_unique<AssignmentNode>(assignment);
        }else{
            insertHelper(node->right, assignment);
        }
    } else {
        // Update the assignment if the IDs match
        node->data = assignment;
    }
}

/*******************************************************

 * Function Name: cloneNode

 * Purpose: Recursively clones the subtree rooted at the given node.

 * Parameter:
 * - node: A constant reference to a unique pointer to an AssignmentNode representing the root of the subtree to clone.

 * Return: unique_ptr<AssignmentNode> - A unique pointer to the root of the cloned subtree.

 *******************************************************/
// Helper function to clone a node and its subtree
std::unique_ptr<AssignmentNode> AssignmentBST::cloneNode(const std::unique_ptr<AssignmentNode>& node) const {
    if (!node) {
            return nullptr;
        }
        auto newNode = std::make_unique<AssignmentNode>(node->data);
        newNode->left = cloneNode(node->left);
        newNode->right = cloneNode(node->right);
        return newNode;
    }


/*******************************************************

 * Function Name: saveHelper

 * Purpose: Recursively saves the assignments stored in the subtree rooted at the given node to the specified output file stream.

 * Parameter:
 * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.
 * - file: A reference to an output file stream to which the assignments will be saved.

 * Return: void

 *******************************************************/

void AssignmentBST::saveHelper(std::unique_ptr<AssignmentNode>& node, ofstream& file){
    if (node != nullptr){
        
        //call recursive
        saveHelper(node->left, file);
        
        file << node->data.toCSVFormat() << std::endl;
        
        saveHelper(node->right, file);
    }
}


/*******************************************************

 * Function Name: increaseIDs

 * Purpose: Recursively increases the IDs of all assignments stored in the subtree rooted at the given node.

 * Parameter:
 * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.

 * Return: void

 *******************************************************/
void AssignmentBST::increaseIDs(){
    increaseIDs(root);
}

/*******************************************************

 * Function Name: reduceIDs

 * Purpose: Recursively reduces the IDs of all assignments stored in the subtree rooted at the given node starting from the specified ID.

 * Parameter:
 * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.
 * - currentID: An integer representing the starting ID from which to reduce.

 * Return: void

 *******************************************************/
void AssignmentBST::reduceIDs(int currentID){
    reduceIDs(root, currentID);
}


/*******************************************************

 * Function Name: getAllAssignments

 * Purpose: Recursively retrieves all assignments stored in the subtree rooted at the given node.

 * Parameter:
 * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.
 * - allAssignments: A reference to a vector of Assignment objects to store the retrieved assignments.

 * Return: void

 *******************************************************/

void AssignmentBST::getAllAssignments(vector<Assignment>& allAssignments){
    getAllAssignments(root, allAssignments);
}








// Helper function to search for an assignment recursively
Assignment* AssignmentBST::searchAssignmentByIDHelper(const std::unique_ptr<AssignmentNode>& node, int assignmentID) const {
    
    if (!node) {
                return nullptr;
            }

            if (node->data.getId() == assignmentID) {
                return &node->data;
            } else if (assignmentID < node->data.getId()) {
                return searchAssignmentByIDHelper(node->left, assignmentID);
            } else {
                return searchAssignmentByIDHelper(node->right, assignmentID);
            }
        }








