/*
===============================================================================
Program Name    : Binary Tree - Basic Structure
Program Number  : 001
File Name       : Tree_01.c
Description     : This program demonstrates the basic structure of a Binary
                  Tree using C. It defines the node structure with left and
                  right child pointers and displays the size of the node.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation (Preparation)
5. Binary Tree

Key Learning Points:
- Understand the Binary Tree node structure.
- Learn self-referential structures.
- Understand left and right child pointers.
- Determine the memory occupied by a tree node.

===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

//=========================================================
// Main
//=========================================================

int main()
{
    PNODE Head = NULL;

    printf("Size of Node : %d\n",sizeof(NODE));

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Size of Node : 20

===============================================================================
Memory Representation:
===============================================================================

              +-----------------------+
              |       data            |
              +-----------------------+
              |      lchild  ---------|----> NULL
              +-----------------------+
              |      rchild  ---------|----> NULL
              +-----------------------+

                Head
                  │
                  ▼
                NULL

Binary Tree is Empty

===============================================================================
Algorithm:
===============================================================================

1. Define the Binary Tree node structure.
2. Create pointer typedefs.
3. Initialize the Head pointer to NULL.
4. Display the size of the node structure.
5. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
     Define Node Structure
               │
               ▼
   Initialize Head = NULL
               │
               ▼
 Display Size of Node
               │
               ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

No Tree operation is performed.

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic structure of a Binary Tree using C.
It defines a self-referential node containing data, left child pointer,
and right child pointer. The program also displays the memory occupied
by a single Binary Tree node.

===============================================================================
*/
