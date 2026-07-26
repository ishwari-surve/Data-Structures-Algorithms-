/*
===============================================================================
Program Name    : Doubly Circular Linked List - Menu Driven Program
Program Number  : 011
File Name       : DoublyCL_11.cpp
Description     : This program demonstrates the complete implementation of a
                  Menu Driven Doubly Circular Linked List using C++. It allows
                  the user to perform various insertion, deletion, display,
                  counting, and position-based operations interactively.

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
7. Circular Linking
8. Position Validation
9. Menu Driven Programming

Key Learning Points:
- Perform insertion and deletion interactively.
- Display all nodes of the linked list.
- Count total nodes.
- Insert/Delete at any valid position.
- Maintain forward and backward circular links.

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

///////////////////////////////////////////////////////////////////////////////
// Constructor
///////////////////////////////////////////////////////////////////////////////

DoublyCL::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
// Display()
///////////////////////////////////////////////////////////////////////////////

void DoublyCL::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;

    cout<<"<=> ";

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;

    }while(temp != first);

    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////
// Count()
///////////////////////////////////////////////////////////////////////////////

int DoublyCL::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
// InsertFirst()
///////////////////////////////////////////////////////////////////////////////

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// InsertLast()
///////////////////////////////////////////////////////////////////////////////

void DoublyCL::InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// InsertAtPos()
///////////////////////////////////////////////////////////////////////////////

void DoublyCL::InsertAtPos(int no, int iPos)
{
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
        PNODE newn = new NODE;
        PNODE temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < iPos - 1; i++)
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
void DoublyCL::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;

        delete first->prev;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}
void DoublyCL::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;

        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}
void DoublyCL::DeleteAtPos(int iPos)
{
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
        PNODE temp = first;

        for(int i = 1; i < iPos - 1; i++)
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
    DoublyCL dobj;

    int iChoice = 1;
    int iValue = 0;
    int iPos = 0;

    while(iChoice != 0)
    {
        cout<<"\n--------------------------------------------------\n";
        cout<<" Doubly Circular Linked List\n";
        cout<<"--------------------------------------------------\n";
        cout<<"1. Insert First\n";
        cout<<"2. Insert Last\n";
        cout<<"3. Insert At Position\n";
        cout<<"4. Delete First\n";
        cout<<"5. Delete Last\n";
        cout<<"6. Delete At Position\n";
        cout<<"7. Display\n";
        cout<<"8. Count Nodes\n";
        cout<<"0. Exit\n";
        cout<<"--------------------------------------------------\n";

        cout<<"Enter your choice : ";
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
                cout<<"Number of nodes are : "<<dobj.Count()<<endl;
                break;

            case 0:
                cout<<"Thank you for using the application.\n";
                break;

            default:
                cout<<"Invalid Choice\n";
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
 Doubly Circular Linked List
--------------------------------------------------
1. Insert First
2. Insert Last
3. Insert At Position
4. Delete First
5. Delete Last
6. Delete At Position
7. Display
8. Count Nodes
0. Exit
--------------------------------------------------

Enter your choice : 1
Enter data : 11

Enter your choice : 2
Enter data : 51

Enter your choice : 7

<=> | 11 | <=> | 51 | <=>

Enter your choice : 8

Number of nodes are : 2

Enter your choice : 0

Thank you for using the application.

===============================================================================
Memory Representation:
===============================================================================

                 first
                   │
                   ▼

<=> |11| ⇄ |21| ⇄ |51| ⇄ |101| <=>
 ^                                       │
 |_______________________________________|

last->next = first
first->prev = last

===============================================================================
Algorithm:
===============================================================================

1. Create an object of DoublyCL.
2. Display the menu repeatedly until Exit is selected.
3. Read the user's choice.
4. Perform the selected operation:
      • Insert First
      • Insert Last
      • Insert At Position
      • Delete First
      • Delete Last
      • Delete At Position
      • Display
      • Count
5. Repeat until the user selects Exit.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
       Create Object
               │
               ▼
        Display Menu
               │
               ▼
        Read Choice
               │
               ▼
     Perform Operation
               │
               ▼
     Display Updated List
               │
               ▼
     Exit Selected?
         │        │
       No         Yes
        │          │
        └──────────┘
               │
               ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)

InsertLast()    : O(1)

InsertAtPos()   : O(n)

DeleteFirst()   : O(1)

DeleteLast()    : O(1)

DeleteAtPos()   : O(n)

Display()       : O(n)

Count()         : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 011 demonstrates the complete Menu Driven implementation of a Doubly
Circular Linked List in C++. It allows users to perform insertion, deletion,
display, counting, and position-based operations interactively while
maintaining the correct forward, backward, and circular links between nodes.

===============================================================================
*/
