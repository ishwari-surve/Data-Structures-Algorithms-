/*
================================================================================
Program Name    : Singly Linked List - Node Initialization
Program Number  : 003
Description     : This program demonstrates the creation of a self-referential
                  structure, initialization of its members, and accessing 
                  structure data using the dot operator.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================

Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Pointers
4. Structure Member Access (dot operator)
5. NULL Pointer
6. #pragma pack(1)
7. Data Initialization

Key Learning Points:
- Creating a single node instance
- Initializing data member
- Initializing pointer to NULL
- Accessing structure members using dot operator
- Understanding NULL pointer in linked lists

================================================================================
*/

#include<stdio.h>

#pragma pack(1)
struct node 
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

int main()
{
    struct node obj;

    // Initialize the node
    obj.data = 11;      // Assign data value
    obj.next = NULL;    // Initialize pointer to NULL (no next node)

    // Display the data
    printf("%d\n", obj.data);  // Output: 11

    return 0;
}

/*
================================================================================
Output: 11

Conclusion:
================================================================================
This program demonstrates:
1. Creating a single node: struct node obj
2. Initializing data member: obj.data = 11
3. Setting pointer to NULL: obj.next = NULL
4. Accessing member using dot operator (.)
================================================================================
*/
