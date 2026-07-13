/*
================================================================================
Program Name    : Singly Linked List - InsertAtPos Function Implementation
Program Number  : 033
Description     : This program implements the InsertAtPos() operation in a
                  Singly Linked List. It validates the given position and
                  inserts a new node at the specified location. Depending on
                  the position, the function internally calls InsertFirst(),
                  InsertLast(), or performs insertion in the middle of the list.
                  The program also includes Display(), Count(), InsertFirst(),
                  InsertLast(), DeleteFirst(), and DeleteLast() functions.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. Position Validation
5. InsertFirst Function
6. InsertLast Function
7. InsertAtPos Function
8. DeleteFirst Function
9. DeleteLast Function
10. Display Function
11. Count Function
12. Pointer Traversal

Key Learning Points:
- InsertAtPos() inserts a node at any valid position.
- Count() is used to validate the entered position.
- Position 1 calls InsertFirst().
- Position Count()+1 calls InsertLast().
- Middle insertion requires pointer traversal.
- Existing node links are preserved while inserting.
- InsertAtPos() performs O(n) insertion in the worst case.
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

================================================================================
Memory Diagram:
================================================================================

Before InsertAtPos():

head
 |
 v
[21] -> [51] -> [101] -> [111] -> NULL

InsertAtPos(&head,105,4)

Traversal:

temp
 |
 v
[21] -> [51] -> [101] -> [111]

New Node

[105]

After Linking

head
 |
 v
[21] -> [51] -> [101] -> [105] -> [111] -> NULL

================================================================================
Pointer / Logic Explanation:
================================================================================

InsertAtPos() first validates the given position.

Case 1 : Invalid Position

if(iPos < 1 || iPos > Count()+1)

Display

Invalid Position

Return immediately.

------------------------------------------------------------

Case 2 : Position = 1

InsertFirst(first, iNo);

Insertion takes place at the beginning.

------------------------------------------------------------

Case 3 : Position = Count()+1

InsertLast(first, iNo);

Insertion takes place at the end.

------------------------------------------------------------

Case 4 : Middle Position

Allocate a new node.

Traverse until the node just before the required position.

for(i = 1; i < iPos-1; i++)
{
    temp = temp->next;
}

Link the new node.

newn->next = temp->next;

temp->next = newn;

Example

Before

21 -> 51 -> 101 -> 111

Insert 105 at Position 4

After

21 -> 51 -> 101 -> 105 -> 111

================================================================================
Operations Performed:
================================================================================

1. Created a self-referential node structure.
2. Inserted nodes at the beginning using InsertFirst().
3. Inserted nodes at the end using InsertLast().
4. Deleted the first node using DeleteFirst().
5. Deleted the last node using DeleteLast().
6. Counted the total number of nodes.
7. Validated the insertion position.
8. Inserted a node at the specified position using InsertAtPos().
9. Displayed the linked list after every operation.
10. Preserved the existing links while inserting the new node.

================================================================================
Time Complexity:
================================================================================

InsertFirst()    : O(1)
InsertLast()     : O(n)
InsertAtPos()    : O(n)
DeleteFirst()    : O(1)
DeleteLast()     : O(n)
Display()        : O(n)
Count()          : O(n)

Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 033 implements the InsertAtPos() operation for a Singly Linked List.
The function validates the position before insertion and efficiently reuses
InsertFirst() and InsertLast() for boundary cases. For middle insertion,
pointer traversal is used to locate the previous node, after which the new
node is linked without disturbing the remaining list structure. This completes
all insertion operations for the Singly Linked List.

================================================================================
*/
