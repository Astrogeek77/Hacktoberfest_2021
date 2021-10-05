#selection sort implementation in python
def selection_sort(arr):
           for i in range(len(arr)-1):
                      min_ind=i
                      for j in range(i+1,len(arr)):
                                 if arr[min_ind]>arr[j]:
                                            min_ind=j
                      arr[i],arr[min_ind]=arr[min_ind],arr[i]

if __name__=="__main__":
    arr=[5,4,9,7,3,1]
    print("Unsorted Array : ",end="")
    print(arr)
    selection_sort(arr)
    print("Sorted Array : ",end="")
    print(arr)
