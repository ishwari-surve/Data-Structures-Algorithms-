/*
================================================================================
Program Name    : Singly Linked List - Manual Node-by-Node Traversal 
Program Number  : 011
Description     : This program demonstrates manual traversal of linked list
                  using TEMP pointer. Shows step-by-step movement through each
                  node using temp = temp->next. This is the foundation for
                  implementing while loop traversal patterns in functions.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. PNODE typedef
4. HEAD Pointer (entry point)
5. TEMP Pointer (for traversal)
6. Pointer Assignment
7. Pointer Movement (temp = temp->next)
8. Manual Node Access
9. Sequential Traversal
10. #pragma pack(1)

Key Learning Points:
- TEMP pointer starts at HEAD
- Each temp = temp->next moves to next node
- Manual traversal shows actual movement sequence
- Access data at each node before moving
- Movement continues until NULL
- Foundation for while loop implementation
- Shows how functions will traverse lists
- Critical concept for all linked list algorithms
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
    PNODE head = NULL;           // HEAD pointer - entry point
    PNODE temp = NULL;           // TEMP pointer - for traversal
    NODE obj1, obj2, obj3;

    // Link nodes
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

    // Manual Traversal - Step 1
    temp = head;                         //  // TEMP points to first node
    printf("%d\n", temp->data);          // Output: 11

    // Manual Traversal - Step 2
    temp = temp->next;                   // Move TEMP to second node
    printf("%d\n", temp->data);          // Output: 21

    // Manual Traversal - Step 3
    temp = temp->next;                   // Move TEMP to third node
    printf("%d\n", temp->data);          // Output: 51

    // Manual Traversal - Step 4
    temp = temp->next;                   // temp at NULL (end of chain)

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
            head (PNODE)
                │
                ▼
      +-----------+      +-----------+      +-----------+
      | data = 11 | ---> | data = 21 | ---> | data = 51 |
      | next -----|      | next -----|      | next=NULL |
      +-----------+      +-----------+      +-----------+
         obj1                obj2               obj3 
      temp ↓

Traversal Sequence:

Step 1: temp → obj1
         Print: 11

Step 2: temp → obj2
         Print: 21

Step 3: temp → obj3
         Print: 51

Step 4: temp → NULL
         Traversal Ends

Traversal:
temp
 │
 ▼
obj1 → obj2 → obj3 → NULL

================================================================================
Pointer/Logic Explanation:
================================================================================

Manual Traversal Steps:

Step 1: temp = head
        ├─ temp points to obj1 
        ├─ temp->data = 11
        └─ Print: 11

Step 2: temp = temp->next
        ├─ temp->next contains address of obj2 
        ├─ temp now points to obj2
        ├─ temp->data = 21
        └─ Print: 21

Step 3: temp = temp->next
        ├─ temp->next contains address of obj3 
        ├─ temp now points to obj3
        ├─ temp->data = 51
        └─ Print: 51

Step 4: temp = temp->next
        ├─ temp->next is NULL (0)
        ├─ temp now points to NULL
        └─ Traversal ends

Traversal Progression:
temp → obj1 → obj2 → obj3 → NULL

Why This Matters:
Each temp = temp->next statement moves temp to next node by extracting
the address stored in next pointer. This is the CORE MECHANISM of linked
list traversal that will be repeated in while loops.

================================================================================
Time Complexity
================================================================================

Node Traversal      : O(n)
Node Access         : O(1)

Space Complexity    : O(1)

================================================================================
Conclusion
================================================================================

This program demonstrates manual traversal of a singly linked list using the
TEMP pointer. By repeatedly executing temp = temp->next, each node is visited
one after another until TEMP becomes NULL. This manual process forms the
foundation for implementing traversal using loops in operations such as
Display(), Count(), and Search().

================================================================================
*/
