/*
===============================================================================
Program Name    : Doubly Circular Linked List - Skeleton Program
Program Number  : 002
File Name       : DoublyCL_02.cpp
Description     : This program provides the basic skeleton of a Doubly
                  Circular Linked List. It includes the node class,
                  class declaration, constructor, function prototypes,
                  and an empty main() function.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Member Functions
6. Pointer

Key Learning Points:
- Understand the basic structure of a Doubly Circular Linked List.
- Learn class-based implementation.
- Declare function prototypes.
- Prepare the foundation for implementing all linked list operations.

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

class DoublyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

DoublyCL::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void DoublyCL::Display()
{
}

int DoublyCL::Count()
{
    return 0;
}

void DoublyCL::InsertFirst(int no)
{
}

void DoublyCL::InsertLast(int no)
{
}

void DoublyCL::InsertAtPos(int no,int iPos)
{
}

void DoublyCL::DeleteFirst()
{
}

void DoublyCL::DeleteLast()
{
}

void DoublyCL::DeleteAtPos(int iPos)
{
}

int main()
{
    DoublyCL dobj;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

===============================================================================
Memory Representation:
===============================================================================

             first
               │
               ▼

NULL

last = NULL

===============================================================================
Algorithm:
===============================================================================

1. Define the node class.
2. Define the DoublyCL class.
3. Declare data members:
      - first
      - last
      - iCount
4. Declare all member function prototypes.
5. Initialize members in the constructor.
6. Create an object in main().
7. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Create Object
             │
             ▼
 Constructor Executes
             │
             ▼
 first = NULL
 last  = NULL
 iCount = 0
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

Program 002 provides the basic skeleton of a Doubly Circular Linked List
using C++. It prepares the class structure, constructor, and function
prototypes that will be implemented in the upcoming programs.

===============================================================================
*/
