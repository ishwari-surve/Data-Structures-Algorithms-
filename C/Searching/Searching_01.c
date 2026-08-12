/*
===============================================================================
Program Name    : Searching - Basic Structure
Program Number  : 01
File Name       : Searching_01.c
Description     : This program demonstrates the basic structure of a Searching
                  application using an array. It defines the Searching
                  structure, dynamic memory allocation, and function prototypes
                  for searching operations.

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

Key Learning Points:
- Understand the basic structure of a Searching application.
- Learn how an array is dynamically allocated.
- Access structure members using a pointer.
- Understand memory allocation and deallocation.

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

void Accept(PSEARCHING ptr)
{

}

void Display(PSEARCHING ptr)
{

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

(No Output)

The program only allocates memory for the array, calls the Accept() and
Display() functions, and releases the allocated memory.

===============================================================================
Memory Representation:
===============================================================================

              sobj
        +------------------+
        | Arr ------------ |------> Dynamic Array
        | iSize = 5        |
        +------------------+

Dynamic Array:

        +------+------+------+------+------+
        |      |      |      |      |      |
        +------+------+------+------+------+
          Arr[0] Arr[1] Arr[2] Arr[3] Arr[4]

Memory is allocated using malloc() and released using free().

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the Searching structure.
3. Create a SEARCHING object.
4. Set the array size to 5.
5. Allocate dynamic memory for 5 integer elements.
6. Call the Accept() function.
7. Call the Display() function.
8. Release the allocated memory using free().
9. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
   Define Searching
      Structure
          |
          v
    Create sobj Object
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
      Display()
          |
          v
       free()
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Accept()    : O(1)   [No operation implemented]
Display()   : O(1)   [No operation implemented]
malloc()    : O(1)
free()      : O(1)

Space Complexity : O(n)

Where n is the size of the dynamically allocated array.

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic structure of a Searching application in C.
It demonstrates the use of structures, typedef, pointers, dynamic memory
allocation using malloc(), and memory deallocation using free(). The
Accept() and Display() functions are kept empty as preparation for the
subsequent Searching programs.

===============================================================================
*/
