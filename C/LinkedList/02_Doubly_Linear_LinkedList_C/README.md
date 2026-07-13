# Doubly Linear Linked List in C 
## Overview 

This folder contains a complete implementation of the **Doubly Linear Linked List(DLL)** using the C programming language. The programs are developed from scratch to demonstrate the internal working of linked lists through dynamic memory allocation and pointer manipulation.

The implementation follows a structured approach, beginning with node creation and progressing to insertion, deletion, traversal, searching, and other utility operations. It is intended to strengthen the understanding of fundamental Data Structures and improve programming skills in C.

## What is a Doubly Linked List?

A Doubly Linked List is a dynamic linear data structure composed of nodes. Each node contains:

1.Previous Pointer – Stores the address of the previous node
2.Data – Stores the integer value
3.Next Pointer – Stores the address of the next node

The first node's previous pointer is NULL, and the last node's next pointer is NULL, indicating the boundaries of the list.

Unlike a Singly Linked List, a Doubly Linked List supports traversal in both forward and backward directions.

-----

## Visualization
NULL <- |11| <-> |21| <-> |51| <-> |101| -> NULL

## Node Structure
#pragma pack(1)

struct node
{
    int data;             // 4 bytes - stores value
    struct node *prev;    // 8 bytes - points to previous node
    struct node *next;    // 8 bytes - points to next node
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

### Why #pragma pack(1)?
Without pragma: 24 bytes per node (padding added by compiler)
With pragma: 20 bytes per node (padding removed)
Helps reduce memory wastage

-----

## Memory Layout

```text
HEAD
 |
 v

NULL <--> +------+------+------+ <--> +------+------+------+ <--> +------+------+------+ <--> NULL
           |Prev | 11  |Next |      |Prev | 21  |Next |      |Prev | 51  |Next |
           +------+------+------+      +------+------+------+      +------+------+------+
```

-----

## Programs Included

The programs in this folder are arranged in a logical sequence to provide step-by-step learning of Doubly Linked Lists.

### Program Progression
| Phase      | Program Files   | Key Concepts                                      |
| ---------- | --------------- | ------------------------------------------------- |
| Foundation | DoublyLL001-010 | Node Structure, Pointers, Memory Layout           |
| Functions  | DoublyLL011-020 | Display, Count, Traversal                         |
| Advanced   | DoublyLL021+    | Insertion, Deletion, Searching, Utility Functions |

Note: Programs continue to be added as topics expand.

-----

## Topics Covered
### Basic Concepts
-Node Structure
-Self-Referential Structure
-Memory Layout
-Structure Packing using #pragma pack(1)
-Dynamic Memory Allocation with malloc()
-Node Creation
-Node Initialization
-Previous Pointer Handling
-Next Pointer Handling
-Pointer Traversal
-Pointer Types (PNODE, PPNODE)

-----

###  Traversal Operations
-Forward Traversal
-Backward Traversal
-Display Linked List
-Count Nodes

-----

### Insertion Operations
-Insert First - O(1)
-Insert Last - O(n)
-Insert At Position - O(n)

-----

### Deletion Operations
-Delete First - O(1)
-Delete Last - O(n)
-Delete At Position - O(n)

-----

### Utility Operations
-Display Linked List - O(n)
-Count Nodes - O(n)
-Search Element - O(n)
-Forward Traversal - O(n)
-Reverse Traversal - O(n)

-----

## Concepts Covered
-Structures
-Self-Referential Structures
-Pointers
-Pointer Manipulation
-Dynamic Memory Allocation
-Memory Management
-Bidirectional Linking
-Forward Traversal
-Backward Traversal
-Modular Programming
-Time and Space Complexity Analysis

-----

## Advantages
-Supports traversal in both directions
-Easier insertion and deletion operations
-Previous node is directly accessible
-Better flexibility than Singly Linked List
-Useful for navigation-based applications

-----

## Disadvantages
-Requires extra memory for the previous pointer
-More pointer manipulation
-Slightly more complex implementation

-----

## Time Complexity
| Operation          | Complexity |
| ------------------ | ---------- |
| Display            | O(n)       |
| Count              | O(n)       |
| Search             | O(n)       |
| Insert First       | O(1)       |
| Insert Last        | O(n)       |
| Insert At Position | O(n)       |
| Delete First       | O(1)       |
| Delete Last        | O(n)       |
| Delete At Position | O(n)       |

-----

## Applications
- Browser Navigation (Back and Forward)
- Undo and Redo Operations
- Music Playlist Systems
- Image Viewers
- Text Editors
- LRU Cache
- Operating Systems
- File Explorers
- Navigation Systems

---

## Technologies Used

- **Language:** C Programming Language
- **Compiler:** GCC Compiler
- **IDE:** Visual Studio Code
- **Version Control:** Git & GitHub

---

## Learning Outcomes

After completing the programs in this folder, you will be able to:

- Understand the internal working of a Doubly Linked List.
- Implement insertion and deletion operations efficiently.
- Perform both forward and backward traversal.
- Master pointer manipulation and dynamic memory allocation.
- Analyze the time and space complexity of Doubly Linked List operations.
- Build a strong foundation for Circular Linked Lists and advanced Data Structures.

-----

## Doubly Linked List vs Singly Linked List
| Singly Linked List                   | Doubly Linked List                |
| ------------------------------------ | --------------------------------- |
| One Pointer                          | Two Pointers                      |
| Forward Traversal Only               | Forward and Backward Traversal    |
| Less Memory                          | More Memory                       |
| Simpler Implementation               | Slightly More Complex             |
| Cannot Access Previous Node Directly | Can Access Previous Node Directly |

-----

## Mastery Checklist

- [ ] Understand node structure and memory layout
- [ ] Know why `#pragma pack(1)` is used
- [ ] Can draw accurate memory diagrams
- [ ] Understand pointer types (`PNODE`, `PPNODE`)
- [ ] Can write `InsertFirst()` from scratch
- [ ] Can write `InsertLast()` from scratch
- [ ] Can write `InsertAtPos()` from scratch
- [ ] Can write `DeleteFirst()` from scratch
- [ ] Can write `DeleteLast()` from scratch
- [ ] Can write `DeleteAtPos()` from scratch
- [ ] Understand forward traversal
- [ ] Understand backward traversal
- [ ] Know the time complexity of each operation
- [ ] Ready for Doubly Circular Linked List
- [ ] Can explain Doubly Linked Lists in technical interviews
- [ ] Can solve related Doubly Linked List problems

-----

## Author

### Ishwari Vijaykumar Surve

