// C++ program to implement recursive Order-Agnostic Binary Search
#include<bits/stdc++.h>
using namespace std;
// A iterative binary search function. 
int binarySearch(int nums[],int start,int end, int x) {
    bool isAsc=nums[start]<nums[end];   //checking the sorted order of the given array
    while (start <= end)
    {
        int middle = start+(end-start)/2;
        // Check if x is present at mid
        if (nums[middle] == x)
            return middle;

        if(isAsc==true){            //ascending order 
                              
            if (nums[middle] < x) // If x greater, ignore left half
                start = middle + 1;
            
            else
                end = middle - 1; // If x smaller, ignore right half

        }else{                      //descending order

            if (nums[middle] >x)       // If x smaller, ignore left half
                start = middle + 1;
            
            else                    //If x greater, ignore right half
                end = middle - 1;
        }
    }
    // if we reach here, then element was
    // not present
    return -1;
}

int main(){
   int arr[] = { 40,10,5,2,1};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}