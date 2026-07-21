/*
===============================================================================
Program Name    : Singly Circular Linked List - DeleteFirst Operation
Program Number  : 013
Description     : This program implements the DeleteFirst() function for a
                  Singly Circular Linked List. It removes the first node,
                  updates the first pointer, reconnects the last node to the
                  new first node, and decreases the node count.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:
1. Singly Circular Linked List
2. DeleteFirst()
3. Dynamic Memory Deallocation
4. Pointer Manipulation
5. Circular Link Maintenance
6. Class and Objects

Key Learning Points:
- Deleting the first node of a circular linked list.
- Updating the first pointer correctly.
- Maintaining circular linkage using last->next.
- Handling empty and single-node lists.
- Updating node count after deletion.

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

class SinglyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);

    void DeleteFirst();

    void InsertAtPos(int,int) {}
    void DeleteLast() {}
    void DeleteAtPos(int) {}
};

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void SinglyCL::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<"\n";
}

int SinglyCL::Count()
{
    return iCount;
}

void SinglyCL::InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    last->next = first;

    iCount++;
}

void SinglyCL::InsertLast(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    last->next = first;

    iCount++;
}

void SinglyCL::DeleteFirst()
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
        delete last->next;
        last->next = first;
    }

    iCount--;
}

int main()
{
    SinglyCL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.DeleteFirst();

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}
