/*
================================================================================
Program Name    : Singly Linked List - TEMP Pointer for Traversal
Program Number  : 010
Description     : This program introduces the TEMP pointer concept. TEMP is a
                  temporary pointer used to traverse the linked list without
                  changing the original HEAD pointer. HEAD always points to the
                  first node, while TEMP moves through nodes during traversal.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. PNODE typedef (Pointer to NODE)
4. HEAD Pointer (entry point to list)
5. TEMP Pointer (temporary traversal pointer)
6. Pointer Assignment
7. Pointer Dereferencing (->)
8. Traversal without modifying HEAD
9. #pragma pack(1)
10. printf() for Output

Key Learning Points:
- TEMP pointer is used for traversal
- TEMP allows moving through list without changing HEAD
- HEAD pointer should never change during traversal
- TEMP = head assigns TEMP to point to first node
- Both HEAD and TEMP can point to same nodes
- TEMP moves: temp = temp->next
- HEAD stays fixed at first node
- Critical concept for all linked list operations
================================================================================
*/

#include<stdio.h>

#pragma pack(1)
struct node 
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node *PNODE;      // PNODE is alias for pointer to NODE

int main()
{
    PNODE head = NULL;           // HEAD pointer - entry point (never changes)
    PNODE temp = NULL;           // TEMP pointer - used for traversal
    NODE obj1, obj2, obj3;

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

    // Assign TEMP to HEAD (both point to first node)
    temp = head;                // HEAD remains unchanged while TEMP is used for traversal

    // Access nodes through TEMP pointer
    printf("%d\n", temp->data);
    printf("%d\n", temp->next->data);
    printf("%d\n", temp->next->next->data);

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
Memory Diagram:
================================================================================
            head (PNODE)          temp (PNODE)
                │                     │
                └─────────┬───────────┘
                          ▼
            +-----------+      +-----------+      +-----------+
            | data = 11 | ---> | data = 21 | ---> | data = 51 |
            | next -----|      | next -----|      | next=NULL |
            +-----------+      +-----------+      +-----------+
            obj1              obj2              obj3

Visual Chain:
head → obj1 → obj2 → obj3 → NULL
temp ↓
(both head and temp point to obj1)

================================================================================
Pointer/Logic Explanation:
================================================================================

Two Pointers Concept:

HEAD Pointer:
- Always points to FIRST node
- Entry point to linked list
- NEVER changes during traversal
- Used to mark beginning of list

TEMP Pointer:
- Temporary pointer for traversal
- Starts at same location as HEAD
- Moves through list using temp = temp->next
- Can be reused for different traversals

Why Two Pointers?

If we only had HEAD and moved it:
  head = head->next;  ← Would LOSE reference to first node!
  
With TEMP, HEAD stays safe:
  temp = head;        ← Both point to first node
  temp = temp->next;  ← TEMP moves, HEAD stays
  temp = temp->next;  ← TEMP continues, HEAD unchanged

Initialization:
temp = head;
└─ Both HEAD and TEMP now point to obj1
└─ temp->data = 11 (same as head->data)

Access Pattern Using TEMP:
Traversal Process:

temp = head;
        │
        ▼
      obj1
        │
temp = temp->next;
        ▼
      obj2
        │
temp = temp->next;
        ▼
      obj3
        │
      NULL

================================================================================
Time Complexity
================================================================================

TEMP Initialization     : O(1)
Pointer Assignment      : O(1)
Node Traversal          : O(n)
Node Access             : O(1)

Space Complexity        : O(1)

================================================================================
Conclusion
================================================================================

This program introduces the TEMP pointer, which is used to traverse a linked
list without modifying the HEAD pointer. By assigning temp = head, all nodes
can be accessed safely while preserving the starting address of the list.
This forms the basis for implementing traversal, display, search, and count
operations in linked lists.

================================================================================
*/
