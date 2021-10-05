#insertion sort implementation in python
def insertion_sort(arr):
           for i in range(1,len(arr)):
                      key=arr[i]
                      j=i-1
                      while(j>=0 and arr[j]>key):
                                 arr[j+1]=arr[j]
                                 j-=1
                      arr[j+1]=key

if __name__=="__main__":
    arr=[5,4,9,7,3,1]
    print("Unsorted Array : ",end="")
    print(arr)
    insertion_sort(arr)
    print("Sorted Array : ",end="")
    print(arr)
