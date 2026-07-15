/*
================================================================================
Program Name    : Singly Linked List - DeleteFirst() and DeleteLast() Operations
Program Number  : 013 
Description     : This program demonstrates the implementation of
                  DeleteFirst() and DeleteLast() operations in a
                  Singly Linear Linked List. DeleteFirst() removes
                  the first node from the linked list, whereas
                  DeleteLast() removes the last node by traversing
                  the list. The node counter (iCount) is updated
                  automatically after every successful deletion.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve

================================================================================
Concepts Used:
1. Class Encapsulation (private/public)
2. DeleteFirst() Implementation
3. DeleteLast() Implementation
4. Linked List Traversal
5. Temporary Reference (temp)
6. InsertFirst() Operation
7. InsertLast() Operation
8. Display() Operation
9. Count() Operation
10. Automatic Node Counting

Key Learning Points:
- DeleteFirst() removes the first node in O(1) time.
- DeleteLast() traverses the linked list to locate the second last node.
- Empty and single-node linked lists are handled separately.
- iCount is updated automatically after successful deletion.
- Display() verifies the updated linked list after deletion.
- Count() returns the current number of nodes in O(1) time.
================================================================================
*/
class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    private node first;
    private int iCount;

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }

        System.out.print("NULL");
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        iCount++;
    }

    public void InsertAtPos(int iNo,int iPos)
    {

    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            node temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {

    }
}

class SinglyLL013
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of Nodes : " + iRet);

        sobj.DeleteFirst();

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of Nodes : " + iRet);

        sobj.DeleteLast();

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of Nodes : " + iRet);
    }
}
/*
================================================================================
Expected Output:
================================================================================

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of Nodes : 6

| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of Nodes : 5

| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of Nodes : 4

================================================================================
Memory Diagram:
================================================================================

Initial List

first

|
v

|11| → |21| → |51| → |101| → |111| → |121| → NULL

After DeleteFirst()

first

|
v

|21| → |51| → |101| → |111| → |121| → NULL

After DeleteLast()

first

|
v

|21| → |51| → |101| → |111| → NULL

================================================================================
Pointer/Logic Explanation:
================================================================================

DeleteFirst() Logic:

• If the linked list is empty, no deletion is performed.

• If only one node exists,
  first becomes null.

• Otherwise,

first = first.next;

The first node is removed from the linked list.

------------------------------------------------------------

DeleteLast() Logic:

• If the linked list is empty,
  no deletion is performed.

• If only one node exists,
  first becomes null.

• Otherwise,

Create a temporary reference.

node temp = first;

Traverse until temp reaches the second last node.

while(temp.next.next != null)
{
    temp = temp.next;
}

Disconnect the last node.

temp.next = null;

------------------------------------------------------------

Execution Trace:

Initial List

11 → 21 → 51 → 101 → 111 → 121

DeleteFirst()

21 → 51 → 101 → 111 → 121

DeleteLast()

21 → 51 → 101 → 111

iCount

6 → 5 → 4

================================================================================
Time Complexity:
================================================================================

DeleteFirst()   : O(1)

DeleteLast()    : O(n)

Display()       : O(n)

Count()         : O(1)

Space Complexity: O(1)

================================================================================
Conclusion:
================================================================================

Program 013 demonstrates the implementation ofDeleteFirst() and DeleteLast() operations in a
Singly Linear Linked List. DeleteFirst() removesthe first node in constant time, whereas 
DeleteLast() uses traversal to remove the last node. The nodecounter is maintained automatically, 
allowing Count() to execute in O(1) time. Together with InsertFirst() and InsertLast(), these 
operations complete the fundamental insertion and deletion operations of a Singly Linear Linked List.

================================================================================
*/
