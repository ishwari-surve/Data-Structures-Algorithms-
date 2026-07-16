/*
================================================================================
Program Name    : Singly Linked List - Node Structure without Padding
Program Number  : 002
Description     : This program demonstrates removing structure padding using
                  #pragma pack(1). Shows memory layout without compiler padding
                  on a 64-bit system.
Date            : July 2026 
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================

Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. Pointers
4. #pragma pack() directive
5. Memory Packing
6. sizeof() Operator
7. Memory Alignment Control

Key Learning Points:
- Understanding #pragma pack(1) directive
- Removing compiler padding from structures
- Tight memory packing vs memory alignment
- Trade-offs between memory and performance
- Pointer size on 64-bit systems

================================================================================
*/

#include<stdio.h>

#pragma pack(1)  // Remove padding - pack structure tightly
struct node 
{
    int data;              // 4 bytes
    struct node *next;     // 8 bytes (64-bit pointer)
};

int main()
{
    struct node obj;

    printf("%d\n", sizeof(obj));  // Output: 12
    
    // Memory Breakdown (with #pragma pack(1)):
    // int data        -> 4 bytes
    // struct node*    -> 8 bytes
    // Total           -> 12 bytes (NO PADDING)

    return 0;
}

/*
================================================================================
Output: 12

Conclusion:
================================================================================
The size of the singly linked list node structure is 12 bytes due to:
1. int data (4 bytes)
2. struct node *next pointer (8 bytes)
3. NO padding (removed by #pragma pack(1))
================================================================================
*/
