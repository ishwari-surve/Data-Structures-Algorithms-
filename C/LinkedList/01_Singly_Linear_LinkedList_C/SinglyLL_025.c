/*
================================================================================
Program Name : Singly Linked List - Traversal Using Implicit NULL Check
Program Number  : 025
Description     : This program demonstrates the use of cleaner
                  traversal syntax using while(first) instead of
                  while(first != NULL). It implements Display(), 
                  Count(), and InsertFirst() functions to build,
                  display, and count nodes in a singly linked list.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. While Loop (while(first) instead of while(first != NULL))
5. Display Function
6. Count Function
7. InsertFirst Function
8. Function Implementation

Key Learning Points:
- while(first) and while(first != NULL) are equivalent
- Cleaner syntax using implicit NULL check
- Display formats output with pipes and arrows
- Count returns total node count
- InsertFirst adds nodes at beginning O(1)
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
typedef struct node* PNODE;
typedef struct node** PPNODE;

/*
================================================================================
Function: Display(PNODE first)
Purpose: Display all nodes in linked list
Parameters: PNODE first (pointer to first node)
Return: void
Time Complexity: O(n)
================================================================================
*/
void Display(PNODE first)
{
    while(first)
    {
        printf("|%d| -> ", first->data);
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
Time Complexity: O(n)
================================================================================
*/
int Count(PNODE first)
{
    int iCount = 0;
    
    while(first)
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

void InsertLast(PPNODE first, int iNo)
{
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{
}

void DeleteFirst(PPNODE first)
{
}

void DeleteLast(PPNODE first)
{
}

void DeleteAtPos(PPNODE first, int iPos)
{
}

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
    
    printf("Number of Nodes: %d\n", iRet);
    
    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
|11| -> |21| -> |51| -> |101| -> NULL
Number of Nodes: 4

================================================================================
Memory Diagram:
================================================================================

After all InsertFirst calls:
head → [11|→] → [21|→] → [51|→] → [101|NULL]

Display Output:
|11| -> |21| -> |51| -> |101| -> NULL

Count Result:
Number of Nodes: 4

================================================================================
Pointer/Logic Explanation:
================================================================================

Display Function:
- while(first) equivalent to while(first != NULL)
- Prints each node: |data| ->
- Moves to next node: first = first->next
- Exits when first becomes NULL
- Prints "NULL" to mark end of chain

Count Function:
- Initializes counter iCount = 0
- while(first) loops through all nodes
- Increments counter for each node
- Returns total count when loop exits

InsertFirst Function:
- Allocates new node with malloc
- Sets data and next = NULL
- If list empty: new node becomes head
- If list has nodes: new node becomes first, points to old first

Syntax Note:

while(first)
{
    ...
}

is equivalent to

while(first != NULL)
{
    ...
}

A pointer evaluates to TRUE whenever it contains a valid
address and FALSE when it becomes NULL. Therefore, both
forms produce identical results, with while(first) being
the shorter and cleaner syntax.

Main Function:
- Creates empty list (head = NULL)
- Inserts 4 nodes at beginning: 101, 51, 21, 11
- Order becomes: 11 → 21 → 51 → 101
- Displays list
- Counts nodes and stores in iRet
- Prints count result

================================================================================
Operations Performed
================================================================================
1. Created an empty linked list.
2. Inserted four nodes using InsertFirst().
3. Displayed all nodes using Display().
4. Traversed the list using Count().
5. Counted the total number of nodes.
6. Stored the returned count in iRet.
7. Displayed the total number of nodes.

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

Program 025 demonstrates that while(first) is a concise alternative to
while(first != NULL) for linked list traversal. The Display() and Count()
functions use this cleaner syntax while maintaining identical behavior.
InsertFirst() efficiently inserts nodes at the beginning in O(1) time,
resulting in a simple and readable implementation of fundamental singly
linked list operations.

================================================================================
*/
