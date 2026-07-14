/*
================================================================================
Program Name    : Doubly Linear Linked List - Display with Enhanced Formatting
Program Number  : 005
Description     : This program demonstrates the implementation of InsertFirst() 
                  and InsertLast() operations in a Doubly Linear Linked List. 
                  It explains how both next and prev pointers are maintained 
                  while inserting nodes at the beginning and end of the list.
                  The program also includes Display() and Count() 
                  functions to traverse the list and count the total number of nodes.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structure
3. PNODE and PPNODE typedef
4. Dynamic Memory Allocation (malloc)
5. InsertFirst() in Doubly Linked List
6. InsertLast() in Doubly Linked List
7. Forward Traversal using next Pointer
8. Previous Pointer (prev) Linking
9. Display() Function
10. Count() Function

Key Learning Points:

- Each node stores both next and prev pointers.
- prev pointer enables backward traversal.
- InsertFirst() updates both next and prev links.
- InsertLast() links the new node in both directions.
- Forward traversal is performed using the next pointer.
- Both insertion operations maintain bidirectional connectivity.
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
    struct node *prev;     // 8 bytes - pointer to previous node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node* PNODE;      // PNODE is alias for pointer to NODE
typedef struct node** PPNODE;    // PPNODE is alias for pointer to pointer to NODE

/*
================================================================================
Function: Display(PNODE first)
Purpose: Display all nodes with bidirectional link visualization
Parameters: PNODE first (pointer to first node)
Return: void
Time Complexity: O(n)

Enhanced formatting shows:
- NULL <=> at beginning (before first node)
- | data | <=> for each node (bidirectional connection)
- NULL at end (after last node)
================================================================================
*/
void Display(PNODE first)
{
    printf("\nNULL <=> ");

    while(first != NULL)
    {
        printf("| %d | <=> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

/*
================================================================================
Function: Count(PNODE first)
Purpose: Count total number of nodes in doubly linked list
Parameters: PNODE first (pointer to first node)
Return: int (total count)
Time Complexity: O(n)
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
Purpose: Insert node at beginning of doubly linked list
Parameters: PPNODE first (address of head), int iNo (data)
Return: void
Time Complexity: O(1)

Critical Updates for Doubly LL:
- newn->prev = NULL (initialize prev)
- (*first)->prev = newn (backward link)
================================================================================
*/
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;              // Initialize prev to NULL

    if(NULL == *first)              // Case 1: List is empty
    {
        *first = newn;
    }
    else                            // Case 2: List has nodes
    {
        newn->next = *first;        // New node points to old first
        (*first)->prev = newn;      // Old first's prev points to new node (CRITICAL)
        *first = newn;              // New node becomes head
    }
}

/*
================================================================================
Function: InsertLast(PPNODE first, int iNo)
Purpose: Insert node at end of doubly linked list
Parameters: PPNODE first (address of head), int iNo (data)
Return: void
Time Complexity: O(n)

Critical Updates for Doubly LL:
- newn->prev = NULL (initialize prev)
- newn->prev = temp (backward link to last node)
================================================================================
*/
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;              // Initialize prev to NULL

    if(NULL == *first)              // Case 1: List is empty
    {
        *first = newn;
    }
    else                            // Case 2: List has nodes
    {
        temp = *first;

        // Traverse to last node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;          // Link last node to new node
        newn->prev = temp;          // New node's prev links to last node (CRITICAL)
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

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

================================================================================
Memory Diagram:
================================================================================

Node Structure (20 bytes with pragma pack):
┌──────┬──────────┬──────────┐
│ data │ next     │ prev     │
│ (4B) │ (8B)     │ (8B)     │
└──────┴──────────┴──────────┘

Final List Structure:
NULL ← [11] ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ [121] → NULL
        ↑                                         ↑
      First                                     Last

Visual Representation:
┌─────┐      ┌─────┐      ┌─────┐      ┌─────┐      ┌─────┐      ┌─────┐
│ 11  │  ↔   │ 21  │  ↔   │ 51  │  ↔   │ 101 │  ↔   │ 111 │  ↔   │ 121 │
└─────┘      └─────┘      └─────┘      └─────┘      └─────┘      └─────┘
  ↑                                                                    ↓
head                                                               last node

Bidirectional Access:
Forward:  head → 11 → 21 → 51 → 101 → 111 → 121 → NULL
Backward: 121 → 111 → 101 → 51 → 21 → 11 → NULL (via prev pointers)

================================================================================
Pointer/Logic Explanation:
================================================================================

Display Function - Enhanced Formatting:

printf("\nNULL <=> ");
└─ Print NULL marker and <=> showing backward connection doesn't exist

while(first != NULL)
{
    printf("| %d | <=> ", first->data);
    first = first->next;
}
└─ Print each node with data and <=> showing bidirectional connection

printf("NULL\n");
└─ Print NULL marker and newline showing forward connection ends

Output Example:
NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> NULL

This clearly shows:
- NULL at start (no node before 11)
- <=> between nodes (bidirectional links)
- NULL at end (no node after 51)


InsertFirst Execution Trace:

Call 1: InsertFirst(&head, 51)
- head = NULL initially
- newn allocated with data=51
- newn->prev = NULL
- *first == NULL? YES
- *first = newn
- List: 51 (isolated)

Call 2: InsertFirst(&head, 21)
- head points to 51
- newn allocated with data=21
- newn->prev = NULL
- *first == NULL? NO
- newn->next = 51node
- 51node->prev = newn (CRITICAL: link back)
- *first = newn
- List: 21 ↔ 51

Call 3: InsertFirst(&head, 11)
- head points to 21
- newn allocated with data=11
- newn->prev = NULL
- *first == NULL? NO
- newn->next = 21node
- 21node->prev = newn (CRITICAL: link back)
- *first = newn
- List: 11 ↔ 21 ↔ 51

InsertLast Execution Trace:

Call 4: InsertLast(&head, 101)
- head points to 11
- newn allocated with data=101
- newn->prev = NULL
- *first == NULL? NO
- temp = head (11)
- while(temp->next != NULL): temp moves 11 → 21 → 51 → NULL stops
- temp points to 51 (last node)
- temp->next = newn (51 links to 101)
- newn->prev = temp (101 links back to 51) (CRITICAL)
- List: 11 ↔ 21 ↔ 51 ↔ 101

Call 5: InsertLast(&head, 111)
- temp traverses to 101 (last node)
- 101->next = newn (111)
- newn->prev = 101 (CRITICAL)
- List: 11 ↔ 21 ↔ 51 ↔ 101 ↔ 111

Call 6: InsertLast(&head, 121)
- temp traverses to 111 (last node)
- 111->next = newn (121)
- newn->prev = 111 (CRITICAL)
- List: 11 ↔ 21 ↔ 51 ↔ 101 ↔ 111 ↔ 121


Why <=> Format Important:
The prev pointer makes deletion and reverse traversal easier because
the previous node can be accessed directly without traversing from the head.

Singly LL:  | 11 | → | 21 | → | 51 | → NULL
└─ Only forward shown

Doubly LL:  NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> NULL
└─ Bidirectional shown clearly with <=>
└─ NULL boundaries shown at both ends
└─ Visual representation of bidirectional nature

================================================================================
Operations Performed:
================================================================================
1. Created a Doubly Linked List node.
2. Allocated memory dynamically using malloc().
3. Inserted nodes at the beginning.
4. Inserted nodes at the end.
5. Updated both next and prev pointers.
6. Traversed the list in forward direction.
7. Counted the total number of nodes.
8. Demonstrated bidirectional linking between nodes.

================================================================================
Time Complexity:
================================================================================
Display()         : O(n)
Count()           : O(n)
InsertFirst()     : O(1)
InsertLast()      : O(n)
Space Complexity  : O(1)

================================================================================
Conclusion:
================================================================================

Program 005 introduces insertion operations in a Doubly Linear Linked
List. Unlike a Singly Linked List, every node maintains both next and
prev pointers, enabling bidirectional traversal. The program
demonstrates how InsertFirst() and InsertLast() correctly update both
forward and backward links while preserving the integrity of the list.
This serves as the foundation for implementing deletion operations,
backward traversal, and more advanced Doubly Linked List algorithms.

================================================================================

*/
