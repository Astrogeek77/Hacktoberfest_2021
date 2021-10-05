"""

Heap Sort Implementation in Python Language

"""

import heapq

def print_array(arr):
    for i in range(len(arr)):
        print(arr[i],end=" ")
    print()
    return

def heap_sort(arr):
    b=[];c=[]
    b=arr.copy()
    heapq.heapify(b)
    while b!=[]:
        c.append(heapq.heappop(b))
        heapq.heapify(b)
    return c

if __name__=="__main__":
    arr=[5,4,9,7,3,1]
    print("Unsorted Array: ",end="")
    print_array(arr)
    Sorted_arr=heap_sort(arr)
    print("Sorted Array : ",end=" ")
    print_array(Sorted_arr)
