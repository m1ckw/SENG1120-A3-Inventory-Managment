
//*********************************************************************************************//
//  Class BSTree (header & implementation)                                                     //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 3                                                            //
//  Date  : 2021-05-24                                                                         //
//  Program Description: Binary Search Tree Class built to work with TreeHashTableDemo & ADT's //
//***********************************************************************************************
 
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include "BTNode.h"
#include "MechPart.h"
using namespace std;

template<typename T>
class BSTree
{
	public:
		////////// CONSTRUCTORS /////////////////////////

		// Precondition: None
		// Postcondition: Sets the root node pointer to NULL and the size of the tree to 0. 
		BSTree() {									// Creates an empty tree setting the root to NULL.
			root = NULL;
			size = 0;
		}

		// Precondition: None
		// Postcondition: A new instance of a Binary Search Tree is created with a single node..
		BSTree(T data) {								// Creates a tree with its first node.
			root = new BTNode<T>(data);
		}

		////////// DESTRUCTOR ///////////////////////////

		// Precondition: A node must exist. 
		// Postcondition: Deletes all nodes in the list.
		    // Calls the removeNodes() recursive function removing each node from the tree untill none remain.
		~BSTree() {                                 
			removeNodes(root);
		}

		void removeNodes(BTNode<T>* node) {						// Recursive function - traverses tree deleting leaf nodes.
			if (node == NULL) {							// Checks node exists and returns if null.
				return;
			} else {
				removeNodes(node->getLeft());					// Deleting left leaves .
				removeNodes(node->getRight());					// Deleting right leaves.
				delete node;							// Deletes the final node.
				size--;											
			}
		}

		////////// MUTATOR FUNCTIONS (SETTERS) //////////

		void add(const T& data) {							// Adds a new node to the BST in position.
			if (root == NULL) {							// Checks for existing root node. 
				root = new BTNode<T>(data);					// Creates a root node if none exist. 
				size++;										 
			} else {
				add(root, data);						// Call to Recursive add function to start at the root,
			}									// traverse the tree and place the node is position.
		}
		// Precondition: A Root node exists.
		// Postcondition: Adds a node to the relevant position and updates relevant pointers.
		BTNode<T>* add(BTNode<T>* node,const T& data) {
			if (data == node->getData()) {						// Checks if the data is equivalent to existing.
				node->setData(data);						// Replaces existing data.
			} else if (data > node->getData()) {					// Moves to the right node. 
				if (node->getRight() == NULL) {					// Checks if Node exists.
					node->setRight(new BTNode<T>(data));			// Creates right node if none exists. 
					size++;							// Increases the size of the tree by 1. 
				} else {
					add(node->getRight(), data);				// Recursive call on the next right node. 
				}
			} else {								// Moves to the left node. 
				if (node->getLeft() == NULL) {					// Checks if Node exists.
					node->setLeft(new BTNode<T>(data));			// Creates left node if none exists.
					size++;							// Increases the size of the tree by 1.
				} else {
					add(node->getLeft(), data);				// Recursive call on the next left node.
				}
			}
			return node;
		}
		
		// Precondition: A node must already exist.  
		// Postcondition: The target node will be deleted and any data contained returned. 
		void remove(T& data) {								// Passes the target data to be deleted.
			BTNode<T>* rootNode = root;						// Creates a temp node pointer set to the root node.
			rootNode = remove(rootNode, data);					// Calls the recursive remove function to traverse the tree,
		}										// from the root to locate the target data. 
		
		// Precondition: A node must already exist.  
		// Postcondition: The target node will be deleted and any data contained returned. 
		BTNode<T>* remove(BTNode<T>* node, T& data) {					// Removes the target node from the linked list.
			BTNode<T>* temp = NULL;							// Creates a temp node pointer set to null.
			if (node == NULL) {							// Checks that the node exists, returns null if true.
				return temp;
			}
			if (data < node->getData()) {						// Compares the data value and moves left if it's < current node.
				node->setLeft(remove(node->getLeft(), data));	// Recursivley removes and sets the left side of the tree
				if (node->getLeft()) {							
					node->getLeft()->setParent(node);			// Sets the new parent node. 
				}
			} 
			else if (data > node->getData()) {					// Compares the data value and moves Right if it's > current node.
				node->setRight(remove(node->getRight(), data));	// Recursivley removes and sets the right side of the tree
				if (node->getRight()) {
					node->getRight()->setParent(node);			// Sets the new parent node.
				}
			} 
			else {									// Assumes same value.
				if (node->getLeft() && node->getRight()) {			// Checks if two children exist.
					temp = findMin(node->getRight());			// Sets temp to the minumum value of the right branch.
					node->setData(temp->getData());				// Sets node data to that min value.
					node->setRight(remove(node->getRight(), node->getData())); 
				} else {							// Deals with single child
					temp = node;
					if (node->getLeft() == NULL) {				// Checks for node on left.
						node = node->getRight();				
					} else if (node->getRight() == NULL) {			// Checks for node on right. 
						node = node->getLeft();
					}
					delete temp;						// Deletes Temp.
					size--;							// Decrements size by 1. 
				}
			}
			if (!node) {								// Deals with no node
				return node;
			}
			return node;								// Returns the deleted node. 
		}
		
