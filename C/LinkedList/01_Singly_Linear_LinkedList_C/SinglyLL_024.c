/*
================================================================================
Program Name    : Singly Linked List - Count Function Implementation
Program Number  : 024 
Description     : This program implements the Count() function to determine
                  the total number of nodes in a singly linked list.
                  Display() prints the linked list using enhanced
                  formatting, while InsertFirst() builds the list by
                  inserting nodes at the beginning.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. Count Function Implementation
5. While Loop for Traversal
6. Integer Counter Variable
7. Return Value Handling

Key Learning Points:
- Count() traverses all nodes and returns total count
- iCount initialized to 0 before loop
- Incremented for each node visited
- Returns count when loop exits
- O(n) time complexity for traversal
- iRet variable stores returned count value
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
Purpose: Count total number of nodes in linked list
Parameters: PNODE first (pointer to first node)
Return: int (total count)
Time Complexity: O(n)
================================================================================
*/
int Count(PNODE first)
{
    int iCount = 0;
    
    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    
    return iCount;
}

/*
================================================================================
Function: InsertFirst(PPNODE first, int iNo)
Purpose: Insert node at beginning of list
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
    int iRet = 0;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n", iRet);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
 | 11 | -> | 21 | -> | 51 | -> | 101 | -> NULL
Number of nodes are : 4

================================================================================
Memory Diagram:
================================================================================

After all InsertFirst calls:
head → [11|→] → [21|→] → [51|→] → [101|NULL]

Display Output:
 | 11 | -> | 21 | -> | 51 | -> | 101 | ->NULL

Count Output:
Number of nodes are : 4

================================================================================
Pointer/Logic Explanation:
================================================================================

Count Function:
- Initialize iCount = 0 (counter starts at 0)
- while(first != NULL) loops through all nodes
- iCount++ increments counter for each node
- first = first->next moves to next node
- When loop exits (first = NULL), return iCount

Execution Trace:
Before: first = head (points to 11)
Iter 1: iCount = 1, first = 21
Iter 2: iCount = 2, first = 51
Iter 3: iCount = 3, first = 101
Iter 4: iCount = 4, first = NULL
Exit:   return 4

Main Function:
- Calls Count(head).
- Receives the returned node count.
- Stores the returned value in iRet.
- Displays the total number of nodes using printf().

Display Function:
- Prints each node in chain format

================================================================================
Operations Performed
================================================================================
1. Created an empty linked list.
2. Inserted four nodes using InsertFirst().
3. Displayed all nodes using Display().
4. Traversed the linked list using Count().
5. Counted each node during traversal.
6. Returned the total number of nodes.
7. Displayed the returned count.

================================================================================
Time Complexity:
================================================================================
Display()        : O(n) - Visit all n nodes
Count()          : O(n) - Visit all n nodes
InsertFirst()    : O(1) - Direct insertion
Space Complexity : O(1) - Constant extra space

================================================================================
Conclusion:
================================================================================

Program 024 implements the Count() function to determine the total number of
nodes present in a singly linked list. The function traverses the entire list,
increments a counter for every node visited, and returns the final count to
the calling function. The Display() function visually presents the linked list,
while the returned value is stored in iRet and displayed. This program
demonstrates how traversal can be used not only for displaying data but also
for performing useful operations such as counting nodes.

================================================================================
*/
