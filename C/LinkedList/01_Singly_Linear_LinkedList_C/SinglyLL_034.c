/*
================================================================================
Program Name    : Singly Linked List - DeleteAtPos Function Implementation
Program Number  : 034
Description     : This program implements the DeleteAtPos() operation in a
                  Singly Linked List. It validates the given position and
                  deletes the node at the specified location. Depending on
                  the position, the function internally calls DeleteFirst(),
                  DeleteLast(), or deletes a node from the middle of the list.
                  The program also includes InsertFirst(), InsertLast(),
                  InsertAtPos(), Display(), and Count() functions.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. Position Validation
5. DeleteFirst Function
6. DeleteLast Function
7. DeleteAtPos Function
8. InsertFirst Function
9. InsertLast Function
10. InsertAtPos Function
11. Display Function
12. Count Function
13. Pointer Traversal
14. Memory Deallocation (free)

Key Learning Points:
- DeleteAtPos() deletes a node from any valid position.
- Count() validates the entered position.
- Position 1 calls DeleteFirst().
- Last position calls DeleteLast().
- Middle deletion requires pointer traversal.
- The previous node is linked directly to the next node.
- The deleted node memory is released using free().
- DeleteAtPos() performs O(n) deletion in the worst case.
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct  node
{
    int data;
    struct node *next ;

};

typedef struct  node NODE;
typedef struct  node *PNODE;
typedef struct  node **PPNODE;

// Call by Value
void Display(PNODE first)
{
    while (first) //while(first != NULL)   Type 1
    {
        printf(" | %d | ->",first->data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first) // only for Count() the 'int' is used
{
    int iCount = 0;

    while (first != NULL)  // Type 1
    {
      iCount++;
      first = first -> next;
    }
    return iCount;
}

//Call by Address Functions(6)
void InsertFirst(PPNODE first,int iNO)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNO;
    newn->next = NULL;
   
    if(*first == NULL) // LL IS EMPTY  
    {
          *first =newn;
    } 
    else               // LL contains atleast 1 node
    {
            newn->next = *first;
           *first = newn;
    }
}

void InsertLast(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL) // LL IS EMPTY
    {
          *first = newn;
    } 
    else               // LL contains atleast 1 node
    {
        temp = *first;

        while (temp->next != NULL)    //Type 2
        {
            temp = temp->next;
        }
        temp->next = newn;
   }

}

void InsertAtPos(PPNODE first,int iNo,int iPos)
{
    int iCount = 0;
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if((iPos < 1)||(iPos > iCount+1))
    {
        printf("Invaild Position");
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
        newn = (PNODE)malloc(sizeof(NODE));

        newn ->data = iNo;
        newn->next = NULL;

        temp = *first;
        for(i=1; i < iPos-1; i++)
        {
            temp=temp->next;
        }
        newn->next= temp->next;
        temp->next = newn;

    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp =NULL;
    if(*first == NULL)                       //LL is empty
    {
        return ;
    }
    else if((*first) ->next == NULL)          //LL contains one node (here in the condition if *first ->next ==NULL) will get error
    {
        free (*first);
        *first = NULL;
    }
    else                                    // LL Contains more than one Node
    {
        temp = *first;
        *first = (*first)-> next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp =NULL;
    if(*first == NULL)                       //LL is empty
    {
        return;
    }
    else if((*first) ->next == NULL)          //LL contains one node (here in the condition if *first ->next ==NULL) will get error
    {
        free (*first);
        *first = NULL;
    }
    else                                    // LL Contains more than one Node
    {
       temp = *first;
       while (temp->next->next != NULL)      // Type 3
       {
           temp = temp->next;
       }

       free(temp->next);
       temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE first,int iPos)
{
    int iCount = 0;
    int i = 0;

    PNODE temp = NULL;
    PNODE target = NULL;
    
    iCount = Count(*first);

    if((iPos < 1)||(iPos > iCount))
    {
        printf("Invalid Position\n");
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

       for(i=1; i < iPos -1; i++)
       {
           temp = temp->next;
       }
       target = temp->next;

        temp->next = target->next;
        free(target);
    }
}

int main()
{
    PNODE head = NULL;
     int iRet  =0 ;

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&head,105,4);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&head,4);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================

 | 11 | -> | 21 | -> | 51 | -> | 101 | ->NULL
Number of nodes are : 4

 | 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->NULL
Number of nodes are : 6

 | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->NULL
Number of nodes are : 5

 | 21 | -> | 51 | -> | 101 | -> | 111 | ->NULL
Number of nodes are : 4

 | 21 | -> | 51 | -> | 101 | -> | 105 | -> | 111 | ->NULL
Number of nodes are : 5

 | 21 | -> | 51 | -> | 101 | -> | 111 | ->NULL
Number of nodes are : 4

================================================================================
Memory Diagram:
================================================================================

Before DeleteAtPos()

head
 |
 v
[21] -> [51] -> [101] -> [105] -> [111] -> NULL

DeleteAtPos(&head,4)

temp
 |
 v
[101]

target
 |
 v
[105]

After Linking

head
 |
 v
[21] -> [51] -> [101] -> [111] -> NULL

================================================================================
Pointer / Logic Explanation:
================================================================================

DeleteAtPos() first validates the given position.

Case 1 : Invalid Position

if(iPos < 1 || iPos > Count())

Display

Invalid Position

Return immediately.

------------------------------------------------------------

Case 2 : Position = 1

DeleteFirst(first);

Deletes the first node.

------------------------------------------------------------

Case 3 : Position = Count()

DeleteLast(first);

Deletes the last node.

------------------------------------------------------------

Case 4 : Middle Position

Traverse up to the previous node.

for(i = 1; i < iPos-1; i++)
{
    temp = temp->next;
}

Store the node to be deleted.

target = temp->next;

Connect the previous node to the next node.

temp->next = target->next;

Delete the node.

free(target);

Example

Before

21 -> 51 -> 101 -> 105 -> 111

Delete Position 4

After

21 -> 51 -> 101 -> 111

================================================================================
Operations Performed:
================================================================================

1. Created a self-referential node structure.
2. Inserted nodes at the beginning using InsertFirst().
3. Inserted nodes at the end using InsertLast().
4. Inserted a node at a specified position using InsertAtPos().
5. Deleted the first node using DeleteFirst().
6. Deleted the last node using DeleteLast().
7. Deleted a node at a specified position using DeleteAtPos().
8. Validated insertion and deletion positions.
9. Traversed the linked list using pointers.
10. Released dynamically allocated memory using free().
11. Displayed the linked list after every operation.
12. Counted the total number of nodes after each modification.

================================================================================
Time Complexity:
================================================================================

InsertFirst()    : O(1)
InsertLast()     : O(n)
InsertAtPos()    : O(n)
DeleteFirst()    : O(1)
DeleteLast()     : O(n)
DeleteAtPos()    : O(n)
Display()        : O(n)
Count()          : O(n)

Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 034 implements the DeleteAtPos() operation for a Singly Linked List.
The function validates the specified position and efficiently handles boundary
cases by calling DeleteFirst() and DeleteLast(). For middle deletion, the
previous node is linked directly to the next node before freeing the target
node. This completes all basic insertion and deletion operations of a Singly
Linked List.

================================================================================
*/
