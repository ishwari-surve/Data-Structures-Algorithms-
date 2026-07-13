/*
================================================================================
Program Name    : Singly Linked List - DeleteLast Function Implementation
Program Number  : 032
Description     : This program implements the DeleteLast() operation in a
                  Singly Linked List. It demonstrates deleting the last node
                  while handling empty list, single-node list, and multiple-node
                  list cases. The program also includes InsertFirst(),
                  InsertLast(), DeleteFirst(), Display(), and Count() functions
                  to verify the linked list after every operation.
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
7. DeleteLast Function
8. Display Function
9. Count Function
10. Pointer Traversal
11. Memory Deallocation (free)

Key Learning Points:
- DeleteLast() removes the last node from the linked list.
- Three cases must be handled: empty list, single-node list, and multiple-node list.
- temp->next->next identifies the second last node.
- The last node is freed using free().
- The second last node becomes the new last node by assigning next = NULL.
- InsertFirst() performs O(1) insertion.
- InsertLast() performs O(n) insertion.
- DeleteFirst() performs O(1) deletion.
- DeleteLast() performs O(n) deletion due to traversal.
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

    if(*first == NULL)
    {
        *first = newn;
    }
    else
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
       while (temp->next->next != NULL)      // Type 3
       {
           temp = temp->next;
       }

       free(temp->next);
       temp->next = NULL;
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

    DeleteLast(&head);

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

After DeleteLast():

head
 |
 v
[21] -> [51] -> [101] -> [111] -> NULL

================================================================================
Pointer / Logic Explanation:
================================================================================

DeleteLast() handles three different situations.

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

*first = NULL;

Result:

head -> NULL

------------------------------------------------------------

Case 3 : Linked List contains multiple nodes

Example:

head
 |
 v
[21] -> [51] -> [101] -> [111] -> [121] -> NULL

Step 1

temp = *first;

temp starts from the first node.

Step 2

while(temp->next->next != NULL)

Traverse until temp reaches the second last node.

Step 3

free(temp->next);

Delete the last node.

Step 4

temp->next = NULL;

Second last node becomes the last node.

Final List

head
 |
 v
[21] -> [51] -> [101] -> [111] -> NULL

------------------------------------------------------------

Loop Types Used:

Type 1

while(first != NULL)

Used in Display() and Count() to traverse every node.

Type 2

while(temp->next != NULL)

Used in InsertLast() to reach the last node.

Type 3

while(temp->next->next != NULL)

Used in DeleteLast() to reach the second last node.

================================================================================
Operations Performed:
================================================================================

1. Created a self-referential node structure.
2. Inserted nodes at the beginning using InsertFirst().
3. Displayed the linked list.
4. Counted the total number of nodes.
5. Inserted new nodes at the end using InsertLast().
6. Deleted the first node using DeleteFirst().
7. Deleted the last node using DeleteLast().
8. Freed dynamically allocated memory of deleted nodes.
9. Updated the head pointer when required.
10. Displayed the modified linked list after each operation.
11. Counted nodes after every modification.

================================================================================
Time Complexity:
================================================================================

InsertFirst()    : O(1)
InsertLast()     : O(n)
DeleteFirst()    : O(1)
DeleteLast()     : O(n)
Display()        : O(n)
Count()          : O(n)

Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 032 implements the DeleteLast() operation for a Singly Linked List.
The function correctly handles empty, single-node, and multiple-node lists.
By traversing up to the second last node using temp->next->next, the last node
can be safely deleted and its memory released using free(). The program now
supports insertion at both ends and deletion from both ends while maintaining
the integrity of the linked list.

================================================================================
*/
