
# SENG1120-A3 Inventory Management. 
Grade: 12.5/15 (83%) - Overlooked memory leek, 2.5 mark deduction. 

SENG1120 is a Data Structures course run by the University of Newcastle. 

Assignment Scope:   
                    You are in charge of inventory management support in a factory. 
                    You are required to create binary search tree and hash table data structures to store instances of a class MechPart. 
                    Both data structures should have functions to add, remove, display, overloaded operators, among others. 
                    The classes MUST be implemented as class templates. 
                    The binary search tree class must be called BSTree and will use as nodes instances of BTNode. 
                    The hash table class must be named HTable.

Requirements:       
                    Your code must work seemlesly with the files supplied.

Restrictions:       
                    Must use C++ 98 and manually manage memory allocation. 
                    Must use Cygwin compiler to run the program. 
                    
Marking Criteria:   
                    If the program compiles you receive full marks (15) less deductions as follows;
                      • Code leads to memory leaks during execution (____/-2.0)
                      • Lack of macroguards (____/-1.0)
                      • Lack of destructors (____/-1.0)
                      • Lack of const qualifiers (____/-1.0)
                      • Lack of comments/documentation in the code (____/-2.0)
                      • Direct acceess to LInkedList to facilitate printing ot analysis (___/-5.0)
                      • Declaration of temporary variables as member variables of the class (____/-1.0)
                      • Lack of use of dynamic memory allocation in Node or LinkedList (____/-10.0)
                      • Use of friend qualifier (____/-2.0)
                      • Violation of encapsulation / information hiding (e.g. use of global variables) (____/-5.0)
                      • Correctness of Submission, filenames and format (___/-5.0)
                      • Concrete Implementation in the header file (____/-2.0)
                      • Lack of recursive calls for BSTree functions, etc (____/-3.0)
