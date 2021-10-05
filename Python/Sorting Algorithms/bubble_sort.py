#bubble sort implementation in python
def bubble_sort(arr):
           for i in range(len(arr)-1):
                      for j in range(len(arr)-i-1):
                                 if arr[j]>arr[j+1]:
                                            arr[j],arr[j+1]=arr[j+1],arr[j]

if __name__=="__main__":
    arr=[5,4,9,7,3,1]
    print("Unsorted Array : ",end="")
    print(arr)
    bubble_sort(arr)
    print("Sorted Array : ",end="")
    print(arr)
