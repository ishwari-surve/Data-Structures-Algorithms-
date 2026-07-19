/*
===============================================================================
Program Name    : Menu Driven Singly Linked List
Program Number  : 017
Description     : This program demonstrates a complete Menu Driven Singly
                  Linked List implementation using C++. The user can perform
                  various linked list operations interactively, including
                  insertion, deletion, display, and counting of nodes through
                  a menu-driven interface.
Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Structure
5. Dynamic Memory Allocation
6. Menu Driven Programming
7. InsertFirst Operation
8. InsertLast Operation
9. InsertAtPos Operation
10. DeleteFirst Operation
11. DeleteLast Operation
12. DeleteAtPos Operation
13. Pointer Traversal
14. Switch Case
15. Node Counting

Key Learning Points:
- Menu Driven implementation of Singly Linked List.
- User can perform all insertion operations.
- User can perform all deletion operations.
- Position validation avoids invalid operations.
- iCount maintains the total number of nodes.
- Object-Oriented approach improves code reusability.

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
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL()
{
    this -> first = NULL;
    this -> iCount = 0;
}

void SinglyLL:: Display()
{
    PNODE temp = NULL;
    temp = this -> first;

    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int SinglyLL:: Count()
{
    return this -> iCount;
}

void  SinglyLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }
    this -> iCount++;                               // Important
}

void  SinglyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;  
        }
        temp -> next = newn;
    }
    this -> iCount++;                              // Important
}

void  SinglyLL:: InsertAtPos(int iNo, int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position";
        return;
    }

    if(iPos == 1)
    {
        this -> InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        this -> InsertLast(iNo);
    }
    else
    {
        newn = new NODE();
        newn -> data = iNo;
        newn -> next = NULL;

        temp = this -> first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        this -> iCount++;
    }
}

void  SinglyLL:: DeleteFirst()
{
    PNODE temp = NULL;
    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;       
        this -> first = this -> first -> next;
        delete(temp);
    }

    this -> iCount--;
}

void  SinglyLL:: DeleteLast()
{
    PNODE temp = NULL;
    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
    this -> iCount--;
}

void  SinglyLL:: DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;
    PNODE target = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position";
        return;
    }

    if(iPos == 1)
    {
        this -> DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        delete(target);
        this -> iCount--;
    }
}

int main()
{
    SinglyLL sobj;

    int iChoice = 1;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(iChoice != 0)
    {
        cout<<"\n-------------------------------------------------\n";
        cout<<"Singly Linked List Menu\n";
        cout<<"-------------------------------------------------\n";

        cout<<"1 : Insert First\n";
        cout<<"2 : Insert Last\n";
        cout<<"3 : Insert At Position\n";
        cout<<"4 : Delete First\n";
        cout<<"5 : Delete Last\n";
        cout<<"6 : Delete At Position\n";
        cout<<"7 : Display Elements\n";
        cout<<"8 : Count Elements\n";
        cout<<"0 : Exit\n";

        cout<<"\nEnter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter data : ";
                cin>>iValue;

                sobj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"Enter data : ";
                cin>>iValue;

                sobj.InsertLast(iValue);
                break;

            case 3:
                cout<<"Enter data : ";
                cin>>iValue;

                cout<<"Enter position : ";
                cin>>iPos;

                sobj.InsertAtPos(iValue,iPos);
                break;

            case 4:
                sobj.DeleteFirst();
                cout<<"First node deleted\n";
                break;

            case 5:
                sobj.DeleteLast();
                cout<<"Last node deleted\n";
                break;

            case 6:
                cout<<"Enter position : ";
                cin>>iPos;

                sobj.DeleteAtPos(iPos);
                break;

            case 7:
                sobj.Display();
                break;

            case 8:
                iRet = sobj.Count();
                cout<<"Number of elements are : "<<iRet<<endl;
                break;

            case 0:
                cout<<"Thank you for using the application...\n";
                break;

            default:
                cout<<"Invalid choice\n";
                break;
        }
    }

    return 0;
}
/*
===============================================================================
Sample Execution:
===============================================================================

-------------------------------------------------
Singly Linked List Menu
-------------------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display Elements
8 : Count Elements
0 : Exit

Enter your choice : 1
Enter data : 11

Enter your choice : 1
Enter data : 21

Enter your choice : 2
Enter data : 51

Enter your choice : 3
Enter data : 31
Enter position : 3

Enter your choice : 7

| 21 |-> | 11 |-> | 31 |-> | 51 |-> NULL

Enter your choice : 8

Number of elements are : 4

Enter your choice : 4

First node deleted

Enter your choice : 7

| 11 |-> | 31 |-> | 51 |-> NULL

Enter your choice : 5

Last node deleted

Enter your choice : 7

| 11 |-> | 31 |-> NULL

Enter your choice : 6

Enter position : 2

Enter your choice : 7

| 11 |-> NULL

Enter your choice : 8

Number of elements are : 1

Enter your choice : 0

Thank you for using the application...

===============================================================================
Memory Representation:
===============================================================================

Initially

first
 │
 ▼
NULL


After InsertFirst(11)

first
 │
 ▼
+------+------+
|  11  | NULL |
+------+------+


After InsertFirst(21)

first
 │
 ▼
+------+------+
|  21  |   •------+
+------+------+    |
                   ▼
            +------+------+
            |  11  | NULL |
            +------+------+


After InsertLast(51)

first
 │
 ▼
+------+------+
|  21  |   •------+
+------+------+    |
                   ▼
            +------+------+
            |  11  |   •------+
            +------+------+    |
                               ▼
                        +------+------+
                        |  51  | NULL |
                        +------+------+


After InsertAtPos(31,3)

first
 │
 ▼
+------+------+
|  21  |   •------+
+------+------+    |
                   ▼
            +------+------+
            |  11  |   •------+
            +------+------+    |
                               ▼
                        +------+------+
                        |  31  |   •------+
                        +------+------+    |
                                           ▼
                                    +------+------+
                                    |  51  | NULL |
                                    +------+------+


===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first to NULL and
iCount to 0.

The program repeatedly displays a menu until the user selects Exit.

Depending on the user's choice, the corresponding linked list operation
is performed.

Insert Operations:

• InsertFirst() inserts a node at the beginning.
• InsertLast() inserts a node at the end.
• InsertAtPos() inserts a node at the specified position after validation.

Delete Operations:

• DeleteFirst() removes the first node.
• DeleteLast() removes the last node.
• DeleteAtPos() removes the specified node after validation.

Display() traverses the linked list from first and prints every node.

Count() returns the total number of nodes maintained by iCount.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Invoked
          │
          ▼
Display Menu
          │
          ▼
Read User Choice
          │
          ▼
Perform Selected Operation
          │
          ▼
Display Updated Linked List
          │
          ▼
Repeat Until User Selects Exit
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created a Singly Linked List object.
2. Inserted nodes at the beginning.
3. Inserted nodes at the end.
4. Inserted nodes at a specified position.
5. Deleted the first node.
6. Deleted the last node.
7. Deleted a node from a specified position.
8. Displayed all nodes.
9. Counted the total number of nodes.
10. Validated user input positions.
11. Executed operations through a menu-driven interface.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)
InsertLast()    : O(n)
InsertAtPos()   : O(n)
DeleteFirst()   : O(1)
DeleteLast()    : O(n)
DeleteAtPos()   : O(n)
Display()       : O(n)
Count()         : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 017 demonstrates the complete implementation of a Menu Driven
Singly Linked List using C++. It combines all insertion, deletion,
display, and counting operations into a single application. The program
validates user input, maintains the node count using iCount, and provides
an interactive interface for performing linked list operations efficiently.
This serves as the final integrated implementation of the Singly Linked
List in C++.

===============================================================================
*/
