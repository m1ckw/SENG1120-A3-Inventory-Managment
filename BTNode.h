
//*********************************************************************************************//
//  Class BTNode (header & implementation)                                                     //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 3                                                            //
//  Date  : 2021-05-24                                                                         //
//  Program Description: Binary Tree Node Class built to work with Binary Search Trees & ADT's //
//***********************************************************************************************
 
#ifndef MICK_BTNODE
#define MICK_BTNODE
#include <cstdlib> // Provides access to the NULL pointer 
#include <iostream>
using namespace std;

template <typename T>
class BTNode
{
    public:
        ////////// CONSTRUCTORS /////////////////////////

        // Precondition: None.
        // Postcondition: An empty node is created with the previous, next, & parent pointers set to NULL. 
        BTNode()
        {
            right = NULL;
            left = NULL;
            parent = NULL;
        }

        // Precondition: None. 
        // Postcondition: A new node is created and initialised with the data passed.
        BTNode(const T& initData, BTNode* initRight = NULL, BTNode* initLeft = NULL, BTNode* initParent = NULL)
		{
            data = initData;
            right = initRight;
            left = initLeft;
            parent = initParent;
        }
        ////////// DESTRUCTOR ///////////////////////////

        // Precondition: A node must exist. 
        // Postcondition: Deletes the node and sets the next and previous pointers to NULL.
        ~BTNode() 
        {
            right = NULL;
            left = NULL;
            parent = NULL;
        }

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////

        // Precondition: A node must exist.
        // Postcondition: Updates the data within the node to the data passed. 
        void setData(const T& newData)  
        {
            data = newData;
        }

        // Precondition: A node must exist. 
        // Postcondition: Sets the current nodes right child pointer to the location passed. 
        void setRight(BTNode* newRight)               
        {
            right = newRight;
        }   

        // Precondition: A node must exist. 
        // Postcondition: Sets the current nodes left child pointer to the location passed.           
        void setLeft(BTNode* newLeft)       
        {
            left = newLeft;
        }  

        // Precondition: A node must exist. 
        // Postcondition: Sets the current nodes parent pointer to the location passed.           
        void setParent(BTNode* newParent)       
        {
            parent = newParent;
        }  

        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////

        // Precondition: A node containing data must exist.
        // Postcondition: The data from the target node is returned.  
        const T getData() const
        {
            return data;
        }

        // Precondition: A node containing data must exist.
        // Postcondition: The data from the target node is returned.  
        T& getData() 
        {
            return data;
        }

        // Precondition: More than one node must exist.  
        // Postcondition: Returns the location of the right child const node.
        const BTNode* getRight() const                 
        {
            return right;
        }

        // Precondition: More than one node must exist. 
        // Postcondition: Returns the location of the right child node.                
        BTNode* getRight()                             
        {
            return right;
        } 

        // Precondition: More than one node must exist.  
        // Postcondition: Returns the location of the left child CONST node.
        const BTNode* getLeft() const             
        {
            return left;
        } 

        // Precondition: More than one node must exist. 
        // Postcondition: Returns the location of the left child node.
        BTNode* getLeft()                         
        {
            return left;
        }      

        // Precondition: More than one node must exist.  
        // Postcondition: Returns the location of the parent CONST node.
        const BTNode* getParent() const             
        {
            return parent;
        } 

        // Precondition: More than one node must exist. 
        // Postcondition: Returns the location of the parent node.
        BTNode* getParent()                         
        {
            return parent;
        }                     

    private:
        T data;                             // Private member variable that stores the data types data.
        BTNode* right;                      // Private member variable that points to the right child node.   
        BTNode* left;                       // Private member variable that points to the left child node.
        BTNode* parent;                     // Private member variable that points to the parent node.

};
template <typename T>
ostream& operator << (ostream& out, const BTNode<T>& node)      // Non member output operator overlaod function.
{
	return node.getData();
}

#endif