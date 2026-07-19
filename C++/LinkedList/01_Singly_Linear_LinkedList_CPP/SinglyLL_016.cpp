/*
===============================================================================
Program Name    : InsertAtPos Operation in Singly Linked List
Program Number  : 016
Description     : This program demonstrates the InsertAtPos() operation of a
                  Singly Linked List. A new node is inserted at a specified
                  position after validating the position entered by the user.
                  The program also supports InsertFirst(), InsertLast(),
                  DeleteFirst(), and DeleteLast() operations while maintaining
                  the node count using iCount.
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
6. InsertFirst Operation
7. InsertLast Operation
8. InsertAtPos Operation
9. DeleteFirst Operation
10. DeleteLast Operation
11. Pointer Traversal
12. Position Validation
13. Node Counting

Key Learning Points:
- InsertAtPos() inserts a node at any valid position.
- Position is validated before insertion.
- InsertFirst() and InsertLast() are reused for boundary cases.
- Traversal is required for middle insertion.
- iCount maintains the total number of nodes.

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
        newn = new NODE;
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

        
        this -> iCount--;
    }
}

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

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.InsertAtPos(105,4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    
    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | -> NULL
Number of Elements are : 3

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of Elements are : 6

| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of Elements are : 5

| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of Elements are : 4

| 21 | -> | 51 | -> | 101 | -> | 105 | -> | 111 | -> NULL
Number of Elements are : 5

===============================================================================
Memory Representation:
===============================================================================

Before InsertAtPos(105,4)

first
 │
 ▼

+-----+     +-----+     +-----+     +------+
| 21  | --> | 51  | --> | 101 | --> | 111 | --> NULL
+-----+     +-----+     +-----+     +------+

After InsertAtPos(105,4)

first
 │
 ▼

+-----+     +-----+     +-----+     +------+     +------+
| 21  | --> | 51  | --> | 101 | --> | 105 | --> | 111 | --> NULL
+-----+     +-----+     +-----+     +------+     +------+

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first to NULL and
iCount to 0.

InsertAtPos() first validates the given position.

If the position is invalid, the function displays an error message and
returns immediately.

If the position is 1, InsertFirst() is called.

If the position is iCount + 1, InsertLast() is called.

For insertion at any middle position:

• A new node is created dynamically.
• A temporary pointer traverses the list until the node before the
  desired position.
• The new node's next pointer stores the address of the next node.
• The previous node's next pointer is updated to point to the new node.

Finally, iCount is incremented to maintain the correct number of nodes.

Display() traverses and displays all nodes.

Count() returns the total number of nodes.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Invoked
          │
          ▼
InsertFirst()
          │
          ▼
InsertLast()
          │
          ▼
DeleteFirst()
          │
          ▼
DeleteLast()
          │
          ▼
InsertAtPos()
          │
          ▼
Display Linked List
          │
          ▼
Return Node Count
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created a Singly Linked List object.
2. Inserted nodes at the beginning.
3. Inserted nodes at the end.
4. Deleted the first node.
5. Deleted the last node.
6. Inserted a node at the specified position.
7. Updated iCount after insertion.
8. Displayed the linked list.
9. Returned the total number of nodes.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)
InsertLast()    : O(n)
InsertAtPos()   : O(n)
DeleteFirst()   : O(1)
DeleteLast()    : O(n)
Display()       : O(n)
Count()         : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 016 demonstrates the InsertAtPos() operation of a Singly Linked
List. The function validates the specified position before inserting a
new node. For middle insertion, traversal is required to locate the
appropriate position, resulting in O(n) time complexity. The program
also reuses InsertFirst() and InsertLast() for boundary cases, making
the implementation modular and efficient while maintaining the correct
node count using iCount.

===============================================================================
*/
