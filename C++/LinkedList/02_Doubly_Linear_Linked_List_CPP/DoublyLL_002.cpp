/*
===============================================================================
Program Name    : Doubly Linear Linked List - Skeleton Program
Program Number  : 002
File Name       : DoublyLL_02.cpp
Description     : This program demonstrates the basic skeleton structure of
                  a Doubly Linear Linked List using C++. It includes the node
                  class, DoublyLL class, and function declarations for all
                  linked list operations.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Function Declaration
6. Pointer
7. Data Abstraction

Key Learning Points:
- Understand the basic structure of a Doubly Linear Linked List class.
- Learn how to organize linked list operations.
- Declare member functions before implementation.
- Prepare the foundation for complete linked list implementation.

===============================================================================
*/

#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

typedef class node NODE;
typedef class node *PNODE;

class DoublyLL
{
private:
    PNODE first;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

DoublyLL::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

void DoublyLL::Display()
{
}

int DoublyLL::Count()
{
    return 0;
}

void DoublyLL::InsertFirst(int no)
{
}

void DoublyLL::InsertLast(int no)
{
}

void DoublyLL::InsertAtPos(int no,int iPos)
{
}

void DoublyLL::DeleteFirst()
{
}

void DoublyLL::DeleteLast()
{
}

void DoublyLL::DeleteAtPos(int iPos)
{
}

int main()
{
    DoublyLL dobj;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

This is a skeleton program containing only the class structure and empty
function definitions.

===============================================================================
Memory Representation:
===============================================================================

                DoublyLL Object

        +--------------------------+
        | first --------------+    |
        | iCount = 0          |    |
        +--------------------------+
                               |
                               ▼
                            NULL

===============================================================================
Algorithm:
===============================================================================

1. Define the node class.
2. Define the DoublyLL class.
3. Declare all linked list member functions.
4. Initialize first to NULL.
5. Initialize iCount to 0.
6. Create an object of DoublyLL.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Define Node Class
             │
             ▼
    Define DoublyLL Class
             │
             ▼
 Declare Member Functions
             │
             ▼
 Create DoublyLL Object
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

Program 002 provides the skeleton structure of a Doubly Linear Linked List.
It defines the node class, DoublyLL class, constructor, and declarations
for all linked list operations. This serves as the foundation for
implementing individual operations in the subsequent programs.

===============================================================================
*/
