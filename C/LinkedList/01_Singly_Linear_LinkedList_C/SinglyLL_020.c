/*
================================================================================
Program Name    : Singly Linked List - Function Templates and Declarations
Program Number  : 020
Description     : This program provides function templates and declarations for
                  all 8 core linked list operations. Contains empty function
                  bodies ready to be implemented. Serves as a framework for
                  understanding function signatures, parameters, and return types
                  before implementing logic. Professional template for structured
                  development approach.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. PNODE typedef (Pointer to NODE)
4. PPNODE typedef (Pointer to Pointer to NODE)
5. Function Declaration
6. Function Parameters (PNODE, PPNODE, int)
7. Return Types (void, int)
8. Function Prototyping
9. Empty Function Bodies
10. Professional Code Organization

Key Learning Points:
- Function signatures for all 8 operations
- PNODE parameter for read-only traversal
- PPNODE parameter for head modification
- void return for operations without results
- int return for Count operation
- Proper parameter naming and organization
- Template structure for implementation
- Clear separation of concerns
- Professional template approach
- Foundation for step-by-step implementation
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node *PNODE;      // PNODE is alias for pointer to NODE
typedef struct node **PPNODE;    // PPNODE is alias for pointer to pointer to NODE

/*
================================================================================
Function 1: Display(PNODE first)
Purpose: Display all nodes in linked list
Parameters: PNODE first (pointer to first node)
Return: void (no return value)
================================================================================
*/
void Display(PNODE first)
{
    // Implementation will go here
}

/*
================================================================================
Function 2: Count(PNODE first)
Purpose: Count total number of nodes in linked list
Parameters: PNODE first (pointer to first node)
Return: int (total count of nodes)
Note: Only Count function returns int - others return void
================================================================================
*/
int Count(PNODE first)
{
    // Implementation will go here
    return 0;
}

/*
================================================================================
Function 3: InsertFirst(PPNODE first, int iNo)
Purpose: Insert node at beginning of list
Parameters: PPNODE first (address of head pointer), int iNo (data value)
Return: void (no return value)
================================================================================
*/
void InsertFirst(PPNODE first, int iNo)
{
    // Implementation will go here
}

/*
================================================================================
Function 4: InsertLast(PPNODE first, int iNo)
Purpose: Insert node at end of list
Parameters: PPNODE first (address of head pointer), int iNo (data value)
Return: void (no return value)
================================================================================
*/
void InsertLast(PPNODE first, int iNo)
{
    // Implementation will go here
}

/*
================================================================================
Function 5: InsertAtPos(PPNODE first, int iNo, int iPos)
Purpose: Insert node at specific position
Parameters: PPNODE first (address of head pointer), int iNo (data), int iPos (position)
Return: void (no return value)
================================================================================
*/
void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    // Implementation will go here
}

/*
================================================================================
Function 6: DeleteFirst(PPNODE first)
Purpose: Delete first node from list
Parameters: PPNODE first (address of head pointer)
Return: void (no return value)
================================================================================
*/
void DeleteFirst(PPNODE first)
{
    // Implementation will go here
}

/*
================================================================================
Function 7: DeleteLast(PPNODE first)
Purpose: Delete last node from list
Parameters: PPNODE first (address of head pointer)
Return: void (no return value)
================================================================================
*/
void DeleteLast(PPNODE first)
{
    // Implementation will go here
}

/*
================================================================================
Function 8: DeleteAtPos(PPNODE first, int iPos)
Purpose: Delete node at specific position
Parameters: PPNODE first (address of head pointer), int iPos (position)
Return: void (no return value)
================================================================================
*/
void DeleteAtPos(PPNODE first, int iPos)
{
    // Implementation will go here
}

int main()
{
    PNODE head = NULL;           // HEAD pointer - entry point to linked list

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
(No output - Template program only)

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
head → NULL (Empty list - ready for operations)

================================================================================
Pointer/Logic Explanation:
================================================================================

Function Parameter Types:

PNODE first (Read-only Operations):
├─ Display()    - Print nodes
├─ Count()      - Count nodes
└─ Used when: No head modification needed

PPNODE first (Modification Operations):
├─ InsertFirst()  - Modify head
├─ InsertLast()   - May modify head
├─ InsertAtPos()  - May modify head
├─ DeleteFirst()  - Modify head
├─ DeleteLast()   - May modify head
├─ DeleteAtPos()  - May modify head
└─ Used when: Head pointer might change

Return Types:

void (No return):
├─ Display()      - Just prints
├─ InsertFirst()  - Modifies list
├─ InsertLast()   - Modifies list
├─ InsertAtPos()  - Modifies list
├─ DeleteFirst()  - Modifies list
├─ DeleteLast()   - Modifies list
└─ DeleteAtPos()  - Modifies list

int (Returns value):
└─ Count()        - Returns count (only one)

================================================================================
Operations Performed
================================================================================

1. Defined the node structure.
2. Created typedef aliases (NODE, PNODE, PPNODE).
3. Declared templates for all eight linked list functions.
4. Demonstrated appropriate parameter and return types.
5. Initialized the HEAD pointer to NULL.
6. Prepared the framework for implementing linked list operations.

================================================================================
Time Complexity:
================================================================================
(Functions not yet implemented - complexity will vary by implementation)

Each function's complexity depends on implementation:
Display()        : Will be O(n)
Count()          : Will be O(n)
InsertFirst()    : Will be O(1)
InsertLast()     : Will be O(n)
InsertAtPos()    : Will be O(n)
DeleteFirst()    : Will be O(1)
DeleteLast()     : Will be O(n)
DeleteAtPos()    : Will be O(n)

Space Complexity : O(1) for all (constant extra space)

================================================================================
Conclusion:
================================================================================

Program 020 provides the complete framework for implementing a singly
linked list. It declares all eight core linked list functions with
appropriate parameters and return types, clearly distinguishing between
read-only operations (PNODE) and modification operations (PPNODE).
This organized template serves as the foundation for implementing each
operation step by step while maintaining clean and modular code.

================================================================================
*/
