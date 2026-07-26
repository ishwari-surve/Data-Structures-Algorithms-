/*
===============================================================================
Program Name    : Doubly Circular Linked List - Node Class & Memory Size
Program Number  : 001
File Name       : DoublyCL_01.cpp
Description     : This program demonstrates the basic node structure of a
                  Doubly Circular Linked List and displays the memory occupied
                  by one node.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Self-Referential Class
3. Pointer
4. sizeof() Operator
5. Object-Oriented Programming (OOP)

Key Learning Points:
- Understand the node structure of a Doubly Circular Linked List.
- Learn self-referential classes.
- Calculate the memory occupied by one node.
- Understand the role of next and prev pointers.

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

(Note: The output may vary depending on the compiler and system architecture.)

===============================================================================
Memory Representation:
===============================================================================

        +--------------------------------------+
        | prev | data | next |
        +--------------------------------------+

prev  -> Address of Previous Node

data  -> Stores Integer Data

next  -> Address of Next Node

===============================================================================
Algorithm:
===============================================================================

1. Define a self-referential class.
2. Declare one integer data member.
3. Declare two pointer members:
      - next
      - prev
4. Use sizeof() to calculate the memory occupied by one node.
5. Display the size.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

        Start
           │
           ▼
 Create Node Class
           │
           ▼
 Calculate sizeof(NODE)
           │
           ▼
 Display Size
           │
           ▼
          Stop

===============================================================================
Time Complexity:
===============================================================================

Time Complexity : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the node structure of a Doubly Circular Linked List
using C++. It demonstrates the use of a self-referential class containing
data, next pointer, and previous pointer, and calculates the memory occupied
by one node.

===============================================================================
*/
