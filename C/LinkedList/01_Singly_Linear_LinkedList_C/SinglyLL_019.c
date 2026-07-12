/*
================================================================================
Program Name    : Singly Linked List - Combined typedef Definition
Program Number  : 019
Description     : This program demonstrates an alternative typedef syntax where
                  NODE, PNODE, and PPNODE are all defined in a single typedef
                  statement. This is a cleaner and more professional approach
                  compared to separate typedef declarations. Functionally
                  identical to Program 018 but with improved code organization.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures
2. Self-Referential Structures
3. Combined typedef Syntax
4. Multiple Type Aliases
5. PNODE
6. PPNODE
7. HEAD Pointer
8. NULL Initialization

Key Learning Points:
- Combined typedef creates multiple aliases at once
- NODE, PNODE, PPNODE defined in single statement
- Cleaner code organization than separate typedefs
- Functionally identical to separate typedef approach
- Professional coding standard
- More efficient and readable
- All aliases available immediately after definition
- Foundation for implementing linked list functions
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node

}NODE, *PNODE, **PPNODE;   // NODE, PNODE, PPNODE all defined here

int main()
{
    PNODE head = NULL;     // HEAD pointer - entry point to linked list

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
(No output - Setup program only)

================================================================================
Memory Diagram:
================================================================================

Stack:
┌─────────────────────────────┐
│ head (PNODE)                │
│ Value: NULL (0)             │
│ Represents: Empty list      │
└─────────────────────────────┘

Visual:
head → NULL (Empty list)

================================================================================
Pointer/Logic Explanation:
================================================================================

Combined typedef Syntax:

Program 018 (Separate typedefs):
┌─ struct node { ... };
├─ typedef struct node NODE;
├─ typedef struct node* PNODE;
└─ typedef struct node** PPNODE;

Program 019 (Combined typedef):
└─ typedef struct node { ... } NODE, *PNODE, **PPNODE;

What Happens in Combined Syntax:

typedef struct node { ... } NODE, *PNODE, **PPNODE;
    ↓                            ↓        ↓         ↓
    └─ Define struct       NODE  PNODE  PPNODE
       and create three aliases in one statement

Breaking Down the Aliases:

NODE        → struct node (the structure itself)
*PNODE      → struct node* (pointer to structure)
**PPNODE    → struct node** (pointer to pointer to structure)

Explanation of Each:

NODE obj;           ← Creates structure object
PNODE ptr;          ← Creates pointer to structure
PPNODE dptr;        ← Creates pointer to pointer

Why Combined Typedef is Better:

✓ Cleaner code - all in one place
✓ More professional - industry standard
✓ Easier to maintain - modify one place
✓ Less typing - single statement
✓ Less clutter - fewer lines
✓ Immediate availability - all at once
✓ Clear relationship - all aliases shown together

Cleaner and More Professional!

================================================================================
Operations Performed
================================================================================

1. Defined a self-referential structure.
2. Created NODE, PNODE and PPNODE using a combined typedef statement.
3. Declared the HEAD pointer.
4. Initialized HEAD to NULL.
5. Demonstrated the compact typedef syntax used in linked list programs.

================================================================================
Time Complexity:
================================================================================
Initialization                 : O(1) - Only set pointer to NULL
Space Complexity               : O(1) - Single pointer on stack

================================================================================
Conclusion:
================================================================================

Program 019 demonstrates how multiple typedef aliases can be created in a
single statement. This approach produces the same result as separate typedef
declarations while making the code shorter, cleaner, and easier to maintain.
It is a commonly used style in professional C programming and provides the
foundation for implementing linked list operations.

================================================================================
*/
