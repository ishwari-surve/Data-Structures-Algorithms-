/*
===============================================================================
Program Name    : Binary Search Tree - Basic Structure
Program Number  : 01
File Name       : Tree_01.cpp
Description     : This program demonstrates the basic structure of a Binary
                  Search Tree using C++. It defines the node structure,
                  BST class, constructor, and root pointer.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Structure
4. Constructor
5. Binary Search Tree
6. Pointers

Key Learning Points:
- Understand the basic structure of a Binary Search Tree.
- Learn how a Tree node contains data and child pointers.
- Understand the use of left and right child pointers.
- Initialize the root pointer using a constructor.
- Understand the foundation required for further BST operations.

===============================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

class BST
{
private:
    struct node *first;

public:
    BST();
};

// Constructor
BST::BST()
{
    first = NULL;
}

int main()
{
    BST bobj;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

The program only creates a Binary Search Tree object and initializes the
root pointer to NULL.

===============================================================================
Memory Representation:
===============================================================================

             BST Object

        +-------------------+
        | first ----------> NULL
        +-------------------+

             Tree is Empty

===============================================================================
Algorithm:
===============================================================================

1. Define the node structure.
2. Declare data, lchild and rchild members in the node.
3. Create the BST class.
4. Declare the first pointer to store the root node.
5. Define the BST constructor.
6. Initialize first to NULL.
7. Create a BST object in main().
8. Stop.

===============================================================================
Program Flow:
===============================================================================

             Start
               │
               ▼
       Define Node Structure
               │
               ▼
         Create BST Class
               │
               ▼
       Declare first Pointer
               │
               ▼
        Call Constructor
               │
               ▼
       Initialize first=NULL
               │
               ▼
         Create BST Object
               │
               ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

Constructor : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 01 introduces the basic structure of a Binary Search Tree using
C++. It defines the node structure with data, left child and right child
pointers. The BST class contains the root pointer, which is initialized
to NULL using the constructor. This program provides the foundation for
implementing further Binary Search Tree operations.

===============================================================================
*/
