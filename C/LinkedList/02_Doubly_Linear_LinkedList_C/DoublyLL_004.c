/*
================================================================================ 
Program Name    : Doubly Linear Linked List - InsertFirst and InsertLast
Program Number  : 004
Description     : This program implements doubly linked list with InsertFirst()
                  and InsertLast() functions. Each node has prev and next pointers
                  allowing bidirectional traversal. InsertFirst adds nodes at
                  beginning with prev/next updates. InsertLast adds nodes at end
                  with prev/next updates. Display and Count functions included.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Doubly Linked List Structure
2. Previous Pointer (prev)
3. Next Pointer (next)
4. #pragma pack(1) for memory optimization
5. PNODE and PPNODE typedef
6. Dynamic Memory Allocation (malloc)
7. InsertFirst with prev/next updates
8. InsertLast with prev/next updates
9. Bidirectional Linking
10. Display Function
11. Count Function

Key Learning Points:
- Each node has data, next, and prev pointers
- prev pointer points to previous node
- next pointer points to next node
- InsertFirst updates both next and prev
- InsertLast updates both next and prev
- (*first)->prev = newn crucial for linking
- newn->prev = temp crucial for bidirectional link
- O(1) for InsertFirst (no traversal)
- O(n) for InsertLast (must find last node)
- Bidirectional traversal possible
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
Purpose: Display all nodes in doubly linked list (forward direction)
Parameters: PNODE first (pointer to first node)
Return: void
Time Complexity: O(n)
================================================================================
*/
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d| <-> ", first->data);
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
Purpose: Insert node at beginning of doubly linked list
Parameters: PPNODE first (address of head), int iNo (data)
Return: void
Time Complexity: O(1)

