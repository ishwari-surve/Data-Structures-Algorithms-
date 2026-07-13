Doubly Linear Linked List in C
Overview

This folder contains a complete implementation of the Doubly Linear Linked List using the C Programming Language. The programs are developed from scratch to demonstrate how doubly linked lists work internally using dynamic memory allocation, pointer manipulation, and bidirectional node linking.

Unlike a Singly Linked List, where each node stores only the address of the next node, a Doubly Linked List stores the addresses of both the previous and the next nodes. This allows traversal in both forward and backward directions and makes insertion and deletion operations more flexible.

The implementation follows a structured learning approach, beginning with node creation and progressing through insertion, deletion, traversal, searching, counting, and various utility operations.

What is a Doubly Linear Linked List?

A Doubly Linear Linked List (DLL) is a dynamic linear data structure in which every node contains three parts:

Previous Pointer – Stores the address of the previous node.
Data – Stores the actual data.
Next Pointer – Stores the address of the next node.

The first node's previous pointer is always NULL, and the last node's next pointer is also NULL.

Unlike arrays, memory is allocated dynamically, so nodes can be inserted or deleted at runtime without shifting elements.

Visualization
NULL
  ↑
[NULL|11|•] ⇄ [•|21|•] ⇄ [•|51|•] ⇄ [•|101|NULL]
                                             ↓
                                            NULL

Head ---------------------------------------> First Node

or simply

NULL <- |11| <-> |21| <-> |51| <-> |101| -> NULL
Node Structure
#pragma pack(1)

struct node
{
    struct node *prev;    // Address of Previous Node
    int data;             // Stores Data
    struct node *next;    // Address of Next Node
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
Why #pragma pack(1)?

Without structure packing, the compiler inserts padding bytes for alignment.

Without #pragma pack(1) → 24 bytes per node (depending on compiler/architecture)
With #pragma pack(1) → 20 bytes per node
Saves memory by removing unnecessary padding bytes.
Memory Layout
Previous Pointer    Data    Next Pointer
+--------------+---------+--------------+
|     8 B      |   4 B   |     8 B      |
+--------------+---------+--------------+

Total = 20 Bytes (Packed)
Programs Included

The programs in this folder are arranged in a logical sequence to provide step-by-step learning of Doubly Linked Lists.

Program Progression
Phase	Program Files	Topics Covered
Foundation	DoublyLL001-010	Node Structure, Memory Layout, Pointer Linking
Basic Operations	DoublyLL011-020	Display, Count, InsertFirst, InsertLast
Intermediate	DoublyLL021-030	DeleteFirst, DeleteLast, InsertAtPos
Advanced	DoublyLL031+	DeleteAtPos, Search, Utility Functions

Note: More programs will be added as additional concepts are covered.

Topics Covered
Basic Concepts
Doubly Node Structure
Self-Referential Structure
Previous Pointer
Next Pointer
Head Pointer
Memory Layout
Structure Packing (#pragma pack(1))
Dynamic Memory Allocation (malloc())
Node Creation
Node Initialization
Bidirectional Linking
Pointer Traversal
Pointer Types
PNODE   -> Pointer to Node

PPNODE  -> Pointer to Pointer to Node
Traversal Operations
Forward Traversal
Reverse Traversal
Display Linked List
Count Nodes
Insertion Operations
Insert First — O(1)
Insert Last — O(n)
Insert At Position — O(n)
Deletion Operations
Delete First — O(1)
Delete Last — O(n)
Delete At Position — O(n)
Utility Operations
Display List
Count Nodes
Search Element
Traverse Forward
Traverse Backward
Concepts Covered
Structures
Self-Referential Structures
Dynamic Memory Allocation
Pointer Manipulation
Previous Pointer Handling
Next Pointer Handling
Bidirectional Traversal
Memory Management
Modular Programming
Time Complexity Analysis
Space Complexity Analysis
Advantages
Traversal is possible in both forward and backward directions.
Deletion of a node is easier because the previous node is directly accessible.
Easier insertion before or after any given node.
Efficient implementation of browser navigation and undo/redo functionality.
Better flexibility compared to Singly Linked Lists.
Disadvantages
Requires extra memory because every node stores an additional previous pointer.
Pointer manipulation becomes slightly more complex.
More memory allocation compared to Singly Linked Lists.
Time Complexity
Operation	Complexity
Display	O(n)
Count	O(n)
Search	O(n)
Insert First	O(1)
Insert Last	O(n)
Insert At Position	O(n)
Delete First	O(1)
Delete Last	O(n)
Delete At Position	O(n)
Applications
Browser Back and Forward Navigation
Undo and Redo Operations
Music Playlist Navigation
Image Gallery Viewers
Text Editors
LRU Cache
File Explorer Navigation
Memory Management Systems
Navigation Systems
Operating System Process Management
Technologies Used
Language: C Programming Language
Compiler: GCC Compiler
IDE: Visual Studio Code
Version Control: Git & GitHub
Learning Outcomes

After completing the programs in this folder, you will be able to:

Understand the internal working of a Doubly Linked List.
Explain the difference between Singly and Doubly Linked Lists.
Implement insertion and deletion operations efficiently.
Perform forward and backward traversal.
Manage previous and next pointers correctly.
Analyze time and space complexity.
Build a strong foundation for Circular Linked Lists and advanced Data Structures.
Doubly Linked List vs Singly Linked List
Singly Linked List	Doubly Linked List
One pointer	Two pointers
Forward traversal only	Forward and backward traversal
Less memory	More memory
Simpler implementation	Slightly more complex
Faster insertion at beginning	Easier insertion/deletion around any node
Mastery Checklist
✅ Understand doubly node structure
✅ Know why two pointers are required
✅ Understand previous and next pointer linking
✅ Draw accurate memory diagrams
✅ Understand PNODE and PPNODE
✅ Implement InsertFirst()
✅ Implement InsertLast()
✅ Implement InsertAtPos()
✅ Implement DeleteFirst()
✅ Implement DeleteLast()
✅ Implement DeleteAtPos()
✅ Perform forward traversal
✅ Understand backward traversal
✅ Know time complexity of every operation
✅ Explain Doubly Linked List confidently in technical interviews
Author

Ishwari Vijaykumar Surve
