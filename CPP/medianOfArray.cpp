#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        sort(a,a+n);
        if(n%2!=0){
            int k=floor(n/2);
            cout<<a[k];
        }
        else{
            int y = n/2;
            int z = (n/2)-1;
            cout<<floor((a[y]+a[z])/2);
        }
    }
}