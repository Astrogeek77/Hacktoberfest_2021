// Implemented HeapSort in C++
#include<iostream>
using namespace std;

// Applying heapify method on index i
void MaxHeapify(int arr[],int i,int size){
    int left =  2*i+1;
    int Right=  2*i+2;
    if(left<size && arr[left]>arr[i]){
        swap(arr[left],arr[i]);
        MaxHeapify(arr,left,size);
    }
    if(Right<size && arr[Right]>arr[i]){
        swap(arr[Right],arr[i]);
        MaxHeapify(arr,Right,size);
    }
    
}

void Display(int[], int);
// Buiding the Heap and sorting by Removing elements
void HeapSort(int arr[],int size){
    // buiding the Heap
    for(int i=size/2-1;i>=0; i--)
    {
        MaxHeapify(arr,i,size);
        
    }
    // Removing the elements
    for(int i=size-1; i>0; i--){
        swap(arr[0], arr[i]);
        MaxHeapify(arr,0,i);
    }
}

void Display(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return;
}

int main()
{
    const int size=10;
    int arr[]= {5,4,1,2,3, 5, 3, 2, 1,0};
    
    // Random Arr
    // ############################################
    
    cout<<"Unsorted Array :: ";
    Display(arr,size);
    HeapSort(arr, size);
    cout<<"Sorted   Array :: ";
    Display(arr,size);
    
    // Reversed Array
    
    // ############################################
    cout<<"________________________________________"<<endl;
    cout<<"########################################"<<endl;
    cout<<"________________________________________"<<endl;
    // ############################################
    int temp=9;
    for(int i=0; i<10; i++)
    {
      arr[i]=temp;
      temp--;
    }
    cout<<"Unsorted Array :: ";
    Display(arr,size);
    HeapSort(arr, size);
    cout<<"Sorted   Array :: ";
    Display(arr,size);
    
    // ############################################
    cout<<"________________________________________"<<endl;
    cout<<"########################################"<<endl;
    cout<<"________________________________________"<<endl;
    // ############################################
    // Sorted Arr
    cout<<"Already Sorted Array :: ";
    Display(arr,size);
    HeapSort(arr, size);
    cout<<"After Sorted   Array :: ";
    Display(arr,size);
    
    return 0;
}
