/*
================================================================================
Program Name    : Singly Linked List - Node Structure & Memory Layout
Program Number  : 001
Description     : This program demonstrates the creation of a singly linked list
                  node structure in C. It explains the memory layout, structure
                  size, padding, and alignment on a 64-bit system. Foundation
                  for all LinkedList operations.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================ 
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Pointers
4. Memory Allocation Concepts
5. Memory Alignment and Padding
6. sizeof() Operator
7. printf() for Output
 
Key Learning Points:
- Understanding node structure in singly linked lists
- Memory layout of structures in C
- Compiler padding and alignment
- Pointer size on 64-bit systems
- Why structure size is important for DSA 
================================================================================
*/

#include<stdio.h>

struct node 
{
    int data;              // 4 bytes
    struct node *next;     // 8 bytes (64-bit pointer)
};

int main()
{
    struct node obj;

    printf("%d\n", sizeof(obj));  // Output: 16
    
    // Memory Breakdown:
    // int data        -> 4 bytes
    // Padding         -> 4 bytes (for alignment)
    // struct node*    -> 8 bytes
    // Total           -> 16 bytes

    return 0;
}

/*
================================================================================
Output: 16
 
Conclusion:
================================================================================
The size of the singly linked list node structure is 16 bytes due to:
1. int data (4 bytes)
2. Compiler padding for alignment (4 bytes)
3. struct node *next pointer (8 bytes)
 
This understanding is essential for:
- Memory management in linked lists
- Dynamic memory allocation (malloc/calloc)
- Pointer arithmetic
- Efficient DSA implementation
 ================================================================================
*/
