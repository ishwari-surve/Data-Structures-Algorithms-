/*
===============================================================================
Program Name    : Doubly Circular Linked List - Menu Driven Program
Program Number  : 011
Description     : This program demonstrates a complete Menu Driven
                  implementation of a Doubly Circular Linked List. It allows
                  the user to perform various insertion, deletion, display,
                  and counting operations interactively while maintaining the
                  circular and doubly linked properties.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Doubly Circular Linked List
4. Dynamic Memory Allocation
5. Memory Deallocation using free()
6. Pointer Manipulation
7. Position Validation
8. Circular Linking
9. Menu Driven Programming
10. Switch Case
11. typedef

Key Learning Points:
- Perform all Doubly Circular Linked List operations using a menu.
- Insert nodes at the beginning, end, and any position.
- Delete nodes from the beginning, end, and any position.
- Display the linked list.
- Count the total number of nodes.
- Validate user input before performing operations.
- Preserve the circular nature of the linked list.

===============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    printf("<=> ");

    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next;

    }while(first != last->next);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return 0;
    }

    do
    {
        iCount++;
        first = first->next;

    }while(first != last->next);

    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;

        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last)->prev;

        free((*last)->next);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    PNODE temp = NULL;
    int i = 0;
    int iCount = 0;

    iCount = Count(*first,*last);

    if(iPos < 1 || iPos > iCount)
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(i = 1; i < iPos - 1; i++)
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
    PNODE tail = NULL;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("-------------------------------------------------\n");
    printf("      Doubly Circular Linked List\n");
    printf("-------------------------------------------------\n");

    while(1)
    {
        printf("\n1.Insert First\n");
        printf("2.Insert Last\n");
        printf("3.Insert At Position\n");
        printf("4.Delete First\n");
        printf("5.Delete Last\n");
        printf("6.Delete At Position\n");
        printf("7.Display\n");
        printf("8.Count\n");
        printf("0.Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d",&iValue);
                InsertFirst(&head,&tail,iValue);
                break;

            case 2:
                printf("Enter data : ");
                scanf("%d",&iValue);
                InsertLast(&head,&tail,iValue);
                break;

            case 3:
                printf("Enter data : ");
                scanf("%d",&iValue);

                printf("Enter position : ");
                scanf("%d",&iPos);

                InsertAtPos(&head,&tail,iValue,iPos);
                break;

            case 4:
                DeleteFirst(&head,&tail);
                break;

            case 5:
                DeleteLast(&head,&tail);
                break;

            case 6:
                printf("Enter position : ");
                scanf("%d",&iPos);

                DeleteAtPos(&head,&tail,iPos);
                break;

            case 7:
                Display(head,tail);
                break;

            case 8:
                iRet = Count(head,tail);
                printf("Number of nodes are : %d\n",iRet);
                break;

            case 0:
                printf("Thank you for using the application.\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

-------------------------------------------------
      Doubly Circular Linked List
-------------------------------------------------

1.Insert First
2.Insert Last
3.Insert At Position
4.Delete First
5.Delete Last
6.Delete At Position
7.Display
8.Count
0.Exit

Enter your choice :

===============================================================================
Memory Representation:
===============================================================================

Initially

head = NULL
tail = NULL

        │
        ▼

Empty Doubly Circular Linked List

--------------------------------------------------

After inserting nodes

head                                            tail
 │                                                │
 ▼                                                ▼

11 <=> 21 <=> 51 <=> 101 <=> 111 <=> 121
 ▲                                        │
 └────────────────────────────────────────┘

===============================================================================
Algorithm:
===============================================================================

1.Start the program.
2.Display the menu.
3.Accept the user's choice.
4.Perform the selected linked list operation.
5.Return to the menu.
6.Repeat until the user selects Exit.
7.Stop.

===============================================================================
Program Flow:
===============================================================================

           Start
   │
   ▼
Display Menu
   │
   ▼
Accept Choice
   │
   ▼
Switch Case
   │
   ├── Insert
   ├── Delete
   ├── Display
   ├── Count
   └── Exit
   │
   ▼
Display Menu Again
   │
   ▼
Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()     : O(1)

InsertLast()      : O(1)

InsertAtPos()     : O(n)

DeleteFirst()     : O(1)

DeleteLast()      : O(1)

DeleteAtPos()     : O(n)

Display()         : O(n)

Count()           : O(n)

Space Complexity  : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 011 demonstrates a complete Menu Driven Doubly Circular Linked List in C. 
It integrates all insertion, deletion, traversal, and counting operations into an 
interactive application, allowing the user to perform linked list operations
dynamically while preserving the circular doubly linked structure.

===============================================================================
*/
