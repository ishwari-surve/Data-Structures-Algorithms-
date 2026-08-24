/*
===============================================================================
Program Name    : Searching - Linear Search
Program Number  : 04 
File Name       : Searching_04.java

Description     : This program accepts elements from the user, displays the
                  array elements and searches for a particular element using
                  the Linear Search technique.

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
8. Display Operation
9. Linear Search
10. Boolean Return Value
11. Array Traversal

Key Learning Points:
- Understand the basic concept of Linear Search.
- Learn how to search an element sequentially in an array.
- Understand comparison of each array element with the search value.
- Learn how to return true when an element is found.
- Learn how to return false when an element is not found.
- Understand the best and worst cases of Linear Search.

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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display elements of the array
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        int i = 0;

        System.out.println("\nElements of the Array are : ");

        for(i = 0; i < iSize; i++)
        {
            System.out.println(Arr[i]);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : LinearSearch
    // Description   : Search element sequentially
    //
    ///////////////////////////////////////////////////////////////////////////

    public boolean LinearSearch(int iNo)
    {
        boolean bFlag = false;

        int i = 0;

        for(i = 0; i < iSize; i++)
        {
            if(Arr[i] == iNo)
            {
                bFlag = true;
                break;
            }
        }

        return bFlag;
    }
}

class Searching_04
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();

        if(sobj.LinearSearch(30) == true)
        {
            System.out.println("\nElement is Present");
        }
        else
        {
            System.out.println("\nThere is no such element");
        }
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Enter the Elements :
11
21
30
51
101

Elements of the Array are :
11
21
30
51
101

Element is Present

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
                       +----+----+----+----+-----+
                       | 11 | 21 | 30 | 51 | 101 |
                       +----+----+----+----+-----+
                         0    1    2    3     4
                                  ^
                                  |
                            Search Element
                                  30

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Searching object with size 5.
3. Call Accept() to accept array elements.
4. Call Display() to display the array elements.
5. Call LinearSearch() with the element to be searched.
6. Set bFlag to false.
7. Traverse the array from index 0 to iSize - 1.
8. Compare each array element with the given element.
9. If the element is found:
   - Set bFlag to true.
   - Stop the searching process.
10. Return bFlag.
11. If bFlag is true, display "Element is Present".
12. Otherwise, display "There is no such element".
13. Stop the program.

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
    Accept Array Elements
          |
          v
     Call Display()
          |
          v
   Call LinearSearch()
          |
          v
    Compare Array Element
          |
          v
      Element Found?
        /       \
      Yes        No
       |          |
       v          v
    Return      Check Next
     true       Element
       |          |
       |          v
       |      End of Array?
       |        /     \
       |      Yes      No
       |       |        |
       |       v        |
       |     Return     |
       |     false <----+
       | 
       v
 Display Result
       |
       v
      Stop

===============================================================================
Time Complexity:
===============================================================================

Best Case    : O(1)
Average Case : O(n)
Worst Case   : O(n)

Where n is the number of elements in the array.

===============================================================================
Space Complexity:
===============================================================================

O(n) for storing n integer elements in the array.

Auxiliary Space : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 04 demonstrates Linear Search in Java. The program sequentially
compares each element of the array with the given search element and returns
true when the element is found. If the element is not present, it returns
false. This program helps understand sequential searching and array traversal.

===============================================================================
*/
