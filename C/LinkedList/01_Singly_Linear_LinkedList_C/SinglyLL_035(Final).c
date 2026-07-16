/*
===============================================================================
Program Name    : Menu Driven Implementation of Singly Linear Linked List
Program Number  : 034
Description     : This program demonstrates a complete Menu Driven Singly
                  Linear Linked List. It allows the user to perform various
                  linked list operations interactively through a menu-based
                  interface. The implementation supports insertion, deletion,
                  display, counting, and position-based operations.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Singly Linear Linked List
2. Self-Referential Structure
3. Dynamic Memory Allocation (malloc/free)
4. Pointer Manipulation
5. Menu Driven Programming
6. Switch Case
7. Traversal
8. Position-Based Operations
9. Function Calls
10. User Interaction

Key Learning Points:
- Menu Driven programs provide an interactive way to perform operations.
- Dynamic memory allocation is used to create and delete nodes.
- All insertion and deletion operations are combined into a single program.
- Position validation prevents invalid operations.
- Display() traverses the linked list from first to last.
- Count() returns the total number of nodes.
- Switch-case controls the execution of different linked list operations.

===============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCnt = 0;
    while(first != NULL)
    {
        iCnt++;
        first = first -> next;
    }
    return iCnt;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> next = NULL;
    }
}

void InsertAtPos(PPNODE first,int iNo, int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if(iPos < 1 || iPos > iCount + 1)
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;

        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

    }   
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free (*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first) -> next;

        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free (*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free (temp -> next);
        temp -> next = NULL;
    }
}

void DeleteAtPos(PPNODE first,int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if(iPos < 1 || iPos > iCount)
    {
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
        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        free (target);
    }   
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    int iChoice = 9;
    int iValue = -1;
    int iPosition = 0;

    while(iChoice != 0)
    {
        printf("-------------------------------------------------------------------\n");
        printf("Enter Your Choice:\n");
        printf("-------------------------------------------------------------------\n");

        printf("1: Insert Node at First Position:\n");
        printf("2: Insert Node at Last Position:\n");
        printf("3: Insert Node at Given Position:\n");
        printf("4: Delete Node at First Position:\n");
        printf("5: Delete Node at Last Position:\n");
        printf("6: Delete Node at Given Position:\n");
        printf("7: Display Node:\n");
        printf("8: Count the Node:\n");
        printf("0: Exit the Program!!!\n");

         scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
            printf("Enter the Value:");
            scanf("%d",&iValue);
            InsertFirst(&head,iValue);
            break;

            case 2:
            printf("Enter the Value:");
            scanf("%d",&iValue);
            InsertLast(&head,iValue);
            break;

            case 3:
            printf("Enter the Value:");
            scanf("%d",&iValue);
            printf("Enter the Position:");
            scanf("%d",&iPosition);
            InsertAtPos(&head,iValue,iPosition);
            break;

            case 4:
            DeleteFirst(&head);
            break;

            case 5:
            DeleteLast(&head);
            break;

            case 6:
            printf("Enter the Position:");
            scanf("%d",&iPosition);
            DeleteAtPos(&head,iPosition);
            break;

            case 7:
            Display(head);
            break;

            case 8:
            iRet = Count(head);
            printf("\nNumber of Nodes: %d\n",iRet);
            break;

            case 0:
            printf("-------------------Thank you for using program--------------------");
            break;

            default:
            printf("Invalid Choice");

        }
    }
    return 0;
}
/*
===============================================================================
Sample Execution:
===============================================================================

-------------------------------------------------------------------
Enter Your Choice:
-------------------------------------------------------------------

1 : Insert Node at First Position
2 : Insert Node at Last Position
3 : Insert Node at Given Position
4 : Delete Node at First Position
5 : Delete Node at Last Position
6 : Delete Node at Given Position
7 : Display Nodes
8 : Count Nodes
0 : Exit

Choice : 1
Enter the Value : 11

Choice : 1
Enter the Value : 21

Choice : 2
Enter the Value : 51

Choice : 7

| 21 | -> | 11 | -> | 51 | -> NULL

Choice : 8

Number of Nodes : 3

Choice : 0

-------------------Thank you for using program--------------------

===============================================================================
Program Flow:
===============================================================================

Start Program
      │
      ▼
Display Menu
      │
      ▼
Read User Choice
      │
      ▼
Execute Selected Operation
      │
      ├──► InsertFirst()
      ├──► InsertLast()
      ├──► InsertAtPos()
      ├──► DeleteFirst()
      ├──► DeleteLast()
      ├──► DeleteAtPos()
      ├──► Display()
      └──► Count()
      │
      ▼
Display Updated Result
      │
      ▼
Repeat Until User Selects Exit
      │
      ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created an empty Singly Linear Linked List.
2. Displayed an interactive menu.
3. Inserted nodes at the beginning.
4. Inserted nodes at the end.
5. Inserted nodes at a specified position.
6. Deleted the first node.
7. Deleted the last node.
8. Deleted a node from a specified position.
9. Displayed all nodes in the linked list.
10. Counted the total number of nodes.
11. Validated user inputs for position-based operations.
12. Repeated operations until the user selected Exit.

===============================================================================
Time Complexity:
===============================================================================

Display()        : O(n)
Count()          : O(n)

InsertFirst()    : O(1)
InsertLast()     : O(n)
InsertAtPos()    : O(n)

DeleteFirst()    : O(1)
DeleteLast()     : O(n)
DeleteAtPos()    : O(n)

Space Complexity : O(1)
(Extra space excluding dynamically allocated nodes)

===============================================================================
Conclusion:
===============================================================================

Program 034 integrates all fundamental operations of a Singly Linear Linked
List into a single Menu Driven application. It enables users to interactively
perform insertion, deletion, display, and counting operations while ensuring
proper position validation and dynamic memory management. This program serves
as the complete implementation of a Singly Linear Linked List in C and
provides a strong foundation for understanding dynamic data structures and
menu-driven programming.

===============================================================================
*/
