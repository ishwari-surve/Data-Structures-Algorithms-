/*
===============================================================================

Program Name    : Singly Linked List - Using iCount to Check Empty List
Program Number  : 012
Description     : This program demonstrates an alternative approach
                  for checking whether a Singly Linked List is empty.

                  Instead of verifying whether the first pointer is
                  NULL, the program uses the iCount data member.
                  InsertFirst() and InsertLast() operations are
                  implemented using iCount to determine whether the
                  linked list contains any nodes.

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
                  Count(),
                  Node Counter (iCount)

Input           : Node values inserted through function calls.

Output          : Displays the linked list after insertion operations
                  and prints the total number of nodes.

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

    if(iCount == 0)                         // 2nd Approach
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

    if(iCount == 0)                         // 2nd Approach
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

    sobj.InsertFirst(51);                // InsertFirst(sobj,51)
    sobj.InsertFirst(21);                // InsertFirst(sobj,21)
    sobj.InsertFirst(11);                // InsertFirst(sobj,11)

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

Initially

first
 │
 ▼
NULL

iCount = 0

-------------------------------------------------------------------------------

After InsertFirst(51)

first
 │
 ▼
+------+------+
|  51  | NULL |
+------+------+

iCount = 1

-------------------------------------------------------------------------------

After InsertFirst(21)

first
 │
 ▼
+------+-----+     +------+------+
|  21  |  • ─────► |  51  | NULL |
+------+-----+     +------+------+

iCount = 2

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

iCount = 4

-------------------------------------------------------------------------------

After InsertLast(111)

first
 │
 ▼
11 → 21 → 51 → 101 → 111 → NULL

iCount = 5

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

This program implements InsertFirst() and InsertLast() operations using
the iCount data member to determine whether the linked list is empty.

Unlike previous programs that checked

    first == NULL

this program checks

    iCount == 0

before performing insertion.

InsertFirst():

• Creates a new node dynamically using the new operator.
• If iCount is 0, the new node becomes the first node.
• Otherwise, the new node is inserted before the current first node.
• Increments iCount after successful insertion.

InsertLast():

• Creates a new node dynamically.
• If iCount is 0, the new node becomes the first node.
• Otherwise, traverses the linked list until the last node.
• Connects the last node with the newly created node.
• Increments iCount after insertion.

Display():

• Traverses the linked list from first.
• Prints every node until NULL is reached.

Count():

• Returns the current value of iCount.
• Since iCount is maintained after every insertion, node counting
  is performed in constant time.

Why Use iCount?

• Directly indicates whether the list is empty.
• Avoids repeated pointer comparisons.
• Simplifies future insertion and deletion operations.
• Maintains logical consistency throughout the linked list.

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
Check iCount == 0
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
Display Count
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
4. Used iCount to check whether the list is empty.
5. Inserted nodes at the beginning using InsertFirst().
6. Displayed the linked list.
7. Returned the node count using Count().
8. Inserted nodes at the end using InsertLast().
9. Displayed the updated linked list.
10. Displayed the updated node count.

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

Program 012 demonstrates an alternative and efficient approach for
checking whether a Singly Linked List is empty by using the iCount
member variable instead of comparing the first pointer with NULL.
The program successfully performs insertion at both the beginning
and end of the linked list while maintaining an accurate node count,
making the implementation more organized and suitable for future
linked list operations.

===============================================================================
*/
