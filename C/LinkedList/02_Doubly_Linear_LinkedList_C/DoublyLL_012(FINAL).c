/*
================================================================================
Program Name    : Doubly Linear Linked List - Menu Driven Implementation
Program Number  : 012 (FINAL)
Description     : This program implements a complete Doubly Linear Linked List
                  using a menu-driven approach. It provides options to perform
                  insertion, deletion, display, and count operations through
                  user interaction. The program demonstrates complete linked
                  list manipulation using forward and backward links while
                  maintaining dynamic memory allocation.

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
12. Menu Driven Programming
13. Switch Case
14. Looping (while)
15. User Interaction using scanf()

Key Learning Points:

- Menu driven programming provides interactive execution.
- User can perform multiple operations without restarting the program.
- Insert operations update both next and prev pointers.
- Delete operations safely free allocated memory.
- Display traverses the list from first to last.
- Count returns the total number of nodes.
- Position validation prevents invalid insertions and deletions.
- All linked list operations are integrated into a single application.

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
      PNODE target = temp->next;
      temp->next = target->next;
      target->next->prev = temp;

      free(target);
   }
}

int main()
{
    PNODE head = NULL;

    int iChoice = 1;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(iChoice != 0)
    {
        printf("\n--------------------------------------------------\n");
        printf("      Doubly Linear Linked List Menu\n");
        printf("--------------------------------------------------\n");

        printf("1 : Insert First\n");
        printf("2 : Insert Last\n");
        printf("3 : Insert At Position\n");
        printf("4 : Delete First\n");
        printf("5 : Delete Last\n");
        printf("6 : Delete At Position\n");
        printf("7 : Display\n");
        printf("8 : Count\n");
        printf("0 : Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d",&iValue);

                InsertFirst(&head,iValue);
                break;

            case 2:
                printf("Enter data : ");
                scanf("%d",&iValue);

                InsertLast(&head,iValue);
                break;

            case 3:
                printf("Enter data : ");
                scanf("%d",&iValue);

                printf("Enter position : ");
                scanf("%d",&iPos);

                InsertAtPos(&head,iValue,iPos);
                break;

            case 4:
                DeleteFirst(&head);
                printf("First node deleted successfully.\n");
                break;

            case 5:
                DeleteLast(&head);
                printf("Last node deleted successfully.\n");
                break;

            case 6:
                printf("Enter position : ");
                scanf("%d",&iPos);

                DeleteAtPos(&head,iPos);
                printf("Node deleted successfully.\n");
                break;

            case 7:
                Display(head);
                break;

            case 8:
                iRet = Count(head);
                printf("Number of elements are : %d\n",iRet);
                break;

            case 0:
                printf("Thank you for using the application...\n");
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}
/*
================================================================================
Expected Output
================================================================================

--------------------------------------------------
      Doubly Linear Linked List Menu
--------------------------------------------------

1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 1
Enter data : 11

Enter your choice : 2
Enter data : 21

Enter your choice : 2
Enter data : 51

Enter your choice : 7

NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> NULL

Enter your choice : 8

Number of elements are : 3

Enter your choice : 0

Thank you for using the application...

================================================================================
Pointer / Logic Explanation
================================================================================

• The program repeatedly displays a menu until the user selects Exit.
• Switch-case executes the selected linked list operation.
• InsertFirst() inserts a node at the beginning.
• InsertLast() inserts a node at the end.
• InsertAtPos() inserts a node at any valid position.
• DeleteFirst() removes the first node.
• DeleteLast() removes the last node.
• DeleteAtPos() removes a node from a specified position.
• Display() traverses and prints the linked list.
• Count() returns the total number of nodes.
• Both next and prev pointers are updated after every insertion and deletion.

================================================================================
Operations Performed
================================================================================

1. Created an empty Doubly Linear Linked List.
2. Displayed menu continuously using a loop.
3. Inserted nodes at the beginning.
4. Inserted nodes at the end.
5. Inserted a node at any valid position.
6. Deleted the first node.
7. Deleted the last node.
8. Deleted a node from any valid position.
9. Displayed all nodes in the list.
10. Counted the total number of nodes.
11. Allowed multiple operations until Exit option was selected.

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

Program 012 presents the final implementation of the Doubly Linear Linked
List using a menu-driven approach. It integrates all insertion, deletion,
display, and count operations into a single interactive application.
Proper maintenance of both next and prev pointers ensures correct list
structure after every operation. This program demonstrates a complete
and user-friendly implementation of the Doubly Linear Linked List in C.

================================================================================
*/
