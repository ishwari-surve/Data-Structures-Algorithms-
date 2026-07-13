/*
================================================================================
Program Name    : Singly Linked List - Correct NULL Comparison
Program Number  : 029
Description     : This program demonstrates the correct use of the comparison
                  operator while checking whether the linked list is empty.
                  InsertFirst() correctly uses *first == NULL before inserting
                  a node at the beginning of the list. Display() prints all
                  nodes, Count() returns the total number of nodes, and
                  InsertLast() is provided as a template for future
                  implementation.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. Pointer to Pointer (PPNODE)
5. Comparison Operator (==)
6. Display Function
7. Count Function
8. InsertFirst Function

Key Learning Points:
- Use == to compare pointers with NULL.
- *first == NULL checks whether the linked list is empty.
- InsertFirst() inserts a node at the beginning in O(1).
- Display() traverses and prints all nodes.
- Count() traverses the list and returns the total number of nodes.
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

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("|%d| -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first)
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

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
 | 11 | -> | 21 | -> | 51 | -> | 101 | ->NULL
Number of nodes are : 4

================================================================================
Memory Diagram:
================================================================================

After all InsertFirst() calls:

head
 │
 ▼
[11|•] → [21|•] → [51|•] → [101|NULL]

Display Output:

 | 11 | -> | 21 | -> | 51 | -> | 101 | ->NULL

Count Output:

Number of nodes are : 4

================================================================================
Pointer/Logic Explanation:
================================================================================

Correct NULL Comparison:

if(*first == NULL)

Explanation:
- '==' is the comparison operator.
- It checks whether the head pointer is NULL.
- If the list is empty, the new node becomes the first node.

InsertFirst Logic:

Step 1:
- Allocate memory for a new node using malloc().
- Store the given data.
- Initialize next pointer to NULL.

Step 2:
- Check whether the linked list is empty.

if(*first == NULL)

Step 3A: Empty List
- Make the new node the head node.

Step 3B: Non-empty List
- Make the new node point to the current head.
- Update head to point to the new node.

Display Function:

- Traverses the linked list node by node.
- Prints each node in the format:

|data| ->

- Stops when NULL is reached.

Count Function:

- Initializes iCount to 0.
- Visits every node once.
- Increments the counter for each node.
- Returns the total number of nodes.

Execution Trace:

InsertFirst(101)
List:
101

InsertFirst(51)
List:
51 → 101

InsertFirst(21)
List:
21 → 51 → 101

InsertFirst(11)
List:
11 → 21 → 51 → 101

Display:
 |11| -> |21| -> |51| -> |101| -> NULL

Count: 4

================================================================================
Operations Performed:
================================================================================
1. Created a self-referential structure for linked list nodes.
2. Defined PNODE and PPNODE using typedef.
3. Allocated memory dynamically using malloc().
4. Inserted nodes at the beginning using InsertFirst().
5. Used the correct comparison operator (*first == NULL) to check whether
   the linked list is empty.
6. Traversed and displayed all nodes using Display().
7. Counted the total number of nodes using Count().
8. Demonstrated the use of Pointer to Pointer (PPNODE) for modifying the
   head pointer.

================================================================================
Time Complexity:
================================================================================

InsertFirst()    : O(1)
Display()        : O(n)
Count()          : O(n)
InsertLast()     : O(1) for empty list (template)
Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 029 demonstrates the correct method of checking whether a linked list
is empty using the comparison operator (*first == NULL). InsertFirst()
efficiently inserts nodes at the beginning of the list in constant time,
while Display() and Count() traverse the list to print its contents and count
the total number of nodes. This program reinforces proper pointer comparison
and forms the foundation for implementing additional linked list operations.

================================================================================
*/
