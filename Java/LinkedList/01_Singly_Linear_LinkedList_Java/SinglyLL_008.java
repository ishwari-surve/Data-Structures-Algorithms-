/*
===============================================================================

Program Name : Singly Linear Linked List - Linked List Class Initialization
Program Number  : 008
Description     : This program demonstrates how to create a
                  separate SinglyLL class to represent a
                  Singly Linear Linked List in Java.

                  The constructor initializes the first
                  reference to null and the node count
                  (iCount) to zero, preparing an empty
                  linked list for future operations.
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:

1. Classes and Objects
2. Self-Referential Class
3. Constructors
4. Encapsulation
5. Object-Oriented Programming
6. Instance Variables
7. Object References
8. this Keyword

Key Learning Points:

- The SinglyLL class represents the linked list.
- first stores the reference to the first node.
- iCount stores the total number of nodes.
- Constructors initialize linked list objects automatically.
- Encapsulation combines data and operations into a single class.
- Every new linked list object starts in an empty state.

===============================================================================
*/
class node
{
    public int data;           // Data value stored in node
    public node next;          // Reference to next node

    // Parameterized Constructor
    node(int no)
    {
        this.data = no;        // Initialize data with parameter
        this.next = null;      // Initialize next to null
    }
}

class SinglyLL
{
    public node first;         // Reference to first node (head)
    public int iCount;         // Counter for number of nodes

    // Constructor for SinglyLL class
    public SinglyLL()
    {
        System.out.println("Inside Constructor");
        this.first = null;     // No nodes initially
        this.iCount = 0;       // Counter starts at 0
    }
}

class SinglyLL008
{
    public static void main(String A[])
    {
        // Create SinglyLL object - constructor runs automatically
        SinglyLL sobj = new SinglyLL();
    }
}

/*
================================================================================
Expected Output:
================================================================================
Inside Constructor

================================================================================
Memory Diagram:
================================================================================

Stack:
┌──────────────────────────┐
│ sobj (reference variable)│
│ Points to SinglyLL object│
└──────────────────────────┘
         │
         ▼
Heap:
┌─────────────────────────┐
│ SinglyLL Object:        │
│ first: null             │
│ iCount: 0               │
└─────────────────────────┘

Constructor Execution:
new SinglyLL() → Allocate memory on heap
                → Constructor SinglyLL() runs
                → Print "Inside Constructor"
                → this.first = null
                → this.iCount = 0
                → Return reference to sobj

================================================================================
Pointer/Logic Explanation:
================================================================================

Linked List Class

SinglyLL

Instance Variables

• first
  - Stores the reference of the first node.
  - Initially null.

• iCount
  - Stores the total number of nodes.
  - Initially 0.

Constructor

public SinglyLL()

• Executes automatically when a SinglyLL object is created.
• Initializes first to null.
• Initializes iCount to 0.

===============================================================================
Operations Performed
===============================================================================
1. Defined a self-referential node class.
2. Created a parameterized constructor for node initialization.
3. Created the SinglyLL class.
4. Declared first as the head reference.
5. Declared iCount to store the node count.
6. Initialized first to null.
7. Initialized iCount to 0.
8. Created a SinglyLL object.
9. Executed the constructor automatically.

================================================================================
Time Complexity:
================================================================================
Constructor Execution  : O(1) - Simple initialization
Object Creation        : O(1) - Allocate memory
Variable Access        : O(1) - Direct field access
Space Complexity       : O(1) - Single SinglyLL object

================================================================================
Conclusion:
================================================================================

This program demonstrates how a Singly Linear Linked List
can be represented using a separate class in Java. The
constructor initializes the linked list by setting the
first reference to null and the node count to zero.

This object-oriented design forms the foundation for
implementing linked list operations such as insertion,
deletion, traversal, and searching in the upcoming programs.

================================================================================
*/
