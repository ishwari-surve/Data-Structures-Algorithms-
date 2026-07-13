/*
================================================================================
Program Name    : Doubly Linear Linked List - Node Structure
Program Number  : 001
Description     : This program demonstrates the basic node structure of a
                  Doubly Linear Linked List. Each node contains three members:
                  data, next pointer, and previous pointer. The program also
                  uses #pragma pack(1) to remove structure padding and displays
                  the size of the node structure using sizeof().
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structure
3. Doubly Linked List Node
4. Previous Pointer (prev)
5. Next Pointer (next)
6. Dynamic Memory Representation
7. Structure Packing (#pragma pack(1))
8. sizeof() Operator

Key Learning Points:
- Every node contains data, previous pointer, and next pointer.
- Previous pointer stores the address of the previous node.
- Next pointer stores the address of the next node.
- #pragma pack(1) removes compiler-added padding.
- sizeof() helps determine the memory occupied by the structure.

================================================================================
*/

// Doubly Linked List starts here
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int main()
{
    printf("Size of NODE : %zu Bytes\n", sizeof(NODE));

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================

Size of NODE : 20 Bytes

================================================================================
Memory Layout:
================================================================================

               +-----------+-----------+-----------+
               |   Prev    |   Data    |   Next    |
               +-----------+-----------+-----------+

Example Node:

               +-----------+-----------+-----------+
               | 0x200100  |    11     | 0x200200  |
               +-----------+-----------+-----------+

Previous Pointer -> Stores address of previous node.
Data             -> Stores integer value.
Next Pointer     -> Stores address of next node.

================================================================================
Pointer / Logic Explanation:
================================================================================

A Doubly Linked List node contains three members:

1. data
   - Stores the actual integer value.

2. prev
   - Stores the address of the previous node.
   - NULL for the first node.

3. next
   - Stores the address of the next node.
   - NULL for the last node.

#pragma pack(1) removes compiler padding, so only the actual memory
required by the structure members is allocated.

Structure Size Calculation (64-bit System):

int data           = 4 Bytes
next pointer       = 8 Bytes
prev pointer       = 8 Bytes

Total = 20 Bytes

================================================================================
Operations Performed:
================================================================================

- Defined a self-referential structure.
- Declared next and previous pointers.
- Applied #pragma pack(1) for structure packing.
- Used typedef for NODE, PNODE, and PPNODE.
- Displayed structure size using sizeof().

================================================================================
Time Complexity:
================================================================================

sizeof()           : O(1)
Space Complexity   : O(1)

================================================================================
Conclusion:
================================================================================

Program 001 introduces the fundamental building block of a Doubly Linear
Linked List. Unlike a Singly Linked List, each node stores both the previous
and next node addresses, enabling bidirectional traversal. The program also
demonstrates the use of structure packing and the sizeof() operator to
understand the memory occupied by a Doubly Linked List node.

================================================================================
*/
