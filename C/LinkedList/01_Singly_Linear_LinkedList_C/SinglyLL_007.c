/*
================================================================================
Program Name    : Singly Linked List - HEAD Pointer Introduction
Program Number  : 007
Description     : This program introduces the concept of the HEAD pointer,
                  which serves as the entry point to a singly linked list.
                  It demonstrates how all nodes are accessed through the
                  HEAD pointer instead of directly using node variables.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Pointers 
4. HEAD Pointer (Entry Point)
5. Pointer Initialization to NULL
6. Node Linking
7. Pointer Dereferencing (->)
8. #pragma pack(1)
9. printf() for Output

Key Learning Points:
- HEAD pointer is the entry point to linked list
- HEAD pointer should be initialized to NULL (empty list)
- HEAD pointer is assigned address of first node
- All nodes are accessed through HEAD pointer
- HEAD pointer never changes during traversal
- HEAD pointer is critical for dynamic linked lists
- Foundation for implementing linked list functions
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
    struct node *head = NULL;  // HEAD pointer - entry point to linked list
    struct node obj1, obj2, obj3;

    // Assign HEAD to first node
    head = &obj1;

    // Initialize Node 1
    obj1.data = 11;
    obj1.next = &obj2;

    // Initialize Node 2
    obj2.data = 21;
    obj2.next = &obj3;

    // Initialize Node 3
    obj3.data = 51;
    obj3.next = NULL;

    // Access all nodes through HEAD pointer
    printf("%d\n", head->data);
    printf("%d\n", head->next->data);
    printf("%d\n", head->next->next->data);

    return 0; 
}

/*
================================================================================
Expected Output:
================================================================================
11
21
51

================================================================================
Memory Diagram
================================================================================

            head
             │
             ▼
      +-----------+      +-----------+      +-----------+
      | data = 11 | ---> | data = 21 | ---> | data = 51 |
      | next -----|      | next -----|      | next=NULL |
      +-----------+      +-----------+      +-----------+

Visual Chain:
head
 │
 ▼
[11|•] ───► [21|•] ───► [51|NULL]


================================================================================
Pointer/Logic Explanation:
================================================================================

HEAD Pointer Concept:
- head = NULL initially (empty list)
- head = &obj1 (points to first node)
- head is the ENTRY POINT to entire linked list
- All nodes accessed through HEAD

Access Pattern:
1. head->data              = 11 (access obj1 data)
2. head->next->data        = 21 (access obj2 data through obj1)
3. head->next->next->data  = 51 (access obj3 data through obj1 and obj2)

Why HEAD is Important:
- Single point of entry to linked list
- Don't need to remember variable names (obj1, obj2, obj3)
- Can dynamically add/remove nodes
- Foundation for implementing functions
- Enables iteration and traversal


================================================================================
Time Complexity
================================================================================

HEAD Initialization      : O(1)
Pointer Assignment       : O(1)
Node Linking             : O(1)
Node Access              : O(1)

Space Complexity         : O(1)


================================================================================
Conclusion
================================================================================

This program introduces the HEAD pointer, which serves as the entry point to a
linked list. By accessing nodes through the HEAD pointer instead of individual
variables, the linked list becomes easier to traverse and manage. The HEAD
pointer forms the foundation for implementing all linked list operations such
as insertion, deletion, searching, and traversal.

================================================================================
*/
