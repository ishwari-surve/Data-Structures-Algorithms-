/*
===============================================================================
Program Name    : DeleteFirst Operation in Singly Linked List 
Program Number  : 014
Description     : This program demonstrates the DeleteFirst()
                  operation of a Singly Linked List. The first
                  node of the linked list is removed safely while
                  handling all possible cases such as an empty
                  list, a single-node list, and a multi-node list.

                  The node counter (iCount) is updated after every
                  successful deletion.

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
9. Pointer Manipulation
10. Node Counting

Key Learning Points:
- DeleteFirst() removes the first node of the linked list.
- Handles empty, single-node and multiple-node lists safely.
- Temporary pointer is used before deleting the node.
- first is updated to point to the next node.
- iCount maintains the correct number of nodes.

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

| 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
Number of Elements are : 5

===============================================================================
Memory Representation:
===============================================================================

Initially

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

-------------------------------------------------------------------------------

Step 1 : Store first node in temp

temp
 │
 ▼

11 → 21 → 51 → 101 → 111 → 121 → NULL

-------------------------------------------------------------------------------

Step 2 : Move first to next node

first
 │
 ▼

21 → 51 → 101 → 111 → 121 → NULL

-------------------------------------------------------------------------------

Step 3 : Delete node pointed by temp

delete(temp);

-------------------------------------------------------------------------------

Final Linked List

first
 │
 ▼

21 → 51 → 101 → 111 → 121 → NULL

iCount = 5

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first to NULL
and iCount to 0.

Nodes are inserted into the linked list using InsertFirst() and
InsertLast().

DeleteFirst() removes the first node from the linked list.

Three cases are handled:

Case 1:
If the linked list is empty, the function immediately returns.

Case 2:
If only one node is present, that node is deleted and first becomes
NULL.

Case 3:
If multiple nodes are present, a temporary pointer stores the address
of the first node. The first pointer is moved to the second node and
the old first node is deleted using delete.

After successful deletion, iCount is decremented to maintain the
correct node count.

Display() traverses the linked list and prints all remaining nodes.

Count() returns the current value of iCount.

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
InsertFirst() Operations
          │
          ▼
InsertLast() Operations
          │
          ▼
Display Linked List
          │
          ▼
Return Node Count
          │
          ▼
DeleteFirst()
          │
          ▼
Update first Pointer
          │
          ▼
Delete Old First Node
          │
          ▼
Decrement iCount
          │
          ▼
Display Updated Linked List
          │
          ▼
Return Updated Count
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created a Singly Linked List object.
2. Initialized first to NULL.
3. Initialized iCount to 0.
4. Inserted nodes at the beginning.
5. Inserted nodes at the end.
6. Displayed the linked list.
7. Returned the total number of nodes.
8. Deleted the first node.
9. Updated the first pointer.
10. Decremented iCount.
11. Displayed the updated linked list.
12. Returned the updated node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()    : O(1)

InsertLast()     : O(n)

DeleteFirst()    : O(1)

Display()        : O(n)

Count()          : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 014 demonstrates the DeleteFirst() operation of a Singly
Linked List. The first node is removed efficiently without requiring
any traversal. The function safely handles empty, single-node and
multiple-node linked lists while maintaining the correct node count
using iCount. Since deletion occurs directly at the beginning of the
list, DeleteFirst() executes in constant time O(1).

===============================================================================
*/
