/*
================================================================================
Program Name    : DeleteFirst() and DeleteLast() in Singly Circular Linked List
Program Number  : 014
Description     : This program demonstrates the DeleteFirst() and DeleteLast()
                  operations in a Singly Circular Linked List using Java.
                  The program inserts nodes at both the beginning and end,
                  displays the list, deletes the first node, deletes the last
                  node, and updates the circular links along with the node count.
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
8. DeleteFirst()
9. DeleteLast()
10. Display Traversal using do-while Loop
11. Node Counting

Key Learning Points:
- DeleteFirst() removes the first node and updates first.
- DeleteLast() removes the last node by traversing to the second-last node.
- last.next always points to first to maintain circularity.
- Special cases of empty list and single node are handled.
- iCount is decremented after every successful deletion.

================================================================================
*/
// Program 14 : DeleteFirst() and DeleteLast() in Singly Circular Linked List
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

    }
}

///////////////////////////////////////////////////////////////////////////

class SinglyCL14
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

================================================================================
Memory Representation:
================================================================================

Initial Circular Linked List

                 first
                   │
                   ▼
        +----+      +----+      +----+      +-----+      +-----+      +-----+
        | 11 | ───► | 21 | ───► | 51 | ───► | 101 | ───► | 111 | ───► | 121 |
        +----+      +----+      +----+      +-----+      +-----+      +-----+
           ▲                                                             │
           └────────────────────────────── last.next ─────────────────────┘
                                                               ▲
                                                               │
                                                              last

After DeleteFirst()

                 first
                   │
                   ▼
        +----+      +----+      +-----+      +-----+      +-----+
        | 21 | ───► | 51 | ───► | 101 | ───► | 111 | ───► | 121 |
        +----+      +----+      +-----+      +-----+      +-----+
           ▲                                                  │
           └──────────────────── last.next ───────────────────┘
                                                     ▲
                                                     │
                                                    last

After DeleteLast()

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

================================================================================
Explanation:
================================================================================

The constructor initializes first and last to null and sets iCount to 0.

InsertFirst() inserts a new node at the beginning of the circular linked
list and updates last.next to maintain the circular connection.

InsertLast() inserts a new node at the end of the list, updates last to
the newly inserted node, and reconnects last.next to first.

Display() traverses the circular linked list using a do-while loop and
stops when the traversal again reaches the first node.

DeleteFirst() handles three cases:

• If the list is empty, no deletion is performed.
• If only one node exists, both first and last become null.
• Otherwise, first moves to the next node and last.next is updated.

DeleteLast() also handles three cases:

• If the list is empty, nothing is deleted.
• If only one node exists, both first and last become null.
• Otherwise, traversal reaches the second-last node, last is updated,
  and last.next is linked back to first.

The node counter (iCount) is decremented after every successful deletion.

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
Count Nodes
          │
          ▼
DeleteFirst()
          │
          ▼
Display Updated List
          │
          ▼
DeleteLast()
          │
          ▼
Display Updated List
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
7. Displayed the updated linked list.
8. Deleted the last node.
9. Displayed the final linked list.
10. Updated iCount after each deletion.

================================================================================
Time Complexity:
================================================================================

InsertFirst()   : O(1)
InsertLast()    : O(1)
DeleteFirst()   : O(1)
DeleteLast()    : O(n)
Display()       : O(n)
Count()         : O(1)

Space Complexity: O(1)

================================================================================
Conclusion:
================================================================================
Program 014 demonstrates the DeleteFirst() and DeleteLast() operations in
a Singly Circular Linked List. The program correctly maintains the circular
link by ensuring last.next always points to first. It also handles empty,
single-node, and multiple-node cases while keeping the node count accurate,
making the implementation reliable and efficient.

================================================================================
*/
