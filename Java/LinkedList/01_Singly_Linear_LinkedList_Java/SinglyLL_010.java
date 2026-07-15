/*
================================================================================
Program Name    : Singly Linked List - InsertFirst with Automatic Count Update
Program Number  : 010 
Description     : This program demonstrates the implementation of
                  InsertFirst() with automatic node count
                  maintenance using iCount.

                  Every successful insertion increments the
                  counter, allowing Count() to return the total
                  number of nodes in constant time O(1).
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Class Encapsulation (private/public)
2. InsertFirst Implementation
3. Automatic iCount Increment
4. O(1) Count Operation
5. Constructor Pattern
6. Linked Node Creation
7. Time Complexity Optimization

Key Learning Points:
- iCount++ increments counter after each insertion
- Count() returns iCount (O(1) not O(n))
- Private first and iCount protect data
- InsertFirst handles empty and non-empty cases
- Maintaining iCount eliminates repeated traversal for counting nodes.
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
    private node first;        // Reference to first node
    private int iCount;        // Node counter

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {
    }

    /*
    ============================================================================
    Count() returns iCount - O(1) complexity
    No traversal needed because counter maintained automatically
    ============================================================================
    */
    public int Count()
    {
        return iCount;
    }

    /*
    ============================================================================
    InsertFirst() - Insert at beginning with automatic count
    - Creates new node
    - Empty list: new node becomes head
    - Non-empty: new node points to old head, becomes new head
    - Increments iCount after insertion
    Time Complexity: O(1)
    ============================================================================
    */
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
        
        iCount++;   // Increment counter after insertion
    }

    /*
    ============================================================================
    InsertLast() - Insert at end with automatic count (Template)
    ============================================================================
    */
    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);
        node temp = null;
        
        if(first == null)
        {
            first = newn;
        }
        else
        {
            //Logic will be implemented in the upcoming program.
        }
        
        iCount++;   // Increment counter after insertion
    }

    public void InsertAtPos(int iNo, int iPos)
    {
    }

    public void DeleteFirst()
    {
    }

    public void DeleteLast()
    {
    }

    public void DeleteAtPos(int iPos)
    {
    }
}

class SinglyLL010
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();
        
        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);
    }
}

/*
================================================================================
Expected Output:
================================================================================
(No output - builds list in memory)

List Created:
head → [11] → [21] → [51] → null

iCount = 3

================================================================================
Memory Diagram:
================================================================================

After InsertFirst(51)
first
  |
  v
[51|null]

iCount = 1

After InsertFirst(21)
first
  |
  v
[21|→] → [51|null]

iCount = 2

After InsertFirst(11)
first
  |
  v
[11|→] → [21|→] → [51|null]

iCount = 3

================================================================================
Pointer/Logic Explanation:
================================================================================

Private vs Public:

private node first;
├─ Only accessible within SinglyLL class
├─ Protected from external access
└─ Prevents accidental modification

public void InsertFirst(int iNo)
├─ Accessible from outside class
├─ Controls how first is modified
└─ Safe encapsulation

C Implementation

Count() traverses the entire linked list.

Time Complexity : O(n)

------------------------------------------------

Java Implementation

Count() simply returns iCount.

Time Complexity : O(1)

Because iCount is updated automatically after
every insertion and deletion.

InsertFirst Logic:

Step 1: Create node
node newn = new node(iNo);

Step 2: Check if empty
if(first == null) → List empty
    first = newn;
else → List has nodes
    newn.next = first;
    first = newn;

Step 3: Increment
iCount++;

Execution Trace:

Call 1: InsertFirst(51)
- newn created with data=51
- List Empty
- first = newn (51 becomes head)
- iCount = 1
- List: [51]

Call 2: InsertFirst(21)
- newn created with data=21
- List Not Empty
- newn.next = 51node
- first = newn (21 becomes head)
- iCount = 2
- List: [21] → [51]

Call 3: InsertFirst(11)
- newn created with data=11
- List Not Empty
- newn.next = 21node
- first = newn (11 becomes head)
- iCount = 3
- List: [11] → [21] → [51]

================================================================================
Time Complexity:
================================================================================
InsertFirst()    : O(1) - No traversal
Count()          : O(1) - Return iCount (not O(n) traversal)
Space Complexity : O(1) - Extra space used by the operation

================================================================================
Conclusion:
================================================================================

Program 010 demonstrates the implementation of
InsertFirst() with automatic maintenance of the
node counter (iCount). Since the counter is
updated during every insertion, Count() can
return the total number of nodes in O(1) time
without traversing the linked list.

This approach improves efficiency and forms the
basis for implementing the remaining insertion
and deletion operations.

================================================================================
*/
