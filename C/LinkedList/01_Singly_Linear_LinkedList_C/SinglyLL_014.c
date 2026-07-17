/*
================================================================================
Program Name    : Singly Linked List - Dynamic Node Creation using malloc() 
Program Number  : 014
Description     : This program demonstrates how to create a node dynamically
                  using malloc(). Memory for the node is allocated from the
                  heap during program execution. The allocated node is then
                  initialized with data and its next pointer is set to NULL.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Dynamic Memory Allocation
4. malloc() Function
5. Heap Memory
6. Pointer to Structure
7. Pointer Dereferencing (->)
8. NULL Pointer
9. stdlib.h
10. #pragma pack(1)
11. printf() for Output

Key Learning Points:
- malloc() allocates memory dynamically from the heap.
- Dynamic nodes are created during program execution.
- malloc() returns the starting address of allocated memory.
- The returned address is stored in a pointer variable.
- The arrow (->) operator is used to access members of the allocated node.
- The next pointer is initialized to NULL to indicate the end of the list.
- Dynamic allocation removes the limitation of fixed-size node creation.
- Foundation for implementing insertion and deletion operations.
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

int main()
{
    struct node *newn = NULL;

    newn = (struct node *)malloc(sizeof(struct node));

    newn->data = 11;
    newn->next = NULL;

    printf("%d", newn->data);

    return 0;
}

/*
================================================================================
Expected Output
================================================================================
11

================================================================================
Memory Diagram
================================================================================
Memory Representation

newn
 │
 ▼
+------------+------------+
| data = 11  | next = NULL|
+------------+------------+
 (Heap Memory)

================================================================================
Pointer/Logic Explanation
================================================================================

Declaration:

struct node *newn = NULL;

- newn is a pointer to a node.
- Initially, it does not point to any memory.

Dynamic Memory Allocation:

newn = (struct node *)malloc(sizeof(struct node));

- malloc() allocates memory for one node on the heap.
- It returns the starting address of the allocated memory.
- That address is stored in newn.

Initialization:

newn->data = 11;
newn->next = NULL;

- data stores the integer value 11.
- next is initialized to NULL because there is no next node.

Data Access:

printf("%d\n", newn->data);

- Prints the value stored inside the dynamically allocated node. 

================================================================================
Operations Performed
================================================================================

1. Declared a pointer to a node.
2. Allocated memory dynamically using malloc().
3. Stored the returned address in the pointer.
4. Initialized the node data.
5. Set the next pointer to NULL.
6. Displayed the node data.

================================================================================
Time Complexity
================================================================================

Memory Allocation    : O(1)
Node Initialization  : O(1)
Node Access          : O(1)

Space Complexity     : O(1)

================================================================================
Conclusion
================================================================================

This program introduces dynamic memory allocation using malloc() for creating
linked list nodes. Unlike previous programs where nodes were created
statically, memory is now allocated at runtime from the heap. This approach
allows linked lists to grow dynamically and forms the foundation for
implementing insertion, deletion, and other dynamic linked list operations.

================================================================================
