/*
================================================================================ 
Program Name    : Doubly Linear Linked List - DeleteLast Operation
Program Number  : 008
Description     : This program extends the Doubly Linear Linked List by
                  implementing the DeleteLast() operation. It demonstrates
                  insertion at both ends of the list, deletion of the first
                  node followed by deletion of the last node while maintaining
                  correct forward and backward links between all remaining nodes.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================

Concepts Used:

1. Doubly Linear Linked List
2. Self-Referential Structure
3. Dynamic Memory Allocation (malloc)
4. Memory Deallocation (free)
5. InsertFirst()
6. InsertLast()
7. DeleteFirst()
8. DeleteLast()
9. Display()
10. Count()
11. Forward and Backward Pointer Manipulation

Key Learning Points:

- DeleteLast() removes the last node from the list.
- Traversal is required to locate the second last node.
- The second last node becomes the new last node.
- The new last node's next pointer is updated to NULL.
- Memory occupied by the deleted node is released using free().
- DeleteFirst() and DeleteLast() correctly handle empty and single-node lists.
- Display() verifies the updated list after every deletion.
- Count() confirms the total number of remaining nodes.

================================================================================
*/
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
  printf("\nNULL <=> ");

  while (first != NULL)
   {
      printf("| %d | <=> ",first->data);
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
     PNODE temp = NULL;

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
      temp = *first;

      while(temp->next != NULL)
      {
         temp = temp->next;
      }
      temp->next = newn;    
      newn->prev = temp;        // $
   }

}

void InsertAtPos(PPNODE first,int iNo,int iPos)
{


}

void DeleteFirst(PPNODE first)
{

    if(*first==NULL)
    {
       return;
    }
    else if ((*first)->next==NULL)
    {
       free(*first);
       *first = NULL;
    }
    else
    {
        *first = (*first)->next;  //200
        free((*first)->prev);     // $
        (*first)->prev = NULL;    // $
    }

}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

     if(*first==NULL)
    {
      return;
    }
    else if ((*first)->next==NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
           temp = temp->next;   
        }
        free(temp->next);
        temp->next = NULL;
    }

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
   printf("Number of elements are: %d\n",iRet);

   DeleteFirst(&head);

   Display(head);
   iRet = Count(head);
   printf("Number of elements are: %d\n",iRet);

   DeleteLast(&head);

   Display(head);
   iRet = Count(head);
   printf("Number of elements are: %d\n",iRet);

    return 0;
}
/*
================================================================================
Expected Output
================================================================================

NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are : 6

NULL <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are : 5

NULL <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL
Number of elements are : 4

================================================================================
Memory Diagram
================================================================================

Initial Doubly Linked List

head
 │
 ▼
NULL ⇄ [11] ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ [121] ⇄ NULL

After DeleteFirst()

head
 │
 ▼
NULL ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ [121] ⇄ NULL

After DeleteLast()

head
 │
 ▼
NULL ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ NULL

================================================================================
Pointer / Logic Explanation
================================================================================

DeleteFirst()

• Checks whether the list is empty.
• If only one node is present, deletes that node and makes the list empty.
• Otherwise,
  - Moves first to the second node.
  - Frees the old first node.
  - Sets first->prev = NULL.
• Maintains both forward and backward links correctly.

DeleteLast()

• Checks whether the list is empty.
• If only one node is present, deletes it.
• Otherwise,
  - Traverses to the second last node.
  - Frees the last node.
  - Sets second last node's next pointer to NULL.
• The remaining nodes remain properly connected.

Display()

• Traverses the list from first to last.
• Displays every node using the next pointer.

Count()

• Traverses the list.
• Counts every node.
• Returns the total number of nodes.

================================================================================
Operations Performed
================================================================================

1. Created an empty Doubly Linear Linked List.
2. Inserted nodes at the beginning using InsertFirst().
3. Inserted nodes at the end using InsertLast().
4. Displayed the linked list.
5. Counted the total number of nodes.
6. Deleted the first node.
7. Updated the previous pointer of the new first node.
8. Displayed the updated linked list.
9. Deleted the last node.
10. Updated the next pointer of the new last node.
11. Displayed the final linked list.
12. Counted the remaining nodes.

================================================================================
Time Complexity
================================================================================

InsertFirst()     : O(1)
InsertLast()      : O(n)
DeleteFirst()     : O(1)
DeleteLast()      : O(n)
Display()         : O(n)
Count()           : O(n)

Space Complexity  : O(1)

================================================================================
Conclusion
================================================================================

Program 008 demonstrates the implementation of the DeleteLast() operation in
a Doubly Linear Linked List. Along with InsertFirst(), InsertLast(), and
DeleteFirst(), it completes the basic deletion operations while maintaining
correct forward and backward links. The program verifies the updated list
using Display() and Count(), providing a strong foundation for implementing
position-based insertion and deletion operations in subsequent programs.

================================================================================
*/
