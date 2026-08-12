/*
===============================================================================
Program Name    : Searching Menu - Driven Application
Program Number  : 06
File Name       : Searching_06.c
Description     : This program implements a menu-driven Searching Application
                  using Linear Search and Bi-Directional Search on a
                  dynamically allocated array.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Pointer to Structure
3. Typedef
4. Dynamic Memory Allocation
5. Linear Search
6. Bi-Directional Search
7. Menu-Driven Programming
8. Switch Case

Key Learning Points:
- Understand menu-driven searching operations.
- Implement Linear Search on an array.
- Implement Bi-Directional Search on an array.
- Perform searching based on user choice.
- Manage dynamically allocated memory.
- Analyze time and space complexity.

===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct Searching
{
    int *Arr;
    int iSize;
};

typedef struct Searching SEARCHING;
typedef struct Searching *PSEARCHING;

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Accept
//
///////////////////////////////////////////////////////////////////////////////

void Accept(PSEARCHING first)
{
    int i = 0;

    printf("Enter the Elements:\n");

    for(i = 0; i < first->iSize; i++)
    {
        scanf("%d",&first->Arr[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
//
///////////////////////////////////////////////////////////////////////////////

void Display(PSEARCHING first)
{
    int i = 0;

    printf("\nElements of the Array are:\n");

    for(i = 0; i < first->iSize; i++)
    {
        printf("%d\n",first->Arr[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinearSearch
//
///////////////////////////////////////////////////////////////////////////////

int LinearSearch(PSEARCHING first,int iNo)
{
    int i = 0;

    for(i = 0; i < first->iSize; i++)
    {
        if(first->Arr[i] == iNo)
        {
            return 1;
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : BiDirectionalSearch
//
///////////////////////////////////////////////////////////////////////////////

int BiDirectionalSearch(PSEARCHING first,int iNo)
{
    int iStart = 0;
    int iEnd = first->iSize - 1;

    while(iStart <= iEnd)
    {
        if((first->Arr[iStart] == iNo) ||
           (first->Arr[iEnd] == iNo))
        {
            return 1;
        }

        iStart++;
        iEnd--;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    SEARCHING sobj;

    int iChoice = 0;
    int iRet = 0;
    int iValue = 0;

    printf("Enter the Number of Elements : ");
    scanf("%d",&sobj.iSize);

    sobj.Arr = (int *)malloc(sizeof(int) * sobj.iSize);

    while(1)
    {
        printf("\n-------------------------------------------------\n");
        printf("------------------ SEARCHING --------------------\n");
        printf("-------------------------------------------------\n");
        printf("1. Accept Elements\n");
        printf("2. Display Elements\n");
        printf("3. Linear Search\n");
        printf("4. Bi-Directional Search\n");
        printf("5. Exit\n");
        printf("-------------------------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:

                Accept(&sobj);
                break;

            case 2:

                Display(&sobj);
                break;

            case 3:

                printf("Enter Element to Search : ");
                scanf("%d",&iValue);

                iRet = LinearSearch(&sobj,iValue);

                if(iRet == 1)
                {
                    printf("Element is Present\n");
                }
                else
                {
                    printf("Element is Absent\n");
                }
                break;

            case 4:

                printf("Enter Element to Search : ");
                scanf("%d",&iValue);

                iRet = BiDirectionalSearch(&sobj,iValue);

                if(iRet == 1)
                {
                    printf("Element is Present\n");
                }
                else
                {
                    printf("Element is Absent\n");
                }
                break;

            case 5:

                free(sobj.Arr);

                printf("Thank you for using Searching Application\n");
                return 0;

            default:

                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Enter the Number of Elements : 5

-------------------------------------------------
------------------ SEARCHING --------------------
-------------------------------------------------
1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit
-------------------------------------------------
Enter your choice : 1

Enter the Elements:
10
20
30
40
50

-------------------------------------------------
------------------ SEARCHING --------------------
-------------------------------------------------
1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit
-------------------------------------------------
Enter your choice : 2

Elements of the Array are:
10
20
30
40
50

Enter your choice : 3
Enter Element to Search : 30
Element is Present

Enter your choice : 4
Enter Element to Search : 40
Element is Present

Enter your choice : 5
Thank you for using Searching Application

===============================================================================
Memory Representation:
===============================================================================

              sobj
        +------------------+
        | Arr ------------ |--------+
        | iSize = 5        |        |
        +------------------+        |
                                    v
                         +------+------+------+------+------+
                         |  10  |  20  |  30  |  40  |  50  |
                         +------+------+------+------+------+
                           Arr[0] Arr[1] Arr[2] Arr[3] Arr[4]

The Arr pointer stores the address of the dynamically allocated array.

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the Searching structure.
3. Create a SEARCHING object.
4. Accept the number of elements from the user.
5. Allocate memory dynamically for the array.
6. Display the Searching menu.
7. Accept the user's choice.
8. If the choice is 1, accept array elements using Accept().
9. If the choice is 2, display array elements using Display().
10. If the choice is 3, accept an element and perform Linear Search.
11. Display whether the element is present or absent.
12. If the choice is 4, accept an element and perform Bi-Directional Search.
13. Display whether the element is present or absent.
14. If the choice is 5, release allocated memory and terminate the program.
15. For an invalid choice, display an error message.
16. Repeat the menu until the user selects Exit.
17. Stop the program.

===============================================================================
Program Flow:
===============================================================================

              Start
                |
                v
       Accept Array Size
                |
                v
       Allocate Array Memory
                |
                v
          Display Menu
                |
                v
        Accept User Choice
                |
        +-------+-------+-------+-------+
        |       |       |       |       |
        v       v       v       v       v
      Accept  Display Linear  Bi-Dir   Exit
      Array   Array   Search  Search    |
        |       |       |       |       v
        |       |       |       |     free()
        |       |       |       |       |
        +-------+-------+-------+-------+
                |
                v
          Display Menu Again
                |
                v
               Stop

===============================================================================
Time Complexity:
===============================================================================

Accept()              : O(n)
Display()             : O(n)

Linear Search:
Best Case             : O(1)
Average Case          : O(n)
Worst Case            : O(n)

Bi-Directional Search:
Best Case             : O(1)
Average Case          : O(n)
Worst Case            : O(n)

Menu Operations       : Depends on the selected operation

Space Complexity      : O(n)

Where n is the number of elements in the array.

===============================================================================
Conclusion:
===============================================================================

Program 006 implements a menu-driven Searching Application in C. The
program allows the user to accept and display array elements and perform
Linear Search or Bi-Directional Search according to the selected menu
option. Dynamic memory allocation is used for storing the array elements,
and the allocated memory is released before program termination.

===============================================================================
*/
