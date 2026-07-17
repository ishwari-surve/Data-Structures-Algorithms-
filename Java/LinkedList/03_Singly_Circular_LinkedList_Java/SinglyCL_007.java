/*
===============================================================================
Program Name    : Creation of Singly Circular Linked List Class
Program Number  : 007
Description     : This program demonstrates the creation of a Singly Circular
                  Linked List class in Java. The class contains references to
                  the first node, last node, and a node counter. A constructor
                  initializes the linked list to an empty state, providing the
                  basic framework for implementing future linked list
                  operations.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Object
2. Constructor
3. Self-Referential Class
4. Encapsulation
5. Data Hiding
6. Private Data Members
7. Linked List Initialization

Key Learning Points:
- first stores the reference of the first node.
- last stores the reference of the last node.
- iCount maintains the total number of nodes.
- The constructor initializes an empty linked list.
- Private members provide data security through encapsulation.

===============================================================================
*/
// Program 07 : Creation of Singly Circular Linked List Class

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
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }
}

class SinglyCL7
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

===============================================================================
Memory Representation:
===============================================================================

              SinglyCL Object (sobj)

        +---------------------------------+
        | first  = NULL                   |
        | last   = NULL                   |
        | iCount = 0                      |
        +---------------------------------+

===============================================================================
Explanation:
===============================================================================

The program defines a self-referential node class where each node contains
an integer data field and a reference to the next node.

A separate SinglyCL class is created to represent the Singly Circular Linked
List.

The class contains three private data members:

• first  – Stores the reference of the first node.
• last   – Stores the reference of the last node.
• iCount – Stores the total number of nodes present in the list.

The constructor initializes all members as:

first = null
last = null
iCount = 0

This indicates that the linked list is initially empty and ready for future
operations such as insertion, deletion, traversal, and counting.

The main() method simply creates an object of the SinglyCL class.

===============================================================================
Program Flow:
===============================================================================

Start Program
      │
      ▼
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
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node class.
2. Created the SinglyCL class.
3. Declared first, last and iCount as private members.
4. Initialized all members using the constructor.
5. Created an object of the SinglyCL class.

===============================================================================
Time Complexity:
===============================================================================

Object Creation  : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the basic structure of a Singly Circular Linked
List class in Java. Initializing the first and last references to NULL and
the node counter to zero ensures that the linked list starts in a valid
empty state, forming the foundation for implementing all subsequent linked
list operations.

===============================================================================
*/
