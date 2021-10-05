"""
Bubble Sort Implementation in Python

"""
# Swap function 
def swap(arr,t):
    arr[t],arr[t+1]=arr[t+1],arr[t]

def BubbleSort(array):  
    for i in range(0,len(array)-1):  # This loop so that each element is traversed from index 0 to n-2
        for j in range(len(array)-1-i):  # Inner loop is from 0 to Unsorted part of array (Slightly Optimized)
            if(array[j]>array[j+1]):  
                swap(array,j) 
    return array

# Supportive Function to print array elements
def array_print(arr):
    for i in range(len(arr)):
        print(arr[i],end=" ")
    print()
    return

if __name__=="__main__":
    arr=[9,8,7,6,5,20,15] # Test array for Demo purpose
    print("Unsorted Array: ",end="")
    array_print(arr)
    array_sorted=BubbleSort(arr)
    print("Sorted Array : ",end=" ")
    array_print(array_sorted)
