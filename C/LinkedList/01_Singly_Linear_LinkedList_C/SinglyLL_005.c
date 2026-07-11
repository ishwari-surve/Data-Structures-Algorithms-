/*
================================================================================
Program Name    : Singly Linked List - Pointer Addresses & Dereferencing 
Program Number  : 005
Description     : This program demonstrates how pointers connect two nodes
                  by storing their virtual memory addresses. It explains
                  node linking, pointer dereferencing, and traversal
                  using the arrow (->) operator.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Pointers and Pointer Variables
4. Address-of Operator (&)
5. Pointer Dereferencing (->)
6. Virtual Memory Addresses
7. Memory Location Access
8. #pragma pack(1)
9. printf() for Output and Address Display

Key Learning Points:
- Understanding virtual addresses in memory
- How pointers store addresses of nodes
- Accessing node address using address-of operator (&)
- Dereferencing pointers to access data (->)
- obj1.next contains address of obj2
- obj2.next contains NULL (no next node)
- Memory addresses are different for each object
- Arrow operator (->) is equivalent to (*ptr).member
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
    obj1.next = &obj2;     // Link obj1 to obj2 (store address of obj2)

    // Initialize Node 2
    obj2.data = 21;
    obj2.next = NULL;      // Last node - no next node

    // Display memory addresses (virtual addresses)
    printf("Address of obj1 (node1): %u\n", &obj1);
    printf("Address of obj2 (node2): %u\n", &obj2);

    // Display what the next pointers contain (addresses)
    printf("obj1.next contains (address of obj2): %d\n", obj1.next);
    printf("obj2.next contains (NULL): %d\n", obj2.next);

    // Dereference pointer to access data from obj2 through obj1
    printf("obj1.next->data (accessing obj2 data via obj1): %d\n", obj1.next->data);

    return 0; 
}
/*
================================================================================
Output (example - actual addresses will vary):
Address of obj1 (node1): 140732925694464
Address of obj2 (node2): 140732925694480
obj1.next contains (address of obj2): 140732925694480
obj2.next contains (NULL): 0
obj1.next->data (accessing obj2 data via obj1): 21

================================================================================
Memory Diagram:
================================================================================

Stack Memory Layout:

Virtual Address Space:    Memory Content:
┌────────────────────────────────────────────┐
│ 0x7ffd45c9e800 │ obj1                      │
│   to 0x0C      │ ┌──────────────────────┐  │
│                │ │ data: 11 (4 bytes)   │  │
│                │ │ [0x08-0x0B]          │  │
│                │ ├──────────────────────┤  │
│                │ │ next: 0x7ffd45c9e810 │  │
│                │ │ [0x0C-0x13] (8 bytes)│  │
│                │ └──────────────────────┘  │
└────────────────────────────────────────────┘

┌────────────────────────────────────────────┐
│ 0x7ffd45c9e810 │ obj2                      │
│   to 0x1C      │ ┌──────────────────────┐  │
│                │ │ data: 21 (4 bytes)   │  │
│                │ │ [0x18-0x1B]          │  │
│                │ ├──────────────────────┤  │
│                │ │ next: NULL (0)       │  │
│                │ │ [0x1C-0x23] (8 bytes)│  │
│                │ └──────────────────────┘  │
└────────────────────────────────────────────┘

Linked Structure:
obj1(11) ────→ obj2(21) ────→ NULL
          

================================================================================
Time Complexity
================================================================================

Node Access           : O(1)
Pointer Assignment    : O(1)
Memory Access         : O(1)

Space Complexity      : O(1)


================================================================================
Pointer Chain Explanation:
================================================================================

1. &obj1 = 0x7ffd45c9e800 (Virtual address of obj1)
   This is WHERE obj1 is located in memory

2. &obj2 = 0x7ffd45c9e810 (Virtual address of obj2)
   This is WHERE obj2 is located in memory

3. obj1.next = 0x7ffd45c9e810
   obj1's next pointer CONTAINS the address of obj2
   This is HOW they are LINKED

4. obj2.next = NULL (or 0)
   obj2's next pointer is NULL
   This indicates END of linked list

5. obj1.next->data = 21
   Using obj1's next pointer to access obj2's data
   This is POINTER DEREFERENCING

6. Arrow Operator (->):
   obj1.next->data  is equivalent to  (*obj1.next).data
   Both access the data field through the pointer

================================================================================
Summary:
================================================================================
A singly linked list works by storing the address of the next node in each
node. Traversal is performed by following these addresses until the last
node is reached, whose next pointer is NULL. Understanding this concept
forms the foundation for implementing all linked list operations.

================================================================================
*/
