/*
================================================================================
Program Name    : Doubly Linear Linked List - InsertFirst() Implementation
Program Number  : 003
Description     : This program implements the InsertFirst() operation of a
                  Doubly Linear Linked List. It creates a new node using
                  dynamic memory allocation and inserts it at the beginning
                  of the list while correctly updating both the next and
                  previous pointers. The InsertLast(), Display(), Count(),
                  and deletion functions are currently provided as skeletons
                  for future implementation.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structure
3. Doubly Linked List
4. Dynamic Memory Allocation (malloc)
5. InsertFirst() Implementation
6. Previous Pointer Handling
7. Next Pointer Handling
8. Call by Address (PPNODE)

Key Learning Points:
- Every new node initializes both next and prev pointers to NULL.
- InsertFirst() updates both forward and backward links.
- The previous pointer of the old first node must point to the new node.
- Head pointer is updated after establishing all links.
- InsertFirst() performs insertion in constant time O(1).

================================================================================
*/
//Doubly linked list 
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct  node
{
    int data;
    struct node *next;
    struct  node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
   
}

int Count(PNODE first)
{
   return 0;
}

void InsertFirst(PPNODE first ,int iNo)
{
   PNODE newn = NULL;

   newn = (PNODE)malloc(sizeof(NODE));

   newn->data = iNo;
   newn->next = NULL;
   newn->prev = NULL;         //$

   if(NULL == *first)
   {
       *first = newn;
   }
   else
   {  
       newn->next= *first;
        (*first)->prev = newn;   //$
        *first= newn;              
   }
}

void InsertLast(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

   newn->data = iNo;
   newn->next = NULL;
   newn->prev = NULL;         //$ means new line added in the code

   if(NULL == *first)
   {
       *first = newn;
   }
   else
   {
     
   }

}

void InsertAtPos(PPNODE first,int iNo,int iPos)
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

   InsertFirst(&head,51);
   InsertFirst(&head,21);
   InsertFirst(&head,11);

    return 0;
}
/*
================================================================================
Expected Output:
================================================================================

(No Output)

Three nodes are inserted successfully at the beginning of the list.

================================================================================
Memory Diagram:
================================================================================

Initially:

head
 │
 ▼
NULL


InsertFirst(51)

head
 │
 ▼
NULL <- [51] -> NULL


InsertFirst(21)

head
 │
 ▼
NULL <- [21] <==> [51] -> NULL


InsertFirst(11)

head
 │
 ▼
NULL <- [11] <==> [21] <==> [51] -> NULL

================================================================================
Pointer / Logic Explanation:
================================================================================

InsertFirst() performs the following steps:

Step 1:
Allocate memory for a new node.

Step 2:
Store the given data inside the node.

Step 3:
Initialize both pointers.

newn->next = NULL;
newn->prev = NULL;

Step 4:
If the linked list is empty,

head
 │
 ▼
NULL

the new node becomes the first node.

Step 5:
Otherwise,

newn->next = *first;
(*first)->prev = newn;
*first = newn;

This creates links in both directions.

Forward Link:
new node -----> old first node

Backward Link:
old first node -----> new node

Finally, the head pointer is updated.

================================================================================
Operations Performed:
================================================================================

- Created a Doubly Linked List node.
- Allocated memory dynamically using malloc().
- Initialized next and previous pointers.
- Inserted node at the beginning.
- Updated previous pointer of the old first node.
- Updated head pointer.

================================================================================
Time Complexity:
================================================================================

InsertFirst()     : O(1)
Space Complexity  : O(1)

================================================================================
Conclusion:
================================================================================

Program 003 demonstrates the implementation of InsertFirst() for a Doubly
Linear Linked List. Unlike a Singly Linked List, insertion at the beginning
requires updating both the next pointer of the new node and the previous
pointer of the existing first node. This maintains correct bidirectional
links between adjacent nodes while preserving constant-time insertion.

================================================================================
*/
