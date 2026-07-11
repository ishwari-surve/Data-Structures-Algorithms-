/*
================================================================================
Program Name    : Singly Linked List - typedef for Structures
Program Number  : 008
Description     : This program demonstrates the use of the typedef keyword to
                  create an alias for the node structure. Using NODE instead
                  of "struct node" improves code readability, reduces
                  repetitive declarations, and follows professional C
                  programming practices.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. typedef Keyword
4. Type Aliasing
5. Pointers to typedef types
6. HEAD Pointer
7. Node Linking
8. Pointer Dereferencing (->)
9. #pragma pack(1)
10. printf() for Output

Key Learning Points:
- typedef creates an alias for a data type
- NODE is now an alias for struct node
- Makes code shorter and more readable
- NODE *head is cleaner than struct node *head
- Reduces typing and improves code maintenance
- Professional coding practice
- Used extensively in DSA implementations
- Foundation for PNODE and PPNODE typedefs
================================================================================
*/

#include<stdio.h>

#pragma pack(1)
struct node 
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

typedef struct node NODE;  // typedef - NODE is alias for struct node

int main()
{
    NODE *head = NULL;     // HEAD pointer using typedef
    NODE obj1, obj2, obj3; // Node objects using typedef

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

head → obj1 → obj2 → obj3 → NULL

================================================================================
Pointer/Logic Explanation
================================================================================

typedef allows us to create an alias for an existing data type.

Declaration:
typedef struct node NODE;

Without typedef:
struct node *head;
struct node obj1;

With typedef:
NODE *head;
NODE obj1;

The functionality remains exactly the same. typedef only improves code
readability by reducing repetitive use of "struct node". It is a compile-time
feature and does not affect program execution or memory usage.


================================================================================
Time Complexity
================================================================================

typedef Declaration      : Compile-Time
Node Initialization      : O(1)
Pointer Assignment       : O(1)
Node Linking             : O(1)
Node Access              : O(1)

Space Complexity         : O(1)

Note:
typedef is a compile-time feature and introduces no runtime overhead.


================================================================================
Conclusion
================================================================================

This program introduces the typedef keyword to create an alias for the node
structure. Using NODE instead of struct node makes the code shorter, cleaner,
and easier to maintain without changing the program's functionality. This is a
common practice in professional C programming and serves as the foundation for
creating pointer aliases such as PNODE and PPNODE.

================================================================================
*/
