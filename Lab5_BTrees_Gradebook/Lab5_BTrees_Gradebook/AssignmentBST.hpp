//
//  AssignmentBST.hpp
//  Lab5_BTrees_Gradebook
//
//  Created by Eden Meseret on 5/6/24.
//

#ifndef AssignmentBST_hpp
#define AssignmentBST_hpp

#include "Assignment.hpp"
#include <vector>
#include <memory>
#include <fstream>

struct AssignmentNode {
    Assignment data;
    std::unique_ptr<AssignmentNode> left;
    std::unique_ptr<AssignmentNode> right;

    AssignmentNode(const Assignment& assignment)
        : data(assignment) {}
};

class AssignmentBST {
public:
    /*******************************************************

     * Function Name: AssignmentBST (constructor)

     * Purpose: Initializes an empty binary search tree for assignments.

     * Parameter: None

     * Return: void

     *******************************************************/
    AssignmentBST() : root(nullptr) {}

    /*******************************************************

     * Function Name: ~AssignmentBST (destructor)

     * Purpose: Destroys the binary search tree for assignments.

     * Parameter: None

     * Return: void

     *******************************************************/
    ~AssignmentBST() {}

    /*******************************************************

     * Function Name: AssignmentBST (copy constructor)

     * Purpose: Creates a deep copy of the provided AssignmentBST.

     * Parameter:
     * - other: A constant reference to another AssignmentBST to be copied.

     * Return: void

     *******************************************************/
    AssignmentBST(const AssignmentBST& other);

    /*******************************************************

     * Function Name: AssignmentBST (move constructor)

     * Purpose: Moves the content of the provided AssignmentBST to the newly constructed AssignmentBST.

     * Parameter:
     * - other: An rvalue reference to another AssignmentBST to be moved.

     * Return: void

     *******************************************************/
    AssignmentBST(AssignmentBST&& other) noexcept;

    /*******************************************************

     * Function Name: operator= (copy assignment)

     * Purpose: Assigns the content of the provided AssignmentBST to this AssignmentBST through deep copy.

     * Parameter:
     * - other: A constant reference to another AssignmentBST to be assigned.

     * Return: AssignmentBST& - Reference to this AssignmentBST after assignment.

     *******************************************************/
    AssignmentBST& operator=(const AssignmentBST& other);

    /*******************************************************

     * Function Name: operator= (move assignment)

     * Purpose: Moves the content of the provided AssignmentBST to this AssignmentBST.

     * Parameter:
     * - other: An rvalue reference to another AssignmentBST to be moved.

     * Return: AssignmentBST& - Reference to this AssignmentBST after assignment.

     *******************************************************/
    AssignmentBST& operator=(AssignmentBST&& other) noexcept;
    
    
    
    /*******************************************************

     * Function Name: insert

     * Purpose: Inserts the provided assignment into the binary search tree.

     * Parameter:
     * - assignment: A constant reference to an Assignment object to be inserted.

     * Return: void

     *******************************************************/
    void insert(const Assignment& assignment);

    /*******************************************************

     * Function Name: searchAssignmentByID

     * Purpose: Searches for an assignment with the specified ID in the binary search tree.

     * Parameter:
     * - assignmentID: An integer representing the ID of the assignment to search for.

     * Return: Assignment* - A pointer to the assignment if found, nullptr otherwise.

     *******************************************************/
    Assignment* searchAssignmentByID(int assignmentID) const;

    /*******************************************************

     * Function Name: printInorder

     * Purpose: Prints the assignments in the binary search tree in inorder traversal.

     * Parameter: None

     * Return: void

     *******************************************************/
    void printInorder() const;

    /*******************************************************

     * Function Name: inorderTraversal

     * Purpose: Performs an inorder traversal of the binary search tree, printing assignments grouped by categories.

     * Parameter:
     * - node: A constant reference to a unique pointer to an AssignmentNode representing the current node in the traversal.
     * - currentGroup: A reference to an integer representing the current assignment group being processed.

     * Return: void

     *******************************************************/
    void inorderTraversal(const std::unique_ptr<AssignmentNode>& node, int& currentGroup) const;
    
    
    /*******************************************************

     * Function Name: remove

     * Purpose: Removes the assignment with the specified ID from the binary search tree.

     * Parameter:
     * - assignmentID: An integer representing the ID of the assignment to remove.

     * Return: bool - True if the assignment was successfully removed, false otherwise.

     *******************************************************/
    bool remove(int assignmentID);