		////////// ACCESSOR FUNCTIONS (GETTERS) /////////	

		// Precondition: A BST exisits. 
		// Postcondition: The function will return the current size of the tree. 
		int getSize() const {
			return size;
		} 

		// Precondition: A node with data exisits. Returns null if there is no node. 
		// Postcondition: Finds the node that contains the maximum value.
		BTNode<T>* findMax(BTNode<T>* const node) const {			 
			if (node == NULL) {							// Checks that a node exists
				return NULL;
			}
			if (node->getRight() == NULL) {						// Checks for right node, if null, max is current node.
				return node;
			}	
			return findMax(node->getRight());					// Recursive call on the function until the max has been found.
		}

		// Precondition: A node with data exisits. Returns null if there is no node. 
		// Postcondition: Finds the node that contains the minimum value. 
		BTNode<T>* findMin(BTNode<T>* const node) const {
			if (node == NULL) {							// Checks that a node exists
				return NULL;
			}
			if (node->getLeft() == NULL) {						// Checks for left node, if null, min is current node.
				return node;									
			}
			return findMin(node->getLeft());					// Recursive call on the function until the min has been found.
		}	                             	                            

		// Precondition: Nodes with inventory exist. Returns 0 if no inventory doesn't exist.
		// Postcondition: Calls the recursive function to start the count of all inventory from the root node. 
		int calculateInventory() {	
			int count = 0;								// Sets the count to 0.
			count = calculateInventory(root);					// Recursive function call. 
			return count;								// Returns the count
		}

		// Precondition: Nodes with inventory exist. Returns 0 if inventory doesn't exist. 
		// Postcondition: Calculates the total inventory of parts and returns that value. 
		int calculateInventory(BTNode<T>* node) {
			int count = 0;
			if (node != NULL) {							// Ensures a node exists.
				count += calculateInventory(node->getLeft());			// Recursive call to the left side of the tree.
				count += calculateInventory(node->getRight());  		// Recursive call to the right side of the tree.
				count += node->getData().get_quantity();			// Adds the number of part to the count.  
			}
			return count;								// Returns the count.
		}

		// Precondition: Nodes with parts exist. Returns 0 if parts don't exist.
		// Postcondition: Calls the recursive function to start the count of the number of different parts from the root node.
		int calculateParts() {
			int count = 0;								// Sets the count to 0.
			count = calculateParts(root);						// Recursive function call.
			return count;								// Returns the count
		}

		// Precondition: Nodes with parts exist. Returns 0 if parts don't exist. 
		// Postcondition: Calculates the total number of part types and returns that value. 
		int calculateParts(BTNode<T>* node) {
			int count = 0;
			if (node != NULL) {							// Ensures a node exists.
				count += calculateParts(node->getLeft());			// Recursive call to the left side of the tree.
				count += calculateParts(node->getRight());			// Recursive call to the right side of the tree.
				count += 1;							// Adds 1 for each part found. 
			}
			return count;										
		}

		// Precondition: A node with data exists. 
		// Postcondition: Calls the recursive print function setting the starting point at the root.  
		ostream& print(ostream& out) {
			return print(out, root);
		}

		// Precondition: A node with data exists.
		// Postcondition: Reteives data and prints the BST with an inorder traversal.  
		ostream& print(ostream& out, const BTNode<T>* node) {
			if (node != NULL) {
				print(out, node->getLeft());					// Recursive call to the LEFT of the tree 
				out << node->getData() << " ";					// Prints current nodes data 
				print(out, node->getRight());					// Recursive call to the Right of the tree 
			}
			return out;
		}
	
	private:
		BTNode<T>* root;								// Private member variable that points to the head node.
		int size;									// Private member variable that stores the size of the tree.
};

template<typename T>
ostream& operator << (ostream& out, BSTree<T>& tree) 						// Non member output operator overlaod function.
{
	return tree.print(out);									// Calls the print function above. 
}

#endif