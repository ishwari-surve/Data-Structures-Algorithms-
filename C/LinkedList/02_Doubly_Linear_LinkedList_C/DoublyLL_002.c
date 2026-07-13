/*
================================================================================
Program Name    : Doubly Linear Linked List - Function Prototypes
Program Number  : 002
Description     : This program creates the basic skeleton of a Doubly Linear
                  Linked List. It defines all major linked list operations
                  including insertion, deletion, display, and count functions.
                  Only the function declarations and empty implementations are
                  provided to establish the program structure for future
                  development.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structure
3. Doubly Linked List
4. Function Definitions
5. PNODE and PPNODE typedef
6. Function Prototypes
7. Call by Value
8. Call by Address
9. Modular Programming
10. Empty Function Skeleton

Key Learning Points:
- A Doubly Linked List requires multiple operations to manage nodes.
- Display() and Count() use Call by Value.
- Insertion and Deletion functions use Call by Address.
- Modular programming improves readability and maintenance.
- Empty function skeletons are created before implementing logic.

================================================================================
*/
//Doubly linked list 
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct  node
{
    int data;
    struct node *next;
    struct  node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
   
}

int Count(PNODE first)
{
   return 0;
}

void InsertFirst(PPNODE first ,int iNo)
{


}

void InsertLast(PPNODE first,int iNo)
{


}

void InsertAtPos(PPNODE first,int iNo,int iPos)
{


}

void DeleteFirst(PPNODE first)
{


}

void DeleteLast(PPNODE first)
{


}

void DeleteAtPos(PPNODE first, int iPos)
{


}
int main()
{
   PNODE head = NULL;

    return 0;
}
/*
================================================================================
Expected Output:
================================================================================

(No Output)

================================================================================
Program Structure:
================================================================================

                     Doubly Linear Linked List

                             main()
                                |
            -----------------------------------------
            |                 |                     |
         Display()         Count()           Insert/Delete
                                              Functions
                                            /     |      \
                                  InsertFirst()  InsertLast()
                                  InsertAtPos()  DeleteFirst()
                                  DeleteLast()   DeleteAtPos()

================================================================================
Pointer / Logic Explanation:
================================================================================

Program 002 establishes the complete framework of a Doubly Linear Linked
List before implementing individual operations.

Functions are divided into two categories:

Call by Value Functions
-----------------------
- Display()
- Count()

These functions receive a copy of the head pointer because they only
traverse the list and do not modify it.

Call by Address Functions
-------------------------
- InsertFirst()
- InsertLast()
- InsertAtPos()
- DeleteFirst()
- DeleteLast()
- DeleteAtPos()

These functions receive the address of the head pointer (PPNODE)
because they may modify the first node of the linked list.

This modular approach makes the program easier to understand,
maintain, and extend.

================================================================================
Operations Planned:
================================================================================

- Display all nodes
- Count total nodes
- Insert node at beginning
- Insert node at end
- Insert node at specified position
- Delete first node
- Delete last node
- Delete node at specified position

================================================================================
Time Complexity:
================================================================================

Program Initialization : O(1)
Space Complexity       : O(1)

(Function implementations will be added in upcoming programs.)

================================================================================
Conclusion:
================================================================================

Program 002 establishes the complete structure of a Doubly Linear Linked
List implementation. Although the functions are currently empty, this
program defines the overall architecture that will be followed throughout
subsequent programs while implementing each linked list operation one by
one.

================================================================================
*/
