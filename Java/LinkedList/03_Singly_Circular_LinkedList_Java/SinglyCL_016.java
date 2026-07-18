/*
================================================================================
Program Name    : Complete Singly Circular Linked List
Program Number  : 016 
Description     : This program demonstrates the complete implementation of a
                  Singly Circular Linked List in Java. It supports insertion, 
                  deletion, display and count operations, including position-
                  based insertion and deletion while maintaining the circular
                  structure of the linked list.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Object-Oriented Programming (OOP)
2. Classes and Objects
3. Constructors
4. Self-Referential Class
5. Singly Circular Linked List
6. Dynamic Object Creation
7. InsertFirst()
8. InsertLast()
9. InsertAtPos()
10. DeleteFirst()
11. DeleteLast()
12. DeleteAtPos()
13. Circular Traversal using do-while Loop
14. Node Counting (iCount)

Key Learning Points:
- Complete implementation of Singly Circular Linked List.
- first and last pointers maintain circular connectivity.
- last.next always points to first.
- Position-based insertion and deletion are supported.
- iCount keeps track of the total number of nodes.
- Display() traverses the circular list using a do-while loop.

================================================================================
*/
// Program 16 : Singly Circular Linked List in Java (Complete)

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
        node target = null;

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
            node temp = first;

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            target = temp.next;
            temp.next = target.next;
            target = null;

            iCount--;
        }
    }
}

///////////////////////////////////////////////////////////////////////////

class SinglyCL16
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

        sobj.DeleteAtPos(4);
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

| 21 | -> | 51 | -> | 101 | -> | 111 | ->
Number of nodes are : 4

================================================================================
Memory Representation:
================================================================================
 Initial Circular Linked List
                 first
                   │
                   ▼
          +---------------+
          | data = 11     |
          | next ---------•---------------------+
          +---------------+                     |
                  │                             |
                  ▼                             |
          +---------------+                     |
          | data = 21     |                     |
          | next ---------•-----------+         |
          +---------------+           |         |
                  │                   |         |
                  ▼                   |         |
          +---------------+           |         |
          | data = 51     |           |         |
          | next ---------•-----------+         |
          +---------------+                     |
                  │                             |
                  ▼                             |
          +---------------+                     |
          | data = 101    |                     |
          | next ---------•-----------+         |
          +---------------+           |         |
                  │                   |         |
                  ▼                   |         |
          +---------------+           |         |
          | data = 111    |           |         |
          | next ---------•-----------+         |
          +---------------+                     |
                  │                             |
                  ▼                             |
          +---------------+                     |
 last --> | data = 121    |---------------------+
          | next = first  |
          +---------------+

After DeleteFirst()
first

21 → 51 → 101 → 111 → 121
↑                     │
└─────────────────────┘

iCount = 5

After DeleteLast()
first

21 → 51 → 101 → 111
↑                │
└────────────────┘

last = 111
iCount = 4

After InsertAtPos(105,4)
first

21 → 51 → 101 → 105 → 111
↑                      │
└──────────────────────┘

iCount = 5

After DeleteAtPos(4)
first

21 → 51 → 101 → 111
↑                │
└────────────────┘

iCount = 4

================================================================================
Explanation:
================================================================================
The constructor initializes the linked list by assigning first and last to null and iCount to 0.

InsertFirst() inserts a new node at the beginning of the circular linked list. The last.next pointer is updated so that the circular connection is maintained.

InsertLast() inserts a new node at the end of the list by updating the last pointer. After insertion, last.next is again connected to first.

DeleteFirst() removes the first node. The first pointer moves to the next node and last.next is updated to point to the new first node.

DeleteLast() traverses the list until the node before the last node is reached. The last pointer is updated to this node and its next pointer is connected back to first.

InsertAtPos() validates the position before inserting a node. Depending on the position, it either calls InsertFirst(), InsertLast(), or inserts the node between two existing nodes.

DeleteAtPos() also validates the position before deletion. It deletes the first node, last node, or an intermediate node as required.

Display() traverses the circular linked list using a do-while loop so that every node is displayed exactly once.

Count() returns the current number of nodes stored in iCount.

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
     Display()
          │
          ▼
       Count()
          │
          ▼
DeleteFirst()
          │
          ▼
DeleteLast()
          │
          ▼
InsertAtPos()
          │
          ▼
DeleteAtPos()
          │
          ▼
Display Updated List
          │
          ▼
Program Terminates

================================================================================
Operations Performed:
================================================================================
1.Created a Singly Circular Linked List object.
2.Inserted nodes at the beginning.
3.Inserted nodes at the end.
4.Displayed the circular linked list.
5.Counted the total number of nodes.
6.Deleted the first node.
7.Deleted the last node.
8.Inserted a node at a specified position.
9.Deleted a node from a specified position.
10.Maintained circular linkage after every operation.
11.Updated iCount after every insertion and deletion.

================================================================================
Time Complexity:
================================================================================
InsertFirst()    : O(1)
InsertLast()     : O(1)
InsertAtPos()    : O(n)
DeleteFirst()    : O(1)
DeleteLast()     : O(n)
DeleteAtPos()    : O(n)
Display()        : O(n)
Count()          : O(1)

Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 016 demonstrates the complete implementation of a Singly Circular Linked List in 
Java. It supports all fundamental operations including insertion, deletion, traversal,
counting, and position-based modifications while preserving the circular structure of the 
list. The use of first, last, and iCount makes each operation efficientand provides a strong 
foundation for understanding circular linked list data structures.

================================================================================
*/
