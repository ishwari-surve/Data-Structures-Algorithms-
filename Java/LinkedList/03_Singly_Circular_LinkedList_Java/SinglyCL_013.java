/*
===============================================================================
Program Name    : DeleteFirst() Operation in Singly Circular Linked List
Program Number  : 013
Description     : This program demonstrates the DeleteFirst() operation
                  in a Singly Circular Linked List using Java.

                  The program supports insertion at the beginning and
                  end of the linked list, displays the list, counts the
                  total number of nodes, and deletes the first node while
                  maintaining the circular link between the last and
                  first nodes.

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
6. InsertFirst() Operation
7. InsertLast() Operation
8. DeleteFirst() Operation
9. Display() Operation
10. Count() Operation
11. Head and Tail Pointer
12. Node Counter (iCount)

Key Learning Points:
- DeleteFirst() removes the first node of the circular linked list.
- The circular link is maintained by updating last.next.
- Handles empty, single-node and multiple-node cases.
- Display() traverses the list using a do-while loop.
- Count() returns the total number of nodes.
- iCount is updated after deletion.

===============================================================================
*/
// Program 13 : DeleteFirst() in Singly Circular Linked List

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
        }
        while(temp != last.next);

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
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
        }

        iCount--;
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

class SinglyCL13
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

        sobj.DeleteFirst();

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

| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before DeleteFirst()

                    first
                      │
                      ▼
      +------+    +------+    +------+    +-------+    +-------+    +-------+
      | 11 | •--->| 21 | •--->| 51 | •--->| 101 | •--->| 111 | •--->| 121 | •--+
      +------+    +------+    +------+    +-------+    +-------+    +-------+   |
           ▲                                                                     |
           |_____________________________________________________________________|
                                      last

After DeleteFirst()

                    first
                      │
                      ▼
      +------+    +------+    +-------+    +-------+    +-------+
      | 21 | •--->| 51 | •--->| 101 | •--->| 111 | •--->| 121 | •--+
      +------+    +------+    +-------+    +-------+    +-------+   |
           ▲                                                          |
           |__________________________________________________________|
                                   last

iCount = 5

===============================================================================
Explanation:
===============================================================================

The constructor initializes first and last to NULL and sets iCount to 0.

Nodes are inserted using InsertFirst() and InsertLast(), maintaining
the circular structure by assigning:

• last.next = first

The DeleteFirst() function handles three different cases.

Case 1 : Empty Linked List

• If both first and last are NULL, no deletion is performed.

Case 2 : Single Node

• first and last point to the same node.
• Both pointers are set to NULL.

Case 3 : Multiple Nodes

• first is moved to the second node.
• last.next is updated to the new first node.
• The circular structure remains intact.

Finally, iCount is decremented to maintain the correct node count.

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
Display Linked List
          │
          ▼
Count Nodes
          │
          ▼
DeleteFirst()
          │
          ▼
Update first
          │
          ▼
Update last.next
          │
          ▼
Display Updated Linked List
          │
          ▼
Display Updated Count
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
6. Displayed all nodes.
7. Counted the total number of nodes.
8. Deleted the first node.
9. Updated first and last.next.
10. Displayed the updated linked list.
11. Returned the updated node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)

InsertLast()    : O(1)

DeleteFirst()   : O(1)

Display()       : O(n)

Count()         : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 013 demonstrates the DeleteFirst() operation in a Singly
Circular Linked List. The first node is removed efficiently without
traversing the list by updating first and maintaining the circular
link through last.next. The program correctly handles empty, single-
node, and multiple-node linked lists while maintaining the node count
using iCount.

===============================================================================
*/