    /*******************************************************

     * Function Name: removeRecursive

     * Purpose: Recursively removes the assignment with the specified ID from the binary search tree.

     * Parameter:
     * - root: A unique pointer to an AssignmentNode representing the root of the subtree.
     * - assignmentID: An integer representing the ID of the assignment to remove.

     * Return: std::unique_ptr<AssignmentNode> - A unique pointer to the root of the modified subtree after removal.

     *******************************************************/
    std::unique_ptr<AssignmentNode> removeRecursive(std::unique_ptr<AssignmentNode> root, int assignmentID);

    /*******************************************************

     * Function Name: findMinNode

     * Purpose: Finds the node with the minimum value in the subtree rooted at the given node.

     * Parameter:
     * - node: A unique pointer to an AssignmentNode representing the root of the subtree.

     * Return: std::unique_ptr<AssignmentNode> - A unique pointer to the node with the minimum value.

     *******************************************************/
    std::unique_ptr<AssignmentNode> findMinNode(std::unique_ptr<AssignmentNode> node);

    /*******************************************************

     * Function Name: getAllAssignments

     * Purpose: Retrieves all assignments stored in the binary search tree.

     * Parameter:
     * - allAssignments: A reference to a vector of Assignment objects to store the retrieved assignments.

     * Return: void

     *******************************************************/
    void getAllAssignments(vector<Assignment>& allAssignments);

    /*******************************************************

     * Function Name: increaseIDs

     * Purpose: Increases the IDs of all assignments in the binary search tree.

     * Parameter: None

     * Return: void

     *******************************************************/
    void increaseIDs();

    /*******************************************************

     * Function Name: reduceIDs

     * Purpose: Reduces the IDs of all assignments in the binary search tree starting from the specified ID.

     * Parameter:
     * - currentID: An integer representing the starting ID from which to reduce.

     * Return: void

     *******************************************************/
    void reduceIDs(int currentID);

    /*******************************************************

     * Function Name: save

     * Purpose: Saves the binary search tree to the specified output file stream.

     * Parameter:
     * - file: A reference to an output file stream to which the binary search tree will be saved.

     * Return: void

     *******************************************************/
    void save(ofstream& file);
private:
    std::unique_ptr<AssignmentNode> root;
    
    
    /*******************************************************

     * Function Name: insertHelper

     * Purpose: Recursively inserts an assignment into the binary search tree.

     * Parameter:
     * - node: A reference to a unique pointer to an AssignmentNode representing the current node in the traversal.
     * - assignment: A constant reference to an Assignment object to be inserted.

     * Return: void

     *******************************************************/
    void insertHelper(std::unique_ptr<AssignmentNode>& node, const Assignment& assignment);
    
    
    Assignment* searchAssignmentByIDHelper(const unique_ptr<AssignmentNode>& node, int assignmentID) const;
    
    /*******************************************************

     * Function Name: cloneNode

     * Purpose: Recursively clones the subtree rooted at the given node.

     * Parameter:
     * - node: A constant reference to a unique pointer to an AssignmentNode representing the root of the subtree to clone.

     * Return: unique_ptr<AssignmentNode> - A unique pointer to the root of the cloned subtree.

     *******************************************************/
    unique_ptr<AssignmentNode> cloneNode(const unique_ptr<AssignmentNode>& node) const;
    
    /*******************************************************

     * Function Name: saveHelper

     * Purpose: Recursively saves the assignments stored in the subtree rooted at the given node to the specified output file stream.

     * Parameter:
     * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.
     * - file: A reference to an output file stream to which the assignments will be saved.

     * Return: void

     *******************************************************/
    void saveHelper(std::unique_ptr<AssignmentNode>& node, ofstream& file);

    /*******************************************************

     * Function Name: increaseIDs

     * Purpose: Recursively increases the IDs of all assignments stored in the subtree rooted at the given node.

     * Parameter:
     * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.

     * Return: void

     *******************************************************/
    void increaseIDs(std::unique_ptr<AssignmentNode>& node);

    /*******************************************************

     * Function Name: reduceIDs

     * Purpose: Recursively reduces the IDs of all assignments stored in the subtree rooted at the given node starting from the specified ID.

     * Parameter:
     * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.
     * - currentID: An integer representing the starting ID from which to reduce.

     * Return: void

     *******************************************************/
    void reduceIDs(std::unique_ptr<AssignmentNode>& node, int currentID);

    /*******************************************************

     * Function Name: getAllAssignments

     * Purpose: Recursively retrieves all assignments stored in the subtree rooted at the given node.

     * Parameter:
     * - node: A reference to a unique pointer to an AssignmentNode representing the root of the subtree.
     * - allAssignments: A reference to a vector of Assignment objects to store the retrieved assignments.

     * Return: void

     *******************************************************/
    void getAllAssignments(std::unique_ptr<AssignmentNode>& node, vector<Assignment>& allAssignments);
};



#endif /* AssignmentBST_hpp */
