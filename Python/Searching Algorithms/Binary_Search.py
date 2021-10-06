"""

Binary Search Implementation Using Python

"""

# Supportive Function to print array elements
def array_print(arr):
    for i in range(len(arr)):
        print(arr[i],end=" ")
    print()
    return

# Post Result Analusis depends on the content of flag bit
def result_analysis(result):
    print("Key (Search Element ) : ",result[2])
    if result[0]==0:
        print("Key = "+str(result[2])+" is Not present in Given Array")
    else:
        print("Key = "+str(result[2])+" is present in Given Array at position "+str(result[1]+1))
    return

# Binary Search Iterative Algorithm
def Binary_Search(array,key,start,end):
    flag=0
    mid=-1
    if end >= start:
 
        mid = (end + start) // 2
 
        # If element is present at the middle itself
        if array[mid] == key:
            flag=1
            return (flag,mid,key)
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif array[mid] > key:
            return Binary_Search(array, key, start, mid - 1)
 
        # Else the element can only be present in right subarray
        else:
            return Binary_Search(array, key, mid + 1, end)
 
    else:
        # Element is not present in the array
        return (flag,mid,key)
    

if __name__=="__main__":
    arr=[9,8,7,6,5,20,15] # Test array for Demo purpose
    key_1=6
    key_2=25
    print("Given Array : ",end="")
    array_print(arr)
    result_1=Binary_Search(arr,key_1,0,len(arr)-1)
    result_2=Binary_Search(arr,key_2,0,len(arr)-1)
    result_analysis(result_1)
    result_analysis(result_2)
    
