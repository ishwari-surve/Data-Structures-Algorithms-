/*
===============================================================================
Program Name    : Binary Search Tree - Menu Driven
Program Number  : 11
File Name       : Tree_11.java

Description     : This program demonstrates a menu-driven Binary Search Tree
                  application using Java. It allows the user to insert nodes,
                  search nodes, perform tree traversals, count total nodes,
                  count leaf nodes and count parent nodes.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Binary Search Tree (BST)
6. Dynamic Memory Allocation
7. Insertion
8. Searching
9. Inorder Traversal
10. Preorder Traversal
11. Postorder Traversal
12. Recursion
13. Menu Driven Programming
14. Switch Case
15. Scanner Class
16. Node Counting
17. Leaf Node
18. Parent Node

Key Learning Points:
- Understand menu-driven programming using Java.
- Learn how to perform different Binary Search Tree operations.
- Use Scanner to accept input from the user.
- Use switch-case to select the required operation.
- Perform insertion and searching in a Binary Search Tree.
- Perform inorder, preorder and postorder traversals.
- Count total nodes, leaf nodes and parent nodes.
- Continue the application until the user selects Exit.

===============================================================================
*/

import java.util.*;

class node
{
    public int data;
    public node lchild;
    public node rchild;
}

class Tree
{
    private node first;

