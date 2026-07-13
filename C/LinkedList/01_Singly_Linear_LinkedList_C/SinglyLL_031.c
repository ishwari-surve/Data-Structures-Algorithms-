/*
================================================================================
Program Name    : Singly Linked List - DeleteFirst Function Implementation
Program Number  : 031
Description     : This program implements the DeleteFirst() operation in a
                  Singly Linked List. It demonstrates deletion of the first
                  node while handling all three possible cases: empty list,
                  single-node list, and multiple-node list. The program also
                  includes Display(), Count(), InsertFirst(), and InsertLast()
                  functions to verify the linked list before and after deletion.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. InsertFirst Function
5. InsertLast Function
6. DeleteFirst Function
7. Display Function
8. Count Function
9. Pointer Manipulation
10. Memory Deallocation (free)

Key Learning Points:
- DeleteFirst() removes the first node from the linked list.
- Three cases must be handled: empty list, single node, and multiple nodes.
- Temporary pointer prevents losing access to the first node before deletion.
- free() releases dynamically allocated memory.
- Head pointer must be updated after deleting the first node.
- InsertFirst() performs O(1) insertion.
- InsertLast() performs O(n) insertion.
- DeleteFirst() performs O(1) deletion.
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
    while (first) //while(first != NULL)
    {
        printf(" | %d | ->",first->data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first) // only for Count() the 'int' is used
{
    int iCount = 0;

    while (first)
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

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
   }

}

void InsertAtPos(PPNODE first,int iNo,int iPos)
{}

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
    if(*first == NULL)                       //LL is empty
    {
        return ;
    }
    else if((*first) ->next == NULL)          //LL contains one node (here in the condition if *first ->next ==NULL) will get error
    {
        free (*first);
        *first = NULL;
    }
   else
  {
       // TODO : Delete last node
  }
}

void DeleteAtPos(PPNODE first,int iPos)
{}


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

================================================================================
Memory Diagram:
================================================================================

Initial List:

head
 |
 v
[11] -> [21] -> [51] -> [101] -> NULL

After InsertLast():

head
 |
 v
[11] -> [21] -> [51] -> [101] -> [111] -> [121] -> NULL

After DeleteFirst():

head
 |
 v
[21] -> [51] -> [101] -> [111] -> [121] -> NULL

================================================================================
Pointer / Logic Explanation:
================================================================================

DeleteFirst() handles three different situations.

Case 1 : Linked List is Empty

Condition:
if(*first == NULL)

No node exists.
Nothing is deleted.
Function immediately returns.

------------------------------------------------------------

Case 2 : Linked List contains only one node

Condition:

else if((*first)->next == NULL)

Example:

head
 |
 v
[11] -> NULL

Steps:

free(*first);

Release memory occupied by the node.

*first = NULL;

Head becomes NULL.

Result:

head -> NULL

------------------------------------------------------------

Case 3 : Linked List contains multiple nodes

Example:

head
 |
 v
[11] -> [21] -> [51] -> [101] -> NULL

Step 1

temp = *first;

temp points to first node.

Step 2

*first = (*first)->next;

Head moves to second node.

Step 3

free(temp);

Delete the old first node.

Final List

head
 |
 v
[21] -> [51] -> [101] -> NULL

------------------------------------------------------------

Why Temporary Pointer is Required?

Without temp:

*first = (*first)->next;

The address of the original first node is lost.

It cannot be freed, causing a memory leak.

Using temp preserves the address until free() is called.

================================================================================
Operations Performed:
================================================================================

1. Created a self-referential node structure.
2. Inserted nodes at the beginning using InsertFirst().
3. Displayed the linked list.
4. Counted the total number of nodes.
5. Inserted new nodes at the end using InsertLast().
6. Deleted the first node using DeleteFirst().
7. Updated the head pointer after deletion.
8. Freed dynamically allocated memory of the deleted node.
9. Displayed the modified linked list.
10. Counted nodes again after deletion.

================================================================================
Time Complexity:
================================================================================

InsertFirst()    : O(1)
InsertLast()     : O(n)
DeleteFirst()    : O(1)
Display()        : O(n)
Count()          : O(n)

Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 031 implements the DeleteFirst() operation for a Singly Linked List.
The function safely deletes the first node by handling empty, single-node,
and multiple-node cases separately. A temporary pointer is used to preserve
the address of the node before freeing its memory, preventing memory leaks.
After deletion, the head pointer is updated correctly, maintaining the
integrity of the linked list.

================================================================================
*/
