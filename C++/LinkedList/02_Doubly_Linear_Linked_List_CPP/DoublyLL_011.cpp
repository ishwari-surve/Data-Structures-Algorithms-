/*
===============================================================================
Program Name    : Doubly Linear Linked List - Menu Driven Program
Program Number  : 011
File Name       : DoublyLL_11.cpp
Description     : This program demonstrates a complete Menu Driven
                  implementation of a Doubly Linear Linked List using C++.
                  It allows the user to perform various insertion, deletion,
                  display, and counting operations interactively.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Memory Deallocation using delete
6. Pointer Manipulation
7. Position Validation
8. Menu Driven Programming
9. Switch Case
10. Constructor

Key Learning Points:
- Perform all linked list operations through a menu.
- Insert nodes at the beginning, end, and any position.
- Delete nodes from the beginning, end, and any position.
- Display all nodes.
- Count total nodes.
- Validate user input.
- Build an interactive linked list application.

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
};

DoublyLL::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

void DoublyLL::Display()
{
    PNODE temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

int DoublyLL::Count()
{
    PNODE temp = first;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

void DoublyLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

void DoublyLL::InsertAtPos(int no, int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyLL::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        first = first->next;
        first->prev = NULL;

        delete temp;
    }

    iCount--;
}

void DoublyLL::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

void DoublyLL::DeleteAtPos(int iPos)
{
    PNODE temp = first;
    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}
int main()
{
    DoublyLL dobj;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(true)
    {
        cout<<"\n--------------------------------------------------\n";
        cout<<"      Doubly Linear Linked List\n";
        cout<<"--------------------------------------------------\n";

        cout<<"1. Insert First\n";
        cout<<"2. Insert Last\n";
        cout<<"3. Insert At Position\n";
        cout<<"4. Delete First\n";
        cout<<"5. Delete Last\n";
        cout<<"6. Delete At Position\n";
        cout<<"7. Display\n";
        cout<<"8. Count\n";
        cout<<"0. Exit\n";

        cout<<"\nEnter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter data : ";
                cin>>iValue;
                dobj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"Enter data : ";
                cin>>iValue;
                dobj.InsertLast(iValue);
                break;

            case 3:
                cout<<"Enter data : ";
                cin>>iValue;

                cout<<"Enter position : ";
                cin>>iPos;

                dobj.InsertAtPos(iValue,iPos);
                break;

            case 4:
                dobj.DeleteFirst();
                break;

            case 5:
                dobj.DeleteLast();
                break;

            case 6:
                cout<<"Enter position : ";
                cin>>iPos;

                dobj.DeleteAtPos(iPos);
                break;

            case 7:
                dobj.Display();
                break;

            case 8:
                iRet = dobj.Count();
                cout<<"Number of nodes are : "<<iRet<<"\n";
                break;

            case 0:
                cout<<"\nThank you for using Doubly Linear Linked List.\n";
                return 0;

            default:
                cout<<"Invalid choice...\n";
                break;
        }
    }

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

--------------------------------------------------
      Doubly Linear Linked List
--------------------------------------------------

1. Insert First
2. Insert Last
3. Insert At Position
4. Delete First
5. Delete Last
6. Delete At Position
7. Display
8. Count
0. Exit

Enter your choice :

===============================================================================
Memory Representation:
===============================================================================

Initially

first
 │
 ▼
NULL

-----------------------------------------

After Insert Operations

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

The linked list grows dynamically based on the user's choices.

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Display the menu.
3. Accept the user's choice.
4. Perform the selected linked list operation.
5. Return to the menu.
6. Repeat until the user selects Exit.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
       Display Menu
             │
             ▼
      Accept Choice
             │
             ▼
        Switch Case
             │
             ├── Insert
             ├── Delete
             ├── Display
             ├── Count
             └── Exit
             │
             ▼
      Display Menu Again
             │
             ▼
            Stop

  ===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)

InsertLast()       : O(n)

InsertAtPos()      : O(n)

DeleteFirst()      : O(1)

DeleteLast()       : O(n)

DeleteAtPos()      : O(n)

Display()          : O(n)

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 011 demonstrates a complete Menu Driven implementation of a Doubly
Linear Linked List in C++. The program allows users to perform insertion,
deletion, display, and counting operations interactively while maintaining
the correct next and previous links between nodes.

===============================================================================
*/
