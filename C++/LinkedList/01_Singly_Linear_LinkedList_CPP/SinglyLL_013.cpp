/*
===============================================================================
Program Name    : Display Using FOR Loop in Singly Linked List
Program Number  : 013
Description     : This program demonstrates an alternative method of
                  traversing a Singly Linked List using a FOR loop
                  instead of the traditional WHILE loop.

                  The Display() function uses the node counter
                  (iCount) to control traversal and displays every
                  node present in the linked list.

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
6. FOR Loop Traversal
7. InsertFirst Operation
8. InsertLast Operation
9. Node Counting
10. Pointer Manipulation

Key Learning Points:
- Display() traverses the linked list using a FOR loop.
- The loop executes exactly iCount times.
- iCount eliminates repeated NULL comparisons.
- InsertFirst() inserts nodes at the beginning.
- InsertLast() inserts nodes at the end.
- Count() returns the total number of nodes in O(1).

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
    int i = 0;
    PNODE temp = NULL;
    temp = this -> first;

    for(i = 1; i <= this -> iCount; i++, temp = temp -> next)            // Insetad of WHILE use FOR Loop
    {
        cout<<"| "<<temp -> data<<" |-> ";
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
Number of Elements are : 3

| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
Number of Elements are : 6

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

After InsertFirst Operations

first
 │
 ▼
+------+------+      +------+------+      +------+------+
|  11  |   •-------->|  21  |   •-------->|  51  | NULL |
+------+------+      +------+------+      +------+------+

iCount = 3

-------------------------------------------------------------------------------

After InsertLast Operations

first
 │
 ▼

+------+------+    +------+------+    +------+------+    +------+------+
|  11  |   •------>|  21  |   •------>|  51  |   •------>| 101  |   •--+
+------+------+    +------+------+    +------+------+    +------+------+
                                                                     |
                                                                     ▼
                                                             +------+------+
                                                             | 111  |   •--+
                                                             +------+------+
                                                                     |
                                                                     ▼
                                                             +------+------+
                                                             | 121  | NULL |
                                                             +------+------+

iCount = 6

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first to NULL
and iCount to 0.

InsertFirst() creates a new node dynamically and inserts it at the
beginning of the linked list. Since insertion occurs at the front,
no traversal is required.

InsertLast() traverses the linked list until the last node is reached
and then connects the newly created node.

Unlike previous programs, the Display() function uses a FOR loop for
traversal.

Instead of

while(temp != NULL)

the program uses

for(i = 1; i <= this->iCount; i++, temp = temp->next)

Since iCount always stores the exact number of nodes, the loop executes
precisely once for every node present in the linked list.

Count() simply returns the value stored in iCount.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Invoked
          │
          ▼
first = NULL
iCount = 0
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
Display Using FOR Loop
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
Display Updated List
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
4. Inserted three nodes using InsertFirst().
5. Displayed the linked list using a FOR loop.
6. Returned the current node count.
7. Inserted three nodes using InsertLast().
8. Displayed the updated linked list.
9. Returned the updated node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()    : O(1)

InsertLast()     : O(n)

Display()        : O(n)

Count()          : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 013 demonstrates an alternative approach for traversing a
Singly Linked List by using a FOR loop instead of a WHILE loop.
Since the exact number of nodes is maintained by iCount, traversal
becomes controlled and predictable while producing the same output as
the traditional traversal method. This program also reinforces the
InsertFirst(), InsertLast(), Display(), and Count() operations in a
Singly Linked List.

===============================================================================
*/
