
//*********************************************************************************************//
//  Class HTable (header & implementation)                                                     //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 3                                                            //
//  Date  : 2021-05-24                                                                         //
//  Program Description: Hash Table Class built to work with TreeHashTableDemo & ADT's         //
//***********************************************************************************************
 
#ifndef HTABLE_H
#define HTABLE_H
#include <iostream>
using namespace std;

#define TABLE_SIZE 5000

template<typename T>
class HTable
{
	public:
        ////////// CONSTRUCTOR ///////////////////////// 

        // Precondition: None.
        // Postcondition: A new array of size TABLE_SIZE defined above, exists with all pointers set to NULL. 
        HTable() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                hashArray[i] = NULL;
            }
        } 

        ////////// DESTRUCTOR ///////////////////////////

        // Precondition: An array must exist. 
        // Postcondition: Deletes the objects that the array points to.
        ~HTable() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                if (hashArray[i] != NULL) {
                    delete hashArray[i];
                } 
            }
        }

        ////////// Hash Algo PROVIDED //////////

        // Precondition: None. 
        // Postcondition: Calculates an int between 0 and TABLE_SIZE -1 based on the item code passed. 
        int hashfun(const T& value) {                           // Does Cool things!
            int position = 0;                                   // Sets loop to begin from position 0.
            string temp = value.get_code();                     // Retrives the part code and stores it in temp.
            for (int i = 0; i < (int)temp.length(); i++) {      // Set the itteration number to the length of the part code. 
                position += (i+1) * (i+1) * temp.at(i);         // Does Math ;)
            }
            return position % TABLE_SIZE;                       // Returns int for an array position
        }

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////
        
        // Precondition: None.
        // Postcondition: Creates a new object of type T on the heap refferenced to from a position in the array. 
        void add(const T& data) {                               // Adds a part to the heap.
            int position = hashfun(data);                       // Calls the hash function to calculate the array position.
            if (hashArray[position] != NULL) {                  // Checks for a collision. 
                cout << "You have a collision. " << endl;
            } else {
                hashArray[position] = new T (data);             // Instantiates the object on the heap refferenced to by the array.
            }
        }
        
        // Precondition: The target data should exist to be deleted. 
        // Postcondition: Delets the target data from the heap and sets the array pointer to null. 
        void remove(T& data) {                                  // Deletes the target object from the heap
            int position = hashfun(data);                       // Calls the hash function to find the location of the target.
            if (hashArray[position] != NULL) {                  // Checks for NULL incase of an error
                delete hashArray[position];                     // Deletes the target object. 
                hashArray[position] = NULL;                     // Sets the pointer to NULL. 
            }
        }

        ////////// ACCESSOR FUNCTIONS (GETTERS) ///////// 
        
        // Precondition: Inventory exists to be counted. If there's no inventory, 0 is returned.  
        // Postcondition: Returns the number of items in the inventory. 
        int calculateInventory() {                              // Counts total of all parts in the inventory.
            int count = 0;
            for (int i = 0; i < TABLE_SIZE; i++) {              // Loops through the array.
                if (hashArray[i] != NULL) {                     // Checks if a part exists.
                    count+= hashArray[i]->get_quantity();       // Retrives the quantity of the part & adds it to the count.
                }
            }
            return count;                                       // Returns the count. 
        }

        // Precondition: Part types exist to be counted. If there's no parts, 0 is returned.  
        // Postcondition: Returns the number of part types stored. 
        int calculateParts() {                                  // Counts the number of different parts.
            int count = 0;
            for (int i = 0; i < TABLE_SIZE; i++) {              // Loops through the array.
                if (hashArray[i] != NULL) {                     // Checks if a part exists.
                    count++;                                    // Adds 1 to the count for every part found. 
                }
            }
            return count;                                       // Returns the count.
        }
        
        // Precondition: items have been added to the heap via the add function. 
        // Postcondition: Prints out all items stored and referred to by the array. 
        ostream& print(ostream& out) { 
            for (int i = 0; i < TABLE_SIZE; i++) {              // Loops through the array.
                if (hashArray[i] != NULL) {                     // Checks a part exists. 
                    out << "(" << hashArray[i]->get_code() << "," 
                        << hashArray[i]->get_quantity() << ") "; 
                }                                               // Prints code and quantity of each part found.
            }
            return out;
        }


    private:
        T* hashArray[TABLE_SIZE];                       // Private member array of size TABLE_SIZE T data type pointers.  
        T data;                                         // Private member variable to store the templated type data.

};

template<typename T>
ostream& operator << (ostream& out, HTable<T>& table)   // Non member output operator overlaod function.
{
	return table.print(out);                            // Calls the print function above. 
}

#endif