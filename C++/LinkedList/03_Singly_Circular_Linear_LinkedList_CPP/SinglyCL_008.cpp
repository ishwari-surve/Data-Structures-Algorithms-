/*
===============================================================================
Program Name    : Singly Circular Linked List - Basic Class Skeleton
Program Number  : 008
Description     : This program creates the basic Singly Circular Linked List
                  class. It contains the required data members and declares
                  all major member functions that will be implemented in the
                  upcoming programs.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. C++ Class
2. Constructor
3. Object Oriented Programming
4. Data Encapsulation
5. Function Declaration
6. Pointer Data Members

Key Learning Points:
- Creating a Linked List class.
- Declaring first and last pointers.
- Maintaining node count.
- Declaring all Linked List operations.
- Constructor initialization.

===============================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

int main()
{
    SinglyCL sobj;

    return 0;
}

/*
===============================================================================
Class Representation:
===============================================================================

                SinglyCL
     +--------------------------------+
     | first  -----> NULL             |
     | last   -----> NULL             |
     | iCount = 0                     |
     +--------------------------------+

===============================================================================
Functions Declared:
===============================================================================

Display()
Count()

InsertFirst()
InsertLast()
InsertAtPos()

DeleteFirst()
DeleteLast()
DeleteAtPos()

===============================================================================
Program Flow:
===============================================================================

Create SinglyCL Object
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
Program Ends

===============================================================================
Time Complexity:
===============================================================================

Constructor        : O(1)
Object Creation    : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 introduces the Singly Circular Linked List class. It initializes
the first pointer, last pointer, and node count using the constructor and
declares all fundamental operations that will be implemented in the upcoming
programs.

===============================================================================
*/
