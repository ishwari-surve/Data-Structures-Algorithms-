/*
================================================================================ 
Program Name    : Singly Linked List - Three Node Chain Creation
Program Number  : 006
Description     : This program demonstrates the creation and linking
                  of three nodes in a singly linked list. It explains
                  how each node stores the address of the next node,
                  enabling sequential traversal through chained pointer
                  dereferencing using the arrow (->) operator.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Pointers and Pointer Variables
4. Address-of Operator (&)
5. Pointer Dereferencing (->, ->->)
6. Virtual Memory Addresses
7. Node Linking and Chain Creation
8. Multi-level Pointer Dereferencing
9. #pragma pack(1)
10. printf() for Output and Address Display

Key Learning Points:
- Creating three nodes and linking them in sequence
- Chain structure: obj1 → obj2 → obj3 → NULL
- Each node's next pointer points to the next node
- Last node's next pointer is NULL (marks end)
- Multi-level dereferencing: obj1.next->next->data
- Understanding sequential node connections
- Foundation for larger linked list structures
- Each node has unique virtual address
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
    struct node obj1, obj2, obj3;

    // Initialize Node 1
    obj1.data = 11;
    obj1.next = &obj2;     // Link obj1 to obj2

    // Initialize Node 2
    obj2.data = 21;
    obj2.next = &obj3;     // Link obj2 to obj3

    // Initialize Node 3
    obj3.data = 51;
    obj3.next = NULL;      // Last node - no next node

    // Display virtual addresses of all three nodes
    printf("Virtual Address of obj1 (Node 1): %u\n", &obj1);
    printf("Virtual Address of obj2 (Node 2): %u\n", &obj2);
    printf("Virtual Address of obj3 (Node 3): %u\n", &obj3);

    // Display what the next pointers contain (addresses)
    printf("\nNext pointer values:\n");
    printf("obj1.next (points to obj2): %d\n", obj1.next);
    printf("obj2.next (points to obj3): %d\n", obj2.next);
    printf("obj3.next (NULL - end of chain): %d\n", obj3.next);

    // Display data from all nodes using dereferencing
    printf("\nData accessed through dereferencing:\n");
    printf("obj1.data (direct access): %d\n", obj1.data);
    printf("obj1.next->data (access obj2 through obj1): %d\n", obj1.next->data);
    printf("obj1.next->next->data (access obj3 through obj1): %d\n", obj1.next->next->data);

    return 0; 
}

/*
================================================================================
Output (example - actual addresses will vary):
Virtual Address of obj1 (Node 1): 140732925694464
Virtual Address of obj2 (Node 2): 140732925694480
Virtual Address of obj3 (Node 3): 140732925694496

Next pointer values:
obj1.next (points to obj2): 140732925694480
obj2.next (points to obj3): 140732925694496
obj3.next (NULL - end of chain): 0

Data accessed through dereferencing:
obj1.data (direct access): 11
obj1.next->data (access obj2 through obj1): 21
obj1.next->next->data (access obj3 through obj1): 51

================================================================================
Memory Diagram:
================================================================================

Stack Memory Layout:

┌────────────────────────────────────────────┐
│ obj1 (Node 1)                              │
│ Address: 0x7ffd45c9e800                    │
│ ┌──────────────────────────────────────┐   │
│ │ data: 11 (4 bytes)     [0x00-0x03]   │   │
│ ├──────────────────────────────────────┤   │
│ │ next: 0x7ffd45c9e810   [0x04-0x0B]   │   │
│ │ (address of obj2)                    │   │
│ └──────────────────────────────────────┘   │
└────────────────────────────────────────────┘
         ↓ (obj1.next points to obj2)

┌────────────────────────────────────────────┐
│ obj2 (Node 2)                              │
│ Address: 0x7ffd45c9e810                    │
│ ┌──────────────────────────────────────┐   │
│ │ data: 21 (4 bytes)     [0x00-0x03]   │   │
│ ├──────────────────────────────────────┤   │
│ │ next: 0x7ffd45c9e820   [0x04-0x0B]   │   │
│ │ (address of obj3)                    │   │
│ └──────────────────────────────────────┘   │
└────────────────────────────────────────────┘
         ↓ (obj2.next points to obj3)

┌────────────────────────────────────────────┐
│ obj3 (Node 3)                              │
│ Address: 0x7ffd45c9e820                    │
│ ┌──────────────────────────────────────┐   │
│ │ data: 51 (4 bytes)     [0x00-0x03]   │   │
│ ├──────────────────────────────────────┤   │
│ │ next: NULL (0)         [0x04-0x0B]   │   │
│ │ (end of chain)                       │   │
│ └──────────────────────────────────────┘   │
└────────────────────────────────────────────┘
         ↓ (obj3.next = NULL)
       END OF CHAIN


Linked Structure Visualization:
┌──────┐     ┌──────┐     ┌──────┐
│ obj1 │────→│ obj2 │────→│ obj3 │────→NULL
│ 11   │     │ 21   │     │ 51   │
└──────┘     └──────┘     └──────┘

================================================================================
Pointer Dereferencing Chain Explanation:
================================================================================

Level 0 - Direct Access:
  obj1.data = 11
  └─ Access obj1's data directly

Level 1 - Single Dereference:
  obj1.next->data = 21
  └─ Follow obj1's next pointer to reach obj2
  └─ Then access obj2's data

Level 2 - Double Dereference:
  obj1.next->next->data = 51
  └─ Follow obj1's next pointer to reach obj2
  └─ Follow obj2's next pointer to reach obj3
  └─ Then access obj3's data

Memory Addresses:
  &obj1 = 0x7ffd45c9e800  (address of node 1)
  &obj2 = 0x7ffd45c9e810  (address of node 2)
  &obj3 = 0x7ffd45c9e820  (address of node 3)

Pointer Chain:
  obj1.next = 0x7ffd45c9e810  (contains address of obj2)
  obj2.next = 0x7ffd45c9e820  (contains address of obj3)
  obj3.next = NULL (0)        (marks end of chain)

Equivalent Expressions:
  obj1.next->data     ≡  (*(obj1.next)).data
  obj1.next->next->data  ≡  (*(*(obj1.next).next)).data


================================================================================
Time Complexity
================================================================================

Node Initialization        : O(1)
Pointer Assignment         : O(1)
Node Linking              : O(1)
Node Access               : O(1)
Pointer Dereferencing     : O(1)

Space Complexity          : O(1)


================================================================================
Conclusion:
================================================================================

This program demonstrates how multiple nodes are connected sequentially to form
a singly linked list. Each node stores the address of the next node, allowing
traversal from one node to another through pointer dereferencing. This concept
forms the foundation for implementing insertion, deletion, and traversal
operations in linked lists.

================================================================================
*/
