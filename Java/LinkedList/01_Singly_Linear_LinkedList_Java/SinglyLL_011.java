/*
================================================================================
Program Name    : Singly Linked List - InsertLast() Implementation
Program Number  : 011 (Java Version)
Description     : This program demonstrates the implementation of
                  InsertLast() in a Singly Linear Linked List. The
                  operation traverses the linked list using a
                  temporary reference until the last node is found,
                  then links the newly created node at the end of
                  the list. The node counter (iCount) is updated
                  automatically after every successful insertion.
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Class Encapsulation (private/public)
2. InsertFirst() Implementation
3. InsertLast() Implementation
4. Linked List Traversal
5. Temporary Reference (temp)
6. Automatic iCount Increment
7. Constructor Pattern
8. Dynamic Object Creation

Key Learning Points:
- InsertLast() inserts a new node at the end of the linked list.
- A temporary reference is used for traversal.
- Traversal continues until temp.next becomes null.
- The last node is linked to the newly created node.
- iCount is updated automatically after every insertion.
- Count() returns the total number of nodes in O(1) time.
- InsertLast() requires traversal, so its time complexity is O(n).
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
    {}

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

class SinglyLL011
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);
    }
}
/*
================================================================================
Expected Output:
================================================================================

(No output - builds linked list in memory)

Linked List Created:

first → [11] → [21] → [51] → [101] → [111] → [121] → null

iCount = 6

================================================================================
Memory Diagram:
================================================================================

After InsertFirst() Operations

first
  |
  v
[11|→] → [21|→] → [51|null]

iCount = 3


After InsertLast(101)

first
  |
  v
[11|→] → [21|→] → [51|→] → [101|null]

iCount = 4


After InsertLast(111)

first
  |
  v
[11|→] → [21|→] → [51|→] → [101|→] → [111|null]

iCount = 5


After InsertLast(121)

first
  |
  v
[11|→] → [21|→] → [51|→] → [101|→] → [111|→] → [121|null]

iCount = 6

================================================================================
Pointer/Logic Explanation:
================================================================================

InsertLast() Logic:

Step 1:
Create a new node.

node newn = new node(iNo);

Step 2:
Check whether the linked list is empty.

if(first == null)

If the list is empty,
the new node becomes the first node.

Step 3:
If the list is not empty,
create a temporary reference.

node temp = first;

Step 4:
Traverse the linked list.

while(temp.next != null)
{
    temp = temp.next;
}

The loop stops when temp reaches the last node.

Step 5:
Attach the new node.

temp.next = newn;

Step 6:
Increment the node counter.

iCount++;

Execution Trace:

InsertLast(101)

Current List

11 → 21 → 51 → null

temp starts from first

11 → 21 → 51

temp reaches 51

51.next = 101

Result

11 → 21 → 51 → 101

------------------------------------------------------------

InsertLast(111)

Traversal

11 → 21 → 51 → 101

Last node = 101

101.next = 111

Result

11 → 21 → 51 → 101 → 111

------------------------------------------------------------

InsertLast(121)

Traversal

11 → 21 → 51 → 101 → 111

Last node = 111

111.next = 121

Final List

11 → 21 → 51 → 101 → 111 → 121

================================================================================
Time Complexity:
================================================================================

InsertFirst()    : O(1)

InsertLast()     : O(n)

Count()          : O(1)

Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 011 demonstrates the implementation of the
InsertLast() operation in a Singly Linear Linked List.
A temporary reference is used to traverse the linked
list until the last node is reached, where the newly
created node is linked successfully. The node counter
is maintained automatically after every insertion,
allowing Count() to execute in constant time O(1).
This program completes the implementation of insertion
operations at both the beginning and the end of the
linked list.

================================================================================
*/
