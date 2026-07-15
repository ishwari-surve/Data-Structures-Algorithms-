/*
================================================================================
Program Name    : Doubly Linear Linked List - InsertAtPos Operation 
Program Number  : 010
Description     : This program extends the Doubly Linear Linked List by
                  implementing the InsertAtPos() operation. It allows a
                  new node to be inserted at any valid position while
                  maintaining correct forward and backward links between
                  adjacent nodes. Position validation is performed before
                  insertion to ensure safe operation.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================

Concepts Used:

1. Doubly Linear Linked List
2. Self-Referential Structure
3. Dynamic Memory Allocation (malloc)
4. InsertFirst()
5. InsertLast()
6. InsertAtPos()
7. Position Validation
8. Forward and Backward Pointer Manipulation
9. Display()
10. Count()

Key Learning Points:

- InsertAtPos() inserts a node at any valid position.
- Count() is used to validate the given position.
- Position 1 calls InsertFirst().
- Last position calls InsertLast().
- Middle insertion updates both next and prev pointers.
- Proper pointer manipulation preserves list integrity.
- Display() verifies the updated linked list.
- Count() confirms the total number of nodes.

================================================================================
*/
//Doubly linked list 10
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

================================================================================
Pointer / Logic Explanation
================================================================================

InsertAtPos()

• Calls Count() to validate the specified position.
• Position 1 calls InsertFirst().
• Last position calls InsertLast().
• Otherwise,
  - Traverses to the node before the insertion position.
  - Creates a new node.
  - Updates next pointer of the new node.
  - Updates prev pointer of the following node.
  - Links previous node with the new node.
  - Updates prev pointer of the new node.
• Both forward and backward links remain intact.

DeleteFirst()

• Removes the first node.
• Updates first pointer.
• Sets prev of new first node to NULL.

DeleteLast()

• Traverses to the second last node.
• Deletes the last node.
• Sets next of the new last node to NULL.

Display()

• Traverses the list from first to last.
• Displays all node elements.

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
8. Inserted a new node at the specified position.
9. Updated both next and prev links.
10. Displayed the final linked list.
11. Counted the updated number of nodes.

================================================================================
Time Complexity
================================================================================

InsertFirst()      : O(1)
InsertLast()       : O(n)
InsertAtPos()      : O(n)
DeleteFirst()      : O(1)
DeleteLast()       : O(n)
Display()          : O(n)
Count()            : O(n)

Space Complexity   : O(1)

================================================================================
Conclusion
================================================================================

Program 010 implements the InsertAtPos() operation in a Doubly Linear
Linked List. After validating the specified position, the program inserts
a new node by correctly updating both next and prev pointers of the
adjacent nodes. This ensures the integrity of the doubly linked list while
supporting insertion at any valid position. The updated list is verified
using Display() and Count() operations.

================================================================================
*/
