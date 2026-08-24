/*
===============================================================================
Program Name    : Searching - Accept Elements
Program Number  : 02
File Name       : Searching_02.java 

Description     : This program accepts integer elements from the user and
                  stores them in an array using the Searching class.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Constructor
4. Array
5. Scanner Class
6. User Input
7. Accept Operation
8. Private Data Members

Key Learning Points:
- Understand how to accept elements into an array.
- Learn how to use the Scanner class for user input.
- Understand array traversal using a for loop.
- Learn how to access private data members through a class method.
- Understand the use of a constructor for array initialization.

===============================================================================
*/

import java.util.*;

class Searching
{
    private int Arr[];
    private int iSize;

    public Searching(int iNo)
    {
        iSize = iNo;
        Arr = new int[iSize];
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Accept
    // Description   : Accept elements from user
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);

        int i = 0;

        System.out.println("Enter the Elements : ");

        for(i = 0; i < iSize; i++)
        {
            Arr[i] = sobj.nextInt();
        }
    }
}

class Searching_02
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();

        System.out.println("Elements accepted successfully");
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Enter the Elements :
11
21
51
101
151
Elements accepted successfully

===============================================================================
Memory Representation:
===============================================================================

Searching Object

       sobj
        |
        v
+----------------------+
| Searching Object     |
+----------------------+
| iSize = 5            |
| Arr ----------------------+
+----------------------+     |
                             v
                       +----+----+----+-----+-----+
                       | 11 | 21 | 51 | 101 | 151 |
                       +----+----+----+-----+-----+
                         0    1    2     3     4

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create the Searching class.
3. Declare an integer array Arr and integer iSize.
4. Create a constructor to initialize the array size.
5. Create the Accept() function.
6. Create a Scanner object to accept input from the user.
7. Traverse the array using a for loop.
8. Store each entered element into the array.
9. Display "Elements accepted successfully".
10. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
   Create Searching Object
          |
          v
      Call Accept()
          |
          v
   Create Scanner Object
          |
          v
     Accept Elements
          |
          v
      Store in Array
          |
          v
    Display Success Message
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Accept() : O(n)

Where n is the number of elements in the array.

===============================================================================
Space Complexity:
===============================================================================

O(n) for storing n integer elements in the array.

===============================================================================
Conclusion:
===============================================================================

Program 02 demonstrates how to accept integer elements from the user and
store them in an array using a Searching class in Java. It also demonstrates
the use of a constructor, Scanner class and array traversal.

===============================================================================
*/
