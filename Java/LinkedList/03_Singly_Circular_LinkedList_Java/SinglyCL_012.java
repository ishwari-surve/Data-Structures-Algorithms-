/*
===============================================================================
Program Name    : Display and Count Operations in Singly Circular Linked List
Program Number  : 012
Description     : This program demonstrates the Display() and Count()
                  operations in a Singly Circular Linked List using Java.

                  The Display() function traverses the circular linked
                  list using a do-while loop and displays all nodes,
                  while the Count() function returns the total number
                  of nodes maintained by the iCount variable.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Class
5. Circular Linked List
6. Display() Operation
7. Count() Operation
8. do-while Loop
9. Head and Tail Pointer
10. Node Counter (iCount)

Key Learning Points:
- Display() traverses the circular linked list.
- Count() returns the total number of nodes.
- Traversal starts from first and ends when first is reached again.
- last.next always points to first.
- iCount is updated after every insertion.
- Count() executes in constant time.

===============================================================================
*/
// Program 12 : Display and Count in Singly Circular Linked List

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

class SinglyCL
{
    public node first;
    public node last;
    public int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    ///////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        if(first == null && last == null)
        {
            return;
        }

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    ///////////////////////////////////////////////////////////////

    public int Count()
    {
        return iCount;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertAtPos(int no, int iPos)
    {

    }

    ///////////////////////////////////////////////////////////////

    public void DeleteFirst()
    {

    }

    ///////////////////////////////////////////////////////////////

    public void DeleteLast()
    {

    }

    ///////////////////////////////////////////////////////////////

    public void DeleteAtPos(int iPos)
    {

    }
}

///////////////////////////////////////////////////////////////////////////

class SinglyCL12
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

                    first
                      │
                      ▼
      +------+    +------+    +------+    +-------+    +-------+    +-------+
      | 11 | •--->| 21 | •--->| 51 | •--->| 101 | •--->| 111 | •--->| 121 | •--+
      +------+    +------+    +------+    +-------+    +-------+    +-------+   |
           ▲                                                                     |
           |_____________________________________________________________________|
                                      last

iCount = 6

===============================================================================
Explanation:
===============================================================================

The constructor initializes first and last to NULL and sets iCount to 0.

InsertFirst() inserts new nodes at the beginning of the linked list,
whereas InsertLast() inserts new nodes at the end.

After every insertion,

• last.next is updated to point to first.

This maintains the circular nature of the linked list.

The Display() function checks whether the linked list is empty.

If the list is not empty,

• A temporary pointer (temp) is initialized to first.
• The do-while loop displays each node.
• temp moves to the next node after every iteration.
• Traversal stops when temp again reaches first
  (i.e., temp == last.next).

The Count() function simply returns the value of iCount.

Since iCount is maintained after every insertion, counting nodes does
not require traversal.

===============================================================================
Program Flow:
===============================================================================

Create SinglyCL Object
          │
          ▼
Constructor Invoked
          │
          ▼
Initialize first = NULL
Initialize last = NULL
Initialize iCount = 0
          │
          ▼
Insert Nodes
          │
          ▼
Maintain Circular Link
(last.next = first)
          │
          ▼
Call Display()
          │
          ▼
Display All Nodes
          │
          ▼
Call Count()
          │
          ▼
Display Total Number of Nodes
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created a Singly Circular Linked List object.
2. Initialized first and last pointers.
3. Initialized iCount to 0.
4. Inserted nodes using InsertFirst().
5. Inserted nodes using InsertLast().
6. Maintained the circular link.
7. Displayed all nodes using Display().
8. Returned the total number of nodes using Count().

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)

InsertLast()    : O(1)

Display()       : O(n)

Count()         : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 012 demonstrates the Display() and Count() operations of a Singly
Circular Linked List. The Display() function traverses and prints every node
exactly once using a do-while loop, while the Count() function efficiently
returns the total number of nodes in constant time using the maintained
iCount variable.

===============================================================================
*/
