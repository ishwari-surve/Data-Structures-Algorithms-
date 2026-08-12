/*
===============================================================================
Program Name    : Searching - Accept and Display
Program Number  : 02
File Name       : Searching_02.c
Description     : This program accepts elements into a dynamically allocated
                  array and displays the elements using a structure pointer.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Pointer to Structure
3. Typedef
4. Dynamic Memory Allocation
5. malloc()
6. free()
7. Array Traversal

Key Learning Points:
- Accept elements into a dynamically allocated array.
- Display elements stored in the array.
- Access structure members using the pointer operator.
- Understand dynamic array traversal.

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

void Accept(PSEARCHING first)
{
    int i = 0;

    printf("Enter the Elements:\n");

    for(i = 0; i < first->iSize; i++)
    {
        scanf("%d",&first->Arr[i]);
    }
}

void Display(PSEARCHING first)
{
    int i = 0;

    printf("Elements of the Array are:\n");

    for(i = 0; i < first->iSize; i++)
    {
        printf("%d\n",first->Arr[i]);
    }
}

int main()
{
    SEARCHING sobj;

    sobj.iSize = 5;

    sobj.Arr = (int *)malloc(sizeof(int) * sobj.iSize);

    Accept(&sobj);
    Display(&sobj);

    free(sobj.Arr);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Enter the Elements:
10
20
30
40
50

Elements of the Array are:
10
20
30
40
50

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

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the Searching structure.
3. Create a SEARCHING object.
4. Set the array size to 5.
5. Allocate memory dynamically for 5 integer elements.
6. Call Accept() to accept array elements from the user.
7. Traverse the array and store each element.
8. Call Display() to display the array elements.
9. Traverse the array and print each element.
10. Release the allocated memory using free().
11. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
   Create SEARCHING Object
          |
          v
      Set iSize = 5
          |
          v
   Allocate Dynamic Memory
          |
          v
        Accept()
          |
          v
   Store Array Elements
          |
          v
        Display()
          |
          v
   Display Array Elements
          |
          v
        free()
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Accept()    : O(n)
Display()   : O(n)

Where n is the number of elements in the array.

Space Complexity : O(n)

Where n is the size of the dynamically allocated array.

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates how to accept and display elements using a
dynamically allocated array in C. It uses a structure, structure pointer,
typedef, malloc(), free(), and array traversal. This program forms the
foundation for implementing searching operations in the subsequent programs.

===============================================================================
*/
