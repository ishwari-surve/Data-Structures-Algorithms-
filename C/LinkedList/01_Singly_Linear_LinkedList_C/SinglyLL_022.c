/*
================================================================================
Program Name    : Singly Linked List - Display, InsertFirst and InsertLast 
Program Number  : 022
Description     : This program implements Display(), InsertFirst(), and
                  InsertLast() functions. Display() traverses and prints
                  all node data, while InsertFirst() inserts nodes at the
                  beginning and InsertLast() inserts nodes at the end of
                  the linked list using dynamic memory allocation.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE typedef
3. PPNODE typedef
4. Dynamic Memory Allocation (malloc)
5. Traversal with while loop
6. Head Pointer Modification
7. Node Linking
8. Display/Print Operations
9. InsertFirst()
10. InsertLast()

Key Learning Points:
- Display() traverses and prints every node.
- InsertFirst() inserts a node at the beginning.
- InsertLast() inserts a node at the end.
- InsertFirst() executes in O(1) time.
- InsertLast() requires traversal (O(n)).
- Display() uses while loop traversal.
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
typedef struct node *PNODE;
typedef struct node **PPNODE;

/*
================================================================================
Function: Display(PNODE first)
Purpose: Display all nodes in linked list
Parameters: PNODE first (pointer to first node)
Return: void
Time Complexity: O(n)
================================================================================
*/
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("%d\t", first->data);
        first = first->next;
    }
    printf("\n");
}

/*
================================================================================
Function: Count(PNODE first)
Purpose: Count total number of nodes
Parameters: PNODE first (pointer to first node)
Return: int (total count)
Status: Placeholder (implementation in later program)
================================================================================
*/
int Count(PNODE first)
{
    return 0;
}

/*
================================================================================
Function: InsertFirst(PPNODE first, int iNo)
Purpose: Insert node at beginning of list
Parameters: PPNODE first (address of head), int iNo (data)
Return: void
Time Complexity: O(1)
================================================================================
*/
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
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

/*
================================================================================
Function: InsertLast(PPNODE first, int iNo)
Purpose: Insert node at end of list
Parameters: PPNODE first (address of head), int iNo (data)
Return: void
Time Complexity: O(n)
================================================================================
*/
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
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
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{}

void DeleteFirst(PPNODE first)
{}

void DeleteLast(PPNODE first)
{}

void DeleteAtPos(PPNODE first, int iPos)
{}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
11	21	51	101	

================================================================================
Memory Diagram:
================================================================================

After all InsertFirst calls:
head → [11|→] → [21|→] → [51|→] → [101|NULL]

Display Output:
11	21	51	101

head
 |
 v
+------+------+
| 11 |  •----|----+
+------+------+
              |
              v
+------+------+
| 21 |  •----|----+
+------+------+
              |
              v
+------+------+
| 51 |  •----|----+
+------+------+
              |
              v
+------+------+
|101 | NULL |
+------+------+

================================================================================
Pointer/Logic Explanation
================================================================================

Display Function

Purpose:
Display all node data from beginning to end.

Logic:

Step 1:
Receive pointer to first node.

Step 2:
while(first != NULL)

Step 3:
Print first->data.

Step 4:
Move to next node.
first = first->next;

Step 5:
Repeat until first becomes NULL.

--------------------------------------------------------

InsertFirst Function

Step 1:
Allocate memory for a new node using malloc().

Step 2:
Store the given data in the new node.

Step 3:
Initialize newn->next to NULL.

Step 4:
Check whether the list is empty.

Case 1: Empty List
*first = newn;

The new node becomes the first node.

Case 2: Non-empty List

newn->next = *first;
*first = newn;

The new node is linked before the current first node and becomes the new HEAD.

--------------------------------------------------------

Why PPNODE in InsertFirst()?

InsertFirst() modifies the HEAD pointer.

Using PPNODE allows the function to update the original HEAD pointer in
main().

If PNODE were used instead, only a local copy of the pointer would change,
and the original HEAD pointer would remain unchanged.

--------------------------------------------------------

Why PNODE in Display()?

Display() only traverses and reads the linked list.

It does not modify the HEAD pointer.

Therefore, passing PNODE is sufficient.

================================================================================
Operations Performed
================================================================================
1. Created an empty linked list.
2. Inserted nodes at the beginning using InsertFirst().
3. Displayed all nodes using Display().
4. Traversed the list using a while loop.
5. Included InsertLast() implementation for future use.

================================================================================
Time Complexity
================================================================================

InsertFirst()      : O(1)
InsertLast()       : O(n)
Display()          : O(n)

Space Complexity   : O(1)

================================================================================
Conclusion
================================================================================

Program 022 implements the Display(), InsertFirst(), and InsertLast()
functions of a singly linked list. Display() traverses the list and prints
the data stored in each node, while InsertFirst() inserts a new node at the
beginning in constant time and InsertLast() inserts a node at the end after
traversing the list. These functions demonstrate the use of dynamic memory
allocation, pointer manipulation, and linked list traversal, forming the
foundation for implementing the remaining linked list operations.

================================================================================
*/
