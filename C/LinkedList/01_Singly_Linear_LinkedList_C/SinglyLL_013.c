/*
================================================================================ 
Program Name    : Singly Linked List - Count Number of Nodes
Program Number  : 013
Description     : This program demonstrates how to count the total number of
                  nodes present in a singly linked list using a TEMP pointer
                  and a while loop. The TEMP pointer traverses each node
                  without modifying the HEAD pointer, while a counter
                  variable increments once for every node visited.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. PNODE typedef (Pointer to NODE)
4. HEAD Pointer (Entry Point)
5. TEMP Pointer (Traversal Pointer)
6. While Loop
7. Linked List Traversal
8. Counter Variable
9. Node Counting
10. #pragma pack(1)
11. printf() for Output

Key Learning Points:
- TEMP pointer traverses the linked list safely.
- HEAD pointer remains unchanged throughout traversal.
- Counter variable increments once for every node visited.
- while(temp != NULL) ensures every node is counted.
- Traversal stops automatically when TEMP becomes NULL.
- The counter value represents the total number of nodes in the linked list.
- Foundation for implementing the Count() function.
- Demonstrates traversal without displaying node data.
================================================================================
*/
//Program 13
#include<stdio.h>

#pragma pack(1)
struct  node 
{
    int data;
    struct  node * next;
    
};

typedef struct node NODE;
typedef struct node * PNODE; 

int main()
{
    PNODE head = NULL; 
    PNODE temp = NULL;

    int iCount = 0;

    NODE obj1,obj2,obj3;

    head = &obj1;

    obj1.data = 11;
    obj1.next=&obj2;
   
    obj2.data  =21;
    obj2.next=&obj3;

    obj3.data  = 51;
    obj3.next = NULL;

    temp = head;                         

    // Traverse the linked list and count each node
    while(temp != NULL)
    {
       iCount++;          
        temp  = temp -> next; 
        
    } 
    printf("Total number of nodes are : %d\n",iCount);
              
    return 0; 
}

================================================================================
Expected Output
================================================================================

Number of nodes are : 3

================================================================================
Memory Diagram
================================================================================

            head
             │
             ▼
      +-----------+      +-----------+      +-----------+
      | data = 11 | ---> | data = 21 | ---> | data = 51 |
      | next -----|      | next -----|      | next=NULL |
      +-----------+      +-----------+      +-----------+
          obj1               obj2               obj3

Traversal:

temp
 │
 ▼
obj1 → obj2 → obj3 → NULL

================================================================================
Pointer/Logic Explanation
================================================================================

Initialization:

head = &obj1
temp = head
iCount = 0

The TEMP pointer starts from the first node and visits every node one by one.

Loop:

while(temp != NULL)
{
    iCount++;
    temp = temp->next;
}

Execution Trace:

Iteration 1:
• temp points to obj1
• iCount becomes 1
• temp moves to obj2

Iteration 2:
• temp points to obj2
• iCount becomes 2
• temp moves to obj3

Iteration 3:
• temp points to obj3
• iCount becomes 3
• temp moves to NULL

Iteration 4:
• temp becomes NULL
• Loop terminates

Final Count:

iCount = 3

This represents the total number of nodes present in the linked list.

================================================================================
Operations Performed
================================================================================

1. Created and linked three nodes.
2. Assigned HEAD to TEMP.
3. Initialized the counter variable to zero.
4. Traversed the linked list using a while loop.
5. Incremented the counter for every node visited.
6. Stopped traversal when TEMP became NULL.
7. Displayed the total number of nodes.

================================================================================
Time Complexity
================================================================================

Node Traversal      : O(n)

Space Complexity    : O(1)

================================================================================
Conclusion
================================================================================

This program demonstrates how to count the total number of nodes in a singly
linked list using traversal. Each node is visited exactly once, and the counter
variable is incremented during every iteration. The HEAD pointer remains
unchanged because traversal is performed using the TEMP pointer. This counting
technique forms the basis of the Count() function used in linked list
implementations.

================================================================================

