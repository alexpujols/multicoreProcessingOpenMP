/*
                      ::::::
                    :+:  :+:
                   +:+   +:+
                  +#++:++#++:::::::
                 +#+     +#+     :+:
               ###       ###+:++#""
                         +#+
                         #+#
                         ###

__author__ = "Alex Pujols"
__copyright__ = "TBD"
__credits__ = ["Alex Pujols"]
__license__ = "GPL"
__version__ = "1.0"
__maintainer__ = "Alex Pujols"
__email__ = "alex.pujols@gmail.com"
__status__ = "Prototype"

: Title	:	multicoreProcessingOpenMP.cpp
: Date		:	3-24-2021
: Description  :	{TBD}
: Options	:	{TBD}
: Notes	:	{TBD}
*/

// Import modules declarations
#include <iostream>
#include <omp.h>

using namespace std;
// Function declarations

// Function to fill array
void fillArray(bool x[], const int y)
{
  for (int i = 0; i < y; i++)
  {
    if (i % 2 == 0)
      x[i] = 0;
    else
      x[i] = 1;
  }
}
// Function to print array
void printArray(bool x[], const int y)
{
  cout << "\nThe current contents of the array are {";
  for (int i = 0; i < y; i++)
  {
    cout << x[i];
  }
  cout << "}\n";
}
// Function for flipping the array
void flipArray(bool w[], bool x[], const int y)
{
  for (int i = 0; i < y; i++)
  {
    x[i] = !w[i];                                                               // flip the bit
  }
}
// Function for TBD

// Function for TBD

// Main code begins
int main()
{
  // Set global vaiables
  const int arraySize = 2500;                                                     // Simulating a bitmap with 'arraySize' amount of bytes (can be adjusted as needed)

  // Begin main code execution
  bool oldArray[arraySize];
  bool newArray[arraySize];

  // Entering portion of code that can be executed in parallel (Fork)
  #pragma omp parallel
  {
    int ID = omp_get_thread_num();
    fillArray(oldArray, arraySize);
    cout << "ProcessID = " << ID << endl;
    flipArray(oldArray, newArray, arraySize);
    cout << "ProcessID = " << ID << endl;
  }
  // Entering portion of code that should not be executed in parallel (Join)
  printArray(oldArray, arraySize);
  printArray(newArray, arraySize);

  return 0;
}
// Main code execution ends
