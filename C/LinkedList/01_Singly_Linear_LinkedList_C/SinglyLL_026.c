/*
================================================================================ 
Program Name    : Singly Linked List - InsertFirst & InsertLast Functions
Program Number  : 026
Description     : This program implements InsertFirst() and InsertLast() functions.
                  InsertFirst inserts nodes at the beginning of the list in O(1) time,
                  while InsertLast inserts nodes at the end by traversing the list,
                  requiring O(n) time. Display() prints the linked list and Count()
                  returns the total number of nodes.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. InsertFirst Implementation
5. InsertLast Implementation with Traversal
6. Comparison Operator (==) vs Assignment (=)
7. While Loop for Traversal
8. Display and Count Functions

Key Learning Points:
- InsertFirst() performs insertion at the beginning in O(1).
- InsertLast() traverses the list before insertion, giving O(n).
- Both functions handle empty and non-empty linked lists.
- Display() traverses and prints all nodes.
- Count() returns the total number of nodes.

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
FIXED: Use == for comparison (was = assignment operator)
================================================================================
*/
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    
    if(*first == NULL)          // FIXED: Use == not =
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
    
    if(*first == NULL)          // Linked List is Empty
    {
        *first = newn;
    }
    else                       // Linked List contains at least one Node
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

Display Output:
|11| -> |21| -> |51| -> |101| -> NULL

Count Result:
Number of Nodes: 4

After InsertFirst():

head → [11] → [21] → [51] → [101] → NULL

Example after InsertLast(121):

head → [11] → [21] → [51] → [101] → [121] → NULL

Count Result:
Number of Nodes: 5

================================================================================
Pointer/Logic Explanation:
================================================================================

CRITICAL BUG FIX - InsertFirst:

WRONG:
if(*first = NULL)    // Assignment operator - MODIFIES *first!
{
    *first = newn;
}

CORRECT:
if(*first == NULL)   // Comparison operator - checks condition only
{
    *first = newn;
}

Common Mistake:
- '=' is the assignment operator.
- '==' is the comparison operator.
- Using '=' inside an if condition changes the value instead of comparing it,
  leading to incorrect program behavior.

Why This Matters:
- = is assignment: changes the value
- == is comparison: checks equality
- In condition, must use == to check
- Using = will assign NULL and cause logic error

InsertFirst Function:
- Allocates new node with malloc
- Sets data and next = NULL
- If list empty (*first == NULL): new node becomes head
- If list has nodes: new node points to old head, becomes new head
- O(1) - no traversal needed

InsertLast Function:
- Allocate and initialize a new node.
- If the list is empty, make the new node the head.
- Otherwise, traverse until the last node is reached.
- Link the last node to the new node.

Execution Trace - InsertFirst Calls:

Call 1: InsertFirst(&head, 101)
- List: 101 → NULL

Call 2: InsertFirst(&head, 51)
- List: 51 → 101 → NULL

Display and Count work on final list showing all 4 nodes

================================================================================
Time Complexity:
================================================================================
InsertFirst() : O(1)
InsertLast()  : O(n)
Display()     : O(n)
Count()       : O(n)
Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 026 implements both InsertFirst() and InsertLast() operations for a 
Singly Linked List. InsertFirst() inserts a node at the beginning in O(1) time, 
while InsertLast() inserts a node at the end by traversing the list, resulting in O(n) time.
Display() and Count() verify the linked list by printing its contents and returning
the total number of nodes.Together, these functions demonstrate the fundamental insertion 
operations of a Singly Linked List.

================================================================================
*/
