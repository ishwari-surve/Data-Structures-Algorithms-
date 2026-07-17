/*
================================================================================
Program Name    : Singly Linked List - Display with Enhanced Formatting 
Program Number  : 023
Description     : This program implements Display() with improved visual
                  formatting showing chain structure. InsertFirst adds nodes
                  at beginning. Display prints nodes in pipe-separated format
                  with arrows showing connections to visualize linked list chain.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. Traversal with while loop
5. Enhanced Output Formatting
6. Visual Chain Representation

Key Learning Points:
- Display() with improved visual formatting
- Pipe and arrow formatting shows chain structure clearly
- InsertFirst() adds nodes at beginning O(1)
- NULL marking shows end of list
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

/*
================================================================================
Function: Display(PNODE first)
Purpose: Display all nodes with enhanced formatting
Parameters: PNODE first (pointer to first node)
Return: void
Time Complexity: O(n)
================================================================================
*/
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf(" | %d | ->", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

/*
================================================================================
Function: Count(PNODE first)
Purpose: Count total number of nodes
Parameters: PNODE first (pointer to first node)
Return: int (total count)
Status: Template
================================================================================
*/
int Count(PNODE first)
{
    return 0;
}

/*
================================================================================
Function: InsertFirst(PPNODE first, int iNo)
Purpose: Insert node at beginning
Parameters: PPNODE first (address of head), int iNo (data)
Return: void
Time Complexity: O(1)
================================================================================
*/
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    } 
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

/*
================================================================================
Function: InsertLast(PPNODE first, int iNo)
Purpose: Insert node at end of list
Parameters: PPNODE first (address of head), int iNo (data)
Return: void
Time Complexity: O(n)
================================================================================
*/
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    } 
    else
    {
        // TODO: Add traversal to find last node
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{}

void DeleteFirst(PPNODE first)
{}

void DeleteLast(PPNODE first)
{}

void DeleteAtPos(PPNODE first, int iPos)
{}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
 | 11 | -> | 21 | -> | 51 | -> | 101 | -> NULL

================================================================================
Memory Diagram:
================================================================================

After all InsertFirst calls:
head → [11|→] → [21|→] → [51|→] → [101|NULL]

head
 │
 ▼
+----------+    +----------+    +----------+    +-----------+
| 11 |  •--|--->| 21 |  •--|--->| 51 |  •--|--->|101 | NULL |
+----------+    +----------+    +----------+    +-----------+

Display Output:
 | 11 | -> | 21 | -> | 51 | -> | 101 | ->NULL

================================================================================
Pointer/Logic Explanation:
================================================================================

Display Function:
- printf(" | %d | ->", first->data) prints: | data | ->
- Loop continues while first != NULL
- After loop exits, printf("NULL\n") marks end of chain
- Creates visual chain representation

Example Trace:
Iteration 1: Print " | 11 | ->", move to 21
Iteration 2: Print " | 21 | ->", move to 51
Iteration 3: Print " | 51 | ->", move to 101
Iteration 4: Print " | 101 | ->", move to NULL
Exit loop:   Print "NULL"

Result: " | 11 | -> | 21 | -> | 51 | -> | 101 | ->NULL"

InsertFirst Function:
- Allocates memory for a new node.
- Inserts the node at the beginning of the list.
- Updates the HEAD pointer.
- Performs insertion in O(1) time without traversal.

================================================================================
Operations Performed
================================================================================
1. Created an empty linked list.
2. Inserted four nodes using InsertFirst().
3. Updated the HEAD pointer after every insertion.
4. Traversed the linked list using Display().
5. Displayed each node in pipe-and-arrow format.
6. Printed NULL to indicate the end of the list.

================================================================================
Time Complexity:
================================================================================
InsertFirst()    : O(1) - Direct insertion
Display()        : O(n) - Visit all nodes
Space Complexity : O(1) - Constant extra space

================================================================================
Conclusion:
================================================================================

Program 023 enhances the Display() function by presenting the linked list
using a clear pipe-and-arrow format. This visual representation makes node
connections easier to understand while preserving the same traversal logic.
The InsertFirst() function continues to insert nodes at the beginning in
O(1) time without requiring traversal, demonstrating efficient linked list
construction and improved output readability.

================================================================================
*/