    public Tree()
    {
        first = null;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Insert
    // Description   : Insert element into Binary Search Tree
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Insert(int iNo)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = iNo;
        newn.lchild = null;
        newn.rchild = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(true)
            {
                if(iNo > temp.data)
                {
                    if(temp.rchild == null)
                    {
                        temp.rchild = newn;
                        break;
                    }

                    temp = temp.rchild;
                }
                else if(iNo < temp.data)
                {
                    if(temp.lchild == null)
                    {
                        temp.lchild = newn;
                        break;
                    }

                    temp = temp.lchild;
                }
                else
                {
                    System.out.println("Duplicate element not allowed");
                    break;
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Search
    // Description   : Search element in Binary Search Tree
    //
    ///////////////////////////////////////////////////////////////////////////

    public boolean Search(int iNo)
    {
        node temp = null;

        temp = first;

        while(temp != null)
        {
            if(iNo == temp.data)
            {
                return true;
            }
            else if(iNo > temp.data)
            {
                temp = temp.rchild;
            }
            else
            {
                temp = temp.lchild;
            }
        }

        return false;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Inorder
    // Description   : Left -> Data -> Right
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Inorder(node temp)
    {
        if(temp != null)
        {
            Inorder(temp.lchild);
            System.out.println(temp.data);
            Inorder(temp.rchild);
        }
    }

    public void Inorder()
    {
        Inorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Preorder
    // Description   : Data -> Left -> Right
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Preorder(node temp)
    {
        if(temp != null)
        {
            System.out.println(temp.data);
            Preorder(temp.lchild);
            Preorder(temp.rchild);
        }
    }

    public void Preorder()
    {
        Preorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Postorder
    // Description   : Left -> Right -> Data
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Postorder(node temp)
    {
        if(temp != null)
        {
            Postorder(temp.lchild);
            Postorder(temp.rchild);
            System.out.println(temp.data);
        }
    }

    public void Postorder()
    {
        Postorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Count total number of nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Count(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        return Count(temp.lchild) +
               Count(temp.rchild) + 1;
    }

    public int Count()
    {
        return Count(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountLeaf
    // Description   : Count leaf nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountLeaf(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        if(temp.lchild == null && temp.rchild == null)
        {
            return 1;
        }

        return CountLeaf(temp.lchild) +
               CountLeaf(temp.rchild);
    }

    public int CountLeaf()
    {
        return CountLeaf(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountParent
    // Description   : Count parent nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountParent(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        if(temp.lchild != null || temp.rchild != null)
        {
            return 1 +
                   CountParent(temp.lchild) +
                   CountParent(temp.rchild);
        }

        return 0;
    }

    public int CountParent()
    {
        return CountParent(first);
    }
}

class Tree_11
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        Tree tobj = new Tree();

        int iChoice = 0;
        int iNo = 0;

        while(true)
        {
            System.out.println("\n==============================================");
            System.out.println("       BINARY SEARCH TREE MENU");
            System.out.println("==============================================");

            System.out.println("1. Insert Node");
            System.out.println("2. Search Node");
            System.out.println("3. Inorder Traversal");
            System.out.println("4. Preorder Traversal");
            System.out.println("5. Postorder Traversal");
            System.out.println("6. Count Total Nodes");
            System.out.println("7. Count Leaf Nodes");
            System.out.println("8. Count Parent Nodes");
            System.out.println("0. Exit");

            System.out.println("==============================================");

            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:

                    System.out.print("Enter element : ");
                    iNo = sobj.nextInt();

                    tobj.Insert(iNo);

                    break;

                case 2:

                    System.out.print("Enter element to search : ");
                    iNo = sobj.nextInt();

                    if(tobj.Search(iNo) == true)
                    {
                        System.out.println("Element is Present");
                    }
                    else
                    {
                        System.out.println("Element is Not Present");
                    }

                    break;

                case 3:

                    System.out.println("\nInorder Traversal :");

                    tobj.Inorder();

                    break;

                case 4:

                    System.out.println("\nPreorder Traversal :");

                    tobj.Preorder();

                    break;

                case 5:

                    System.out.println("\nPostorder Traversal :");

                    tobj.Postorder();

                    break;

                case 6:

                    System.out.println("Total Nodes : " + tobj.Count());

                    break;

                case 7:

                    System.out.println("Leaf Nodes : " + tobj.CountLeaf());

                    break;

                case 8:

                    System.out.println("Parent Nodes : " + tobj.CountParent());

                    break;

                case 0:

                    System.out.println("\nThank you for using Binary Search Tree Application");

                    System.exit(0);

                    break;

                default:

                    System.out.println("Invalid Choice");

                    break;
            }
        }
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

==============================================
       BINARY SEARCH TREE MENU
==============================================
1. Insert Node
2. Search Node
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Count Total Nodes
7. Count Leaf Nodes
8. Count Parent Nodes
0. Exit
==============================================
Enter your choice : 1
Enter element : 11

Enter your choice : 1
Enter element : 5

Enter your choice : 1
Enter element : 17

Enter your choice : 1
Enter element : 4

Enter your choice : 1
Enter element : 7

Enter your choice : 1
Enter element : 15

Enter your choice : 1
Enter element : 21

Enter your choice : 3

Inorder Traversal :
4
5
7
11
15
17
21

Enter your choice : 4

Preorder Traversal :
11
5
4
7
17
15
21

Enter your choice : 5

Postorder Traversal :
4
7
5
15
21
17
11

Enter your choice : 6
Total Nodes : 7

Enter your choice : 7
Leaf Nodes : 4

Enter your choice : 8
Parent Nodes : 3

Enter your choice : 2
Enter element to search : 15
Element is Present

Enter your choice : 0

Thank you for using Binary Search Tree Application

===============================================================================
Memory Representation:
===============================================================================

                         11
                       /    \
                      5      17
                     / \    /  \
                    4   7  15  21

Total Nodes  = 7
Leaf Nodes   = 4
Parent Nodes = 3

===============================================================================
Menu Operations:
===============================================================================

1. Insert Node
   Inserts a new element into the Binary Search Tree.

2. Search Node
   Searches for a given element in the Binary Search Tree.

3. Inorder Traversal
   Visits nodes in the order:
   Left -> Data -> Right

4. Preorder Traversal
   Visits nodes in the order:
   Data -> Left -> Right

5. Postorder Traversal
   Visits nodes in the order:
   Left -> Right -> Data

6. Count Total Nodes
   Counts all nodes present in the Binary Search Tree.

7. Count Leaf Nodes
   Counts nodes which do not have any child.

8. Count Parent Nodes
   Counts nodes which have at least one child.

0. Exit
   Terminates the Binary Search Tree application.

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Import the Scanner class.
3. Define the node class with data, lchild and rchild.
4. Define the Tree class.
5. Initialize first to NULL using the constructor.
6. Create a Scanner object for user input.
7. Display the Binary Search Tree menu.
8. Accept the user's choice.
9. Use switch-case to perform the selected operation.
10. Insert a node when choice 1 is selected.
11. Search a node when choice 2 is selected.
12. Perform Inorder traversal when choice 3 is selected.
13. Perform Preorder traversal when choice 4 is selected.
14. Perform Postorder traversal when choice 5 is selected.
15. Count total nodes when choice 6 is selected.
16. Count leaf nodes when choice 7 is selected.
17. Count parent nodes when choice 8 is selected.
18. Exit the program when choice 0 is selected.
19. Display Invalid Choice for any other option.
20. Continue displaying the menu until the user selects Exit.
21. Stop the program.

===============================================================================
Program Flow:
===============================================================================

                         Start
                           |
                           v
                    Create Tree Object
                           |
                           v
                    Display Menu
                           |
                           v
                    Accept Choice
                           |
                           v
                      Switch Case
                           |
       +---------+---------+---------+---------+
       |         |         |         |         |
       v         v         v         v         v
    Insert    Search   Traversal   Counting   Exit
       |         |         |         |         |
       +---------+---------+---------+         |
                           |                   |
                           v                   v
                    Display Result           Stop
                           |
                           v
                    Display Menu Again

===============================================================================
Time Complexity:
===============================================================================

Insertion     : O(log n) Average
Insertion     : O(n) Worst Case
Searching     : O(log n) Average
Searching     : O(n) Worst Case
Inorder       : O(n)
Preorder      : O(n)
Postorder     : O(n)
Count         : O(n)
CountLeaf     : O(n)
CountParent   : O(n)

===============================================================================
Space Complexity:
===============================================================================

Tree Storage    : O(n)
Recursion Stack : O(h)

Where h is the height of the Binary Search Tree.

===============================================================================
Conclusion:
===============================================================================

Program 11 demonstrates a complete menu-driven Binary Search Tree
application using Java. The user can dynamically insert and search elements,
perform all three tree traversals, count total nodes, count leaf nodes and
count parent nodes. The program continues to execute until the user selects
the Exit option.

===============================================================================
*/
