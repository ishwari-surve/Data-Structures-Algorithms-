/*
===============================================================================
Program Name    : Searching Using Dynamic Array - Basic Class Structure
Program Number  : 001
File Name       : Searching_01.cpp

Description     : This program demonstrates the basic structure of a
                  Searching class using a dynamically allocated array.
                  The constructor creates the array dynamically and the
                  destructor releases the allocated memory.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Constructor
3. Destructor
4. Dynamic Memory Allocation
5. Dynamic Array
6. Encapsulation

Key Learning Points:
- Create a class for searching operations.
- Allocate an array dynamically using new.
- Initialize array size through a constructor.
- Release dynamically allocated memory using delete[].

===============================================================================
*/
#include<iostream>
using namespace std;

class Searching
{
    private:
        int *Arr;
        int iSize;

    public:
        Searching(int iNo);
        ~Searching();

        void Accept();
        void Display();
};

Searching :: Searching(int iNo)
{
    iSize = iNo;
    Arr = new int[iSize];
}

Searching :: ~Searching()
{
    delete []Arr;
}

void Searching :: Accept()
{
}

void Searching :: Display()
{
}

int main()
{
    Searching sobj(5);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

No output is displayed.

The program creates an object of Searching with an array size of 5
and releases the allocated memory when the object is destroyed.

===============================================================================
Memory Representation:
===============================================================================

Searching sobj(5);

        │
        ▼
   Searching Object
   ┌─────────────────┐
   │ iSize = 5       │
   │ Arr ────────────────┐
   └─────────────────┘   │
                         ▼
                  ┌────┬────┬────┬────┬────┐
                  │    │    │    │    │    │
                  │  0 │  1 │  2 │  3 │  4 │
                  └────┴────┴────┴────┴────┘
                     Dynamic Integer Array

===============================================================================
Algorithm:
===============================================================================

1. Define a Searching class.
2. Declare a pointer Arr and an integer iSize.
3. Create a constructor that accepts the array size.
4. Allocate an integer array dynamically using new.
5. Create Accept() and Display() functions.
6. Create a destructor to release the allocated array using delete[].
7. Create an object with array size 5.
8. Program terminates and destructor releases the memory.

===============================================================================
Program Flow:
===============================================================================

             Start
                │
                ▼
       Create Searching Object
                │
                ▼
        Constructor Called
                │
                ▼
       Set iSize = 5
                │
                ▼
     Allocate Dynamic Array
                │
                ▼
          Program Ends
                │
                ▼
        Destructor Called
                │
                ▼
       Release Array Memory
                │
                ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

Constructor : O(n) for dynamic allocation
Destructor  : O(n) for releasing the array

Space Complexity : O(n)

where,

n = Size of the array

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates the basic class structure required for
implementing searching operations in C++. It uses a constructor to
dynamically allocate an integer array and a destructor to properly
release the allocated memory.

===============================================================================
*/
