/*
===============================================================================
Program Name    : Searching - Accept and Display Array Elements
Program Number  : 002
File Name       : Searching_02.cpp

Description     : This program demonstrates the Accept() and Display()
                  functions of the Searching class. The Accept() function
                  accepts elements from the user and stores them in a
                  dynamically allocated array. The Display() function
                  displays all elements stored in the array.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Parameterized Constructor
3. Destructor
4. Dynamic Memory Allocation
5. Array
6. Member Functions
7. User Input and Output

Key Learning Points:
- Accept array elements from the user.
- Store elements in a dynamic array.
- Display array elements.
- Understand member functions.
- Manage dynamically allocated memory.

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

Searching::Searching(int iNo)
{
    iSize = iNo;
    Arr = new int[iSize];
}

Searching::~Searching()
{
    delete []Arr;
}

void Searching::Accept()
{
    int i = 0;

    cout<<"Enter the elements\n";

    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

void Searching::Display()
{
    int i = 0;

    cout<<"Elements of the Array are :\n";

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

int main()
{
    Searching sobj(5);

    sobj.Accept();
    sobj.Display();

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Enter the elements
10
20
30
40
50

Elements of the Array are :
10
20
30
40
50

===============================================================================
Memory Representation:
===============================================================================

Searching sobj(5)

        │
        ▼
   +-------------+
   |   iSize = 5 |
   | Arr --------|----------------┐
   +-------------+                │
                                  ▼
                         +----+----+----+----+----+
                         | 10 | 20 | 30 | 40 | 50 |
                         +----+----+----+----+----+
                           0    1    2    3    4

  ===============================================================================
Algorithm:
===============================================================================

1. Create an object of the Searching class.
2. Allocate an integer array dynamically.
3. Call Accept().
4. Accept elements from the user.
5. Store the elements in the array.
6. Call Display().
7. Display all array elements.
8. Destructor releases the allocated memory.

===============================================================================
Program Flow:
===============================================================================

              Start
                │
                ▼
       Create Searching Object
                │
                ▼
       Allocate Dynamic Array
                │
                ▼
          Call Accept()
                │
                ▼
        Accept Array Elements
                │
                ▼
         Call Display()
                │
                ▼
        Display Array Elements
                │
                ▼
        Destructor Called
                │
                ▼
          Free Array Memory
                │
                ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

Accept  : O(n)
Display : O(n)

Space Complexity : O(n)

where,

n = Size of the array

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates how to accept and display elements of a
dynamically allocated array using member functions of a Searching
class. It also demonstrates the use of a parameterized constructor
and destructor for memory management.

===============================================================================
*/
