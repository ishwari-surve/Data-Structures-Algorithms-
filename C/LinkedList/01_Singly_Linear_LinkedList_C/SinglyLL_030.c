/*
================================================================================
Program Name    : Singly Linked List - InsertFirst and InsertLast Implementation
Program Number  : 030
Description     : This program implements both InsertFirst() and InsertLast()
                  operations in a Singly Linked List. InsertFirst() inserts
                  nodes at the beginning in constant time, while InsertLast()
                  traverses the list and inserts nodes at the end. Display()
                  prints the linked list, and Count() returns the total number
                  of nodes after each insertion.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. InsertFirst() Implementation
5. InsertLast() Implementation
6. Linked List Traversal
7. Display() Function
8. Count() Function

Key Learning Points:
- InsertFirst() inserts nodes at the beginning in O(1).
- InsertLast() inserts nodes at the end in O(n).
- Traversal is required to locate the last node.
- Display() traverses and prints all nodes.
- Count() returns the total number of nodes.
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
    while (first!= NULL)
    {
        printf("|%d| -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{   
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(NULL == *first)          
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

    if(*first == NULL)          // Linked List is Empty
    {
        *first = newn;
    }
    else                       // Linked List at lest contain one Node
    {
        temp = *first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{

}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int iPos)
{

}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    // INSERT AT FIRST
    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);


    // INSERT AT LAST
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

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

================================================================================
Memory Diagram:
================================================================================

After InsertFirst():

head
 |
 v
[11|•] → [21|•] → [51|•] → [101|NULL]

After InsertLast(111) and InsertLast(121):

head
 |
 v
[11|•] → [21|•] → [51|•] → [101|•] → [111|•] → [121|NULL]

================================================================================
Pointer/Logic Explanation:
================================================================================

InsertFirst():
- Allocates memory for a new node.
- If the list is empty, the new node becomes the first node.
- Otherwise, the new node points to the current first node.
- Updates the head pointer.
- Time Complexity: O(1)

InsertLast():
- Allocates memory for a new node.
- If the list is empty, the new node becomes the first node.
- Otherwise:
  * temp starts from the first node.
  * Traverses until temp->next becomes NULL.
  * Links the new node after the last node.
- Time Complexity: O(n)

Display():
- Traverses the linked list from first node.
- Prints every node in sequence.
- Stops when NULL is reached.

Count():
- Traverses every node.
- Increments the counter for each node.
- Returns the total number of nodes.

Program Flow:

1. InsertFirst(101)
2. InsertFirst(51)
3. InsertFirst(21)
4. InsertFirst(11)

Current List:

11 → 21 → 51 → 101

Count = 4

InsertLast(111)

11 → 21 → 51 → 101 → 111

InsertLast(121)

11 → 21 → 51 → 101 → 111 → 121

Count = 6

================================================================================
Operations Performed:
================================================================================
1. Created a self-referential structure for linked list nodes.
2. Defined PNODE and PPNODE using typedef.
3. Allocated memory dynamically using malloc().
4. Inserted nodes at the beginning using InsertFirst().
5. Inserted nodes at the end using InsertLast().
6. Traversed the linked list to locate the last node.
7. Displayed all nodes using Display().
8. Counted the total number of nodes using Count().
9. Demonstrated both beginning and end insertion operations.
  
================================================================================
Time Complexity:
================================================================================
InsertFirst()    : O(1)
InsertLast()     : O(n)
Display()        : O(n)
Count()          : O(n)
Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================
Program 030 implements both InsertFirst() and InsertLast() operations for a
Singly Linked List. InsertFirst() performs insertion at the beginning in
constant time, whereas InsertLast() traverses the linked list before inserting
a new node at the end. Display() and Count() verify the correctness of both
operations by printing the updated list and total node count. This program
demonstrates the difference between O(1) and O(n) insertion techniques.

================================================================================
