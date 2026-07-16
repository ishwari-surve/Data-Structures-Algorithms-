/*
===============================================================================
Program Name    : InsertFirst Operation in Singly Linked List
Program Number  : 010 
Description     : This program demonstrates the InsertFirst() operation of a
                  Singly Linked List. A new node is dynamically allocated
                  using the new operator and inserted at the beginning of
                  the linked list. The node counter (iCount) is updated
                  after every successful insertion.
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
7. Pointer Manipulation
8. Node Counting

Key Learning Points:
- Nodes are created dynamically using new.
- InsertFirst() inserts a node at the beginning of the list.
- No traversal is required.
- first always points to the first node.
- iCount keeps track of the total number of nodes.

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

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        
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

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | -> NULL
Number of Elements are : 3

===============================================================================
Memory Representation:
===============================================================================

Initially

first
 │
 ▼
NULL

After InsertFirst(51)

first
 │
 ▼
+------+------+
|  51  | NULL |
+------+------+

After InsertFirst(21)

first
 │
 ▼
+------+------+
|  21  |   •------+
+------+------+
               |
               ▼
        +------+------+
        |  51  | NULL |
        +------+------+

After InsertFirst(11)

first
 │
 ▼
+------+------+
|  11  |   •------+
+------+------+   |
                  ▼
           +------+------+
           |  21  |   •------+
           +------+------+   |
                              ▼
                       +------+------+
                       |  51  | NULL |
                       +------+------+

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first to NULL and
iCount to 0.

The InsertFirst() function dynamically allocates memory for a new node,
stores the given data, and inserts the node at the beginning of the linked
list.

If the list is empty, first points directly to the new node.

Otherwise,

• newn->next stores the address of the current first node.
• first is updated to point to the new node.

After every successful insertion, iCount is incremented to maintain the
correct number of nodes.

Display() traverses the linked list from first and prints every node.

Count() simply returns the value of iCount.

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
2. Initialized first to NULL.
3. Initialized iCount to 0.
4. Allocated memory for new nodes.
5. Inserted nodes at the beginning of the list.
6. Updated first after each insertion.
7. Incremented iCount after every insertion.
8. Displayed all nodes.
9. Returned the total number of nodes.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)
Display()       : O(n)
Count()         : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the InsertFirst() operation of a Singly Linked
List. Since insertion occurs directly at the beginning of the list, no
traversal is required, making InsertFirst() one of the most efficient
linked list operations with constant time complexity O(1). The program also
maintains the total number of nodes using the iCount variable.

===============================================================================
*/
