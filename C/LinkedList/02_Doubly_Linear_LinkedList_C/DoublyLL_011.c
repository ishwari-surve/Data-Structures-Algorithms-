/*
================================================================================
Program Name    : Doubly Linear Linked List - DeleteAtPos Operation 
Program Number  : 011
Description     : This program completes the implementation of the Doubly
                  Linear Linked List by implementing the DeleteAtPos()
                  operation. It removes a node from any valid position
                  while maintaining proper forward and backward links
                  between adjacent nodes. Position validation is performed
                  before deletion to ensure safe operation.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================

Concepts Used:

1. Doubly Linear Linked List
2. Self-Referential Structure
3. Dynamic Memory Allocation (malloc/free)
4. InsertFirst()
5. InsertLast()
6. InsertAtPos()
7. DeleteFirst()
8. DeleteLast()
9. DeleteAtPos()
10. Display()
11. Count()

Key Learning Points:

- DeleteAtPos() removes a node from any valid position.
- Count() validates the deletion position.
- Position 1 calls DeleteFirst().
- Last position calls DeleteLast().
- Middle node deletion updates both next and prev pointers.
- Memory occupied by deleted node is released using free().
- Display() verifies the updated linked list.
- Count() confirms the updated number of nodes.

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
   int iCount = 0;
   int i = 0;
   PNODE temp = NULL;
   PNODE newn = NULL;
  
   iCount = Count(*first);

   if((iPos < 1)||(iPos > iCount+1))
   {
     printf("Invlaid position\n");
     return;
   }
   if(iPos == 1)
   {
     InsertFirst(first,iNo);
   }
   else if(iPos == iCount+1)
   {
      InsertLast(first,iNo);
   }
   else
   {
      temp = *first;
      newn = (PNODE)malloc(sizeof(NODE));

      newn->data =iNo;
      newn->next = NULL;
      newn->prev = NULL;

      for(i=1; i < iPos-1; i++)
      {
         temp = temp->next;
      }
      newn->next = temp->next;
      temp->next->prev = newn;  //$
      temp->next = newn;
      newn->prev = temp;       // $
    }


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
    int iCount = 0;
    int i = 0;
    PNODE temp = NULL;
  
   iCount = Count(*first);

   if((iPos < 1)||(iPos > iCount))
   {
     printf("Invlaid position\n");
     return;
   }
   if(iPos == 1)
   {
     DeleteFirst(first);
   }
   else if(iPos == iCount)
   {
      DeleteLast(first);
   }
   else
   {
      temp = *first;  // 100 intialized

      for(i=1; i < iPos-1; i++)
      {
         temp = temp->next;
      }
      temp->next = temp->next->next;
      free(temp->next->prev);
      temp->next->prev = temp;

   }


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
   InsertLast(&head,151);

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

   InsertAtPos(&head,105,4);

   Display(head);
   iRet = Count(head);
   printf("Number of elements are: %d\n",iRet);

   DeleteAtPos(&head,4);

    Display(head);
   iRet = Count(head);
   printf("Number of elements are: %d\n",iRet);

    return 0;
}
/*
================================================================================
Expected Output
================================================================================

NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> | 151 | <=> NULL
Number of elements are : 7

NULL <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> | 151 | <=> NULL
Number of elements are : 6

NULL <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are : 5

NULL <=> | 21 | <=> | 51 | <=> | 101 | <=> | 105 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are : 6

NULL <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are : 5

================================================================================
Memory Diagram
================================================================================

Initial List

head
 │
 ▼
NULL ⇄ [11] ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ [121] ⇄ [151] ⇄ NULL

After DeleteFirst()

head
 │
 ▼
NULL ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ [121] ⇄ [151] ⇄ NULL

After DeleteLast()

head
 │
 ▼
NULL ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ [121] ⇄ NULL

After InsertAtPos(105,4)

head
 │
 ▼
NULL ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [105] ⇄ [111] ⇄ [121] ⇄ NULL

After DeleteAtPos(4)

head
 │
 ▼
NULL ⇄ [21] ⇄ [51] ⇄ [101] ⇄ [111] ⇄ [121] ⇄ NULL
================================================================================
Pointer / Logic Explanation
================================================================================

DeleteAtPos()

• Calls Count() to validate the specified position.
• Position 1 calls DeleteFirst().
• Last position calls DeleteLast().
• Otherwise,
  - Traverses to the node before the deletion position.
  - Links previous node directly to the next node.
  - Updates prev pointer of the next node.
  - Frees the deleted node.
• Both forward and backward links remain correct.

InsertAtPos()

• Inserts a new node at any valid position.
• Updates both next and prev pointers.

DeleteFirst()

• Removes the first node.
• Updates first pointer.
• Sets prev of new first node to NULL.

DeleteLast()

• Traverses to the second last node.
• Deletes the last node.
• Sets next pointer to NULL.

Display()

• Traverses the list from first to last.
• Displays every node.

Count()

• Traverses the list.
• Returns total number of nodes.

================================================================================
Operations Performed
================================================================================

1. Created an empty Doubly Linear Linked List.
2. Inserted nodes at the beginning.
3. Inserted nodes at the end.
4. Displayed the linked list.
5. Counted the total number of nodes.
6. Deleted the first node.
7. Deleted the last node.
8. Inserted a node at a specified position.
9. Deleted a node from a specified position.
10. Updated both next and prev pointers.
11. Displayed the final linked list.
12. Counted the updated number of nodes.

================================================================================
Time Complexity
================================================================================

InsertFirst()      : O(1)
InsertLast()       : O(n)
InsertAtPos()      : O(n)
DeleteFirst()      : O(1)
DeleteLast()       : O(n)
DeleteAtPos()      : O(n)
Display()          : O(n)
Count()            : O(n)

Space Complexity   : O(1)

================================================================================
Conclusion
================================================================================

Program 011 completes the Doubly Linear Linked List implementation by
adding the DeleteAtPos() operation. The program safely removes a node
from any valid position by correctly updating both next and prev pointers
of the adjacent nodes. Together with insertion, deletion, display, and
count operations, this program provides a complete implementation of a
Doubly Linear Linked List in C.

================================================================================
*/
