/*
===============================================================================
Program Name    : DeleteLast Operation in Singly Linked List
Program Number  : 015
Description     : This program demonstrates the DeleteLast() operation of a
                  Singly Linked List. The program removes the last node from
                  the linked list while handling all possible cases such as 
                  an empty list, a single-node list, and a list containing
                  multiple nodes. The node counter (iCount) is updated after
                  every successful deletion.
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
8. DeleteFirst Operation
9. DeleteLast Operation
10. Pointer Traversal
11. Node Counting

Key Learning Points:
- DeleteLast() removes the last node from the linked list.
- Traversal is required to reach the second last node.
- Handles empty list and single node list separately.
- The last node is deleted using delete.
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
{}

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

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.DeleteLast();
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

===============================================================================
Memory Representation:
===============================================================================

Before DeleteLast()

first
 │
 ▼

+-----+     +-----+     +-----+     +------+     +------+ 
| 21  | --> | 51  | --> | 101 | --> | 111 | --> | 121 | --> NULL
+-----+     +-----+     +-----+     +------+     +------+
                                                   ▲
                                                   │
                                              Node Deleted

After DeleteLast()

first
 │
 ▼

+-----+     +-----+     +-----+     +------+
| 21  | --> | 51  | --> | 101 | --> | 111 | --> NULL
+-----+     +-----+     +-----+     +------+

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first to NULL and
iCount to 0.

DeleteLast() removes the last node from the linked list.

Case 1:
If the linked list is empty, the function simply returns.

Case 2:
If only one node is present, that node is deleted and first becomes NULL.

Case 3:
If multiple nodes are present, a temporary pointer traverses the list
until it reaches the second last node.

The last node is deleted using the delete operator and the second last
node becomes the new last node by setting its next pointer to NULL.

After successful deletion, iCount is decremented.

Display() traverses the linked list and prints all nodes.

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
Display Linked List
          │
          ▼
DeleteFirst()
          │
          ▼
Display Linked List
          │
          ▼
DeleteLast()
          │
          ▼
Display Updated Linked List
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
4. Displayed all nodes.
5. Counted total number of nodes.
6. Deleted the first node.
7. Deleted the last node.
8. Updated iCount.
9. Displayed the modified linked list.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)
InsertLast()    : O(n)
DeleteFirst()   : O(1)
DeleteLast()    : O(n)
Display()       : O(n)
Count()         : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================
Program 015 demonstrates the DeleteLast() operation of a Singly Linked
List. Since the second last node must be located before deleting the
last node, traversal of the linked list is required, resulting in a
time complexity of O(n). The program also correctly handles empty,
single-node, and multiple-node linked lists while maintaining the
correct node count using iCount.

===============================================================================
*/
