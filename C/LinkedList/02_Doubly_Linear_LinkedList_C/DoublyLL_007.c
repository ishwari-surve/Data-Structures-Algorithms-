/*
================================================================================
Program Name    : Doubly Linear Linked List - DeleteFirst Operation
Program Number  : 007 
Description     : This program demonstrates the implementation of the
                  DeleteFirst() operation in a Doubly Linear Linked List.
                  It performs insertion at both the beginning and end of
                  the list, displays the elements, deletes the first node,
                  and updates the forward as well as backward links
                  correctly.

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
6. DeleteFirst()
7. Display()
8. Count()
9. Forward and Backward Linking
10. Pointer Manipulation
11. Memory Deallocation using free()

Key Learning Points:

- Each node stores both next and prev pointers.
- InsertFirst() updates both forward and backward links.
- InsertLast() connects the new node with the previous last node.
- DeleteFirst() safely removes the first node.
- The second node becomes the new first node.
- Previous pointer of the new first node is set to NULL.
- Memory occupied by the deleted node is released using free().
- Display() traverses the list from first to last.
- Count() returns the total number of nodes.
- Proper pointer updates prevent dangling references.
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


    return 0;
}
/*
================================================================================
Expected Output

NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are : 6

NULL <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are : 5

================================================================================

Operations Performed

1. Created an empty Doubly Linear Linked List.
2. Inserted nodes at the beginning using InsertFirst().
3. Inserted nodes at the end using InsertLast().
4. Displayed all nodes in forward direction.
5. Counted the total number of nodes.
6. Deleted the first node using DeleteFirst().
7. Updated both next and prev pointers correctly.
8. Freed memory occupied by the deleted node.
9. Displayed the updated linked list.
10. Counted the remaining nodes.

================================================================================

Time Complexity

InsertFirst()    : O(1)
InsertLast()     : O(n)
DeleteFirst()    : O(1)
Display()        : O(n)
Count()          : O(n)

Space Complexity : O(1)

================================================================================

Conclusion

Program 007 demonstrates the DeleteFirst() operation in a Doubly Linear
Linked List. After removing the first node, the second node becomes the
new head of the list and its previous pointer is updated to NULL. The
deleted node is properly deallocated using free(), ensuring efficient
memory management while maintaining the integrity of both forward and
backward links in the linked list.

================================================================================
*/
