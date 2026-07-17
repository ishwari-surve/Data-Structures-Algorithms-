/*
================================================================================ 
Program Name    : Singly Linked List - Defensive Programming Style
Program Number  : 027
Description     : This program demonstrates the defensive programming style by using
                  NULL == *first instead of *first == NULL while checking whether the 
                  linked list is empty. InsertFirst() inserts nodes at the beginning,
                  InsertLast() inserts nodes at the end, Display() prints the list,
                  and Count() returns the total number of nodes.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. Defensive Programming (NULL on left side)
5. InsertFirst Implementation
6. InsertLast Implementation with Traversal
7. While Loop for Traversal
8. Display and Count Functions

Key Learning Points:
- Defensive programming places constants on the left side of comparisons.
- Accidental assignment ( = ) is detected by the compiler.
- NULL == *first and *first == NULL are logically equivalent.
- InsertFirst() performs O(1) insertion.
- InsertLast() performs O(n) insertion.
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
    while(first != NULL)
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
Note: Uses defensive style NULL == *first
================================================================================
*/
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    
    if(NULL == *first)          // Defensive: NULL on left side
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
    PNODE temp = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    
    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
    }
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

Visual Chain:
|11| -> |21| -> |51| -> |101| -> NULL

================================================================================
Pointer/Logic Explanation:
================================================================================

Defensive Programming Style - NULL == *first:

Standard Style:
if(*first == NULL)

Defensive Style:
if(NULL == *first)

If '=' is used accidentally:

Standard:
if(*first = NULL)

Defensive:
if(NULL = *first)

The second form produces a compiler error because NULL cannot be assigned a value.

Why Defensive is Better:
If accidentally type = instead of ==:
- Standard: if(*first = NULL)   ❌ Compiles, assigns NULL
- Defensive: if(NULL = *first)  ✅ Compiler ERROR - can't assign to NULL

If '=' is accidentally used instead of '==', the compiler reports an error 
because NULL cannot be assigned a value.

InsertFirst Logic:
- Allocate new node
- if(NULL == *first): list empty, new node becomes head
- else: new node points to old head, becomes new head
- O(1) - no traversal

InsertLast Logic:
- Allocate new node
- if(*first == NULL): list empty, new node becomes head
- else: traverse to last node, link new node
- O(n) - must traverse entire list

================================================================================
Time Complexity:
================================================================================
InsertFirst()    : O(1) - No traversal
InsertLast()     : O(n) - Must find last node
Display()        : O(n) - Visit all nodes
Count()          : O(n) - Visit all nodes
Space Complexity : O(1) - Constant extra space

================================================================================
Conclusion:
================================================================================

Program 027 demonstrates the defensive programming style by placing
NULL on the left side of comparison expressions. Although
NULL == *first and *first == NULL produce the same logical result,
the defensive style helps detect accidental assignment mistakes during
compilation. The program also implements InsertFirst(), InsertLast(),
Display(), and Count() operations for a Singly Linked List.

================================================================================
*/
