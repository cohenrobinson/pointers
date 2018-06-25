// an example of the use of pointers
// author: Cohen Robinson
// date: 25/06/18

#include <stdio.h>
#include <stdlib.h>

void somefunction(int *variable1);

int main()
{
  // We create an array
  int array1[9];
  // we store a number in the 5th element
  array1[4] = 53;
  // we print the 5th element
  printf("1. array1[4] = %d\n", array1[4]);    // think of this as calling the 4th element
                                            // after the first element
  // now we create a new variable
  // if we consider array1 to be a pointer for the first element of the array
  // then 4 elements along will be the 5th element
  int number1 = *(array1 + 4);            // this stores the pointer for the 4th element
                                          // as a variable

  printf("2. number1 = %d\n", number1);      // we then print the number to the terminal
                                          // to show that these two are equivalent
  // pointers can also be used to reference outside a local variable
  somefunction(&number1);             // ampersand (&) references the address of the number
  printf("4. number1: %d\n",number1);

  // we can use pointers to create structures - variables grouped together
  // that are of similar type

  struct UserType1 {int Part1; char* Part2;};

  struct UserType1 variable2;

  variable2.Part2 = "An example of a text";
  variable2.Part1 = number1;

  printf("5. Part1: %d\n6. Part2: %s\n", variable2.Part1, variable2.Part2);
  // we can use *variable2.part1 the same as variable2->part1
  return 0;
}

// boring function to demonstrate pointers
void somefunction(int *variable1)
{
  printf("3. input: %d\n", *variable1);  // recalls value stored at address
  *variable1 = *variable1 + 1;        // adjusts value stored at address
}
