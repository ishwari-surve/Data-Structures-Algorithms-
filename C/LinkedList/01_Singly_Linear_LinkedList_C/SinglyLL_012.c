/*
================================================================================
Program Name    : Singly Linked List - While Loop Traversal (Display)
Program Number  : 012
Description     : This program demonstrates linked list traversal using a
                  while loop. Instead of manually moving the TEMP pointer,
                  the loop automatically visits each node until TEMP
                  becomes NULL. This traversal pattern forms the foundation
                  of the Display() function and other linked list
                  operations such as Count() and Search().
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. PNODE typedef
4. HEAD and TEMP Pointers
5. While Loop
6. Loop Condition (temp != NULL)
7. Pointer Movement (temp = temp->next)
8. Automatic Iteration
9. NULL Termination Check
10. #pragma pack(1)

Key Learning Points:
- While loop automates manual traversal
- while(temp != NULL) repeats until end of list
- Eliminates repetitive temp = temp->next statements
- Loop body: print data and move to next node
- Condition checks if temp is not NULL
- Loop stops when temp becomes NULL
- This is the Display() function logic
- Foundation for all traversal-based operations
- Critical pattern for linked list functions
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

    // Assign TEMP to HEAD
    temp = head;

    // While loop traversal - Automatically visit all nodes
    while(temp != NULL)
    {
        printf("%d\n", temp->data);           // Print current node data
        temp = temp->next;                    // Move to next node
    }

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
          obj1               obj2                obj3 

Traversal using TEMP:

temp
 │
 ▼
obj1 → obj2 → obj3 → NULL)

Visual Chain:
head → obj1(11) → obj2(21) → obj3(51) → NULL

================================================================================
Pointer/Logic Explanation:
================================================================================

While Loop Pattern:

Initialization:
temp = head;                    // temp points to first node

Loop Condition:
while(temp != NULL)             // Continue if temp is not NULL

Loop Body:
{
    printf("%d\n", temp->data); // Print current node data
    temp = temp->next;          // Move to next node
}

Execution Trace:

Iteration 1:
├─ Condition: temp != NULL? YES (temp points to obj1)
├─ Print: temp->data = 11
├─ Move: temp = temp->next (now points to obj2)
└─ Loop continues

Iteration 2:
├─ Condition: temp != NULL? YES (temp points to obj2)
├─ Print: temp->data = 21
├─ Move: temp = temp->next (now points to obj3)
└─ Loop continues

Iteration 3:
├─ Condition: temp != NULL? YES (temp points to obj3)
├─ Print: temp->data = 51
├─ Move: temp = temp->next (now points to NULL)
└─ Loop continues

Iteration 4:
├─ Condition: temp != NULL? NO (temp is NULL)
└─ Loop exits

Why while(temp != NULL)?

The condition checks if temp is not NULL:
- If temp is NOT NULL: Node exists, continue loop
- If temp IS NULL: End of list reached, exit loop

Flow Chart:
START
  ↓
temp = head
  ↓
temp != NULL? ──NO──→ END
  ↓ YES
Print temp->data
  ↓
temp = temp->next
  ↓
(Loop back to condition check)

This Pattern is Foundation:
This while loop pattern is used in Display(), Count(), Search(),
and all other traversal functions. Mastering this is essential
for all linked list operations.

================================================================================
Operations Performed
================================================================================

1. Created and linked three nodes.
2. Assigned the HEAD pointer to the TEMP pointer.
3. Traversed the linked list using a while loop.
4. Displayed the data stored in each node.
5. Stopped traversal when TEMP became NULL.

================================================================================
Time Complexity
================================================================================

Node Traversal      : O(n)

Space Complexity    : O(1)

================================================================================
Conclusion:
================================================================================

The while loop transforms manual traversal into an automatic, reusable pattern.
By checking while(temp != NULL), we can traverse any number of nodes without
knowing the list size in advance. The loop continues as long as there are nodes
to visit and stops when temp reaches NULL, marking the end of the list. This
elegant pattern eliminates repetitive code and is the foundation for the Display()
function and all other traversal-based operations in linked lists.

================================================================================
*/
