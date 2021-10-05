"""

Linear Search Implementation Using Python

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

# Linear Search Iterative Algorithm
def Linear_Search(array,k):
    flag=0
    for i in range(len(array)):
        if k==array[i]:
            flag=1      # If element present in the given array, flag set to 1 else remains 0.
            break
    return (flag,i,k)

if __name__=="__main__":
    arr=[9,8,7,6,5,20,15] # Test array for Demo purpose
    key_1=6
    key_2=25
    print("Given Array : ",end="")
    array_print(arr)
    result_1=Linear_Search(arr,key_1)
    result_2=Linear_Search(arr,key_2)
    result_analysis(result_1)
    result_analysis(result_2)
    
