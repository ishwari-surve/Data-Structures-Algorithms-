/*
================================================================================
Program Name    : Singly Linked List - PNODE Pointer Type Alias 
Program Number  : 009
Description     : This program introduces PNODE typedef, which is an alias for
                  "pointer to NODE". Creates cleaner and more professional code
                  by using PNODE instead of NODE*. Shows difference between
                  pointer values (addresses) and data values.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. typedef for Types
4. typedef for Pointers (PNODE)
5. Pointers to typedef types
6. HEAD Pointer (PNODE type)
7. Node Linking
8. Pointer Dereferencing (->)
9. Data vs Address values
10. #pragma pack(1)
11. printf() for Output

Key Learning Points:
- PNODE is typedef for pointer to NODE
- PNODE head is same as NODE *head but cleaner
- Pointer stores ADDRESS of node
- Node stores DATA value
- PNODE is fundamental for linked list operations
- Makes code more readable and professional
- Essential foundation for PPNODE (pointer to pointer)
- Distinguishes between data access and address access
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
    PNODE head = NULL;           // HEAD pointer using PNODE typedef
    NODE obj1, obj2, obj3;        // Node objects using NODE typedef

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

    // Access data through pointer
    printf("%d\n", head->data);
    printf("%d\n", head->next->data);
    printf("%d\n", head->next->next->data);
    
    // Data gives value, next gives address
    printf("%p\n", obj1.next);

    return 0; 
}

/*
================================================================================
Expected Output:
================================================================================
11
21
51
140732925694480

(Note: The address value depends on system and run - shown as example)

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

Visual Chain:
head → obj1 → obj2 → obj3 → NULL

================================================================================
Pointer / Logic Explanation
================================================================================

typedef allows aliases to be created for existing data types.

Declaration:
typedef struct node NODE;
typedef struct node *PNODE;

NODE represents the node structure, while PNODE represents a pointer to
that structure.

Example:
NODE obj;
PNODE head;

Here, head stores the address of the first node in the linked list.

Data vs Address:
head->data      → Returns the data stored inside the node.
head->next      → Returns the address of the next node.
obj1.next       → Stores the address of obj2.

Using PNODE improves readability by replacing repeated declarations such
as "struct node *" with a meaningful alias.

================================================================================
Time Complexity
================================================================================

Node Initialization      : O(1)
Pointer Assignment       : O(1)
Node Linking             : O(1)
Node Access              : O(1)

Space Complexity         : O(1)

Note:
PNODE is a compile-time alias created using typedef and introduces no
runtime overhead.

================================================================================
Conclusion
================================================================================

This program introduces PNODE as an alias for a pointer to the node
structure. Using PNODE instead of "struct node *" makes the code shorter,
clearer, and easier to maintain. It also helps distinguish between node
objects and node pointers, making linked list implementations more
readable and consistent.

================================================================================
*/
