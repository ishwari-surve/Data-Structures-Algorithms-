/*
================================================================================
Program Name    : Doubly Linear Linked List - Position Validation Framework
Program Number  : 009
Description     : This program extends the Doubly Linear Linked List by
                  introducing position validation for InsertAtPos() and
                  DeleteAtPos() operations. The program verifies whether
                  the given position is valid before performing insertion
                  or deletion. The actual position-based operations will
                  be implemented in the subsequent programs.

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
9. Position Validation
10. Count() Function
11. Display() Function

Key Learning Points:

- Count() is used to validate user positions.
- InsertAtPos() accepts positions from 1 to Count()+1.
- DeleteAtPos() accepts positions from 1 to Count().
- Invalid positions are rejected immediately.
- Position validation avoids invalid memory access.
- Existing insertion and deletion operations remain unchanged.
- Position-based logic will be completed in future programs.

================================================================================
*/
//Doubly linked list 9
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

Initial List

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

InsertAtPos() and DeleteAtPos()

Position validation is performed before executing the
actual insertion or deletion operation.

================================================================================
Pointer / Logic Explanation
================================================================================

InsertAtPos()

• Calls Count() to determine the total number of nodes.
• Accepts positions from 1 to Count()+1.
• Invalid positions display an error message.
• Position 1 calls InsertFirst().
• Position Count()+1 calls InsertLast().
• Middle insertion logic will be implemented later.

DeleteAtPos()

• Calls Count() before deletion.
• Accepts positions from 1 to Count().
• Invalid positions are rejected.
• Position 1 calls DeleteFirst().
• Position Count() calls DeleteLast().
• Middle deletion logic will be implemented later.

Display()

• Traverses the list using next pointer.
• Displays every node from first to last.

Count()

• Traverses the linked list.
• Returns the total number of nodes.

================================================================================
Operations Performed
================================================================================

1. Created an empty Doubly Linear Linked List.
2. Inserted nodes using InsertFirst().
3. Inserted nodes using InsertLast().
4. Displayed the linked list.
5. Counted the total number of nodes.
6. Deleted the first node.
7. Deleted the last node.
8. Added position validation in InsertAtPos().
9. Added position validation in DeleteAtPos().
10. Prevented invalid position access.

================================================================================
Time Complexity
================================================================================

InsertFirst()      : O(1)
InsertLast()       : O(n)
DeleteFirst()      : O(1)
DeleteLast()       : O(n)
InsertAtPos()      : O(n) (Validation Only)
DeleteAtPos()      : O(n) (Validation Only)
Display()          : O(n)
Count()            : O(n)

Space Complexity   : O(1)

================================================================================
Conclusion
================================================================================

Program 009 introduces position validation for InsertAtPos() and
DeleteAtPos() operations in a Doubly Linear Linked List. The program
ensures that only valid positions are accepted before performing any
operation, preventing invalid memory access and improving reliability.
This validation framework prepares the linked list for complete
position-based insertion and deletion implementations in the upcoming
programs.

================================================================================
*/
