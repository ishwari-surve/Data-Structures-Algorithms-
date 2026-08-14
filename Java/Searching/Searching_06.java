/*
===============================================================================
Program Name    : Searching - Linear Search and Bi-Directional Search
Program Number  : 06
File Name       : Searching_06.java

Description     : This program accepts elements from the user and searches
                  for a particular element using both Linear Search and
                  Bi-Directional Search techniques.

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
10. Bi-Directional Search
11. Boolean Return Value
12. Array Traversal
13. Searching Techniques

Key Learning Points:
- Understand Linear Search and Bi-Directional Search.
- Learn how to search an element using two different techniques.
- Compare sequential searching with two-end searching.
- Understand the use of start and end indexes.
- Learn how to return a boolean result from searching functions.
- Analyze the time complexity of different searching techniques.

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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : BiDirectionalSearch
    // Description   : Search element from both ends
    //
    ///////////////////////////////////////////////////////////////////////////

    public boolean BiDirectionalSearch(int iNo)
    {
        int iStart = 0;
        int iEnd = 0;
        boolean bFlag = false;

        iStart = 0;
        iEnd = iSize - 1;

        while(iStart <= iEnd)
        {
            if(Arr[iStart] == iNo || Arr[iEnd] == iNo)
            {
                bFlag = true;
                break;
            }

            iStart++;
            iEnd--;
        }

        return bFlag;
    }
}

class Searching_06
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();

        ///////////////////////////////////////////////////////////////////////
        // Linear Search
        ///////////////////////////////////////////////////////////////////////

        if(sobj.LinearSearch(30) == true)
        {
            System.out.println("\nLinear Search : Element is Present");
        }
        else
        {
            System.out.println("\nLinear Search : There is no such element");
        }

        ///////////////////////////////////////////////////////////////////////
        // Bi-Directional Search
        ///////////////////////////////////////////////////////////////////////

        if(sobj.BiDirectionalSearch(30) == true)
        {
            System.out.println("Bi-Directional Search : Element is Present");
        }
        else
        {
            System.out.println("Bi-Directional Search : There is no such element");
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
51
30
101

Elements of the Array are :
11
21
51
30
101

Linear Search : Element is Present
Bi-Directional Search : Element is Present

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
                       | 11 | 21 | 51 | 30 | 101 |
                       +----+----+----+----+-----+
                         0    1    2    3     4
                                  ^
                                  |
                            Search Element
                                  30

Linear Search:
11 -> 21 -> 51 -> 30
                  ^
                Found

Bi-Directional Search:
11 <-> 101
21 <-> 30
       ^
     Found

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Searching object with size 5.
3. Call Accept() to accept array
