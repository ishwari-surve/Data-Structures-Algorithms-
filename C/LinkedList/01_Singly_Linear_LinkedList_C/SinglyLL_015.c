/*
================================================================================
Program Name    : Singly Linked List - Count Function
Program Number  : 015
Description     : This program demonstrates how to count the total number of
                  nodes in a singly linked list using a separate Count()
                  function. The HEAD pointer is passed to the function, which
                  traverses the linked list and returns the total node count
                  without modifying the original HEAD pointer.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. typedef (NODE, PNODE)
4. Function
5. Function Parameter (PNODE)
6. Call by Value
7. HEAD Pointer
8. Linked List Traversal
9. While Loop
10. Counter Variable
11. return Statement
12. printf()

Key Learning Points:
- Traversal logic is moved into a separate function.
- HEAD pointer is passed by value to Count().
- Original HEAD pointer remains unchanged.
- Function returns the total number of nodes.
- Each node is visited exactly once.
- Demonstrates modular programming.
- Foundation for creating Display(), Search(), and other functions.
================================================================================
*/

#include<stdio.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    NODE obj1, obj2, obj3;
    int iRet = 0;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    obj4.data  = 101;
    obj4.next = NULL;

    iRet = Count(head);

    printf("Number of Nodes are : %d", iRet);

    return 0;
}

/*
================================================================================
Expected Output
================================================================================

Number of nodes are : 4

================================================================================
Memory Diagram
================================================================================

                head
                 │
                 ▼
      +-----------+      +-----------+      +-----------+      +-----------+
      | data = 11 | ---> | data = 21 | ---> | data = 51 | ---> | data=101 |
      | next -----|      | next -----|      | next -----|      | next=NULL|
      +-----------+      +-----------+      +-----------+      +-----------+
          obj1               obj2               obj3               obj4

================================================================================
Function Working
================================================================================

Function Call:

iRet = Count(head);

The address stored in HEAD is copied into the parameter "first".

main()                      Count()
------                      -------
head  ───────────────►      first

Both point to the first node initially.

Traversal inside Count():

first → obj1 → obj2 → obj3 → obj4 → NULL

During each iteration:

Iteration 1:
• iCount = 1
• first moves to obj2

Iteration 2:
• iCount = 2
• first moves to obj3

Iteration 3:
• iCount = 3
• first moves to obj4

Iteration 4:
• iCount = 4
• first moves to NULL

Loop terminates.
Count() returns 4.

iRet receives the returned value. 

================================================================================
Operations Performed
================================================================================

1. Created and linked four nodes.
2. Passed HEAD pointer to Count() function.
3. Traversed the linked list using a while loop.
4. Counted every node visited.
5. Returned the total node count.
6. Stored the returned value in iRet.
7. Displayed the total number of nodes.

================================================================================
Time Complexity
================================================================================

Node Traversal      : O(n)

Space Complexity    : O(1)

================================================================================
Conclusion
================================================================================

This program demonstrates how to implement a separate Count() function for a
singly linked list. The HEAD pointer is passed by value to the function, allowing
safe traversal without modifying the original linked list. The function visits
each node exactly once, counts the nodes, and returns the total count. This
modular approach improves code readability, reusability, and serves as the
foundation for implementing other linked list operations such as Display(),
Search(), Insert(), and Delete().
