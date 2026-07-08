/*
================================================================================
Program Name    : Singly Linked List - Linking Two Nodes
Program Number  : 004
Description     : This program demonstrates the creation of two nodes and
                  linking them together using pointers. Shows how nodes are
                  connected in a singly linked list.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================

Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Pointers
4. Address-of Operator (&)
5. Linking Nodes
6. #pragma pack(1)
7. printf() for Output

Key Learning Points:
- Creating multiple nodes
- Linking nodes using pointers
- Node 1's next pointer points to Node 2
- Accessing data from linked nodes
- Understanding node connections in linked lists

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
    struct node obj1, obj2;

    // Initialize Node 1
    obj1.data = 11;
    obj1.next = &obj2;     // Link obj1 to obj2

    // Initialize Node 2
    obj2.data = 21;
    obj2.next = NULL;      // Last node - no next node

    // Display data from both nodes
    printf("%d\n", obj1.data);  // Output: 11
    printf("%d\n", obj2.data);  // Output: 21

    return 0;
}

/*
================================================================================
Output:
11
21

Conclusion:
================================================================================
This program demonstrates:
1. Creating two nodes: obj1 and obj2
2. Linking them: obj1.next = &obj2
3. Accessing data from both nodes
================================================================================
*/
