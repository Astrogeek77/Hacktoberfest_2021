// Optimized implementation of Bubble sort
#include <stdio.h>
  
void swaping(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// An optimized version of Bubble Sort
void bubbleSortalgo(int arr[], int n)
{
   int x, y;
   bool swapped;
   for (x = 0; x < n-1; x++)
   {
     swapped = false;
     for (y= 0; y < n-x-1; y++)
     {
        if (arr[y] > arr[y+1])
        {
           swaping(&arr[y], &arr[y+1]);
           swapped = true;
        }
     }
  
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
  
/* Function to print an array */
void printArray(int arr[], int Arrsize)
{
    int i;
    for (i=0; i < Arrsize; i++)
        printf("%d ", arr[i]);
    printf("n");
}
  
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSortalgo(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}