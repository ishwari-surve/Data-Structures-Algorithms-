/*
===============================================================================
Program Name    : Display Operation in Singly Linked List
Program Number  : 009 
Description     : This program demonstrates the Display() operation of a
                  Singly Linked List. The Display() function traverses the
                  linked list from the first node and prints all the node
                  elements. Since no nodes are inserted, the linked list
                  remains empty and only NULL is displayed.
Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Structure
5. Linked List Traversal
6. Temporary Pointer
7. Encapsulation
8. Display Operation

Key Learning Points:
- Display() traverses the linked list from first to NULL.
- A temporary pointer is used for traversal.
- The original first pointer remains unchanged.
- An empty linked list is handled safely.
- Traversal continues until temp becomes NULL.

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

class SinglyLL
{
    private:

        PNODE first;
        int iCount;

    public:

        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

/*
===============================================================================
Constructor Definition
===============================================================================
*/

SinglyLL::SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

/*
===============================================================================
Member Function Definitions
===============================================================================
*/

void SinglyLL::Display()
{
    PNODE temp = NULL;

    temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

int SinglyLL::Count()
{
    return this->iCount;
}

void SinglyLL::InsertFirst(int iNo)
{
}

void SinglyLL::InsertLast(int iNo)
{
}

void SinglyLL::InsertAtPos(int iNo,int iPos)
{
}

void SinglyLL::DeleteFirst()
{
}

void SinglyLL::DeleteLast()
{
}

void SinglyLL::DeleteAtPos(int iPos)
{
}

int main()
{
    SinglyLL sobj;

    sobj.Display();

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

NULL

===============================================================================
Memory Representation:
===============================================================================

Linked List:

first
  │
  ▼
NULL

temp
 │
 ▼
NULL

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first to NULL and
iCount to 0.

The Display() function creates a temporary pointer named temp and assigns it
the address stored in first.

Since no nodes have been inserted into the linked list, first contains NULL.
Therefore, temp also becomes NULL.

The while loop checks whether temp is not NULL. Since the condition is false,
the loop is skipped and only NULL is displayed.

Using a temporary pointer ensures that the original first pointer remains
unchanged after traversal.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Invoked
          │
          ▼
Initialize first = NULL
Initialize iCount = 0
          │
          ▼
Call Display()
          │
          ▼
temp = first
          │
          ▼
temp == NULL ?
          │
          ▼
Display NULL
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node structure.
2. Created the SinglyLL class.
3. Initialized first to NULL.
4. Initialized iCount to 0.
5. Created a temporary pointer for traversal.
6. Checked whether the linked list is empty.
7. Displayed NULL for an empty linked list.

===============================================================================
Time Complexity:
===============================================================================

Display()        : O(n)
Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the Display() operation of a Singly Linked List.
The function traverses the list using a temporary pointer and safely handles
the empty list condition by displaying NULL. This forms the basis for
displaying node elements after insertion operations in later programs.

===============================================================================
*/
