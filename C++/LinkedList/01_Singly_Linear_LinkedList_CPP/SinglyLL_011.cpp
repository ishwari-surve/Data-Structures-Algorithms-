/*
===============================================================================

Program Name    : Singly Linked List - InsertFirst() and InsertLast()
Program Number  : 011
Description     : This program demonstrates the implementation of
                  InsertFirst() and InsertLast() operations in a
                  Singly Linked List using C++ classes.

                  InsertFirst() inserts a new node at the beginning
                  of the linked list, while InsertLast() inserts a
                  new node at the end. The program also displays the
                  linked list and maintains the total number of nodes
                  using the Count() function.

Concepts Used   : C++ Classes,
                  Objects,
                  Constructor,
                  Dynamic Memory Allocation (new),
                  Self-Referential Structure,
                  Pointer Manipulation,
                  Encapsulation,
                  InsertFirst(),
                  InsertLast(),
                  Display(),
                  Count()

Input           : Node values inserted through function calls.

Output          : Displays the linked list after InsertFirst() and
                  InsertLast() operations along with the total
                  number of nodes.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve

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

    this -> iCount++;
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

    this -> iCount++;
}

void  SinglyLL:: InsertAtPos(int iNo, int iPos)
{}

void  SinglyLL:: DeleteFirst()
{}

void  SinglyLL:: DeleteLast()
{}

void  SinglyLL:: DeleteAtPos(int iPos)
{}

int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    return 0;
}
/*
===============================================================================

Expected Output:
===============================================================================

| 11 |-> | 21 |-> | 51 |-> NULL
Number of Elements are: 3

| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
Number of Elements are: 6

===============================================================================
Memory Representation:
===============================================================================

After InsertFirst(51)

first
 │
 ▼
+------+------+
|  51  | NULL |
+------+------+

-------------------------------------------------------------------------------

After InsertFirst(21)

first
 │
 ▼
+------+-----+     +------+------+
|  21  |  • ─────► |  51  | NULL |
+------+-----+     +------+------+

-------------------------------------------------------------------------------

After InsertFirst(11)

first
 │
 ▼
+------+-----+     +------+-----+     +------+------+
|  11  |  • ─────► |  21  |  • ─────► |  51  | NULL |
+------+-----+     +------+-----+     +------+------+

iCount = 3

-------------------------------------------------------------------------------

After InsertLast(101)

first
 │
 ▼
11 → 21 → 51 → 101 → NULL

-------------------------------------------------------------------------------

After InsertLast(111)

first
 │
 ▼
11 → 21 → 51 → 101 → 111 → NULL

-------------------------------------------------------------------------------

After InsertLast(121)

first
 │
 ▼
11 → 21 → 51 → 101 → 111 → 121 → NULL

iCount = 6

===============================================================================
Explanation:
===============================================================================

This program implements two important insertion operations of a Singly
Linked List.

InsertFirst():

• Creates a new node using the new operator.
• Initializes the data and next members.
• If the list is empty, the new node becomes the first node.
• Otherwise, the new node points to the current first node and then
  becomes the new first node.
• Increments iCount after successful insertion.

InsertLast():

• Creates a new node dynamically.
• If the list is empty, the new node becomes the first node.
• Otherwise, traverses the linked list until the last node is reached.
• Connects the last node to the new node.
• Increments iCount after insertion.

Display():

• Traverses the linked list from first.
• Prints every node until NULL is reached.

Count():

• Returns the value of iCount.
• Since iCount is updated after every insertion, counting is performed
  in constant time without traversing the linked list.

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
InsertFirst(51)
          │
          ▼
InsertFirst(21)
          │
          ▼
InsertFirst(11)
          │
          ▼
Display Linked List
          │
          ▼
Count Nodes
          │
          ▼
InsertLast(101)
          │
          ▼
InsertLast(111)
          │
          ▼
InsertLast(121)
          │
          ▼
Display Updated Linked List
          │
          ▼
Display Updated Count
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created a Singly Linked List object.
2. Initialized first to NULL.
3. Initialized iCount to 0.
4. Inserted nodes at the beginning using InsertFirst().
5. Displayed the linked list.
6. Counted total nodes.
7. Inserted nodes at the end using InsertLast().
8. Displayed the updated linked list.
9. Displayed the updated node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()    : O(1)

InsertLast()     : O(n)

Display()        : O(n)

Count()          : O(1)

Space Complexity : O(1)
(Excluding dynamically allocated nodes)

===============================================================================
Conclusion:
===============================================================================

Program 011 demonstrates the implementation of both InsertFirst() and
InsertLast() operations in a Singly Linked List using C++. The program
illustrates dynamic node creation, pointer manipulation, list traversal,
and efficient node counting using the iCount data member. Together, these
operations form the foundation for more advanced linked list operations
such as insertion at a specific position and deletion.

===============================================================================
*/
