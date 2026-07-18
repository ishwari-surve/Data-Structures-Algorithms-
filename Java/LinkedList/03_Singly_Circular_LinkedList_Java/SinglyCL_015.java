/*
================================================================================
Program Name    : InsertAtPos() in Singly Circular Linked List
Program Number  : 015
Description     : This program demonstrates the InsertAtPos() operation in a
                  Singly Circular Linked List using Java.
                  The program supports insertion at the beginning, end, and
                  any valid position in the list while maintaining the circular
                  link and the node count.
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Class
5. Singly Circular Linked List
6. InsertFirst()
7. InsertLast()
8. InsertAtPos()
9. Display Traversal using do-while Loop
10. Node Counting
11. Position Validation

Key Learning Points:
- InsertAtPos() inserts a node at any valid position.
- Position is validated before insertion.
- InsertFirst() is used when position is 1.
- InsertLast() is used when position is iCount + 1.
- For middle insertion, traversal reaches the previous node.
- Circular structure is preserved automatically.

================================================================================
*/
// Program 15 : InsertAtPos() in Singly Circular Linked List
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
        if((iPos < 1) || (iPos > iCount + 1))
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node(no);
            node temp = first;

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
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
            node temp = first;

            while(temp.next != last)
            {
                temp = temp.next;
            }

            last = temp;
            last.next = first;
        }

        iCount--;
    }

    ///////////////////////////////////////////////////////////////

    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            // Program 16
        }
    }
}

///////////////////////////////////////////////////////////////////////////

class SinglyCL15
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

        sobj.DeleteLast();
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);

        sobj.InsertAtPos(105, 4);
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are : " + iRet);
    }
}
/*
================================================================================
Expected Output:
================================================================================

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->
Number of nodes are : 6

| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->
Number of nodes are : 5

| 21 | -> | 51 | -> | 101 | -> | 111 | ->
Number of nodes are : 4

| 21 | -> | 51 | -> | 101 | -> | 105 | -> | 111 | ->
Number of nodes are : 5

================================================================================
Memory Representation:
================================================================================

Before InsertAtPos(105, 4)

                 first
                   │
                   ▼
        +----+      +----+      +-----+      +-----+
        | 21 | ───► | 51 | ───► | 101 | ───► | 111 |
        +----+      +----+      +-----+      +-----+
           ▲                                       │
           └────────────── last.next ──────────────┘
                                           ▲
                                           │
                                          last

After InsertAtPos(105, 4)

                 first
                   │
                   ▼
        +----+      +----+      +-----+      +-----+      +-----+
        | 21 | ───► | 51 | ───► | 101 | ───► | 105 | ───► | 111 |
        +----+      +----+      +-----+      +-----+      +-----+
           ▲                                                  │
           └──────────────────── last.next ───────────────────┘
                                                     ▲
                                                     │
                                                    last

================================================================================
Explanation:
================================================================================

The constructor initializes first and last to null and sets iCount to 0.

InsertFirst() inserts a new node at the beginning of the circular linked
list and updates last.next to maintain the circular connection.

InsertLast() inserts a new node at the end of the list, updates last to
the newly inserted node, and reconnects last.next to first.

InsertAtPos() first validates the given position.

• If the position is less than 1 or greater than iCount + 1, insertion is
  rejected.
• If the position is 1, InsertFirst() is called.
• If the position is iCount + 1, InsertLast() is called.
• Otherwise, traversal reaches the node before the desired position and the
  new node is inserted between two existing nodes.

For InsertAtPos(105, 4):

Step 1: Traverse to position 3 (node 101).

Step 2:
newn.next = temp.next

Step 3:
temp.next = newn

The circular link remains valid because the insertion occurs in the middle
of the list.

The node counter (iCount) is incremented after a successful middle insertion.

================================================================================
Program Flow:
================================================================================

Create SinglyCL Object
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
DeleteLast()
          │
          ▼
InsertAtPos(105, 4)
          │
          ▼
Display Updated List
          │
          ▼
Count Nodes
          │
          ▼
Program Terminates

================================================================================
Operations Performed:
================================================================================

1. Created a Singly Circular Linked List object.
2. Inserted nodes using InsertFirst().
3. Inserted nodes using InsertLast().
4. Displayed the circular linked list.
5. Counted the total number of nodes.
6. Deleted the first node.
7. Deleted the last node.
8. Inserted node 105 at position 4.
9. Displayed the updated linked list.
10. Updated iCount after insertion.

================================================================================
Time Complexity:
================================================================================

InsertFirst()   : O(1)
InsertLast()    : O(1)
InsertAtPos()   : O(n)
DeleteFirst()   : O(1)
DeleteLast()    : O(n)
Display()       : O(n)
Count()         : O(1)

Space Complexity: O(1)

================================================================================
Conclusion:
================================================================================

Program 015 demonstrates insertion at a specified position in a Singly
Circular Linked List. The operation correctly handles insertion at the
beginning, end, and middle of the list while preserving the circular
structure and maintaining an accurate node count.

================================================================================
*/
