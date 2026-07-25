/*
===============================================================================
Program Name    : Doubly Linear Linked List - Node Class and Memory Size
Program Number  : 001
File Name       : DoublyLL_01.cpp
Description     : This program demonstrates the basic node structure of a
                  Doubly Linear Linked List using C++. It also displays the
                  size of the node in memory.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Pointer
5. sizeof() Operator

Key Learning Points:
- Understand the structure of a Doubly Linear Linked List node.
- Learn how a self-referential class is created.
- Display the memory occupied by a node.
- Introduction to Doubly Linear Linked List.

===============================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

class node
{
public:
    int data;
    node *next;
    node *prev;
};

typedef class node NODE;
typedef class node *PNODE;
typedef class node **PPNODE;

int main()
{
    cout<<"Size of NODE is : "<<sizeof(NODE)<<" bytes"<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Size of NODE is : 20 bytes

(Note: The size may vary depending on the compiler and system architecture.)

===============================================================================
Memory Representation:
===============================================================================

        +---------+-----------+-----------+
        |  data   |   next    |   prev    |
        +---------+-----------+-----------+
            int      pointer      pointer

===============================================================================
Algorithm:
===============================================================================

1. Define a self-referential class named node.
2. Declare three data members:
      - data
      - next
      - prev
3. Use sizeof() to determine the size of the node.
4. Display the size.
5. Stop.

===============================================================================
Program Flow:
===============================================================================

        Start
          │
          ▼
Define Node Class
          │
          ▼
Calculate sizeof(NODE)
          │
          ▼
Display Memory Size
          │
          ▼
         Stop

===============================================================================
Time Complexity:
===============================================================================

Time Complexity  : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the node structure of a Doubly Linear Linked List
using C++. It demonstrates how a self-referential class is created and
shows the amount of memory occupied by a single node.

===============================================================================
*/
