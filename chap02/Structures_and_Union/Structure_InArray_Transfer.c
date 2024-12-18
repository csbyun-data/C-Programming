// C program to demonstrate passing an array
// by value using structures.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// A wrapper for array to make user that array is passed by value.
struct ArrayWrapper {
  int arr[SIZE];
};

// An array is passed by value wrapped in temp
void modify( struct ArrayWrapper temp) {
  int *ptr = temp.arr;
  int i;

  // Display array contents
  printf("In 'modify()', before modification\n"); 
  for( i=0; i<SIZE; ++i)
    printf("%d ", ptr[i]);

  printf("\n");

  // Modify the array 
  for (i = 0; i < SIZE; ++i) 
    ptr[i] = 100; // OR *(ptr + i) 
  
  printf("\nIn 'modify()', after modification\n"); 
  for (i = 0; i < SIZE; ++i) 
    printf("%d ", ptr[i]); // OR *(ptr + i)   

}

// Driver code
int main()
{
  int i;
  struct ArrayWrapper obj;
  for( i=0; i<SIZE; i++)
    obj.arr[i] = 10;

  modify(obj);

  // Display array contents
  printf("\n\nIn 'Main', after calling modify() \n"); 
    for (i = 0; i < SIZE; ++i) 
      printf("%d ", obj.arr[i]); // Not changed 
  
    printf("\n"); 
  
    return 0; 
} 

/*
In 'modify()', before modification
10 10 10 10 10

In 'modify()', after modification
100 100 100 100 100

In 'Main', after calling modify()
10 10 10 10 10 
*/
