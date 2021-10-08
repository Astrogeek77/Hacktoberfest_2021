// Method 1 - (simple Solution)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    cout<<arr[k-1];
}

// Method 2 - (Min-Max Heap)
// Pending.......