// heap sort in c++
#include<bits/stdc++.h>
using namespace std;

// to heapify a subtree rooted with node i which is an index in arr[]
// n is size of heap 
void heapify(int arr[], int n,int i){
    int largest=i; // largest is root
    int l=2*i+1;  // left subtree
    int r= 2*i+2; //right sibtree

    // if left child is larger than root
    if(l<n && arr[l]>arr[largest]){
        largest =l;
    }  
    // if right child is larger than root
    if(r<n && arr[r]>arr[largest]){
        largest =r;
    }  
    // root is not largest
    if(largest!=i){
        swap(arr[i],arr[largest]);

        // recursive call 
        heapify(arr,n,largest);
    }

}

void heapsort(int arr[],int n){
    // create the heap by rearranging elements
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    // extracting element one by one from heap
    for(int i=n-1;i>=0;i--){
        // move current root to end
        swap(arr[0],arr[i]);

        // calling max heapify on the reduced heap
        heapify(arr,i,0);
    }
}
int main(){
    int n;
    cout<<"Size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array: "<<endl;
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    heapsort(arr,n);
    cout<<endl<<"Sorted Array: "<<endl;
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";


}

