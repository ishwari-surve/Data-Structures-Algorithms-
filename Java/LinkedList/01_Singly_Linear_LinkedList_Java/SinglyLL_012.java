/*
================================================================================
Program Name    : Singly Linked List - Display() and Count() Operations
Program Number  : 012 
Description     : This program demonstrates the implementation of
                  Display() and Count() operations in a Singly
                  Linear Linked List. Display() traverses the
                  linked list using a temporary reference and
                  prints all the nodes sequentially, while Count()
                  returns the total number of nodes maintained
                  by the iCount variable.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Class Encapsulation (private/public)
2. Display() Implementation
3. Count() Implementation
4. Linked List Traversal
5. Temporary Reference (temp)
6. InsertFirst() Operation
7. InsertLast() Operation
8. Automatic Node Counting
9. Constructor Pattern

Key Learning Points:
- Display() traverses the linked list using a temporary reference.
- The original first reference remains unchanged during traversal.
- Each node is visited exactly once.
- Count() returns the value of iCount in O(1) time.
- Display() requires traversal, whereas Count() does not.
- Temporary references are commonly used in traversal-based operations.
- Display() forms the foundation for Search(), Frequency(), and other traversal operations.
======================================================================================
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
            System.out.print("| "+temp.data+"| -> ");
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
            node temp = null;
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void InsertAtPos(int iNo,int iPos)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int iPos)
    {}
}

class SinglyLL012
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
        System.out.println("Number of Nodes : "+iRet);
    }
}
/*
================================================================================
Expected Output:
================================================================================

|11| -> |21| -> |51| -> |101| -> |111| -> |121| -> NULL

Number of Nodes : 6

================================================================================
Memory Diagram:
================================================================================

first
  |
  v

|11| → |21| → |51| → |101| → |111| → |121| → NULL

temp

Initially

temp = first

temp
 |
 v
|11|

After First Move

temp
 |
 v
|21|

After Second Move

temp
 |
 v
|51|

...

Finally

temp = null

Traversal Completed

================================================================================
Pointer/Logic Explanation:
================================================================================

Display() Logic:

Step 1:

Create a temporary reference.

node temp = first;

Step 2:

Traverse until temp becomes null.

while(temp != null)
{
    System.out.print("|"+temp.data+"| -> ");
    temp = temp.next;
}

Step 3:

Print NULL after traversal.

------------------------------------------------------------

Count() Logic:

Count() simply returns iCount.

return iCount;

Since iCount is updated automatically during every
insertion and deletion operation, traversal is not
required.

------------------------------------------------------------

Execution Trace:

Display()

temp starts from first

11 → 21 → 51 → 101 → 111 → 121

Output

|11| -> |21| -> |51| -> |101| -> |111| -> |121| -> NULL

------------------------------------------------------------

Count()

Current value of iCount = 6

Output

Number of Nodes : 6

================================================================================
Time Complexity:
================================================================================

Display()        : O(n)

Count()          : O(1)

InsertFirst()    : O(1)

InsertLast()     : O(n)

Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 012 demonstrates the implementation of the
Display() and Count() operations in a Singly Linear
Linked List. Display() traverses the linked list
using a temporary reference without modifying the
first reference, while Count() returns the node
count maintained by iCount in constant time O(1).
These operations serve as the foundation for
advanced traversal-based linked list algorithms.

================================================================================
*/