Key Updates from Singly LL:
- newn->prev = NULL (initialize prev to NULL)
- (*first)->prev = newn (link old first's prev to new node)
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
        (*first)->prev = newn;      // Old first's prev points to new node
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

Key Updates from Singly LL:
- newn->prev = NULL (initialize prev to NULL)
- newn->prev = temp (link new node's prev to last node)
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
        newn->prev = temp;          // Link new node's prev to last node
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

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes : %d\n",iRet);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
|11| <-> |21| <-> |51| <-> |101| <-> |111| <-> |121| <-> NULL
Number of nodes : 6

================================================================================
Memory Diagram:
================================================================================

Node Structure (with #pragma pack(1)):
Total: 20 bytes (4 data + 8 next + 8 prev)

After all operations:
head → [11] ↔ [21] ↔ [51] ↔ [101] ↔ [111] ↔ [121]

Forward Chain:
head → [11|prev:NULL, next:↓|] 
            ↓
        [21|prev:↑, next:↓|]
            ↓
        [51|prev:↑, next:↓|]
            ↓
        [101|prev:↑, next:↓|]
            ↓
        [111|prev:↑, next:↓|]
            ↓
        [121|prev:↑, next:NULL|]

Bidirectional Links:
11 ↔ 21 ↔ 51 ↔ 101 ↔ 111 ↔ 121

Forward: 11 → 21 → 51 → 101 → 111 → 121 → NULL
Backward: 121 → 111 → 101 → 51 → 21 → 11 → NULL

================================================================================
Pointer/Logic Explanation:
================================================================================

Doubly Linked List vs Singly Linked List:

Singly:
[data | next] → [data | next] → [data | NULL]

Doubly:
[NULL|11|→] ⇄ [←|21|→] ⇄ [←|51|NULL]

Comparison Between Singly and Doubly Linked Lists

Singly:
- Only forward traversal possible
- Backward traversal not possible
- One link pointer (next) per node

Doubly:
- Forward and backward traversal possible
- Two link pointers (next and prev) per node
- More memory but more flexibility

InsertFirst Logic:

Step 1: Allocate and initialize
  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

Step 2: Check if empty
  if(NULL == *first)
  └─ New node becomes head
  └─ Both next and prev remain NULL

Step 3: If not empty
  newn->next = *first;           // New node points to old first
  (*first)->prev = newn;         // Old first's prev points back to new node
  *first = newn;                 // New node becomes head

Important: (*first)->prev = newn
└─ This creates backward link
└─ Essential for doubly linked list
└─ Allows traversal from head to new node and back


InsertLast Logic:

Step 1: Allocate and initialize
  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

Step 2: Check if empty
  if(NULL == *first)
  └─ New node becomes head
  └─ Both next and prev remain NULL

Step 3: If not empty
  temp = *first;
  
  // Traverse to last node
  while(temp->next != NULL)
  {
      temp = temp->next;
  }
  
  temp->next = newn;             // Link last node to new node
  newn->prev = temp;             // Link new node back to last node

Important: newn->prev = temp
└─ Creates backward link
└─ New node can now reach previous node
└─ Completes bidirectional chain


Execution Trace - InsertFirst Calls:

Call 1: InsertFirst(&head, 51)
- head = NULL initially
- newn allocated, data=51
- *first == NULL? YES
- *first = newn
- List: [51|NULL|NULL]

Call 2: InsertFirst(&head, 21)
- head points to 51
- newn allocated, data=21
- *first == NULL? NO
- newn->next = 51node
- 51->prev = newn(backward link)
- *first = newn
- List: 21 ↔ 51

Call 3: InsertFirst(&head, 11)
- head points to 21
- newn allocated, data=11
- *first == NULL? NO
- newn->next = 21node
- 21node->prev = newn (backward link)
- *first = newn
- List: 11 ↔ 21 ↔ 51


Execution Trace - InsertLast Calls:

Call 4: InsertLast(&head, 101)
- head points to 11
- newn allocated, data=101
- *first == NULL? NO
- temp = head (11)
- while(temp->next != NULL): traverse to 51
- temp now points to the last node (51)
- temp->next = newn (51 points to 101)
- newn->prev = temp (101 points back to 51)
- List: 11 ↔ 21 ↔ 51 ↔ 101

Call 5: InsertLast(&head, 111)
- temp traverses from 11 to 101
- 101->next = newn (111)
- newn->prev = 101
- List: 11 ↔ 21 ↔ 51 ↔ 101 ↔ 111

Call 6: InsertLast(&head, 121)
- temp traverses from 11 to 111
- 111->next = newn (121)
- newn->prev = 111
- List: 11 ↔ 21 ↔ 51 ↔ 101 ↔ 111 ↔ 121

Importance of the prev Pointer:

Forward Traversal (using next):
  temp = head;
  while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
  }
  Output: 11 21 51 101 111 121

Backward Traversal (using prev):
  temp = last_node;
  while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->prev;
  }
  Output: 121 111 101 51 21 11

 Note:

In a Singly Linked List, backward traversal is not possible because
each node stores only the address of its next node.

In a Doubly Linked List, every node stores both next and prev pointers,
allowing traversal in both forward and backward directions.

Backward traversal is possible only because each node maintains a
pointer to its previous node (prev).

================================================================================
Time Complexity:
================================================================================
InsertFirst()    : O(1) - No traversal
InsertLast()     : O(n) - Must traverse to last node
Display()        : O(n) - Visit all nodes
Count()          : O(n) - Visit all nodes
Space Complexity : O(1) - Constant extra space (node pointers only)

================================================================================
Differences from Singly LL Programs:
================================================================================

Singly LL Node:
    struct node
    {
        int data;
        struct node *next;
    };

Doubly LL Node:
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    };

Additional Updates in Doubly Linked List:

InsertFirst():
    Singly : newn->next = *first;
             *first = newn;

    Doubly : newn->next = *first;
             (*first)->prev = newn;
             *first = newn;

InsertLast():
    Singly : temp->next = newn;

    Doubly : temp->next = newn;
             newn->prev = temp;

Each node now maintains both forward and backward links, allowing
bidirectional traversal through the linked list.

================================================================================
Conclusion:
================================================================================

Program 004 extends the Doubly Linear Linked List by implementing both
InsertFirst() and InsertLast() operations. Unlike a Singly Linked List,
every insertion updates both the next and previous pointers, maintaining
bidirectional links between adjacent nodes. The program demonstrates how
nodes can be inserted efficiently at both ends while preserving the
integrity of the list.

================================================================================
*/
