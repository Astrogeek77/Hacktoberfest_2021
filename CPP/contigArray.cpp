#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int x = 0;
    int y = 0;
    for(int i=0;i<n;i++){
        y = y + arr[i];

        if(y > x){
            x = y;
        }
        else if(y < 0){
            y = 0;
        }
    }
    cout<<x<<" ";
}